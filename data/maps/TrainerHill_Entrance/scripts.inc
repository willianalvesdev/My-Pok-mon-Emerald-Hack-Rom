TrainerHill_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_OnReturn
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_OnFrame
	.byte 0

TrainerHill_Entrance_OnTransition:
	setflag FLAG_LANDMARK_TRAINER_HILL
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

@ Unused
TrainerHill_Entrance_OnWarp:
	end

TrainerHill_Entrance_OnResume:
	trainerhill_resumetimer
	setvar VAR_TEMP_0, 0
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_TryFaceAttendant  @ VAR_RESULT always FALSE here
	setobjectxy LOCALID_PLAYER, 9, 6
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_TryFaceAttendant::
	trainerhill_getwon
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant::
	end

TrainerHill_Entrance_OnReturn:
	addobject LOCALID_TRAINER_HILL_NURSE
	addobject LOCALID_TRAINER_HILL_ATTENDANT
	addobject LOCALID_TRAINER_HILL_MAN
	addobject LOCALID_TRAINER_HILL_GIRL
	end

TrainerHill_Entrance_OnLoad:
	call_if_eq VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_OpenCounterDoor
	end

TrainerHill_Entrance_EventScript_OpenCounterDoor::
	setmetatile 17, 10, METATILE_TrainerHill_GreenFloorTile, FALSE
	return

TrainerHill_Entrance_OnFrame:
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_EventScript_ExitChallenge
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_ExitElevator
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_EventScript_EntryTrigger
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
	.2byte 0

TrainerHill_Entrance_EventScript_ExitElevator::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerExitElevator
	waitmovement 0
	setmetatile 17, 10, METATILE_TrainerHill_CounterDoor, TRUE
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerHill_Entrance_EventScript_ExitChallenge::
	setvar VAR_TEMP_0, 1
	trainerhill_getstatus
	switch VAR_RESULT
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_EventScript_ExitChallengeLost
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_EventScript_ExitChallengeECard
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_EventScript_EndExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeLost::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_PlayerExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeECard::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_PlayerExitChallenge::
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	releaseall
TrainerHill_Entrance_EventScript_EndExitChallenge::
	end

TrainerHill_Entrance_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_TRAINER_HILL_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TrainerHill_Entrance_EventScript_Attendant::
	lock
	faceplayer
	trainerhill_inchallenge
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_ThanksForPlaying
	msgbox TrainerHill_Entrance_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AttendantEnd

TrainerHill_Entrance_EventScript_ThanksForPlaying::
	msgbox TrainerHill_Entrance_Text_ThankYouForPlaying, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AttendantEnd::
	release
	end

TrainerHill_Entrance_EventScript_EntryTrigger::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_Closed
	msgbox TrainerHill_Entrance_Text_WelcomeToTrainerHill, MSGBOX_DEFAULT
	trainerhill_getsaved
	call_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveGame
	trainerhill_allfloorsused
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_AllFloorsUsed
	msgbox TrainerHill_Entrance_Text_TrainersUpToFloorX, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers

TrainerHill_Entrance_EventScript_AllFloorsUsed::
	msgbox TrainerHill_Entrance_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AskChallengeTrainers::
	message TrainerHill_Entrance_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 15, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerHill_Entrance_EventScript_ChooseChallenge
	case 1, TrainerHill_Entrance_EventScript_CancelEntry
	case 2, TrainerHill_Entrance_EventScript_Info
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Info::
	msgbox TrainerHill_Entrance_Text_ExplainTrainerHill, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers
	end

TrainerHill_Entrance_EventScript_ChooseChallenge::
	multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
	switch VAR_RESULT
	case 4, TrainerHill_Entrance_EventScript_CancelEntry
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	trainerhill_setmode VAR_RESULT
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
	setvar VAR_TEMP_5, 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	msgbox TrainerHill_Entrance_Text_TimeProgessGetSetGo, MSGBOX_DEFAULT
	trainerhill_start
	releaseall
	end

