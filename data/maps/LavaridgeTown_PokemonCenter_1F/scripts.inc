LavaridgeTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LavaridgeTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_LAVARIDGE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_LAVARIDGE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Youngster::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Woman::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether:
	.string "Acho que os POKÉMONS ficam mais\n"
	.string "próximos dos treinadores quando\l"
	.string "passam tempo juntos.\p"
	.string "Quanto mais, melhor. É oque eu\n"
	.string "acho.$"

LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate:
	.string "É quase mágica. Você fica sentado\n"
	.string "na água quente e já sai com outra\l"
	.string "disposiçao.\p"
	.string "Queria que meus Pokémon pudessem\n"
	.string "entrar também.$"

LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo:
	.string "Hohoho! Ei, você pode chegar às\n"
	.string "fontes termais por aqui.\p"
	.string "Se os Pokémon descansam, quem\n"
	.string "treina eles também precisa\l"
	.string "descansar.$"

