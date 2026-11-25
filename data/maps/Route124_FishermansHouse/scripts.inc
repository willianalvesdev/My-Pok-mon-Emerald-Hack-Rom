Route124_FishermansHouse_MapScripts::
	.byte 0

Route124_FishermansHouse_EventScript_Magikarp::
	lockall
	goto_if_set FLAG_ROUTE124_RECEIVED_SHINY_MAGIKARP, Route124_FishermansHouse_End
	msgbox Route124_FishermansHouse_Text_Offer, MSGBOX_YESNO
	goto_if_ne VAR_RESULT, YES, Route124_FishermansHouse_End
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MAGIKARP
	givemon SPECIES_MAGIKARP, 5, shinyMode=SHINY_MODE_ALWAYS
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route124_FishermansHouse_GivenToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route124_FishermansHouse_GivenToPC
	msgbox Route124_FishermansHouse_Text_NoRoom, MSGBOX_DEFAULT
	goto Route124_FishermansHouse_End

Route124_FishermansHouse_GivenToParty:
	call Route124_FishermansHouse_ReceivedMagikarp
	goto Route124_FishermansHouse_End

Route124_FishermansHouse_GivenToPC:
	call Route124_FishermansHouse_ReceivedMagikarp
	call Common_EventScript_TransferredToPC

Route124_FishermansHouse_End:
	releaseall
	end

Route124_FishermansHouse_ReceivedMagikarp:
	setflag FLAG_ROUTE124_RECEIVED_SHINY_MAGIKARP
	removeobject LOCALID_FISHERMANS_HOUSE_MAGIKARP_BALL
	playfanfare MUS_OBTAIN_ITEM
	msgbox Route124_FishermansHouse_Text_ReceivedMagikarp, MSGBOX_DEFAULT
	waitfanfare
	return

Route124_FishermansHouse_Text_Offer:
	.string "Tem um Magikarp dourado aqui!\n"
	.string "Quer pegar a Poké Bola?$"

Route124_FishermansHouse_Text_ReceivedMagikarp:
	.string "Você recebeu um Magikarp shiny!$"

Route124_FishermansHouse_Text_NoRoom:
	.string "Falta espaço na equipe e no PC.\n"
	.string "A Poké Bola ficou na mesa.$"
