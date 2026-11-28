BattleFrontier_Lounge3_MapScripts::
	.byte 0

	.set BET_AMOUNT_5,  5
	.set BET_AMOUNT_10, 10
	.set BET_AMOUNT_15, 15

BattleFrontier_Lounge3_EventScript_Gambler::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols
	goto_if_le VAR_0x8004, 2, BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_AskToEnterChallenge::
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_ChooseBetAmount::
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet
	end

BattleFrontier_Lounge3_EventScript_Bet5::
	setvar VAR_0x8008, BET_AMOUNT_5
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet10::
	setvar VAR_0x8008, BET_AMOUNT_10
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet15::
	setvar VAR_0x8008, BET_AMOUNT_15
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_TryPlaceBet::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge3_EventScript_PlaceBet
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_PlaceBet::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FinishBet
	end

BattleFrontier_Lounge3_EventScript_FinishBet::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_CountSilverSymbols::
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	return

BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount::
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols::
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_AlreadyMetGambler::
	msgbox BattleFrontier_Lounge3_Text_Oh, MSGBOX_DEFAULT
	goto_if_ge VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_CheckBetResults
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_CheckBetResults::
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON, BattleFrontier_Lounge3_EventScript_WonChallenge
	goto BattleFrontier_Lounge3_EventScript_LostChallenge
	end

BattleFrontier_Lounge3_EventScript_WonChallenge::
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints, MSGBOX_DEFAULT
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_RewardBet5
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_RewardBet10
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_RewardBet15
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints, MSGBOX_GETPOINTS
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_LostChallenge::
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_RewardBet5::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_5 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet10::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_10 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet15::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_15 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
	return

BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_DeclineChallenge::
	msgbox BattleFrontier_Lounge3_Text_NotInterested, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_CancelBet::
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge
	end

BattleFrontier_Lounge3_EventScript_Man::
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_Woman::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FatMan::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere::
	.string "...O que você quer?\p"
	.string "Nao está vendo que estamos\n"
	.string "ocupados? Nao pode deixar isso pra\l"
	.string "depois?$"

BattleFrontier_Lounge3_Text_YouLookToughExplainGambling::
	.string "...Hein? Você parece um treinador\n"
	.string "forte.\p"
	.string "Hehe... Escuta, tenho uma\n"
	.string "proposta.\p"
	.string "A gente se reúne aqui e faz um\n"
	.string "joguinho com os desafios da BATTLE\l"
	.string "FRONTIER.\p"
	.string "As regras sao bem simples.\p"
	.string "Primeiro, escolhemos uma das\n"
	.string "instalaçoes.\p"
	.string "Depois, cada um escolhe um\n"
	.string "treinador que vai participar e\l"
	.string "aposta seus Pontos de Batalha.\p"
	.string "Quem apostar no treinador com o\n"
	.string "melhor resultado fica com todos os\l"
	.string "pontos.\p"
	.string "Simples, né? Entao...$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle::
	.string "Estou procurando alguém que vá\n"
	.string "desafiar as Salas de Batalhas\l"
	.string "Individuais da BATTLE TOWER.\p"
	.string "Mas ainda nao achei ninguém com\n"
	.string "jeito de quem vai ganhar.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble::
	.string "Estou procurando alguém que vá\n"
	.string "desafiar as Salas de Batalhas em\l"
	.string "Dupla da BATTLE TOWER.\p"
	.string "Mas ainda nao achei ninguém com\n"
	.string "jeito de quem vai ganhar.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti::
	.string "Estou procurando alguém que vá\n"
	.string "desafiar as Salas de Batalhas em\l"
	.string "Parceria da BATTLE TOWER.\p"
	.string "Mas ainda nao achei ninguém com\n"
	.string "jeito de quem vai ganhar.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle::
	.string "Estou procurando alguém que vá\n"
	.string "participar do Torneio de Batalhas\l"
	.string "Individuais do BATTLE DOME.\p"
	.string "Mas ainda nao achei ninguém com\n"
	.string "jeito de quem vai ganhar.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble::
	.string "Estou procurando alguém que vá\n"
	.string "participar do Torneio de Batalhas\l"
	.string "em Dupla do BATTLE DOME.\p"
	.string "Mas ainda nao achei ninguém com\n"
	.string "jeito de quem vai ganhar.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle::
	.string "Estou procurando alguém que vá\n"
	.string "participar do Desafio de Trocas\l"
	.string "Individual da BATTLE FACTORY.\p"
	.string "Mas ainda nao achei ninguém com\n"
	.string "jeito de quem vai ganhar.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble::
	.string "Estou procurando alguém que vá\n"
	.string "participar do Desafio de Trocas em\l"
	.string "Dupla da BATTLE FACTORY.\p"
	.string "Mas ainda nao achei ninguém com\n"
	.string "jeito de quem vai ganhar.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle::
	.string "Estou procurando alguém que vá\n"
	.string "desafiar os Saloes de Batalhas\l"
	.string "Individuais do BATTLE PALACE.\p"
	.string "Mas ainda nao achei ninguém com\n"
	.string "jeito de quem vai ganhar.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble::
	.string "Estou procurando alguém que vá\n"
	.string "desafiar os Saloes de Batalhas em\l"
	.string "Dupla do BATTLE PALACE.\p"
	.string "Mas ainda nao achei ninguém com\n"
	.string "jeito de quem vai ganhar.$"

