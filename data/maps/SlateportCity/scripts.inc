SlateportCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
	.byte 0

SlateportCity_OnTransition:
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_EnterSlateport
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_MovePeopleForSternInterview
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
	end

SlateportCity_EventScript_EnterSlateport::
	setflag FLAG_VISITED_SLATEPORT_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
	return

SlateportCity_EventScript_MovePeopleForSternInterview::
	setobjectxyperm LOCALID_SLATEPORT_CAPT_STERN, 28, 13
	setobjectxyperm LOCALID_SLATEPORT_OLD_WOMAN, 25, 13
	setobjectxyperm LOCALID_SLATEPORT_RICH_BOY, 25, 14
	setobjectxyperm LOCALID_SLATEPORT_COOK, 27, 16
	setobjectxyperm LOCALID_SLATEPORT_GIRL, 28, 16
	setobjectxyperm LOCALID_SLATEPORT_FAT_MAN, 29, 16
	setobjectxyperm LOCALID_SLATEPORT_MAN_1, 31, 14
	setobjectmovementtype LOCALID_SLATEPORT_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_SLATEPORT_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_COOK, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_GIRL, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_FAT_MAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_MAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SlateportCity_EventScript_SetReadyForScottScene::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 23, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_MoveScottLeft::
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 22, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_OnFrame:
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
	.2byte 0

SlateportCity_EventScript_ScottScene::
	lockall
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceScott
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottApproachPlayer
	waitmovement 0
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 60
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_SCOTT
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 10, 12
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

SlateportCity_Movement_PlayerFaceScott:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ScottApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_Movement_ScottExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_EventScript_EnergyGuru::
	lock
	faceplayer
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
	waitmessage
	pokemart SlateportCity_Pokemart_EnergyGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_EnergyGuru:
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	pokemartlistend

SlateportCity_EventScript_EffortRibbonWoman::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SlateportCity_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_MonEVsNotMaxed::
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_MonHasEffortRibbon::
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Cook::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_CookSternInterview
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_CookSternInterview::
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWoman::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_OldWomanSternInterview
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWomanSternInterview::
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Girl::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_GirlSternInterview
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSternInterview::
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSecretBase::
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoy::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_RichBoySternInterview
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoySternInterview::
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_FatMan::
	goto_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_FatManSternInterview
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
	end

SlateportCity_EventScript_FatManSternInterview::
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man1::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_Man1SternInterview
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Man1SternInterview::
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1::
	lock
	faceplayer
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1AquaGone::
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_BattleTentSign::
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_SternsShipyardSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardNearsCompletion::
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardFerryComplete::
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_PokemonFanClubSign::
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_OceanicMuseumSign::
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_CitySign::
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
	end

SlateportCity_EventScript_MarketSign::
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_HarborSignFerryComplete::
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_NameRatersHouseSign::
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_Maniac::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_ManiacSternInterview
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

@ Unclear if the text here was meant to be different, but its not
SlateportCity_EventScript_ManiacSternInterview::
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman2::
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor1::
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor2::
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
	end

SlateportCity_EventScript_PokefanF::
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
	end

SlateportCity_EventScript_Man2::
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
	end

SlateportCity_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt5::
	lock
	faceplayer
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt6::
	lock
	faceplayer
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_6, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt7::
	lock
	faceplayer
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_7, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt8::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt9::
	lock
	faceplayer
	playse SE_PIN
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Movement_DelayAquaGrunt:
	delay_16
	delay_16
	step_end

SlateportCity_EventScript_AquaGrunt10::
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
	end

SlateportCity_EventScript_AquaGrunt11::
	lock
	faceplayer
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_11, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_DollClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor_Dolls:
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	pokemartlistend

SlateportCity_EventScript_ComeBackWithSecretPower::
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_DecorClerk::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor:
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	pokemartlistend

SlateportCity_EventScript_PowerTMClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs:
	.2byte ITEM_TM_HIDDEN_POWER
	.2byte ITEM_TM_SECRET_POWER
	pokemartlistend

