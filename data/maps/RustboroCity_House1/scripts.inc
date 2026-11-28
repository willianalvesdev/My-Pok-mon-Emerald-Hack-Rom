RustboroCity_House1_MapScripts::
	.byte 0

RustboroCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_SEEDOT, RustboroCity_House1_Text_IllTradeIfYouWant, RustboroCity_House1_EventScript_DeclineTrade, RustboroCity_House1_EventScript_NotRequestedMon, RustboroCity_House1_Text_PleaseBeGoodToMyPokemon
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	release
	end

RustboroCity_House1_EventScript_DeclineTrade::
	msgbox RustboroCity_House1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox RustboroCity_House1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_TradeCompleted::
	msgbox RustboroCity_House1_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Hiker::
	msgbox RustboroCity_House1_Text_AllSortsOfPlaces, MSGBOX_NPC
	end

RustboroCity_House1_Text_IllTradeIfYouWant:
	.string "Hein? Meu Pokémon é fofo? Claro,\n"
	.string "eu já sabia.\p"
	.string "Mas, se quiser muito, aceito\n"
	.string "trocar.\p"
	.string "Posso dar meu {STR_VAR_2} por\n"
	.string "um {STR_VAR_1}.$"

RustboroCity_House1_Text_PleaseBeGoodToMyPokemon:
	.string "Eheheh... Cuide bem do meu\n"
	.string "Pokémon, por favor.$"

RustboroCity_House1_Text_DoesntLookLikeMonToMe:
	.string "Hein? Isso nao parece um\n"
	.string "{STR_VAR_1}.$"

RustboroCity_House1_Text_YouDontWantToThatsOkay:
	.string "Se nao quiser, tudo bem. Mas meu\n"
	.string "Pokémon é fofo, viu...$"

RustboroCity_House1_Text_AnyPokemonCanBeCute:
	.string "Qualquer Pokémon fica fofo quando\n"
	.string "você cuida dele com carinho.$"

RustboroCity_House1_Text_AllSortsOfPlaces:
	.string "Em todo lugar tem gente e Pokémon\n"
	.string "diferentes.\p"
	.string "Acho isso tao legal que quero\n"
	.string "conhecer todos os cantos.$"

