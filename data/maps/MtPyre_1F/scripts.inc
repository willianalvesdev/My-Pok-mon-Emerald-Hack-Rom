MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "Todo tipo de ser anda pelas\n"
	.string "encostas do Mt. Pyre...\p"
	.string "Nao dá pra saber oque pode\n"
	.string "acontecer. Leve isto, é pro seu\l"
	.string "bem.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "Deixe um Pokémon segurar essa\n"
	.string "Cleanse Tag.\p"
	.string "Ela ajuda a afastar Pokémon\n"
	.string "selvagens.$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "Veio prestar respeito aos Pokémon\n"
	.string "que já se foram?\p"
	.string "Você deve gostar muito dos seus\n"
	.string "Pokémon.$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "Meu Zigzagoon descansa aqui. Eu\n"
	.string "gostava tanto dele...$"

