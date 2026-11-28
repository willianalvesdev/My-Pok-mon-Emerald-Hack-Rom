FortreeCity_Mart_MapScripts::
	.byte 0

FortreeCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FortreeCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FortreeCity_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_DUSK_BALL
	.2byte ITEM_HEAL_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_WOOD_MAIL
	pokemartlistend

FortreeCity_Mart_EventScript_Woman::
	msgbox FortreeCity_Mart_Text_SuperRepelBetter, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Girl::
	msgbox FortreeCity_Mart_Text_StockUpOnItems, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Boy::
	msgbox FortreeCity_Mart_Text_RareCandyMakesMonGrow, MSGBOX_NPC
	end

FortreeCity_Mart_Text_SuperRepelBetter:
	.string "SUPER REPEL dura bastante e\n"
	.string "funciona bem.\p"
	.string "É bem melhor que um REPEL comum.$"

FortreeCity_Mart_Text_StockUpOnItems:
	.string "Sempre compro mais itens do que\n"
	.string "acho que vou precisar.\p"
	.string "Nunca dá pra saber oque vai\n"
	.string "acontecer. Melhor prevenir!$"

FortreeCity_Mart_Text_RareCandyMakesMonGrow:
	.string "Um RARE CANDY faz um POKÉMON\n"
	.string "subir um nível na hora.$"