SlateportCity_EventScript_BerryElder::
	lock
	faceplayer
	message SlateportCity_Text_BerryElderWelcome
	waitmessage
	pokemart SlateportCity_Pokemart_RareBerries
	msgbox SlateportCity_Text_BerryElderFarewell, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_RareBerries::
	.2byte ITEM_GANLON_BERRY
	.2byte ITEM_SALAC_BERRY
	.2byte ITEM_PETAYA_BERRY
	.2byte ITEM_APICOT_BERRY
	.2byte ITEM_ENIGMA_BERRY
	pokemartlistend

SlateportCity_Text_BerryElderWelcome:
	.string "Bem-vindo! Tenho Berries raras por\n"
	.string "¥20.000 cada.$"

SlateportCity_Text_BerryElderFarewell:
	.string "Volta quando quiser.$"

@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
SlateportCity_EventScript_CaptStern::
	lockall
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GABBY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 10
	applymovement LOCALID_SLATEPORT_TY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceStern
	applymovement LOCALID_SLATEPORT_GABBY, SlateportCity_Movement_GabbyExit
	applymovement LOCALID_SLATEPORT_TY, SlateportCity_Movement_TyExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_GABBY
	removeobject LOCALID_SLATEPORT_TY
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_COOK, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
	applymovement LOCALID_SLATEPORT_RICH_BOY, Common_Movement_QuestionMark
	applymovement LOCALID_SLATEPORT_MAN_1, SlateportCity_Movement_ManConcern
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
	waitmovement 0
	removeobject LOCALID_SLATEPORT_CAPT_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setvar VAR_SLATEPORT_CITY_STATE, 2
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
	waitstate
	releaseall
	end

SlateportCity_Movement_OldWomanConcern:
	delay_16
	delay_16
	emote_question_mark
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ManConcern:
	emote_question_mark
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_GabbyExit:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_TyExit:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_Unused:
	walk_down
	walk_in_place_faster_up
	step_end

SlateportCity_Movement_SternEnterHarbor:
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_Movement_SternWatchGabbyAndTyExit:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SlateportCity_Movement_PlayerEnterHarbor:
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_right
	walk_up
	step_end

SlateportCity_Movement_PlayerFaceStern:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_EventScript_Ty::
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
	end

SlateportCity_EventScript_Gabby::
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man3::
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
	end

SlateportCity_EventScript_BerryPowderClerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
	giveitem ITEM_POWDER_JAR
	setflag FLAG_RECEIVED_POWDER_JAR
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ReceivedPowderJar::
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ExplainBerryPowder::
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ChooseBerryPowderItem::
	message SlateportCity_Text_ExchangeWhatWithIt
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_EnergyPowder
	case 1, SlateportCity_EventScript_EnergyRoot
	case 2, SlateportCity_EventScript_HealPowder
	case 3, SlateportCity_EventScript_RevivalHerb
	case 4, SlateportCity_EventScript_Protein
	case 5, SlateportCity_EventScript_Iron
	case 6, SlateportCity_EventScript_Carbos
	case 7, SlateportCity_EventScript_Calcium
	case 8, SlateportCity_EventScript_Zinc
	case 9, SlateportCity_EventScript_HPUp
	case 10, SlateportCity_EventScript_PPUp
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
	end

SlateportCity_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_CancelPowderItemSelect::
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_TryBuyBerryPowderItem::
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NoRoomForBerryPowderItem::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NotEnoughBerryPowder::
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ScottBattleTentScene::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	opendoor 10, 12
	waitdooranim
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PushPlayerDown
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitBattleTent
	waitmovement 0
	closedoor 10, 12
	waitdooranim
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
	waitmovement 0
	removeobject LOCALID_SLATEPORT_SCOTT
	addvar VAR_SCOTT_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	releaseall
	end

SlateportCity_Movement_PushPlayerDown:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

SlateportCity_Movement_PlayerWatchScottExit:
	delay_16
	walk_in_place_faster_right
	step_end

SlateportCity_Movement_ScottExitBattleTent:
	delay_8
	walk_down
	step_end

SlateportCity_Movement_ScottExitAfterBattleTent:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_EventScript_BerryCrushRankingsSign::
	lockall
	special ShowBerryCrushRankings
	releaseall
	end

SlateportCity_Text_EnergyGuruSellWhatYouNeed:
	.string "Sou o Energy Guru! Vou vender\n"
	.string "tudo oque você precisa pra dar o\l"
	.string "seu melhor!$"

SlateportCity_Text_OhYourPokemon:
	.string "Ah? Seu {STR_VAR_1}...$"