TrainerHill_Entrance_EventScript_CancelEntry::
	setvar VAR_TEMP_5, 0
	msgbox TrainerHill_Entrance_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_EventScript_SaveGame::
	msgbox TrainerHill_Entrance_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
	trainerhill_setsaved
	setvar VAR_TEMP_5, 1
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveFailed
	trainerhill_setsaved
	return

TrainerHill_Entrance_EventScript_SaveFailed::
	trainerhill_clearsaved
	goto TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Closed::
	msgbox TrainerHill_Entrance_Text_StillGettingReady, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_Movement_PlayerFaceAttendant:
	face_right
	step_end

TrainerHill_Entrance_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

@ Unused
TrainerHill_Entrance_Movement_FaceUp:
	face_up
	step_end

TrainerHill_Entrance_Movement_PlayerExitElevator:
	walk_down
	walk_down
	step_end

TrainerHill_Entrance_EventScript_Records::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 0
	special ShowTrainerHillRecords
	releaseall
	end

TrainerHill_Entrance_EventScript_Man::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ManTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_ManTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_CantWaitToTestTheWaters, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Girl::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_GirlTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_GirlTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ExpandedPokemart
	pokemart TrainerHill_Entrance_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Basic:
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_EventScript_ExpandedPokemart::
	pokemart TrainerHill_Entrance_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Expanded:
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_Text_StillGettingReady:
	.string "Esta é Trainer Hill, onde você\n"
	.string "pode batalhar em dupla contra\l"
	.string "vários treinadores.\p"
	.string "Ainda estamos preparando tudo.\n"
	.string "Volte depois!$"

TrainerHill_Entrance_Text_WelcomeToTrainerHill:
	.string "Bem-vindo!\p"
	.string "Esta é Trainer Hill, onde você\n"
	.string "pode batalhar em dupla contra\l"
	.string "vários treinadores!$"

TrainerHill_Entrance_Text_SaveGameBeforeEnter:
	.string "É sua primeira visita?\p"
	.string "Antes de entrar, salve seu jogo.$"

TrainerHill_Entrance_Text_TrainersUpToFloorX:
	.string "Vamos ver... Os treinadores de\n"
	.string "hoje estao...\p"
	.string "Até o andar {STR_VAR_1}.$"

TrainerHill_Entrance_Text_TrainersInEveryRoom:
	.string "Vamos ver... Os treinadores de\n"
	.string "hoje...\p"
	.string "Parece que estao em todas as\n"
	.string "salas.$"

TrainerHill_Entrance_Text_LikeToChallengeTrainers:
	.string "Quer desafiar os treinadores que\n"
	.string "estao esperando?$"

TrainerHill_Entrance_Text_TimeProgessGetSetGo:
	.string "Vou marcar seu tempo. Boa sorte!\p"
	.string "Em suas marcas...\p"
	.string "Preparar...\p"
	.string "Já!$"

TrainerHill_Entrance_Text_PleaseVisitUsAgain:
	.string "Volte sempre!$"

TrainerHill_Entrance_Text_TooBadTremendousEffort:
	.string "Que pena.\p"
	.string "Você se esforçou muito nas\n"
	.string "batalhas.\p"
	.string "Volte pra tentar de novo!$"

TrainerHill_Entrance_Text_HopeYouGiveItYourBest:
	.string "Espero que dê o seu melhor.$"

TrainerHill_Entrance_Text_MovedReceptionHereForSwitch:
	.string "Quando os treinadores trocam de\n"
	.string "lugar, fica uma correria.\p"
	.string "Mudamos o balcao pra cá pra nao\n"
	.string "ficar no caminho.\p"
	.string "Desculpa o transtorno.$"

TrainerHill_Entrance_Text_ThankYouForPlaying:
	.string "Obrigado por participar!$"

