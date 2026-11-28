LavaridgeTown_House_MapScripts::
	.byte 0

LavaridgeTown_House_EventScript_OldMan::
	msgbox LavaridgeTown_House_Text_WifeWarmingEggInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_House_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox LavaridgeTown_House_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LavaridgeTown_House_Text_WifeWarmingEggInHotSprings:
	.string "Minha esposa ta aquecendo um Ovo\n"
	.string "nas águas termais. Foi oque ela me\l"
	.string "contou.\p"
	.string "Ela deixou dois POKÉMONS no DAY\n"
	.string "CARE, e encontraram esse Ovo!$"

LavaridgeTown_House_Text_Zigzagoon:
	.string "ZIGZAGOON: Pshoo!$"