SlateportCity_Text_PleaseGiveItThisEffortRibbon:
	.string "Se esforçou demais!\p"
	.string "Como recompensa, dê esta Effort\n"
	.string "Ribbon a ele.$"

SlateportCity_Text_ReceivedEffortRibbon:
	.string "{PLAYER} recebeu a Effort Ribbon.$"

SlateportCity_Text_PutEffortRibbonOnMon:
	.string "{PLAYER} colocou a Effort Ribbon em\n"
	.string "{STR_VAR_1}.$"

SlateportCity_Text_GoForItLittleHarder:
	.string "Precisa se esforçar um pouco mais.\p"
	.string "Se fizer isso, vou dar uma coisa\n"
	.string "boa pro seu Pokémon.$"

SlateportCity_Text_EffortRibbonLooksGoodOnIt:
	.string "Ah! Essa Effort Ribbon ficou ótima\n"
	.string "em {STR_VAR_1}!$"

SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
	.string "A luz do farol alcança muitos\n"
	.string "quilômetros.\p"
	.string "Será que nao assusta os Pokémon\n"
	.string "do mar?$"

SlateportCity_Text_SeaweedFullOfLife:
	.string "Olha só!\p"
	.string "As algas daqui sao fresquinhas,\n"
	.string "cheias de vida.\p"
	.string "Parece até que vao levantar e\n"
	.string "atacar!$"

SlateportCity_Text_HowTownIsBornAndGrows:
	.string "Onde a água é limpa, os alimentos\n"
	.string "chegam em grande quantidade.\p"
	.string "Onde as pessoas se encontram,\n"
	.string "surge um mercado.\p"
	.string "É assim que uma cidade nasce e\n"
	.string "cresce.$"

SlateportCity_Text_SlateportWonderfulPlace:
	.string "Fazer compras sentindo o cheiro do\n"
	.string "mar...\p"
	.string "Slateport é um lugar maravilhoso!$"

SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
	.string "Se deixar bonecos e almofadas no\n"
	.string "chao, eles vao sujar.\p"
	.string "Vou comprar uns blocos pra colocar\n"
	.string "embaixo e manter tudo limpo.$"

SlateportCity_Text_GoingToCompeteInBattleTent:
	.string "Uroooar! Também vou participar da\n"
	.string "Battle Tent!\p"
	.string "Mas antes preciso capturar uns\n"
	.string "Pokémon!$"

SlateportCity_Text_BushedHikingFromMauville:
	.string "Ufa... Tô acabado...\p"
	.string "Vim andando de Mauville City, mas\n"
	.string "esta cidade é enorme.\p"
	.string "Se soubesse, tinha vindo de\n"
	.string "bicicleta.$"

SlateportCity_Text_EveryoneCallsHimCaptStern:
	.string "Stern, que construiu o museu,\n"
	.string "também lidera uma equipe de\l"
	.string "exploraçao submarina.\p"
	.string "Por isso todo mundo chama ele de\n"
	.string "capitao Stern.$"

SlateportCity_Text_WhatsLongLineOverThere:
	.string "Oque é aquilo? Aquela fila\n"
	.string "enorme...$"

SlateportCity_Text_VisitedMuseumOften:
	.string "Quando era criança, vinha bastante\n"
	.string "ao museu.\p"
	.string "Depois de olhar as peças, ficava\n"
	.string "sonhando com os mistérios do mar.$"

SlateportCity_Text_QuitPushing:
	.string "Ei! Para de empurrar! Nao ta vendo\n"
	.string "a fila?$"

SlateportCity_Text_AquaHasPolicy:
	.string "Na Team Aqua, a regra é reunir e\n"
	.string "dispensar o pessoal no lugar da\l"
	.string "missao.$"

SlateportCity_Text_BossIsBrilliant:
	.string "Nosso chefe é um gênio.\p"
	.string "Oque será que ele quer com um\n"
	.string "museu?$"

SlateportCity_Text_WhatsNewSchemeIWonder:
	.string "Qual será o plano novo?\p"
	.string "Nosso chefe dá medo quando fica\n"
	.string "bravo. É melhor eu nao fazer\l"
	.string "besteira...$"

