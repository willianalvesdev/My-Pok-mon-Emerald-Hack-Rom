BerryTreeScript::
	special ObjectEventInteractionGetBerryTreeData
	switch VAR_0x8004
	case BERRY_STAGE_SPARKLING, BerryTree_EventScript_Sparkling
	case BERRY_STAGE_NO_BERRY, BerryTree_EventScript_CheckSoil
	case BERRY_STAGE_PLANTED, BerryTree_EventScript_CheckBerryStage1
	case BERRY_STAGE_SPROUTED, BerryTree_EventScript_CheckBerryStage2
	case BERRY_STAGE_TALLER, BerryTree_EventScript_CheckBerryStage3
	case BERRY_STAGE_TRUNK, BerryTree_EventScript_CheckBerryStageTrunk
	case BERRY_STAGE_BUDDING, BerryTree_EventScript_CheckBerryStageBudding
	case BERRY_STAGE_FLOWERING, BerryTree_EventScript_CheckBerryStage4
	case BERRY_STAGE_BERRIES, BerryTree_EventScript_CheckBerryFullyGrown
	end

BerryTree_EventScript_Sparkling::
	lockall
	message BerryTree_Text_ExclamationPoint
	waitmessage
	waitbuttonpress
	releaseall
	end

BerryTree_EventScript_CheckSoil::
	lock
	faceplayer
	specialvar VAR_RESULT, PlayerHasBerries
	goto_if_eq VAR_RESULT, TRUE, BerryTree_EventScript_WantToPlant
	specialvar VAR_RESULT, PlayerHasMulch
	goto_if_eq VAR_RESULT, TRUE, BerryTree_EventScript_WantToMulch
	message BerryTree_Text_ItsSoftLoamySoil
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_WantToPlant::
	specialvar VAR_RESULT, PlayerHasMulch
	goto_if_eq VAR_RESULT, TRUE, BerryTree_EventScript_WantToPlantMulch
	msgbox BerryTree_Text_WantToPlant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_ChooseBerryToPlant
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_CancelPlanting
	end

BerryTree_EventScript_WantToMulch::
.if OW_BERRY_MULCH_USAGE == TRUE
	msgbox BerryTree_Text_WantToMulch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_ChooseMulchToUse
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_CancelPlanting
.endif
	end

BerryTree_EventScript_WantToPlantMulch::
.if OW_BERRY_MULCH_USAGE == TRUE
	message BerryTree_Text_ItsSoftLoamySoil
	waitmessage
	multichoice 0, 0, MULTI_BERRY_PLOT, FALSE
	switch VAR_RESULT
	case 0, BerryTree_EventScript_ChooseMulchToUse
	case 1, BerryTree_EventScript_ChooseBerryToPlant
	case 2, BerryTree_EventScript_CancelPlanting
	case MULTI_B_PRESSED, BerryTree_EventScript_CancelPlanting

BerryTree_EventScript_ChooseMulchToUse::
	fadescreen FADE_TO_BLACK
	closemessage
	special Bag_ChooseMulch
	waitstate
	goto_if_eq VAR_ITEM_ID, 0, BerryTree_EventScript_CancelPlanting
	removeitem VAR_ITEM_ID
	call BerryTree_EventScript_UseMulch
.endif

BerryTree_EventScript_ChooseBerryToPlant::
	fadescreen FADE_TO_BLACK
	closemessage
	special Bag_ChooseBerry
	goto_if_eq VAR_ITEM_ID, 0, BerryTree_EventScript_CancelPlanting
	removeitem VAR_ITEM_ID
	call BerryTree_EventScript_PlantBerry

BerryTree_EventScript_CancelPlanting::
	release
	end

BerryTree_EventScript_CheckBerryStage1::
	lockall
	special ObjectEventInteractionGetBerryCountString
	message BerryTree_Text_BerryGrowthStage1
	waitmessage
	waitbuttonpress
	goto BerryTree_EventScript_WantToWater

BerryTree_EventScript_CheckBerryStage2::
	lockall
	special ObjectEventInteractionGetBerryName
	message BerryTree_Text_BerryGrowthStage2
	waitmessage
	waitbuttonpress
	goto BerryTree_EventScript_WantToWater

BerryTree_EventScript_CheckBerryStage3::
	lockall
	special ObjectEventInteractionGetBerryName
	message BerryTree_Text_BerryGrowthStage3
	waitmessage
	waitbuttonpress
	goto BerryTree_EventScript_WantToWater

