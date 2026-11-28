LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	.byte 0

LilycoveCity_OnTransition:
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_OnLoad:
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
	end

LilycoveCity_EventScript_SetWailmerMetatiles::
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
	return

LilycoveCity_EventScript_BerryGentleman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	giverandomberry BERRY_ID_CHERI, BERRY_ID_SITRUS
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry::
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3::
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone::
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy::
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone::
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone::
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2::
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1::
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF::
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone::
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1::
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan::
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1::
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_MAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1::
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_WOMAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign::
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ContestHallSign::
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign::
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign::
	lockall
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings::
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady::
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign::
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign::
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign::
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt::
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer::
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1::
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2::
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3::
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4::
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
	end

LilycoveCity_EventScript_May::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleMayTreecko
	case 1, LilycoveCity_EventScript_BattleMayTorchic
	case 2, LilycoveCity_EventScript_BattleMayMudkip
	end

LilycoveCity_EventScript_MayAskToBattleAgain::
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_MayAskToBattle::
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineMayBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_Brendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
	end

LilycoveCity_EventScript_BrendanAskToBattleAgain::
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_BrendanAskToBattle::
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineBrendanBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_DefeatedMay::
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_CheckFinalBadge::
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
	return

LilycoveCity_EventScript_HasFinalBadge::
	setvar VAR_RESULT, TRUE
	return

LilycoveCity_EventScript_MayCollectBadges::
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayBattleFrontier::
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DefeatedBrendan::
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_BrendanCollectBadges::
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanBattleFrontier::
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_RivalFlyAway::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_SchoolKidM::
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end

LilycoveCity_EventScript_KnowAboutBerryBlender::
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender::
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MayShoppingLetsBattle:
	.string "MAY: Oi, {PLAYER}{KUN}! Veio fazer\n"
	.string "compras também?\p"
	.string "Comprei um monte de bonecos e\n"
	.string "pôsteres.\p"
	.string "Mas também capturei vários Pokémon\n"
	.string "e tô cuidando bem deles, viu?\p"
	.string "Agora quero ver, {PLAYER}{KUN}, como\n"
	.string "você ta cuidando dos seus.\p"
	.string "Vamos batalhar, {PLAYER}{KUN}? Assim\n"
	.string "você me mostra!$"

LilycoveCity_Text_MayNotRaisingPokemon:
	.string "MAY: Ué, por que nao, {PLAYER}{KUN}? Nao\n"
	.string "anda treinando seus Pokémon?\p"
	.string "Assim fica difícil levar você a\n"
	.string "sério como treinador...$"

LilycoveCity_Text_MayBattleMe:
	.string "MAY: Vamos, batalha comigo! Quero\n"
	.string "ver seus Pokémon!$"

LilycoveCity_Text_MayWontBeBeaten:
	.string "MAY: Meus Pokémon nao vao perder\n"
	.string "pros seus, {PLAYER}{KUN}!$"

LilycoveCity_Text_MayDefeat:
	.string "...\p"
	.string "Lembra da nossa batalha na Route\n"
	.string "103, {PLAYER}{KUN}?\p"
	.string "Ela ajudou você a chegar até aqui,\n"
	.string "{PLAYER}{KUN}, né?$"

LilycoveCity_Text_MayGoingBackToLittleroot:
	.string "MAY: Tô pensando em voltar pra\n"
	.string "Littleroot em breve.\p"
	.string "Já capturei vários Pokémon e minha\n"
	.string "Pokédex ta ficando bem completa.\l"
	.string "Quero mostrar pro meu pai.$"

LilycoveCity_Text_MayYouGoingToCollectBadges:
	.string "E você, {PLAYER}{KUN}, vai fazer oque\n"
	.string "agora?\p"
	.string "Pegar todas as insígnias e\n"
	.string "desafiar a Liga Pokémon?\p"
	.string "Enquanto você busca as insígnias,\n"
	.string "{PLAYER}{KUN}, vou cuidar da minha\l"
	.string "Pokédex. Vou completar ela antes\l"
	.string "de você!\p"
	.string "Até mais!$"

