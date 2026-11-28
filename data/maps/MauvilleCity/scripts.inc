MauvilleCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_OnTransition
	.byte 0

MauvilleCity_OnTransition:
	setflag FLAG_VISITED_MAUVILLE_CITY
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	clearflag FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION
	setflag FLAG_SYS_TV_START
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	setvar VAR_MAUVILLE_GYM_STATE, 0
	call_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_MoveWattsonBackToGym
	end

MauvilleCity_EventScript_MoveWattsonBackToGym::
	clearflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	setflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setflag FLAG_WATTSON_REMATCH_AVAILABLE
	return

MauvilleCity_EventScript_Boy::
	msgbox MauvilleCity_Text_NurseHurtMonBackToHealth, MSGBOX_NPC
	end

MauvilleCity_EventScript_Maniac::
	msgbox MauvilleCity_Text_AllSortsOfPeopleComeThrough, MSGBOX_NPC
	end

MauvilleCity_EventScript_Woman::
	msgbox MauvilleCity_Text_RydelVeryGenerous, MSGBOX_NPC
	end

MauvilleCity_EventScript_RichBoy::
	msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike, MSGBOX_NPC
	end

MauvilleCity_EventScript_CitySign::
	msgbox MauvilleCity_Text_CitySign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GymSign::
	msgbox MauvilleCity_Text_GymSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_BikeShopSign::
	msgbox MauvilleCity_Text_BikeShopSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GameCornerSign::
	msgbox MauvilleCity_Text_GameCornerSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_SchoolKidM::
	lock
	faceplayer
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_TVExplained
	msgbox MauvilleCity_Text_ExplainTV, MSGBOX_DEFAULT
	setflag FLAG_TV_EXPLAINED
	release
	end

MauvilleCity_EventScript_TVExplained::
	msgbox MauvilleCity_Text_BeenCheckingOutTV, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_UncleAskPlayerToBattleWally
	msgbox MauvilleCity_Text_UncleHesTooPeppy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_UncleAskPlayerToBattleWally::
	msgbox MauvilleCity_Text_UncleCanYouBattleWally, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Wally::
	lockall
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_WallyRequestBattleAgain
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWantToChallengeGym, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_UncleYourePushingIt, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_WallyWeCanBeatAnyone, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWillYouBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_EventScript_BattleWallyPrompt::
	call_if_eq VAR_RESULT, YES, MauvilleCity_EventScript_BattleWally
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_DeclineWallyBattle
	closemessage
	switch VAR_FACING
	case DIR_NORTH, MauvilleCity_EventScript_WallyAndUncleExitNorth
	case DIR_EAST, MauvilleCity_EventScript_WallyAndUncleExitEast
	end

MauvilleCity_EventScript_WallyAndUncleExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth1
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerFaceUncleNorth
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerNorth
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_WallyAndUncleExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast1
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerEast
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_DefeatedWally::
	removeobject LOCALID_MAUVILLE_WALLY
	removeobject LOCALID_MAUVILLE_WALLYS_UNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_WALLY_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottApproachPlayerNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottApproachPlayerEast
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MauvilleCity_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottExitEast
	removeobject LOCALID_MAUVILLE_SCOTT
	releaseall
	end

MauvilleCity_EventScript_ScottApproachPlayerNorth::
	addobject LOCALID_MAUVILLE_SCOTT
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottApproachPlayerEast::
	setobjectxyperm LOCALID_MAUVILLE_SCOTT, 12, 13
	addobject LOCALID_MAUVILLE_SCOTT
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerEast
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitNorth
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitEast
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitEast
	waitmovement 0
	return

MauvilleCity_EventScript_BattleWally::
	msgbox MauvilleCity_Text_WallyHereICome, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, MauvilleCity_Text_WallyDefeat
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyIllGoBackToVerdanturf, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_ThankYouNotEnoughToBattle, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_UncleNoNeedToBeDown, MSGBOX_DEFAULT
	return

MauvilleCity_EventScript_DeclineWallyBattle::
	setflag FLAG_DECLINED_WALLY_BATTLE_MAUVILLE
	msgbox MauvilleCity_Text_WallyMyUncleWontKnowImStrong, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallyRequestBattleAgain::
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_WallyPleaseBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_Movement_WallyExitNorth1:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

MauvilleCity_Movement_WallyExitEast1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallyExitNorth2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_WallyExitEast2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast2:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitNorth:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitEast:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast1:
	delay_16
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth1:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_WallysUncleExitNorth1:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

MauvilleCity_Movement_WallysUncleExitEast1:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_PlayerFaceUncleNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerNorth:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerEast:
	walk_right
	walk_up
	step_end

MauvilleCity_Movement_WallysUncleExitNorth2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallysUncleExitEast2:
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

