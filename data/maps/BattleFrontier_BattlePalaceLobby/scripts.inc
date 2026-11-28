BattleFrontier_BattlePalaceLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceLobby_OnWarp
	.byte 0

BattleFrontier_BattlePalaceLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePalaceLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge, MSGBOX_DEFAULT
	closemessage
	palace_set PALACE_DATA_WIN_STREAK, 0
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven
	msgbox BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded
	waitmessage
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded
	waitmessage
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	palace_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting, MSGBOX_DEFAULT
	message BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge
	waitmessage
	palace_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge

BattleFrontier_BattlePalaceLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
	end

BattleFrontier_BattlePalaceLobby_EventScript_DoublesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
	end

BattleFrontier_BattlePalaceLobby_EventScript_Attendant::
	palace_get PALACE_DATA_PRIZE
	goto_if_ne VAR_RESULT, ITEM_NONE, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle
BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_WhichChallenge
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	palace_init
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePalaceLobby_Text_FollowMe, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_CORRIDOR, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge::
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative LoadPlayerParty
BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge
	return

BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor
	waitdooranim
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor
	waitdooranim
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_PALACE_ATTENDANT_SINGLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_PALACE_ATTENDANT_DOUBLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor::
	opendoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor::
	opendoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor::
	closedoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor::
	closedoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor:
	walk_up
	step_end

BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_BlackBelt::
	msgbox BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Man::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Beauty::
	msgbox BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Maniac::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 16, 0, MULTI_BATTLE_PALACE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_RulesNature
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves
	case 3, BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered
	case 4, BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger
	case 5, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesNature::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle:
	.string "Aqui o coraçao dos treinadores é\n"
	.string "posto à prova.\p"
	.string "Boas-vindas ao BATTLE PALACE.\p"
	.string "Recebo as inscriçoes para os\n"
	.string "Saloes de Batalhas Individuais.$"

BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge:
	.string "Quer participar do desafio do Salao\n"
	.string "de Batalhas Individuais?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge:
	.string "No BATTLE PALACE, temos vários\n"
	.string "espaços chamados Saloes de\l"
	.string "Batalhas Individuais.\p"
	.string "As batalhas individuais seguem as\n"
	.string "regras normais, com uma diferença\l"
	.string "importante.\p"
	.string "Você só pode trocar seus Pokémon\n"
	.string "durante a luta.\p"
	.string "Nao pode dar nenhuma outra ordem.\p"
	.string "Os Pokémon escolhem como lutar de\n"
	.string "acordo com sua natureza.\p"
	.string "Você precisa confiar neles e\n"
	.string "acompanhar a batalha.\p"
	.string "Se vencer sete treinadores\n"
	.string "seguidos, ganha Pontos de Batalha.\p"
	.string "Se quiser parar por um tempo,\n"
	.string "salve o jogo.\p"
	.string "Se sair sem salvar, você será\n"
	.string "eliminado do desafio.$"

BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified:
	.string "Volte quando você e seus Pokémon\n"
	.string "estiverem prontos.$"

BattleFrontier_BattlePalaceLobby_Text_WhichChallenge:
	.string "Há dois desafios nos Saloes de\n"
	.string "Batalha: Nível 50 e Nível Livre.\l"
	.string "Qual você escolhe?$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50:
	.string "Ah...\p"
	.string "Você nao tem os três Pokémon\n"
	.string "necessários para o desafio.\p"
	.string "Precisa trazer três Pokémon de\n"
	.string "espécies diferentes.\p"
	.string "Todos devem estar no nível 50 ou\n"
	.string "abaixo.\p"
	.string "Eles também precisam estar\n"
	.string "segurando itens diferentes.\p"
	.string "OVOS{STR_VAR_1}.$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsEnd:
	.string "Volte quando estiver tudo pronto.$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Ah...\p"
	.string "Você nao tem os três Pokémon\n"
	.string "necessários para o desafio.\p"
	.string "Precisa trazer três Pokémon de\n"
	.string "espécies diferentes.\p"
	.string "Eles também precisam estar\n"
	.string "segurando itens diferentes.\p"
	.string "OVOS{STR_VAR_1}.$"

BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons:
	.string "Certo. Agora escolha seus três\n"
	.string "Pokémon.$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2:
	.string "Preciso salvar antes de te levar\n"
	.string "ao Salao de Batalha. Tudo bem?$"

BattleFrontier_BattlePalaceLobby_Text_FollowMe:
	.string "Certo. Venha comigo.$"

BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded:
	.string "Foi um prazer ver seus Pokémon em\n"
	.string "açao.\p"
	.string "Vamos registrar os resultados.\n"
	.string "Espere um pouco.$"

BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak:
	.string "Sete vitórias seguidas...\p"
	.string "A confiança entre você e seus\n"
	.string "Pokémon parece forte e verdadeira.$"

BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded:
	.string "Vou registrar esse resultado.\n"
	.string "Espere um pouco.$"

@ Unused
BattleFrontier_BattlePalaceLobby_Text_BattlePointsFor7WinStreak:
	.string "Pelas sete vitórias seguidas, você\n"
	.string "recebe estes Pontos de Batalha.$"

BattleFrontier_BattlePalaceLobby_Text_NoSpaceForPrize:
	.string "Parece que nao há espaço para o\n"
	.string "prêmio.\p"
	.string "Organize sua Bolsa e volte depois.$"

BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting:
	.string "Estávamos esperando por você...$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge:
	.string "Preciso salvar antes de te levar\n"
	.string "ao Salao de Batalha. Tudo bem?$"

BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge:
	.string "Ah...\p"
	.string "Da última vez, você saiu do\n"
	.string "desafio sem salvar.\p"
	.string "Por isso, seu desafio foi\n"
	.string "encerrado. Que pena.$"

@ Unused
BattleFrontier_BattlePalaceLobby_Text_ReceivedPrize:
	.string "{PLAYER} recebeu {STR_VAR_1}\n"
	.string "como prêmio.$"

BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink:
	.string "Pra alguém firme como eu, os\n"
	.string "melhores Pokémon sao os de\l"
	.string "natureza Hardy.\p"
	.string "O ataque é a melhor defesa! Tem\n"
	.string "que atacar sem parar!\p"
	.string "Mas nao era disso que eu queria\n"
	.string "falar.\p"
	.string "De vez em quando, uma moça muito\n"
	.string "bonita passa aqui.\p"
	.string "Ela diz que entende o que os\n"
	.string "Pokémon pensam.\p"
	.string "Nao sei se isso é verdade, mas\n"
	.string "bonita ela é.\p"
	.string "Ué? Por que está me olhando assim?$"

BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere:
	.string "Hum...\p"
	.string "Parece que a natureza dos Pokémon\n"
	.string "e os golpes que eles aprenderam\l"
	.string "sao a chave das batalhas daqui.\p"
	.string "Mais exatamente, o quanto os\n"
	.string "golpes combinam com a natureza\l"
	.string "deles.\p"
	.string "Se seu Pokémon nao consegue\n"
	.string "mostrar o que sabe, talvez você\l"
	.string "deva conferir se os golpes\l"
	.string "combinam com a natureza dele.$"

BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms:
	.string "Meu Pokémon costuma ser bem\n"
	.string "calminho.\p"
	.string "Mas no Salao de Batalha, às vezes\n"
	.string "parece que vira uma fera!\p"
	.string "Fica assustador. Dá até um choque\n"
	.string "ver aquilo.$"

BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway:
	.string "Que natureza teria um Pokémon que\n"
	.string "gosta de enfraquecer o adversário\l"
	.string "e vencer aos poucos?\p"
	.string "Eu ficaria surpreso se fosse Lax.\p"
	.string "Mas nao, nao deve ser isso.$"

BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle:
	.string "Aqui o coraçao dos treinadores é\n"
	.string "posto à prova.\p"
	.string "Boas-vindas ao BATTLE PALACE.\p"
	.string "Recebo as inscriçoes para os\n"
	.string "Saloes de Batalhas em Dupla.$"

BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge:
	.string "Quer participar do desafio do Salao\n"
	.string "de Batalhas em Dupla?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge:
	.string "No BATTLE PALACE, temos vários\n"
	.string "espaços chamados Saloes de\l"
	.string "Batalhas em Dupla.\p"
	.string "As batalhas em dupla seguem as\n"
	.string "regras normais, com uma diferença\l"
	.string "importante.\p"
	.string "Você só pode trocar seus Pokémon\n"
	.string "durante a luta.\p"
	.string "Nao pode dar nenhuma outra ordem.\p"
	.string "Os Pokémon escolhem como lutar de\n"
	.string "acordo com sua natureza.\p"
	.string "Você precisa confiar neles e\n"
	.string "acompanhar a batalha.\p"
	.string "Se vencer sete treinadores\n"
	.string "seguidos, ganha Pontos de Batalha.\p"
	.string "Se quiser parar por um tempo,\n"
	.string "salve o jogo.\p"
	.string "Se sair sem salvar, você será\n"
	.string "eliminado do desafio.$"

BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers:
	.string "Vencer o PALACE MAVEN e completar\n"
	.string "sete vitórias seguidas...$"

BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints:
	.string "Pela ligaçao que você tem com seus\n"
	.string "Pokémon, receba estes Pontos de\l"
	.string "Batalha.$"

BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch:
	.string "Quer gravar sua última batalha do\n"
	.string "BATTLE PALACE no FRONTIER PASS?$"

BattleFrontier_BattlePalaceLobby_Text_RulesAreListed:
	.string "Aqui estao as regras dos Saloes de\n"
	.string "Batalha.$"

BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading:
	.string "Sobre o que você quer ler?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics:
	.string "Aqui os Pokémon precisam pensar e\n"
	.string "lutar sozinhos.\p"
	.string "Ao contrário dos selvagens, os\n"
	.string "Pokémon que vivem com pessoas\l"
	.string "agem de formas diferentes de\l"
	.string "acordo com sua natureza.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature:
	.string "Dependendo da natureza, um\n"
	.string "Pokémon pode querer atacar a\l"
	.string "qualquer custo.\p"
	.string "Outro pode preferir se proteger de\n"
	.string "todo perigo.\p"
	.string "E outro pode gostar de atrapalhar\n"
	.string "ou confundir o adversário.\p"
	.string "Por causa da natureza, cada\n"
	.string "Pokémon tem golpes favoritos que\l"
	.string "usa bem.\p"
	.string "Também pode ter dificuldade com\n"
	.string "golpes de que nao gosta.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves:
	.string "Existem golpes de ataque, que\n"
	.string "causam dano direto ao adversário.\p"
	.string "Há golpes de defesa, que ajudam a\n"
	.string "se preparar para ataques ou a\l"
	.string "recuperar HP.\p"
	.string "E há outros golpes que\n"
	.string "enfraquecem o adversário com\l"
	.string "problemas como veneno e paralisia.\p"
	.string "Os Pokémon escolhem entre esses\n"
	.string "três tipos de golpes.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered:
	.string "Sem as ordens do treinador, um\n"
	.string "Pokémon pode ter dificuldade para\l"
	.string "usar certos golpes.\p"
	.string "Ele nao usa bem os golpes de que\n"
	.string "nao gosta.\p"
	.string "Se só conhecer golpes que nao\n"
	.string "combinam com sua natureza, muitas\l"
	.string "vezes nao vai conseguir mostrar\l"
	.string "sua força.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger:
	.string "Dependendo da natureza, um\n"
	.string "Pokémon pode começar a usar\l"
	.string "golpes fora do seu costume quando\l"
	.string "está em apuros.\p"
	.string "Se ele mudar de comportamento\n"
	.string "numa situaçao difícil, observe com\l"
	.string "atençao.$"

