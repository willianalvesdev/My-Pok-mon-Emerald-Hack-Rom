MtChimney_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
	.byte 0

MtChimney_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

MtChimney_OnResume:
	setstepcallback STEP_CB_ASH
	end

MtChimney_EventScript_Archie::
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
	closemessage
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MtChimney_EventScript_ArchieGoStopTeamMagma::
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
	return

MtChimney_EventScript_ArchieBusyFighting::
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
	return

MtChimney_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_Delay48
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MT_CHIMNEY_MAXIE
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_1
	removeobject LOCALID_MT_CHIMNEY_TABITHA
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_2
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	fadescreenswapbuffers FADE_FROM_BLACK
	setobjectxyperm LOCALID_MT_CHIMNEY_ARCHIE, 10, 12
	addobject LOCALID_MT_CHIMNEY_ARCHIE
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
	removeobject LOCALID_MT_CHIMNEY_ARCHIE
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	releaseall
	end

MtChimney_EventScript_ArchieApproachPlayerEast::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieApproachPlayerNorth::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitEast::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitNorth::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitNorth
	waitmovement 0
	return

MtChimney_EventScript_LavaCookieLady::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
	checkmoney 200
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
.if OW_SHOW_ITEM_DESCRIPTIONS == OW_ITEM_DESCRIPTIONS_OFF
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	hidemoneybox
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end
.else
	hidemoneybox
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	release
	end
.endif @ OW_SHOW_ITEM_DESCRIPTIONS


MtChimney_EventScript_RemoveMoney::
	removemoney 200
	updatemoneybox
	return

MtChimney_EventScript_DeclineLavaCookie::
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_NotEnoughMoney::
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_Movement_ArchieApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MtChimney_Movement_ArchieExitEast:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_ArchieApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

MtChimney_Movement_ArchieExitNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused3:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused4:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused5:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused6:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused7:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused8:
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MtChimney_Movement_Unused9:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused10:
	walk_down
	step_end

MtChimney_Movement_Unused11:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused12:
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused13:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused14:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	face_right
	step_end

MtChimney_Movement_Unused15:
	walk_left
	walk_in_place_faster_right
	delay_16
	step_end

MtChimney_EventScript_BusyAquaGrunt1::
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt2::
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt3::
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_BusyMagmaGrunt1::
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt2::
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt3::
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt4::
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt5::
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt6::
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
	end

MtChimney_EventScript_MagmaPoochyena::
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
	end

MtChimney_EventScript_AquaPoochyena::
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
	end

MtChimney_EventScript_MeteoriteMachine::
	lockall
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
	giveitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_METEORITE
	releaseall
	end

MtChimney_EventScript_LeaveMeteoriteAlone::
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOff::
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOn::
	msgbox MtChimney_Text_MeteoriteFittedOnMachine, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_RouteSign::
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
	end

MtChimney_EventScript_Shelby::
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_DefeatedShelby::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SHELBY_1
	release
	end

MtChimney_EventScript_RematchShelby::
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Melissa::
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sheila::
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sawyer::
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_SawyerDefeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SAWYER_1
	release
	end

MtChimney_EventScript_SawyerRematch::
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_Text_MeteoriteWillActivateVolcano:
	.string "O poder deste Meteorite...\p"
	.string "Se esta máquina ampliar essa\n"
	.string "energia, a atividade do Mt. Chimney\l"
	.string "vai aumentar na hora...\p"
	.string "A energia vai crescer dentro da\n"
	.string "cratera e... Fufufu...$"

MtChimney_Text_MaxieIntro:
	.string "MAXIE: Hum? Quem é você?\p"
	.string "...\p"
	.string "Ouvi Archie reclamar de uma criança\n"
	.string "que andava atrapalhando a Team\l"
	.string "Aqua.\p"
	.string "Deve ser você.\p"
	.string "Hum! Entao agora pretende\n"
	.string "interferir na Team Magma?\p"
	.string "Escute. Desde muito tempo, os\n"
	.string "seres vivos usam a terra pra viver\l"
	.string "e crescer.\p"
	.string "Por isso ela é tao importante. É\n"
	.string "onde tudo começa!\p"
	.string "A Team Magma quer aumentar os\n"
	.string "continentes pra ajudar humanos e\l"
	.string "Pokémon a se desenvolverem.\p"
	.string "Pra isso, precisamos do poder que\n"
	.string "dorme nesta montanha...\p"
	.string "Ah! Você nao precisava saber\n"
	.string "tanto.\p"
	.string "Mas nao importa! Vou mostrar oque\n"
	.string "acontece com quem interfere no\l"
	.string "nosso grande plano!$"

MtChimney_Text_MaxieDefeat:
	.string "Oque?!\p"
	.string "Eu, Maxie, fui pego de surpresa?!$"

MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
	.string "MAXIE: Já chega. Vou recuar desta\n"
	.string "vez.\p"
	.string "Mas nao pense que viu o fim da\n"
	.string "Team Magma.\p"
	.string "Fufufu... Mesmo sem o Meteorite,\n"
	.string "se conseguirmos aquela Orb...\l"
	.string "Fufufu...$"

