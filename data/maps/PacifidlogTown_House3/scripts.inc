PacifidlogTown_House3_MapScripts::
	.byte 0

PacifidlogTown_House3_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_HORSEA, PacifidlogTown_House3_Text_WillingToTradeIt, PacifidlogTown_House3_EventScript_DeclineTrade, PacifidlogTown_House3_EventScript_NotRequestedMon, PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
	release
	end

PacifidlogTown_House3_EventScript_DeclineTrade::
	msgbox PacifidlogTown_House3_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_TradeCompleted::
	msgbox PacifidlogTown_House3_Text_ReallyWantedToGetBagon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_Girl::
	msgbox PacifidlogTown_House3_Text_IsThatAPokedex, MSGBOX_NPC
	end

PacifidlogTown_House3_Text_WillingToTradeIt:
	.string "Olha este {STR_VAR_2}!\p"
	.string "Capturei esse {STR_VAR_2}\n"
	.string "ontem pra comemorar meu\l"
	.string "aniversário!\p"
	.string "Já vi que você gostou. É uma\n"
	.string "preciosidade!\p"
	.string "Talvez eu aceite trocar por um\n"
	.string "{STR_VAR_1}.$"

PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou:
	.string "Ah, entao este é um\n"
	.string "{STR_VAR_1}?\p"
	.string "Parece um pouco com\n"
	.string "{STR_VAR_2}, mas tem suas\l"
	.string "diferenças.\p"
	.string "Obrigado!$"

PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon:
	.string "Nao, nao! Só aceito um\n"
	.string "{STR_VAR_1} de verdade!$"

PacifidlogTown_House3_Text_NotDesperateOrAnything:
	.string "Ah, nao vai querer?\p"
	.string "Tudo bem. Nao tô desesperado pra\n"
	.string "trocar nem nada...$"

PacifidlogTown_House3_Text_ReallyWantedToGetBagon:
	.string "Eu podia procurar por conta\n"
	.string "própria, mas...\p"
	.string "Queria mesmo um Bagon capturado\n"
	.string "por outro treinador...$"

PacifidlogTown_House3_Text_IsThatAPokedex:
	.string "Isso é uma Pokédex?\p"
	.string "Já conheceu vários Pokémon\n"
	.string "diferentes?\p"
	.string "Queria ser igual a você.$"