SlateportCity_Text_ShouldTakeItAll:
	.string "Se tiver alguma coisa útil no\n"
	.string "museu, vamos levar tudo!$"

SlateportCity_Text_DontButtIn:
	.string "Ei, você! Nao se mete!$"

SlateportCity_Text_RemindsMeOfLongLineForGames:
	.string "Uma fila enorme, hein?\p"
	.string "Lembra quando eu entrava na fila\n"
	.string "pra comprar jogo famoso...$"

SlateportCity_Text_WhyAreWeLiningUp:
	.string "Por que a gente ta na fila e ainda\n"
	.string "vai pagar? Era só entrar de uma\l"
	.string "vez!$"

SlateportCity_Text_WhatDoYouWant:
	.string "Oque foi? Oque você quer?$"

SlateportCity_Text_IllReadSignForYou:
	.string "Quer ler a placa? Eu leio pra\n"
	.string "você!$"

SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
	.string "Vamos ver...\p"
	.string "Hum... Acho que diz alguma coisa\n"
	.string "tipo “a vida no mar nao tem fim”.\p"
	.string "É, tenho quase certeza.$"

SlateportCity_Text_ShouldveBroughtMyGameBoy:
	.string "Resmungo...\p"
	.string "Devia ter trazido meu Game Boy\n"
	.string "Advance pra passar o tempo na\l"
	.string "fila...\p"
	.string "Resmungo...$"

SlateportCity_Text_HotSpringsAfterOperation:
	.string "“Quando a missao acabar, vou levar\n"
	.string "vocês às fontes termais!”\p"
	.string "Foi oque nosso líder disse. Mal\n"
	.string "posso esperar!$"

SlateportCity_Text_SeaIsSoWet:
	.string "O mar é tao grande...\p"
	.string "Será que foi feito das lágrimas\n"
	.string "dos Pokémon?$"

SlateportCity_Text_SinkOldBoats:
	.string "Sabe oque fazem com os navios\n"
	.string "velhos que nao conseguem mais\l"
	.string "navegar?\p"
	.string "Afundam eles pra virarem abrigo\n"
	.string "pros Pokémon.$"

SlateportCity_Text_BuyTooMuch:
	.string "Sempre que venho aqui, me empolgo\n"
	.string "e compro demais.$"

SlateportCity_Text_GetNameRaterToHelpYou:
	.string "Se quiser mudar o apelido do seu\n"
	.string "Pokémon, procure o Name Rater.$"

SlateportCity_Text_CantChangeTradeMonName:
	.string "Nao dá pra mudar o apelido de um\n"
	.string "Pokémon recebido numa troca.\p"
	.string "O carinho do treinador original ta\n"
	.string "naquele nome.$"

SlateportCity_Text_BattleTentBuiltRecently:
	.string "Construíram uma Battle Tent em\n"
	.string "Slateport faz pouco tempo.\p"
	.string "Ginásios sao legais, mas ela tem\n"
	.string "sua própria graça.\p"
	.string "Vá encontrar Pokémon fortes pra\n"
	.string "participar!$"

SlateportCity_Text_CaptSternBeingInterviewed:
	.string "Achei que era algum artista famoso\n"
	.string "e vim pedir autógrafo.\p"
	.string "Mas quem ta dando entrevista? Nao\n"
	.string "é o capitao Stern?$"

SlateportCity_Text_InterviewerSoCool:
	.string "Aquela repórter é tao bonita e\n"
	.string "legal!\p"
	.string "Quando crescer, quero ser\n"
	.string "jornalista e viajar pelo mundo!$"

SlateportCity_Text_SternSaysDiscoveredSomething:
	.string "O capitao Stern disse que\n"
	.string "descobriram alguma coisa no fundo\l"
	.string "do mar.\p"
	.string "Oque será que é?$"

SlateportCity_Text_CaptainComeBackWithBigFish:
	.string "Oque ta acontecendo?\p"
	.string "O capitao voltou com algum peixao\n"
	.string "do fundo do mar?$"

SlateportCity_Text_AmIOnTV:
	.string "Ei! Tao vendo? Tô aparecendo na\n"
	.string "televisao?$"

SlateportCity_Text_CaptainsACelebrity:
	.string "Uma entrevista na televisao! Aqui!\n"
	.string "O capitao ficou famoso!$"