MtChimney_Text_TabithaIntro:
	.string "Hehehe!\p"
	.string "Entao você veio até aqui!\p"
	.string "Mas chegou tarde! Já entreguei o\n"
	.string "Meteorite de Meteor Falls pro\l"
	.string "chefe!$"

MtChimney_Text_TabithaDefeat:
	.string "Hehehe...\p"
	.string "Mesmo perdendo, se nosso líder\n"
	.string "acordar aquilo...$"

MtChimney_Text_TabithaPostBattle:
	.string "Chefe, rápido! Use a energia do\n"
	.string "Meteorite!\p"
	.string "Hehehe...$"

MtChimney_Text_Grunt2Intro:
	.string "A Team Magma trabalha pelo bem de\n"
	.string "todo mundo.\p"
	.string "Se aquele poder criar mais terra,\n"
	.string "vai ter mais lugar pra morar.\p"
	.string "Todo mundo vai ficar feliz!$"

MtChimney_Text_Grunt2Defeat:
	.string "Hein? Como assim eu perdi?$"

MtChimney_Text_Grunt2PostBattle:
	.string "Nosso chefe diz que isso vai\n"
	.string "deixar todo mundo feliz.\p"
	.string "Entao por que todo mundo tenta\n"
	.string "impedir a gente?$"

MtChimney_Text_Grunt1Intro:
	.string "Com mais terra, vou poder construir\n"
	.string "minha própria casa enorme!\p"
	.string "Vou fazer ela em cima da lava\n"
	.string "endurecida!$"

MtChimney_Text_Grunt1Defeat:
	.string "Meu sonho da casa própria...$"

MtChimney_Text_Grunt1PostBattle:
	.string "Uma criança como você devia estar\n"
	.string "brincando nas ondas!\p"
	.string "Deixa o financiamento imobiliário\n"
	.string "comigo!$"

MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
	.string "Essa Team Aqua irritante... Sempre\n"
	.string "estraga nossos planos!$"

MtChimney_Text_MeteoritesPackAmazingPower:
	.string "Os meteoritos têm um poder\n"
	.string "incrível!$"

MtChimney_Text_YouBetterNotMessWithUs:
	.string "É melhor nao se meter com a\n"
	.string "gente!\p"
	.string "Estamos tentando acordar aquilo\n"
	.string "pelo bem de todo mundo!$"

MtChimney_Text_AquasNameSimilar:
	.string "Nós somos a Team Magma!\p"
	.string "Eles sao a Team Aqua!\p"
	.string "Que raiva de terem um nome\n"
	.string "parecido com o nosso!$"

MtChimney_Text_DouseThemInFire:
	.string "Isso! Vamos acabar com eles no\n"
	.string "fogo!$"

MtChimney_Text_KeepMakingMoreLand:
	.string "Vamos criar cada vez mais terra!$"

MtChimney_Text_Bufoh:
	.string "Bufoh!$"

MtChimney_Text_ArchieGoStopTeamMagma:
	.string "ARCHIE: Grr, {PLAYER}! Eu devia\n"
	.string "imaginar que você apareceria!\p"
	.string "Veja oque esses malucos da Team\n"
	.string "Magma estao fazendo!\p"
	.string "Querem jogar a energia do\n"
	.string "Meteorite roubado no vulcao!\p"
	.string "Isso vai provocar uma erupçao!$"

MtChimney_Text_ArchieIHaveMyHandsFull:
	.string "ARCHIE: Grrr...\p"
	.string "Quero impedir Maxie, mas nao\n"
	.string "consigo!\p"
	.string "Já tô ocupado enfrentando três de\n"
	.string "uma vez!$"

MtChimney_Text_ArchieThankYou:
	.string "ARCHIE: Obrigado, {PLAYER}!\p"
	.string "Com sua ajuda, impedimos o plano\n"
	.string "de destruiçao da Team Magma!\p"
	.string "Mas... De que lado você está?\p"
	.string "Ah, nao importa.\p"
	.string "Vamos continuar de olho e seguir\n"
	.string "atrás da Team Magma.\p"
	.string "Nos veremos de novo, {PLAYER}!$"

MtChimney_Text_MagmaOutnumbersUs:
	.string "Droga... Tem mais gente da Team\n"
	.string "Magma! Nao estamos dando conta!$"

MtChimney_Text_LessHabitatForWaterPokemon:
	.string "Se aumentarem os continentes, os\n"
	.string "Pokémon aquáticos vao perder\l"
	.string "espaço pra viver!$"

MtChimney_Text_MagmasNameSimilar:
	.string "Nós somos a Team Aqua!\p"
	.string "Eles sao a Team Magma!\p"
	.string "Por que escolheram um nome que\n"
	.string "confunde tanto?$"

MtChimney_Text_Bushaa:
	.string "Bushaa!$"

MtChimney_Text_LavaCookiesJust200:
	.string "Lava Cookies sao a especialidade\n"
	.string "do Mt. Chimney.\p"
	.string "Quer experimentar? Só ¥200.$"

MtChimney_Text_ThankYouDear:
	.string "Obrigada, meu bem!$"

