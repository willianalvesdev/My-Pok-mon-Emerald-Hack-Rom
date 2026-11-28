MauvilleCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_Gym_OnLoad
	.byte 0

MauvilleCity_Gym_OnLoad:
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_DeactivatePuzzle
	switch VAR_MAUVILLE_GYM_STATE
	case 0, MauvilleCity_Gym_EventScript_UpdateBarriers
	case 1, MauvilleCity_Gym_EventScript_Switch1Pressed
	case 2, MauvilleCity_Gym_EventScript_Switch2Pressed
	case 3, MauvilleCity_Gym_EventScript_Switch3Pressed
	case 4, MauvilleCity_Gym_EventScript_Switch4Pressed
	end

MauvilleCity_Gym_EventScript_UpdateBarriers::
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetAltBarriers
	end

MauvilleCity_Gym_EventScript_SetAltBarriers::
	setmetatile 3, 11, METATILE_MauvilleGym_RedBeamV1_On, TRUE
	setmetatile 3, 12, METATILE_MauvilleGym_RedBeamV2_On, TRUE
	setmetatile 3, 13, METATILE_MauvilleGym_PoleTop_On, TRUE
	setmetatile 4, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 5, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 4, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 5, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 7, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 8, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 7, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 8, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 4, 13, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 13, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 14, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 14, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 1, 10, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 2, 10, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 1, 11, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 2, 11, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 6, 8, METATILE_MauvilleGym_PoleBottom_On, TRUE
	setmetatile 6, 9, METATILE_MauvilleGym_FloorTile, FALSE
	setmetatile 6, 10, METATILE_MauvilleGym_PoleTop_Off, FALSE
	setmetatile 4, 6, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 6, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 7, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 7, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	end

MauvilleCity_Gym_EventScript_Switch1Pressed::
	setvar VAR_0x8004, 0
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch2Pressed::
	setvar VAR_0x8004, 1
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch3Pressed::
	setvar VAR_0x8004, 2
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch4Pressed::
	setvar VAR_0x8004, 3
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_DeactivatePuzzle::
	special MauvilleGymDeactivatePuzzle
	end

MauvilleCity_Gym_EventScript_Wattson::
	trainerbattle_single TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonIntro, MauvilleCity_Gym_Text_WattsonDefeat, MauvilleCity_Gym_EventScript_WattsonDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_Gym_EventScript_WattsonRematch
	goto_if_unset FLAG_RECEIVED_TM_SHOCK_WAVE, MauvilleCity_Gym_EventScript_GiveShockWave2
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_Gym_EventScript_CompletedNewMauville
	msgbox MauvilleCity_Gym_Text_WattsonPostBattle, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonDefeated::
	message MauvilleCity_Gym_Text_ReceivedDynamoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	clearflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_BADGE03_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	special MauvilleGymDeactivatePuzzle
	special DrawWholeMapView
	playse SE_UNLOCK
	call MauvilleCity_Gym_EventScript_GiveShockWave
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Gym_Text_RegisteredWattson, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave2::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	return

MauvilleCity_Gym_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonRematch::
	trainerbattle_rematch_double TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonPreRematch, MauvilleCity_Gym_Text_WattsonRematchDefeat, MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons
	msgbox MauvilleCity_Gym_Text_WattsonPostRematch, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 1, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 1
	setvar VAR_0x8004, 0
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 2, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 2
	setvar VAR_0x8004, 1
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 3, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 3
	setvar VAR_0x8004, 2
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 4, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 4
	setvar VAR_0x8004, 3
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_PressFloorSwitch::
	special MauvilleGymSetDefaultBarriers
	special MauvilleGymPressSwitch
	special DrawWholeMapView
	playse SE_UNLOCK
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_ClearBarriersAltState
	goto_if_unset FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetBarriersAltState
	releaseall
	end

MauvilleCity_Gym_EventScript_SwitchDoNothing::
	releaseall
	end

