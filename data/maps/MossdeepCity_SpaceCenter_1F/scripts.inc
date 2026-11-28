MossdeepCity_SpaceCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_SpaceCenter_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_SpaceCenter_1F_OnTransition
	.byte 0

MossdeepCity_SpaceCenter_1F_OnTransition:
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_MoveObjectsForTeamMagma
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveObjectsForTeamMagma::
	setobjectxyperm LOCALID_SPACE_CENTER_1F_SAILOR, 1, 9
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_SAILOR, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_SPACE_CENTER_1F_WOMAN, 0, 8
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_WOMAN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_SPACE_CENTER_1F_OLD_MAN, 1, 6
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_OLD_MAN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_SPACE_CENTER_1F_SCIENTIST_1, 3, 4
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_SCIENTIST_1, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_SCIENTIST_2, MOVEMENT_TYPE_FACE_RIGHT
	goto_if_eq VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 1, MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardLeft
	goto_if_eq VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardDown
	goto_if_eq VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 3, MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardRight
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardLeft::
	setobjectxyperm LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, 12, 2
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardDown::
	setobjectxyperm LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, 13, 3
	end

@ Functionally unused. See comment on MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardRight::
	setobjectxyperm LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, 14, 2
	end

MossdeepCity_SpaceCenter_1F_OnLoad:
	goto_if_le VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_SetMagmaNote
	end

MossdeepCity_SpaceCenter_1F_EventScript_SetMagmaNote::
	setmetatile 2, 5, METATILE_Facility_DataPad, TRUE
	return

MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounter::
	lock
	faceplayer
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounterMagma
	dotimebasedevents
	specialvar VAR_RESULT, GetWeekCount
	buffernumberstring STR_VAR_1, VAR_RESULT
	call_if_eq VAR_RESULT, 0, MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYet
	call_if_ge VAR_RESULT, 1, MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumber
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYet::
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketLaunchImminent, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumber::
	msgbox MossdeepCity_SpaceCenter_1F_Text_SuccessfulLaunchNumber, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounterMagma::
	dotimebasedevents
	specialvar VAR_RESULT, GetWeekCount
	buffernumberstring STR_VAR_1, VAR_RESULT
	call_if_eq VAR_RESULT, 0, MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYetMagma
	call_if_ge VAR_RESULT, 1, MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumberMagma
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYetMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_HaywireButRocketLaunchImminent, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumberMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_HaywireButSuccessfulLaunchNumber, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_Scientist::
	lock
	faceplayer
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_ScientistMagma
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketLaunchDemandsPerfection, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_ScientistMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaHaveSightsOnSpaceCenter, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_SunStoneMan::
	lock
	faceplayer
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_SunStoneManMagma
	goto_if_set FLAG_RECEIVED_SUN_STONE_MOSSDEEP, MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStone
	msgbox MossdeepCity_SpaceCenter_1F_Text_FoundThisYouCanHaveIt, MSGBOX_DEFAULT
	giveitem ITEM_SUN_STONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUN_STONE_MOSSDEEP
	msgbox MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStone::
	msgbox MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_SunStoneManMagma::
	goto_if_set FLAG_RECEIVED_SUN_STONE_MOSSDEEP, MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStoneMagma
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaCantStealFuelTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_SUN_STONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUN_STONE_MOSSDEEP
	msgbox MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStoneMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal
	goto MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma
	end

MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal::
	msgbox MossdeepCity_SpaceCenter_1F_Text_DidPokemonComeFromSpace, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_AquaShouldBeatMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal
	goto MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma
	end

MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal::
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketsBoggleMyMind, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaWantsToSpoilMyDream, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_Steven::
	lock
	faceplayer
	msgbox MossdeepCity_SpaceCenter_1F_Text_StevenMagmaCantBeAllowedToTakeFuel, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_MagmaNote::
	lockall
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaIntentToStealNotice, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_3, MossdeepCity_SpaceCenter_1F_Text_Grunt3Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt3Defeat
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_1, MossdeepCity_SpaceCenter_1F_Text_Grunt1Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt1Defeat
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_4, MossdeepCity_SpaceCenter_1F_Text_Grunt4Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt4Defeat
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt2::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F, MossdeepCity_SpaceCenter_1F_EventScript_Grunt2Defeated
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt2Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_2, MossdeepCity_SpaceCenter_1F_Text_Grunt2Defeat
	setflag FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F
	copyobjectxytoperm LOCALID_SPACE_CENTER_1F_STAIR_GRUNT
	switch VAR_FACING
	case DIR_WEST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsWest
#ifdef BUGFIX
	case DIR_EAST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
#else
	case DIR_WEST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
#endif
	applymovement LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairs
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 2
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt2Defeated::
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt2PostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsWest::
	applymovement LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsWest
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 1
	release
	end

@ Functionally unused by mistake. The movement is handled anyway after the switch (see above)
@ This also means VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE can never be 3
MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast::
	applymovement LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsEast
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 3
	release
	end

MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsWest:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

@ Functionally unused. See above
MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsEast:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

@ This was meant to only handle the player facing North, but by mistake(?) it also handles the player facing East
MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairs:
	face_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_1F_Text_RocketLaunchImminent:
	.string "O foguete ta quase pronto pra\n"
	.string "decolar!$"

MossdeepCity_SpaceCenter_1F_Text_SuccessfulLaunchNumber:
	.string "O foguete decolou em segurança!\n"
	.string "Já sao {STR_VAR_1} lançamentos\l"
	.string "bem-sucedidos!$"

MossdeepCity_SpaceCenter_1F_Text_HaywireButRocketLaunchImminent:
	.string "Sei que as coisas tao meio fora de\n"
	.string "controle, mas...\p"
	.string "O foguete ta quase pronto pra\n"
	.string "decolar!$"

MossdeepCity_SpaceCenter_1F_Text_HaywireButSuccessfulLaunchNumber:
	.string "Sei que as coisas tao meio fora de\n"
	.string "controle, mas...\p"
	.string "O foguete decolou em segurança!\n"
	.string "Já sao {STR_VAR_1} lançamentos\l"
	.string "bem-sucedidos!$"

MossdeepCity_SpaceCenter_1F_Text_RocketLaunchDemandsPerfection:
	.string "O lançamento de um foguete precisa\n"
	.string "ser perfeito. Nem 1% de erro é\l"
	.string "aceitável.\p"
	.string "Mesmo com 99% certo, aquele 1%\n"
	.string "pode estragar tudo.\p"
	.string "Ainda assim, continuamos tentando.\n"
	.string "Por quê? Porque esse sonho nao\l"
	.string "acaba.$"

MossdeepCity_SpaceCenter_1F_Text_MagmaHaveSightsOnSpaceCenter:
	.string "Aqueles bandidos da Team Magma\n"
	.string "tao de olho no nosso centro\l"
	.string "espacial.\p"
	.string "Mas isso nao vai atrapalhar o\n"
	.string "lançamento do foguete!$"

MossdeepCity_SpaceCenter_1F_Text_FoundThisYouCanHaveIt:
	.string "Achei isto enquanto caminhava na\n"
	.string "praia.\p"
	.string "Nao preciso, entao pode ficar.$"

MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers:
	.string "Hoenn é conhecida pelas chuvas de\n"
	.string "meteoros faz muito tempo.$"

MossdeepCity_SpaceCenter_1F_Text_MagmaCantStealFuelTakeThis:
	.string "Nao podemos deixar a Team Magma\n"
	.string "roubar o combustível do foguete.\p"
	.string "Ah, e pode ficar com esta pedra\n"
	.string "que achei na praia.$"

MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma:
	.string "Com a Team Magma por aqui, acho\n"
	.string "que nem caminhar na praia é\l"
	.string "seguro.$"

