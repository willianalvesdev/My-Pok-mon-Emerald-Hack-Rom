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
	.string "Coleciono Pokémon shiny! Dou uma\n"
	.string "Shiny Charm em troca de um. Quer\l"
	.string "escolher um do seu time?$"

Route124_ShinyCollectorHouse_Text_Confirm:
	.string "Quer me entregar {STR_VAR_1}\n"
	.string "em troca da Shiny Charm? Você nao\l"
	.string "vai poder pegar ele de volta. Tem\l"
	.string "certeza?$"

Route124_ShinyCollectorHouse_Text_Reward:
	.string "Valeu! Aqui ta sua Shiny Charm.\n"
	.string "Deixa ela na bolsa que sua chance\l"
	.string "base de encontrar shiny dobra!$"

Route124_ShinyCollectorHouse_Text_Invalid:
	.string "Só aceito Pokémon shiny. Ovo nao\n"
	.string "vale.$"

Route124_ShinyCollectorHouse_Text_NeedsPartner:
	.string "Você precisa deixar outro Pokémon\n"
	.string "que possa batalhar no time.$"

Route124_ShinyCollectorHouse_Text_HasItem:
	.string "Tira o item que ele segura antes\n"
	.string "de fazer a troca.$"

Route124_ShinyCollectorHouse_Text_BagFull:
	.string "Libera espaço na bolsa pra receber\n"
	.string "a Shiny Charm.$"

Route124_ShinyCollectorHouse_Text_AlreadyRewarded:
	.string "Você já tem uma Shiny Charm!$"
