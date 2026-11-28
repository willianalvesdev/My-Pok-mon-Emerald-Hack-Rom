BattleFrontier_Lounge6_MapScripts::
	.byte 0

BattleFrontier_Lounge6_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_MEOWTH, BattleFrontier_Lounge6_Text_WouldYouLikeToTrade, BattleFrontier_Lounge6_EventScript_DeclineTrade, BattleFrontier_Lounge6_EventScript_NotRequestedMon, BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_DeclineTrade::
	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_TradeCompleted::
	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_WouldYouLikeToTrade:
	.string "Meu Pokémon é um {STR_VAR_2}.\n"
	.string "Você conhece? Ele é fofo e muito\l"
	.string "legal.\p"
	.string "É um Pokémon que eu teria orgulho\n"
	.string "de oferecer numa troca!\p"
	.string "Quer trocar um {STR_VAR_1} pelo\n"
	.string "meu {STR_VAR_2}?$"

BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt:
	.string "Ah, que gracinha! Obrigada!\n"
	.string "Prometo cuidar bem dele!\p"
	.string "Ah! Espero que cuide bem do meu\n"
	.string "{STR_VAR_2} também!$"

BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon:
	.string "Ah, desculpe! Só quero trocar por\n"
	.string "um {STR_VAR_1}.$"

BattleFrontier_Lounge6_Text_WellThatsFineToo:
	.string "Ah, nao quer? Tudo bem. Volte para\n"
	.string "nos visitar.$"

BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined:
	.string "Hehe! SKITTY é ainda mais fofo do\n"
	.string "que eu imaginava. Estou muito\l"
	.string "feliz!$"
