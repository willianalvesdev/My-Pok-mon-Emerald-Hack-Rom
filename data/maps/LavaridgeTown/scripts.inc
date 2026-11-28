LavaridgeTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
	.byte 0

LavaridgeTown_OnTransition:
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_CheckSetRivalPos
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_HideMapNamePopup
	end

LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
	return

LavaridgeTown_EventScript_CheckSetRivalPos::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 9, LavaridgeTown_EventScript_SetRivalPos
	return

LavaridgeTown_EventScript_SetRivalPos::
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL, 11, 9
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL_ON_BIKE, 9, 8
	setobjectmovementtype LOCALID_LAVARIDGE_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
	return

LavaridgeTown_EventScript_ShowMtChimneyTrainers::
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	return

LavaridgeTown_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LavaridgeTown_OnFrame:
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
	.2byte 0

LavaridgeTown_EventScript_RivalGiveGoGoggles::
	lockall
	getplayerxy VAR_0x8008, VAR_0x8009
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalNoticePlayer
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExitHerbShop
	delay 20
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_PlayBrendanMusic
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer2
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	end

LavaridgeTown_EventScript_MayGiveGoGoggles::
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_BrendanGiveGoGoggles::
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_RivalExit::
	closemessage
	removeobject LOCALID_LAVARIDGE_RIVAL
	addobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit2
	removeobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

LavaridgeTown_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

LavaridgeTown_EventScript_RivalNoticePlayer::
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExitHerbShop::
	opendoor 12, 15
	waitdooranim
	addobject LOCALID_LAVARIDGE_RIVAL
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
	waitmovement 0
	closedoor 12, 15
	waitdooranim
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit1::
	applymovement LOCALID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit2::
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
	waitmovement 0
	return

LavaridgeTown_Movement_RivalExit2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

LavaridgeTown_Movement_PlayerWatchRivalExit:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LavaridgeTown_Movement_RivalExit1:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_Movement_RivalApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_Movement_RivalApproachPlayer1:
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_Movement_RivalExitHerbShop:
	walk_down
	step_end

LavaridgeTown_EventScript_HotSpringsTrigger::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
	end

LavaridgeTown_EventScript_EnteredHotSprings::
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
	end

LavaridgeTown_EventScript_ExpertM::
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
	end

LavaridgeTown_EventScript_OldMan::
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_Twin::
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman1::
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman2::
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
	end

LavaridgeTown_EventScript_ExpertF::
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_EggWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_WYNAUT
	release
	end

LavaridgeTown_EventScript_ReceivedEgg::
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_NoRoomForEgg::
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_DeclineEgg::
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_TownSign::
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_GymSign::
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_HerbShopSign::
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
	end

LavaridgeTown_Text_MayNiceBadgesTakeThis:
	.string "MAY: {PLAYER}{KUN}! Quanto tempo!\p"
	.string "Olha só, enquanto eu estava nas\n"
	.string "águas termais, você ganhou a\l"
	.string "insígnia de LAVARIDGE.\p"
	.string "Deve ter conseguido bons\n"
	.string "POKÉMONS... Nao, acho que treinou\l"
	.string "bem os seus.\p"
	.string "Acho que já pode ficar com isto.$"

LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
	.string "MAY: Com esses GO-GOGGLES, dá pra\n"
	.string "atravessar o deserto perto da\l"
	.string "ROUTE 111 sem problema.\p"
	.string "Mas olha só, {PLAYER}{KUN}... Desafiando\n"
	.string "ginásios...\p"
	.string "Aposto que ta se esforçando\n"
	.string "porque nao quer perder pra mim!\p"
	.string "{PLAYER}{KUN}, acho que vou desafiar seu\n"
	.string "pai no ginásio de PETALBURG.\p"
	.string "Até mais!$"

LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
	.string "BRENDAN: Ei, {PLAYER}, quanto\n"
	.string "tempo. Tudo certo?\p"
	.string "Hum... Você já tem uma boa coleçao\n"
	.string "de insígnias.\p"
	.string "Ta bom, pode ficar com isto.$"

LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
	.string "BRENDAN: Leve isso se for entrar\n"
	.string "no deserto perto da ROUTE 111.\p"
	.string "Deve ter POKÉMONS que só vivem por\n"
	.string "lá. Dá uma olhada.\p"
	.string "Quanto a mim... Tô pensando em\n"
	.string "desafiar NORMAN, o líder de\l"
	.string "PETALBURG.\p"
	.string "Ao contrário de você, {PLAYER}, seu\n"
	.string "pai tem cara de forte.\p"
	.string "Até mais!$"

LavaridgeTown_Text_HaveEggWillYouTakeIt:
	.string "Tenho um Ovo aqui.\p"
	.string "Tentei fazer ele chocar cobrindo\n"
	.string "com areia quente, perto das águas\l"
	.string "termais. Mas nao parece\l"
	.string "suficiente...\p"
	.string "Ouvi dizer que é melhor levar ele\n"
	.string "pra passear junto de outros\l"
	.string "POKÉMONS.\p"
	.string "Você é um treinador, né? Seus\n"
	.string "POKÉMONS parecem cheios de\l"
	.string "energia.\p"
	.string "Entao, aceita levar este Ovo pra\n"
	.string "chocar?$"

LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
	.string "Ótimo! Espero que ande bastante\n"
	.string "com esse Ovo!$"

LavaridgeTown_Text_ReceivedTheEgg:
	.string "{PLAYER} recebeu o Ovo.$"

LavaridgeTown_Text_NoRoomForThisEgg:
	.string "Ah? Sua equipe já ta cheia. Nao\n"
	.string "tem espaço pro Ovo...$"

LavaridgeTown_Text_AsYouWishThen:
	.string "Como quiser...\p"
	.string "Se mudar de ideia, vou estar aqui.$"

LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
	.string "De vez em quando, encontram um\n"
	.string "Ovo no Pokémon DAY CARE.\p"
	.string "Pelo menos é oque dizem.$"

LavaridgeTown_Text_HotSpringsNeverRunDry:
	.string "A gente usa toda a água quente\n"
	.string "que precisa, e a fonte nunca seca.\p"
	.string "Nao é incrível?\p"
	.string "Essas fontes aparecem perto de\n"
	.string "vulcoes ativos. O magma aquece a\l"
	.string "água debaixo da terra, que sobe e\l"
	.string "forma as águas termais.$"

LavaridgeTown_Text_PokemonNippedBackside:
	.string "Ficar enterrado nessa areia quente\n"
	.string "é... Ah...\p"
	.string "Tao quentinho e gostoso...\p"
	.string "Hein? Aaah! Ai!\p"
	.string "Um POKÉMON mordeu minha bunda!$"

LavaridgeTown_Text_OhYouLikeHotSprings:
	.string "Ah, você gosta de águas termais?\p"
	.string "Que surpresa pra alguém tao jovem.$"

LavaridgeTown_Text_BatheInHotSpringsEveryDay:
	.string "Venho nas águas termais todo dia.\p"
	.string "Quero virar uma líder bonita e\n"
	.string "forte como FLANNERY.$"

LavaridgeTown_Text_IfPokemonInHotSprings:
	.string "Colocar POKÉMONS nas águas termais\n"
	.string "pode dar umas coisas estranhas.\p"
	.string "Pode virar um banho elétrico, de\n"
	.string "espuma ou até de lava...\p"
	.string "Prefiro nao entrar pra conferir.$"

LavaridgeTown_Text_HotSpringsClaims:
	.string "Dizem que essas águas termais\n"
	.string "acalmam os nervos, aliviam dores,\l"
	.string "resolvem problemas amorosos e\l"
	.string "atraem dinheiro...\p"
	.string "Se for tudo verdade, vou morar\n"
	.string "nessa piscina.$"

LavaridgeTown_Text_TownSign:
	.string "LAVARIDGE TOWN\p"
	.string "“Águas termais do POKÉMON CENTER:\n"
	.string "um ótimo lugar pra relaxar!”$"

LavaridgeTown_Text_GymSign:
	.string "Ginásio Pokémon de LAVARIDGE TOWN\p"
	.string "Líder: FLANNERY\p"
	.string "“Uma paixao que queima como fogo!”$"

LavaridgeTown_Text_HerbShopSign:
	.string "Loja de ervas Pokémon\p"
	.string "“Gosto amargo, cura melhor!”$"

