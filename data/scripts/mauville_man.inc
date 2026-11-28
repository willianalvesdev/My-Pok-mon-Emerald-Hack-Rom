MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan::
	special Script_GetCurrentMauvilleMan
	switch VAR_RESULT
	case MAUVILLE_MAN_BARD, MauvilleCity_PokemonCenter_1F_EventScript_Bard
	case MAUVILLE_MAN_HIPSTER, MauvilleCity_PokemonCenter_1F_EventScript_Hipster
	case MAUVILLE_MAN_TRADER, MauvilleCity_PokemonCenter_1F_EventScript_Trader
	case MAUVILLE_MAN_STORYTELLER, MauvilleCity_PokemonCenter_1F_EventScript_Storyteller
	case MAUVILLE_MAN_GIDDY, MauvilleCity_PokemonCenter_1F_EventScript_Giddy
	end

@ Bard
MauvilleCity_PokemonCenter_1F_EventScript_Bard::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_PlaySong
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong
	end

MauvilleCity_PokemonCenter_1F_EventScript_PlaySong::
	setvar VAR_0x8004, FALSE  @ Play his current song
	special PlayBardSong
	delay 60
	special HasBardSongBeenChanged
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	end

MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics::
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, TRUE  @ Play the new song
	special PlayBardSong
	delay 60
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	special SaveBardSongLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2, MSGBOX_DEFAULT
	release
	end

@ Hipster
MauvilleCity_PokemonCenter_1F_EventScript_Hipster::
	lock
	faceplayer
	setflag FLAG_UNLOCKED_TRENDY_SAYINGS
	msgbox MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening, MSGBOX_DEFAULT
	special HasHipsterTaughtWord
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord::
	special HipsterTryTeachWord
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_TeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TeachWord::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord, MSGBOX_DEFAULT
	special SetHipsterTaughtWord
	release
	end

@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor:
	.string "Oi, sou o Trader. Quer trocar\n"
	.string "enfeites comigo?$"

MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues:
	.string "Ah... Você me deixou triste...$"

MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded:
	.string "Mas a gente já trocou enfeites.$"

MauvilleCity_PokemonCenter_1F_Text_PickADecorItem:
	.string "Se quiser algum dos meus enfeites,\n"
	.string "é só falar.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything:
	.string "Nao quer nada? Me sinto deixado de\n"
	.string "lado...$"

MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt:
	.string "Esse enfeite já foi de\n"
	.string "{STR_VAR_1}.\p"
	.string "Você quer?$"

MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor:
	.string "Espera um pouco. Você nao tem\n"
	.string "nenhum enfeite!$"

MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade:
	.string "Certo, escolha o enfeite que vai\n"
	.string "dar em troca.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade:
	.string "Nao quer trocar comigo? Me sinto\n"
	.string "deixado de lado...$"

MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis:
	.string "Você já tem o máximo de\n"
	.string "{STR_VAR_2}S que pode guardar.\l"
	.string "Nao tem espaço pra mais.$"

MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor:
	.string "Entao vamos trocar meu\n"
	.string "{STR_VAR_3} pelo seu\l"
	.string "{STR_VAR_2}?$"

MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse:
	.string "Esse enfeite está em uso. Nao dá\n"
	.string "pra trocar.$"

MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC:
	.string "Entao vamos trocar! Vou mandar\n"
	.string "meu enfeite pro seu PC.$"

MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne:
	.string "Opa, desculpa! Esse enfeite é\n"
	.string "muito raro. Nao posso trocar ele!\p"
	.string "Quer alguma outra coisa?$"

MauvilleCity_PokemonCenter_1F_EventScript_Trader::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade
	special GetTraderTradedFlag
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive::
	special TraderMenuGetDecoration
	goto_if_eq VAR_0x8004, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor
	goto_if_eq VAR_0x8004, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor
	special DoesPlayerHaveNoDecorations
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor::
	message MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor::
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive::
	msgbox MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade, MSGBOX_DEFAULT
	special TraderShowDecorationMenu
	goto_if_eq VAR_0x8006, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor
	goto_if_eq VAR_0x8006, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse
	special IsDecorationCategoryFull
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	special TraderDoDecorationTrade
	msgbox MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis, MSGBOX_DEFAULT
	release
	end

@ Storyteller
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale:
	.string "Sou o Storyteller. Conto histórias\n"
	.string "de treinadores lendários.\p"
	.string "Quer ouvir uma?$"

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
	.string "Ah... Você me deixou triste...$"

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell:
	.string "Conheço estas lendas. Qual quer\n"
	.string "ouvir?$"

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales:
	.string "Mas nao conheço nenhum treinador\n"
	.string "lendário. Entao nao tenho\l"
	.string "histórias.\p"
	.string "Onde vou encontrar alguém que\n"
	.string "mereça uma lenda?$"

MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes:
	.string "Oque?! Você... Você...\p"
	.string "{STR_VAR_2} {STR_VAR_1}\n"
	.string "vezes?!\p"
	.string "Isso é incrível! Nasceu uma nova\n"
	.string "lenda!$"

MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends:
	.string "Fico pensando... Será que existem\n"
	.string "treinadores com histórias ainda\l"
	.string "mais incríveis esperando pra serem\l"
	.string "descobertos?$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
	.string "Você é um treinador?\p"
	.string "Tem alguma história sua que chegue\n"
	.string "perto de ser uma lenda?$"

@ Unused
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale:
	.string "Aliás... Quer ouvir outra história\n"
	.string "lendária?$"

MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend:
	.string "Hum... Ainda nao me convenceu...\p"
	.string "Quero notícias que mereçam ser\n"
	.string "chamadas de lenda.$"

MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested:
	.string "Queria que mais gente se\n"
	.string "interessasse pelas minhas histórias\l"
	.string "de treinadores lendários.$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle::
	.string "O treinador que adora salvar$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction::
	.string "Salvou o jogo$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador salvou o jogo\n"
	.string "{STR_VAR_1} vezes!\p"
	.string "Nunca vai existir alguém mais\n"
	.string "prevenido que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle::
	.string "O treinador que lança moda$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction::
	.string "Criou novas modas$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador criou novas modas\n"
	.string "{STR_VAR_1} vezes!\p"
	.string "{STR_VAR_3} ta ditando a moda\n"
	.string "de Hoenn inteira!$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle::
	.string "O treinador que planta Berries$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction::
	.string "Plantou Berries$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador plantou Berries\n"
	.string "{STR_VAR_1} vezes!\p"
	.string "{STR_VAR_3} é uma lenda no\n"
	.string "cultivo de Berries!$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle::
	.string "O treinador que adora bicicletas$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction::
	.string "Trocou de bicicleta$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador trocou de bicicleta\n"
	.string "{STR_VAR_1} vezes!\p"
	.string "{STR_VAR_3} deve gostar muito\n"
	.string "de pedalar!$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle::
	.string "O treinador das entrevistas$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction::
	.string "Deu entrevistas$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador deu entrevistas\n"
	.string "{STR_VAR_1} vezes!\p"
	.string "{STR_VAR_3} chama muita\n"
	.string "atençao!$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle::
	.string "O treinador que adora batalhar$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction::
	.string "Batalhou$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador batalhou\n"
	.string "{STR_VAR_1} vezes!\p"
	.string "{STR_VAR_3} deve adorar\n"
	.string "enfrentar desafios!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle::
	.string "O treinador que captura Pokémon$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction::
	.string "Capturou Pokémon$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador capturou\n"
	.string "{STR_VAR_1} Pokémon!\p"
	.string "{STR_VAR_3} é uma lenda nas\n"
	.string "capturas!$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
	.string "O treinador pescador$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
	.string "Pescou Pokémon$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador pescou\n"
	.string "{STR_VAR_1} Pokémon!\p"
	.string "{STR_VAR_3} é um grande\n"
	.string "especialista em pesca!$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle::
	.string "O treinador que choca ovos$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction::
	.string "Chocou ovos$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador chocou\n"
	.string "{STR_VAR_1} ovos de Pokémon!\p"
	.string "{STR_VAR_3} é uma lenda em\n"
	.string "manter os ovos quentinhos!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle::
	.string "O treinador das evoluçoes$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction::
	.string "Evoluiu Pokémon$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador evoluiu\n"
	.string "{STR_VAR_1} Pokémon!\p"
	.string "{STR_VAR_3} é um grande mestre\n"
	.string "das evoluçoes!$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
	.string "O fa dos Centros Pokémon$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction::
	.string "Usou Centros Pokémon$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador curou seus Pokémon\n"
	.string "{STR_VAR_1} vezes nos Centros\l"
	.string "Pokémon!\p"
	.string "{STR_VAR_3} já deve ser da\n"
	.string "família por lá!$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle::
	.string "O treinador caseiro$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction::
	.string "Descansou os Pokémon em casa$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador recuperou seus\n"
	.string "Pokémon em casa {STR_VAR_1}\l"
	.string "vezes!\p"
	.string "Ninguém gosta tanto de ficar em\n"
	.string "casa quanto {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle::
	.string "O treinador que adora o safári$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction::
	.string "Entrou na Safari Zone$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador entrou na Safari\n"
	.string "Zone {STR_VAR_1} vezes!\p"
	.string "É lá que {STR_VAR_3} solta seu\n"
	.string "lado selvagem!$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle::
	.string "O treinador que adora Cut$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction::
	.string "Usou Cut$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador usou Cut\n"
	.string "{STR_VAR_1} vezes!\p"
	.string "{STR_VAR_3} deve gostar muito\n"
	.string "de cortar árvores!$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle::
	.string "O treinador que quebra pedras$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction::
	.string "Quebrou pedras$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador usou Rock Smash\n"
	.string "{STR_VAR_1} vezes!\p"
	.string "{STR_VAR_3} nao consegue\n"
	.string "deixar uma pedra inteira!$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle::
	.string "O treinador das mudanças$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction::
	.string "Mudou de base secreta$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador mudou de base\n"
	.string "secreta {STR_VAR_1} vezes!\p"
	.string "{STR_VAR_3} deve estar fugindo\n"
	.string "do aluguel!$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle::
	.string "O treinador que adora Splash$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction::
	.string "Usou Splash$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador usou Splash\n"
	.string "{STR_VAR_1} vezes!\p"
	.string "{STR_VAR_3} se esforçou muito\n"
	.string "pra nao fazer nada!$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle::
	.string "O treinador que nao desiste$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction::
	.string "Precisou usar Struggle$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador precisou usar\n"
	.string "Struggle {STR_VAR_1} vezes!\p"
	.string "{STR_VAR_3} nao desiste nem\n"
	.string "quando tudo dá errado!$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle::
	.string "O campeao das máquinas$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction::
	.string "Ganhou a bolada nas máquinas$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador ganhou a bolada nas\n"
	.string "máquinas {STR_VAR_1} vezes!\p"
	.string "{STR_VAR_3} teve muita sorte\n"
	.string "no cassino!$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle::
	.string "O campeao da roleta$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction::
	.string "Teve vitórias seguidas na roleta$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador ganhou na roleta\n"
	.string "{STR_VAR_1} vezes seguidas!\p"
	.string "A bolinha da sorte tava do lado de\n"
	.string "{STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
	.string "O desafiante da Battle Tower$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction::
	.string "Desafiou a Battle Tower$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador desafiou a Battle\n"
	.string "Tower {STR_VAR_1} vezes!\p"
	.string "{STR_VAR_3} quer chegar ao\n"
	.string "topo desse desafio!$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle::
	.string "O treinador das misturas$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction::
	.string "Fez {POKEBLOCK}S$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador fez {POKEBLOCK}S\n"
	.string "{STR_VAR_1} vezes!\p"
	.string "Ninguém usa um Berry Blender\n"
	.string "melhor que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle::
	.string "O treinador dos concursos$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction::
	.string "Participou de concursos$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador participou de\n"
	.string "concursos {STR_VAR_1} vezes!\p"
	.string "{STR_VAR_3} adora mostrar seus\n"
	.string "Pokémon!$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle::
	.string "O mestre dos concursos$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction::
	.string "Venceu concursos$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador venceu concursos\n"
	.string "{STR_VAR_1} vezes!\p"
	.string "{STR_VAR_3} é um grande mestre\n"
	.string "dos concursos!$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle::
	.string "O comprador feliz$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction::
	.string "Fez compras$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador fez compras\n"
	.string "{STR_VAR_1} vezes!\p"
	.string "{STR_VAR_3} nasceu pra comprar.\n"
	.string "Só falta combinar com a carteira!$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle::
	.string "O treinador que encontra itens$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction::
	.string "Usou Itemfinder$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador usou Itemfinder\n"
	.string "{STR_VAR_1} vezes!\p"
	.string "{STR_VAR_3} adora procurar\n"
	.string "itens escondidos pelo chao!$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle::
	.string "O treinador encharcado$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction::
	.string "Tomou chuva$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador tomou chuva\n"
	.string "{STR_VAR_1} vezes!\p"
	.string "Até a chuva quer um encontro com\n"
	.string "{STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle::
	.string "O leitor da Pokédex$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction::
	.string "Consultou a Pokédex$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador consultou a Pokédex\n"
	.string "{STR_VAR_1} vezes!\p"
	.string "{STR_VAR_3} adora pesquisar\n"
	.string "Pokémon!$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
	.string "O colecionador de fitas$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction::
	.string "Ganhou fitas$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador ganhou fitas\n"
	.string "{STR_VAR_1} vezes!\p"
	.string "{STR_VAR_3} adora colecionar\n"
	.string "elas!$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle::
	.string "O treinador que pula barrancos$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction::
	.string "Pulou barrancos$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador pulou barrancos\n"
	.string "{STR_VAR_1} vezes!\p"
	.string "Se aparece um barranco,\n"
	.string "{STR_VAR_3} nao consegue\l"
	.string "resistir!$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle::
	.string "A lenda da televisao$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction::
	.string "Assistiu televisao$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador assistiu televisao\n"
	.string "{STR_VAR_1} vezes!\p"
	.string "{STR_VAR_3} ta quase ganhando\n"
	.string "uma insígnia do sofá!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle::
	.string "O treinador pontual$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction::
	.string "Olhou as horas$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador olhou as horas\n"
	.string "{STR_VAR_1} vezes!\p"
	.string "{STR_VAR_3} deve gostar de\n"
	.string "chegar no horário!$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle::
	.string "O mestre da loteria Pokémon$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction::
	.string "Ganhou na loteria Pokémon$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador ganhou na loteria\n"
	.string "Pokémon {STR_VAR_1} vezes!\p"
	.string "{STR_VAR_3} deve ter muitos\n"
	.string "amigos pra trocar Pokémon!$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle::
	.string "O treinador que usa a Day Care$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction::
	.string "Deixou Pokémon na Day Care$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador deixou Pokémon na\n"
	.string "Day Care {STR_VAR_1} vezes!\p"
	.string "{STR_VAR_3} leva o treinamento\n"
	.string "dos seus Pokémon muito a sério!$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle::
	.string "O fa do teleférico$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction::
	.string "Andou de teleférico$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador andou de teleférico\n"
	.string "{STR_VAR_1} vezes!\p"
	.string "{STR_VAR_3} vive pra cima e pra\n"
	.string "baixo!$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle::
	.string "O fa das fontes termais$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction::
	.string "Entrou nas fontes termais$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory::
	.string "Esta é a história de\n"
	.string "{STR_VAR_3}.\p"
	.string "Esse treinador entrou nas fontes\n"
	.string "termais {STR_VAR_1} vezes!\p"
	.string "{STR_VAR_3} deve ter a pele\n"
	.string "macia como a de um bebê!$"


