Route119_House_MapScripts::
	.byte 0

Route119_House_EventScript_Woman::
	msgbox Route119_House_Text_RumorAboutCaveOfOrigin, MSGBOX_NPC
	end

Route119_House_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route119_House_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route119_House_Text_RumorAboutCaveOfOrigin:
	.string "Ouvi falar de uma caverna chamada\n"
	.string "Cave of Origin.\p"
	.string "Dizem que os espíritos dos Pokémon\n"
	.string "voltam à vida lá. Será que isso\l"
	.string "acontece mesmo?$"

Route119_House_Text_Wingull:
	.string "WINGULL: Pihyoh!$"

