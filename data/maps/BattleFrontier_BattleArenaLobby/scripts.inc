BattleFrontier_BattleArenaLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaLobby_OnWarp
	.byte 0

BattleFrontier_BattleArenaLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleArenaLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleArenaLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleArenaLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown, MSGBOX_DEFAULT
	closemessage
	arena_set ARENA_DATA_WIN_STREAK, 0
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon::
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleArenaLobby_Text_RecordAchievement
	waitmessage
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave
	waitmessage
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	arena_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattleArenaLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattleArenaLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattleArenaLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame
	waitmessage
	arena_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge

BattleFrontier_BattleArenaLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARENA
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleArenaLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_OkayToSave, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	arena_init
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattleArenaLobby_Text_GuideYouToArena, MSGBOX_DEFAULT
	closemessage
	frontier_get FRONTIER_DATA_LVL_MODE
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_CORRIDOR, 9, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50::
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor
	waitmovement 0
	opendoor 2, 2
	waitdooranim
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen::
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor
	waitmovement 0
	opendoor 11, 2
	waitdooranim
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 11, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_ARENA
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_Youngster::
	msgbox BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Man::
	msgbox BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_ARENA_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_BattleRules
	case 1, BattleFrontier_BattleArenaLobby_EventScript_MindRules
	case 2, BattleFrontier_BattleArenaLobby_EventScript_SkillRules
	case 3, BattleFrontier_BattleArenaLobby_EventScript_BodyRules
	case 4, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	end

BattleFrontier_BattleArenaLobby_EventScript_BattleRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_MindRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainMindRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_SkillRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_BodyRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena:
	.string "Aqui a vontade de lutar dos\n"
	.string "treinadores é posta à prova!\p"
	.string "Boas-vindas à BATTLE ARENA!\p"
	.string "Vou te orientar no Torneio de\n"
	.string "Nocautes!$"

BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge:
	.string "Quer participar do desafio da\n"
	.string "BATTLE ARENA?$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge:
	.string "Volte quando quiser tentar de\n"
	.string "novo!$"

BattleFrontier_BattleArenaLobby_Text_ExplainChallenge:
	.string "Na BATTLE ARENA, você participa do\n"
	.string "Torneio de Nocautes.\p"
	.string "Cada participante entra com três\n"
	.string "Pokémon.\p"
	.string "Você deve escolher a ordem em que\n"
	.string "eles vao lutar antes de começar.\p"
	.string "Durante as batalhas, eles entram\n"
	.string "um por vez, na ordem escolhida.\p"
	.string "Quando um Pokémon entra, ele fica\n"
	.string "até o resultado da luta ser\l"
	.string "decidido.\p"
	.string "Se ninguém vencer em três turnos,\n"
	.string "o juiz decide o resultado.\p"
	.string "Se quiser parar o desafio por um\n"
	.string "tempo, salve o jogo.\p"
	.string "Se sair sem salvar, nao poderá\n"
	.string "continuar de onde parou.\p"
	.string "Se vencer sete treinadores\n"
	.string "seguidos, você ganha Pontos de\l"
	.string "Batalha.$"

BattleFrontier_BattleArenaLobby_Text_OkayToSave:
	.string "Antes de entrar na BATTLE ARENA,\n"
	.string "você precisa salvar. Tudo bem?$"

BattleFrontier_BattleArenaLobby_Text_WhichLevelMode:
	.string "A BATTLE ARENA tem dois desafios:\n"
	.string "Nível 50 e Nível Livre. Qual você\l"
	.string "escolhe?$"

BattleFrontier_BattleArenaLobby_Text_SelectThreeMons:
	.string "Certo, escolha seus três Pokémon.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Ei, você ainda nao tem três\n"
	.string "Pokémon que possam participar.\p"
	.string "Para entrar, precisa trazer três\n"
	.string "Pokémon de espécies diferentes.\p"
	.string "Eles também precisam estar\n"
	.string "segurando itens diferentes.\p"
	.string "OVOS{STR_VAR_1}.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsEnd:
	.string "Volte quando estiver tudo pronto.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50:
	.string "Ei, você ainda nao tem três\n"
	.string "Pokémon que possam participar.\p"
	.string "Para entrar, precisa trazer três\n"
	.string "Pokémon de espécies diferentes.\p"
	.string "Todos devem estar no nível 50 ou\n"
	.string "abaixo.\p"
	.string "Eles também precisam estar\n"
	.string "segurando itens diferentes.\p"
	.string "OVOS{STR_VAR_1}.$"

BattleFrontier_BattleArenaLobby_Text_GuideYouToArena:
	.string "Vou te levar até a BATTLE ARENA.$"

BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown:
	.string "Você desligou sem salvar o jogo,\n"
	.string "nao foi?\p"
	.string "Por isso, seu desafio foi\n"
	.string "encerrado.\p"
	.string "Mas você pode começar um novo\n"
	.string "desafio quando quiser.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins:
	.string "Parabéns pelas sete vitórias\n"
	.string "seguidas!$"