SlateportCity_Text_BigSmileForCamera:
	.string "TY: Certo, capitao Stern, um\n"
	.string "sorriso pra câmera!$"

SlateportCity_Text_MostInvaluableExperience:
	.string "GABBY: Entendo. Foi uma\n"
	.string "experiência muito importante...$"

SlateportCity_Text_SternMoveAheadWithExploration:
	.string "CAPT. STERN: Sim. Pretendemos\n"
	.string "continuar a exploraçao.$"

SlateportCity_Text_GabbyWonderfulThanksForInterview:
	.string "GABBY: Que ótimo, capitao Stern!\n"
	.string "Obrigada por separar um tempo pra\l"
	.string "conversar com a gente.\p"
	.string "Esperamos entrevistar você de novo\n"
	.string "com mais descobertas!$"

SlateportCity_Text_SternWhewFirstInterview:
	.string "CAPT. STERN: Ufa...\p"
	.string "Foi minha primeira vez na\n"
	.string "televisao. Fiquei nervoso demais.$"

SlateportCity_Text_OhPlayerWeMadeDiscovery:
	.string "Ah, {PLAYER}{KUN}! Você parece ótimo!\p"
	.string "Fizemos uma grande descoberta na\n"
	.string "última exploraçao submarina.\p"
	.string "Encontramos uma caverna submersa\n"
	.string "na Route 128.\p"
	.string "Achamos que é o lar de um Pokémon\n"
	.string "que todos pensavam ter\l"
	.string "desaparecido há muito tempo.$"

SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
	.string "Fufufu... Capitao Stern, imagino.\p"
	.string "Nós, da Team Aqua, vamos assumir o\n"
	.string "controle do seu submarino!\p"
	.string "Nao adianta reclamar. Esperamos\n"
	.string "sua colaboraçao!\p"
	.string "Fufufu... Veja oque a Team Aqua\n"
	.string "planejou!$"

SlateportCity_Text_SternWhatWasAllThat:
	.string "CAPT. STERN: Oque foi isso?\p"
	.string "Parecia alguém falando num\n"
	.string "megafone...\p"
	.string "De onde veio?$"

SlateportCity_Text_FromHarborTryingToTakeSub:
	.string "Veio do porto!\p"
	.string "O submarino! Tao tentando levar\n"
	.string "ele!$"

SlateportCity_Text_PleaseComeWithMe:
	.string "{PLAYER}{KUN}! Venha comigo, por favor!$"

SlateportCity_Text_BattleTentSign:
	.string "Battle Tent de Slateport\p"
	.string "“Encontre o Pokémon ideal!”$"

SlateportCity_Text_SternsShipyardWantedSign:
	.string "Stern's Shipyard\p"
	.string "“Procura-se marinheiro capaz de\n"
	.string "navegar em qualquer correnteza.”$"

SlateportCity_Text_SternsShipyardNearsCompletion:
	.string "Stern's Shipyard\p"
	.string "“O S.S. Tidal está quase pronto\n"
	.string "para ligar os portos de Slateport\l"
	.string "e Lilycove.”$"

SlateportCity_Text_SternsShipyardFerryComplete:
	.string "Stern's Shipyard\p"
	.string "“O embarque no S.S. Tidal, entre\n"
	.string "Slateport e Lilycove, é feito no\l"
	.string "porto.”$"

SlateportCity_Text_PokemonFanClubSign:
	.string "Fa-clube Pokémon\p"
	.string "“Chamando todos os fas de\n"
	.string "Pokémon!”$"

SlateportCity_Text_OceanicMuseumSign:
	.string "“O mar sem fim sustenta toda a\n"
	.string "vida.”\p"
	.string "Oceanic Museum$"

SlateportCity_Text_CitySign:
	.string "Slateport City\p"
	.string "“O porto onde pessoas e Pokémon\n"
	.string "se encontram.”$"

SlateportCity_Text_MarketSign:
	.string "Slateport Market\p"
	.string "“Produtos que você nao encontra\n"
	.string "em outro lugar!”$"

SlateportCity_Text_HarborFerryUnderConstruction:
	.string "Porto de Slateport\p"
	.string "“O S.S. Tidal está sendo\n"
	.string "construído no estaleiro.\p"
	.string "As viagens vao começar em breve.”$"

