AbandonedShip_Rooms2_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani::
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison::
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro:
	.string "DAN: Enquanto procurávamos\n"
	.string "tesouros, achamos um Treinador!$"

AbandonedShip_Rooms2_1F_Text_DanDefeat:
	.string "DAN: Nao conseguíamos ganhar,\n"
	.string "mesmo tendo trabalho juntos...$"

AbandonedShip_Rooms2_1F_Text_DanPostBattle:
	.string "DAN: Nao conseguimos encontrar\n"
	.string "nenhum tesouro... será que alguém\l"
	.string "já os achou?$"

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons:
	.string "DAN: Você nao tem nem dois\n"
	.string "POKÉMONS, como você acha que\l"
	.string "venceria a gente?$"

AbandonedShip_Rooms2_1F_Text_KiraIntro:
	.string "KIRA: AHA, Estavamos procurando\n"
	.string "tesouros. Mas em vez disso achamos\l"
	.string "um TREINADOR!$"

AbandonedShip_Rooms2_1F_Text_KiraDefeat:
	.string "KIRA: Caramba tao forte!$"

AbandonedShip_Rooms2_1F_Text_KiraPostBattle:
	.string "KIRA: Onde podem estar esses\n"
	.string "tesouros?\p"
	.string "Já ate decidi o que vou comprar\n"
	.string "quando encontrarmos!$"

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons:
	.string "KIRA: Você nem sequer tem dois\n"
	.string "POKÉMONS, como você acha que\l"
	.string "poderia vencer a gente?$"

AbandonedShip_Rooms2_1F_Text_KiraRegister:
	.string "KIRA: AH, você me irrita tanto!\n"
	.string "vou registrar você por causa\l"
	.string "disso!$"

AbandonedShip_Rooms2_1F_Text_DanRematchIntro:
	.string "DAN: Estivemos procurando tesouros\n"
	.string "este tempo todo.\p"
	.string "Os nossos POKéMONS também se\n"
	.string "tornaram mais fortes. Vamos te\l"
	.string "mostrar!$"

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat:
	.string "DAN: Você está muito forte, como\n"
	.string "sempre!$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch:
	.string "DAN: Nao encontramos nenhum\n"
	.string "tesouro, ainda perdemos a\l"
	.string "batalha...\p"
	.string "Quero ir para casa, mas se eu\n"
	.string "disser isso, ela fica vai ficar\l"
	.string "furiosa comigo.$"

AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons:
	.string "DAN: Você nao tem nem dois\n"
	.string "POKÉMONS, como você acha que\l"
	.string "venceria a gente?$"

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro:
	.string "KIRA: Oh! Nos estrosamos denovo\p"
	.string "Parece que você ainda nao desistiu\n"
	.string "de procurar os tesouros nao é\l"
	.string "mesmo?\p"
	.string "Que tal uma luta? o perdedor\n"
	.string "betinha desiste de procurar o\l"
	.string "tesouro$"

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat:
	.string "KIRA: Fomos molestados\n"
	.string "novamente...$"

AbandonedShip_Rooms2_1F_Text_KiraPostRematch:
	.string "KIRA: Nao vamos embora até\n"
	.string "uparmos os nossos POKéMONS e\l"
	.string "encontrarmos os tesouros!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons:
	.string "KIRA: Você nem sequer tem dois\n"
	.string "POKÉMONS, como você acha que\l"
	.string "poderia vencer a gente?$"

AbandonedShip_Rooms2_1F_Text_JaniIntro:
	.string "Nadar eu posso até nao saber, mas\n"
	.string "pra x1 eu sou fera!$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat:
	.string "Eu só perdi porque fui programado\n"
	.string "pra isso fdp$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle:
	.string "Andar descalço nesse navio é\n"
	.string "nojento, parece que alguém cagou\l"
	.string "no chao$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro:
	.string "Força e bondade... sao as\n"
	.string "caracteristicas de um verdadeiro\l"
	.string "TREINADOR!$"

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat:
	.string "Algo me diz que você é o alto\n"
	.string "nivel dos mitos antigos.... O\l"
	.string "ESCOLHIDO!$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle:
	.string "Em alguma cabine do navio vi algo\n"
	.string "brilhando.$"