TrainerHill_Entrance_Text_ExplainTrainerHill:
	.string "Em Trainer Hill temos o desafio\n"
	.string "Time Attack.\p"
	.string "Medimos quanto tempo você leva\n"
	.string "deste balcao até nosso dono no\l"
	.string "terraço.\p"
	.string "Os melhores tempos ficam no\n"
	.string "quadro. Tente competir com seus\l"
	.string "amigos.\p"
	.string "As batalhas do caminho nao dao\n"
	.string "experiência nem dinheiro.$"

@ Unused
TrainerHill_Entrance_Text_NeedAtLeastTwoPokemon:
	.string "Desculpa, você só tem um Pokémon.\p"
	.string "Precisa de pelo menos dois pra\n"
	.string "participar.$"

TrainerHill_Roof_Text_YouFinallyCameBravo:
	.string "Hum! Hum! Finalmente chegou!\p"
	.string "Espera, nao fala! Sei por que veio\n"
	.string "até aqui sozinho!\p"
	.string "Você queria conhecer o dono de\n"
	.string "Trainer Hill porque quer formar uma\l"
	.string "dupla comigo! Uhuu!\p"
	.string "Hein? Nao era isso?\p"
	.string "Bom, vi suas batalhas na subida.\n"
	.string "Foram maravilhosas! Bravo!$"

TrainerHill_Roof_Text_HaveTheMostMarvelousGift:
	.string "Pra alguém maravilhoso como você,\n"
	.string "tenho um presente maravilhoso!$"

TrainerHill_Roof_Text_FullUpBeBackLaterForThis:
	.string "Ah, sua bolsa ta cheia! Volte\n"
	.string "depois pra pegar isto!$"

TrainerHill_Roof_Text_GotHereMarvelouslyQuickly:
	.string "Espera! Você chegou muito rápido!\p"
	.string "Que ótimo! Nao precisava correr\n"
	.string "tanto pra me ver!\p"
	.string "Fico feliz demais. Vou pedir pra\n"
	.string "atualizarem o quadro de tempos!$"

TrainerHill_Roof_Text_YouWerentVeryQuick:
	.string "Mas... Você demorou um pouco pra\n"
	.string "chegar.$"

TrainerHill_Roof_Text_ArriveZippierNextTime:
	.string "Talvez eu ficasse mais feliz se\n"
	.string "chegasse mais rápido na próxima.\p"
	.string "Aí eu adoraria formar uma dupla\n"
	.string "com você!\p"
	.string "Até a próxima, amigo!$"

@ Unused
TrainerHill_Roof_Text_BuiltTrainerHillToFindPartner:
	.string "Mandei construir Trainer Hill por\n"
	.string "um único motivo!\p"
	.string "Encontrar a pessoa ideal pra\n"
	.string "formar uma dupla comigo!$"

TrainerHill_Entrance_Text_ChallengeTime:
	.string "{STR_VAR_1} min.\n"
	.string "{STR_VAR_2}.{STR_VAR_3}\l"
	.string "seg.$"

TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead:
	.string "Quem sabe quais combinaçoes de\n"
	.string "treinadores e Pokémon vêm pela\l"
	.string "frente?\p"
	.string "Só sei que vou vencer todo mundo\n"
	.string "que aparecer no caminho!$"

TrainerHill_Entrance_Text_CantWaitToTestTheWaters:
	.string "Ouvi dizer que treinadores fortes\n"
	.string "vêm de todo canto pra Trainer Hill.\p"
	.string "Mal posso esperar pra testar minha\n"
	.string "força! Vou vencer quem entrar no\l"
	.string "caminho!$"

TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop:
	.string "Viu aquele quadro de tempos?\p"
	.string "Eu e meus amigos estamos\n"
	.string "disputando quem chega ao topo mais\l"
	.string "rápido.$"

TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen:
	.string "Sabe quando este lugar vai abrir?\p"
	.string "Tô esperando pra ser o primeiro\n"
	.string "desafiante!$"

TrainerHill_Elevator_Text_ReturnToReception:
	.string "Quer voltar à recepçao?$"
