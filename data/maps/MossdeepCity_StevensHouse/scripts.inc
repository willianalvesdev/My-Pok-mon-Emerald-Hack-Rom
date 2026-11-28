MossdeepCity_StevensHouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_StevensHouse_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_StevensHouse_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_StevensHouse_OnFrame
	.byte 0

MossdeepCity_StevensHouse_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, MossdeepCity_StevensHouse_EventScript_HideStevensNote
	end

MossdeepCity_StevensHouse_EventScript_HideStevensNote::
	setmetatile 6, 4, METATILE_GenericBuilding_TableEdge, TRUE
	return

MossdeepCity_StevensHouse_OnTransition:
	call_if_eq VAR_STEVENS_HOUSE_STATE, 2, MossdeepCity_StevensHouse_EventScript_SetStevenPos
	end

MossdeepCity_StevensHouse_EventScript_SetStevenPos::
	setobjectxyperm LOCALID_STEVENS_HOUSE_STEVEN, 6, 5
	setobjectmovementtype LOCALID_STEVENS_HOUSE_STEVEN, MOVEMENT_TYPE_FACE_UP
	return

MossdeepCity_StevensHouse_OnFrame:
	map_script_2 VAR_STEVENS_HOUSE_STATE, 1, MossdeepCity_StevensHouse_EventScript_StevenGivesDive
	.2byte 0

MossdeepCity_StevensHouse_EventScript_StevenGivesDive::
	lockall
	applymovement LOCALID_STEVENS_HOUSE_STEVEN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_STEVENS_HOUSE_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STEVENS_HOUSE_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_STEVENS_HOUSE_STEVEN, MossdeepCity_StevensHouse_Movement_StevenApproachPlayer
	waitmovement 0
	msgbox MossdeepCity_StevensHouse_Text_YouveEarnedHMDive, MSGBOX_DEFAULT
	giveitem ITEM_HM_DIVE
	setflag FLAG_RECEIVED_HM_DIVE
	setflag FLAG_OMIT_DIVE_FROM_STEVEN_LETTER
	msgbox MossdeepCity_StevensHouse_Text_ExplainDive, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_STEVENS_HOUSE_STEVEN, MossdeepCity_StevensHouse_Movement_StevenReturn
	waitmovement 0
	setflag FLAG_HIDE_MOSSDEEP_CITY_SCOTT
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT
	setvar VAR_STEVENS_HOUSE_STATE, 2
	releaseall
	end

MossdeepCity_StevensHouse_Movement_StevenApproachPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MossdeepCity_StevensHouse_Movement_StevenReturn:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MossdeepCity_StevensHouse_EventScript_BeldumPokeball::
	lockall
	msgbox MossdeepCity_StevensHouse_Text_TakeBallContainingBeldum, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_StevensHouse_EventScript_LeaveBeldum
	goto MossdeepCity_StevensHouse_EventScript_GiveBeldum
	end

MossdeepCity_StevensHouse_EventScript_LeaveBeldum::
	msgbox MossdeepCity_StevensHouse_Text_LeftPokeBallWhereItWas, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_GiveBeldum::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_BELDUM
	givemon SPECIES_BELDUM, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MossdeepCity_StevensHouse_EventScript_SendBeldumParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MossdeepCity_StevensHouse_EventScript_SendBeldumPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

MossdeepCity_StevensHouse_EventScript_SendBeldumParty::
	call MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
	end

MossdeepCity_StevensHouse_EventScript_SendBeldumPC::
	call MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC
	end

MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
	end

MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_BELDUM
	removeobject LOCALID_STEVENS_HOUSE_BALL
	playfanfare MUS_OBTAIN_ITEM
	message MossdeepCity_StevensHouse_Text_ObtainedBeldum
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_BELDUM
	return

MossdeepCity_StevensHouse_EventScript_ReceivedBeldum::
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_BELDUM_POKEBALL
	setflag FLAG_RECEIVED_BELDUM
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_RockDisplay::
	msgbox MossdeepCity_StevensHouse_Text_CollectionOfRareRocks, MSGBOX_SIGN
	end

MossdeepCity_StevensHouse_EventScript_Steven::
	msgbox MossdeepCity_StevensHouse_Text_UnderwateCavernBetweenMossdeepSootopolis, MSGBOX_NPC
	end

MossdeepCity_StevensHouse_EventScript_Letter::
	lockall
	msgbox MossdeepCity_StevensHouse_Text_LetterFromSteven, MSGBOX_DEFAULT
	releaseall
	end

@ Unused, leftover from RS
MossdeepCity_StevensHouse_EventScript_DiveItemBall::
	finditem ITEM_HM_DIVE
	setflag FLAG_RECEIVED_HM_DIVE
	end

MossdeepCity_StevensHouse_Text_YouveEarnedHMDive:
	.string "STEVEN: {PLAYER}{KUN}...\p"
	.string "Como pode ver, nao tem muita coisa\n"
	.string "aqui, mas é minha casa.\p"
	.string "Obrigado por tudo. Quero dar a\n"
	.string "você a HM Dive.\p"
	.string "Pode aceitar, você merece.$"

MossdeepCity_StevensHouse_Text_ExplainDive:
	.string "STEVEN: Enquanto usa Surf, você\n"
	.string "vai ver partes mais escuras da\l"
	.string "água.\p"
	.string "Use Dive nessas partes profundas\n"
	.string "pra descer até o fundo do mar.\p"
	.string "Pra voltar, use Dive de novo.\p"
	.string "Mas tem lugares onde nao é\n"
	.string "possível subir.$"

MossdeepCity_StevensHouse_Text_UnderwateCavernBetweenMossdeepSootopolis:
	.string "STEVEN: Parece que existe uma\n"
	.string "caverna submersa entre Mossdeep e\l"
	.string "Sootopolis.\p"
	.string "É aquela que o capitao Stern\n"
	.string "encontrou com o submarino.$"

MossdeepCity_StevensHouse_Text_TakeBallContainingBeldum:
	.string "{PLAYER} olhou a Poké Ball.\p"
	.string "Tem um Beldum dentro dela.\p"
	.string "Pegar a Poké Ball?$"

MossdeepCity_StevensHouse_Text_ObtainedBeldum:
	.string "{PLAYER} recebeu um Beldum.$"

@ Unused
MossdeepCity_StevensHouse_Text_NoSpaceForAnotherMon:
	.string "Nao tem espaço pra outro Pokémon.$"

MossdeepCity_StevensHouse_Text_LeftPokeBallWhereItWas:
	.string "{PLAYER} deixou a Poké Ball onde\n"
	.string "estava.$"

MossdeepCity_StevensHouse_Text_LetterFromSteven:
	.string "É uma carta.\p"
	.string "...\p"
	.string "Para {PLAYER}{KUN}...\p"
	.string "Decidi viajar pra pensar um pouco\n"
	.string "na vida e treinar pelo caminho. Nao\l"
	.string "devo voltar pra casa tao cedo.\p"
	.string "Tenho um favor a pedir. Pegue a\n"
	.string "Poké Ball em cima da mesa.\p"
	.string "Dentro dela tem um Beldum, meu\n"
	.string "Pokémon favorito.\p"
	.string "Conto com você. Espero que a\n"
	.string "gente se encontre de novo.\p"
	.string "Steven Stone$"

MossdeepCity_StevensHouse_Text_CollectionOfRareRocks:
	.string "É uma coleçao de pedras raras\n"
	.string "reunida por Steven.$"

