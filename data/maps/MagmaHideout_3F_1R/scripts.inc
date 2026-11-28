MagmaHideout_3F_1R_MapScripts::
	.byte 0

MagmaHideout_3F_1R_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_Grunt9Intro:
	.string "Oque eu fiz pra merecer ficar de\n"
	.string "guarda aqui?\p"
	.string "Minha orelha esquerda ta pegando\n"
	.string "fogo!$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:
	.string "Tô passando mal de calor...$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle:
	.string "Você nao acha estranho a gente\n"
	.string "usar capuz dentro de um vulcao\l"
	.string "cheio de magma?\p"
	.string "O uniforme foi aprovado no inverno,\n"
	.string "só pode.$"

MagmaHideout_3F_1R_Text_Grunt16Intro:
	.string "Entramos pra ajudar nosso líder a\n"
	.string "realizar seu grande plano.\p"
	.string "Nao importa se você é da Team\n"
	.string "Aqua ou só uma criança de\l"
	.string "passagem.\p"
	.string "Ninguém atrapalha a gente e sai\n"
	.string "sem pagar!$"

MagmaHideout_3F_1R_Text_Grunt16Defeat:
	.string "Ah, nao! Nao dá pra confiar em\n"
	.string "você!$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle:
	.string "Escuta aqui. A Team Magma ta\n"
	.string "certa!\p"
	.string "Nao acredita nas mentiras da Team\n"
	.string "Aqua!$"

