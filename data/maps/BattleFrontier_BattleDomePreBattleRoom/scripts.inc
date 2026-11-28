BattleFrontier_BattleDomePreBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomePreBattleRoom_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomePreBattleRoom_OnWarp
	.byte 0

BattleFrontier_BattleDomePreBattleRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleDomePreBattleRoom_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleDomePreBattleRoom_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_EnterRoom
	.2byte 0

BattleFrontier_BattleDomePreBattleRoom_EventScript_EnterRoom::
	goto_if_eq VAR_0x8006, 1, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReturnFromBattle
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomePreBattleRoom_Movement_PlayerEnter
	waitmovement 0
	lockall
BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound::
	call BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForNextRoundMessage
	waitmessage
	switch VAR_RESULT  @ No case?
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRoundNoRecord
	multichoice 16, 0, MULTI_TOURNEY_WITH_RECORD, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowOpponentInfo
	case 1, BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowTourneyTree
	case 2, BattleFrontier_BattleDomePreBattleRoom_EventScript_ContinueChallenge
	case 3, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskRecordBattle
	case 4, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskPauseChallenge
	case 5, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound

BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRoundNoRecord::
	multichoice 16, 2, MULTI_TOURNEY_NO_RECORD, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowOpponentInfo
	case 1, BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowTourneyTree
	case 2, BattleFrontier_BattleDomePreBattleRoom_EventScript_ContinueChallenge
	case 3, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskPauseChallenge
	case 4, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound

BattleFrontier_BattleDomePreBattleRoom_EventScript_AskRecordBattle::
	message BattleFrontier_BattleDomePreBattleRoom_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
	case 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_RecordBattle
	case MULTI_B_PRESSED, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound

BattleFrontier_BattleDomePreBattleRoom_EventScript_RecordBattle::
	call BattleFrontier_EventScript_SaveBattle
	goto BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound

BattleFrontier_BattleDomePreBattleRoom_EventScript_AskPauseChallenge::
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
	case YES, BattleFrontier_BattleDomePreBattleRoom_EventScript_PauseChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound

BattleFrontier_BattleDomePreBattleRoom_EventScript_AskRetireChallenge::
	message BattleFrontier_BattleDomePreBattleRoom_Text_RetireYourChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
	case 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_RetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound

BattleFrontier_BattleDomePreBattleRoom_EventScript_RetireChallenge::
	dome_resolvewinners DOME_PLAYER_RETIRED
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobbyLost

BattleFrontier_BattleDomePreBattleRoom_EventScript_PauseChallenge::
	message BattleFrontier_BattleDomePreBattleRoom_Text_SavingDataPleaseWait
	waitmessage
	dome_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowOpponentInfo::
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_PlayersNextOpponentIsTrainer, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	dome_showopponentinfo
	waitstate
	goto BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound

BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowTourneyTree::
	call BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowRoundMessage
	fadescreen FADE_TO_BLACK
	dome_showtourneytree
	waitstate
	goto BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound

BattleFrontier_BattleDomePreBattleRoom_EventScript_ShowRoundMessage::
	frontier_get FRONTIER_DATA_BATTLE_NUM
	switch VAR_RESULT
	case DOME_ROUND1, BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInRound1
	case DOME_ROUND2, BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInRound2
	case DOME_SEMIFINAL, BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInSemifinals
	case DOME_FINAL, BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInFinals
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInRound1::
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInRound1, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInRound2::
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInRound2, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInSemifinals::
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInSemifinals, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_TourneyInFinals::
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInFinals, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_ContinueChallenge::
	message BattleFrontier_BattleDomePreBattleRoom_Text_ChooseTwoMons
	waitmessage
	waitbuttonpress
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, DOME_BATTLE_PARTY_SIZE  @ 2 of the 3 party mons are selected for battle
	special ChoosePartyForBattleFrontier
	frontier_resetsketch
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound
	dome_set DOME_DATA_SELECTED_MONS
	dome_reduceparty
	dome_setopponent
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOME_PRE_BATTLE_ATTENDANT, BattleFrontier_BattleDomePreBattleRoom_Movement_AttendantMoveAside
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomePreBattleRoom_Movement_PlayerWalkToDoor
	waitmovement 0
	opendoor 5, 1
	waitdooranim
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomePreBattleRoom_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 5, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_BATTLE_ROOM, 9, 5
	setvar VAR_TEMP_0, 0
	waitstate
	end

BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForNextRoundMessage::
	frontier_get FRONTIER_DATA_BATTLE_NUM
	switch VAR_RESULT
	case DOME_ROUND1, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForRound1
	case DOME_ROUND2, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForRound2
	case DOME_SEMIFINAL, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForSemifinals
	case DOME_FINAL, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForFinals
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForRound1::
	message BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForRound1
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForRound2::
	message BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForRound2
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForSemifinals::
	message BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForSemifinals
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForFinals::
	frontier_getbrainstatus
	switch VAR_RESULT
	case FRONTIER_BRAIN_SILVER, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerSilver
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerGold
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerSilver
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerGold
	message BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForFinals
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerSilver::
	goto_if_set FLAG_TEMP_1, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerSilverShort
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerSilver, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerGold::
	goto_if_set FLAG_TEMP_1, BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerGoldShort
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerGold, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerSilverShort::
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerSilverShort, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_ReadyForTuckerGoldShort::
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerGoldShort, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_ReturnFromBattle::
	setvar VAR_TEMP_0, 1
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_RestoreMonsToFullHealth, MSGBOX_DEFAULT
	special LoadPlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	call BattleFrontier_BattleDomePreBattleRoom_EventScript_RoundCompleteMessage
	fadescreen FADE_TO_BLACK
	dome_showstatictourneytree
	waitstate
	goto BattleFrontier_BattleDomePreBattleRoom_EventScript_AskReadyForNextRound

