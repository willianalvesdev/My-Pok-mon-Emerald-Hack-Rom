MagmaHideout_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

MagmaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_1, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_2, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_Text_Grunt1Intro:
	.string "Na chamada da Team Magma, os\n"
	.string "melhores postos ficam com quem\l"
	.string "chega primeiro.\p"
	.string "Por isso acabei neste canto.\n"
	.string "Sempre chego atrasado!\p"
	.string "Pelo menos aqui ninguém vê que eu\n"
	.string "durmo em pé.$"

MagmaHideout_1F_Text_Grunt1Defeat:
	.string "Também chego atrasado nos treinos!\p"
	.string "É... Sou meio fraco.$"

MagmaHideout_1F_Text_Grunt1PostBattle:
	.string "Ta bom, vou tentar me esforçar\n"
	.string "mais...\p"
	.string "Começo amanha. Hoje já perdi o\n"
	.string "horário.$"

MagmaHideout_1F_Text_Grunt2Intro:
	.string "Nosso líder mandou cavar o Mt.\n"
	.string "Chimney, entao a gente cavou sem\l"
	.string "parar.\p"
	.string "E encontramos uma coisa\n"
	.string "inacreditável!\p"
	.string "Oque foi? Fuhahaha! Só conto se\n"
	.string "você me vencer!$"

MagmaHideout_1F_Text_Grunt2Defeat:
	.string "Argh! Você me derrubou!$"

MagmaHideout_1F_Text_Grunt2PostBattle:
	.string "Mudei de ideia, nao vou contar.\n"
	.string "Você descobre quando chegar lá!\p"
	.string "É melhor deixar a surpresa pro\n"
	.string "final, né?$"

