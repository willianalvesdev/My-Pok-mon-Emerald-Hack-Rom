SSTidalLowerDeck_MapScripts::
	.byte 0

SSTidalLowerDeck_EventScript_Phillip::
	trainerbattle_single TRAINER_PHILLIP, SSTidalLowerDeck_Text_PhillipIntro, SSTidalLowerDeck_Text_PhillipDefeat
	msgbox SSTidalLowerDeck_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_EventScript_Leonard::
	trainerbattle_single TRAINER_LEONARD, SSTidalLowerDeck_Text_LeonardIntro, SSTidalLowerDeck_Text_LeonardDefeat
	msgbox SSTidalLowerDeck_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_Text_PhillipIntro:
	.string "Arrrgh! Cansei de limpar esse lugar\n"
	.string "enorme!\p"
	.string "Vamos fazer uma batalha rápida!$"

SSTidalLowerDeck_Text_PhillipDefeat:
	.string "Irmaozinho, perdi!$"

SSTidalLowerDeck_Text_PhillipPostBattle:
	.string "Somos os irmaos da limpeza!\p"
	.string "O mais velho joga o sabao e o mais\n"
	.string "novo esfrega!$"

SSTidalLowerDeck_Text_LeonardIntro:
	.string "Este é o fundo do navio. Tem\n"
	.string "bastante espaço. Dá pra batalhar\l"
	.string "aqui sem problema.$"

SSTidalLowerDeck_Text_LeonardDefeat:
	.string "Irmao, perdi!$"

SSTidalLowerDeck_Text_LeonardPostBattle:
	.string "Somos os irmaos da limpeza!\p"
	.string "O mais velho joga o sabao e o mais\n"
	.string "novo esfrega!$"

