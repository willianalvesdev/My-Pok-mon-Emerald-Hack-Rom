BattleFrontier_BattleFactoryLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryLobby_OnWarp
	.byte 0

BattleFrontier_BattleFactoryLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleFactoryLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	factory_setswapped
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS, 0
	factory_set FACTORY_DATA_WIN_STREAK, 0
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
	factory_save 0
	playse SE_SAVE
	waitse
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle
	end

BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	factory_save 0
	playse SE_SAVE
	waitse

BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle::
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
	message BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle

BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume
	waitmessage
	factory_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	setvar VAR_0x8006, 2
	goto BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge

BattleFrontier_BattleFactoryLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
	end

BattleFrontier_BattleFactoryLobby_EventScript_DoublesAttendant::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
	end

BattleFrontier_BattleFactoryLobby_EventScript_Attendant::
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle
BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	factory_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed
	setvar VAR_0x8006, 0
BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	msgbox BattleFrontier_BattleFactoryLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor
	waitmovement 0
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_SINGLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_DOUBLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor:
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Picnicker::
	lock
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle:
	.string "Aqui o conhecimento dos\n"
	.string "treinadores é posto à prova!\p"
	.string "Boas-vindas à BATTLE FACTORY!\p"
	.string "Vou te orientar no Desafio de\n"
	.string "Trocas Individual.$"

BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge:
	.string "Quer participar do Desafio de\n"
	.string "Trocas Individual?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge:
	.string "O Desafio de Trocas Individual tem\n"
	.string "batalhas individuais só com\l"
	.string "Pokémon de aluguel.\p"
	.string "Primeiro, você recebe três Pokémon\n"
	.string "emprestados para o desafio.\p"
	.string "Você vai usá-los em batalhas\n"
	.string "individuais.\p"
	.string "Se ganhar, pode trocar um dos seus\n"
	.string "Pokémon de aluguel.\p"
	.string "Continue lutando e fazendo trocas.\n"
	.string "Se vencer sete vezes seguidas,\l"
	.string "ganha Pontos de Batalha.\p"
	.string "Se quiser parar por um tempo,\n"
	.string "salve o jogo.\p"
	.string "Se sair sem salvar, você será\n"
	.string "eliminado do desafio.$"

BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit:
	.string "Esperamos sua próxima visita.$"

BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode:
	.string "Qual desafio você quer? Nível 50\n"
	.string "ou Nível Livre?$"

BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge:
	.string "Antes de começar o desafio,\n"
	.string "preciso salvar o jogo. Tudo bem?$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_WillHoldMonsForSafekeeping:
	.string "Certo, vou guardar seus Pokémon\n"
	.string "enquanto você participa.$"

BattleFrontier_BattleFactoryLobby_Text_StepThisWay:
	.string "Pode vir por aqui.$"

BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults:
	.string "Valeu por participar!\p"
	.string "Vou devolver seus Pokémon e\n"
	.string "recolher os de aluguel.\p"
	.string "Também preciso salvar os\n"
	.string "resultados. Espere um pouco.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReturnMons:
	.string "Vou devolver seus Pokémon e\n"
	.string "recolher os de aluguel.$"

BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins:
	.string "Parabéns! Você ganhou sete\n"
	.string "batalhas seguidas no Desafio de\l"
	.string "Trocas!$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePointsForStreak:
	.string "Pelas sete vitórias seguidas, você\n"
	.string "recebe estes Pontos de Batalha.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_MaxBattlePoints:
	.string "Opa, opa!\p"
	.string "Você já atingiu o limite de Pontos\n"
	.string "de Batalha.\p"
	.string "Gaste alguns pontos e volte\n"
	.string "depois.$"

BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume:
	.string "Estávamos esperando por você!\p"
	.string "Antes de continuar seu desafio,\n"
	.string "preciso salvar o jogo.$"

BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting:
	.string "Você saiu sem salvar da última\n"
	.string "vez.\p"
	.string "Por isso, seu desafio foi\n"
	.string "encerrado.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_WellReturnMons:
	.string "Vamos devolver seus Pokémon.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReceivedPrizeItem:
	.string "{PLAYER} recebeu {STR_VAR_1}\n"
	.string "como prêmio.$"

BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle:
	.string "Aqui o conhecimento dos\n"
	.string "treinadores é posto à prova!\p"
	.string "Boas-vindas à BATTLE FACTORY!\p"
	.string "Vou te orientar no Desafio de\n"
	.string "Trocas em Dupla.$"

BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge:
	.string "Quer participar do Desafio de\n"
	.string "Trocas em Dupla?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge:
	.string "O Desafio de Trocas em Dupla tem\n"
	.string "batalhas em dupla só com Pokémon\l"
	.string "de aluguel.\p"
	.string "Primeiro, você recebe três Pokémon\n"
	.string "emprestados para o desafio.\p"
	.string "Você vai usá-los em batalhas em\n"
	.string "dupla.\p"
	.string "Se ganhar, pode trocar um dos seus\n"
	.string "Pokémon de aluguel.\p"
	.string "Continue lutando e fazendo trocas.\n"
	.string "Se vencer sete vezes seguidas,\l"
	.string "ganha Pontos de Batalha.\p"
	.string "Se quiser parar por um tempo,\n"
	.string "salve o jogo.\p"
	.string "Se sair sem salvar, você será\n"
	.string "eliminado do desafio.$"

BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead:
	.string "Parabéns por vencer o FACTORY\n"
	.string "HEAD e ganhar sete batalhas\l"
	.string "seguidas!$"

BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints:
	.string "Pelo seu conhecimento e pelas boas\n"
	.string "decisoes, você recebe estes Pontos\l"
	.string "de Batalha.$"

BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave:
	.string "Vou devolver seus Pokémon e\n"
	.string "recolher os de aluguel.\p"
	.string "Preciso salvar os dados das\n"
	.string "batalhas, entao espere um pouco.$"

BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch:
	.string "Quer gravar sua última batalha da\n"
	.string "BATTLE FACTORY no FRONTIER PASS?$"

BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves:
	.string "Ei, você!\p"
	.string "Está achando que aqui é fácil\n"
	.string "porque nao precisa treinar sua\l"
	.string "própria equipe?\p"
	.string "Eu nao contaria com uma vitória\n"
	.string "tao fácil.\p"
	.string "Sem conhecer bem os Pokémon e\n"
	.string "seus golpes, vai ser difícil\l"
	.string "continuar ganhando.$"

BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon:
	.string "Troquei por um Pokémon fraco...\n"
	.string "Achei que ele seria bom pra\l"
	.string "equipe...\p"
	.string "Acabaram com a gente...$"

BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons:
	.string "Nada tem dado certo pra mim.\p"
	.string "Durante a batalha, você precisa\n"
	.string "observar os Pokémon do adversário\l"
	.string "pra ver se eles sao bons.$"

BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints:
	.string "Sabe aquelas dicas que os\n"
	.string "funcionários dao sobre o próximo\l"
	.string "adversário?\p"
	.string "Sou um homem adulto, mas tenho\n"
	.string "dificuldade pra entender o que\l"
	.string "eles querem dizer.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_RentalMonsAreVaried:
	.string "Eu sou forte, mas enjoo fácil das\n"
	.string "coisas, entao fiquei trocando e\l"
	.string "batalhando sem parar.\p"
	.string "De tanto participar do Desafio de\n"
	.string "Trocas, percebi que os Pokémon de\l"
	.string "aluguel mudavam.$"

BattleFrontier_BattleFactoryLobby_Text_RulesAreListed:
	.string "Aqui estao as regras do Desafio de\n"
	.string "Trocas.$"

BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading:
	.string "Sobre o que você quer ler?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules:
	.string "No Desafio de Trocas, você só pode\n"
	.string "usar três Pokémon.\p"
	.string "Ao alugar ou trocar, sua equipe\n"
	.string "nao pode ficar com dois Pokémon da\l"
	.string "mesma espécie.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules:
	.string "Você só pode trocar Pokémon com o\n"
	.string "treinador que acabou de vencer.\p"
	.string "E só pode receber um dos Pokémon\n"
	.string "que ele usou.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules:
	.string "Depois de cada vitória, você pode\n"
	.string "trocar por um dos Pokémon do\l"
	.string "adversário.\p"
	.string "Nao é possível fazer uma troca\n"
	.string "com o sétimo treinador do desafio.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules:
	.string "Há duas coisas importantes sobre\n"
	.string "as trocas.\p"
	.string "Primeiro, você nao pode conferir os\n"
	.string "atributos do Pokémon que vai\l"
	.string "receber.\p"
	.string "Segundo, os Pokémon ficam na\n"
	.string "equipe na ordem em que você os\l"
	.string "alugou.\p"
	.string "Essa ordem continua a mesma depois\n"
	.string "das trocas.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules:
	.string "No Nível Livre, os Pokémon de\n"
	.string "aluguel e os dos adversários estao\l"
	.string "todos no nível 100.$"
