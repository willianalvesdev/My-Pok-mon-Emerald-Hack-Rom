BattleFrontier_BattlePyramidLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
	.byte 0

@ Unused. Pyramid uses Dome's OnWarp (presumably by mistake). Their effects are identical
BattleFrontier_BattlePyramidLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth:
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePyramidLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving::
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	closemessage
	pyramid_set PYRAMID_DATA_WIN_STREAK, 0
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing::
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints::
	special DoBattlePyramidMonsHaveHeldItem
	call_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag
	clearflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	message BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_setprize
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge::
	goto BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge

BattleFrontier_BattlePyramidLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PYRAMID
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pyramid_init
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	pyramid_seedfloor
	pyramid_settrainers
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePyramidLobby_EventScript_HintGiver::
	lockall
	applymovement LOCALID_PYRAMID_LOBBY_HINT_GIVER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidLobby_EventScript_GiveHint
	msgbox BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot, MSGBOX_DEFAULT
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint::
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	return

@ Shouldnt occur
BattleFrontier_BattlePyramidLobby_EventScript_NoHint::
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_50
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_50
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_OPEN
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_OPEN
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment::
	copyvar VAR_0x8004, VAR_RESULT
	special GetBattlePyramidHint
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_HintPoison
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_HintBurn
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate
	case 5, BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility
	case 6, BattleFrontier_BattlePyramidLobby_EventScript_HintIce
	case 7, BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion
	case 8, BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic
	case 9, BattleFrontier_BattlePyramidLobby_EventScript_HintRock
	case 10, BattleFrontier_BattlePyramidLobby_EventScript_HintFighting
	case 11, BattleFrontier_BattlePyramidLobby_EventScript_HintWeather
	case 12, BattleFrontier_BattlePyramidLobby_EventScript_HintBug
	case 13, BattleFrontier_BattlePyramidLobby_EventScript_HintDark
	case 14, BattleFrontier_BattlePyramidLobby_EventScript_HintWater
	case 15, BattleFrontier_BattlePyramidLobby_EventScript_HintGhost
	case 16, BattleFrontier_BattlePyramidLobby_EventScript_HintSteel
	case 17, BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon
	case 18, BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve
	case 19, BattleFrontier_BattlePyramidLobby_EventScript_HintNormal
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintParalysis, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPoison::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPoison, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBurn::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBurn, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPPWaste, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintLevitate, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintIce::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintIce, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintExplosion, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPsychic, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintRock::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintRock, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFighting::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFighting, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWeather::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWeather, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBug::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBug, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintDark::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintDark, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWater::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWater, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintGhost::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintGhost, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintSteel::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintSteel, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintNormal::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintNormal, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_PYRAMID
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag::
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag

BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag::
	message BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel
	waitmovement 0
	return

BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside:
	walk_right
	face_left
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel:
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake, MSGBOX_DEFAULT
	setflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	special TryStoreHeldItemsInPyramidBag
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag
	message BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag, MSGBOX_DEFAULT
	return

@ When exiting Battle Pyramid with a full pyramid bag and held items the player must select to keep/toss party held items and make room for any kept items by tossing from the pyramid bag
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep::
	multichoice 17, 6, MULTI_FRONTIER_ITEM_CHOOSE, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag::
	special ChooseItemsToTossFromPyramidBag
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty::
	special BattlePyramidChooseMonHeldItems
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems::
	special DoBattlePyramidMonsHaveHeldItem
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems
	return

BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem, MSGBOX_DEFAULT
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_Woman::
	msgbox BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePyramidLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 15, 2, MULTI_BATTLE_PYRAMID_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_RulesBag
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid:
	.string "Aqui a coragem dos treinadores é\n"
	.string "posta à prova!\p"
	.string "Boas-vindas à BATTLE PYRAMID!\p"
	.string "Vou te orientar na Jornada de\n"
	.string "Batalha.$"

BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge:
	.string "Tem coragem de encarar a Jornada\n"
	.string "de Batalha?$"

BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge:
	.string "Esperamos seu próximo desafio!$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid:
	.string "Na Jornada de Batalha, você\n"
	.string "explora a PYRAMID e tenta chegar\l"
	.string "ao topo.\p"
	.string "Sao sete andares de labirintos,\n"
	.string "cheios de treinadores fortes e\l"
	.string "Pokémon selvagens.\p"
	.string "Você precisa entrar com três\n"
	.string "Pokémon, sem itens para segurar.\p"
	.string "Durante a subida, recebe uma Bolsa\n"
	.string "de Batalha para guardar itens.\p"
	.string "Se perder o desafio, todos os\n"
	.string "itens dessa Bolsa somem.\p"
	.string "Se quiser parar por um tempo,\n"
	.string "escolha DESCANSAR e salve o jogo.\p"
	.string "Se sair sem salvar, você será\n"
	.string "eliminado do desafio.$"

BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode:
	.string "A PYRAMID tem dois desafios: Nível\n"
	.string "50 e Nível Livre. Qual você\l"
	.string "escolhe?$"

BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons:
	.string "Muito bem. Agora escolha os três\n"
	.string "Pokémon que vao com você.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Temos um probleminha!\p"
	.string "Você nao tem os três Pokémon\n"
	.string "necessários para o desafio.\p"
	.string "Lembre também de tirar todos os\n"
	.string "itens que eles estao segurando.\p"
	.string "OVOS{STR_VAR_1}.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50:
	.string "Temos um probleminha!\p"
	.string "Você nao tem os três Pokémon\n"
	.string "necessários para o desafio.\p"
	.string "Eles devem ser de espécies\n"
	.string "diferentes e estar no nível 50 ou\l"
	.string "abaixo.\p"
	.string "Lembre também de tirar todos os\n"
	.string "itens que eles estao segurando.\p"
	.string "OVOS{STR_VAR_1}.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsEnd:
	.string "Fale comigo quando estiver tudo\n"
	.string "pronto.$"

BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge:
	.string "Antes de entrar na BATTLE\n"
	.string "PYRAMID, é preciso salvar o jogo.\l"
	.string "Tudo bem?$"

BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid:
	.string "Muito bem. Vou te levar até a\n"
	.string "BATTLE PYRAMID.$"

BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping:
	.string "Vamos guardar sua Bolsa enquanto\n"
	.string "você explora, {PLAYER}.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag:
	.string "Em troca, pegue a Bolsa de Batalha\n"
	.string "que usou da última vez.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag:
	.string "Em troca, pegue esta Bolsa de\n"
	.string "Batalha.$"

BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag:
	.string "{PLAYER} trocou a Bolsa pela Bolsa\n"
	.string "de Batalha.$"

BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel:
	.string "Ao pisar neste painel, você será\n"
	.string "levado ao andar de cima da\l"
	.string "PYRAMID.\p"
	.string "Espero que sua jornada corra bem!$"

BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag:
	.string "Temos um grande problema!\p"
	.string "Da última vez, você saiu do\n"
	.string "desafio sem salvar.\p"
	.string "Por isso, seu desafio foi\n"
	.string "encerrado.\p"
	.string "Aqui está a Bolsa que guardamos\n"
	.string "para você.\p"
	.string "{PLAYER} pegou a Bolsa de volta.$"

BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid:
	.string "Que bom te ver de volta!\p"
	.string "Você conquistou a PYRAMID!\n"
	.string "Excelente!$"

BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake:
	.string "Ah, temos um probleminha.\p"
	.string "Pelo menos um Pokémon está\n"
	.string "segurando um item.\p"
	.string "Os itens encontrados na PYRAMID\n"
	.string "nao podem ser levados embora.$"

BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag:
	.string "Todos os itens que seus Pokémon\n"
	.string "estao segurando serao guardados\l"
	.string "na Bolsa de Batalha, {PLAYER}.$"

BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep:
	.string "Infelizmente, nao cabe tudo na\n"
	.string "Bolsa de Batalha.\p"
	.string "Escolha os itens que vai deixar na\n"
	.string "Bolsa de Batalha e com seus\l"
	.string "Pokémon.$"

BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem:
	.string "Pelo menos um Pokémon ainda está\n"
	.string "segurando um item.$"

BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep:
	.string "Escolha os itens que vai deixar na\n"
	.string "Bolsa de Batalha e com seus\l"
	.string "Pokémon.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReturnedEverythingMonsHeld:
	.string "{PLAYER} devolveu todos os itens\n"
	.string "que os Pokémon seguravam.$"

BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept:
	.string "Sua Bolsa de Batalha será guardada\n"
	.string "para o próximo desafio.\p"
	.string "{PLAYER} entregou a Bolsa de\n"
	.string "Batalha e recebeu sua Bolsa de\l"
	.string "volta.$"

BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait:
	.string "Preciso registrar seus resultados.\n"
	.string "Espere um pouco.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ForConqueringPyramidTakeThis:
	.string "Pela conquista da BATTLE PYRAMID,\n"
	.string "receba isto.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReceivedPrizeItem:
	.string "{PLAYER} recebeu {STR_VAR_1}\n"
	.string "como prêmio.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_BagIsFull:
	.string "Ah... Sua Bolsa está cheia.\p"
	.string "Organize os itens e volte depois.$"

BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag:
	.string "Que pena...\p"
	.string "Aqui está a Bolsa que guardamos\n"
	.string "para você.\p"
	.string "{PLAYER} pegou a Bolsa de volta.$"

BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge:
	.string "Esperamos seu próximo desafio!$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_HereIsPrize:
	.string "Estávamos esperando por você!\p"
	.string "Aqui está seu prêmio pela\n"
	.string "conquista da PYRAMID.$"

BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait:
	.string "Boas-vindas...\p"
	.string "Posso contar quais perigos esperam\n"
	.string "por você na PYRAMID...$"

BattleFrontier_BattlePyramidLobby_Text_Aah:
	.string "... ... ... ... ... ... ... ... ...\n"
	.string "... ... ...\p"
	.string "... ... ... ... ... ... Ah!$"

BattleFrontier_BattlePyramidLobby_Text_HintParalysis:
	.string "Vejo uma chuva de faíscas...\p"
	.string "...E seus Pokémon sofrendo com\n"
	.string "paralisia...$"

BattleFrontier_BattlePyramidLobby_Text_HintPoison:
	.string "Vejo veneno...\p"
	.string "...E seus Pokémon sofrendo com\n"
	.string "seus efeitos...$"

BattleFrontier_BattlePyramidLobby_Text_HintBurn:
	.string "Vejo chamas bem vermelhas...\p"
	.string "...E seus Pokémon sofrendo com\n"
	.string "queimaduras...$"

BattleFrontier_BattlePyramidLobby_Text_HintPPWaste:
	.string "Sinto o peso de uma raiva sem\n"
	.string "fim...\p"
	.string "É uma maldiçao...\p"
	.string "...E vejo seus Pokémon ficando sem\n"
	.string "PP, obrigados a usar STRUGGLE...$"

BattleFrontier_BattlePyramidLobby_Text_HintLevitate:
	.string "Vejo Pokémon voando bem alto...\p"
	.string "...E seus Pokémon tentando usar\n"
	.string "golpes do tipo Terra, sem\l"
	.string "resultado...$"

BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility:
	.string "Sinto uma grande força vindo do\n"
	.string "chao...\p"
	.string "...E seus Pokémon sem conseguir\n"
	.string "escapar dela...$"

BattleFrontier_BattlePyramidLobby_Text_HintIce:
	.string "Vejo Pokémon do tipo Gelo...\p"
	.string "...E seus Pokémon lutando contra o\n"
	.string "congelamento...$"

BattleFrontier_BattlePyramidLobby_Text_HintExplosion:
	.string "Vejo vários golpes que também\n"
	.string "machucam quem os usa...\p"
	.string "...E seus Pokémon caindo diante\n"
	.string "deles...$"

BattleFrontier_BattlePyramidLobby_Text_HintPsychic:
	.string "Vejo Pokémon do tipo Psíquico...\p"
	.string "...E seus Pokémon sofrendo com\n"
	.string "golpes psíquicos...$"

BattleFrontier_BattlePyramidLobby_Text_HintRock:
	.string "Vejo Pokémon do tipo Pedra...\p"
	.string "...E seus Pokémon sofrendo com\n"
	.string "golpes de Pedra...$"

BattleFrontier_BattlePyramidLobby_Text_HintFighting:
	.string "Vejo Pokémon do tipo Lutador...\p"
	.string "...E seus Pokémon apanhando de\n"
	.string "golpes de luta...$"

BattleFrontier_BattlePyramidLobby_Text_HintWeather:
	.string "RAIN DANCE... SUNNY DAY...\n"
	.string "SANDSTORM... HAIL...\p"
	.string "Vejo Pokémon que ficam mais fortes\n"
	.string "com o clima...\p"
	.string "...E seus Pokémon sofrendo com\n"
	.string "vários tipos de golpes...$"