MtChimney_Text_YouveNotGotTheMoney:
	.string "Ah, meu bem. Sem dinheiro, nao dá\n"
	.string "pra comprar.$"

MtChimney_Text_OhFineThen:
	.string "Ah, tudo bem, entao.$"

MtChimney_Text_MeteoriteFittedOnMachine:
	.string "Tem um Meteorite encaixado numa\n"
	.string "máquina estranha...\p"
	.string "Parece que a máquina acumula\n"
	.string "energia nele.$"

MtChimney_Text_RemoveTheMeteorite:
	.string "Tem um Meteorite encaixado numa\n"
	.string "máquina estranha...\p"
	.string "Quer retirar o Meteorite?$"

MtChimney_Text_PlayerRemovedMeteorite:
	.string "{PLAYER} tirou o Meteorite da\n"
	.string "máquina.$"

MtChimney_Text_PlayerLeftMeteorite:
	.string "{PLAYER} deixou o Meteorite onde\n"
	.string "estava.$"

MtChimney_Text_MachineMakesNoResponse:
	.string "A máquina nao dá nenhum sinal de\n"
	.string "resposta.$"

MtChimney_Text_RouteSign:
	.string "{DOWN_ARROW} Jagged Pass Lavaridge Town à\n"
	.string "frente$"

MtChimney_Text_ShelbyIntro:
	.string "Passei nas fontes termais e\n"
	.string "descansei meus ossos cansados.\l"
	.string "Agora tô me sentindo forte!$"

MtChimney_Text_ShelbyDefeat:
	.string "Nossa, você é bom mesmo!$"

MtChimney_Text_ShelbyPostBattle:
	.string "Perdi... Agora nem sei se posso me\n"
	.string "chamar de especialista!$"

MtChimney_Text_ShelbyRegister:
	.string "Obrigada, meu bem. Foi divertido,\n"
	.string "parecia que eu tava batalhando com\l"
	.string "meu neto.\p"
	.string "Volte pra uma revanche qualquer\n"
	.string "dia.$"

MtChimney_Text_ShelbyRematchIntro:
	.string "Se você e seus Pokémon estiverem\n"
	.string "em sintonia, podem fazer coisas\l"
	.string "incríveis.$"

MtChimney_Text_ShelbyRematchDefeat:
	.string "Nossa, você é bom mesmo!$"

MtChimney_Text_ShelbyPostRematch:
	.string "Parece que seu coraçao e o dos\n"
	.string "seus Pokémon se tornaram um só.$"

MtChimney_Text_MelissaIntro:
	.string "Tô pegando fogo! Nao aguento\n"
	.string "mais, preciso batalhar!$"

MtChimney_Text_MelissaDefeat:
	.string "Uau, essa batalha foi quente!$"

MtChimney_Text_MelissaPostBattle:
	.string "O calor do Mt. Chimney me deixa no\n"
	.string "ponto!$"

MtChimney_Text_SheilaIntro:
	.string "Finalmente cheguei ao Mt. Chimney!\n"
	.string "Quero colocar meus Pokémon pra\l"
	.string "batalhar!$"

MtChimney_Text_SheilaDefeat:
	.string "Seu jeito de batalhar parece uma\n"
	.string "erupçao do Mt. Chimney!$"

MtChimney_Text_SheilaPostBattle:
	.string "Finalmente cheguei ao Mt. Chimney.\n"
	.string "Seria uma pena só olhar a\l"
	.string "paisagem.\p"
	.string "Quero batalhar um pouco e comprar\n"
	.string "Lava Cookies de lembrança.$"

MtChimney_Text_ShirleyIntro:
	.string "Desde que fui às fontes termais,\n"
	.string "tô me sentindo ótima! Tenho\l"
	.string "certeza que vou ganhar!$"

MtChimney_Text_ShirleyDefeat:
	.string "Ai! Fora da água ta dando um\n"
	.string "frio...$"

MtChimney_Text_ShirleyPostBattle:
	.string "Vou precisar entrar nas fontes\n"
	.string "termais de novo. Quer vir comigo?\p"
	.string "Tô brincando!$"

MtChimney_Text_SawyerIntro:
	.string "Que montanha boa! Cheia de gente\n"
	.string "quente pra fazer companhia!$"

MtChimney_Text_SawyerDefeat:
	.string "Ah, você também tem fogo no\n"
	.string "sangue!$"

MtChimney_Text_SawyerPostBattle:
	.string "Preciso ir às fontes termais de\n"
	.string "Lavaridge com o pessoal daqui!$"

MtChimney_Text_SawyerRegister:
	.string "Gosto de gente animada como você.\n"
	.string "Deixa eu registrar você no meu\l"
	.string "PokéNav.$"

MtChimney_Text_SawyerRematchIntro:
	.string "Tô feliz, cercado de gente animada\n"
	.string "por aqui. Nao vou perder!$"

MtChimney_Text_SawyerRematchDefeat:
	.string "Nossa, continua com o mesmo fogo\n"
	.string "de antes!$"

MtChimney_Text_SawyerPostRematch:
	.string "Na verdade, aqui é quente mesmo.\n"
	.string "Vim com roupa demais.$"
