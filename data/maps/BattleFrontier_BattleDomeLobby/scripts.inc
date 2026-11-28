BattleFrontier_BattleDomeLobby_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleDomeLobby_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
	.byte 0

BattleFrontier_BattleDomeLobby_OnResume:
	dome_initresultstree
	end

BattleFrontier_BattleDomeLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleDomeLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleDomeLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleDomeLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleDomeLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleDomeLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleDomeLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleDomeLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleDomeLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleDomeLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleDomeLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	dome_set DOME_DATA_WIN_STREAK, 0
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, FALSE
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_WonChallenge::
	call BattleFrontier_EventScript_IncrementWinStreak
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleDomeLobby_EventScript_DefeatedAce
	msgbox BattleFrontier_BattleDomeLobby_Text_CongratsForWinningTourney, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleDomeLobby_EventScript_DefeatedAce::
	msgbox BattleFrontier_BattleDomeLobby_Text_CongratsDefeatedTucker, MSGBOX_DEFAULT
BattleFrontier_BattleDomeLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleDomeLobby_Text_AwardTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved
	waitmessage
	special LoadPlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	frontier_checkairshow
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
	dome_set DOME_DATA_HAS_WON_CHALLENGE, TRUE
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, TRUE
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	goto BattleFrontier_BattleDomeLobby_EventScript_AskRecordBattle

BattleFrontier_BattleDomeLobby_EventScript_LostChallenge::
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_ThankYouForPlaying, MSGBOX_DEFAULT
	message BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved
	waitmessage
	special LoadPlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	frontier_checkairshow
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, FALSE
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleDomeLobby_EventScript_AskRecordBattle::
	dome_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge
	message BattleFrontier_BattleDomeLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge
	case 0, BattleFrontier_BattleDomeLobby_EventScript_RecordBattle
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge

BattleFrontier_BattleDomeLobby_EventScript_RecordBattle::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleDomeLobby_EventScript_EndChallenge::
	msgbox BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_ResumeChallenge::
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_WeveBeenWaitingForYou, MSGBOX_DEFAULT
	message BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge2
	waitmessage
	dome_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattleDomeLobby_EventScript_EnterChallenge

BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_DOME
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome
	end

BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_DOME
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome
	end

BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome::
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_WelcomeSingles
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_WelcomeDoubles
BattleFrontier_BattleDomeLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_TakeSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_TakeDoublesChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomeLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleDomeLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge

BattleFrontier_BattleDomeLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleDomeLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleDomeLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge
	msgbox BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge
	case YES, BattleFrontier_BattleDomeLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge

BattleFrontier_BattleDomeLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	dome_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomeLobby_EventScript_CancelChallengeSaveFailed
	dome_inittrainers
BattleFrontier_BattleDomeLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	dome_settrainers
	msgbox BattleFrontier_BattleDomeLobby_Text_ShowYouToBattleDome, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattleDomeLobby_EventScript_WalkToDoor
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_CORRIDOR, 23, 6
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleDomeLobby_EventScript_ExplainChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_ExplainSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_ExplainDoublesChallenge
	goto BattleFrontier_BattleDomeLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleDomeLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge

BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain, MSGBOX_DEFAULT
BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattleDomeLobby_EventScript_WalkToDoor::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendantWalkToDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendantWalkToDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_OpenSinglesDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_OpenDoublesDoor
	waitdooranim
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendantEnterDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeLobby_Movement_PlayerEnterDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_CloseSinglesDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_CloseDoublesDoor
	waitdooranim
	return

BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendantWalkToDoor::
	applymovement LOCALID_DOME_ATTENDANT_SINGLES, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor
	return

BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendantWalkToDoor::
	applymovement LOCALID_DOME_ATTENDANT_DOUBLES, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor
	return

BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendantEnterDoor::
	applymovement LOCALID_DOME_ATTENDANT_SINGLES, BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor
	return

BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendantEnterDoor::
	applymovement LOCALID_DOME_ATTENDANT_DOUBLES, BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor
	return

BattleFrontier_BattleDomeLobby_EventScript_WelcomeSingles::
	msgbox BattleFrontier_BattleDomeLobby_Text_WelcomeSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_WelcomeDoubles::
	msgbox BattleFrontier_BattleDomeLobby_Text_WelcomeDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_TakeSinglesChallenge::
	message BattleFrontier_BattleDomeLobby_Text_TakeSinglesChallenge
	return