LilycoveCity_Text_MayYouGoingToPokemonLeague:
	.string "E agora, {PLAYER}{KUN}?\p"
	.string "Vai desafiar a Liga Pokémon ou\n"
	.string "completar a Pokédex?\p"
	.string "Posso ter perdido na batalha, mas\n"
	.string "vou completar minha Pokédex antes\l"
	.string "de você!\p"
	.string "Até mais!$"

LilycoveCity_Text_MayYouGoingToBattleFrontier:
	.string "E agora, {PLAYER}{KUN}?\p"
	.string "Vai desafiar a Battle Frontier ou\n"
	.string "completar a Pokédex?\p"
	.string "Posso ter perdido na batalha, mas\n"
	.string "vou completar minha Pokédex antes\l"
	.string "de você!\p"
	.string "Até mais!$"

LilycoveCity_Text_BrendanShoppingLetsBattle:
	.string "BRENDAN: Opa, {PLAYER}!\p"
	.string "Vim resolver umas coisas pro meu\n"
	.string "pai. Nao, nao tô comprando\l"
	.string "bonecos.\p"
	.string "Faz um tempo que a gente nao se\n"
	.string "vê.\p"
	.string "Vamos batalhar pra ver quem andou\n"
	.string "treinando melhor?$"

LilycoveCity_Text_BrendanNoConfidence:
	.string "BRENDAN: Ué, oque foi? Ta sem\n"
	.string "confiança?$"

LilycoveCity_Text_BrendanBattleMe:
	.string "BRENDAN: Vamos batalhar pra ver\n"
	.string "quem andou treinando melhor?$"

LilycoveCity_Text_BrendanWontBeBeaten:
	.string "BRENDAN: Ah, pode vir. Nao vou\n"
	.string "perder pra você, {PLAYER}.$"

LilycoveCity_Text_BrendanDefeat:
	.string "Hum... Você treinou bastante.\p"
	.string "Essa doeu um pouco. Eu comecei a\n"
	.string "treinar antes de você...$"

LilycoveCity_Text_BrendanGoingBackToLittleroot:
	.string "BRENDAN: Eu... tô pensando em\n"
	.string "voltar pra Littleroot.\p"
	.string "A Pokédex que tô ajudando meu pai\n"
	.string "a montar já ta bem completa.\l"
	.string "Preciso mostrar pra ele.$"

LilycoveCity_Text_BrendanYouGoingToCollectBadges:
	.string "E agora, {PLAYER}?\p"
	.string "Vai pegar todas as insígnias e\n"
	.string "desafiar a Liga Pokémon?\p"
	.string "Talvez eu faça isso também...\p"
	.string "Bom, seja como for, manda ver!$"

LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
	.string "E agora, {PLAYER}?\p"
	.string "Com essa força toda, vai desafiar\n"
	.string "a Liga Pokémon?\p"
	.string "Heh, se eu treinar mais um pouco,\n"
	.string "ainda fico mais forte que você,\l"
	.string "{PLAYER}.\p"
	.string "Continua firme!$"

LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
	.string "E agora, {PLAYER}?\p"
	.string "Vai desafiar a Battle Frontier ou\n"
	.string "completar a Pokédex?\p"
	.string "Com essa força toda, vale a pena\n"
	.string "conhecer a Battle Frontier.\p"
	.string "Heh, com mais treino eu ainda\n"
	.string "passo você, {PLAYER}. Talvez eu vá\l"
	.string "pra lá também.\p"
	.string "Continua firme!$"

LilycoveCity_Text_MovedLootIntoHideoutToday:
	.string "Fufufu...\p"
	.string "Hoje levamos mais coisa roubada\n"
	.string "pro nosso esconderijo secreto...\p"
	.string "Q-quem é você?! Eu tava falando\n"
	.string "sozinho! Nao vale usar isso como\l"
	.string "prova!$"

LilycoveCity_Text_ChanceToDoBigThings:
	.string "Sou só um capanga, nao sei oque o\n"
	.string "chefe ta planejando...\p"
	.string "Mas na Team Aqua eu ainda vou\n"
	.string "fazer algo grande!\p"
	.string "Q-quem é você?! Eu tava ensaiando\n"
	.string "meu discurso de promoçao!$"

