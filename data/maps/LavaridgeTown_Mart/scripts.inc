LavaridgeTown_Mart_MapScripts::
	.byte 0

LavaridgeTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LavaridgeTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SPEED
	pokemartlistend

LavaridgeTown_Mart_EventScript_ExpertM::
	msgbox LavaridgeTown_Mart_Text_XSpeedFirstStrike, MSGBOX_NPC
	end

LavaridgeTown_Mart_EventScript_OldWoman::
	msgbox LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney, MSGBOX_NPC
	end

LavaridgeTown_Mart_Text_XSpeedFirstStrike:
	.string "Use X SPEED pra aumentar a\n"
	.string "Velocidade de um POKÉMON na\l"
	.string "batalha.\p"
	.string "Isso ajuda ele a atacar primeiro,\n"
	.string "oque dá uma boa vantagem!$"

LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney:
	.string "No topo do MT. CHIMNEY, vendem\n"
	.string "uma especialidade que você só\l"
	.string "encontra lá.\p"
	.string "Dê a um POKÉMON, e ele vai ficar\n"
	.string "bem feliz.$"

