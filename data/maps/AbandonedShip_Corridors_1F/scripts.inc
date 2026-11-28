AbandonedShip_Corridors_1F_MapScripts::
	.byte 0

AbandonedShip_Corridors_1F_EventScript_Youngster::
	msgbox AbandonedShip_Corridors_1F_Text_IsntItFunHere, MSGBOX_NPC
	end

AbandonedShip_Corridors_1F_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_CharlieIntro, AbandonedShip_Corridors_1F_Text_CharlieDefeat
	msgbox AbandonedShip_Corridors_1F_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_1F_Text_CharlieIntro:
	.string "Qual o problema de trazer minha\n"
	.string "boia pro navio?$"

AbandonedShip_Corridors_1F_Text_CharlieDefeat:
	.string "Eita, você me moggou$"

AbandonedShip_Corridors_1F_Text_CharliePostBattle:
	.string "Nao é nem um pouco facil jogar\n"
	.string "POKé BALLS enquanto se está\l"
	.string "segurando em uma boia!$"

AbandonedShip_Corridors_1F_Text_IsntItFunHere:
	.string "É muito divertido aqui nao é? Adoro\n"
	.string "esse lugar$"
