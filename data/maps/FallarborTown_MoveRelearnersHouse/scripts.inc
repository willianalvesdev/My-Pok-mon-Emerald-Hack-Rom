FallarborTown_MoveRelearnersHouse_MapScripts::
	.byte 0

FallarborTown_MoveRelearnersHouse_EventScript_MoveRelearner::
	lockall
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
	msgbox FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	msgbox FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
	setmoverelearnerstate MOVE_RELEARNER_LEVEL_UP_MOVES @ Specifically supposed to teach level up moves
	chooseboxmon SELECT_PC_MON_MOVE_RELEARNER
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg
	special Special_HasMoveToRelearn
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	msgbox FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	end

FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg::
	msgbox FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale::
	msgbox FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	releaseall
	end

FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor:
	.string "Sou o tutor de golpes.\p"
	.string "Conheço todos os golpes que os\n"
	.string "POKÉMONS aprendem e posso ensinar\l"
	.string "eles de novo.\p"
	.string "Se quiser, posso ensinar um golpe\n"
	.string "a um dos seus POKÉMONS.\p"
	.string "Em troca, peço uma HEART SCALE.\n"
	.string "Estou colecionando essas coisas.$"

FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove:
	.string "Ah! É ela! Uma HEART SCALE de\n"
	.string "verdade!\p"
	.string "Deixa eu adivinhar, quer que eu\n"
	.string "ensine um golpe?$"

FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon:
	.string "Qual POKÉMON vai aprender?$"

FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove:
	.string "Qual golpe devo ensinar?$"

FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon:
	.string "Desculpe...\p"
	.string "Parece que nao tenho nenhum golpe\n"
	.string "pra ensinar a esse POKÉMON.$"

FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale:
	.string "{PLAYER} entregou uma HEART SCALE\n"
	.string "em troca.$"

FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale:
	.string "Se seus POKÉMONS precisarem\n"
	.string "aprender um golpe, volte com uma\l"
	.string "HEART SCALE.$"

FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg:
	.string "Hein? Nao tem nenhum golpe que eu\n"
	.string "possa ensinar a um Ovo.$"

