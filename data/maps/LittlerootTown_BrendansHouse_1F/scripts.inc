LittlerootTown_BrendansHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad:
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes::
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	return

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual::
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return

LittlerootTown_BrendansHouse_1F_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 8, 4
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 4, 5
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 9, 8
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
LittlerootTown_BrendansHouse_1F_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 1, LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock::
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 7, 1
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs:
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn::
	lockall
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
	setvar VAR_0x8005, MALE
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport::
	lockall
	setvar VAR_0x8004, MALE
	setvar VAR_0x8005, LOCALID_PLAYERS_HOUSE_1F_MOM
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
	end

LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor::
	lockall
	playse SE_PIN
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
	waitmovement 0
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom::
	lockall
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
	setvar VAR_0x8005, MALE
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0::
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1::
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2::
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival::
	playse SE_EXIT
	delay 10
	addobject LOCALID_RIVALS_HOUSE_1F_RIVAL
	delay 30
	playse SE_PIN
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call_if_ne VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2
	playse SE_EXIT
	removeobject LOCALID_RIVALS_HOUSE_1F_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	delay 30
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1:
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1:
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

PlayersHouse_1F_Text_IsntItNiceInHere:
	.string "MAE: Olha só, {PLAYER}! Aqui dentro\n"
	.string "até que é bonitinho, nao é?$"

PlayersHouse_1F_Text_MoversPokemonGoSetClock:
	.string "Os Pokémons da mudança carregam\n"
	.string "tudo e ainda deixam a casa\l"
	.string "arrumada. Que belezinha!\p"
	.string "{PLAYER}, seu quarto fica lá em\n"
	.string "cima. Vai lá ver!\p"
	.string "Seu pai aquele ausente comprou um\n"
	.string "relógio novo pra você. Lembra de\l"
	.string "acertar a hora depois tabom?$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom:
	.string "MAE: Eai, {PLAYER}? Cadê a\n"
	.string "curiosidade pra ver o seu quarto\l"
	.string "novo?$"

PlayersHouse_1F_Text_GoSetTheClock:
	.string "MAE: {PLAYER}, vai acertar o relógio\n"
	.string "do seu quarto.$"

PlayersHouse_1F_Text_OhComeQuickly:
	.string "MAE: {PLAYER}! {PLAYER}! Vem cá,\n"
	.string "rápido!$"

PlayersHouse_1F_Text_MaybeDadWillBeOn:
	.string "MAE: Olha! É o ginásio de\n"
	.string "Petalburg! Talvez seu pai apareça!$"

PlayersHouse_1F_Text_ItsOverWeMissedHim:
	.string "MAE: Ah... Acabou.\p"
	.string "Acho que seu pai apareceu, mas a\n"
	.string "gente perdeu. Que pena.$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor:
	.string "Ah, um amigo do seu pai mora aqui\n"
	.string "na cidade.\p"
	.string "É o professor Birch.\p"
	.string "Ele mora bem ao lado. Vai lá se\n"
	.string "apresentar.$"

PlayersHouse_1F_Text_SeeYouHoney:
	.string "MAE: Até mais, meu bem!$"

PlayersHouse_1F_Text_DidYouMeetProfBirch:
	.string "MAE: Já foi se apresentar pro\n"
	.string "professor Birch?$"

PlayersHouse_1F_Text_YouShouldRestABit:
	.string "MAE: Como você ta, {PLAYER}?\n"
	.string "Parece meio cansado.\p"
	.string "Descansa um pouco.$"

PlayersHouse_1F_Text_TakeCareHoney:
	.string "MAE: Se cuida, meu bem!$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom:
	.string "MAE: Ah, seu pai te deu essa\n"
	.string "insígnia?\p"
	.string "Entao aqui vai um presente da sua\n"
	.string "mae!$"

PlayersHouse_1F_Text_DontPushYourselfTooHard:
	.string "Nao precisa se cobrar tanto, meu\n"
	.string "bem. Você sempre pode voltar pra\l"
	.string "casa.\p"
	.string "Vai lá, você consegue!$"

PlayersHouse_1F_Text_IsThatAPokenav:
	.string "MAE: Oque é isso, meu bem? Um\n"
	.string "PokéNav? Alguém da Devon te deu?\p"
	.string "Que tal registrar sua mae também?\p"
	.string "...$"

PlayersHouse_1F_Text_RegisteredMom:
	.string "MAE foi registrada no PokéNav.$"

PlayersHouse_1F_Text_Vigoroth1:
	.string "Fugiiiiih!$"

PlayersHouse_1F_Text_Vigoroth2:
	.string "Huggoh, uggo uggo...$"

PlayersHouse_1F_Text_ReportFromPetalburgGym:
	.string "REPÓRTER: ...Esta foi nossa\n"
	.string "reportagem direto da frente do\l"
	.string "ginásio de Petalburg.$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
	.string "Tem um filme passando na\n"
	.string "televisao.\p"
	.string "Dois homens dançam em um teclado\n"
	.string "de piano gigante.\p"
	.string "Melhor ir!$"

PlayersHouse_1F_Text_RunningShoesManual:
	.string "É o manual dos Running Shoes.\p"
	.string "“Segure o botao B pra correr\n"
	.string "usando os Running Shoes.\p"
	.string "Amarre os cadarços e pegue a\n"
	.string "estrada!”$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou:
	.string "PAI: Hum?\p"
	.string "Olha só, {PLAYER}!\p"
	.string "Faz tempo que nao vejo você.\n"
	.string "Parece mais forte.\p"
	.string "É a impressao que eu tenho. Mas\n"
	.string "seu velho ainda nao desistiu!\p"
	.string "Ah, tenho uma coisa pra você.\n"
	.string "Alguém chamado Mr. Briney mandou\l"
	.string "isto.$"

PlayersHouse_1F_Text_PortsInSlateportLilycove:
	.string "PAI: Hum, um Ticket de barco?\p"
	.string "Se nao me engano, tem portos em\n"
	.string "Slateport e Lilycove.$"

PlayersHouse_1F_Text_BetterGetBackToGym:
	.string "Preciso voltar pro ginásio de\n"
	.string "Petalburg.\p"
	.string "Obrigado por cuidar da casa\n"
	.string "enquanto tô fora.$"

PlayersHouse_1F_Text_DadShouldStayLonger:
	.string "MAE: Esse seu pai...\p"
	.string "Depois de tanto tempo sem vir, só\n"
	.string "fala de Pokémon.\p"
	.string "Podia relaxar e ficar mais um\n"
	.string "pouco.$"

PlayersHouse_1F_Text_IsThatABreakingStory:
	.string "MAE: É uma notícia de última hora?$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash:
	.string "Interrompemos a programaçao com\n"
	.string "uma notícia urgente!\p"
	.string "Um Pokémon de cor BZZT... foi\n"
	.string "visto voando em vários lugares de\l"
	.string "Hoenn.\p"
	.string "Ainda nao sabemos que Pokémon é\n"
	.string "esse.\p"
	.string "Voltamos agora ao filme.$"

PlayersHouse_1F_Text_WhatColorDidTheySay:
	.string "MAE: {PLAYER}, você ouviu?\p"
	.string "Que cor o repórter disse que o\n"
	.string "Pokémon tinha?$"

PlayersHouse_1F_Text_StillUnknownPokemon:
	.string "MAE: Olha só! Ainda tem Pokémon\n"
	.string "que ninguém conhece.$"