BattleFrontier_BattleArenaLobby_Text_RecordAchievement:
	.string "Vamos registrar seu resultado.\n"
	.string "Espere enquanto salvo o jogo.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_PresentYouWithPrize:
	.string "Aqui está seu prêmio pelas sete\n"
	.string "vitórias seguidas.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_ReceivedPrize:
	.string "{PLAYER} recebeu {STR_VAR_1}\n"
	.string "como prêmio.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_BagFullReturnForPrize:
	.string "Sua Bolsa está cheia.\p"
	.string "Libere um espaço e volte para\n"
	.string "pegar seu prêmio.$"

BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave:
	.string "Valeu por participar!\p"
	.string "Espere enquanto salvo o jogo.$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2:
	.string "Volte quando quiser tentar de\n"
	.string "novo!$"

BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame:
	.string "Estávamos esperando por você.\p"
	.string "Antes de te levar à BATTLE ARENA,\n"
	.string "preciso salvar o jogo. Espere um\l"
	.string "pouco.$"

BattleFrontier_BattleArenaLobby_Text_RecordLastMatch:
	.string "Quer gravar sua última batalha da\n"
	.string "BATTLE ARENA no FRONTIER PASS?$"

BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack:
	.string "Perdi na decisao do JUIZ...\p"
	.string "Acho que só usar golpes de defesa\n"
	.string "e nao atacar nao foi uma boa\l"
	.string "ideia...$"

BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked:
	.string "Ganhei na decisao do juiz!\p"
	.string "Acertar os golpes no Pokémon\n"
	.string "adversário deu certo!$"

BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw:
	.string "Nossa batalha terminou empatada.\p"
	.string "Quando o tempo acabou, meu\n"
	.string "Pokémon e o dele tinham quase a\l"
	.string "mesma quantidade de HP.$"

BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant:
	.string "Na BATTLE ARENA, a ordem dos\n"
	.string "Pokémon faz muita diferença.\p"
	.string "Por exemplo, se seu primeiro\n"
	.string "Pokémon é fraco contra certo tipo,\l"
	.string "escolha um segundo com golpes que\l"
	.string "sejam supereficazes contra o\l"
	.string "primeiro.\p"
	.string "Acho que isso ajuda a montar uma\n"
	.string "boa equipe.$"

BattleFrontier_BattleArenaLobby_Text_RulesAreListed:
	.string "Aqui estao as regras do Torneio de\n"
	.string "Nocautes.$"

BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading:
	.string "Sobre o que você quer ler?$"

BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules:
	.string "O Torneio de Nocautes tem regras\n"
	.string "próprias.\p"
	.string "Para começar, cada luta dura só\n"
	.string "três turnos.\p"
	.string "Se ninguém vencer nesse tempo, o\n"
	.string "juiz decide o resultado.\p"
	.string "O JUIZ escolhe quem venceu com\n"
	.string "base no que cada Pokémon fez na\l"
	.string "batalha.\p"
	.string "Além disso, você nao pode trocar\n"
	.string "de Pokémon até o resultado da\l"
	.string "luta ser decidido.$"

BattleFrontier_BattleArenaLobby_Text_ExplainMindRules:
	.string "O primeiro ponto avaliado é a\n"
	.string "Atitude. Ele mostra o quanto cada\l"
	.string "lado partiu para o ataque.\p"
	.string "O juiz leva em conta quantas\n"
	.string "vezes o treinador mandou usar\l"
	.string "golpes de ataque.$"

BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules:
	.string "O segundo ponto avaliado é a\n"
	.string "Técnica. Ele mede o quanto os\l"
	.string "golpes deram certo.\p"
	.string "Quando um golpe funciona, a nota\n"
	.string "sobe.\p"
	.string "Quando falha, a nota cai.\p"
	.string "No caso de ataques, a nota sobe\n"
	.string "se o golpe for supereficaz e cai\l"
	.string "se for pouco eficaz.\p"
	.string "Golpes como PROTECT e DETECT nao\n"
	.string "aumentam a nota.\p"
	.string "Se o adversário usar PROTECT ou\n"
	.string "DETECT e impedir seu ataque, sua\l"
	.string "nota nao cai.$"

BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules:
	.string "O terceiro ponto avaliado é o\n"
	.string "Corpo. Ele leva em conta o HP que\l"
	.string "sobrou no fim da luta.\p"
	.string "O juiz compara o HP que o Pokémon\n"
	.string "tinha no começo com o que restou\l"
	.string "no final.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon:
	.string "Você venceu a ARENA TYCOON e\n"
	.string "completou sete vitórias seguidas!\p"
	.string "Parabéns por esse grande\n"
	.string "resultado!$"

BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints:
	.string "Pela sua garra, receba estes\n"
	.string "Pontos de Batalha!$"
