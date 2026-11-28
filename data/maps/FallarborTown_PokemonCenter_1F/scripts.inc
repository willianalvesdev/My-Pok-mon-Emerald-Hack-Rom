FallarborTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FallarborTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FALLARBOR_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

FallarborTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FALLARBOR_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_Girl::
	msgbox FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_Lanette::
	lock
	faceplayer
	msgbox FallarborTown_PokemonCenter_1F_Text_LanetteGreeting, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_NORTH, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth
	case DIR_WEST, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth::
	applymovement LOCALID_FALLARBOR_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest::
	applymovement LOCALID_FALLARBOR_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExited::
	playse SE_SLIDING_DOOR
	removeobject LOCALID_FALLARBOR_LANETTE
	clearflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	release
	end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Text_LanetteGreeting:
	.string "Ah, oi. Quem é você?\p"
	.string "Entao seu nome é {PLAYER}{KUN}. Vejo\n"
	.string "que é um treinador.\p"
	.string "Isso significa que usa o Sistema\n"
	.string "de Armazenamento Pokémon que eu\l"
	.string "desenvolvi.\p"
	.string "Cheguei a essa conclusao por um\n"
	.string "raciocínio bem simples.\p"
	.string "Você falou comigo porque queria\n"
	.string "usar alguma coisa neste PC.\p"
	.string "Ah, desculpe. Sou LANETTE.\p"
	.string "É um prazer te conhecer. Fico\n"
	.string "feliz que use meu sistema.\p"
	.string "Se puder, passe na minha casa.\n"
	.string "Fica na ROUTE 114.$"

FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown:
	.string "Como será que eram os POKÉMONS há\n"
	.string "muito tempo?\p"
	.string "Talvez o fanático por fósseis lá\n"
	.string "na saída da cidade saiba.$"

FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees:
	.string "Nos campos de FALLARBOR,\n"
	.string "plantamos árvores resistentes que\l"
	.string "crescem até nas cinzas do vulcao.$"