SlateportCity_Text_HarborSign:
	.string "Porto de Slateport\p"
	.string "“Aproveite um belo passeio a bordo\n"
	.string "do S.S. Tidal.”$"

SlateportCity_Text_NameRatersHouseSign:
	.string "Casa do Name Rater\p"
	.string "“Avaliamos apelidos de Pokémon.”$"

SlateportCity_Text_ExplainBerries:
	.string "Um Pokémon selvagem machucado\n"
	.string "pode se curar comendo Berries.\l"
	.string "Sabia disso?\p"
	.string "Alguém viu isso e teve a ideia de\n"
	.string "fazer remédios com elas. Sabia\l"
	.string "disso?\p"
	.string "Pra transformar Berries em remédio,\n"
	.string "primeiro precisa moer elas. Sabia\l"
	.string "disso?\p"
	.string "Você parece gostar de Berries!\n"
	.string "Tenho uma coisa boa pra você.$"

SlateportCity_Text_ExplainBerryPowder:
	.string "Instalei máquinas pra moer Berries\n"
	.string "nos Centros Pokémon.\p"
	.string "As máquinas Berry Crush ficam no\n"
	.string "Direct Corner, lá em cima. Sabia\l"
	.string "disso?\p"
	.string "Pode fazer Berry Powder pra mim?\p"
	.string "Se trouxer bastante, faço vários\n"
	.string "remédios pra você.$"

SlateportCity_Text_BroughtMeSomeBerryPowder:
	.string "Trouxe Berry Powder pra mim?$"

SlateportCity_Text_ExchangeWhatWithIt:
	.string "Pelo que quer trocar?$"

SlateportCity_Text_ExchangeBerryPowderForItem:
	.string "Quer trocar seu Berry Powder por\n"
	.string "{STR_VAR_1}?$"

SlateportCity_Text_DontHaveEnoughBerryPowder:
	.string "Ah, que pena. Você nao tem Berry\n"
	.string "Powder suficiente.$"

SlateportCity_Text_FineBerryPowderTradeSomethingElse:
	.string "Esse Berry Powder é ótimo. Vai\n"
	.string "render um bom remédio.\p"
	.string "Quer trocar mais por outra coisa?$"

SlateportCity_Text_WhenYouGetMoreBringItToMe:
	.string "Certo! Quando conseguir mais Berry\n"
	.string "Powder, traga pra mim, por favor!$"

SlateportCity_Text_ComeBackToTradeBerryPowder:
	.string "Volte quando quiser trocar Berry\n"
	.string "Powder por remédios.\p"
	.string "Sempre tenho minha barraca aqui.\p"
	.string "Sabia disso?$"

SlateportCity_Text_YouDroveTeamAquaAway:
	.string "SCOTT: Hein? Tenho certeza que já\n"
	.string "encontrei você antes.\p"
	.string "Já me apresentei? Sou Scott.\p"
	.string "Acabei de ver a Team Aqua saindo\n"
	.string "daqui na maior correria.\p"
	.string "Deixa eu adivinhar: foi você que\n"
	.string "espantou eles?$"

SlateportCity_Text_MaybeThisTrainer:
	.string "SCOTT: Hum... Talvez este\n"
	.string "treinador...$"

SlateportCity_Text_LetsRegisterEachOther:
	.string "SCOTT: Muito bem! Acho que vamos\n"
	.string "ser bons amigos.\p"
	.string "Vamos registrar um ao outro no\n"
	.string "PokéNav.\p"
	.string "...$"

SlateportCity_Text_RegisteredScott:
	.string "Esse tal de Scott foi registrado\n"
	.string "no PokéNav.$"

SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
	.string "SCOTT: Queria acompanhar você, mas\n"
	.string "também preciso conhecer o talento\l"
	.string "de outras pessoas.\p"
	.string "Vou visitar mais algumas cidades.\p"
	.string "Até mais, {PLAYER}{KUN}!$"

SlateportCity_Text_TakingBattleTentChallenge:
	.string "SCOTT: Opa, {PLAYER}{KUN}!\p"
	.string "Deixa eu adivinhar, {PLAYER}{KUN}: vai\n"
	.string "desafiar a Battle Tent?\p"
	.string "Ótima ideia! Um treinador forte\n"
	.string "combina muito com esse lugar.\p"
	.string "Dê o seu melhor!$"
