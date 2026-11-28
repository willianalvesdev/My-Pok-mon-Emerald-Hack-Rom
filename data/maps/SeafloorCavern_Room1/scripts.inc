SeafloorCavern_Room1_MapScripts::
	.byte 0

SeafloorCavern_Room1_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_1, SeafloorCavern_Room1_Text_Grunt1Intro, SeafloorCavern_Room1_Text_Grunt1Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_2, SeafloorCavern_Room1_Text_Grunt2Intro, SeafloorCavern_Room1_Text_Grunt2Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_Text_Grunt1Intro:
	.string "Nao precisamos de criança aqui! Vai\n"
	.string "pra casa!$"

SeafloorCavern_Room1_Text_Grunt1Defeat:
	.string "Eu que quero ir pra casa...$"

SeafloorCavern_Room1_Text_Grunt1PostBattle:
	.string "Quero ser promovido pra poder\n"
	.string "mandar nos capangas...\p"
	.string "Começo mandando um deles me\n"
	.string "buscar aqui.$"

SeafloorCavern_Room1_Text_Grunt2Intro:
	.string "Aquele submarino é minúsculo por\n"
	.string "dentro. Tô todo dolorido!$"

SeafloorCavern_Room1_Text_Grunt2Defeat:
	.string "Perder dói ainda mais!$"

SeafloorCavern_Room1_Text_Grunt2PostBattle:
	.string "O submarino que roubamos é\n"
	.string "apertado demais. Foi terrível\l"
	.string "viajar nele!\p"
	.string "Pedia reembolso, mas o ingresso\n"
	.string "também foi roubado.$"

