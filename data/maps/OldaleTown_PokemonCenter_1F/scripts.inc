OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_OLDALE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "Qualquer treinador pode usar\n"
	.string "aquele PC no canto.\p"
	.string "Isso inclui você, claro.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "Os Centros Pokémon sao ótimos!\p"
	.string "Você pode usar o quanto quiser e\n"
	.string "tudo é de graça. Nao precisa se\l"
	.string "preocupar!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "O Pokémon Wireless Club do segundo\n"
	.string "andar foi construído faz pouco\l"
	.string "tempo.\p"
	.string "Mas dizem que ainda tao ajustando\n"
	.string "algumas coisas.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "O Pokémon Wireless Club do segundo\n"
	.string "andar foi construído faz pouco\l"
	.string "tempo.\p"
	.string "Já aproveitei pra trocar Pokémon!$"

