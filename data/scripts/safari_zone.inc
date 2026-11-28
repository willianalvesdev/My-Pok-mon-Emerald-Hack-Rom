SafariZone_EventScript_OutOfBallsMidBattle::
#if IS_FRLG
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 3
#else
	setvar VAR_SAFARI_ZONE_STATE, 1
#endif
	special ExitSafariMode
#if IS_FRLG
	setwarp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 4, 1
#else
	setwarp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
#endif
	end

SafariZone_EventScript_Exit::
#if IS_FRLG
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 1
#else
	setvar VAR_SAFARI_ZONE_STATE, 1
#endif
	special ExitSafariMode
#if IS_FRLG
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 4, 1
#else
	warp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
#endif
	waitstate
	end

SafariZone_EventScript_RetirePrompt::
	lockall
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_Retire
	releaseall
	end

SafariZone_EventScript_Retire::
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_TimesUp
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_OutOfBalls::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_OutOfBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

EventScript_PokeBlockFeeder::
	lockall
	special GetPokeblockFeederInFront
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPlaced
#ifdef BUGFIX
	releaseall  @ Only gets called from EventScript_PokeBlockFeeder which uses lockall.
#endif
	end

SafariZone_EventScript_PokeblockPlaced::
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent::
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_WouldYouLikeToExit:
	.string "Quer sair da Safari Zone agora?$"

SafariZone_Text_TimesUp:
	.string "Dim-dom! O tempo acabou! Seu\n"
	.string "passeio no safári terminou.$"

SafariZone_Text_OutOfBalls:
	.string "Suas Safari Balls acabaram. Seu\n"
	.string "passeio no safári terminou.$"

SafariZone_Text_PlacePokeblockOnFeeder:
	.string "Colocar um {POKEBLOCK} no comedouro\n"
	.string "de {POKEBLOCK}?$"

SafariZone_Text_PokeblockStillHere:
	.string "O {STR_VAR_1} que você deixou\n"
	.string "ainda está aqui.$"

SafariZone_Text_PokeblockWasPlaced:
	.string "{STR_VAR_1} foi colocado no\n"
	.string "comedouro de {POKEBLOCK}.$"

Route121_SafariZoneEntrance_Text_WelcomeToSafariZone:
	.string "Bem-vindo à Safari Zone!\p"
	.string "Aqui você encontra vários Pokémon\n"
	.string "raros em Hoenn, vivendo soltos na\l"
	.string "natureza.\p"
	.string "Abrimos as portas pros treinadores\n"
	.string "e você pode capturar eles pra\l"
	.string "levar!\p"
	.string "Entre e aproveite!$"

Route121_SafariZoneEntrance_Text_WelcomeFirstTime:
	.string "Bem-vindo à Safari Zone! É sua\n"
	.string "primeira vez aqui?$"

Route121_SafariZoneEntrance_Text_ComeInAndEnjoy:
	.string "Entre e aproveite a Safari Zone!$"

Route121_SafariZoneEntrance_Text_FirstTimeInfo:
	.string "Você começa com 30 Safari Balls\n"
	.string "pra capturar Pokémon.\p"
	.string "O passeio acaba quando elas\n"
	.string "terminam ou depois de 500 passos.\p"
	.string "Entre e aproveite a Safari Zone!$"

Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay:
	.string "Bem-vindo à Safari Zone!\p"
	.string "Capture oque conseguir por só\n"
	.string "¥500! Quer participar?$"

Route121_SafariZoneEntrance_Text_PlayAnotherTime:
	.string "Certo. Volte pra participar outra\n"
	.string "hora!$"

Route121_SafariZoneEntrance_Text_NotEnoughMoney:
	.string "Desculpa, você nao tem dinheiro\n"
	.string "suficiente.$"

Route121_SafariZoneEntrance_Text_ThatWillBe500Please:
	.string "Sao ¥500, por favor.$"

Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls:
	.string "Aqui estao suas Safari Balls.$"

Route121_SafariZoneEntrance_Text_Received30SafariBalls:
	.string "{PLAYER} recebeu 30 Safari Balls.$"

Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself:
	.string "Vamos avisar quando o passeio\n"
	.string "acabar.\p"
	.string "Até lá, aproveite sua aventura na\n"
	.string "natureza!$"

Route121_SafariZoneEntrance_Text_PCIsFull:
	.string "Com licença! Sua Box do PC está\n"
	.string "cheia.$"

Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase:
	.string "Com licença! Você nao tem uma\n"
	.string "caixa de {POKEBLOCK}.\p"
	.string "Seu passeio rende mais usando\n"
	.string "{POKEBLOCK}S.\p"
	.string "Volte com uma caixa de {POKEBLOCK}.\n"
	.string "Você consegue uma caixa de\l"
	.string "{POKEBLOCK} no salao de concursos\l"
	.string "de Lilycove.$"

SafariZone_South_Text_StillHaveTimeExit:
	.string "Você ainda tem tempo. Quer sair da\n"
	.string "Safari Zone agora?$"