BerryTree_EventScript_CheckBerryStageTrunk::
	lockall
	special ObjectEventInteractionGetBerryName
	message BerryTree_Text_BerryGrowthStageTrunk
	waitmessage
	waitbuttonpress
	goto BerryTree_EventScript_WantToWater

BerryTree_EventScript_CheckBerryStageBudding::
	lockall
	special ObjectEventInteractionGetBerryName
	message BerryTree_Text_BerryGrowthStageBudding
	waitmessage
	waitbuttonpress
	goto BerryTree_EventScript_WantToWater

BerryTree_EventScript_CheckBerryStage4::
	call BerryTree_EventScript_GetCareAdverb
	lockall
	special ObjectEventInteractionGetBerryName
	message BerryTree_Text_BerryGrowthStage4
	waitmessage
	waitbuttonpress
	goto BerryTree_EventScript_WantToWater

@ VAR_0x8005 here is the number of times watered
@ Buffered by ObjectEventInteractionGetBerryTreeData
BerryTree_EventScript_GetCareAdverb::
	goto_if_eq VAR_0x8005, 0, BerryTree_EventScript_SetAdverbPoor
	goto_if_eq VAR_0x8005, 4, BerryTree_EventScript_SetAdverbGreat
	bufferstring STR_VAR_2, BerryTree_Text_CareAdverbGood
	return

BerryTree_EventScript_SetAdverbGreat::
	bufferstring STR_VAR_2, BerryTree_Text_CareAdverbGreat
	return

BerryTree_EventScript_SetAdverbPoor::
	bufferstring STR_VAR_2, BerryTree_Text_CareAdverbPoor
	return

@ VAR_0x8006 here is the number of berries
BerryTree_EventScript_CheckBerryFullyGrown::
	buffernumberstring STR_VAR_2, VAR_0x8006
	lock
	faceplayer
	special ObjectEventInteractionGetBerryCountString
.if OW_BERRY_MUTATIONS == TRUE
	goto_if_eq VAR_RESULT, TRUE, BerryTree_EventScript_CheckBerryFullyGrown_Mutation
.endif
	msgbox BerryTree_Text_WantToPick, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_PickBerry
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_CancelPickingBerry

.set BERRY_NORMAL_BAG_FULL, 0
.set BERRY_NORMAL_SPACE_IN_BAG, 1
.set BERRY_MUTATION_BAG_FULL, 2
.set BERRY_MUTATION_SPACE_IN_BAG, 3

BerryTree_EventScript_PickBerry::
	special ObjectEventInteractionPickBerryTree
	goto_if_eq VAR_0x8004, BERRY_NORMAL_BAG_FULL, BerryTree_EventScript_BerryPocketFull
.if OW_BERRY_MUTATIONS == TRUE
	goto_if_eq VAR_0x8004, BERRY_MUTATION_BAG_FULL, BerryTree_EventScript_BerryPocketFull_Mutation
	goto_if_eq VAR_0x8004, BERRY_MUTATION_SPACE_IN_BAG, BerryTree_EventScript_PickBerry_Mutation
.endif
	special IncrementDailyPickedBerries
	special ObjectEventInteractionRemoveBerryTree
	message BerryTree_Text_PickedTheBerry
	delay 10
	showberrydescription
	playfanfare MUS_OBTAIN_BERRY
	waitmessage
	waitfanfare
	waitbuttonpress
	message BerryTree_Text_PutAwayBerry
	waitmessage
	waitbuttonpress
	hideitemdescription
	release
	end

BerryTree_EventScript_BerryPocketFull::
	message BerryTree_Text_BerryPocketFull
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_CancelPickingBerry::
	message BerryTree_Text_BerryLeftUnpicked
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_ItemUsePlantBerry::
	lockall
	special ObjectEventInteractionGetBerryTreeData
	call BerryTree_EventScript_PlantBerry
	releaseall
	end

BerryTree_EventScript_WantToWater::
.if OW_BERRY_PESTS == TRUE
	call BerryTree_EventScript_CheckForPests
.endif
.if OW_BERRY_WEEDS == TRUE
	call BerryTree_EventScript_CheckForWeed
.endif
	checkitem ITEM_WAILMER_PAIL
	goto_if_eq VAR_RESULT, FALSE, BerryTree_EventScript_DontWater
	specialvar VAR_RESULT, CanWaterBerryPlot
	goto_if_eq VAR_RESULT, FALSE, BerryTree_EventScript_DontWater
	special ObjectEventInteractionGetBerryName
	msgbox BerryTree_Text_WantToWater, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_WaterBerry
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_DontWater

