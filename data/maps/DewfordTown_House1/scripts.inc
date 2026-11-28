DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.string "É bom demais morar numa ilha\n"
	.string "pequena assim, em paz com os\l"
	.string "POKÉMONS e com a família.$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "Saí do grande porto de SLATEPORT\n"
	.string "CITY quando me casei com meu\l"
	.string "marido.\p"
	.string "A vida passa devagar nesta ilha.\n"
	.string "Mas esse mar lindo em volta também\l"
	.string "é felicidade.$"

DewfordTown_House1_Text_Zigzagoon:
	.string "ZIGZAGOON: Guguuh!$"