SafariZone_South_Text_EnjoyTheRestOfYourAdventure:
	.string "Aproveite o resto da sua aventura!$"

SafariZone_South_Text_ExitEarlyThankYouForPlaying:
	.string "Certo. Vou recolher as Safari Balls\n"
	.string "que sobraram.\p"
	.string "Obrigado por participar. Esperamos\n"
	.string "você de novo.$"

SafariZone_South_Text_GoodLuck:
	.string "Boa sorte!\p"
	.string "Se precisar de alguma coisa, é só\n"
	.string "falar!$"

SafariZone_South_Text_Boy:
	.string "Sabia que, se colocar um {POKEBLOCK}\n"
	.string "naquela caixa quadrada, os Pokémon\l"
	.string "se reúnem em volta?$"

SafariZone_South_Text_Man:
	.string "Quero explorar mais, mas esqueci\n"
	.string "de trazer bicicleta.\p"
	.string "Tenho a impressao de que os\n"
	.string "Pokémon raros vivem nos cantos\l"
	.string "mais afastados.$"

SafariZone_Southwest_Text_Woman:
	.string "Às vezes jogo um {POKEBLOCK} e o\n"
	.string "Pokémon ignora.\p"
	.string "Será que eles têm suas comidas\n"
	.string "favoritas?$"

SafariZone_Northwest_Text_Man:
	.string "Ufa... Ufa... Cheguei até aqui,\n"
	.string "mas...\p"
	.string "Tô exausto. Nem tenho energia pra\n"
	.string "capturar Pokémon...$"

SafariZone_North_Text_Fisherman:
	.string "Quero encontrar Pokémon Water que\n"
	.string "nao aparecem em Hoenn.\p"
	.string "Sabe onde fica o lago?$"

SafariZone_North_Text_Man:
	.string "Vou capturar vários Pokémon raros\n"
	.string "e trocar com meus amigos!$"

SafariZone_South_Text_Youngster:
	.string "Coloquei um {POKEBLOCK} no comedouro\n"
	.string "de {POKEBLOCK}, mas ele sumiu.\p"
	.string "Acho que algum Pokémon comeu sem\n"
	.string "eu perceber.$"

Route121_SafariZoneEntrance_Text_TrainerTip:
	.string "DICA DA SAFARI ZONE!\p"
	.string "Jogue {POKEBLOCK}S pros Pokémon\n"
	.string "selvagens pra eles fugirem menos.$"

SafariZone_Southwest_Text_RestHouseSign:
	.string "“Descanse os pés cansados.”\p"
	.string "Casa de descanso$"

SafariZone_RestHouse_Text_Youngster:
	.string "Nao tenho {POKEBLOCK}S, mas capturei\n"
	.string "vários Pokémon.\p"
	.string "Você aumenta suas chances\n"
	.string "chegando mais perto antes de jogar\l"
	.string "uma Safari Ball.$"

SafariZone_RestHouse_Text_PsychicM:
	.string "Com {POKEBLOCK}S, os Pokémon\n"
	.string "selvagens demoram mais pra fugir.\p"
	.string "Nao adianta muito dar {POKEBLOCK}S\n"
	.string "pros que já nao fogem fácil.$"

SafariZone_RestHouse_Text_FatMan:
	.string "Se colocar um {POKEBLOCK} no\n"
	.string "comedouro, os Pokémon vao até ele.\p"
	.string "Acho que cada {POKEBLOCK} atrai\n"
	.string "Pokémon de certas naturezas.$"

SafariZone_South_Text_AreaOffLimits1:
	.string "Esta área ainda ta em construçao.\n"
	.string "Nao pode entrar, desculpa!$"

SafariZone_Southeast_Text_ExpansionIsFinished:
	.string "A ampliaçao da Safari Zone\n"
	.string "terminou.\p"
	.string "Esperamos que aproveite a área\n"
	.string "nova.$"

SafariZone_South_Text_AreaOffLimits2:
	.string "Esta área ainda ta em construçao.\n"
	.string "Nao pode entrar, desculpa!$"

SafariZone_Southeast_Text_LittleGirl:
	.string "Nossa! Nunca vi nenhum desses\n"
	.string "Pokémon antes!$"

SafariZone_Southeast_Text_FatMan:
	.string "Nao conheço os Pokémon desta\n"
	.string "área.\p"
	.string "E ainda posso capturar eles! Bom\n"
	.string "demais!$"

SafariZone_Southeast_Text_RichBoy:
	.string "Os Pokémon daqui parecem vir de\n"
	.string "outras regioes.$"

SafariZone_Northeast_Text_Boy:
	.string "Só tenho algumas Safari Balls.\p"
	.string "Ta difícil decidir oque capturar.$"

SafariZone_Northeast_Text_Woman:
	.string "Ouvi dizer que tem Pikachu aqui.\n"
	.string "Onde será?$"

SafariZone_Northeast_Text_Girl:
	.string "Ah, nao consigo capturar nada!\p"
	.string "Se continuar assim, vou desperdiçar\n"
	.string "o dinheiro da entrada!$"