MauvilleCity_PokemonCenter_1F_EventScript_Storyteller::
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, StorytellerGetFreeStorySlot
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales
	message MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell
	waitmessage
	special StorytellerStoryListMenu
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection
	setvar VAR_0x8008, 1
	special Script_StorytellerDisplayStory
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, StorytellerUpdateStat
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales
	goto MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale

MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection::
	goto MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	end

MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasStorytellerAlreadyRecorded
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd
	goto MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales

MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, Script_StorytellerInitializeRandomStat
	goto_if_eq VAR_RESULT, 1, MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
	msgbox MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller::
	msgbox MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

@ Unused
MauvilleCity_PokemonCenter_1F_EventScript_WaitingForRecordMix::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd::
	release
	end

@ Giddy
MauvilleCity_PokemonCenter_1F_Text_HearMyStory:
	.string "Sou Giddy! Tenho uma história\n"
	.string "animada pra contar!\p"
	.string "Quer ouvir?$"

MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues:
	.string "Ah... Você me deixou triste...$"

MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking:
	.string "Também tava pensando...$"

MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain:
	.string "Acho que é isso...\p"
	.string "Vamos conversar de novo! Tchau!$"

MauvilleCity_PokemonCenter_1F_EventScript_Giddy::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_HearMyStory, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	end

