SlateportCity_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentCorridor_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentCorridor_OnWarp
	.byte 0

	@ This is Slateport Tent's version of the Battle Factory Pre-Battle Room

SlateportCity_BattleTentCorridor_OnWarp:
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentCorridor_EventScript_SetUpObjects
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_SetUpObjects::
	setvar VAR_TEMP_1, 1
	goto_if_ne VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth
	setobjectxy LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, 2, 2
	turnobject LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, DIR_SOUTH
SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

SlateportCity_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, SlateportCity_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_EnterCorridor::
	goto_if_eq VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantEnter
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerEnter
	waitmovement 0
	goto_if_eq VAR_0x8006, 2, SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge
	slateporttent_generaterentalmons
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	slateporttent_rentmons
	waitstate
SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantExit
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerExit
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM, 4, 4
	waitstate
	end

SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle::
	factory_setopponentmons
	factory_resethelditems
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent::
	frontier_get FRONTIER_DATA_BATTLE_NUM
	call_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent
	call_if_eq VAR_RESULT, 2, SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentCorridor_EventScript_AskSwapMon
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge
	case 2, SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge

SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case YES, SlateportCity_BattleTentCorridor_EventScript_PauseChallenge
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case 0, SlateportCity_BattleTent_EventScript_WarpToLobbyLost
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskSwapMon::
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	case YES, SlateportCity_BattleTentCorridor_EventScript_SwapMons
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_SwapMons::
	fadescreen FADE_TO_BLACK
	slateporttent_swapmons
	waitstate
	goto_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_PauseChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait
	waitmessage
	slateporttent_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge::
	special SavePlayerParty
	factory_setparties 0
	goto SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_BattleTentCorridor_Movement_PlayerExit:
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantExit:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S
@ Unused
SlateportCity_ContestHall_Text_AdviceForContests:
	.string "Quer uma dica pros concursos?\p"
	.string "Usar certos golpes em sequência\n"
	.string "pode chamar mais atençao e render\l"
	.string "pontos extras.\p"
	.string "Mas os adversários podem tentar\n"
	.string "atrapalhar sua apresentaçao.$"

@ Unused
SlateportCity_ContestHall_Text_MyPapaIsContestJudge:
	.string "Meu pai é juiz de concursos.\p"
	.string "Quando crescer, será que viro juiz\n"
	.string "ou líder de ginásio?$"

@ Unused
SlateportCity_ContestHall_Text_ImLikeMajorlyCheesed:
	.string "Cara, tô muito irritado, sabe? Só\n"
	.string "queria entender por que meu\l"
	.string "Pokémon nunca ganha.\p"
	.string "Fui falar isso pro juiz e ele nem\n"
	.string "me ouviu! Que droga!\p"
	.string "Ei, você! Nao fala nada. Só pega\n"
	.string "isto!$"

@ Unused
SlateportCity_ContestHall_Text_ExplainTorment:
	.string "Essa é a TM41, sabe? Tem Torment.\n"
	.string "Ta me ouvindo?\p"
	.string "Ela impede o outro de usar o mesmo\n"
	.string "golpe duas vezes seguidas.\p"
	.string "E nao tô tentando atormentar\n"
	.string "você, ta?$"

@ Unused
SlateportCity_ContestHall_Text_MCStepUpTakePartInContest:
	.string "APRESENTADOR: Nossa, que Pokémon\n"
	.string "bonito!\p"
	.string "Venha participar dos nossos\n"
	.string "concursos!\p"
	.string "Tenho certeza que vai se sair bem.\n"
	.string "Meu olho nao falha!$"

@ Unused
SlateportCity_ContestHall_Text_JudgeWouldntDoToMissContest:
	.string "JUIZ: Oi! Vejo que você é um\n"
	.string "treinador!\p"
	.string "Entao nao pode perder os\n"
	.string "concursos Pokémon!\p"
	.string "Pegue um Contest Pass em\n"
	.string "Verdanturf City e participe quando\l"
	.string "quiser!$"

@ Unused
SlateportCity_ContestHall_Text_ItsAppealTime:
	.string "Hora da apresentaçao! Com qual\n"
	.string "golpe começo?$"

@ Unused
SlateportCity_ContestHall_Text_DidntPayAttentionToAppeal:
	.string "Nao deram muita atençao ao meu\n"
	.string "Pokémon...\p"
	.string "Hum, esse juiz nao reconhece uma\n"
	.string "coisa boa nem quando ta na frente\l"
	.string "dele.$"

@ Unused
SlateportCity_ContestHall_Text_RewardWithSageAdvice:
	.string "Oi! Você deve gostar mesmo pra\n"
	.string "chegar tao perto da açao.\p"
	.string "Uma dica: se um golpe faz sucesso,\n"
	.string "o público fica animado.\p"
	.string "O Pokémon que se apresentar bem\n"
	.string "na hora em que a animaçao chega\l"
	.string "ao máximo pode ganhar um bom\l"
	.string "bônus!$"

@ Unused
SlateportCity_ContestHall_Text_MoreFreakedOutThanMon:
	.string "Nao consigo! Tô mais nervoso que\n"
	.string "meu Pokémon!\p"
	.string "Tô tremendo e meu coraçao ta\n"
	.string "disparado!$"

@ Unused
SlateportCity_ContestHall_Text_BattleAndContestAlike:
	.string "Batalhas e concursos sao\n"
	.string "diferentes, mas também têm coisas\l"
	.string "em comum.\p"
	.string "Você precisa se esforçar e\n"
	.string "acreditar nos Pokémon que criou.$"

@ Unused
SlateportCity_ContestHall_Text_MonLooksOnTopOfGame:
	.string "Aquele Pokémon parece estar no\n"
	.string "seu melhor momento.\p"
	.string "Quem vai bem na segunda avaliaçao\n"
	.string "parece mais tranquilo durante as\l"
	.string "apresentaçoes.$"

@ Unused
SlateportCity_ContestHall_Text_MyMonBetterThanThatLot:
	.string "Olha só que situaçao...\p"
	.string "Heh, meu Pokémon é bem melhor que\n"
	.string "todos eles!$"

@ Unused
SlateportCity_ContestHall_Text_GetUrgeToMoveWithMon:
	.string "Quando um Pokémon faz uma\n"
	.string "apresentaçao animada, nao dá\l"
	.string "vontade de se mexer junto?$"

@ Unused
SlateportCity_ContestHall_Text_HyperRankStage:
	.string "Concursos Pokémon\p"
	.string "Palco do Hyper Rank!$"

