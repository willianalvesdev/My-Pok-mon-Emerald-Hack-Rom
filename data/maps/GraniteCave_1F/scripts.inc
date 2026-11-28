GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "Ei, você. Mais à frente fica escuro\n"
	.string "demais. Vai ser difícil explorar.\p"
	.string "O rapaz que passou aqui antes...\n"
	.string "Acho que era STEVEN.\p"
	.string "Ele sabia usar FLASH, entao deve\n"
	.string "ficar bem...\p"
	.string "A gente que gosta de montanha tem\n"
	.string "o costume de ajudar quem\l"
	.string "encontra.\p"
	.string "Pegue isto, vou passar pra você.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Ensine FLASH a um POKÉMON e use o\n"
	.string "golpe.\p"
	.string "Ele ilumina até as partes mais\n"
	.string "escuras das cavernas.\p"
	.string "Mas você precisa da insígnia do\n"
	.string "ginásio de DEWFORD pra usar.$"