BattleFrontier_Lounge3_Text_ChallengeBattleArena::
	.string "Estou procurando alguém que vá\n"
	.string "participar do Torneio de Nocautes\l"
	.string "da BATTLE ARENA.\p"
	.string "Mas ainda nao achei ninguém com\n"
	.string "jeito de quem vai ganhar.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePike::
	.string "Estou procurando alguém que vá\n"
	.string "participar do Desafio dos Caminhos\l"
	.string "do BATTLE PIKE.\p"
	.string "Mas ainda nao achei ninguém com\n"
	.string "jeito de quem vai ganhar.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePyramid::
	.string "Estou procurando alguém que vá\n"
	.string "participar da Jornada de Batalha\l"
	.string "da BATTLE PYRAMID.\p"
	.string "Mas ainda nao achei ninguém com\n"
	.string "jeito de quem vai ganhar.$"

BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe::
	.string "Vou fazer valer a pena pra você\n"
	.string "também. E aí? Topa participar\l"
	.string "desse desafio por mim?$"

BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints::
	.string "Beleza, perfeito. Entao... Que tal\n"
	.string "me emprestar alguns Pontos de\l"
	.string "Batalha?\p"
	.string "Confia em mim, depois eu agradeço\n"
	.string "como deve ser.$"

BattleFrontier_Lounge3_Text_HowMuchCanYouSpot::
	.string "Ótimo, ótimo! Quanto pode me\n"
	.string "emprestar?$"

BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints::
	.string "Ah, nao! Você nao tem Pontos de\n"
	.string "Batalha suficientes!\p"
	.string "Nao fique de brincadeira e fazendo\n"
	.string "a gente perder tempo!$"

BattleFrontier_Lounge3_Text_ThanksOffYouGo::
	.string "Hehe! Valeu mesmo! Agora pode ir!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerSingle::
	.string "Vá logo para as Salas de Batalhas\n"
	.string "Individuais da BATTLE TOWER!\p"
	.string "Você precisa ganhar! Nao\n"
	.string "desperdice essa chance! Nosso\l"
	.string "futuro depende de você!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerDouble::
	.string "Vá logo para as Salas de Batalhas\n"
	.string "em Dupla da BATTLE TOWER!\p"
	.string "Você precisa ganhar! Nao\n"
	.string "desperdice essa chance! Nosso\l"
	.string "futuro depende de você!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerMulti::
	.string "Vá logo para as Salas de Batalhas\n"
	.string "em Parceria da BATTLE TOWER!\p"
	.string "Você precisa ganhar! Nao\n"
	.string "desperdice essa chance! Nosso\l"
	.string "futuro depende de você!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeSingle::
	.string "Vá logo para o Torneio de Batalhas\n"
	.string "Individuais do BATTLE DOME!\p"
	.string "Você precisa ganhar! Nao\n"
	.string "desperdice essa chance! Nosso\l"
	.string "futuro depende de você!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeDouble::
	.string "Vá logo para o Torneio de Batalhas\n"
	.string "em Dupla do BATTLE DOME!\p"
	.string "Você precisa ganhar! Nao\n"
	.string "desperdice essa chance! Nosso\l"
	.string "futuro depende de você!$"