BattleFrontier_BattlePyramidLobby_Text_HintBug:
	.string "Vejo Pokémon do tipo Inseto...\p"
	.string "...E seus Pokémon sofrendo com\n"
	.string "vários tipos de ataques...$"

BattleFrontier_BattlePyramidLobby_Text_HintDark:
	.string "Vejo Pokémon do tipo Sombrio...\p"
	.string "...E seus Pokémon sofrendo com\n"
	.string "golpes sombrios...$"

BattleFrontier_BattlePyramidLobby_Text_HintWater:
	.string "Vejo Pokémon do tipo Água...\p"
	.string "...E seus Pokémon sofrendo com\n"
	.string "golpes de Água...$"

BattleFrontier_BattlePyramidLobby_Text_HintGhost:
	.string "Vejo Pokémon do tipo Fantasma...\p"
	.string "...E seus Pokémon sofrendo com\n"
	.string "golpes de Fantasma...$"

BattleFrontier_BattlePyramidLobby_Text_HintSteel:
	.string "Vejo Pokémon do tipo Aço...\p"
	.string "...E seus Pokémon sofrendo com\n"
	.string "golpes muito poderosos...$"

BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon:
	.string "Vejo Pokémon voadores...\p"
	.string "...E seus Pokémon sofrendo com\n"
	.string "golpes muito poderosos...$"

BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve:
	.string "Vejo Pokémon que evoluíram com o\n"
	.string "poder das pedras...\p"
	.string "Também sinto fogo, água e\n"
	.string "eletricidade...\p"
	.string "...E seus Pokémon sofrendo com\n"
	.string "essas três forças...$"

BattleFrontier_BattlePyramidLobby_Text_HintNormal:
	.string "Vejo Pokémon do tipo Normal...\p"
	.string "...E seus Pokémon sofrendo com\n"
	.string "golpes muito poderosos...$"

BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot:
	.string "Você decide se acredita nas minhas\n"
	.string "previsoes...\p"
	.string "O futuro pode mudar a qualquer\n"
	.string "momento... Desejo uma boa\l"
	.string "viagem...$"

BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning:
	.string "Você sabia?\p"
	.string "Se correr, os treinadores podem te\n"
	.string "perceber e vir batalhar.\p"
	.string "Se quiser evitá-los, passe devagar\n"
	.string "e com cuidado, longe da vista\l"
	.string "deles.$"

BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems:
	.string "Aaaaargh!\p"
	.string "Eu tinha um monte de itens, mas\n"
	.string "perdi tudo quando fui derrotado!\p"
	.string "Aaaaargh!$"

BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing:
	.string "Boas-vindas de volta! Você fez o\n"
	.string "que parecia impossível!\p"
	.string "Venceu o PYRAMID KING e\n"
	.string "conquistou a BATTLE PYRAMID!$"

BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints:
	.string "Pela sua coragem, receba estes\n"
	.string "Pontos de Batalha!$"

BattleFrontier_BattlePyramidLobby_Text_RulesAreListed:
	.string "Aqui estao as regras da Jornada de\n"
	.string "Batalha.$"

BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading:
	.string "Sobre o que você quer ler?$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules:
	.string "Depois que você conquista a\n"
	.string "PYRAMID, as espécies de Pokémon\l"
	.string "selvagens que aparecem nela mudam.\p"
	.string "Explore, observe e descubra quais\n"
	.string "Pokémon pode encontrar.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules:
	.string "Os treinadores esperam por você\n"
	.string "dentro da PYRAMID.\p"
	.string "Cada andar tem até oito deles.\p"
	.string "Ao vencer um treinador, você\n"
	.string "recebe uma dica útil para sua\l"
	.string "aventura.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules:
	.string "Os labirintos da PYRAMID mudam\n"
	.string "toda vez que você entra.\p"
	.string "É bem escuro lá dentro, entao\n"
	.string "avance com cuidado.\p"
	.string "A luz aumenta sempre que você\n"
	.string "derrota um Pokémon selvagem ou um\l"
	.string "treinador.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules:
	.string "A Bolsa de Batalha substitui sua\n"
	.string "Bolsa dentro da PYRAMID.\p"
	.string "Você tem duas Bolsas de Batalha\n"
	.string "separadas: uma para Nível 50 e\l"
	.string "outra para Nível Livre.\p"
	.string "Cada uma guarda até 99 unidades\n"
	.string "de dez tipos de itens.\p"
	.string "Se perder o desafio, também perde\n"
	.string "os itens dessa Bolsa.$"

