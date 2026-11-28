BattleFrontier_Lounge4_MapScripts::
	.byte 0

BattleFrontier_Lounge4_EventScript_Woman::
	msgbox BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Cook::
	msgbox BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Man::
	msgbox BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles, MSGBOX_NPC
	end

BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring:
	.string "Será que vao mostrar entrevistas\n"
	.string "com treinadores fortes hoje?$"

BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere:
	.string "Se eu abrisse um restaurante aqui,\n"
	.string "ia ganhar dinheiro com certeza.$"

BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles:
	.string "Ufa...\p"
	.string "Preciso respirar um pouco depois\n"
	.string "dessas batalhas intensas...\p"
	.string "Mas, mesmo agora, nao paro de\n"
	.string "pensar em estratégias e\l"
	.string "combinaçoes.$"