LilycoveCity_Text_DontGoNearCaveInCove:
	.string "Ei, você!\p"
	.string "Fica longe daquela caverna na\n"
	.string "enseada!\p"
	.string "Por quê? Porque eu mandei! Sou\n"
	.string "adulto, pode obedecer!\p"
	.string "É o melhor argumento que eu tenho.$"

LilycoveCity_Text_IfWorldBecomesOurs:
	.string "Quando esse mundo todo for da\n"
	.string "Team Aqua, os Pokémon também vao\l"
	.string "viver mais felizes.$"

LilycoveCity_Text_WailmerLeapOutOfWater:
	.string "Isso, Wailmer! Agora pula pra fora\n"
	.string "da água!$"

LilycoveCity_Text_GetLostMessingUpTraining:
	.string "Hein? Oque você quer?\p"
	.string "Ta atrapalhando nosso treino. Dá\n"
	.string "pra sair daqui?$"

LilycoveCity_Text_ContestHallInTown:
	.string "Tem um salao de concursos Pokémon\n"
	.string "aqui na cidade.\p"
	.string "Isso atrai Pokémon bem cuidados de\n"
	.string "todo canto.\p"
	.string "Só de pensar já fico animado!$"

LilycoveCity_Text_StrangeCaveInCove:
	.string "Você viu aquela caverna estranha\n"
	.string "na enseada, na ponta da cidade?$"

LilycoveCity_Text_GoingToMoveDeleterForHMs:
	.string "Vou ensinar golpes novos pro meu\n"
	.string "Pokémon participar de um concurso.\p"
	.string "Antes preciso ir ao Move Deleter\n"
	.string "pra ele esquecer os golpes de HM.$"

LilycoveCity_Text_ImFromKanto:
	.string "Vim de Kanto.\p"
	.string "Hoenn é linda, cheia de água e\n"
	.string "natureza.\p"
	.string "Espera... Será que tem Pokémon\n"
	.string "raros que só vivem por aqui?$"

LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
	.string "A Team Aqua anda treinando Wailmer\n"
	.string "na enseada.\p"
	.string "Com eles na frente, a gente nao\n"
	.string "consegue sair de barco!$"

LilycoveCity_Text_SomeonePuntedTeamAquaOut:
	.string "Opa, ficou sabendo?\p"
	.string "Alguém tirou a Team Aqua do nosso\n"
	.string "caminho!\p"
	.string "Os Wailmer saíram da enseada e\n"
	.string "agora podemos navegar de novo.$"

LilycoveCity_Text_SomeoneStoleMyPokemon:
	.string "Eu tava tirando um cochilo na\n"
	.string "pousada, ouvindo as ondas...\p"
	.string "E roubaram meu Pokémon!\p"
	.string "Foi a Team Aqua? Só pode ter sido\n"
	.string "a Team Aqua!$"

LilycoveCity_Text_MissingPokemonCameBack:
	.string "Meu Pokémon voltou sem eu\n"
	.string "perceber!\p"
	.string "Acho que ele só foi dar uma volta.\n"
	.string "Eu já tava montando uma\l"
	.string "investigaçao.$"

LilycoveCity_Text_ImArtDealer:
	.string "Trabalho comprando e vendendo\n"
	.string "obras de arte, principalmente\l"
	.string "pinturas.\p"
	.string "Ouvi dizer que o museu daqui tem\n"
	.string "uma coleçao maravilhosa...$"

LilycoveCity_Text_SeaRemainsForeverYoung:
	.string "A gente envelhece e fica cheio de\n"
	.string "rugas, mas o mar continua jovem,\l"
	.string "cheio de vida...\p"
	.string "Fwohoho, fwohohohoho...$"

LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
	.string "Foi aqui que meu marido me pediu\n"
	.string "em casamento, sessenta anos\l"
	.string "atrás.\p"
	.string "O mar continua lindo como naquele\n"
	.string "dia.\p"
	.string "Mufufufu, mufufufufufu...$"

LilycoveCity_Text_TeamAquaRenovatedCavern:
	.string "Sabe a caverna da enseada? Ela\n"
	.string "era toda natural, até a Team Aqua\l"
	.string "aparecer e reformar tudo.\p"
	.string "E eles ainda dizem que amam a\n"
	.string "natureza!\p"
	.string "Falam uma coisa e fazem outra.$"