BattleFrontier_BattleDomeLobby_EventScript_TakeDoublesChallenge::
	message BattleFrontier_BattleDomeLobby_Text_TakeDoublesChallenge
	return

BattleFrontier_BattleDomeLobby_EventScript_ExplainSinglesChallenge::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_OpenSinglesDoor::
	opendoor 5, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_OpenDoublesDoor::
	opendoor 17, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_CloseSinglesDoor::
	closedoor 5, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_CloseDoublesDoor::
	closedoor 17, 4
	return

BattleFrontier_BattleDomeLobby_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_DOME, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_DOME, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_ShowPrevTourneyTree::
	dome_get DOME_DATA_PREV_TOURNEY_TYPE
	call_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLv50
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLv50
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLvOpen
	call_if_eq VAR_RESULT, 3, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLvOpen
	fadescreen FADE_TO_BLACK
	dome_showprevtourneytree
	waitstate
	end

BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLv50::
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLv50, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLv50::
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLv50, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLvOpen::
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLvOpen, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLvOpen::
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLvOpen, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_Maniac::
	dome_getwinnersname
	msgbox BattleFrontier_BattleDomeLobby_Text_LastWinnerWasTough, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_Lass::
	msgbox BattleFrontier_BattleDomeLobby_Text_WinnersGainReputation, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattleDomeLobby_Text_TrashedInFirstRound, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_Man::
	msgbox BattleFrontier_BattleDomeLobby_Text_NeedToCheckOpponentCarefully, MSGBOX_NPC
	end

@ A few OutsideWest event scripts are inserted here instead, two of which are unused
BattleFrontier_OutsideWest_EventScript_Man3::
	msgbox BattleFrontier_OutsideWest_Text_LongDreamedAboutBattleFrontier, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_BattleDomeSign2::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign2, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnderConstructionSign::
	msgbox BattleFrontier_OutsideWest_Text_QuestionMarkUnderConstruction, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleDomeLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 4, MULTI_BATTLE_DOME_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomeLobby_EventScript_RulesMatchup
	case 1, BattleFrontier_BattleDomeLobby_EventScript_RulesTourneyTree
	case 2, BattleFrontier_BattleDomeLobby_EventScript_RulesDoubleKO
	case 3, BattleFrontier_BattleDomeLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_ExitRules
	end

BattleFrontier_BattleDomeLobby_EventScript_RulesMatchup::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainMatchupRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleDomeLobby_EventScript_RulesTourneyTree::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainTourneyTree, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleDomeLobby_EventScript_RulesDoubleKO::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainDoubleKORules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleDomeLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleDomeLobby_Text_WelcomeSingleBattle:
	.string "Aqui a estratégia dos treinadores\n"
	.string "é posta à prova!\p"
	.string "Boas-vindas ao BATTLE DOME!\p"
	.string "Vou te orientar no Torneio de\n"
	.string "Batalhas Individuais.$"

BattleFrontier_BattleDomeLobby_Text_TakeSinglesChallenge:
	.string "Quer participar do Torneio de\n"
	.string "Batalhas Individuais?$"

BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain:
	.string "Esperamos te ver de novo.$"

BattleFrontier_BattleDomeLobby_Text_ExplainSinglesChallenge:
	.string "O Torneio de Batalhas Individuais\n"
	.string "funciona como o nome diz: todas as\l"
	.string "batalhas sao individuais.\p"
	.string "Cada treinador entra com três\n"
	.string "Pokémon.\p"
	.string "Em cada partida, um deles fica de\n"
	.string "reserva.\p"
	.string "Os outros dois lutam, um por vez.\p"
	.string "Confira os três Pokémon do\n"
	.string "adversário antes de escolher os\l"
	.string "dois que vao lutar.\p"
	.string "Para ganhar o torneio, você\n"
	.string "precisa vencer quatro treinadores.\p"
	.string "Quem vence o torneio ganha Pontos\n"
	.string "de Batalha.\p"
	.string "Se quiser parar por um tempo,\n"
	.string "salve o jogo.\p"
	.string "Se sair sem salvar, você será\n"
	.string "eliminado do desafio.$"

BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge:
	.string "Antes de te levar ao BATTLE DOME,\n"
	.string "preciso salvar o jogo. Tudo bem?$"

BattleFrontier_BattleDomeLobby_Text_WhichLevelMode:
	.string "O torneio tem dois desafios: Nível\n"
	.string "50 e Nível Livre. Qual você\l"
	.string "escolhe?$"