MauvilleCity_Gym_EventScript_SetBarriersAltState::
	setflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_ClearBarriersAltState::
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK, MauvilleCity_Gym_Text_KirkIntro, MauvilleCity_Gym_Text_KirkDefeat
	msgbox MauvilleCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_SHAWN, MauvilleCity_Gym_Text_ShawnIntro, MauvilleCity_Gym_Text_ShawnDefeat
	msgbox MauvilleCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Ben::
	trainerbattle_single TRAINER_BEN, MauvilleCity_Gym_Text_BenIntro, MauvilleCity_Gym_Text_BenDefeat
	msgbox MauvilleCity_Gym_Text_BenPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Vivian::
	trainerbattle_single TRAINER_VIVIAN, MauvilleCity_Gym_Text_VivianIntro, MauvilleCity_Gym_Text_VivianDefeat
	msgbox MauvilleCity_Gym_Text_VivianPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Angelo::
	trainerbattle_single TRAINER_ANGELO, MauvilleCity_Gym_Text_AngeloIntro, MauvilleCity_Gym_Text_AngeloDefeat
	msgbox MauvilleCity_Gym_Text_AngeloPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_GymGuidePostVictory
	msgbox MauvilleCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MauvilleCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_GymStatueCertified::
	msgbox MauvilleCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_EventScript_GymStatue::
	msgbox MauvilleCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_Text_GymGuideAdvice:
	.string "E aí, {PLAYER}, futuro campeao!\p"
	.string "Wattson, o líder daqui, usa\n"
	.string "Pokémon do tipo Electric.\p"
	.string "Se vier com Pokémon do tipo Water,\n"
	.string "vai tomar choque! Bzzt!\p"
	.string "Ele também encheu o ginásio de\n"
	.string "portas controladas por botoes. Uma\l"
	.string "figura!\p"
	.string "Vai com tudo!$"

MauvilleCity_Gym_Text_GymGuidePostVictory:
	.string "Nossa, você ta eletrizante! Até\n"
	.string "abriu a porta!$"

MauvilleCity_Gym_Text_KirkIntro:
	.string "Minha alma elétrica vai acabar com\n"
	.string "seus sonhos! Uou, yeah!$"

MauvilleCity_Gym_Text_KirkDefeat:
	.string "Isso foi ligado, amplificado e\n"
	.string "eletrizante demais, cara!$"

MauvilleCity_Gym_Text_KirkPostBattle:
	.string "Pokémon e rock precisam de\n"
	.string "coraçao! Uou, yeah!$"

MauvilleCity_Gym_Text_ShawnIntro:
	.string "Treinei com Wattson! Nao vou\n"
	.string "perder tao fácil!$"

MauvilleCity_Gym_Text_ShawnDefeat:
	.string "Desligado da tomada...$"

MauvilleCity_Gym_Text_ShawnPostBattle:
	.string "Wattson treina faz muito, muito\n"
	.string "tempo.\p"
	.string "Esse velho já batalhava antes do\n"
	.string "seu pai nascer!$"

MauvilleCity_Gym_Text_BenIntro:
	.string "Este ginásio tem quebra-cabeças!\n"
	.string "Legal, né?$"

MauvilleCity_Gym_Text_BenDefeat:
	.string "Perder nao tem graça...$"

MauvilleCity_Gym_Text_BenPostBattle:
	.string "Wattson gosta de preparar umas\n"
	.string "armadilhas com botoes.$"

MauvilleCity_Gym_Text_VivianIntro:
	.string "Meu charme e os golpes dos meus\n"
	.string "Pokémon vao deixar você em\l"
	.string "choque!$"

MauvilleCity_Gym_Text_VivianDefeat:
	.string "Sua força me deixou em choque!$"

MauvilleCity_Gym_Text_VivianPostBattle:
	.string "Ouvi dizer que Wattson fundou\n"
	.string "Mauville.\p"
	.string "Ele já era treinador muito antes\n"
	.string "da gente. Deve saber muita coisa!$"

