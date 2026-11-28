BattleFrontier_ReceptionGate_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition
	.byte 0

BattleFrontier_ReceptionGate_OnTransition:
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_OnFrame:
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering::
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter
	waitmovement 0
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene
	end

BattleFrontier_ReceptionGate_EventScript_ScottScene::
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_ExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_FRONTIER_RECEPTION_SCOTT
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_PlayerFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

@ Unused
BattleFrontier_ReceptionGate_Movement_WalkDown:
	walk_down
	walk_down
	step_end

BattleFrontier_ReceptionGate_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_ScottExit:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_GreeterFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

BattleFrontier_ReceptionGate_EventScript_Greeter::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FacilityGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
	special ShowScrollableMultichoice
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_BattleTower
	case 1, BattleFrontier_ReceptionGate_EventScript_BattleDome
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePalace
	case 3, BattleFrontier_ReceptionGate_EventScript_BattleArena
	case 4, BattleFrontier_ReceptionGate_EventScript_BattleFactory
	case 5, BattleFrontier_ReceptionGate_EventScript_BattlePike
	case 6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid
	case 7, BattleFrontier_ReceptionGate_EventScript_RankingHall
	case 8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner
	case 9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	end

BattleFrontier_ReceptionGate_EventScript_BattleTower::
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleDome::
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePalace::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleArena::
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleFactory::
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePike::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePyramid::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RankingHall::
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExchangeCorner::
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_RulesGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat
	waitmessage
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_LevelMode
	case 1, BattleFrontier_ReceptionGate_EventScript_Level50
	case 2, BattleFrontier_ReceptionGate_EventScript_OpenLevel
	case 3, BattleFrontier_ReceptionGate_EventScript_MonEntry
	case 4, BattleFrontier_ReceptionGate_EventScript_HoldItems
	case 5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	end

BattleFrontier_ReceptionGate_EventScript_LevelMode::
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_Level50::
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_OpenLevel::
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_MonEntry::
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_HoldItems::
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1
	waitmessage
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_Symbols
	case 1, BattleFrontier_ReceptionGate_EventScript_RecordBattle
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePoints
	case 3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	end

BattleFrontier_ReceptionGate_EventScript_Symbols::
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RecordBattle::
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePoints::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay:
	.string "É sua primeira vez aqui? Pode vir\n"
	.string "por aqui!$"

BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier:
	.string "O lugar das grandes batalhas\n"
	.string "Pokémon! Boas-vindas à BATTLE\l"
	.string "FRONTIER!$"

BattleFrontier_ReceptionGate_Text_IssueFrontierPass:
	.string "Quem vem pela primeira vez recebe\n"
	.string "o FRONTIER PASS.\p"
	.string "Ele serve para todas as\n"
	.string "instalaçoes da BATTLE FRONTIER.\p"
	.string "Aqui está!$"

BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass:
	.string "{PLAYER} recebeu o FRONTIER PASS.$"

BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass:
	.string "{PLAYER} guardou o Cartao de\n"
	.string "Treinador no FRONTIER PASS.$"

BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier:
	.string "Esperamos que aproveite tudo o que\n"
	.string "a BATTLE FRONTIER oferece!$"

BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame:
	.string "???: Ora, se nao é {PLAYER}{KUN}! Você\n"
	.string "veio mesmo!$"

BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay:
	.string "GUIA: Ah! Senhor SCOTT! Bom dia!$"

BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere:
	.string "SCOTT: Que bom te ver aqui! Bom\n"
	.string "mesmo!\p"
	.string "Espero que tenha tempo de\n"
	.string "conhecer cada canto.\p"
	.string "E, claro, de sentir toda a emoçao\n"
	.string "das batalhas.\p"
	.string "Também tenho uma casa aqui, entao\n"
	.string "passe lá quando puder.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFacilities:
	.string "Vou te apresentar as instalaçoes\n"
	.string "da BATTLE FRONTIER.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich2:
	.string "Sobre qual lugar quer saber?$"

BattleFrontier_ReceptionGate_Text_BattleTowerInfo:
	.string "É a torre gigante, considerada o\n"
	.string "símbolo da BATTLE FRONTIER.\p"
	.string "Ela tem quatro tipos de Sala de\n"
	.string "Batalha: Individual, em Dupla, em\l"
	.string "Parceria e em Parceria via Link.$"

BattleFrontier_ReceptionGate_Text_BattleDomeInfo:
	.string "O BATTLE DOME é o prédio grande em\n"
	.string "forma de ovo.\p"
	.string "Lá acontecem os Torneios de\n"
	.string "Batalha.\p"
	.string "Há duas modalidades: batalhas\n"
	.string "individuais e em dupla.$"

BattleFrontier_ReceptionGate_Text_BattlePalaceInfo:
	.string "O BATTLE PALACE é o prédio\n"
	.string "vermelho do lado direito da BATTLE\l"
	.string "FRONTIER.\p"
	.string "Tem dois tipos de Salao de\n"
	.string "Batalha: Individual e em Dupla.$"

BattleFrontier_ReceptionGate_Text_BattleArenaInfo:
	.string "A BATTLE ARENA é o prédio parecido\n"
	.string "com um dojo, à direita do centro\l"
	.string "da BATTLE FRONTIER.\p"
	.string "Lá acontece o Torneio de Nocautes.$"