@ Giddy will continue to tell stories regardless of whether yes or no is selected below.
@ Each story there is a 10% chance it will be his last. Otherwise he will stop at 10 stories.
MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale::
	special GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy::
	msgbox MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong:
	.string "Oi, sou o Bard. Quer ouvir minha\n"
	.string "música?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1:
	.string "Ah... Você me deixou triste...$"

MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers:
	.string "Que música emocionante... Queria\n"
	.string "cantar pra outras pessoas...$"

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics:
	.string "E entao? Gostou da música?\p"
	.string "Nao tô muito feliz com a letra.\p"
	.string "Quer escrever uma nova pra mim?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2:
	.string "Ah... Você me deixou triste...$"

MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou:
	.string "Muito obrigado! Vou cantar pra\n"
	.string "você.$"

MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo:
	.string "Era assim que queria a música?$"

MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile:
	.string "Certo! Vou cantar essa música por\n"
	.string "um tempo.$"

MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening:
	.string "Ei! Me chamam de Hipster. Vou\n"
	.string "mostrar oque ta na moda.$"

MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou:
	.string "Mas eu já mostrei as novidades pra\n"
	.string "você.\p"
	.string "Quero contar pra outras pessoas\n"
	.string "também.$"

MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach:
	.string "Você já conhece um monte de\n"
	.string "novidades.\p"
	.string "Nao tenho mais nada pra ensinar!$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord:
	.string "Ei, já ouviu falar de\n"
	.string "“{STR_VAR_1}”?\p"
	.string "Oque significa? Bem... Pergunte pro\n"
	.string "seu pai ou sua mae, ta?$"