BattleFrontier_BattleDomePreBattleRoom_EventScript_RoundCompleteMessage::
	frontier_get FRONTIER_DATA_BATTLE_NUM
	switch VAR_RESULT
	case DOME_ROUND2, BattleFrontier_BattleDomePreBattleRoom_EventScript_Round1Complete
	case DOME_SEMIFINAL, BattleFrontier_BattleDomePreBattleRoom_EventScript_Round2Complete
	case DOME_FINAL, BattleFrontier_BattleDomePreBattleRoom_EventScript_SemifinalsComplete
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_Round1Complete::
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_Round1Complete, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_Round2Complete::
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_Round2Complete, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_SemifinalsComplete::
	msgbox BattleFrontier_BattleDomePreBattleRoom_Text_SemifinalsComplete, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomePreBattleRoom_Movement_AttendantMoveAside:
	walk_right
	face_left
	step_end

BattleFrontier_BattleDomePreBattleRoom_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleDomePreBattleRoom_Movement_PlayerWalkToDoor:
	walk_up
	step_end

BattleFrontier_BattleDomePreBattleRoom_Movement_PlayerEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForRound1:
	.string "Sua partida da primeira rodada é a\n"
	.string "próxima. Tudo pronto?$"

BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForRound2:
	.string "Sua partida da segunda rodada é a\n"
	.string "próxima. Tudo pronto?$"

BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForSemifinals:
	.string "Sua semifinal é a próxima. Tudo\n"
	.string "pronto?$"

BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForFinals:
	.string "Sua final é a próxima. Tudo\n"
	.string "pronto?$"

BattleFrontier_BattleDomePreBattleRoom_Text_ChooseTwoMons:
	.string "Escolha os dois Pokémon que vao\n"
	.string "lutar.$"

BattleFrontier_BattleDomePreBattleRoom_Text_RightThisWay:
	.string "Por aqui, por favor.$"

BattleFrontier_BattleDomePreBattleRoom_Text_RestoreMonsToFullHealth:
	.string "Valeu por participar!\p"
	.string "Vou recuperar seus Pokémon.$"

BattleFrontier_BattleDomePreBattleRoom_Text_Round1Complete:
	.string "Todas as partidas da primeira\n"
	.string "rodada terminaram.\p"
	.string "Estas sao as equipes que\n"
	.string "passaram!$"

BattleFrontier_BattleDomePreBattleRoom_Text_Round2Complete:
	.string "Todas as partidas da segunda\n"
	.string "rodada terminaram.\p"
	.string "Estas sao as equipes que\n"
	.string "passaram!$"

BattleFrontier_BattleDomePreBattleRoom_Text_SemifinalsComplete:
	.string "Todas as semifinais terminaram.\p"
	.string "Estas sao as equipes que\n"
	.string "passaram!$"

@ Unused
BattleFrontier_BattleDomePreBattleRoom_Text_CongratsReadyForRound2:
	.string "Parabéns por passar da primeira\n"
	.string "rodada.\p"
	.string "A segunda é a próxima. Tudo\n"
	.string "pronto?$"

@ Unused
BattleFrontier_BattleDomePreBattleRoom_Text_CongratsReadyForSemifinals:
	.string "Parabéns por chegar à semifinal.\p"
	.string "As quatro melhores equipes se\n"
	.string "enfrentam agora. Tudo pronto?$"

@ Unused
BattleFrontier_BattleDomePreBattleRoom_Text_CongratsReadyForFinals:
	.string "Parabéns por chegar à final.\p"
	.string "Falta só uma vitória para o\n"
	.string "título. Tudo pronto?$"

BattleFrontier_BattleDomePreBattleRoom_Text_PlayersNextOpponentIsTrainer:
	.string "Este treinador é o próximo\n"
	.string "adversário de {PLAYER}.$"

BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInRound1:
	.string "O torneio está na primeira rodada.$"

BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInRound2:
	.string "O torneio está na segunda rodada.$"

BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInSemifinals:
	.string "O torneio está nas semifinais.$"

BattleFrontier_BattleDomePreBattleRoom_Text_TourneyInFinals:
	.string "O torneio está na final.$"

BattleFrontier_BattleDomePreBattleRoom_Text_SaveAndQuitGame:
	.string "Quer salvar e sair do jogo?$"

BattleFrontier_BattleDomePreBattleRoom_Text_RetireYourChallenge:
	.string "Quer desistir do Torneio de\n"
	.string "Batalha?$"

BattleFrontier_BattleDomePreBattleRoom_Text_SavingDataPleaseWait:
	.string "Estou salvando seu jogo. Espere\n"
	.string "um pouco.$"

BattleFrontier_BattleDomePreBattleRoom_Text_RecordLastMatch:
	.string "Quer gravar sua última partida no\n"
	.string "FRONTIER PASS?$"

BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerSilver:
	.string "Parabéns por chegar à final.\p"
	.string "Nela, você vai enfrentar TUCKER, o\n"
	.string "DOME ACE.\p"
	.string "Tudo pronto?$"

@ Identical to ReadyForTuckerSilver
BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerGold:
	.string "Parabéns por chegar à final.\p"
	.string "Nela, você vai enfrentar TUCKER, o\n"
	.string "DOME ACE.\p"
	.string "Tudo pronto?$"

BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerSilverShort:
	.string "Sua final contra TUCKER é a\n"
	.string "próxima. Tudo pronto?$"

@ Identical again
BattleFrontier_BattleDomePreBattleRoom_Text_ReadyForTuckerGoldShort:
	.string "Sua final contra TUCKER é a\n"
	.string "próxima. Tudo pronto?$"

