BattleFrontier_BattlePikeLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeLobby_OnWarp
	.byte 0

BattleFrontier_BattlePikeLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePikeLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePikeLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePikeLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving::
	special HealPlayerParty
	pike_resethelditems
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	pike_set PIKE_DATA_WIN_STREAK, 0
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen
	msgbox BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen::
	msgbox BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	frontier_checkairshow
	pike_get PIKE_DATA_TOTAL_STREAKS
	addvar VAR_RESULT, 1
	pike_set PIKE_DATA_TOTAL_STREAKS, VAR_RESULT
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	pike_resethelditems
	message BattleFrontier_BattlePikeLobby_Text_ShallRecordResults
	waitmessage
	pike_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults
	waitmessage
	frontier_checkairshow
	frontier_set FRONTIER_DATA_BATTLE_NUM, 0
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	pike_resethelditems
	pike_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PIKE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike, MSGBOX_DEFAULT
BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattlePikeLobby_Text_TakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_1, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pike_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, TRUE
	pike_savehelditems
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	pike_savehelditems
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_CancelChallengeSaveFailed
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePikeLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	frontier_settrainers
	call BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor
	special HealPlayerParty
	call BattleFrontier_BattlePike_EventScript_CloseCurtain
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_CORRIDOR, 6, 7
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePikeLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_PIKE
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor::
	applymovement LOCALID_PIKE_LOBBY_ATTENDANT, BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor
	waitmovement 0
	return

BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor:
	walk_up
BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePikeLobby_EventScript_Hiker::
	msgbox BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Twin::
	msgbox BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Beauty::
	msgbox BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 16, 4, MULTI_BATTLE_PIKE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag
	case 1, BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems
	case 2, BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder
	case 3, BattleFrontier_BattlePikeLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePike_EventScript_CloseCurtain::
	playse SE_PIKE_CURTAIN_CLOSE
	special CloseBattlePikeCurtain
	waitse
	return

BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike:
	.string "Aqui a sorte dos treinadores é\n"
	.string "posta à prova...\p"
	.string "Boas-vindas ao BATTLE PIKE...\p"
	.string "Vou te orientar por aqui...$"

BattleFrontier_BattlePikeLobby_Text_TakeChallenge:
	.string "Quer participar do Desafio dos\n"
	.string "Caminhos?$"

BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike:
	.string "Aqui temos o Desafio dos Caminhos.\p"
	.string "As regras sao bem simples...\p"
	.string "Escolha um dos três caminhos e\n"
	.string "chegue à última sala do BATTLE\l"
	.string "PIKE. É só isso.\p"
	.string "Mas o que acontece pelo caminho\n"
	.string "depende totalmente da sua sorte...\p"
	.string "Se chegar ao fim, ganha Pontos de\n"
	.string "Batalha.\p"
	.string "Se quiser parar por um tempo, fale\n"
	.string "com um funcionário nas salas\l"
	.string "grandes pelo caminho.\p"
	.string "Se sair sem salvar, você será\n"
	.string "eliminado do desafio.$"

BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou:
	.string "Esperamos te ver de novo...$"

BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode:
	.string "Você pode escolher entre Nível 50\n"
	.string "e Nível Livre. Qual desafio vai\l"
	.string "encarar?$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50:
	.string "Desculpe, mas...\p"
	.string "Você nao tem três Pokémon que\n"
	.string "possam participar do Desafio dos\l"
	.string "Caminhos.\p"
	.string "Precisa trazer três Pokémon de\n"
	.string "espécies diferentes, no nível 50\l"
	.string "ou abaixo.\p"
	.string "Eles também precisam estar\n"
	.string "segurando itens diferentes.\p"
	.string "OVOS{STR_VAR_1}.$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsEnd:
	.string "Volte quando estiver tudo\n"
	.string "pronto...$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Desculpe, mas...\p"
	.string "Você nao tem três Pokémon que\n"
	.string "possam participar do Desafio dos\l"
	.string "Caminhos.\p"
	.string "Precisa trazer três Pokémon de\n"
	.string "espécies diferentes.\p"
	.string "Eles também precisam estar\n"
	.string "segurando itens diferentes.\p"
	.string "OVOS{STR_VAR_1}.$"

BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons:
	.string "Escolha os três Pokémon que vao\n"
	.string "participar do desafio...$"

BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge:
	.string "Antes de começar o Desafio dos\n"
	.string "Caminhos, preciso salvar o jogo.\l"
	.string "Tudo bem?$"

BattleFrontier_BattlePikeLobby_Text_StepThisWay:
	.string "Pode vir por aqui...$"

BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults:
	.string "Seu desafio terminou...\p"
	.string "Vou registrar os resultados.\n"
	.string "Espere um pouco...$"

BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance:
	.string "Você completou o desafio...\p"
	.string "Tenho que dizer... Você tem sorte\n"
	.string "de sobra...$"

BattleFrontier_BattlePikeLobby_Text_ShallRecordResults:
	.string "Vou registrar os resultados.\n"
	.string "Espere um pouco...$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints2:
	.string "Por completar o Desafio dos\n"
	.string "Caminhos, você recebe estes Pontos\l"
	.string "de Batalha...$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_ReachedBattlePointLimit:
	.string "Você chegou ao limite de Pontos de\n"
	.string "Batalha...\p"
	.string "Troque alguns pontos por prêmios e\n"
	.string "volte depois...$"

BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting:
	.string "Desculpe, mas...\p"
	.string "Da última vez, você saiu do\n"
	.string "desafio sem salvar.\p"
	.string "Por isso, seu desafio foi\n"
	.string "encerrado. Sinto muito...$"

BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen:
	.string "Parabéns...\p"
	.string "Você venceu a PIKE QUEEN e\n"
	.string "completou o desafio...$"

BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints:
	.string "Pela sua sorte incrível, você\n"
	.string "recebe estes Pontos de Batalha...$"

BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal:
	.string "Argh! Perdi minha chance! Faltava\n"
	.string "só uma sala pra chegar ao fim!\p"
	.string "Aqui é bom tomar cuidado com\n"
	.string "veneno, congelamento e coisas\l"
	.string "assim.$"

BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer:
	.string "Já completei o desafio dez vezes e\n"
	.string "nunca precisei enfrentar um\l"
	.string "treinador.$"

BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere:
	.string "Escuta só!\p"
	.string "Você nao acha que as habilidades\n"
	.string "dos Pokémon podem ajudar bastante\l"
	.string "aqui?$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_TrainersWhicheverPathIChoose:
	.string "Que lugar estranho! Nao entendo\n"
	.string "nada!\p"
	.string "Já tentei várias vezes, mas só\n"
	.string "encontro treinadores, seja qual\l"
	.string "for o caminho.$"

BattleFrontier_BattlePikeLobby_Text_RulesAreListed:
	.string "Aqui estao as regras do Desafio\n"
	.string "dos Caminhos.$"

BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading:
	.string "Sobre o que você quer ler?$"

BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules:
	.string "Você nao pode usar a Bolsa nem o\n"
	.string "POKéNAV durante o Desafio dos\l"
	.string "Caminhos.$"

BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules:
	.string "Durante o Desafio dos Caminhos,\n"
	.string "cada Berry ou Erva que um Pokémon\l"
	.string "segura só funciona uma vez.$"

BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules:
	.string "Durante o Desafio dos Caminhos,\n"
	.string "você nao pode mudar a ordem dos\l"
	.string "Pokémon.\p"
	.string "Escolha a ordem antes de começar.$"

