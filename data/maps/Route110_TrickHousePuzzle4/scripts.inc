Route110_TrickHousePuzzle4_MapScripts::
	.byte 0

Route110_TrickHousePuzzle4_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle4_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle4_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle4_EventScript_Cora::
	trainerbattle_single TRAINER_CORA, Route110_TrickHousePuzzle4_Text_CoraIntro, Route110_TrickHousePuzzle4_Text_CoraDefeat
	msgbox Route110_TrickHousePuzzle4_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Yuji::
	trainerbattle_single TRAINER_YUJI, Route110_TrickHousePuzzle4_Text_YujiIntro, Route110_TrickHousePuzzle4_Text_YujiDefeat
	msgbox Route110_TrickHousePuzzle4_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, Route110_TrickHousePuzzle4_Text_PaulaIntro, Route110_TrickHousePuzzle4_Text_PaulaDefeat
	msgbox Route110_TrickHousePuzzle4_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} escreveu o código secreto\n"
	.string "na porta.\p"
	.string "“Trick Master é legal.”\p"
	.string "A fechadura abriu com um clique!$"

Route110_TrickHousePuzzle4_Text_CoraIntro:
	.string "Pensar em tudo isso dá trabalho\n"
	.string "demais. Só queria batalhar!$"

Route110_TrickHousePuzzle4_Text_CoraDefeat:
	.string "Mesmo perdendo, ainda prefiro\n"
	.string "batalhar!$"

Route110_TrickHousePuzzle4_Text_CoraPostBattle:
	.string "Você também é assim? Vai pra\n"
	.string "qualquer canto se tiver treinador\l"
	.string "pra enfrentar.$"

Route110_TrickHousePuzzle4_Text_YujiIntro:
	.string "Heh! Empurro pedras assim com um\n"
	.string "dedo só!$"

Route110_TrickHousePuzzle4_Text_YujiDefeat:
	.string "Consigo empurrar as pedras, mas\n"
	.string "nao resolver o desafio...$"

Route110_TrickHousePuzzle4_Text_YujiPostBattle:
	.string "Nao basta ter força... Tem que\n"
	.string "usar a cabeça também!$"

Route110_TrickHousePuzzle4_Text_PaulaIntro:
	.string "A Trick House ta ficando mais\n"
	.string "complicada, né?$"

Route110_TrickHousePuzzle4_Text_PaulaDefeat:
	.string "Aaah!$"

Route110_TrickHousePuzzle4_Text_PaulaPostBattle:
	.string "Será que alguém chegou até o\n"
	.string "final?$"

