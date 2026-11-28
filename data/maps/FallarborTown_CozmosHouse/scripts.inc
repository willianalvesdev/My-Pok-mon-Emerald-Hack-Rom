FallarborTown_CozmosHouse_MapScripts::
	.byte 0

FallarborTown_CozmosHouse_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_GaveMeteorite
	checkitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite::
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_RECEIVED_TM_RETURN
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_NoticeMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	msgbox FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_AskForMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MayIHaveMeteorite, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite::
	setflag FLAG_TEMP_2
	msgbox FallarborTown_CozmosHouse_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_GaveMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmosWife::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsSad
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsSad::
	msgbox FallarborTown_CozmosHouse_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsHappy::
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow:
	.string "PROF. COZMO: Ah... Eu nao devia\n"
	.string "ter caído na conversa do Team\l"
	.string "Magma e contado onde encontrar\l"
	.string "METEORITES...\p"
	.string "Aquele METEORITE de METEOR\n"
	.string "FALLS... Agora nunca vai ser meu...$"

FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt:
	.string "Ah! Hein?\p"
	.string "Esse item...\p"
	.string "Nao pode ser!\p"
	.string "É o METEORITE que o Team Magma\n"
	.string "levou de METEOR FALLS?\p"
	.string "Por favor, pode me dar ele?\p"
	.string "Nao quero de graça. Que tal trocar\n"
	.string "por esta TM?$"

FallarborTown_CozmosHouse_Text_PleaseUseThisTM:
	.string "PROF. COZMO: Esta TM é meu jeito\n"
	.string "de agradecer. Aproveite!$"

FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch:
	.string "PROF. COZMO: Nem acredito. Isso é\n"
	.string "bom demais!\p"
	.string "Vai ajudar muito na minha\n"
	.string "pesquisa!$"

FallarborTown_CozmosHouse_Text_CrushedWithDisappointment:
	.string "PROF. COZMO: Ah, mas... Fiquei\n"
	.string "muito decepcionado...$"

FallarborTown_CozmosHouse_Text_MayIHaveMeteorite:
	.string "PROF. COZMO: Por favor, pode me\n"
	.string "dar aquele METEORITE?\p"
	.string "Nao quero de graça. Que tal trocar\n"
	.string "por esta TM?$"

FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls:
	.string "O Professor COZMO foi até METEOR\n"
	.string "FALLS, na ROUTE 114, com umas\l"
	.string "pessoas do Team Magma.$"

FallarborTown_CozmosHouse_Text_FeelSorryForCozmo:
	.string "Coitado do Professor COZMO... Ta\n"
	.string "tao triste... Fico com pena dele.$"

FallarborTown_CozmosHouse_Text_CozmoIsSoHappy:
	.string "Olha o Professor COZMO... Ta tao\n"
	.string "feliz! Acho uma graça.$"

