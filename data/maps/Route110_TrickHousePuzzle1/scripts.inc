Route110_TrickHousePuzzle1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_OnLoad
	.byte 0

Route110_TrickHousePuzzle1_OnLoad:
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2, Route110_TrickHousePuzzle1_EventScript_OpenDoor
	end

Route110_TrickHousePuzzle1_EventScript_OpenDoor::
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	end

Route110_TrickHousePuzzle1_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle1_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle1_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle1_EventScript_Sally::
	trainerbattle_single TRAINER_SALLY, Route110_TrickHousePuzzle1_Text_SallyIntro, Route110_TrickHousePuzzle1_Text_SallyDefeat
	msgbox Route110_TrickHousePuzzle1_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Eddie::
	trainerbattle_single TRAINER_EDDIE, Route110_TrickHousePuzzle1_Text_EddieIntro, Route110_TrickHousePuzzle1_Text_EddieDefeat
	msgbox Route110_TrickHousePuzzle1_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Robin::
	trainerbattle_single TRAINER_ROBIN, Route110_TrickHousePuzzle1_Text_RobinIntro, Route110_TrickHousePuzzle1_Text_RobinDefeat
	msgbox Route110_TrickHousePuzzle1_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} escreveu o código secreto\n"
	.string "na porta.\p"
	.string "“Trick Master é incrível.”\p"
	.string "A fechadura abriu com um clique!$"

Route110_TrickHousePuzzle1_Text_SallyIntro:
	.string "Vou abrir caminho até a vitória com\n"
	.string "o Cut que acabamos de aprender!$"

Route110_TrickHousePuzzle1_Text_SallyDefeat:
	.string "Por que leva isso tao a sério?$"

Route110_TrickHousePuzzle1_Text_SallyPostBattle:
	.string "Nunca me canso de cortar tudo\n"
	.string "pelo caminho!$"

Route110_TrickHousePuzzle1_Text_EddieIntro:
	.string "Entrei nesta casa estranha sem\n"
	.string "querer...$"

Route110_TrickHousePuzzle1_Text_EddieDefeat:
	.string "E agora ainda perdi...$"

Route110_TrickHousePuzzle1_Text_EddiePostBattle:
	.string "Perdi o caminho, perdi a batalha e\n"
	.string "agora tô mais perdido ainda... Nao\l"
	.string "consigo sair...$"

Route110_TrickHousePuzzle1_Text_RobinIntro:
	.string "Quem é esse tal de Trick Master?$"

Route110_TrickHousePuzzle1_Text_RobinDefeat:
	.string "Fiquei pensando e perdi a batalha!$"

Route110_TrickHousePuzzle1_Text_RobinPostBattle:
	.string "Você é forte! Quem é você?$"

