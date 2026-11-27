SootopolisCity_DreamHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_DreamHouse_OnTransition
	.byte 0

SootopolisCity_DreamHouse_OnTransition:
	clearflag FLAG_TEMP_1
	call_if_unset FLAG_SYS_GAME_CLEAR, SootopolisCity_DreamHouse_HideWitch
	end

SootopolisCity_DreamHouse_HideWitch:
	setflag FLAG_TEMP_1
	return

SootopolisCity_DreamHouse_EventScript_Witch::
	lock
	faceplayer
	switch VAR_DREAM_WITCH_STAGE
	case 0, SootopolisCity_DreamHouse_RequestCubone
	case 1, SootopolisCity_DreamHouse_RequestBanette
	case 2, SootopolisCity_DreamHouse_RequestSpiritomb
	msgbox SootopolisCity_DreamHouse_Text_Rest, MSGBOX_DEFAULT
	goto SootopolisCity_DreamHouse_End

SootopolisCity_DreamHouse_RequestCubone:
	bufferspeciesname STR_VAR_1, SPECIES_CUBONE
	goto SootopolisCity_DreamHouse_Request

SootopolisCity_DreamHouse_RequestBanette:
	bufferspeciesname STR_VAR_1, SPECIES_BANETTE
	goto SootopolisCity_DreamHouse_Request

SootopolisCity_DreamHouse_RequestSpiritomb:
	bufferspeciesname STR_VAR_1, SPECIES_SPIRITOMB

SootopolisCity_DreamHouse_Request:
	msgbox SootopolisCity_DreamHouse_Text_Request, MSGBOX_YESNO
	goto_if_ne VAR_RESULT, YES, SootopolisCity_DreamHouse_End
	special ChoosePartyMon
	goto_if_ge VAR_0x8004, PARTY_SIZE, SootopolisCity_DreamHouse_End
	setvar VAR_0x8005, FALSE
	callnative Script_TryDonateDreamMon, requests_effects=1
	goto_if_ne VAR_RESULT, MON_DONATION_OK, SootopolisCity_DreamHouse_Refuse
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	msgbox SootopolisCity_DreamHouse_Text_Confirm, MSGBOX_YESNO
	goto_if_ne VAR_RESULT, YES, SootopolisCity_DreamHouse_End
	setvar VAR_0x8005, TRUE
	callnative Script_TryDonateDreamMon, requests_effects=1
	goto_if_ne VAR_RESULT, MON_DONATION_OK, SootopolisCity_DreamHouse_Refuse
	goto_if_eq VAR_DREAM_WITCH_STAGE, 3, SootopolisCity_DreamHouse_Reward
	msgbox SootopolisCity_DreamHouse_Text_Thanks, MSGBOX_DEFAULT
	goto SootopolisCity_DreamHouse_End

SootopolisCity_DreamHouse_Reward:
	playfanfare MUS_OBTAIN_ITEM
	msgbox SootopolisCity_DreamHouse_Text_Reward, MSGBOX_DEFAULT
	waitfanfare
	goto SootopolisCity_DreamHouse_End

SootopolisCity_DreamHouse_Refuse:
	switch VAR_RESULT
	case MON_DONATION_NEEDS_PARTNER, SootopolisCity_DreamHouse_NeedsPartner
	case MON_DONATION_HAS_ITEM, SootopolisCity_DreamHouse_HasItem
	case MON_DONATION_BAG_FULL, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_DreamHouse_Text_Invalid, MSGBOX_DEFAULT
	goto SootopolisCity_DreamHouse_End

SootopolisCity_DreamHouse_NeedsPartner:
	msgbox SootopolisCity_DreamHouse_Text_NeedsPartner, MSGBOX_DEFAULT
	goto SootopolisCity_DreamHouse_End

SootopolisCity_DreamHouse_HasItem:
	msgbox SootopolisCity_DreamHouse_Text_HasItem, MSGBOX_DEFAULT
	goto SootopolisCity_DreamHouse_End

SootopolisCity_DreamHouse_EventScript_Bed::
	lock
	goto_if_set FLAG_FINISHED_DREAM_DARKRAI, SootopolisCity_DreamHouse_QuietBed
	checkitem ITEM_DREAM_ORB
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_DreamHouse_QuietBed
	msgbox SootopolisCity_DreamHouse_Text_Sleep, MSGBOX_YESNO
	goto_if_ne VAR_RESULT, YES, SootopolisCity_DreamHouse_End
	closemessage
	fadescreen FADE_TO_BLACK
	delay 40
	warpsilent MAP_DREAM_ISLAND_SHORE, 27, 18
	waitstate
	end

SootopolisCity_DreamHouse_QuietBed:
	msgbox SootopolisCity_DreamHouse_Text_QuietBed, MSGBOX_DEFAULT

SootopolisCity_DreamHouse_End:
	release
	end

SootopolisCity_DreamHouse_Text_Request:
	.string "Preciso de um {STR_VAR_1}.\p"
	.string "Quer me entregar um da equipe?$"

SootopolisCity_DreamHouse_Text_Confirm:
	.string "Quer mesmo me entregar\n"
	.string "{STR_VAR_1}?\p"
	.string "A entrega é definitiva.$"

SootopolisCity_DreamHouse_Text_Thanks:
	.string "Obrigada. Ainda preciso de mais\n"
	.string "um ajudante. Fale comigo de novo.$"

SootopolisCity_DreamHouse_Text_Reward:
	.string "Agora sim. Pegue esta Dream Orb.\p"
	.string "Deite na cama e descanse um pouco.\n"
	.string "Deixe que a esfera guie seu sono.$"

SootopolisCity_DreamHouse_Text_Rest:
	.string "Descanse um pouco na minha cama.\n"
	.string "A esfera vai guiar seu sono.$"

SootopolisCity_DreamHouse_Text_Invalid:
	.string "Esse Pokémon é diferente\n"
	.string "do que eu pedi.$"

SootopolisCity_DreamHouse_Text_NeedsPartner:
	.string "Deixe outro Pokémon apto a lutar\n"
	.string "na sua equipe antes da entrega.$"

SootopolisCity_DreamHouse_Text_HasItem:
	.string "Retire o item que ele segura\n"
	.string "antes de entregá-lo.$"

SootopolisCity_DreamHouse_Text_Sleep:
	.string "A Dream Orb pulsa perto da cama.\n"
	.string "Quer se deitar e dormir?$"

SootopolisCity_DreamHouse_Text_QuietBed:
	.string "Uma cama coberta por um\n"
	.string "edredom pesado.$"
