AbandonedShip_Rooms_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms_1F_EventScript_Gentleman::
	msgbox AbandonedShip_Rooms_1F_Text_TakingALookAround, MSGBOX_NPC
	end

AbandonedShip_Rooms_1F_EventScript_Demetrius::
	trainerbattle_single TRAINER_DEMETRIUS, AbandonedShip_Rooms_1F_Text_DemetriusIntro, AbandonedShip_Rooms_1F_Text_DemetriusDefeat
	msgbox AbandonedShip_Rooms_1F_Text_DemetriusPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_Thalia::
	trainerbattle_single TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaIntro, AbandonedShip_Rooms_1F_Text_ThaliaDefeat, AbandonedShip_Rooms_1F_EventScript_RegisterThalia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms_1F_EventScript_ThaliaRematch
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms_1F_EventScript_RegisterThalia::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_THALIA_1
	release
	end

AbandonedShip_Rooms_1F_EventScript_ThaliaRematch::
	trainerbattle_rematch TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro, AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_Text_TakingALookAround:
	.string "Navios deste tipo sao raros, por\n"
	.string "isso estou vasculhando tudo por\l"
	.string "aqui.\p"
	.string "Parece que há outras cabines...$"

AbandonedShip_Rooms_1F_Text_ThaliaIntro:
	.string "O que você acha que ta fazendo\n"
	.string "aqui? Você é bem enxerido!$"

AbandonedShip_Rooms_1F_Text_ThaliaDefeat:
	.string "Você pode até ser forte, mas\n"
	.string "continua enxerido.$"

AbandonedShip_Rooms_1F_Text_ThaliaPostBattle:
	.string "O homem na porta ao lado...\p"
	.string "Ele diz que está só de passagem,\n"
	.string "mas nao sei se isso é verdade.$"

AbandonedShip_Rooms_1F_Text_ThaliaRegister:
	.string "Você é um treinador muito casca\n"
	.string "grossa! Vou te adicionar no meu\l"
	.string "Discord!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro:
	.string "O que você acha que ta fazendo\n"
	.string "aqui? Você é bem enxerido!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat:
	.string "Você nao apela demais?$"

AbandonedShip_Rooms_1F_Text_ThaliaPostRematch:
	.string "Tenho certeza que aquele viado\n"
	.string "está tramando algo, ele está\l"
	.string "agindo de forma muito sus$"

AbandonedShip_Rooms_1F_Text_DemetriusIntro:
	.string "WAAAAAAH! ME ENCONTRARAM, FUDEU!\n"
	.string "....Huh?$"

AbandonedShip_Rooms_1F_Text_DemetriusDefeat:
	.string "Que susto cara, achei que era\n"
	.string "minha mainha$"

AbandonedShip_Rooms_1F_Text_DemetriusPostBattle:
	.string "Acabei com o cartao de crédito\n"
	.string "dela em robux, por favor nao diga\l"
	.string "onde eu estou$"