MauvilleCity_Gym_Text_AngeloIntro:
	.string "Eu adoro coisas brilhantes!$"

MauvilleCity_Gym_Text_AngeloDefeat:
	.string "Ah... Meus olhos tao até\n"
	.string "cansados...$"

MauvilleCity_Gym_Text_AngeloPostBattle:
	.string "Wattson tem a testa brilhante.\n"
	.string "Gosto disso!\p"
	.string "Nem precisa de lanterna no apagao.$"

MauvilleCity_Gym_Text_WattsonIntro:
	.string "Desisti de reformar a cidade\n"
	.string "inteira.\p"
	.string "Agora passo o tempo criando\n"
	.string "armadilhas com portas no meu\l"
	.string "ginásio.\p"
	.string "Opa! Oque você faz aqui?\p"
	.string "Passou por todas as minhas portas?\p"
	.string "Wahahahah! Que divertido!\p"
	.string "Entao eu, Wattson, líder do\n"
	.string "ginásio de Mauville, vou deixar\l"
	.string "você eletrizado!$"

MauvilleCity_Gym_Text_WattsonDefeat:
	.string "Wahahahah! Muito bem, perdi!\p"
	.string "Você me deu uma batalha\n"
	.string "emocionante! Pegue esta insígnia!$"

MauvilleCity_Gym_Text_ReceivedDynamoBadge:
	.string "{PLAYER} recebeu a Dynamo Badge de\n"
	.string "Wattson.$"

MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis:
	.string "Com a Dynamo Badge, seus Pokémon\n"
	.string "podem usar Rock Smash fora das\l"
	.string "batalhas.\p"
	.string "Ela também deixa seus Pokémon um\n"
	.string "pouco mais rápidos.\p"
	.string "Hum... Leve isto também!$"

MauvilleCity_Gym_Text_ExplainShockWave:
	.string "A TM34 tem Shock Wave.\p"
	.string "É um golpe que nunca erra. Pode\n"
	.string "confiar nele!\p"
	.string "...$"

MauvilleCity_Gym_Text_RegisteredWattson:
	.string "O líder Wattson foi registrado no\n"
	.string "PokéNav.$"

MauvilleCity_Gym_Text_WattsonPostBattle:
	.string "Ver um jovem treinador com tanto\n"
	.string "futuro me deixa cheio de\l"
	.string "esperança!$"

MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor:
	.string "Wahahahah! Vá em frente e\n"
	.string "continue se esforçando!$"

MauvilleCity_Gym_Text_GymStatue:
	.string "Ginásio Pokémon de Mauville City$"

MauvilleCity_Gym_Text_GymStatueCertified:
	.string "Ginásio Pokémon de Mauville City\p"
	.string "Treinadores aprovados por Wattson:\n"
	.string "{PLAYER}$"

MauvilleCity_Gym_Text_WattsonPreRematch:
	.string "WATTSON: Ahá! Finalmente chegou!\n"
	.string "Já sei oque você quer: batalhar\l"
	.string "com meus Pokémon!\p"
	.string "Wahahahaha!\p"
	.string "Vou fazer as faíscas voarem!\n"
	.string "Depois nao diga que nao avisei!$"

MauvilleCity_Gym_Text_WattsonRematchDefeat:
	.string "Ufa... Nossas baterias acabaram...$"

MauvilleCity_Gym_Text_WattsonPostRematch:
	.string "WATTSON: Precisamos recarregar as\n"
	.string "baterias.\p"
	.string "Quando estivermos com a carga\n"
	.string "cheia, vamos aceitar seu desafio\l"
	.string "com prazer.\p"
	.string "Volta aqui outra hora, combinado?$"

MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons:
	.string "WATTSON: Ahá! Finalmente chegou!\n"
	.string "Já sei oque você quer: batalhar\l"
	.string "com meus Pokémon!\p"
	.string "Wahahahaha!\p"
	.string "Opa, espera! Você só trouxe um\n"
	.string "Pokémon!\p"
	.string "Volte com pelo menos dois, ta bom?$"

