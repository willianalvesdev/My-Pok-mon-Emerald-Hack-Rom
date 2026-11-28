SootopolisCity_House4_MapScripts::
	.byte 0

SootopolisCity_House4_EventScript_Man::
	msgbox SootopolisCity_House4_Text_AncientTreasuresWaitingInSea, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Woman::
	msgbox SootopolisCity_House4_Text_StrollUnderwaterWithPokemon, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SootopolisCity_House4_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House4_Text_AncientTreasuresWaitingInSea:
	.string "Vou contar uma coisa boa.\p"
	.string "Dizem que tem uma ruína antiga no\n"
	.string "mar por aqui.\p"
	.string "Talvez tenha tesouros só\n"
	.string "esperando alguém encontrar.$"

SootopolisCity_House4_Text_StrollUnderwaterWithPokemon:
	.string "Tesouros antigos...\p"
	.string "Seria bom se existissem. Mas,\n"
	.string "mesmo sem eles, passear debaixo\l"
	.string "d'água com meu Pokémon já seria\l"
	.string "lindo.$"

SootopolisCity_House4_Text_Azumarill:
	.string "AZUMARILL: Marurii.$"