BerryTree_EventScript_DontWater::
	releaseall
	end

BerryTree_EventScript_ItemUseWailmerPail::
	special ObjectEventInteractionGetBerryTreeData
	lockall
BerryTree_EventScript_WaterBerry::
	special ObjectEventInteractionGetBerryName
	message BerryTree_Text_WateredTheBerry
	waitmessage
	special ObjectEventInteractionWaterBerryTree
	special DoWateringBerryTreeAnim
	message BerryTree_Text_PlantIsDelighted
	waitmessage
	waitbuttonpress
	releaseall
	end

BerryTree_EventScript_PlantBerry::
	special ObjectEventInteractionPlantBerryTree
	incrementgamestat GAME_STAT_PLANTED_BERRIES
	special IncrementDailyPlantedBerries
	special ObjectEventInteractionGetBerryCountString
	message BerryTree_Text_PlantedOneBerry
	waitmessage
	waitbuttonpress
	return

BerryTree_Text_ItsSoftLoamySoil:
	.string "É uma terra macia e boa pra\n"
	.string "plantar.$"

BerryTree_Text_WantToPlant:
	.string "É uma terra macia e boa pra\n"
	.string "plantar. Quer plantar uma Berry?$"

BerryTree_Text_PlantedOneBerry:
	.string "{PLAYER} plantou {STR_VAR_1} na\n"
	.string "terra macia.$"

BerryTree_Text_BerryGrowthStage1:
.if OW_BERRY_SIX_STAGES == TRUE
	.string "Foi aqui que você plantou\n"
	.string "{STR_VAR_1}!$"
.else
	.string "Uma {STR_VAR_1} foi plantada\n"
	.string "aqui.$"
.endif

BerryTree_Text_BerryGrowthStage2:
.if OW_BERRY_SIX_STAGES == TRUE
	.string "A {STR_VAR_1} está brotando!$"
.else
	.string "A {STR_VAR_1} brotou.$"
.endif

BerryTree_Text_BerryGrowthStage3:
.if OW_BERRY_SIX_STAGES == TRUE
	.string "A muda de {STR_VAR_1} está\n"
	.string "crescendo bem!$"
.else
	.string "A planta de {STR_VAR_1} está\n"
	.string "ficando mais alta.$"
.endif

BerryTree_Text_BerryGrowthStageTrunk:
	.string "O tronco da {STR_VAR_1} está\n"
	.string "ficando maior!$"

BerryTree_Text_BerryGrowthStageBudding:
	.string "A árvore de {STR_VAR_1} tem\n"
	.string "botoes de flor!$"

BerryTree_Text_BerryGrowthStage4:
.if OW_BERRY_SIX_STAGES == TRUE
	.string "A árvore de {STR_VAR_1} está\n"
	.string "florida!$"
.else
	.string "As flores de {STR_VAR_1} estao\n"
	.string "abrindo {STR_VAR_2}.$"
.endif

BerryTree_Text_CareAdverbGreat:
	.string "de um jeito lindo$"

BerryTree_Text_CareAdverbPoor:
	.string "de um jeito fofo$"

BerryTree_Text_CareAdverbGood:
	.string "de um jeito bonito$"

BerryTree_Text_WantToPick:
	.string "Você encontrou {STR_VAR_2}\n"
	.string "{STR_VAR_1}!\p"
	.string "Quer colher {STR_VAR_1}?$"

BerryTree_Text_PickedTheBerry:
	.string "{PLAYER} colheu {STR_VAR_2}\n"
	.string "{STR_VAR_1}.$"

BerryTree_Text_PutAwayBerry:
	.string "{PLAYER} guardou {STR_VAR_1} no\n"
	.string "bolso de Berries da bolsa.\p"
	.string "A terra ficou macia de novo.$"

BerryTree_Text_BerryPocketFull:
	.string "O bolso de Berries da bolsa está\n"
	.string "cheio.\p"
	.string "Nao foi possível pegar\n"
	.string "{STR_VAR_1}.$"

BerryTree_Text_BerryLeftUnpicked:
	.string "{PLAYER} nao colheu\n"
	.string "{STR_VAR_1}.$"

BerryTree_Text_WantToWater:
	.string "Regar {STR_VAR_1} com o Wailmer\n"
	.string "Pail?$"

