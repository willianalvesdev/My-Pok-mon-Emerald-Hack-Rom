BattleFrontier_BattlePyramidFloor_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame:
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight::
	lockall
	@ pyramid_updatelight, cant use macro because it straddles the loop
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
	setvar VAR_0x8007, SE_SAVE
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop::
	special CallBattlePyramidFunction
	delay 2
	goto_if_ne VAR_RESULT, 2, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic::
	playbgm MUS_B_PYRAMID, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume:
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty::
	pyramid_resetparty
	end

BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
BattleFrontier_BattlePyramid_EventScript_WarpToLobby::
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
	pyramid_clearhelditems
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_OnTransition:
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius::
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
	return

BattlePyramid_WarpToNextFloor::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	goto_if_eq VAR_RESULT, 7, BattlePyramid_WarpToTop
	pyramid_seedfloor
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	waitstate
	end

BattlePyramid_WarpToTop::
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 17, 17
	waitstate
	end

BattlePyramid_TrainerBattle::
	facilitytrainerbattle FACILITY_BATTLE_PYRAMID
	pyramid_showhint
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall::
	pyramid_setitem
	callstd STD_FIND_ITEM
	goto_if_eq VAR_0x8007, 0, BattlePyramid_FindItemBallEnd
	pyramid_hideitem
BattlePyramid_FindItemBallEnd::
	end

BattlePyramid_Retire::
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

@ Also used by Trainer Hill
BattleFacility_TrainerBattle_PlaceholderText:
	.string "Esta é uma mensagem de exemplo.$"

gText_BattlePyramidConfirmRest::
	.string "Vou salvar seu desafio da BATTLE\n"
	.string "PYRAMID para você poder sair por\l"
	.string "enquanto. Tudo bem?$"

gText_BattlePyramidConfirmRetire::
	.string "Tem certeza de que quer desistir\n"
	.string "do desafio da PYRAMID?$"

BattlePyramid_Text_ExitHintUp1::
	.string "A saída deste andar fica nesta\n"
	.string "direçao: {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft1::
	.string "A saída deste andar fica nesta\n"
	.string "direçao: {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight1::
	.string "A saída deste andar fica nesta\n"
	.string "direçao: {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown1::
	.string "A saída deste andar fica nesta\n"
	.string "direçao: {DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp2::
	.string "A saída deste andar fica nesta\n"
	.string "direçao: {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft2::
	.string "A saída deste andar fica nesta\n"
	.string "direçao: {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight2::
	.string "A saída deste andar fica nesta\n"
	.string "direçao: {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown2::
	.string "A saída deste andar fica nesta\n"
	.string "direçao: {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp3::
	.string "A saída é por ali: {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft3::
	.string "A saída é por ali: {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight3::
	.string "A saída é por ali: {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown3::
	.string "A saída é por ali: {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp4::
	.string "Neste andar, a saída fica em algum\n"
	.string "lugar nessa direçao: {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft4::
	.string "Neste andar, a saída fica em algum\n"
	.string "lugar nessa direçao: {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight4::
	.string "Neste andar, a saída fica em algum\n"
	.string "lugar nessa direçao: {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown4::
	.string "Neste andar, a saída fica em algum\n"
	.string "lugar nessa direçao: {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp5::
	.string "A saída? É por ali: {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft5::
	.string "A saída? É por ali: {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight5::
	.string "A saída? É por ali: {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown5::
	.string "A saída? É por ali: {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp6::
	.string "A saída fica nesta direçao: {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft6::
	.string "A saída fica nesta direçao: {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight6::
	.string "A saída fica nesta direçao: {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown6::
	.string "A saída fica nesta direçao: {DOWN_ARROW}.$"

BattlePyramid_Text_EightItemsRemaining1::
	.string "Está procurando itens?\p"
	.string "Ainda tem oito para encontrar.$"

