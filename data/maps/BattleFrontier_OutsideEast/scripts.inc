BattleFrontier_OutsideEast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
	.byte 0

BattleFrontier_OutsideEast_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_FRONTIER_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign:
	.string "Esta é a BATTLE TOWER! Continue\n"
	.string "vencendo e prove que é o treinador\l"
	.string "mais forte!$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign:
	.string "Este é o BATTLE PALACE! Acompanhe\n"
	.string "de perto as batalhas Pokémon!$"

BattleFrontier_OutsideEast_Text_BattleArenaSign:
	.string "Esta é a BATTLE ARENA! Que venham\n"
	.string "as equipes mais fortes!$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign:
	.string "Esta é a BATTLE PYRAMID! Avance\n"
	.string "pela Jornada de Batalha!$"

BattleFrontier_OutsideEast_Text_RankingHallSign:
	.string "BATTLE FRONTIER RANKING HALL: mire\n"
	.string "em novos recordes!$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign:
	.string "BATTLE POINT EXCHANGE SERVICE\n"
	.string "CORNER: troque seus Pontos de\l"
	.string "Batalha!$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial:
	.string "Uau! É enorme!\p"
	.string "A BATTLE TOWER parece especial. É\n"
	.string "diferente das outras.$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier:
	.string "Meu grande sonho é conquistar a\n"
	.string "BATTLE FRONTIER e a POKéMON\l"
	.string "LEAGUE.\p"
	.string "E, se eu conseguir...\p"
	.string "Eu... Vou perguntar à MIMI, minha\n"
	.string "vizinha, se ela quer ser minha\l"
	.string "amiga!$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh:
	.string "A BATTLE PYRAMID é difícil demais!\n"
	.string "Nao consigo chegar ao topo!\p"
	.string "Já que nao tem outro jeito, talvez\n"
	.string "eu possa subir pelo lado de\l"
	.string "fora...$"

BattleFrontier_OutsideEast_Text_ThriveInDarkness:
	.string "Eu me sinto bem na escuridao...\n"
	.string "Sim... Qual lugar combina comigo? A\l"
	.string "BATTLE PYRAMID, claro...\p"
	.string "Que tal vagar no escuro, sem\n"
	.string "nenhuma esperança?$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam:
	.string "Fiquei uma semana sem dormir, mas\n"
	.string "montei a equipe perfeita!\p"
	.string "Nao consigo imaginar a gente\n"
	.string "perdendo, sério. Vamos arrasar na\l"
	.string "BATTLE ARENA!$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere:
	.string "SCOTT trouxe você também? Qual é\n"
	.string "a desse cara?\p"
	.string "Parece que ele sabe reconhecer\n"
	.string "treinadores talentosos, mas...\p"
	.string "Nunca vi ele batalhar.$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy:
	.string "ZIGG! Eu acredito em você,\n"
	.string "amiguinho!\p"
	.string "Se ganhar, faço todas as suas\n"
	.string "comidas favoritas!$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant:
	.string "ZIGZAGOON está olhando para o\n"
	.string "nada...$"

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody:
	.string "Dizem que eu me meto em tudo, mas\n"
	.string "nao consigo evitar.\p"
	.string "Seu boné está torto! Olha, lixo no\n"
	.string "chao! Nossa, já está quase na\l"
	.string "hora de jantar!\p"
	.string "Nao sei se aguento ficar só\n"
	.string "olhando no BATTLE PALACE...$"

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader:
	.string "Hoje posso nao parecer grande\n"
	.string "coisa, mas já venci um líder de\l"
	.string "ginásio.\p"
	.string "Quem sabe eu nao tente brilhar de\n"
	.string "novo?$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles:
	.string "Sou rápido na bicicleta e também\n"
	.string "nas batalhas.\p"
	.string "Venço num piscar de olhos!$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon:
	.string "Sou melhor com Pokémon do que meu\n"
	.string "pai.$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy:
	.string "Vai, meu amorzinho! Vai conseguir\n"
	.string "umas vitórias para o papai!\p"
	.string "Você puxou sua mae, entao vai\n"
	.string "arrasar!$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena:
	.string "Nao foi fácil chegar aqui, mas ouvi\n"
	.string "falar de uma garota linda na\l"
	.string "BATTLE ARENA.\p"
	.string "E sabe o que encontrei no lugar\n"
	.string "dela?\p"
	.string "Um monte de lutadores suados,\n"
	.string "fedidos e brutos!$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere:
	.string "Às vezes vejo um senhor com jeito\n"
	.string "importante entrando ali.\p"
	.string "Ele tem uns Pokémon incríveis.\n"
	.string "Parece bem simpático.$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid:
	.string "Conhece a lenda da BATTLE\n"
	.string "PYRAMID?\p"
	.string "Quando um treinador cheio de\n"
	.string "confiança busca o topo dourado,\l"
	.string "surge um homem sem igual.\p"
	.string "Nao conhece? Claro que nao! Acabei\n"
	.string "de inventar!\p"
	.string "O que significa? Isso, meu amigo,\n"
	.string "eu nao sei dizer!$"

