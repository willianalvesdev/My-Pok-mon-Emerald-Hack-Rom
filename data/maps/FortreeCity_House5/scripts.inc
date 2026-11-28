FortreeCity_House5_MapScripts::
	.byte 0

FortreeCity_House5_EventScript_PokefanF::
	msgbox FortreeCity_House5_Text_TreeHousesAreGreat, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Man::
	msgbox FortreeCity_House5_Text_AdaptedToNature, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House5_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House5_Text_TreeHousesAreGreat:
	.string "As casas nas árvores de FORTREE\n"
	.string "sao ótimas!\p"
	.string "Acho que é a melhor cidade pra\n"
	.string "viver junto dos POKÉMONS.$"

FortreeCity_House5_Text_AdaptedToNature:
	.string "Pessoas e POKÉMONS aprenderam a\n"
	.string "viver junto da natureza.\p"
	.string "Nao precisamos mudar tudo nela só\n"
	.string "pra ficar do nosso jeito.$"

FortreeCity_House5_Text_Zigzagoon:
	.string "ZIGZAGOON: Bufuu!$"

