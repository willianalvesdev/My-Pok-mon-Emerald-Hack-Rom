SlateportCity_PokemonFanClub_MapScripts::
	.byte 0

SlateportCity_PokemonFanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_unset FLAG_ENTERED_CONTEST, SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest
	call_if_unset FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_MeetChairman
	switch VAR_SLATEPORT_FAN_CLUB_STATE
	case 0, SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment
	case 1, SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon
	case 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 1
	msgbox SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon::
	setvar VAR_TEMP_2, 0
	call_if_set FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_eq VAR_TEMP_2, CONTEST_CATEGORIES_COUNT, SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves
	goto_if_eq VAR_SLATEPORT_FAN_CLUB_STATE, 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	msgbox SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_NoMoreScarves::
	msgbox SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon::
	msgbox SlateportCity_PokemonFanClub_Text_HmHmISee, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	call_if_unset FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonTough
	call_if_unset FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonSmart
	call_if_unset FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCute
	call_if_unset FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty
	call_if_unset FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCool
	bufferleadmonspeciesname STR_VAR_1
	switch VAR_TEMP_1
	case 0, SlateportCity_PokemonFanClub_EventScript_NoHighConditions
	case 1, SlateportCity_PokemonFanClub_EventScript_GiveRedScarf
	case 2, SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf
	case 3, SlateportCity_PokemonFanClub_EventScript_GivePinkScarf
	case 4, SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf
	case 5, SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 2
	return

SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf::
	addvar VAR_TEMP_2, 1
	return

SlateportCity_PokemonFanClub_EventScript_NoHighConditions::
	msgbox SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveRedScarf::
	checkitemspace ITEM_RED_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_RED_SCARF
	giveitem ITEM_RED_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainRedScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf::
	checkitemspace ITEM_BLUE_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_BLUE_SCARF
	giveitem ITEM_BLUE_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainBlueScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GivePinkScarf::
	checkitemspace ITEM_PINK_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_PINK_SCARF
	giveitem ITEM_PINK_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainPinkScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf::
	checkitemspace ITEM_GREEN_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_GREEN_SCARF
	giveitem ITEM_GREEN_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainGreenScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf::
	checkitemspace ITEM_YELLOW_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_YELLOW_SCARF
	giveitem ITEM_YELLOW_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainYellowScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf::
	msgbox SlateportCity_PokemonFanClub_Text_NoSpaceForReward, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_CheckMonCool::
	specialvar VAR_RESULT, CheckLeadMonCool
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCool
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCool::
	setvar VAR_TEMP_1, 1
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty::
	specialvar VAR_RESULT, CheckLeadMonBeauty
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonBeauty
	return

SlateportCity_PokemonFanClub_EventScript_SetMonBeauty::
	setvar VAR_TEMP_1, 2
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonCute::
	specialvar VAR_RESULT, CheckLeadMonCute
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCute
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCute::
	setvar VAR_TEMP_1, 3
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonSmart::
	specialvar VAR_RESULT, CheckLeadMonSmart
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonSmart
	return

SlateportCity_PokemonFanClub_EventScript_SetMonSmart::
	setvar VAR_TEMP_1, 4
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonTough::
	specialvar VAR_RESULT, CheckLeadMonTough
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonTough
	return

SlateportCity_PokemonFanClub_EventScript_SetMonTough::
	setvar VAR_TEMP_1, 5
	return

SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest::
	goto_if_set FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest::
	msgbox SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_MeetChairman::
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	return

SlateportCity_PokemonFanClub_EventScript_SootheBellWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SOOTHE_BELL, SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell
	msgbox SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, SlateportCity_PokemonFanClub_EventScript_GiveSootheBell
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveSootheBell::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_PokemonFanClub_Text_PokemonAdoresYou, MSGBOX_DEFAULT
	giveitem ITEM_SOOTHE_BELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SOOTHE_BELL
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell::
	msgbox SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_Man::
	msgbox SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Twin::
	msgbox SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_Text_MeetChairman:
	.string "Aham! Sou o presidente do fa-clube\n"
	.string "Pokémon! Naturalmente, a pessoa\l"
	.string "mais importante!\p"
	.string "Ninguém cuida dos Pokémon melhor\n"
	.string "que eu! Ninguém!\p"
	.string "Nos concursos, podemos mostrar\n"
	.string "nossos Pokémon pro mundo.\p"
	.string "Mas eles acontecem longe e nao\n"
	.string "consigo ir sempre.\p"
	.string "Por isso nos reunimos aqui pra\n"
	.string "mostrar nossos Pokémon e conhecer\l"
	.string "os dos outros.$"

SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon:
	.string "Queria ver o Pokémon de alguém que\n"
	.string "já participou de um concurso.$"

SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon:
	.string "Aham! Você já participou de um\n"
	.string "concurso Pokémon!\p"
	.string "Deixe eu ver como cuidou dos seus\n"
	.string "Pokémon. Adoro conhecer os que\l"
	.string "outros treinadores criaram.\p"
	.string "A carinha feliz de um Pokémon bem\n"
	.string "cuidado e o olhar carinhoso do\l"
	.string "treinador... Só de pensar já fico\l"
	.string "alegre!\p"
	.string "Ah, desculpa falar tanto! Vamos\n"
	.string "ver como seu Pokémon cresceu!$"

SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing:
	.string "Como seu Pokémon ta crescendo?\n"
	.string "Deixa eu olhar.$"

SlateportCity_PokemonFanClub_Text_HmHmISee:
	.string "Hum, hum... Entendo...$"

SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks:
	.string "Hum... Nao ta ruim, mas também nao\n"
	.string "ta bom...\p"
	.string "Você precisa se esforçar mais pra\n"
	.string "cuidar deste Pokémon!\p"
	.string "Que tal dar mais {POKEBLOCK}S a ele?$"

SlateportCity_PokemonFanClub_Text_NoSpaceForReward:
	.string "Ah... Seu Pokémon ta crescendo bem\n"
	.string "e você merece um presente.\p"
	.string "Mas sua bolsa nao tem espaço.$"

SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis:
	.string "Seu {STR_VAR_1} ta crescendo\n"
	.string "muito bem! Que belo Pokémon!\p"
	.string "Mas, com isto, pode ficar ainda\n"
	.string "melhor!$"

SlateportCity_PokemonFanClub_Text_ExplainRedScarf:
	.string "Deixe um Pokémon segurar Red\n"
	.string "Scarf.\p"
	.string "Todo mundo vai perceber como ele é\n"
	.string "estiloso!$"

SlateportCity_PokemonFanClub_Text_ExplainBlueScarf:
	.string "Deixe um Pokémon segurar Blue\n"
	.string "Scarf.\p"
	.string "A beleza dele vai chamar ainda\n"
	.string "mais atençao!$"

SlateportCity_PokemonFanClub_Text_ExplainPinkScarf:
	.string "Deixe um Pokémon segurar Pink\n"
	.string "Scarf.\p"
	.string "Ele vai parecer ainda mais fofo!$"

SlateportCity_PokemonFanClub_Text_ExplainGreenScarf:
	.string "Deixe um Pokémon segurar Green\n"
	.string "Scarf.\p"
	.string "Isso destaca a inteligência dele!$"

SlateportCity_PokemonFanClub_Text_ExplainYellowScarf:
	.string "Deixe um Pokémon segurar Yellow\n"
	.string "Scarf.\p"
	.string "Isso destaca ainda mais a força\n"
	.string "dele!$"

SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou:
	.string "Desculpa, nao tenho mais nada pra\n"
	.string "dar! Nada mesmo!\p"
	.string "Você tem o dom de cuidar dos\n"
	.string "Pokémon sem precisar de item\l"
	.string "nenhum!$"

SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou:
	.string "Adoro ver Pokémon que gostam dos\n"
	.string "seus treinadores.\p"
	.string "Eles percebem muito bem oque a\n"
	.string "gente sente.\p"
	.string "Se cuidar deles com carinho, vao\n"
	.string "gostar de você também.\p"
	.string "Quando isso acontecer, venha me\n"
	.string "mostrar.$"

SlateportCity_PokemonFanClub_Text_PokemonAdoresYou:
	.string "Seu Pokémon adora você.\p"
	.string "Pra um treinador tao cuidadoso,\n"
	.string "aqui vai um presente do fa-clube!$"

SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove:
	.string "Os Pokémon percebem muito bem\n"
	.string "oque seus treinadores sentem.\p"
	.string "Se cuidar deles com carinho, vao\n"
	.string "gostar de você também.$"

SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting:
	.string "Se deixar seu Pokémon desmaiar\n"
	.string "muitas vezes, ele vai ficar\l"
	.string "chateado.\p"
	.string "Pode começar a confiar menos em\n"
	.string "você.\p"
	.string "Ou seja, nao vai gostar tanto\n"
	.string "assim de você.$"

SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein:
	.string "Será que os Pokémon gostam quando\n"
	.string "usamos itens neles?\p"
	.string "O meu ficou bem feliz quando dei\n"
	.string "Protein.$"

SlateportCity_PokemonFanClub_Text_Skitty:
	.string "SKITTY: Fffnyaaaah...$"

SlateportCity_PokemonFanClub_Text_Zigzagoon:
	.string "ZIGZAGOON: Kyuuu...$"

SlateportCity_PokemonFanClub_Text_Azumarill:
	.string "AZUMARILL: Marimari?$"