BattlePyramid_Text_SevenItemsRemaining1::
	.string "Está procurando itens?\p"
	.string "Ainda tem sete para encontrar.$"

BattlePyramid_Text_SixItemsRemaining1::
	.string "Está procurando itens?\p"
	.string "Ainda tem seis para encontrar.$"

BattlePyramid_Text_FiveItemsRemaining1::
	.string "Está procurando itens?\p"
	.string "Ainda tem cinco para encontrar.$"

BattlePyramid_Text_FourItemsRemaining1::
	.string "Está procurando itens?\p"
	.string "Ainda tem quatro para encontrar.$"

BattlePyramid_Text_ThreeItemsRemaining1::
	.string "Está procurando itens?\p"
	.string "Ainda tem três para encontrar.$"

BattlePyramid_Text_TwoItemsRemaining1::
	.string "Está procurando itens?\p"
	.string "Ainda tem dois para encontrar.$"

BattlePyramid_Text_OneItemRemaining1::
	.string "Está procurando itens?\p"
	.string "Ainda tem um para encontrar.$"

BattlePyramid_Text_ZeroItemsRemaining1::
	.string "Está procurando itens?\p"
	.string "Nao sobrou mais nenhum!$"

BattlePyramid_Text_EightItemsRemaining2::
	.string "Já que você ganhou, vou contar um\n"
	.string "segredinho!\p"
	.string "Tem oito itens espalhados por\n"
	.string "aqui.$"

BattlePyramid_Text_SevenItemsRemaining2::
	.string "Já que você ganhou, vou contar um\n"
	.string "segredinho!\p"
	.string "Ainda tem sete itens espalhados\n"
	.string "por aqui.$"

BattlePyramid_Text_SixItemsRemaining2::
	.string "Já que você ganhou, vou contar um\n"
	.string "segredinho!\p"
	.string "Ainda tem seis itens espalhados\n"
	.string "por aqui.$"

BattlePyramid_Text_FiveItemsRemaining2::
	.string "Já que você ganhou, vou contar um\n"
	.string "segredinho!\p"
	.string "Ainda tem cinco itens espalhados\n"
	.string "por aqui.$"

BattlePyramid_Text_FourItemsRemaining2::
	.string "Já que você ganhou, vou contar um\n"
	.string "segredinho!\p"
	.string "Ainda tem quatro itens espalhados\n"
	.string "por aqui.$"

BattlePyramid_Text_ThreeItemsRemaining2::
	.string "Já que você ganhou, vou contar um\n"
	.string "segredinho!\p"
	.string "Ainda tem três itens espalhados\n"
	.string "por aqui.$"

BattlePyramid_Text_TwoItemsRemaining2::
	.string "Já que você ganhou, vou contar um\n"
	.string "segredinho!\p"
	.string "Ainda tem dois itens espalhados\n"
	.string "por aqui.$"

BattlePyramid_Text_OneItemRemaining2::
	.string "Já que você ganhou, vou contar um\n"
	.string "segredinho!\p"
	.string "Só sobrou um item por aqui.$"

BattlePyramid_Text_ZeroItemsRemaining2::
	.string "Já que você ganhou, vou contar um\n"
	.string "segredinho!\p"
	.string "Nao sobrou nenhum item por aqui.$"

BattlePyramid_Text_EightItemsRemaining3::
	.string "Como está seu estoque de itens?\p"
	.string "Acho que ainda tem oito esperando\n"
	.string "por você neste andar.$"

BattlePyramid_Text_SevenItemsRemaining3::
	.string "Como está seu estoque de itens?\p"
	.string "Acho que ainda tem sete esperando\n"
	.string "por você neste andar.$"

BattlePyramid_Text_SixItemsRemaining3::
	.string "Como está seu estoque de itens?\p"
	.string "Acho que ainda tem seis esperando\n"
	.string "por você neste andar.$"