BerryTree_Text_WateredTheBerry:
	.string "{PLAYER} regou {STR_VAR_1}.$"

BerryTree_Text_PlantIsDelighted:
	.string "A planta parece feliz.$"

BerryTree_Text_ExclamationPoint:
	.string "!$"

.if OW_BERRY_MUTATIONS == TRUE
BerryTree_EventScript_CheckBerryFullyGrown_Mutation:
	msgbox BerryTree_Text_WantToPick_Mutation, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_PickBerry
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_CancelPickingBerry_Mutation

BerryTree_EventScript_CancelPickingBerry_Mutation::
	message BerryTree_Text_BerryLeftUnpicked_Mutation
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_BerryPocketFull_Mutation::
	message BerryTree_Text_BerryPocketFull_Mutation
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_PickBerry_Mutation::
	special IncrementDailyPickedBerries
	special ObjectEventInteractionRemoveBerryTree
	message BerryTree_Text_PickedTheBerry_Mutation
	playfanfare MUS_OBTAIN_BERRY
	waitmessage
	waitfanfare
	waitbuttonpress
	message BerryTree_Text_PutAwayBerry_Mutation
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_Text_WantToPick_Mutation:
	.string "Você encontrou {STR_VAR_2}\n"
	.string "{STR_VAR_1} e 1\l"
	.string "{STR_VAR_3}!\p"
	.string "Quer colher?$"

BerryTree_Text_BerryLeftUnpicked_Mutation:
	.string "{PLAYER} nao colheu {STR_VAR_1}\n"
	.string "nem {STR_VAR_3}.$"

BerryTree_Text_BerryPocketFull_Mutation:
	.string "O bolso de Berries da bolsa está\n"
	.string "cheio.\p"
	.string "Nao foi possível pegar\n"
	.string "{STR_VAR_1} nem\l"
	.string "{STR_VAR_3}.$"

BerryTree_Text_PickedTheBerry_Mutation:
	.string "{PLAYER} colheu {STR_VAR_2}\n"
	.string "{STR_VAR_1} e {STR_VAR_3}.$"

BerryTree_Text_PutAwayBerry_Mutation:
	.string "{PLAYER} guardou {STR_VAR_1} e\n"
	.string "{STR_VAR_3} no bolso de Berries\l"
	.string "da bolsa.\p"
	.string "A terra ficou macia de novo.$"
.endif

.if OW_BERRY_MULCH_USAGE == TRUE
BerryTree_EventScript_UseMulch::
	special ObjectEventInteractionApplyMulch
	message BerryTree_Text_ScatteredMulch
	waitmessage
	waitbuttonpress
	return

BerryTree_Text_WantToMulch:
	.string "É uma terra macia e boa pra\n"
	.string "plantar. Colocar adubo?$"

BerryTree_Text_ScatteredMulch:
	.string "{PLAYER} espalhou {STR_VAR_1}\n"
	.string "na terra macia.$"
.endif

.if OW_BERRY_WEEDS == TRUE
BerryTree_EventScript_CheckForWeed::
	specialvar VAR_RESULT, ObjectEventInteractionBerryHasWeed
	call_if_eq VAR_RESULT, TRUE, BerryTree_EventScript_WeedIsGrowing
	return

BerryTree_EventScript_WeedIsGrowing::
	msgbox BerryTree_Text_WeedIsGrowing, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_PullOutWeed
	return

BerryTree_EventScript_PullOutWeed::
	special ObjectEventInteractionPullBerryWeed
	message BerryTree_Text_PulledOutTheWeed
	waitmessage
	waitbuttonpress
	return

BerryTree_Text_WeedIsGrowing:
	.string "Tem uma erva daninha crescendo\n"
	.string "aqui. Quer arrancar?$"

BerryTree_Text_PulledOutTheWeed:
	.string "{PLAYER} arrancou a erva daninha!$"
.endif

.if OW_BERRY_PESTS == TRUE
BerryTree_EventScript_CheckForPests::
	specialvar VAR_RESULT, ObjectEventInteractionBerryHasPests
	call_if_eq VAR_RESULT, TRUE, BerryTree_EventScript_EncounterPests
	return

BerryTree_EventScript_EncounterPests::
	message BerryTree_Text_APokemonAppeared
	waitmessage
	waitbuttonpress
	dowildbattle
	return

BerryTree_Text_APokemonAppeared:
	.string "Um Pokémon apareceu!$"
.endif
