OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "Quando os Pokémon batalham,\n"
	.string "ganham níveis e ficam mais fortes.$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "Com Pokémon mais fortes, você\n"
	.string "consegue ir cada vez mais longe.$"