MauvilleCity_Movement_ScottApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_ScottApproachPlayerEast:
	walk_up
	walk_up
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

MauvilleCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_EventScript_Wattson::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_ReceivedThunderbolt
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_EventScript_CompletedNewMauville
	goto_if_set FLAG_GOT_BASEMENT_KEY_FROM_WATTSON, MauvilleCity_EventScript_BegunNewMauville
	msgbox MauvilleCity_Text_WattsonNeedFavorTakeKey, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_BegunNewMauville::
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Text_WattsonThanksTakeTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_ReceivedThunderbolt::
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RegisterWallyCall::
	lockall
	pokenavcall MauvilleCity_Text_WallyPokenavCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Text_RegisteredWally, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WALLY_MATCH_CALL
	clearflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	releaseall
	end

MauvilleCity_Text_UncleHesTooPeppy:
	.string "TIO: Acho que os Pokémon deixaram\n"
	.string "esse menino mais disposto...\p"
	.string "Mas ele ta animado até demais.$"

MauvilleCity_Text_WallyWantToChallengeGym:
	.string "WALLY: Ah, tio, por favor!\p"
	.string "Quero desafiar este ginásio pra ver\n"
	.string "o quanto melhorei.\p"
	.string "Deixa, por favor?$"

MauvilleCity_Text_UncleYourePushingIt:
	.string "TIO: Calma, Wally.\p"
	.string "Você ficou bem mais forte desde\n"
	.string "que começou a conviver com os\l"
	.string "Pokémon.\p"
	.string "Mas nao acha cedo pra desafiar um\n"
	.string "ginásio?$"

MauvilleCity_Text_WallyWeCanBeatAnyone:
	.string "WALLY: Nao tô exagerando.\p"
	.string "Se eu e Ralts juntarmos nossas\n"
	.string "forças, podemos vencer qualquer\l"
	.string "um!$"

MauvilleCity_Text_WallyWillYouBattleMe:
	.string "WALLY: Oi, {PLAYER}!\p"
	.string "Fiquei bem mais forte desde que a\n"
	.string "gente se conheceu.\p"
	.string "{PLAYER}, quero mostrar isso pra\n"
	.string "você e pro meu tio.\p"
	.string "{PLAYER}, por favor, pode batalhar\n"
	.string "comigo?$"

MauvilleCity_Text_WallyMyUncleWontKnowImStrong:
	.string "WALLY: Ah... Se você nao batalhar\n"
	.string "comigo, {PLAYER}, meu tio nao vai\l"
	.string "ver que fiquei mais forte.$"

MauvilleCity_Text_UncleCanYouBattleWally:
	.string "TIO: É {PLAYER}{KUN}, né? Pode batalhar\n"
	.string "com Wally só desta vez?\p"
	.string "Acho que ele nao vai ouvir mais\n"
	.string "nada enquanto nao tentar.$"

MauvilleCity_Text_WallyPleaseBattleMe:
	.string "WALLY: {PLAYER}, por favor! Batalha\n"
	.string "comigo.$"

MauvilleCity_Text_WallyHereICome:
	.string "WALLY: Obrigado, {PLAYER}.\p"
	.string "Ta bom... Lá vou eu!$"

MauvilleCity_Text_WallyDefeat:
	.string "WALLY: ...\p"
	.string "Eu perdi...$"

MauvilleCity_Text_WallyIllGoBackToVerdanturf:
	.string "WALLY: Tio... Vou voltar pra\n"
	.string "Verdanturf...$"

MauvilleCity_Text_ThankYouNotEnoughToBattle:
	.string "Obrigado, {PLAYER}. Ser treinador é\n"
	.string "difícil, né?\p"
	.string "Nao basta ter Pokémon e colocar\n"
	.string "eles pra lutar. Ser um treinador de\l"
	.string "verdade vai além disso.$"

MauvilleCity_Text_UncleNoNeedToBeDown:
	.string "TIO: Wally, nao precisa ficar\n"
	.string "assim.\p"
	.string "Você ainda pode ficar cada vez\n"
	.string "mais forte.\p"
	.string "Vamos pra casa. Todo mundo ta\n"
	.string "esperando você.$"

MauvilleCity_Text_UncleVisitUsSometime:
	.string "TIO: {PLAYER}{KUN}, agora percebi. Foi\n"
	.string "você que ajudou Wally quando ele\l"
	.string "capturou seu Pokémon, né?\p"
	.string "Vem visitar a gente em Verdanturf\n"
	.string "qualquer dia. Ele vai adorar.$"


