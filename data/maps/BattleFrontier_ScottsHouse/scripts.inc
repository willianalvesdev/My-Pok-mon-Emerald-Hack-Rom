BattleFrontier_ScottsHouse_MapScripts::
	.byte 0

BattleFrontier_ScottsHouse_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_4, BattleFrontier_ScottsHouse_EventScript_GivenBerry
	goto_if_set FLAG_TEMP_3, BattleFrontier_ScottsHouse_EventScript_GivenShield
	goto_if_set FLAG_TEMP_2, BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveItems
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveItems::
	goto_if_unset FLAG_SCOTT_GIVES_BATTLE_POINTS, BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier
	goto_if_unset FLAG_COLLECTED_ALL_SILVER_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols
	goto_if_unset FLAG_COLLECTED_ALL_GOLD_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveShield::
	goto_if_unset FLAG_RECEIVED_SILVER_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield
	goto_if_unset FLAG_RECEIVED_GOLD_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols::
	goto_if_unset FLAG_SYS_TOWER_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_DOME_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PALACE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_ARENA_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_FACTORY_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PIKE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PYRAMID_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols, MSGBOX_DEFAULT
	giveitem ITEM_LANSAT_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull
	setflag FLAG_COLLECTED_ALL_SILVER_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols::
	goto_if_unset FLAG_SYS_TOWER_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_DOME_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PALACE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_ARENA_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_FACTORY_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PIKE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PYRAMID_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols, MSGBOX_DEFAULT
	giveitem ITEM_STARF_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull
	setflag FLAG_COLLECTED_ALL_GOLD_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_BerryPocketFull::
	msgbox BattleFrontier_ScottsHouse_Text_BerryPocketStuffed, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenBerry::
	msgbox BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_RandomComment::
	random 3
	goto_if_eq VAR_RESULT, 1, BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment
	goto_if_eq VAR_RESULT, 2, BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment
	msgbox BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment::
	msgbox BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment::
	msgbox BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_GiveSilverShield::
	msgbox BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow, MSGBOX_DEFAULT
	givedecoration DECOR_SILVER_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield
	setflag FLAG_RECEIVED_SILVER_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield
	end

BattleFrontier_ScottsHouse_EventScript_NoRoomForShield::
	msgbox BattleFrontier_ScottsHouse_Text_ComeBackForThisLater, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenShield::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_GiveGoldShield::
	msgbox BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow, MSGBOX_DEFAULT
	givedecoration DECOR_GOLD_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield
	setflag FLAG_RECEIVED_GOLD_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield
	end

BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingGreatThings, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier::
	msgbox BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	closemessage
	delay 30
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwaySouth
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayEast
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayWest
	msgbox BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal, MSGBOX_DEFAULT
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing, MSGBOX_DEFAULT
	goto_if_eq VAR_SCOTT_STATE, 13, BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints
	goto_if_ge VAR_SCOTT_STATE, 9, BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints
	goto_if_ge VAR_SCOTT_STATE, 6, BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints
	goto BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint
	end

BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints::
	buffernumberstring STR_VAR_1, 4
	setvar VAR_0x8004, 4
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints::
	buffernumberstring STR_VAR_1, 3
	setvar VAR_0x8004, 3
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints::
	buffernumberstring STR_VAR_1, 2
	setvar VAR_0x8004, 2
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint::
	buffernumberstring STR_VAR_1, 1
	setvar VAR_0x8004, 1
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints::
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	msgbox BattleFrontier_ScottsHouse_Text_ExplainBattlePoints, MSGBOX_DEFAULT
	setflag FLAG_SCOTT_GIVES_BATTLE_POINTS
	setflag FLAG_TEMP_2
	release
	end

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayNorth::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwaySouth::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayEast::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayWest::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier:
	.string "SCOTT: Oi, entra! Heheh... Foi mal\n"
	.string "pelo espaço apertado. Bom,\l"
	.string "{PLAYER}{KUN}, seja bem-vindo à Battle\l"
	.string "Frontier. Esse é meu sonho\l"
	.string "realizado. Levou anos, mas\l"
	.string "finalmente consegui tirar a ideia\l"
	.string "do papel.$"

BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal:
	.string "Pensando bem, foi uma longa\n"
	.string "jornada...\p"
	.string "Saí de casa sozinho à procura de\n"
	.string "treinadores fortes.\p"
	.string "Ninguém imagina o tempo e o\n"
	.string "esforço que precisei para fazer\l"
	.string "isso acontecer.$"

BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing:
	.string "Mas isso ficou no passado. Nao\n"
	.string "vale a pena ficar pensando nisso!\p"
	.string "Só quero que você batalhe aqui o\n"
	.string "quanto tiver vontade.\p"
	.string "{PLAYER}{KUN}, quero que fique com isto\n"
	.string "como lembrança de todas as vezes\l"
	.string "que nos encontramos pelo caminho.$"

BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints:
	.string "{PLAYER} ganhou {STR_VAR_1}\n"
	.string "Pontos de Batalha.$"

BattleFrontier_ScottsHouse_Text_ExplainBattlePoints:
	.string "SCOTT: Você pode conferir seus\n"
	.string "Pontos de Batalha no FRONTIER\l"
	.string "PASS.\p"
	.string "Quanto mais vencer na BATTLE\n"
	.string "FRONTIER, mais pontos vai juntar.\p"
	.string "Use como quiser, por exemplo,\n"
	.string "trocando por itens.$"

BattleFrontier_ScottsHouse_Text_ExpectingGreatThings:
	.string "Espero grandes coisas de você!$"

BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers:
	.string "SCOTT: Cada treinador é uma pessoa\n"
	.string "diferente, com sua própria vida.\p"
	.string "Mas, numa batalha, nao importa\n"
	.string "quem você é.\p"
	.string "Todos ficam em pé de igualdade!\p"
	.string "Eu adoro isso nas batalhas.\p"
	.string "É por isso que viajo procurando\n"
	.string "treinadores que levam as batalhas\l"
	.string "a sério e os convido para cá.$"

BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain:
	.string "SCOTT: Já conheceu algum dos\n"
	.string "FRONTIER BRAINS?\p"
	.string "Melhor ainda: já ganhou algum\n"
	.string "Símbolo deles?\p"
	.string "Escolhi cada um por serem os\n"
	.string "treinadores mais fortes que\l"
	.string "encontrei.\p"
	.string "Mas tenho certeza de que até eles\n"
	.string "vao se surpreender com sua força!$"

BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier:
	.string "SCOTT: Você faz mais do que\n"
	.string "treinar para batalhas, né?\p"
	.string "Lembro que também estava\n"
	.string "completando uma POKéDEX.\p"
	.string "Quer saber de uma coisa?\p"
	.string "Talvez encontre Pokémon selvagens\n"
	.string "em algum canto da BATTLE\l"
	.string "FRONTIER... Hehehe!$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols:
	.string "SCOTT: Está gostando da BATTLE\n"
	.string "FRONTIER?\p"
	.string "...Espera um pouco... Ah!\p"
	.string "Seu FRONTIER PASS! Você conseguiu\n"
	.string "todos os Símbolos de prata!\p"
	.string "Que incrível! Você é forte mesmo,\n"
	.string "como eu imaginava!\p"
	.string "Normalmente eu nao faria isso, mas\n"
	.string "a ocasiao é especial!\p"
	.string "Quero que fique com isto. Tenho\n"
	.string "certeza de que vai aproveitar bem.$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols:
	.string "SCOTT: Espero que esteja gostando\n"
	.string "de tudo na BATTLE FRONTIER.\p"
	.string "...Espera um pouco... Nao acredito\n"
	.string "no que estou vendo!\p"
	.string "Seu FRONTIER PASS! Você conseguiu\n"
	.string "todos os Símbolos de ouro!\p"
	.string "Que coisa incrível! Você é fora de\n"
	.string "série, como eu imaginava!\p"
	.string "... ... ... ... ... ...\p"
	.string "{PLAYER}, você precisa aceitar\n"
	.string "isto!\p"
	.string "Acho que vai dar o devido valor ao\n"
	.string "meu presente!$"

BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere:
	.string "Tenho que admitir: sei reconhecer\n"
	.string "um bom treinador quando vejo um.\p"
	.string "Ainda bem que tive a ideia de te\n"
	.string "trazer para cá!$"

BattleFrontier_ScottsHouse_Text_BerryPocketStuffed:
	.string "Seu bolso de Berries está cheio.$"

BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow:
	.string "SCOTT: Ah, ouvi falar de você!\n"
	.string "Arrasou na BATTLE TOWER! Venceu\l"
	.string "mais de 50 treinadores seguidos?\p"
	.string "Isso é incrível! Quero que fique\n"
	.string "com isto!$"

BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow:
	.string "SCOTT: Nossa! Ouvi falar de você!\n"
	.string "Dominou a BATTLE TOWER! Venceu\l"
	.string "mais de 100 treinadores seguidos?\p"
	.string "Isso é bom demais! Você precisa\n"
	.string "ficar com isto!$"

BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings:
	.string "Agora vou esperar notícias ainda\n"
	.string "melhores sobre você!$"

BattleFrontier_ScottsHouse_Text_ComeBackForThisLater:
	.string "Opa, se estiver sem espaço, volte\n"
	.string "para pegar isto depois.$"

