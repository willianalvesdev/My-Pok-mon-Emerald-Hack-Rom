RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "Esse olhar decidido... Seu jeito de\n"
	.string "se mover... Seus Pokémon bem\l"
	.string "treinados...\p"
	.string "Você é um treinador habilidoso!\p"
	.string "Nao precisa falar, dá pra ver!\n"
	.string "Tenho certeza que vai usar bem\l"
	.string "esta HM.\p"
	.string "Nao precisa ter vergonha. Pode\n"
	.string "pegar!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "Esta HM tem Cut.\p"
	.string "Golpes de HM também podem ser\n"
	.string "usados fora das batalhas.\p"
	.string "Com a Stone Badge, um Pokémon que\n"
	.string "sabe Cut pode cortar árvores\l"
	.string "finas.\p"
	.string "E, diferente das TMs, uma HM pode\n"
	.string "ser usada várias vezes.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "Quando Rustboro tava crescendo,\n"
	.string "meu pai ajudou a cidade.\p"
	.string "Ele usava Cut com seus Pokémon\n"
	.string "pra tirar as árvores do caminho.$"

