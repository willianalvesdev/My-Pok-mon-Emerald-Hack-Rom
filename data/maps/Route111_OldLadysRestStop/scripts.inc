Route111_OldLadysRestStop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OldLadysRestStop_OnTransition
	.byte 0

Route111_OldLadysRestStop_OnTransition:
	setflag FLAG_LANDMARK_OLD_LADY_REST_SHOP
	end

Route111_OldLadysRestStop_EventScript_OldLady::
	lock
	faceplayer
	msgbox Route111_OldLadysRestStop_Text_RestUpHere, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_Rest::
	msgbox Route111_OldLadysRestStop_Text_TakeYourTimeRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_DeclineRest::
	msgbox Route111_OldLadysRestStop_Text_DontNeedToBeShy, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_Text_RestUpHere:
	.string "Ah, meu bem, seus Pokémon nao tao\n"
	.string "exaustos?\p"
	.string "Se quiser, descanse aqui. É uma\n"
	.string "boa ideia!$"

Route111_OldLadysRestStop_Text_TakeYourTimeRestUp:
	.string "Isso mesmo. Fique à vontade e\n"
	.string "descanse!$"

Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest:
	.string "Ah, seus Pokémon ainda tao\n"
	.string "cansados?\p"
	.string "Descanse mais um pouco aqui. Vai\n"
	.string "fazer bem.$"

Route111_OldLadysRestStop_Text_DontNeedToBeShy:
	.string "Ah, é? Nao precisa ficar com\n"
	.string "vergonha.$"

