Route124_ShinyCollectorHouse_MapScripts::
	.byte 0

Route124_ShinyCollectorHouse_EventScript_Collector::
	lock
	faceplayer
	checkitem ITEM_SHINY_CHARM
	goto_if_eq VAR_RESULT, TRUE, Route124_ShinyCollectorHouse_AlreadyRewarded
	msgbox Route124_ShinyCollectorHouse_Text_Offer, MSGBOX_YESNO
	goto_if_ne VAR_RESULT, YES, Route124_ShinyCollectorHouse_End
	special ChoosePartyMon
	goto_if_ge VAR_0x8004, PARTY_SIZE, Route124_ShinyCollectorHouse_End
	setvar VAR_0x8005, FALSE
	callnative Script_TryDonateShinyMon, requests_effects=1
	goto_if_ne VAR_RESULT, MON_DONATION_OK, Route124_ShinyCollectorHouse_Refuse
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	msgbox Route124_ShinyCollectorHouse_Text_Confirm, MSGBOX_YESNO
	goto_if_ne VAR_RESULT, YES, Route124_ShinyCollectorHouse_End
	setvar VAR_0x8005, TRUE
	callnative Script_TryDonateShinyMon, requests_effects=1
	goto_if_ne VAR_RESULT, MON_DONATION_OK, Route124_ShinyCollectorHouse_Refuse
	playfanfare MUS_OBTAIN_ITEM
	msgbox Route124_ShinyCollectorHouse_Text_Reward, MSGBOX_DEFAULT
	waitfanfare
	goto Route124_ShinyCollectorHouse_End

Route124_ShinyCollectorHouse_Refuse:
	switch VAR_RESULT
	case MON_DONATION_ALREADY_REWARDED, Route124_ShinyCollectorHouse_AlreadyRewarded
	case MON_DONATION_NEEDS_PARTNER, Route124_ShinyCollectorHouse_NeedsPartner
	case MON_DONATION_HAS_ITEM, Route124_ShinyCollectorHouse_HasItem
	case MON_DONATION_BAG_FULL, Route124_ShinyCollectorHouse_BagFull
	msgbox Route124_ShinyCollectorHouse_Text_Invalid, MSGBOX_DEFAULT
	goto Route124_ShinyCollectorHouse_End

Route124_ShinyCollectorHouse_NeedsPartner:
	msgbox Route124_ShinyCollectorHouse_Text_NeedsPartner, MSGBOX_DEFAULT
	goto Route124_ShinyCollectorHouse_End

Route124_ShinyCollectorHouse_HasItem:
	msgbox Route124_ShinyCollectorHouse_Text_HasItem, MSGBOX_DEFAULT
	goto Route124_ShinyCollectorHouse_End

Route124_ShinyCollectorHouse_BagFull:
	msgbox Route124_ShinyCollectorHouse_Text_BagFull, MSGBOX_DEFAULT
	goto Route124_ShinyCollectorHouse_End

Route124_ShinyCollectorHouse_AlreadyRewarded:
	msgbox Route124_ShinyCollectorHouse_Text_AlreadyRewarded, MSGBOX_DEFAULT

Route124_ShinyCollectorHouse_End:
	release
	end

Route124_ShinyCollectorHouse_Text_Offer:
	.string "Coleciono Pokémon shiny!\p"
	.string "Dou uma Shiny Charm por um.\n"
	.string "Quer escolher um da sua equipe?$"

Route124_ShinyCollectorHouse_Text_Confirm:
	.string "Quer me entregar {STR_VAR_1}\n"
	.string "em troca da Shiny Charm?\p"
	.string "A entrega é definitiva.\n"
	.string "Tem certeza?$"

Route124_ShinyCollectorHouse_Text_Reward:
	.string "Obrigado! Aqui está sua\n"
	.string "Shiny Charm.\p"
	.string "Na Bolsa, ela dobra sua chance\n"
	.string "base de encontrar um shiny!$"

Route124_ShinyCollectorHouse_Text_Invalid:
	.string "Só aceito Pokémon shiny.\n"
	.string "Ovos ficam de fora.$"

Route124_ShinyCollectorHouse_Text_NeedsPartner:
	.string "Outro Pokémon da sua equipe\n"
	.string "precisa estar apto a lutar.$"

Route124_ShinyCollectorHouse_Text_HasItem:
	.string "Tire o item que ele segura\n"
	.string "antes de fazer a troca.$"

Route124_ShinyCollectorHouse_Text_BagFull:
	.string "Sua Bolsa precisa de espaço\n"
	.string "para receber a Shiny Charm.$"

Route124_ShinyCollectorHouse_Text_AlreadyRewarded:
	.string "Você já tem uma Shiny Charm!$"
