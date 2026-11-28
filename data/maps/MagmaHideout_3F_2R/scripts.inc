MagmaHideout_3F_2R_MapScripts::
	.byte 0

MagmaHideout_3F_2R_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_2R_Text_Grunt10Intro:
	.string "Eu entendo oque nosso líder fala,\n"
	.string "mas sabe...\p"
	.string "Desenterrar um Pokémon antigo e\n"
	.string "roubar meteorito dos outros...\p"
	.string "Acho que estamos passando do\n"
	.string "ponto. Oque você acha?$"

MagmaHideout_3F_2R_Text_Grunt10Defeat:
	.string "É... Acho que a gente ta fazendo\n"
	.string "alguma coisa errada mesmo.$"

MagmaHideout_3F_2R_Text_Grunt10PostBattle:
	.string "Perder pra você me ajudou a pensar\n"
	.string "melhor.\p"
	.string "Na próxima vez que encontrar o\n"
	.string "líder, vou perguntar sobre oque\l"
	.string "estamos fazendo.$"

