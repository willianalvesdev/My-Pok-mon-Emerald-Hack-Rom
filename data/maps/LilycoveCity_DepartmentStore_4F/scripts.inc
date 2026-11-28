LilycoveCity_DepartmentStore_4F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_4F_EventScript_Gentleman::
	msgbox LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_Woman::
	msgbox LilycoveCity_DepartmentStore_4F_Text_FiftyDifferentTMs, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_Youngster::
	msgbox LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_ClerkLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_TMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Pokemart_TMs:
	.2byte ITEM_TM_FIRE_BLAST
	.2byte ITEM_TM_THUNDER
	.2byte ITEM_TM_BLIZZARD
	.2byte ITEM_TM_HYPER_BEAM
	.2byte ITEM_TM_PROTECT
	.2byte ITEM_TM_SAFEGUARD
	.2byte ITEM_TM_REFLECT
	.2byte ITEM_TM_LIGHT_SCREEN
	pokemartlistend

LilycoveCity_DepartmentStore_4F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_EvolutionItems
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Pokemart_EvolutionItems::
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_SUN_STONE
	.2byte ITEM_SHINY_STONE
	.2byte ITEM_DUSK_STONE
	.2byte ITEM_DAWN_STONE
	.2byte ITEM_ICE_STONE
	.2byte ITEM_LINKING_CORD
	.2byte ITEM_METAL_COAT
	.2byte ITEM_KINGS_ROCK
	.2byte ITEM_DRAGON_SCALE
	.2byte ITEM_UPGRADE
	.2byte ITEM_DEEP_SEA_TOOTH
	.2byte ITEM_DEEP_SEA_SCALE
	.2byte ITEM_PROTECTOR
	.2byte ITEM_ELECTIRIZER
	.2byte ITEM_MAGMARIZER
	.2byte ITEM_DUBIOUS_DISC
	.2byte ITEM_REAPER_CLOTH
	.2byte ITEM_OVAL_STONE
	.2byte ITEM_RAZOR_CLAW
	.2byte ITEM_RAZOR_FANG
	.2byte ITEM_PRISM_SCALE
	pokemartlistend

LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM:
	.string "Hum...\p"
	.string "Um golpe de ataque ou um de\n"
	.string "defesa...\p"
	.string "É difícil escolher quais golpes de\n"
	.string "TM ensinar pros Pokémon.$"

LilycoveCity_DepartmentStore_4F_Text_FiftyDifferentTMs:
	.string "Existem vários golpes de TM.\p"
	.string "Li num catálogo que sao cinquenta\n"
	.string "tipos diferentes.$"

LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves:
	.string "Queria ter todas as TMs, mas cada\n"
	.string "Pokémon só pode aprender quatro\l"
	.string "golpes.$"

