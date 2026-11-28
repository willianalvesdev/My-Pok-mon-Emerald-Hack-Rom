VictoryRoad_B2F_MapScripts::
	.byte 0

VictoryRoad_B2F_EventScript_Vito::
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline::
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie::
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix::
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Dianne::
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_Text_VitoIntro:
	.string "Treinei com minha família inteira!\n"
	.string "Nao vou perder pra ninguém!$"

VictoryRoad_B2F_Text_VitoDefeat:
	.string "Melhor que minha família?! Como é\n"
	.string "possível?!$"

VictoryRoad_B2F_Text_VitoPostBattle:
	.string "Eu era o mais forte da família.\n"
	.string "Nunca tinha perdido...\p"
	.string "Perdi minha confiança... Talvez eu\n"
	.string "volte pra casa...$"

VictoryRoad_B2F_Text_OwenIntro:
	.string "Ouvi falar de uma criança bem\n"
	.string "forte por aqui. É você?$"

VictoryRoad_B2F_Text_OwenDefeat:
	.string "Esse baixinho é forte!$"

VictoryRoad_B2F_Text_OwenPostBattle:
	.string "Disseram que essa criança forte\n"
	.string "vem de Petalburg City.$"

VictoryRoad_B2F_Text_CarolineIntro:
	.string "Você já deve estar ficando\n"
	.string "cansado.$"

VictoryRoad_B2F_Text_CarolineDefeat:
	.string "Nenhum sinal de cansaço!$"

VictoryRoad_B2F_Text_CarolinePostBattle:
	.string "Victory Road e Liga Pokémon sao\n"
	.string "desafios longos e difíceis. Cuidado\l"
	.string "com o cansaço!$"

VictoryRoad_B2F_Text_JulieIntro:
	.string "Nao fique se achando só porque\n"
	.string "tem várias insígnias.\p"
	.string "Sempre vai ter alguém melhor que\n"
	.string "você!$"

VictoryRoad_B2F_Text_JulieDefeat:
	.string "Você é melhor que eu!$"

VictoryRoad_B2F_Text_JuliePostBattle:
	.string "Olhe suas insígnias e lembre dos\n"
	.string "treinadores que enfrentou.$"

VictoryRoad_B2F_Text_FelixIntro:
	.string "Cheguei até aqui, mas o nervoso ta\n"
	.string "dando uma dor de barriga\l"
	.string "terrível...$"

VictoryRoad_B2F_Text_FelixDefeat:
	.string "Ah... Ta doendo...$"

VictoryRoad_B2F_Text_FelixPostBattle:
	.string "Nao consigo evitar o nervoso de\n"
	.string "estar tao perto da Liga Pokémon.\p"
	.string "Finjo tranquilidade, mas minha\n"
	.string "barriga nao colabora.$"

VictoryRoad_B2F_Text_DianneIntro:
	.string "Os melhores dos melhores se reúnem\n"
	.string "nesta caverna.\p"
	.string "Oque ta achando?$"

VictoryRoad_B2F_Text_DianneDefeat:
	.string "Nem se abalou!$"

VictoryRoad_B2F_Text_DiannePostBattle:
	.string "Você tem coragem! Gostei! Continue\n"
	.string "assim!$"

