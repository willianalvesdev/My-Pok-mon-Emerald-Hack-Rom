FortreeCity_House1_MapScripts::
	.byte 0

FortreeCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_PLUSLE, FortreeCity_House1_Text_YouWillTradeWontYou, FortreeCity_House1_EventScript_DeclineTrade, FortreeCity_House1_EventScript_NotRequestedMon, FortreeCity_House1_Text_MonYouTakeCare
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
	release
	end

FortreeCity_House1_EventScript_DeclineTrade::
	msgbox FortreeCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_TradeCompleted::
	msgbox FortreeCity_House1_Text_GoingToMakeVolbeatStrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_ExpertF::
	msgbox FortreeCity_House1_Text_TradingMemoriesWithOthers, MSGBOX_NPC
	end

FortreeCity_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House1_Text_YouWillTradeWontYou:
	.string "Aaaaah! Preciso de um\n"
	.string "{STR_VAR_1}! Faço qualquer\l"
	.string "coisa pra conseguir!\p"
	.string "...É... Você ouviu? Foi um grito\n"
	.string "que veio do coraçao.\p"
	.string "Depois disso, vai trocar seu\n"
	.string "{STR_VAR_1} pelo meu\l"
	.string "{STR_VAR_2}, né?$"

FortreeCity_House1_Text_MonYouTakeCare:
	.string "Isso! Boa!\p"
	.string "Seja bem-vindo, {STR_VAR_1}!\n"
	.string "Se cuida, {STR_VAR_2}!$"

FortreeCity_House1_Text_ThisIsntAMon:
	.string "É, nao. Isso aí nao é um\n"
	.string "{STR_VAR_1}.$"

FortreeCity_House1_Text_YouWontTradeMe:
	.string "Nao? Nao vai trocar? Mesmo depois\n"
	.string "de eu abrir meu coraçao?$"

FortreeCity_House1_Text_GoingToMakeVolbeatStrong:
	.string "Vou deixar VOLBEAT muito forte\n"
	.string "daqui pra frente!\p"
	.string "Espero que faça o mesmo com\n"
	.string "PLUSLE!$"

FortreeCity_House1_Text_TradingMemoriesWithOthers:
	.string "Trocar POKÉMONS com outras\n"
	.string "pessoas...\p"
	.string "É quase como trocar lembranças com\n"
	.string "elas.$"

FortreeCity_House1_Text_Zigzagoon:
	.string "ZIGZAGOON: Gumomoh?$"

