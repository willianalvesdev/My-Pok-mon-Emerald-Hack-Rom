Route114_FossilManiacsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_OnTransition
	.byte 0

Route114_FossilManiacsHouse_OnTransition:
	setflag FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE
	end

Route114_FossilManiacsHouse_EventScript_FossilManiacsBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_DIG, Route114_FossilManiacsHouse_EventScript_ReceivedDig
	msgbox Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother, MSGBOX_DEFAULT
	giveitem ITEM_TM_DIG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_DIG
	release
	end

Route114_FossilManiacsHouse_EventScript_ReceivedDig::
	msgbox Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsHouse_EventScript_RockDisplay::
	msgbox Route114_FossilManiacsHouse_Text_RocksFillDisplayCase, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_EventScript_Bookshelf::
	msgbox Route114_FossilManiacsHouse_Text_CrammedWithBooks, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother:
	.string "Meu irmao é o Fossil Maniac... Ele\n"
	.string "é legal e adora fósseis...\p"
	.string "Também gosta de cavar. Fez esse\n"
	.string "buraco sozinho...\p"
	.string "Leve isto pra poder usar Dig e\n"
	.string "cavar como ele...$"

Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance:
	.string "Se seu Pokémon usar Dig dentro de\n"
	.string "uma caverna, você volta pra\l"
	.string "entrada...$"

Route114_FossilManiacsHouse_Text_RocksFillDisplayCase:
	.string "O mostruário ta cheio de pedras de\n"
	.string "formatos estranhos...$"

Route114_FossilManiacsHouse_Text_CrammedWithBooks:
	.string "COMO AS CAMADAS DO SOLO SE\n"
	.string "FORMAM... COMO A CHUVA MUDA A\l"
	.string "TERRA... PEDRAS E SOLO...\p"
	.string "Está cheio de livros.$"