MauvilleCity_Text_WallyPokenavCall:
	.string "... Bip!\p"
	.string "WALLY: Oi, {PLAYER}!\p"
	.string "Queria contar que meu tio me deu\n"
	.string "um PokéNav!\p"
	.string "Agora posso falar com você a\n"
	.string "qualquer hora, {PLAYER}!\p"
	.string "... Clic!$"

MauvilleCity_Text_RegisteredWally:
	.string "Wally foi registrado no PokéNav.$"

MauvilleCity_Text_ScottYouDidntHoldBack:
	.string "SCOTT: Hehe... Eu vi a batalha!\p"
	.string "Você é amigo daquele menino,\n"
	.string "Wally, né?\p"
	.string "Mesmo assim, lutou com tudo e\n"
	.string "venceu muito bem.\p"
	.string "É disso que uma batalha Pokémon\n"
	.string "precisa! Admiro treinadores assim.\p"
	.string "Vou torcer por você!$"

MauvilleCity_Text_WattsonNeedFavorTakeKey:
	.string "WATTSON: Ah, {PLAYER}{KUN}! Ta cheio de\n"
	.string "energia! Muito bom, wahahahaha!\p"
	.string "Decidi! Preciso de um favor,\n"
	.string "{PLAYER}{KUN}!\p"
	.string "Mauville City tem uma área\n"
	.string "subterrânea chamada New Mauville.\p"
	.string "{PLAYER}{KUN}, quero que você vá até lá\n"
	.string "e desligue o gerador.\p"
	.string "Ele ta funcionando de um jeito\n"
	.string "estranho e ficando perigoso.\p"
	.string "Toma, esta é a chave de New\n"
	.string "Mauville.$"

MauvilleCity_Text_WattsonWontBeChallenge:
	.string "WATTSON: Nao se preocupe, você\n"
	.string "consegue.\p"
	.string "A entrada de New Mauville fica\n"
	.string "perto da Route 110. É só usar Surf\l"
	.string "por um trecho curto.\p"
	.string "Confio em você! Wahahahaha!$"

MauvilleCity_Text_WattsonThanksTakeTM:
	.string "WATTSON: Wahahahaha!\p"
	.string "Sabia que tinha escolhido a pessoa\n"
	.string "certa, {PLAYER}{KUN}!\p"
	.string "Aqui vai meu agradecimento: uma TM\n"
	.string "com Thunderbolt!\p"
	.string "Pode pegar, você merece!$"

MauvilleCity_Text_WattsonYoungTakeCharge:
	.string "WATTSON: Wahahahaha!\p"
	.string "Fico feliz demais de ver a\n"
	.string "juventude tomando a frente das\l"
	.string "coisas!$"

MauvilleCity_Text_NurseHurtMonBackToHealth:
	.string "Batalhar com Pokémon é muito\n"
	.string "legal...\p"
	.string "Mas, se eles se machucarem, você\n"
	.string "precisa cuidar deles até ficarem\l"
	.string "bem.$"

MauvilleCity_Text_AllSortsOfPeopleComeThrough:
	.string "As estradas daqui vao pro norte,\n"
	.string "sul, leste e oeste.\p"
	.string "Por isso passa gente de todo tipo\n"
	.string "pela cidade.$"

MauvilleCity_Text_RydelVeryGenerous:
	.string "Já passou na Rydel's Cycles?\p"
	.string "O dono, Rydel, é um homem muito\n"
	.string "generoso.$"

MauvilleCity_Text_PokemonCanJumpYouOnBike:
	.string "Os Pokémon selvagens podem\n"
	.string "aparecer mesmo quando você ta de\l"
	.string "bicicleta.$"

MauvilleCity_Text_CitySign:
	.string "Mauville City\p"
	.string "“A cidade brilhante da diversao!”$"

MauvilleCity_Text_GymSign:
	.string "Ginásio Pokémon de Mauville City\p"
	.string "Líder: Wattson\p"
	.string "“O homem de alegria eletrizante!”$"

MauvilleCity_Text_BikeShopSign:
	.string "“Pedale pelo cascalho e sinta a\n"
	.string "emoçao!”\p"
	.string "Rydel's Cycles$"

MauvilleCity_Text_GameCornerSign:
	.string "“Diversao pra todo mundo!”\p"
	.string "Mauville Game Corner$"

MauvilleCity_Text_ExplainTV:
	.string "Oi, você costuma assistir\n"
	.string "televisao?\p"
	.string "Colocaram uns programas bem\n"
	.string "legais.\p"
	.string "Já vi meus amigos aparecendo do\n"
	.string "nada! Às vezes colocam a gente na\l"
	.string "televisao sem avisar.\p"
	.string "Queria aparecer também...\p"
	.string "Dá uma olhada quando puder!$"

MauvilleCity_Text_BeenCheckingOutTV:
	.string "Oi, anda assistindo televisao?$"
