PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition:
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_Text_FastRunningCurrent:
	.string "A correnteza entre Pacifidlog e\n"
	.string "Slateport é muito forte.\p"
	.string "Se usar Surf, pode acabar sendo\n"
	.string "levado pra outro lugar.$"

PacifidlogTown_Text_NeatHousesOnWater:
	.string "Legal, né? As casas ficam em cima\n"
	.string "da água!\p"
	.string "Nasci aqui!$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "Sky Pillar?\p"
	.string "Ah, você ta falando daquela torre\n"
	.string "enorme um pouco mais longe.\p"
	.string "Eu nao subiria lá. Tenho medo de\n"
	.string "altura.\p"
	.string "Viver no nível do mar em Pacifidlog\n"
	.string "já ta bom demais.$"

PacifidlogTown_Text_TownSign:
	.string "Pacifidlog Town\p"
	.string "“Onde o sol da manha sorri sobre\n"
	.string "as águas.”$"

