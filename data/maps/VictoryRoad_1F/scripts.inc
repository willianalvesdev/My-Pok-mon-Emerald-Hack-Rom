VictoryRoad_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
	.byte 0

VictoryRoad_1F_OnTransition:
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 1, VictoryRoad_1F_EventScript_SetEntranceWallyPos1
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 2, VictoryRoad_1F_EventScript_SetEntranceWallyPos2
	end

VictoryRoad_1F_EventScript_SetEntranceWallyPos1::
	setobjectxyperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, 2, 24
	setobjectmovementtype LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_SetEntranceWallyPos2::
	setobjectxyperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, 3, 24
	setobjectmovementtype LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_WallyBattleTrigger1::
	lockall
	setvar VAR_0x8008, 1
	addobject LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	applymovement LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, VictoryRoad_1F_Movement_WallyApproachPlayer1
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyBattleTrigger2::
	lockall
	setvar VAR_0x8008, 2
	addobject LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	applymovement LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, VictoryRoad_1F_Movement_WallyApproachPlayer2
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyEntranceBattle::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_VR_1, VictoryRoad_1F_Text_WallyEntranceDefeat
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	copyobjectxytoperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
	copyvar VAR_VICTORY_ROAD_1F_STATE, VAR_0x8008
	releaseall
	end

VictoryRoad_1F_Movement_WallyApproachPlayer1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

VictoryRoad_1F_Movement_WallyApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

@ This Wally appears near the entrance once his battle is triggered and remains there until the Hall of Fame is entered
VictoryRoad_1F_EventScript_EntranceWally::
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_NPC
	end

@ This Wally appears and remains at the exit after the Hall of Fame is entered
VictoryRoad_1F_EventScript_ExitWally::
	trainerbattle_single TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, VictoryRoad_1F_EventScript_RematchWally
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_RematchWally::
	trainerbattle_rematch TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_EdgarIntro, VictoryRoad_1F_Text_EdgarDefeat
	msgbox VictoryRoad_1F_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Albert::
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_AlbertIntro, VictoryRoad_1F_Text_AlbertDefeat
	msgbox VictoryRoad_1F_Text_AlbertPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_HopeIntro, VictoryRoad_1F_Text_HopeDefeat
	msgbox VictoryRoad_1F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Quincy::
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_QuincyIntro, VictoryRoad_1F_Text_QuincyDefeat
	msgbox VictoryRoad_1F_Text_QuincyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Katelynn::
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_KatelynnIntro, VictoryRoad_1F_Text_KatelynnDefeat
	msgbox VictoryRoad_1F_Text_KatelynnPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore:
	.string "WALLY: Oi, {PLAYER}!\p"
	.string "Aposto que nao esperava me ver\n"
	.string "aqui!\p"
	.string "Cheguei até aqui graças a você.\n"
	.string "Perder aquela batalha me fez ficar\l"
	.string "mais forte, {PLAYER}!\p"
	.string "Mas nao vou perder de novo!\p"
	.string "Vou vencer pelos Pokémon que me\n"
	.string "deram coragem e força!\p"
	.string "Ta bom... Lá vou eu!$"

VictoryRoad_1F_Text_WallyEntranceDefeat:
	.string "Nossa! Você é forte mesmo,\n"
	.string "{PLAYER}!$"

VictoryRoad_1F_Text_WallyPostEntranceBattle:
	.string "WALLY: Nao consegui vencer hoje,\n"
	.string "{PLAYER}, mas um dia vou alcançar\l"
	.string "você!$"

VictoryRoad_1F_Text_WallyIntro:
	.string "WALLY: Oi, {PLAYER}!\p"
	.string "Fiquei mais forte desde a última\n"
	.string "vez. Queria mostrar pra você,\l"
	.string "{PLAYER}!\p"
	.string "Ta bom... Lá vou eu!$"

VictoryRoad_1F_Text_WallyDefeat:
	.string "Nossa! Você é forte mesmo,\n"
	.string "{PLAYER}!$"

VictoryRoad_1F_Text_WallyPostBattle:
	.string "WALLY: Nao consegui vencer desta\n"
	.string "vez também... Mas um dia vou\l"
	.string "alcançar você, {PLAYER}...\p"
	.string "E desafiar a Liga Pokémon!$"

VictoryRoad_1F_Text_EdgarIntro:
	.string "Já cheguei até aqui algumas vezes,\n"
	.string "mas esse último trecho é longo\l"
	.string "demais...$"

VictoryRoad_1F_Text_EdgarDefeat:
	.string "Meu sonho acaba aqui de novo...$"

VictoryRoad_1F_Text_EdgarPostBattle:
	.string "Você chegou até aqui. Continue\n"
	.string "nesse ritmo e vire o campeao! Sei\l"
	.string "que consegue!$"

VictoryRoad_1F_Text_AlbertIntro:
	.string "Nao vim tao longe pra perder\n"
	.string "agora. Isso nem é uma opçao!$"

VictoryRoad_1F_Text_AlbertDefeat:
	.string "Impossível... Eu perdi?$"

VictoryRoad_1F_Text_AlbertPostBattle:
	.string "Perdi aqui...\p"
	.string "Isso quer dizer que ainda nao tô\n"
	.string "pronto pra ser campeao...$"

VictoryRoad_1F_Text_HopeIntro:
	.string "Essa estrada longa e difícil faz\n"
	.string "jus ao nome Victory Road.$"

VictoryRoad_1F_Text_HopeDefeat:
	.string "Seu jeito de batalhar é\n"
	.string "fantástico...$"

VictoryRoad_1F_Text_HopePostBattle:
	.string "Você tem tudo pra chegar ao posto\n"
	.string "de campeao.$"

VictoryRoad_1F_Text_QuincyIntro:
	.string "Oque é a Victory Road? Conto se\n"
	.string "você ganhar!$"

VictoryRoad_1F_Text_QuincyDefeat:
	.string "Muito bem! Você conseguiu!$"

VictoryRoad_1F_Text_QuincyPostBattle:
	.string "Passar por aqui em segurança é o\n"
	.string "teste final de quem quer ser\l"
	.string "campeao.\p"
	.string "Por isso o nome é Victory Road.$"

VictoryRoad_1F_Text_KatelynnIntro:
	.string "Nao tenho nada pra dizer a quem\n"
	.string "chegou tao longe. Vamos!$"

VictoryRoad_1F_Text_KatelynnDefeat:
	.string "Que vergonha...$"

VictoryRoad_1F_Text_KatelynnPostBattle:
	.string "Hum, pode seguir em frente. Nem\n"
	.string "ligo.$"
