PacifidlogTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PacifidlogTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PACIFIDLOG_TOWN
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_PACIFIDLOG_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Girl::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Woman::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_OldMan::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard:
	.string "Qual é a cor do seu cartao de\n"
	.string "treinador? O meu é de cobre!$"

PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola:
	.string "Pacifidlog Town flutua em cima de\n"
	.string "uma colônia de Corsola.\p"
	.string "Você acreditaria se eu dissesse\n"
	.string "isso?$"

PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats:
	.string "Dizem que os antepassados do\n"
	.string "pessoal daqui nasciam, viviam e\l"
	.string "morriam em barcos.\p"
	.string "Parece que viviam assim porque\n"
	.string "procuravam alguma coisa.$"

