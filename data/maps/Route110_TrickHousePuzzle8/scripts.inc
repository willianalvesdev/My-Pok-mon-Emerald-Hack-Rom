Route110_TrickHousePuzzle8_MapScripts::
	.byte 0

Route110_TrickHousePuzzle8_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0, Route110_TrickHousePuzzle8_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle8_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle8_EventScript_Vincent::
	trainerbattle_single TRAINER_VINCENT, Route110_TrickHousePuzzle8_Text_VincentIntro, Route110_TrickHousePuzzle8_Text_VincentDefeat
	msgbox Route110_TrickHousePuzzle8_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Keira::
	trainerbattle_single TRAINER_KEIRA, Route110_TrickHousePuzzle8_Text_KeiraIntro, Route110_TrickHousePuzzle8_Text_KeiraDefeat
	msgbox Route110_TrickHousePuzzle8_Text_KeiraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Leroy::
	trainerbattle_single TRAINER_LEROY, Route110_TrickHousePuzzle8_Text_LeroyIntro, Route110_TrickHousePuzzle8_Text_LeroyDefeat
	msgbox Route110_TrickHousePuzzle8_Text_LeroyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} escreveu o código secreto\n"
	.string "na porta.\p"
	.string "“Eu amo Trick Master.”\p"
	.string "A fechadura abriu com um clique!$"

Route110_TrickHousePuzzle8_Text_VincentIntro:
	.string "Poucos treinadores chegaram tao\n"
	.string "longe.$"

Route110_TrickHousePuzzle8_Text_VincentDefeat:
	.string "Isso quer dizer que você também é\n"
	.string "forte...$"

Route110_TrickHousePuzzle8_Text_VincentPostBattle:
	.string "Você venceu o campeao da Liga\n"
	.string "Pokémon? Aí é demais!$"

Route110_TrickHousePuzzle8_Text_KeiraIntro:
	.string "Considere uma sorte poder batalhar\n"
	.string "comigo!$"

Route110_TrickHousePuzzle8_Text_KeiraDefeat:
	.string "Isso ta errado! Eu nao posso\n"
	.string "perder!$"

Route110_TrickHousePuzzle8_Text_KeiraPostBattle:
	.string "Você me vencer foi um milagre.\n"
	.string "Pode sair contando vantagem.$"

Route110_TrickHousePuzzle8_Text_LeroyIntro:
	.string "Você também ta se esforçando pra\n"
	.string "passar pelos desafios da Trick\l"
	.string "House.$"

Route110_TrickHousePuzzle8_Text_LeroyDefeat:
	.string "Entendi... Seu jeito de batalhar é\n"
	.string "fora do comum.$"

Route110_TrickHousePuzzle8_Text_LeroyPostBattle:
	.string "Trick Master deve ficar feliz de\n"
	.string "conhecer alguém como você.$"

