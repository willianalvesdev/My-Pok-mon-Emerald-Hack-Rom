Route110_TrickHousePuzzle6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle6_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHousePuzzle6_OnWarp
	.byte 0

Route110_TrickHousePuzzle6_OnTransition:
	special RotatingGate_InitPuzzle
	end

Route110_TrickHousePuzzle6_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, Route110_TrickHousePuzzle6_EventScript_InitPuzzle
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_5
Route110_TrickHousePuzzle6_EventScript_InitPuzzle::
	special RotatingGate_InitPuzzleAndGraphics
	end

Route110_TrickHousePuzzle6_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0, Route110_TrickHousePuzzle6_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle6_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle6_EventScript_Sophia::
	trainerbattle_single TRAINER_SOPHIA, Route110_TrickHousePuzzle6_Text_SophiaIntro, Route110_TrickHousePuzzle6_Text_SophiaDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SophiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Benny::
	trainerbattle_single TRAINER_BENNY, Route110_TrickHousePuzzle6_Text_BennyIntro, Route110_TrickHousePuzzle6_Text_BennyDefeat
	msgbox Route110_TrickHousePuzzle6_Text_BennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Sebastian::
	trainerbattle_single TRAINER_SEBASTIAN, Route110_TrickHousePuzzle6_Text_SebastianIntro, Route110_TrickHousePuzzle6_Text_SebastianDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} escreveu o código secreto\n"
	.string "na porta.\p"
	.string "“Trick Master é minha vida.”\p"
	.string "A fechadura abriu com um clique!$"

Route110_TrickHousePuzzle6_Text_SophiaIntro:
	.string "Ouvi falar desta casa estranha e\n"
	.string "precisei vir conhecer.$"

Route110_TrickHousePuzzle6_Text_SophiaDefeat:
	.string "Encontrei um treinador forte!$"

Route110_TrickHousePuzzle6_Text_SophiaPostBattle:
	.string "Tô me divertindo conhecendo este\n"
	.string "lugar.\p"
	.string "É um desafio que vale a pena\n"
	.string "repetir!$"

Route110_TrickHousePuzzle6_Text_BennyIntro:
	.string "Talvez meu Pokémon pássaro consiga\n"
	.string "voar por cima da parede...$"

Route110_TrickHousePuzzle6_Text_BennyDefeat:
	.string "Guaaah! Nao deu certo!$"

Route110_TrickHousePuzzle6_Text_BennyPostBattle:
	.string "Ehehehe... Acho que perdi porque\n"
	.string "tava tentando trapacear.$"

Route110_TrickHousePuzzle6_Text_SebastianIntro:
	.string "Essas portas giratórias tao me\n"
	.string "deixando tonto...$"

Route110_TrickHousePuzzle6_Text_SebastianDefeat:
	.string "Ta tudo rodando sem parar. Nao\n"
	.string "aguento mais...$"

Route110_TrickHousePuzzle6_Text_SebastianPostBattle:
	.string "Você parece bem. Ou só ta\n"
	.string "disfarçando?$"

