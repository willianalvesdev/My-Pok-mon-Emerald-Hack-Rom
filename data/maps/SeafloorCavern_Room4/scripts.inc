SeafloorCavern_Room4_MapScripts::
	.byte 0

SeafloorCavern_Room4_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_3, SeafloorCavern_Room4_Text_Grunt3Intro, SeafloorCavern_Room4_Text_Grunt3Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_4, SeafloorCavern_Room4_Text_Grunt4Intro, SeafloorCavern_Room4_Text_Grunt4Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_Text_Grunt3Intro:
	.string "Quem é você? Entrou por onde?$"

SeafloorCavern_Room4_Text_Grunt3Defeat:
	.string "Perdi...$"

SeafloorCavern_Room4_Text_Grunt3PostBattle:
	.string "Nao encontro a saída!\p"
	.string "Nao é medo, ta? Só nao quero\n"
	.string "morrer aqui.$"

SeafloorCavern_Room4_Text_Grunt4Intro:
	.string "Quem é você? Acha que vai pra\n"
	.string "onde?$"

SeafloorCavern_Room4_Text_Grunt4Defeat:
	.string "Nao consegui vencer!$"

SeafloorCavern_Room4_Text_Grunt4PostBattle:
	.string "Meu parceiro esqueceu o mapa no\n"
	.string "submarino!\p"
	.string "Dá pra ser mais inútil?$"

