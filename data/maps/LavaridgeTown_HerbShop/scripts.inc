LavaridgeTown_HerbShop_MapScripts::
	.byte 0

LavaridgeTown_HerbShop_EventScript_Clerk::
	lock
	faceplayer
	message LavaridgeTown_HerbShop_Text_WelcomeToHerbShop
	waitmessage
	pokemart LavaridgeTown_HerbShop_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_HerbShop_Pokemart:
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	pokemartlistend

LavaridgeTown_HerbShop_EventScript_ExpertM::
	msgbox LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike, MSGBOX_NPC
	end

LavaridgeTown_HerbShop_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CHARCOAL, LavaridgeTown_HerbShop_EventScript_ExplainCharcoal
	msgbox LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CHARCOAL
	release
	end

LavaridgeTown_HerbShop_EventScript_ExplainCharcoal::
	msgbox LavaridgeTown_HerbShop_Text_ExplainCharcoal, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_HerbShop_Text_WelcomeToHerbShop:
	.string "Bem-vindo à loja de ervas!\n"
	.string "Remédios que funcionam e cabem no\l"
	.string "bolso!$"

LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine:
	.string "Veio conhecer os remédios de ervas\n"
	.string "de LAVARIDGE?\p"
	.string "Que boa iniciativa.\p"
	.string "Gostei de você! Pegue isto!$"

LavaridgeTown_HerbShop_Text_ExplainCharcoal:
	.string "O CHARCOAL que te dei é usado pra\n"
	.string "fazer remédios de ervas.\p"
	.string "Também ajuda muito quando um\n"
	.string "POKÉMON segura.\p"
	.string "Aumenta a força dos golpes do tipo\n"
	.string "Fogo.$"

LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike:
	.string "Os remédios de ervas funcionam\n"
	.string "muito bem, mas seus POKÉMONS nao\l"
	.string "vao gostar de você por usar. Devem\l"
	.string "ser amargos demais!$"

