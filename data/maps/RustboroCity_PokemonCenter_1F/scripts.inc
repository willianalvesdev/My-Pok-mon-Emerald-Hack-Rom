RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_RUSTBORO_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "Meu Pokémon tem natureza Naive e\n"
	.string "o do meu amigo é Jolly.\p"
	.string "É muito legal ver que eles têm\n"
	.string "personalidades diferentes!$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "Assim como as pessoas, tem\n"
	.string "Pokémon machos e fêmeas.\p"
	.string "Mas parece que ninguém sabe\n"
	.string "direito como eles sao diferentes.$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "O homem da casa ao lado me deu\n"
	.string "uma HM!\p"
	.string "Usei pra ensinar Cut ao meu\n"
	.string "Pokémon e cortar árvores finas.$"

