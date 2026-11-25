	.set GOLDSMITH_NUGGET_PRICE, 10000

Route124_GoldsmithHouse_MapScripts::
	.byte 0

Route124_GoldsmithHouse_EventScript_Goldsmith::
	lock
	faceplayer
	checkitem ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Route124_GoldsmithHouse_NoNugget
	msgbox Route124_GoldsmithHouse_Text_Offer, MSGBOX_YESNO
	goto_if_ne VAR_RESULT, YES, Route124_GoldsmithHouse_End
	checkmoney (MAX_MONEY - GOLDSMITH_NUGGET_PRICE + 1)
	goto_if_eq VAR_RESULT, TRUE, Route124_GoldsmithHouse_WalletFull
	removeitem ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Route124_GoldsmithHouse_NoNugget
	addmoney GOLDSMITH_NUGGET_PRICE
	playse SE_SHOP
	msgbox Route124_GoldsmithHouse_Text_Sold, MSGBOX_DEFAULT
	goto Route124_GoldsmithHouse_End

Route124_GoldsmithHouse_NoNugget:
	msgbox Route124_GoldsmithHouse_Text_NoNugget, MSGBOX_DEFAULT
	goto Route124_GoldsmithHouse_End

Route124_GoldsmithHouse_WalletFull:
	msgbox Route124_GoldsmithHouse_Text_WalletFull, MSGBOX_DEFAULT

Route124_GoldsmithHouse_End:
	release
	end

Route124_GoldsmithHouse_Text_Offer:
	.string "Sou ourives. Pago ¥10000 por\n"
	.string "um Nugget. Quer vender um?$"

Route124_GoldsmithHouse_Text_Sold:
	.string "Aqui vai o seu pagamento.\n"
	.string "Obrigado pelo Nugget!$"

Route124_GoldsmithHouse_Text_NoNugget:
	.string "Compro Nuggets por ¥10000 cada.\n"
	.string "Se achar um, traga pra mim.$"

Route124_GoldsmithHouse_Text_WalletFull:
	.string "Sua carteira está quase cheia.\n"
	.string "Volte quando puder receber tudo.$"
