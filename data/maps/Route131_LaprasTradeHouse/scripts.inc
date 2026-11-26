Route131_LaprasTradeHouse_MapScripts::
	.byte 0

Route131_LaprasTradeHouse_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_ROUTE131_LAPRAS_TRADE_COMPLETED, Route131_LaprasTradeHouse_AlreadyTraded
	ingame_trade INGAME_TRADE_LAPRAS, Route131_LaprasTradeHouse_Text_Offer, Route131_LaprasTradeHouse_End, Route131_LaprasTradeHouse_WrongPokemon, Route131_LaprasTradeHouse_Text_Thanks
	setflag FLAG_ROUTE131_LAPRAS_TRADE_COMPLETED
	goto Route131_LaprasTradeHouse_End

Route131_LaprasTradeHouse_WrongPokemon:
	msgbox Route131_LaprasTradeHouse_Text_WrongPokemon, MSGBOX_DEFAULT
	goto Route131_LaprasTradeHouse_End

Route131_LaprasTradeHouse_AlreadyTraded:
	msgbox Route131_LaprasTradeHouse_Text_AlreadyTraded, MSGBOX_DEFAULT

Route131_LaprasTradeHouse_End:
	release
	end

Route131_LaprasTradeHouse_Text_Offer:
	.string "Eu sempre quis um Psyduck!\p"
	.string "Quer trocar um pelo meu Lapras\n"
	.string "de nível 30?$"

Route131_LaprasTradeHouse_Text_WrongPokemon:
	.string "Eu queria um Psyduck!$"

Route131_LaprasTradeHouse_Text_Thanks:
	.string "Valeu pelo Psyduck!\n"
	.string "Cuide bem do Lapras!$"

Route131_LaprasTradeHouse_Text_AlreadyTraded:
	.string "Meu Psyduck adora morar aqui!$"