BattleFrontier_OutsideEast_Text_GotWipedOut:
	.string "Cara! Eu nunca tinha perdido!\p"
	.string "Mas acabaram comigo sem me dar a\n"
	.string "menor chance!\p"
	.string "E ainda disseram que eu nao tenho\n"
	.string "talento?! Poxa!$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower:
	.string "Esse cara encontrou um treinador\n"
	.string "forte demais no desafio da BATTLE\l"
	.string "TOWER.\p"
	.string "Agora olha o estado dele...\p"
	.string "É bom tomar cuidado se for tentar\n"
	.string "a BATTLE TOWER.$"

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll:
	.string "Isso! Finalmente tenho Pontos de\n"
	.string "Batalha suficientes!\p"
	.string "Acho que vou pegar outra pelúcia\n"
	.string "gigante!$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere:
	.string "Ah, entendi! Este é o RANKING\n"
	.string "HALL!\p"
	.string "Quero entrar para a história como\n"
	.string "um grande campeao e deixar meu\l"
	.string "nome registrado aqui.$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou:
	.string "Com você ao meu lado, eu consigo\n"
	.string "tudo.$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome:
	.string "Ah, querido, você é maravilhoso!\p"
	.string "Nao aguento mais esperar!\p"
	.string "Vamos agora para uma Sala de\n"
	.string "Batalhas em Parceria!\p"
	.string "Se nos juntarmos no Salao de\n"
	.string "Batalha, o poder do nosso amor vai\l"
	.string "vencer qualquer um.\p"
	.string "Na nossa frente, querido, todos\n"
	.string "vao cair como peças de dominó!$"

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers:
	.string "A BATTLE FRONTIER recebe mais\n"
	.string "gente além de treinadores fortes.\p"
	.string "Parece que convidaram várias\n"
	.string "pessoas com talentos especiais.\p"
	.string "Esse SCOTT...\p"
	.string "Talvez tenha criado este lugar\n"
	.string "pensando em algo maior...$"

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle:
	.string "Com licença, jovem. Você enxerga\n"
	.string "bem?\p"
	.string "Tem uma árvore estranha mais à\n"
	.string "frente. Com esses meus olhos\l"
	.string "cansados, parece que ela se mexe.$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere:
	.string "Com licença, jovem. Você tem boa\n"
	.string "memória?\p"
	.string "Tenho a impressao de que havia uma\n"
	.string "árvore estranha mais à frente.$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail:
	.string "Eu... Eu vi!\p"
	.string "Tinha um Pokémon meio grudento,\n"
	.string "com uma cauda comprida, ali na\l"
	.string "frente!\p"
	.string "Estava escondido debaixo de uma\n"
	.string "pedra e ficou me encarando!$"