BattleFrontier_BattleDomeLobby_Text_SelectThreeMons:
	.string "Escolha os três Pokémon que vao\n"
	.string "participar.$"

BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Opa!\p"
	.string "Você nao tem três Pokémon que\n"
	.string "possam participar.\p"
	.string "Eles também precisam estar\n"
	.string "segurando itens diferentes.\p"
	.string "OVOS{STR_VAR_1}.$"

BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsEnd:
	.string "Volte quando estiver tudo pronto.$"

BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLv50:
	.string "Opa!\p"
	.string "Você nao tem três Pokémon que\n"
	.string "possam participar.\p"
	.string "Precisa trazer três Pokémon de\n"
	.string "espécies diferentes, no nível 50\l"
	.string "ou abaixo.\p"
	.string "Eles também precisam estar\n"
	.string "segurando itens diferentes.\p"
	.string "OVOS{STR_VAR_1}.$"

BattleFrontier_BattleDomeLobby_Text_ShowYouToBattleDome:
	.string "Vou te levar até o BATTLE DOME.$"

BattleFrontier_BattleDomeLobby_Text_DidntSaveBeforeQuitting:
	.string "Opa!\p"
	.string "Da última vez, você saiu do\n"
	.string "desafio sem salvar.\p"
	.string "Por isso, seu desafio foi\n"
	.string "encerrado. Que pena!$"

BattleFrontier_BattleDomeLobby_Text_CongratsForWinningTourney:
	.string "Parabéns por vencer o Torneio de\n"
	.string "Batalha!$"

@ Unused
BattleFrontier_BattleDomeLobby_Text_HereIsYourPrize:
	.string "Aqui está seu prêmio pela vitória\n"
	.string "no Torneio de Batalha.$"

@ Used by Verdanturf Tent
BattleFrontier_BattleDomeLobby_Text_ReceivedPrize:
	.string "{PLAYER} recebeu {STR_VAR_1}\n"
	.string "como prêmio.$"

@ Unused
BattleFrontier_BattleDomeLobby_Text_BagFullMakeRoom:
	.string "Sua Bolsa está cheia.\p"
	.string "Libere um espaço e volte para\n"
	.string "falar comigo.$"

BattleFrontier_BattleDomeLobby_Text_ThankYouForPlaying:
	.string "Valeu por jogar!$"

BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved:
	.string "Vou salvar seu resultado. Espere\n"
	.string "um pouco.$"

BattleFrontier_BattleDomeLobby_Text_WeveBeenWaitingForYou:
	.string "Estávamos esperando por você!$"

BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge2:
	.string "Antes de te levar ao BATTLE DOME,\n"
	.string "preciso salvar o jogo. Tudo bem?$"

BattleFrontier_BattleDomeLobby_Text_WelcomeDoubleBattle:
	.string "Aqui a estratégia dos treinadores\n"
	.string "é posta à prova!\p"
	.string "Boas-vindas ao BATTLE DOME!\p"
	.string "Vou te orientar no Torneio de\n"
	.string "Batalhas em Dupla.$"

BattleFrontier_BattleDomeLobby_Text_TakeDoublesChallenge:
	.string "Quer participar do Torneio de\n"
	.string "Batalhas em Dupla?$"

BattleFrontier_BattleDomeLobby_Text_ExplainDoublesChallenge:
	.string "O Torneio de Batalhas em Dupla\n"
	.string "funciona como o nome diz: todas as\l"
	.string "batalhas sao em dupla.\p"
	.string "Cada treinador entra com três\n"
	.string "Pokémon.\p"
	.string "Em cada partida, um deles fica de\n"
	.string "reserva.\p"
	.string "Os outros dois lutam juntos.\p"
	.string "Confira os três Pokémon do\n"
	.string "adversário antes de escolher os\l"
	.string "dois que vao lutar.\p"
	.string "Para ganhar o torneio, você\n"
	.string "precisa vencer quatro treinadores.\p"
	.string "Quem vence o torneio ganha Pontos\n"
	.string "de Batalha.\p"
	.string "Se quiser parar por um tempo,\n"
	.string "salve o jogo.\p"
	.string "Se sair sem salvar, você será\n"
	.string "eliminado do desafio.$"

BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLv50:
	.string "Estes sao os resultados do último\n"
	.string "Torneio de Batalhas Individuais de\l"
	.string "Nível 50.$"

BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLv50:
	.string "Estes sao os resultados do último\n"
	.string "Torneio de Batalhas em Dupla de\l"
	.string "Nível 50.$"

BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLvOpen:
	.string "Estes sao os resultados do último\n"
	.string "Torneio de Batalhas Individuais de\l"
	.string "Nível Livre.$"

BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLvOpen:
	.string "Estes sao os resultados do último\n"
	.string "Torneio de Batalhas em Dupla de\l"
	.string "Nível Livre.$"

BattleFrontier_BattleDomeLobby_Text_LastWinnerWasTough:
	.string "Você viu o último Torneio de\n"
	.string "Batalha?\p"
	.string "{STR_VAR_1}, que ganhou, era\n"
	.string "forte demais.\p"
	.string "Dá uma olhada nos resultados no\n"
	.string "monitor ao lado do PC.$"

BattleFrontier_OutsideWest_Text_LongDreamedAboutBattleFrontier:
	.string "A BATTLE FRONTIER... Faz tempo\n"
	.string "que eu sonho com um lugar assim.$"

@ Functionally unused
BattleFrontier_OutsideWest_Text_BattleDomeSign2:
	.string "BATTLE DOME: torne-se uma estrela\n"
	.string "imbatível!$"

@ Functionally unused
BattleFrontier_OutsideWest_Text_QuestionMarkUnderConstruction:
	.string "?????? Em construçao!$"

BattleFrontier_BattleDomeLobby_Text_WinnersGainReputation:
	.string "Quem ganha vários torneios no\n"
	.string "BATTLE DOME fica conhecido como\l"
	.string "uma estrela.\p"
	.string "Essa fama atrai treinadores fortes\n"
	.string "para cá.\p"
	.string "Uma estrela de verdade consegue\n"
	.string "continuar vencendo.$"

BattleFrontier_BattleDomeLobby_Text_TrashedInFirstRound:
	.string "Enfrentei um dos favoritos logo na\n"
	.string "primeira rodada.\p"
	.string "Claro que levei uma surra...$"

BattleFrontier_BattleDomeLobby_Text_NeedToCheckOpponentCarefully:
	.string "Eu teria ganhado se tivesse\n"
	.string "deixado este Pokémon de reserva.\p"
	.string "É preciso conferir bem os Pokémon\n"
	.string "do adversário antes de escolher\l"
	.string "quem vai lutar.$"

BattleFrontier_BattleDomeLobby_Text_CongratsDefeatedTucker:
	.string "Parabéns!\p"
	.string "Você venceu o DOME ACE e ganhou o\n"
	.string "Torneio de Batalha!$"

BattleFrontier_BattleDomeLobby_Text_AwardTheseBattlePoints:
	.string "Sua estratégia foi um show! Por\n"
	.string "isso, você recebe estes Pontos de\l"
	.string "Batalha!$"

BattleFrontier_BattleDomeLobby_Text_RecordLastMatch:
	.string "Quer gravar sua última batalha do\n"
	.string "BATTLE DOME no FRONTIER PASS?$"

BattleFrontier_BattleDomeLobby_Text_RulesAreListed:
	.string "Aqui estao as regras do Torneio de\n"
	.string "Batalha.$"

BattleFrontier_BattleDomeLobby_Text_ReadWhichHeading:
	.string "Sobre o que você quer ler?$"

BattleFrontier_BattleDomeLobby_Text_ExplainMatchupRules:
	.string "Os confrontos do torneio sao\n"
	.string "definidos pela força dos Pokémon\l"
	.string "de cada treinador.\p"
	.string "Assim, os treinadores mais fortes\n"
	.string "nao se enfrentam logo de cara.$"

BattleFrontier_BattleDomeLobby_Text_ExplainTourneyTree:
	.string "Você pode ver a chave do torneio\n"
	.string "com qualquer guia na sala de\l"
	.string "espera.\p"
	.string "Ela mostra várias informaçoes.\p"
	.string "Você pode conferir os resultados\n"
	.string "do torneio anterior, os Pokémon de\l"
	.string "cada treinador e o jeito de lutar\l"
	.string "de cada um.$"

BattleFrontier_BattleDomeLobby_Text_ExplainDoubleKORules:
	.string "Se os dois Pokémon caírem ao\n"
	.string "mesmo tempo em uma partida, os\l"
	.string "JUÍZES avaliam a luta e decidem\l"
	.string "quem venceu.$"