BattlePyramid_Text_FiveItemsRemaining3::
	.string "Como está seu estoque de itens?\p"
	.string "Acho que ainda tem cinco esperando\n"
	.string "por você neste andar.$"

BattlePyramid_Text_FourItemsRemaining3::
	.string "Como está seu estoque de itens?\p"
	.string "Acho que ainda tem quatro\n"
	.string "esperando por você neste andar.$"

BattlePyramid_Text_ThreeItemsRemaining3::
	.string "Como está seu estoque de itens?\p"
	.string "Acho que ainda tem três esperando\n"
	.string "por você neste andar.$"

BattlePyramid_Text_TwoItemsRemaining3::
	.string "Como está seu estoque de itens?\p"
	.string "Acho que ainda tem dois esperando\n"
	.string "por você neste andar.$"

BattlePyramid_Text_OneItemRemaining3::
	.string "Como está seu estoque de itens?\p"
	.string "Acho que só tem um esperando por\n"
	.string "você neste andar.$"

BattlePyramid_Text_ZeroItemsRemaining3::
	.string "Como está seu estoque de itens?\p"
	.string "Acho que nao sobrou mais nada\n"
	.string "neste andar. Se cuida!$"

BattlePyramid_Text_EightItemsRemaining4::
	.string "Você é forte, entao merece uma\n"
	.string "dica!\p"
	.string "Parece que ainda tem oito itens no\n"
	.string "chao.$"

BattlePyramid_Text_SevenItemsRemaining4::
	.string "Você é forte, entao merece uma\n"
	.string "dica!\p"
	.string "Parece que ainda tem sete itens no\n"
	.string "chao.$"

BattlePyramid_Text_SixItemsRemaining4::
	.string "Você é forte, entao merece uma\n"
	.string "dica!\p"
	.string "Parece que ainda tem seis itens no\n"
	.string "chao.$"

BattlePyramid_Text_FiveItemsRemaining4::
	.string "Você é forte, entao merece uma\n"
	.string "dica!\p"
	.string "Parece que ainda tem cinco itens\n"
	.string "no chao.$"

BattlePyramid_Text_FourItemsRemaining4::
	.string "Você é forte, entao merece uma\n"
	.string "dica!\p"
	.string "Parece que ainda tem quatro itens\n"
	.string "no chao.$"

BattlePyramid_Text_ThreeItemsRemaining4::
	.string "Você é forte, entao merece uma\n"
	.string "dica!\p"
	.string "Parece que ainda tem três itens no\n"
	.string "chao.$"

BattlePyramid_Text_TwoItemsRemaining4::
	.string "Você é forte, entao merece uma\n"
	.string "dica!\p"
	.string "Parece que ainda tem dois itens no\n"
	.string "chao.$"

BattlePyramid_Text_OneItemRemaining4::
	.string "Você é forte, entao merece uma\n"
	.string "dica!\p"
	.string "Parece que só sobrou um item no\n"
	.string "chao.$"

BattlePyramid_Text_ZeroItemsRemaining4::
	.string "Você é forte, entao merece uma\n"
	.string "dica!\p"
	.string "Parece que nao sobrou nenhum item\n"
	.string "no chao.$"

BattlePyramid_Text_EightItemsRemaining5::
	.string "Ouvi dizer que tem oito itens\n"
	.string "neste andar da PYRAMID...$"

BattlePyramid_Text_SevenItemsRemaining5::
	.string "Ouvi dizer que tem sete itens\n"
	.string "neste andar da PYRAMID...$"

BattlePyramid_Text_SixItemsRemaining5::
	.string "Ouvi dizer que tem seis itens\n"
	.string "neste andar da PYRAMID...$"

BattlePyramid_Text_FiveItemsRemaining5::
	.string "Ouvi dizer que tem cinco itens\n"
	.string "neste andar da PYRAMID...$"

BattlePyramid_Text_FourItemsRemaining5::
	.string "Ouvi dizer que tem quatro itens\n"
	.string "neste andar da PYRAMID...$"

