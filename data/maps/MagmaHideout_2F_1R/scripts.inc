MagmaHideout_2F_1R_MapScripts::
	.byte 0

MagmaHideout_2F_1R_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_14, MagmaHideout_2F_1R_Text_Grunt14Intro, MagmaHideout_2F_1R_Text_Grunt14Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt14PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_3, MagmaHideout_2F_1R_Text_Grunt3Intro, MagmaHideout_2F_1R_Text_Grunt3Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_4, MagmaHideout_2F_1R_Text_Grunt4Intro, MagmaHideout_2F_1R_Text_Grunt4Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_5, MagmaHideout_2F_1R_Text_Grunt5Intro, MagmaHideout_2F_1R_Text_Grunt5Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_Text_Grunt14Intro:
	.string "Oque?! Só pode entrar gente da\n"
	.string "Team Magma aqui!\p"
	.string "Você nao ta de uniforme...\p"
	.string "Muito suspeito! Vamos batalhar!$"

MagmaHideout_2F_1R_Text_Grunt14Defeat:
	.string "Ai, ai... Meu orgulho de membro da\n"
	.string "Team Magma...$"

MagmaHideout_2F_1R_Text_Grunt14PostBattle:
	.string "Se você sente muito frio, entra\n"
	.string "pra Team Magma.\p"
	.string "O calor daqui vem incluso. O\n"
	.string "desodorante, nao.$"

MagmaHideout_2F_1R_Text_Grunt3Intro:
	.string "Parou aí!\p"
	.string "Achou mesmo que eu ia ficar quieto\n"
	.string "e deixar você passar?$"

MagmaHideout_2F_1R_Text_Grunt3Defeat:
	.string "Nossa! Ta bom, eu desisto!$"

MagmaHideout_2F_1R_Text_Grunt3PostBattle:
	.string "Era melhor ter deixado você passar\n"
	.string "mesmo...$"

MagmaHideout_2F_1R_Text_Grunt4Intro:
	.string "Ahá! Um invasor!$"

MagmaHideout_2F_1R_Text_Grunt4Defeat:
	.string "Graaaah!$"

MagmaHideout_2F_1R_Text_Grunt4PostBattle:
	.string "Já perdi.\p"
	.string "Preciso continuar dando volta ou\n"
	.string "já posso sentar?$"

MagmaHideout_2F_1R_Text_Grunt5Intro:
	.string "Ei, ei! Um invasor!$"

MagmaHideout_2F_1R_Text_Grunt5Defeat:
	.string "Resmungo...$"

MagmaHideout_2F_1R_Text_Grunt5PostBattle:
	.string "Na verdade, nao sou muito bom em\n"
	.string "batalhas...$"