BattleFrontier_ReceptionGate_Text_BattleFactoryInfo:
	.string "A BATTLE FACTORY é o prédio grande\n"
	.string "mais perto daqui.\p"
	.string "Lá acontece o Desafio de Trocas.\p"
	.string "Ele tem duas modalidades:\n"
	.string "Individual e em Dupla.$"

BattleFrontier_ReceptionGate_Text_BattlePikeInfo:
	.string "O BATTLE PIKE é o prédio em forma\n"
	.string "de Pokémon, à esquerda do centro\l"
	.string "da BATTLE FRONTIER.\p"
	.string "Lá acontece o Desafio dos\n"
	.string "Caminhos.$"

BattleFrontier_ReceptionGate_Text_BattlePyramidInfo:
	.string "A BATTLE PYRAMID é aquela pirâmide\n"
	.string "enorme.\p"
	.string "Lá acontece a Jornada de Batalha.$"

BattleFrontier_ReceptionGate_Text_RankingHallInfo:
	.string "O RANKING HALL fica perto da\n"
	.string "BATTLE TOWER.\p"
	.string "Lá você pode ver os melhores\n"
	.string "recordes dos treinadores nos\l"
	.string "vários desafios da BATTLE\l"
	.string "FRONTIER.$"

BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo:
	.string "O EXCHANGE SERVICE CORNER fica\n"
	.string "perto da BATTLE TOWER.\p"
	.string "Lá você troca os Pontos de\n"
	.string "Batalha que ganhou na BATTLE\l"
	.string "FRONTIER por prêmios.$"

BattleFrontier_ReceptionGate_Text_YourGuideToRules:
	.string "Vou explicar as regras básicas que\n"
	.string "valem para todos os desafios da\l"
	.string "BATTLE FRONTIER.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhat:
	.string "Sobre o que quer saber?$"

BattleFrontier_ReceptionGate_Text_LevelModeInfo:
	.string "Todos os desafios da BATTLE\n"
	.string "FRONTIER têm duas modalidades:\l"
	.string "Nível 50 e Nível Livre.$"

BattleFrontier_ReceptionGate_Text_Level50Info:
	.string "O desafio de Nível 50 aceita\n"
	.string "Pokémon até o nível 50.\p"
	.string "Mas lembre que os adversários nao\n"
	.string "terao nenhum Pokémon abaixo do\l"
	.string "nível 50.\p"
	.string "É a modalidade de entrada da\n"
	.string "BATTLE FRONTIER.\p"
	.string "Recomendamos começar por ela.$"

BattleFrontier_ReceptionGate_Text_OpenLevelInfo:
	.string "O Nível Livre nao limita o nível\n"
	.string "dos Pokémon que entram no desafio.\p"
	.string "Os níveis dos adversários sao\n"
	.string "ajustados para acompanhar os dos\l"
	.string "seus Pokémon.\p"
	.string "Mas nenhum adversário terá Pokémon\n"
	.string "abaixo do nível 60.$"

BattleFrontier_ReceptionGate_Text_MonEntryInfo:
	.string "Quase todas as espécies de\n"
	.string "Pokémon podem participar dos\l"
	.string "desafios.\p"
	.string "Mas Ovos e algumas espécies nao\n"
	.string "sao permitidos.\p"
	.string "A quantidade de Pokémon exigida\n"
	.string "depende da instalaçao.\p"
	.string "Em todas elas, sua equipe nao pode\n"
	.string "ter dois Pokémon da mesma espécie.$"

BattleFrontier_ReceptionGate_Text_HoldItemsInfo:
	.string "Ao entrar num desafio da BATTLE\n"
	.string "FRONTIER, seus Pokémon nao podem\l"
	.string "estar segurando itens iguais.\p"
	.string "Confira se todos estao segurando\n"
	.string "itens diferentes.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass:
	.string "Vou te explicar o FRONTIER PASS.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich1:
	.string "Sobre o que quer saber?$"

BattleFrontier_ReceptionGate_Text_SymbolsInfo:
	.string "A BATTLE FRONTIER tem sete\n"
	.string "instalaçoes.\p"
	.string "Treinadores que mostram seu\n"
	.string "talento podem ganhar um Símbolo\l"
	.string "de cada uma.\p"
	.string "Para conseguir um Símbolo, pode\n"
	.string "ser preciso vencer vários\l"
	.string "treinadores seguidos ou ganhar o\l"
	.string "mesmo desafio várias vezes.\p"
	.string "Nao é fácil juntar os Símbolos.\n"
	.string "Boa sorte!$"

BattleFrontier_ReceptionGate_Text_RecordedBattleInfo:
	.string "Você pode gravar uma batalha no\n"
	.string "FRONTIER PASS.\p"
	.string "Pode ser uma batalha contra um ou\n"
	.string "mais amigos.\p"
	.string "Também pode gravar batalhas da\n"
	.string "BATTLE FRONTIER, exceto as do\l"
	.string "BATTLE PIKE e da BATTLE PYRAMID.\p"
	.string "A opçao de gravar aparece no fim\n"
	.string "da batalha.$"

BattleFrontier_ReceptionGate_Text_BattlePointsInfo:
	.string "Os Pontos de Batalha sao prêmios\n"
	.string "por bons resultados na BATTLE\l"
	.string "FRONTIER.\p"
	.string "Você pode trocá-los por prêmios no\n"
	.string "EXCHANGE SERVICE CORNER.$"