LilycoveCity_Text_TeamAquaLotGoneForGood:
	.string "Aquela caverna da enseada...\p"
	.string "Demorei pra perceber, mas agora\n"
	.string "ela ta vazia.\p"
	.string "Parece que a Team Aqua foi embora\n"
	.string "de vez.$"

LilycoveCity_Text_CitySign:
	.string "Lilycove City\p"
	.string "“Onde a terra acaba e o mar\n"
	.string "começa.”$"

LilycoveCity_Text_ContestHallSign:
	.string "Salao de concursos Pokémon\p"
	.string "“O ponto de encontro dos\n"
	.string "treinadores!”$"

LilycoveCity_Text_MotelSign:
	.string "Cove Lily Motel\p"
	.string "“Lembre da gente como Cove Lily de\n"
	.string "Lilycove.”$"

LilycoveCity_Text_MuseumSign:
	.string "Lilycove Museum\p"
	.string "“Exposiçao de grandes obras sobre\n"
	.string "Pokémon!”$"

LilycoveCity_Text_MuseumSignPlayersExhibit:
	.string "Lilycove Museum\p"
	.string "“Coleçao de Pokémon de {PLAYER} em\n"
	.string "exposiçao!”$"

LilycoveCity_Text_HarborSignUnderConstruction:
	.string "Porto de Lilycove City\p"
	.string "“O S.S. Tidal está sendo\n"
	.string "construído em Slateport City.\p"
	.string "As viagens vao começar em breve.”$"

LilycoveCity_Text_HarborSign:
	.string "Porto de Lilycove City\p"
	.string "“Aproveite um belo passeio a bordo\n"
	.string "do S.S. Tidal.”$"

LilycoveCity_Text_TrainerFanClubSign:
	.string "Fa-clube dos treinadores Pokémon\p"
	.string "Tem nomes de treinadores\n"
	.string "rabiscados por toda a placa...$"

LilycoveCity_Text_DepartmentStoreSign:
	.string "Lilycove Department Store\p"
	.string "“Cheio de produtos e novidades!\p"
	.string "Aqui você encontra oque precisa!”$"

LilycoveCity_Text_MoveDeletersHouseSign:
	.string "Casa do Move Deleter\p"
	.string "“Fazemos seus Pokémon esquecerem\n"
	.string "golpes.”$"

LilycoveCity_Text_DoYouKnowAboutBerryBlender:
	.string "Você conhece a máquina Berry\n"
	.string "Blender?$"

LilycoveCity_Text_FasterSpinBetterPokeblocks:
	.string "Todo mundo precisa colaborar pra\n"
	.string "ela girar mais rápido.\p"
	.string "Ouvi dizer que quanto mais rápido\n"
	.string "ela gira, melhores ficam os\l"
	.string "{POKEBLOCK}S.$"

LilycoveCity_Text_ExplainBerryBlender:
	.string "Ela faz um tipo de doce chamado\n"
	.string "{POKEBLOCK}.\p"
	.string "Um bom {POKEBLOCK} melhora bastante\n"
	.string "as condiçoes de um Pokémon.$"

LilycoveCity_Text_HeardTowerCalledSkyPillar:
	.string "Ouvi dizer que tem uma torre em\n"
	.string "alguma das rotas do mar.\p"
	.string "Parece que ela se chama Sky\n"
	.string "Pillar.$"

LilycoveCity_Text_SawTallTowerOnRoute131:
	.string "Vi uma torre enorme perto da Route\n"
	.string "131.\p"
	.string "Será que é aquela...?$"

LilycoveCity_Text_JustArrivedAndSawRarePokemon:
	.string "Acabamos de chegar pra nossa lua\n"
	.string "de mel.\p"
	.string "Vimos um Pokémon do tipo Dragon\n"
	.string "voando bem alto.\p"
	.string "Tem Pokémon assim em Hoenn?$"

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
	.string "Na nossa lua de mel, prometemos\n"
	.string "ver o máximo de Pokémon raros que\l"
	.string "pudermos.\p"
	.string "E já vimos um assim que chegamos!\p"
	.string "Tô feliz demais!$"