BattlePyramid_Text_ThreeItemsRemaining5::
	.string "Ouvi dizer que tem três itens\n"
	.string "neste andar da PYRAMID...$"

BattlePyramid_Text_TwoItemsRemaining5::
	.string "Ouvi dizer que tem dois itens\n"
	.string "neste andar da PYRAMID...$"

BattlePyramid_Text_OneItemRemaining5::
	.string "Ouvi dizer que tem um item neste\n"
	.string "andar da PYRAMID...$"

BattlePyramid_Text_ZeroItemsRemaining5::
	.string "Ouvi dizer que nao tem nenhum item\n"
	.string "neste andar da PYRAMID...$"

BattlePyramid_Text_EightItemsRemaining6::
	.string "Já pegou algum item?\p"
	.string "Acho que ainda tem oito neste\n"
	.string "andar.$"

BattlePyramid_Text_SevenItemsRemaining6::
	.string "Já pegou algum item?\p"
	.string "Acho que ainda tem sete neste\n"
	.string "andar.$"

BattlePyramid_Text_SixItemsRemaining6::
	.string "Já pegou algum item?\p"
	.string "Acho que ainda tem seis neste\n"
	.string "andar.$"

BattlePyramid_Text_FiveItemsRemaining6::
	.string "Já pegou algum item?\p"
	.string "Acho que ainda tem cinco neste\n"
	.string "andar.$"

BattlePyramid_Text_FourItemsRemaining6::
	.string "Já pegou algum item?\p"
	.string "Acho que ainda tem quatro neste\n"
	.string "andar.$"

BattlePyramid_Text_ThreeItemsRemaining6::
	.string "Já pegou algum item?\p"
	.string "Acho que ainda tem três neste\n"
	.string "andar.$"

BattlePyramid_Text_TwoItemsRemaining6::
	.string "Já pegou algum item?\p"
	.string "Acho que ainda tem dois neste\n"
	.string "andar.$"

BattlePyramid_Text_OneItemRemaining6::
	.string "Já pegou algum item?\p"
	.string "Acho que só tem mais um neste\n"
	.string "andar.$"

BattlePyramid_Text_ZeroItemsRemaining6::
	.string "Já pegou algum item?\p"
	.string "Acho que nao sobrou nenhum neste\n"
	.string "andar.$"

BattlePyramid_Text_SevenTrainersRemaining1::
	.string "Você mandou muito bem!\p"
	.string "Mas ainda tem sete treinadores\n"
	.string "fortes além de mim!$"

BattlePyramid_Text_SixTrainersRemaining1::
	.string "Você mandou muito bem!\p"
	.string "Mas ainda tem seis treinadores\n"
	.string "fortes além de mim!$"

BattlePyramid_Text_FiveTrainersRemaining1::
	.string "Você mandou muito bem!\p"
	.string "Mas ainda tem cinco treinadores\n"
	.string "fortes além de mim!$"

BattlePyramid_Text_FourTrainersRemaining1::
	.string "Você mandou muito bem!\p"
	.string "Mas ainda tem quatro treinadores\n"
	.string "fortes além de mim!$"

BattlePyramid_Text_ThreeTrainersRemaining1::
	.string "Você mandou muito bem!\p"
	.string "Mas ainda tem três treinadores\n"
	.string "fortes além de mim!$"

BattlePyramid_Text_TwoTrainersRemaining1::
	.string "Você mandou muito bem!\p"
	.string "Mas ainda tem dois treinadores\n"
	.string "fortes além de mim!$"

BattlePyramid_Text_OneTrainersRemaining1::
	.string "Você mandou muito bem!\p"
	.string "Mas ainda tem um treinador forte\n"
	.string "além de mim!$"

BattlePyramid_Text_ZeroTrainersRemaining1::
	.string "Você mandou muito bem!\p"
	.string "Nao sobrou ninguém que possa te\n"
	.string "vencer!$"