BattleFrontier_Lounge3_Text_GetToBattleFactorySingle::
	.string "Vá logo para o Desafio de Trocas\n"
	.string "Individual da BATTLE FACTORY!\p"
	.string "Você precisa ganhar! Nao\n"
	.string "desperdice essa chance! Nosso\l"
	.string "futuro depende de você!$"

BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble::
	.string "Vá logo para o Desafio de Trocas\n"
	.string "em Dupla da BATTLE FACTORY!\p"
	.string "Você precisa ganhar! Nao\n"
	.string "desperdice essa chance! Nosso\l"
	.string "futuro depende de você!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle::
	.string "Vá logo para os Saloes de Batalhas\n"
	.string "Individuais do BATTLE PALACE!\p"
	.string "Você precisa ganhar! Nao\n"
	.string "desperdice essa chance! Nosso\l"
	.string "futuro depende de você!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble::
	.string "Vá logo para os Saloes de Batalhas\n"
	.string "em Dupla do BATTLE PALACE!\p"
	.string "Você precisa ganhar! Nao\n"
	.string "desperdice essa chance! Nosso\l"
	.string "futuro depende de você!$"

BattleFrontier_Lounge3_Text_GetToBattleArena::
	.string "Vá logo para o Torneio de Nocautes\n"
	.string "da BATTLE ARENA!\p"
	.string "Você precisa ganhar! Nao\n"
	.string "desperdice essa chance! Nosso\l"
	.string "futuro depende de você!$"

BattleFrontier_Lounge3_Text_GetToBattlePike::
	.string "Vá logo para o Desafio dos\n"
	.string "Caminhos do BATTLE PIKE!\p"
	.string "Você precisa ganhar! Nao\n"
	.string "desperdice essa chance! Nosso\l"
	.string "futuro depende de você!$"

BattleFrontier_Lounge3_Text_GetToBattlePyramid::
	.string "Vá logo para a Jornada de Batalha\n"
	.string "da BATTLE PYRAMID!\p"
	.string "Você precisa ganhar! Nao\n"
	.string "desperdice essa chance! Nosso\l"
	.string "futuro depende de você!$"

BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints::
	.string "Ah, é você... Boa tentativa...\p"
	.string "O problema é que nao posso\n"
	.string "devolver seus Pontos de Batalha...\p"
	.string "Vamos usar isso como motivo pra\n"
	.string "tentar com mais força na próxima!$"

BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints::
	.string "Ah, sim! Oi, campeao! Eu sabia que\n"
	.string "você conseguia! Sabia mesmo! Nós\l"
	.string "dois ganhamos! Vou devolver seus\l"
	.string "Battle Points e ainda dar um\l"
	.string "extra!$"

BattleFrontier_Lounge3_Text_ObtainedBattlePoints::
	.string "{PLAYER} ganhou {STR_VAR_1}\n"
	.string "Pontos de Batalha.$"

BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge::
	.string "Se for tentar outro desafio,\n"
	.string "lembra de mim!$"

BattleFrontier_Lounge3_Text_NotInterested::
	.string "Nao quer?! Nao precisa ter tanto\n"
	.string "medo de arriscar!$"

BattleFrontier_Lounge3_Text_Oh::
	.string "Ah...$"

BattleFrontier_Lounge3_Text_BackedWrongTrainer::
	.string "Apostei no treinador errado de\n"
	.string "novo!\p"
	.string "Talvez eu devesse batalhar como\n"
	.string "todo mundo...$"

BattleFrontier_Lounge3_Text_TrainerGoodButRattled::
	.string "Aquele treinador...\p"
	.string "Ele é bom, mas perde a calma fácil\n"
	.string "demais pra aguentar o BATTLE\l"
	.string "DOME...$"

BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne::
	.string "Hehe! Eu reconheço quem vai ganhar\n"
	.string "só de olhar!$"

BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges::
	.string "Aqueles treinadores... O que estao\n"
	.string "fazendo? Deviam estar participando\l"
	.string "dos desafios.$"