MossdeepCity_SpaceCenter_1F_Text_DidPokemonComeFromSpace:
	.string "Tem gente que diz que os Pokémon\n"
	.string "vieram do espaço. Será verdade?$"

MossdeepCity_SpaceCenter_1F_Text_AquaShouldBeatMagma:
	.string "A Team Aqua devia dar um jeito na\n"
	.string "Team Magma!\p"
	.string "Mas aí eles iam ficar se achando,\n"
	.string "né?$"

MossdeepCity_SpaceCenter_1F_Text_RocketsBoggleMyMind:
	.string "Um pedaço enorme de metal\n"
	.string "atravessa o céu e vai pro\l"
	.string "espaço...\p"
	.string "Nao consigo nem imaginar!$"

MossdeepCity_SpaceCenter_1F_Text_MagmaWantsToSpoilMyDream:
	.string "Um pedaço enorme de metal\n"
	.string "atravessa o céu e vai pro\l"
	.string "espaço...\p"
	.string "Mas a Team Magma quer acabar com\n"
	.string "esse meu sonho!\p"
	.string "Nao vou aceitar isso!$"

MossdeepCity_SpaceCenter_1F_Text_StevenMagmaCantBeAllowedToTakeFuel:
	.string "STEVEN: {PLAYER}{KUN}, já leu aquele\n"
	.string "aviso?\p"
	.string "A Team Magma quer o combustível\n"
	.string "dos foguetes desta ilha.\p"
	.string "Nao sei pra que precisam dele, mas\n"
	.string "nao podemos deixar levarem.\p"
	.string "Vou ficar de olho por aqui.\n"
	.string "Enquanto isso, por que nao conhece\l"
	.string "a cidade?$"

MossdeepCity_SpaceCenter_1F_Text_Grunt3Intro:
	.string "Como prometido, viemos buscar o\n"
	.string "combustível do foguete!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt3Defeat:
	.string "Acabou meu combustível...$"

MossdeepCity_SpaceCenter_1F_Text_Grunt3PostBattle:
	.string "Nao fica se achando só porque me\n"
	.string "venceu!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt1Intro:
	.string "A gente avisou que vinha! Ladrao\n"
	.string "educado manda convite!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt1Defeat:
	.string "Grrr... Devíamos ter vindo\n"
	.string "escondidos...$"

MossdeepCity_SpaceCenter_1F_Text_Grunt1PostBattle:
	.string "Ta bom, já entendi! Na próxima a\n"
	.string "gente vem sem avisar.$"

MossdeepCity_SpaceCenter_1F_Text_Grunt4Intro:
	.string "Queremos o combustível que o\n"
	.string "centro espacial guarda aqui.\p"
	.string "Vamos levar até a última gota!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt4Defeat:
	.string "Por favor, dá só um pouco de\n"
	.string "combustível? Até uma xícara\l"
	.string "serve!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt4PostBattle:
	.string "Oque vamos fazer com o\n"
	.string "combustível?\p"
	.string "Como é que eu vou saber? Pergunta\n"
	.string "pro líder lá em cima!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt2Intro:
	.string "Nosso líder disse que ninguém,\n"
	.string "ninguém mesmo, pode passar por\l"
	.string "mim!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt2Defeat:
	.string "Ack! Ack! Aaack!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt2PostBattle:
	.string "Por favor, fala pro líder que eu\n"
	.string "nao abandonei meu posto. Fiquei\l"
	.string "aqui até o final...\p"
	.string "Derrotado, mas dentro do horário.$"

MossdeepCity_SpaceCenter_1F_Text_MagmaIntentToStealNotice:
	.string "Isto é... Um aviso de roubo?\p"
	.string "“Aos funcionários do centro\n"
	.string "espacial: como vao? Estamos bem.\p"
	.string "Vamos visitar vocês em breve pra\n"
	.string "levar o combustível dos foguetes.\p"
	.string "Por favor, nao tentem impedir.\n"
	.string "Vamos levar de qualquer jeito.\p"
	.string "Por um mundo com mais terra! Team\n"
	.string "Magma.”$"