BattlePyramid_Text_SevenTrainersRemaining2::
	.string "Que raiva!\p"
	.string "Mas ainda tem sete treinadores!\n"
	.string "Alguém vai te dar uma liçao!$"

BattlePyramid_Text_SixTrainersRemaining2::
	.string "Que raiva!\p"
	.string "Mas ainda tem seis treinadores!\n"
	.string "Alguém vai te dar uma liçao!$"

BattlePyramid_Text_FiveTrainersRemaining2::
	.string "Que raiva!\p"
	.string "Mas ainda tem cinco treinadores!\n"
	.string "Alguém vai te dar uma liçao!$"

BattlePyramid_Text_FourTrainersRemaining2::
	.string "Que raiva!\p"
	.string "Mas ainda tem quatro treinadores!\n"
	.string "Alguém vai te dar uma liçao!$"

BattlePyramid_Text_ThreeTrainersRemaining2::
	.string "Que raiva!\p"
	.string "Mas ainda tem três treinadores!\n"
	.string "Alguém vai te dar uma liçao!$"

BattlePyramid_Text_TwoTrainersRemaining2::
	.string "Que raiva!\p"
	.string "Mas ainda tem dois treinadores!\n"
	.string "Alguém vai te dar uma liçao!$"

BattlePyramid_Text_OneTrainersRemaining2::
	.string "Que raiva!\p"
	.string "Mas ainda tem um treinador! Tenho\n"
	.string "certeza de que ele vai te dar uma\l"
	.string "liçao!$"

BattlePyramid_Text_ZeroTrainersRemaining2::
	.string "Que raiva!\p"
	.string "Mas nao sobrou nenhum treinador\n"
	.string "pra te enfrentar!$"

BattlePyramid_Text_SevenTrainersRemaining3::
	.string "Foi impressionante!\p"
	.string "Mas ainda tem sete treinadores\n"
	.string "neste andar. Consegue vencer\l"
	.string "todos?$"

BattlePyramid_Text_SixTrainersRemaining3::
	.string "Foi impressionante!\p"
	.string "Mas ainda tem seis treinadores\n"
	.string "neste andar. Consegue vencer\l"
	.string "todos?$"

BattlePyramid_Text_FiveTrainersRemaining3::
	.string "Foi impressionante!\p"
	.string "Mas ainda tem cinco treinadores\n"
	.string "neste andar. Consegue vencer\l"
	.string "todos?$"

BattlePyramid_Text_FourTrainersRemaining3::
	.string "Foi impressionante!\p"
	.string "Mas ainda tem quatro treinadores\n"
	.string "neste andar. Consegue vencer\l"
	.string "todos?$"

BattlePyramid_Text_ThreeTrainersRemaining3::
	.string "Foi impressionante!\p"
	.string "Mas ainda tem três treinadores\n"
	.string "neste andar. Consegue vencer\l"
	.string "todos?$"

BattlePyramid_Text_TwoTrainersRemaining3::
	.string "Foi impressionante!\p"
	.string "Mas ainda tem dois treinadores\n"
	.string "neste andar. Consegue vencer os\l"
	.string "dois?$"

BattlePyramid_Text_OneTrainersRemaining3::
	.string "Foi impressionante!\p"
	.string "Mas ainda tem um treinador neste\n"
	.string "andar. Consegue vencer?$"

BattlePyramid_Text_ZeroTrainersRemaining3::
	.string "Foi impressionante!\p"
	.string "Você enfrentou todos os\n"
	.string "treinadores deste andar.$"

BattlePyramid_Text_SevenTrainersRemaining4::
	.string "Talvez você consiga vencer os sete\n"
	.string "treinadores que sobraram neste\l"
	.string "andar.$"

BattlePyramid_Text_SixTrainersRemaining4::
	.string "Talvez você consiga vencer os seis\n"
	.string "treinadores que sobraram neste\l"
	.string "andar.$"

