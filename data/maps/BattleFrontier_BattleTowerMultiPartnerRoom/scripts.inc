BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_OnResume:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	tower_loadpartners
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_BOY_1
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, 10, 2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom
	waitmovement 0
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit
	waitmovement 0
	copyobjectxytoperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit:
	walk_left
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator::
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorEast:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorWest:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorWest
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast:
	walk_right
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorWest:
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_INTRO
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON1
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner:
	.string "Encontre alguém entre os\n"
	.string "treinadores daqui para formar uma\l"
	.string "parceria.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner:
	.string "{PLAYER}, você ainda nao encontrou\n"
	.string "ninguém para formar uma parceria.\p"
	.string "Quer parar de procurar e voltar ao\n"
	.string "balcao?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2:
	.string "Entao escolha alguém entre os\n"
	.string "treinadores daqui.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner::
	.string "Obrigado por escolher sua parceria.\p"
	.string "Vou levar vocês até a Sala de\n"
	.string "Batalhas em Parceria.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro::
	.string "Sou o aprendiz número\n"
	.string "{STR_VAR_2} de {STR_VAR_1}.\l"
	.string "Pode me chamar de {STR_VAR_3}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1::
	.string "Segui o conselho de\n"
	.string "{STR_VAR_1} e trouxe um\l"
	.string "{STR_VAR_3} com {STR_VAR_2}\l"
	.string "e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}.\p"
	.string "Por favor, deixa eu formar uma\n"
	.string "parceria com você.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept::
	.string "Valeu! Vou fazer a inscriçao\n"
	.string "agora.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject::
	.string "Eu queria muito fazer uma parceria\n"
	.string "com você, {PLAYER}...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro::
	.string "Sou o aprendiz número\n"
	.string "{STR_VAR_2} de {STR_VAR_1}.\l"
	.string "Meu nome é {STR_VAR_3}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1::
	.string "Segui os conselhos de\n"
	.string "{STR_VAR_1} e escolhi um\l"
	.string "{STR_VAR_3} com {STR_VAR_2}\l"
	.string "e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}.\p"
	.string "Vamos formar uma parceria?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept::
	.string "Muito obrigado! Vou fazer a\n"
	.string "inscriçao rapidinho!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject::
	.string "{PLAYER}, eu esperava poder formar\n"
	.string "uma parceria com você...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro::
	.string "É... Meu nome é {STR_VAR_3},\n"
	.string "sou o aprendiz número\l"
	.string "{STR_VAR_2} de {STR_VAR_1}.\p"
	.string "Snif...\p"
	.string "Desculpa! Estou tao nervoso que\n"
	.string "comecei a chorar...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1::
	.string "{STR_VAR_3} me deu uns\n"
	.string "conselhos, entao trouxe um\l"
	.string "{STR_VAR_2} com {STR_VAR_1}\l"
	.string "e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}.\p"
	.string "Snif... Por favor, faz uma parceria\n"
	.string "comigo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept::
	.string "Sério? Você aceita? Que demais!\n"
	.string "Uhuu!\p"
	.string "Ah... Desculpa... Agora estou\n"
	.string "chorando de alegria...\p"
	.string "Vou fazer a inscriçao! Nao sai\n"
	.string "daqui!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject::
	.string "Ah, m-mas... Snif... Buaaaa!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro::
	.string "Oi! Sou {STR_VAR_3}! Sou o\n"
	.string "aprendiz número {STR_VAR_2} de\l"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1::
	.string "{STR_VAR_3} recomendou minha\n"
	.string "equipe. Tenho um {STR_VAR_2}\l"
	.string "com {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}! Legal, né?\p"
	.string "Vamos lá! Faz uma parceria comigo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept::
	.string "Oba! Ótimo! Vou fazer a inscriçao,\n"
	.string "tá?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject::
	.string "Ah, por quê? Eu queria fazer uma\n"
	.string "parceria com você, {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro::
	.string "Sou {STR_VAR_3}, o aprendiz\n"
	.string "número {STR_VAR_2} de\l"
	.string "{STR_VAR_1}, que é uma pessoa\l"
	.string "muito famosa!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1::
	.string "Pedi conselhos a {STR_VAR_3}.\n"
	.string "Tenho um {STR_VAR_2} que usa\l"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask::
	.string "e um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}. Essa é minha\l"
	.string "equipe.\p"
	.string "Quer formar uma parceria comigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept::
	.string "Valeu! Vou fazer a inscriçao\n"
	.string "agora!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject::
	.string "{PLAYER}, eu esperava poder fazer\n"
	.string "uma parceria com você...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro::
	.string "É... Fico muito feliz que tenha\n"
	.string "parado para falar comigo.\p"
	.string "Sou {STR_VAR_3}, o aprendiz\n"
	.string "número {STR_VAR_2} de\l"
	.string "{STR_VAR_1}...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1::
	.string "{STR_VAR_3} me deu uns\n"
	.string "conselhos. Sou muito grato por\l"
	.string "isso.\p"
	.string "Minha equipe tem um {STR_VAR_2}\n"
	.string "com {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}. Sei que é pedir\l"
	.string "muito...\p"
	.string "Nao sei se vai aceitar, mas posso\n"
	.string "fazer uma parceria com você?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept::
	.string "Sério? Nem acredito! Você vai\n"
	.string "mesmo fazer uma parceria comigo!\l"
	.string "Eu... Nao vou te decepcionar!\p"
	.string "É... Se estiver tudo bem mesmo,\n"
	.string "vou fazer a inscriçao agora!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject::
	.string "Ah... Eu já achava que nao era bom\n"
	.string "o bastante...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro::
	.string "Oi, sou {STR_VAR_3}. Sou o\n"
	.string "aprendiz número {STR_VAR_2} de\l"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1::
	.string "{STR_VAR_3} disse que seria bom\n"
	.string "montar esta equipe: um\l"
	.string "{STR_VAR_2} que usa\l"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask::
	.string "e um {STR_VAR_2} que sabe usar\n"
	.string "{STR_VAR_1}.\p"
	.string "Nada mal, né? Quer que eu faça\n"
	.string "uma parceria com você?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept::
	.string "Beleza, vou com você! Espero que\n"
	.string "nao atrapalhe meus planos! Vou\l"
	.string "fazer a inscriçao.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject::
	.string "Ué? Por que me recusou? Você nao\n"
	.string "sabe reconhecer talento!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro::
	.string "Sou {STR_VAR_3}, um triatleta.\n"
	.string "Vivo ocupado correndo, treinando e\l"
	.string "fazendo rap.\p"
	.string "Também sou o aprendiz número\n"
	.string "{STR_VAR_2} de {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1::
	.string "{STR_VAR_3} recomendou esta\n"
	.string "equipe: um {STR_VAR_2} que usa\l"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask::
	.string "e um {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}.\p"
	.string "Mesmo ocupado, me esforcei muito\n"
	.string "pra treinar os dois.\p"
	.string "Vamos formar uma parceria e\n"
	.string "tentar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept::
	.string "Valeu, é isso aí! Espera enquanto\n"
	.string "faço a inscriçao, tá?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject::
	.string "Eu tirei um tempo da minha rotina\n"
	.string "corrida pra vir aqui! Me ajuda aí!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro::
	.string "Oi! Tudo bem?\p"
	.string "Sou {STR_VAR_3}, o aprendiz\n"
	.string "número {STR_VAR_2} de\l"
	.string "{STR_VAR_1}. Prazer!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1::
	.string "Escuta só! Preciso te contar dos\n"
	.string "Pokémon que {STR_VAR_3}\l"
	.string "recomendou. Um {STR_VAR_2} com\l"
	.string "{STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}. Claro que eu\l"
	.string "treinei os dois muito bem!\p"
	.string "Quer formar uma parceria? Acho que\n"
	.string "a gente vai combinar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept::
	.string "Oba, acho que vai ser divertido!\n"
	.string "Vou fazer a inscriçao!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject::
	.string "Ah, que maldade! Eu tenho boas\n"
	.string "recomendaçoes, sabia?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro::
	.string "Deixe eu me apresentar. Sou\n"
	.string "{STR_VAR_3}.\p"
	.string "Sou o aprendiz número\n"
	.string "{STR_VAR_2} de {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1::
	.string "Pedi conselhos a {STR_VAR_3} e\n"
	.string "treinei minha equipe: um\l"
	.string "{STR_VAR_2} com {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask::
	.string "e um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}.\p"
	.string "Por favor, aceite formar uma\n"
	.string "parceria comigo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept::
	.string "Ah... Que alegria! Prometo dar o\n"
	.string "meu melhor!\p"
	.string "Pode deixar a inscriçao comigo!\n"
	.string "Espere um pouco!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject::
	.string "Eu esperava poder me juntar a\n"
	.string "você, {PLAYER}...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro::
	.string "Ah! Você falou comigo! Eu... Estou\n"
	.string "tao feliz!\p"
	.string "Sou {STR_VAR_3}! Sou o\n"
	.string "aprendiz número {STR_VAR_2} de\l"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1::
	.string "Seguindo o conselho de\n"
	.string "{STR_VAR_3}, treinei um\l"
	.string "{STR_VAR_2} que usa\l"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask::
	.string "e um {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}.\p"
	.string "Pode realizar meu desejo? Quero\n"
	.string "fazer uma parceria com você!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept::
	.string "Ah! Estou até tonto de felicidade!\n"
	.string "Muito obrigado! Vou fazer nossa\l"
	.string "inscriçao agora!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject::
	.string "Buaaa! Você nao tem dó? Mas isso\n"
	.string "te deixa ainda mais legal...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro::
	.string "Uhuu! Sou o aprendiz número\n"
	.string "{STR_VAR_2} de {STR_VAR_1}!\p"
	.string "Meu nome é {STR_VAR_3}! Oi, oi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1::
	.string "Meu mentor {STR_VAR_3}\n"
	.string "recomendou um {STR_VAR_2} que\l"
	.string "domina {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask::
	.string "e um {STR_VAR_2} que domina\n"
	.string "{STR_VAR_1}.\p"
	.string "Bom, né? Você vai fazer uma\n"
	.string "parceria comigo, nao vai?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept::
	.string "Beleza, ótimo! Vou fazer a\n"
	.string "inscriçao rapidinho!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject::
	.string "Aaah! Você pensa em tudo, hein,\n"
	.string "{PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro::
	.string "Ei! Temos um problemao! Hoje é o\n"
	.string "último dia da BATTLE TOWER!\p"
	.string "... ... ... ... ... ... É\n"
	.string "brincadeira!\p"
	.string "As pessoas me chamam de\n"
	.string "{STR_VAR_3}, e eu também! Sou\l"
	.string "o milésimo aprendiz de\l"
	.string "{STR_VAR_1}! Na verdade, sou o\l"
	.string "número {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1::
	.string "{STR_VAR_3} me deu uns\n"
	.string "conselhos. Tenho um\l"
	.string "{STR_VAR_2} com {STR_VAR_1}\l"
	.string "e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}. Tenho dez de\l"
	.string "cada! Na verdade, só um de cada!\p"
	.string "E aí? Quer tentar batalhar em\n"
	.string "parceria comigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept::
	.string "Oba! Vou te dar um Pokémon pra\n"
	.string "agradecer!\p"
	.string "Brincadeira! Mas vou fazer a\n"
	.string "inscriçao de verdade, tá?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject::
	.string "Ah, que frieza! Vou ter que\n"
	.string "derrubar a BATTLE TOWER por causa\l"
	.string "disso!\p"
	.string "Claro que nao vou!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro::
	.string "Ei, estou no ritmo, pronto pra\n"
	.string "mandar! Com meus Pokémon, eu vou\l"
	.string "batalhar!\p"
	.string "Sou {STR_VAR_3}, o marinheiro\n"
	.string "do rap. Pode ouvir que eu tenho\l"
	.string "talento!\p"
	.string "Sou o aprendiz número\n"
	.string "{STR_VAR_2} de {STR_VAR_1}.\l"
	.string "Nao me deixe de lado!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1::
	.string "Segui os conselhos de\n"
	.string "{STR_VAR_3} e montei minha\l"
	.string "equipe com orgulho! Um\l"
	.string "{STR_VAR_2} que usa\l"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask::
	.string "e um {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}!\p"
	.string "Vamos comemorar esse encontro com\n"
	.string "uma vitória em parceria!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept::
	.string "Ei, gostei do seu jeito! Vou fazer\n"
	.string "nossa inscriçao!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject::
	.string "Poxa, {PLAYER}, que frieza! Assim\n"
	.string "você me deixa na tristeza!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro::
	.string "Uhuu! Ei, nao corre! Eu só estava\n"
	.string "brincando!\p"
	.string "Oi! Sou {STR_VAR_3}! Sou o\n"
	.string "aprendiz número {STR_VAR_2} de\l"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1::
	.string "Segui os conselhos de\n"
	.string "{STR_VAR_3} e escolhi um\l"
	.string "{STR_VAR_2} que usa\l"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask::
	.string "e um {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}.\p"
	.string "E aí, o que me diz? Vem comigo!\p"
	.string "Por favor, deixa eu me juntar a\n"
	.string "você!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept::
	.string "Isso! Dei sorte! Estou feliz\n"
	.string "demais!\p"
	.string "Antes da batalha, vou fazer nossa\n"
	.string "inscriçao!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject::
	.string "Você vai me recusar? Poxa,\n"
	.string "{PLAYER}, assim eu fico triste!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro::
	.string "Cof!\p"
	.string "Ah, desculpa, estou resfriado. Mas\n"
	.string "meus Pokémon estao bem.\p"
	.string "Sou {STR_VAR_3}, o aprendiz\n"
	.string "número {STR_VAR_2} de\l"
	.string "{STR_VAR_1}. Cof!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1::
	.string "Levei os conselhos de\n"
	.string "{STR_VAR_3} a sério e montei\l"
	.string "uma equipe com um {STR_VAR_2}\l"
	.string "que usa {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask::
	.string "um {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}.\p"
	.string "Treinei os dois todo dia, mesmo com\n"
	.string "vento e chuva.\p"
	.string "Acho que foi assim que peguei esse\n"
	.string "resfriado.\p"
	.string "Essa é a minha história. Quer\n"
	.string "formar uma parceria?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept::
	.string "Valeu, de verdade! Cof, cof!\n"
	.string "Espera enquanto faço a inscriçao.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject::
	.string "Ah, nao quer? {PLAYER}, acho que a\n"
	.string "gente formaria uma boa equipe.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro::
	.string "Ah, oi! Estou bem nervoso.\p"
	.string "Sou {STR_VAR_3}, o aprendiz\n"
	.string "número {STR_VAR_2} de\l"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1::
	.string "{STR_VAR_3} disse que esta\n"
	.string "equipe seria boa: um\l"
	.string "{STR_VAR_2} com {STR_VAR_1}\l"
	.string "e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}.\p"
	.string "Estou meio sem jeito, mas posso me\n"
	.string "juntar a você?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept::
	.string "Ah, obrigado! Estou com vergonha,\n"
	.string "mas vou dar o meu melhor!\p"
	.string "Vou fazer a inscriçao.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject::
	.string "Ah, por favor, nao diga nao! Já\n"
	.string "estou sem jeito o bastante...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro::
	.string "Sou {STR_VAR_3}, e isso é\n"
	.string "verdade. Sou o aprendiz número\l"
	.string "{STR_VAR_2} de {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1::
	.string "{STR_VAR_3} recomendou minha\n"
	.string "equipe.\p"
	.string "Como o conselho pareceu sincero,\n"
	.string "trouxe meu {STR_VAR_2} que usa\l"
	.string "{STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask::
	.string "meu {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}.\p"
	.string "Se puder, gostaria que me\n"
	.string "aceitasse como sua parceria.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept::
	.string "Você aceita mesmo? Seria horrível\n"
	.string "se nao aceitasse.\p"
	.string "Mas, já que aceitou, está tudo\n"
	.string "certo. Vou fazer nossa inscriçao.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject::
	.string "Hum? Por que você recusaria? Isso\n"
	.string "é alguma brincadeira?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro::
	.string "Sou {STR_VAR_1}, uma\n"
	.string "treinadora!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1::
	.string "Tenho um {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1} e um$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask::
	.string "{STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}. Sao eles que\l"
	.string "estao comigo.\p"
	.string "Quer fazer uma parceria?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept::
	.string "Obrigada! Vou fazer nossa\n"
	.string "inscriçao!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject::
	.string "Nao quer fazer uma parceria\n"
	.string "comigo? Vai se arrepender depois!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro::
	.string "Oi!\p"
	.string "Sou o jovem treinador\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1::
	.string "Quer saber quem está comigo? Um\n"
	.string "{STR_VAR_2} com {STR_VAR_1}\l"
	.string "e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}!\p"
	.string "Você vai formar uma parceria\n"
	.string "comigo, né?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept::
	.string "Oba! Vou fazer a inscriçao, tá?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject::
	.string "Ah! Com meus Pokémon, nossa\n"
	.string "equipe seria imbatível!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro::
	.string "Uhuu! Sou o montanhista\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1::
	.string "Sabe quem está comigo? Meu\n"
	.string "{STR_VAR_2} que usa\l"
	.string "{STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask::
	.string "meu {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}!\p"
	.string "Legal, né? Vamos formar uma\n"
	.string "parceria?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept::
	.string "Uhuu! Vou fazer a inscriçao,\n"
	.string "entao.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject::
	.string "Eu gostaria de batalhar com você\n"
	.string "ao meu lado.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro::
	.string "Oi! Sou {STR_VAR_1}, uma bela\n"
	.string "treinadora!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1::
	.string "Sabe quais Pokémon eu treinei? Um\n"
	.string "{STR_VAR_2} com {STR_VAR_1}\l"
	.string "e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}!\p"
	.string "O que acha? Vamos formar uma\n"
	.string "parceria?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept::
	.string "Maravilha! Vou fazer a inscriçao\n"
	.string "agora!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject::
	.string "Que pena!\p"
	.string "Nós dois juntos seríamos os\n"
	.string "melhores!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro::
	.string "Ei!\p"
	.string "Sabe quem eu sou? Sou\n"
	.string "{STR_VAR_1}, o pescador!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1::
	.string "Minha equipe tem um {STR_VAR_2}\n"
	.string "que usa {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask::
	.string "um {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}.\p"
	.string "E aí? Quer lutar ao meu lado?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept::
	.string "Ótimo! Deixa comigo!\p"
	.string "Vou fazer nossa inscriçao agora.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject::
	.string "A gente combinava tao bem...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro::
	.string "Prazer em te conhecer. Sou\n"
	.string "{STR_VAR_1}, uma dama.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1::
	.string "Minha equipe é formada por um\n"
	.string "{STR_VAR_2} com {STR_VAR_1}\l"
	.string "e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}.\p"
	.string "Espero que goste. Quero muito\n"
	.string "fazer uma parceria com você.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept::
	.string "Muito obrigada. Vou cuidar da\n"
	.string "inscriçao.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject::
	.string "Tenho certeza de que vai se\n"
	.string "arrepender de nao fazer uma\l"
	.string "parceria comigo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro::
	.string "Sou o triatleta {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1::
	.string "Minha equipe... Tem um\n"
	.string "{STR_VAR_2} com {STR_VAR_1}\l"
	.string "e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}! Sao esses dois!\p"
	.string "Por favor, quer formar uma parceria\n"
	.string "comigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept::
	.string "Poxa, valeu! Vou fazer a inscriçao\n"
	.string "no balcao.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject::
	.string "Juntos, a gente seria forte de\n"
	.string "verdade!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro::
	.string "Oi! Sou {STR_VAR_1}, o caçador\n"
	.string "de insetos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1::
	.string "Olha só quem está comigo! Um\n"
	.string "{STR_VAR_2} com {STR_VAR_1}\l"
	.string "e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}!\p"
	.string "Entao, quer formar uma parceria?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept::
	.string "Combinado!\p"
	.string "Vou cuidar da inscriçao no balcao.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject::
	.string "Ah, meus Pokémon sao ótimos.\n"
	.string "Espero que nao se arrependa!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro::
	.string "Bom dia! Sou o estudante\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1::
	.string "Treinei um {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask::
	.string "e um {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}.\p"
	.string "Nada mal, né? Quer formar uma\n"
	.string "parceria?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept::
	.string "Muito obrigado! Vou fazer a\n"
	.string "inscriçao.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject::
	.string "Que pena...\p"
	.string "Eu esperava aprender com você\n"
	.string "sendo sua parceria...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro::
	.string "Ei! Deixa eu me apresentar! Sou o\n"
	.string "garoto rico {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1::
	.string "Adivinha quem eu tenho! Um\n"
	.string "{STR_VAR_2} com {STR_VAR_1}\l"
	.string "e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}!\p"
	.string "Vou te dar a chance de formar uma\n"
	.string "parceria comigo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept::
	.string "Boa escolha!\p"
	.string "Vou terminar a inscriçao rapidinho!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject::
	.string "Você vai recusar justo a mim? Vai\n"
	.string "se arrepender dessa decisao!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro::
	.string "Iáá! Sou o faixa-preta\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1::
	.string "Meus companheiros sao um\n"
	.string "{STR_VAR_2} que usa\l"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask::
	.string "e um {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}.\p"
	.string "Por favor, realize meu desejo!\n"
	.string "Deixe eu formar uma parceria com\l"
	.string "você!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept::
	.string "Iáá! Vou fazer a inscriçao agora!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject::
	.string "Entendi... Espero ter outra chance\n"
	.string "quando a gente se encontrar...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro::
	.string "Oi! Sou {STR_VAR_1}, um nadador\n"
	.string "mirim!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1::
	.string "Vou contar quem eu tenho. Um\n"
	.string "{STR_VAR_2} com {STR_VAR_1}\l"
	.string "e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}! Posso fazer uma\l"
	.string "parceria com você?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept::
	.string "Valeu! Vou fazer nossa inscriçao\n"
	.string "agora!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject::
	.string "Se a gente formasse uma parceria,\n"
	.string "seria forte demais!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro::
	.string "Oi... Sou {STR_VAR_1}, uma\n"
	.string "bruxa...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1::
	.string "Trouxe um {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1} e um$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask::
	.string "{STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}...\p"
	.string "Por favor... Forme uma parceria\n"
	.string "comigo...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept::
	.string "Obrigada... Vou fazer nossa\n"
	.string "inscriçao...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject::
	.string "Eu queria tanto me juntar a\n"
	.string "você...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro::
	.string "Tudo bem? Sou {STR_VAR_1}, um\n"
	.string "criador de Pokémon!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1::
	.string "Estou criando dois Pokémon muito\n"
	.string "bons! Um {STR_VAR_2} com\l"
	.string "{STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}!\p"
	.string "E aí? Quer formar uma parceria\n"
	.string "comigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept::
	.string "Muito obrigado!\p"
	.string "Vou cuidar da inscriçao. Espere bem\n"
	.string "aqui!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject::
	.string "Eu queria muito ser sua parceria...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro::
	.string "Ora, oi! Sou a triatleta\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1::
	.string "Quer saber com quem eu corro? Um\n"
	.string "{STR_VAR_2} com {STR_VAR_1}\l"
	.string "e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}!\p"
	.string "E aí? Quer formar uma parceria\n"
	.string "comigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept::
	.string "Boa!\p"
	.string "Vou terminar a inscriçao rapidinho!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject::
	.string "Nós dois juntos seríamos os\n"
	.string "melhores. Que pena...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro::
	.string "Oi! Meu nome é {STR_VAR_1}!\n"
	.string "Sou um triatleta!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1::
	.string "Corro com uma equipe resistente:\n"
	.string "um {STR_VAR_2} com\l"
	.string "{STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}!\p"
	.string "Nada mal, hein? A gente devia\n"
	.string "formar uma parceria!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept::
	.string "Beleza! Vou fazer a inscriçao num\n"
	.string "instante!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject::
	.string "Eu queria muito batalhar como sua\n"
	.string "parceria...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro::
	.string "Sou a lutadora {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1::
	.string "Andei treinando um {STR_VAR_2}\n"
	.string "que usa {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask::
	.string "um {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}!\p"
	.string "Gostou da equipe? Vamos nos\n"
	.string "juntar?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept::
	.string "Opa, valeu!\p"
	.string "Vou fazer a inscriçao agora!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject::
	.string "Achei que a gente poderia formar\n"
	.string "uma equipe imbatível...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro::
	.string "Sou a triatleta {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1::
	.string "Andei correndo com um\n"
	.string "{STR_VAR_2} que sabe usar\l"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask::
	.string "e um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}!\p"
	.string "A gente podia formar uma parceria.\n"
	.string "Nao seria legal?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept::
	.string "Obrigada!\p"
	.string "Vou fazer nossa inscriçao agora\n"
	.string "mesmo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject::
	.string "Ah, que pena. Nossa parceria seria\n"
	.string "a mais forte daqui!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro::
	.string "Eu? Sou {STR_VAR_1}, uma\n"
	.string "nadadora mirim!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1::
	.string "Quem está comigo? Um\n"
	.string "{STR_VAR_2} com {STR_VAR_1}\l"
	.string "e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}!\p"
	.string "Ei, você vai fazer uma parceria\n"
	.string "comigo, né?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept::
	.string "Beleza!\p"
	.string "Vou fazer a inscriçao! Vamos\n"
	.string "arrasar juntos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject::
	.string "Meus Pokémon sao fortes de\n"
	.string "verdade... Que pena que nao quer\l"
	.string "se juntar a mim.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro::
	.string "Uhuu! Pode me chamar de\n"
	.string "guitarrista {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1::
	.string "Olha só minha banda! Um\n"
	.string "{STR_VAR_2} com {STR_VAR_1}\l"
	.string "e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}!\p"
	.string "Uhuu! É demais, né? Vamos fazer um\n"
	.string "dueto nas batalhas!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept::
	.string "Uhuu! É isso aí! Vou cuidar da\n"
	.string "inscriçao!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject::
	.string "Meus Pokémon mandam muito! Você\n"
	.string "vai se arrepender!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro::
	.string "Prazer em te conhecer. Sou\n"
	.string "{STR_VAR_1}, um cavalheiro.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1::
	.string "Tenho a companhia do meu fiel\n"
	.string "{STR_VAR_2}, que usa\l"
	.string "{STR_VAR_1}, e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask::
	.string "de um {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}.\p"
	.string "Gostaria de formar uma parceria\n"
	.string "comigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept::
	.string "Ah, agradeço pela confiança. Vou\n"
	.string "fazer a inscriçao.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject::
	.string "Que pena...\p"
	.string "Vou esperar por uma próxima\n"
	.string "oportunidade...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro::
	.string "Oi, sou {STR_VAR_1}, um fa de\n"
	.string "Pokémon.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1::
	.string "Trouxe um {STR_VAR_2} que\n"
	.string "conhece o golpe {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}.\p"
	.string "Gostou? Que tal formar uma\n"
	.string "parceria comigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept::
	.string "Obrigado! Vou cuidar da inscriçao!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject::
	.string "Meus Pokémon sao de primeira...\n"
	.string "Pena que você nao percebe isso.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro::
	.string "Hum! Sou {STR_VAR_1}, um\n"
	.string "especialista!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1::
	.string "Treinei bem um {STR_VAR_2} com\n"
	.string "{STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}!\p"
	.string "O que acha de formar uma parceria\n"
	.string "comigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept::
	.string "Hum! Vou fazer nossa inscriçao\n"
	.string "agora! Vamos dar o nosso melhor!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject::
	.string "Espero que tenha feito a escolha\n"
	.string "certa...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro::
	.string "Oi, oi. Sou {STR_VAR_1}, uma\n"
	.string "especialista.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1::
	.string "Treinei meus Pokémon com muito\n"
	.string "cuidado. Um {STR_VAR_2} com\l"
	.string "{STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}. Sao eles que\l"
	.string "estao comigo.\p"
	.string "Quer formar uma parceria?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept::
	.string "Ótimo, ótimo. Vou cuidar da\n"
	.string "inscriçao agora.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject::
	.string "Talvez a gente forme uma equipe no\n"
	.string "próximo encontro.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro::
	.string "Sou o domador de dragoes\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1::
	.string "Minha equipe tem um {STR_VAR_2}\n"
	.string "com {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}!\p"
	.string "E aí? Quer formar uma parceria\n"
	.string "comigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept::
	.string "Beleza, vou dar o meu melhor! Vou\n"
	.string "fazer a inscriçao, tá?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject::
	.string "Vai ser difícil achar alguém mais\n"
	.string "forte que eu pra formar uma\l"
	.string "parceria!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro::
	.string "Sou {STR_VAR_1}, o criador de\n"
	.string "pássaros!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1::
	.string "Quais Pokémon eu tenho? Um\n"
	.string "{STR_VAR_2} com {STR_VAR_1}\l"
	.string "e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}.\p"
	.string "Nao acha que a gente formaria uma\n"
	.string "boa equipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept::
	.string "Ótimo, valeu! Vou cuidar da\n"
	.string "inscriçao!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject::
	.string "Meus Pokémon e eu somos fortes.\n"
	.string "Que decepçao.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro::
	.string "Sou o menino ninja {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1::
	.string "Minha equipe Pokémon tem um\n"
	.string "{STR_VAR_2} com {STR_VAR_1}\l"
	.string "e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}!\p"
	.string "Vamos formar uma parceria!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept::
	.string "Oba! Vou fazer a inscriçao!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject::
	.string "Você vai se arrepender de nao ter\n"
	.string "meus Pokémon fortes ao seu lado!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro::
	.string "Oi! Sou {STR_VAR_1}, a moça da\n"
	.string "sombrinha!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1::
	.string "Quem me acompanha é meu\n"
	.string "{STR_VAR_2} que usa\l"
	.string "{STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask::
	.string "um {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}.\p"
	.string "Nao sao ótimos? Quer se juntar à\n"
	.string "nossa equipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept::
	.string "Muito obrigada!\p"
	.string "Vou fazer a inscriçao no balcao.\n"
	.string "Vamos dar o nosso melhor!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject::
	.string "Meus Pokémon sao fortes demais.\n"
	.string "Que decepçao...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro::
	.string "Oi. Sou {STR_VAR_1}, um\n"
	.string "fanático por insetos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1::
	.string "Encontrei meus Pokémon, sim. Um\n"
	.string "{STR_VAR_2} com {STR_VAR_1}\l"
	.string "e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}. Foram eles que eu\l"
	.string "encontrei.\p"
	.string "Quer formar uma parceria comigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept::
	.string "Certo! Entendido!\p"
	.string "Vou terminar a inscriçao rapidinho!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject::
	.string "Com os Pokémon que encontrei, a\n"
	.string "gente nao perderia...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro::
	.string "Ei, marujo! Sou o marinheiro\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1::
	.string "Deixa eu mostrar meu orgulho! Um\n"
	.string "{STR_VAR_2} com {STR_VAR_1}\l"
	.string "e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}!\p"
	.string "Você nao vai me recusar, claro.\n"
	.string "Vamos formar uma parceria, né?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept::
	.string "Eu sabia! Vou fazer a inscriçao\n"
	.string "agora.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject::
	.string "A gente passaria por cima dos\n"
	.string "adversários! Que pena!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro::
	.string "Oi, sou {STR_VAR_1}. Sou um\n"
	.string "colecionador.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1::
	.string "As joias da minha coleçao sao meu\n"
	.string "{STR_VAR_2} com {STR_VAR_1}\l"
	.string "e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}!\p"
	.string "Ótimos, né? A gente devia formar\n"
	.string "uma equipe.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept::
	.string "É isso aí!\p"
	.string "Sem perder tempo. Vou fazer nossa\n"
	.string "inscriçao.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject::
	.string "Poxa, que chato. Você nao dá valor\n"
	.string "aos meus Pokémon.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro::
	.string "Oi, sou {STR_VAR_1}. Sou um\n"
	.string "guarda Pokémon.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1::
	.string "Meus companheiros sao um\n"
	.string "{STR_VAR_2} que usa\l"
	.string "{STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}!\p"
	.string "Nao acha que a gente formaria uma\n"
	.string "bela equipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept::
	.string "Maravilha! Vou cuidar da inscriçao\n"
	.string "agora.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject::
	.string "Na próxima, escolha meus Pokémon,\n"
	.string "tá?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro::
	.string "Meu nome é {STR_VAR_1}. Sou\n"
	.string "uma guarda Pokémon!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1::
	.string "Vou te contar sobre minha equipe.\n"
	.string "Tenho um {STR_VAR_2} com\l"
	.string "{STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}!\p"
	.string "Quer formar uma parceria com a\n"
	.string "gente?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept::
	.string "Vamos dar o nosso melhor! Vou\n"
	.string "fazer a inscriçao rapidinho!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject::
	.string "Espero que escolha meus Pokémon\n"
	.string "da próxima vez.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro::
	.string "Prazer. Sou {STR_VAR_1}, a moça\n"
	.string "dos aromas.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1::
	.string "Viajo com um {STR_VAR_2} que\n"
	.string "usa {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask::
	.string "um {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}.\p"
	.string "Espero que goste deles. Quer\n"
	.string "formar uma parceria?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept::
	.string "Fico muito feliz que tenha\n"
	.string "aceitado. Vou fazer a inscriçao\l"
	.string "agora.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject::
	.string "Seria ótimo formar uma parceria no\n"
	.string "nosso próximo encontro.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro::
	.string "Quer saber quem eu sou? Sou\n"
	.string "{STR_VAR_1}, o fanático por\l"
	.string "ruínas!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1::
	.string "Os Pokémon que estao comigo sao\n"
	.string "um {STR_VAR_2} com\l"
	.string "{STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}!\p"
	.string "Interessante, né? Que tal nos\n"
	.string "juntarmos?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept::
	.string "Boa decisao! Vou cuidar da\n"
	.string "papelada da inscriçao.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject::
	.string "Hum... Acho que meus Pokémon sao\n"
	.string "fortes...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro::
	.string "Sou o treinador de elite\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1::
	.string "Meus Pokémon sao um\n"
	.string "{STR_VAR_2} com {STR_VAR_1}\l"
	.string "e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}. Legal, né?\p"
	.string "Nao acha que seria legal formar\n"
	.string "uma parceria?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept::
	.string "Legal! Vou fazer a inscriçao num\n"
	.string "instante!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject::
	.string "Achei que a gente formaria a\n"
	.string "melhor equipe de todas.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro::
	.string "Sou a treinadora de elite\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1::
	.string "Minha equipe tem um {STR_VAR_2}\n"
	.string "com {STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}.\p"
	.string "Parece bom? Vamos formar uma\n"
	.string "parceria?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept::
	.string "Parece ótimo! É melhor eu fazer a\n"
	.string "inscriçao.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject::
	.string "Eu estava pensando em como nossa\n"
	.string "equipe seria forte...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro::
	.string "Ei! Sou {STR_VAR_1}, o fanático\n"
	.string "por Pokémon!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1::
	.string "Quem um cara como eu teria? Um\n"
	.string "{STR_VAR_2} com {STR_VAR_1}\l"
	.string "e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}, é isso!\p"
	.string "Vamos lá! Nossa parceria vai\n"
	.string "arrasar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept::
	.string "Boa escolha! Vou fazer nossa\n"
	.string "inscriçao!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject::
	.string "Meus Pokémon sao ferozes! Depois\n"
	.string "nao diga que eu nao avisei!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro::
	.string "Ei! Sou {STR_VAR_1}, o\n"
	.string "treinador de fogo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1::
	.string "Sabe o que saiu do meu treino? Um\n"
	.string "{STR_VAR_2} com {STR_VAR_1}\l"
	.string "e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}!\p"
	.string "E aí? Quer formar uma parceria?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept::
	.string "Beleza! Vou cuidar da inscriçao.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject::
	.string "Promete que vai fazer uma parceria\n"
	.string "comigo da próxima vez?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro::
	.string "Sou {STR_VAR_1}, um campista!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1::
	.string "Treinei um {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1} e um$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask::
	.string "{STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}.\p"
	.string "Acha que seria divertido formar uma\n"
	.string "parceria? Aposto que sim!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept::
	.string "Isso! Vou fazer a inscriçao!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject::
	.string "Na próxima, tá? Quero fazer parte\n"
	.string "da sua equipe.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro::
	.string "Oi! Sou {STR_VAR_1}, uma\n"
	.string "campista!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1::
	.string "Os Pokémon que trouxe sao um\n"
	.string "{STR_VAR_2} com {STR_VAR_1}\l"
	.string "e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}.\p"
	.string "Tem interesse em formar uma\n"
	.string "parceria comigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept::
	.string "Muito obrigada! Vou fazer a\n"
	.string "inscriçao agora.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject::
	.string "Seria legal poder me juntar a você\n"
	.string "outra hora.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro::
	.string "Sou o paranormal {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1::
	.string "Os dois que treinei sao um\n"
	.string "{STR_VAR_2} com {STR_VAR_1}\l"
	.string "e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}.\p"
	.string "Quer formar uma parceria comigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept::
	.string "Pode deixar! Vou cuidar da\n"
	.string "inscriçao!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject::
	.string "Quando a gente se encontrar de\n"
	.string "novo, quero formar uma parceria\l"
	.string "com você.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro::
	.string "Sou {STR_VAR_1}, uma\n"
	.string "paranormal.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1::
	.string "Um {STR_VAR_2} com\n"
	.string "{STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}. Eles sao meus\l"
	.string "aprendizes.\p"
	.string "A ideia de formar uma parceria te\n"
	.string "interessa?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept::
	.string "Obrigada. Vou cuidar da inscriçao.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject::
	.string "Espero ter outra chance de me unir\n"
	.string "a você.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro::
	.string "Sou a estudante {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1::
	.string "Um {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask::
	.string "e um {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1} formam minha\l"
	.string "equipe.\p"
	.string "Posso fazer uma parceria com você?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept::
	.string "Ah, obrigada! Vou fazer a inscriçao\n"
	.string "no balcao agora!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject::
	.string "Por favor, posso me juntar a você\n"
	.string "na próxima?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro::
	.string "Oi! Meu nome é {STR_VAR_1}!\n"
	.string "Sou uma criadora de Pokémon!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1::
	.string "Treinei um {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask::
	.string "um {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}.\p"
	.string "Gostou? Que tal formar uma\n"
	.string "parceria?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept::
	.string "Beleza! Deixa a inscriçao comigo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject::
	.string "Na próxima, você tem que fazer uma\n"
	.string "parceria comigo, tá?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro::
	.string "Sou {STR_VAR_1}, e tenho\n"
	.string "orgulho de ser uma fa de Pokémon.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1::
	.string "Meus queridos Pokémon sao um\n"
	.string "{STR_VAR_2} com {STR_VAR_1}\l"
	.string "e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}.\p"
	.string "Nao sao uma graça? A gente devia\n"
	.string "formar uma equipe!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept::
	.string "Obrigada, querido! Vou fazer a\n"
	.string "inscriçao!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject::
	.string "Meus queridos Pokémon sao os\n"
	.string "melhores, viu? Que raiva!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro::
	.string "Oi, sou o nadador {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1::
	.string "Um {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask::
	.string "e um {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}. Foram esses que\l"
	.string "eu treinei.\p"
	.string "Vamos formar uma parceria.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept::
	.string "Legal! Vou fazer nossa inscriçao.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject::
	.string "Na próxima vez, você me deve uma\n"
	.string "parceria!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro::
	.string "Tudo certo? Sou {STR_VAR_1},\n"
	.string "uma triatleta.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1::
	.string "Tenho dois Pokémon bons. Um\n"
	.string "{STR_VAR_2} com {STR_VAR_1}\l"
	.string "e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}!\p"
	.string "Seria legal formar uma parceria. O\n"
	.string "que acha?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept::
	.string "É isso aí! Espera enquanto faço a\n"
	.string "inscriçao, tá?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject::
	.string "Espero que me deixe entrar na\n"
	.string "equipe da próxima vez, combinado?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro::
	.string "Sou o triatleta {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1::
	.string "Um {STR_VAR_2} com\n"
	.string "{STR_VAR_1} e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask::
	.string "outro {STR_VAR_2} que sabe\n"
	.string "usar {STR_VAR_1}. Esses sao os\l"
	.string "dois.\p"
	.string "O que acha? A gente formaria uma\n"
	.string "boa equipe.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept::
	.string "Gostei da resposta! Vou terminar a\n"
	.string "inscriçao rapidinho!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject::
	.string "Você vai me dar outra chance de\n"
	.string "formar uma parceria, né?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro::
	.string "Oi! E aí! Sou {STR_VAR_1}, uma\n"
	.string "nadadora!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1::
	.string "Olha quem eu treinei! Um\n"
	.string "{STR_VAR_2} com {STR_VAR_1}\l"
	.string "e$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask::
	.string "um {STR_VAR_2} com\n"
	.string "{STR_VAR_1}!\p"
	.string "Legal, né? Seria legal formar uma\n"
	.string "equipe também!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept::
	.string "Muito obrigada! Vou cuidar da\n"
	.string "inscriçao!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject::
	.string "Na próxima vez, você tem que fazer\n"
	.string "uma parceria comigo. Vai fazer, né?$"