BattlePyramid_Text_FiveTrainersRemaining4::
	.string "Talvez você consiga vencer os\n"
	.string "cinco treinadores que sobraram\l"
	.string "neste andar.$"

BattlePyramid_Text_FourTrainersRemaining4::
	.string "Talvez você consiga vencer os\n"
	.string "quatro treinadores que sobraram\l"
	.string "neste andar.$"

BattlePyramid_Text_ThreeTrainersRemaining4::
	.string "Talvez você consiga vencer os três\n"
	.string "treinadores que sobraram neste\l"
	.string "andar.$"

BattlePyramid_Text_TwoTrainersRemaining4::
	.string "Talvez você consiga vencer os dois\n"
	.string "treinadores que sobraram neste\l"
	.string "andar.$"

BattlePyramid_Text_OneTrainersRemaining4::
	.string "Talvez você complete a sequência\n"
	.string "vencendo o último treinador deste\l"
	.string "andar.$"

BattlePyramid_Text_ZeroTrainersRemaining4::
	.string "Agora nao sobrou ninguém que possa\n"
	.string "te vencer...$"

BattlePyramid_Text_SevenTrainersRemaining5::
	.string "Talvez você consiga vencer os sete\n"
	.string "treinadores experientes que\l"
	.string "sobraram.$"

BattlePyramid_Text_SixTrainersRemaining5::
	.string "Talvez você consiga vencer os seis\n"
	.string "treinadores experientes que\l"
	.string "sobraram.$"

BattlePyramid_Text_FiveTrainersRemaining5::
	.string "Talvez você consiga vencer os\n"
	.string "cinco treinadores experientes que\l"
	.string "sobraram.$"

BattlePyramid_Text_FourTrainersRemaining5::
	.string "Talvez você consiga vencer os\n"
	.string "quatro treinadores experientes que\l"
	.string "sobraram.$"

BattlePyramid_Text_ThreeTrainersRemaining5::
	.string "Talvez você consiga vencer os três\n"
	.string "treinadores experientes que\l"
	.string "sobraram.$"

BattlePyramid_Text_TwoTrainersRemaining5::
	.string "Talvez você consiga vencer os dois\n"
	.string "treinadores experientes que\l"
	.string "sobraram.$"

BattlePyramid_Text_OneTrainersRemaining5::
	.string "Talvez você consiga vencer o\n"
	.string "último treinador experiente.$"

BattlePyramid_Text_ZeroTrainersRemaining5::
	.string "Você luta muito bem.\p"
	.string "Nao sobrou nenhum treinador aqui\n"
	.string "com chance de te vencer.$"

BattlePyramid_Text_SevenTrainersRemaining6::
	.string "Consegue continuar ganhando dos\n"
	.string "sete treinadores restantes?$"

BattlePyramid_Text_SixTrainersRemaining6::
	.string "Consegue continuar ganhando dos\n"
	.string "seis treinadores restantes?$"

BattlePyramid_Text_FiveTrainersRemaining6::
	.string "Consegue continuar ganhando dos\n"
	.string "cinco treinadores restantes?$"

BattlePyramid_Text_FourTrainersRemaining6::
	.string "Consegue continuar ganhando dos\n"
	.string "quatro treinadores restantes?$"

BattlePyramid_Text_ThreeTrainersRemaining6::
	.string "Consegue continuar ganhando dos\n"
	.string "três treinadores restantes?$"

BattlePyramid_Text_TwoTrainersRemaining6::
	.string "Consegue continuar ganhando dos\n"
	.string "dois treinadores restantes?$"

BattlePyramid_Text_OneTrainersRemaining6::
	.string "Consegue vencer o último\n"
	.string "treinador?$"

BattlePyramid_Text_ZeroTrainersRemaining6::
	.string "Agora nao sobrou nenhum treinador\n"
	.string "pra te enfrentar...$"
