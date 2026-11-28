BattleFrontier_OutsideWest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
	.byte 0

BattleFrontier_OutsideWest_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_Red::
	trainerbattle_single TRAINER_RED, BattleFrontier_OutsideWest_Text_Red, BattleFrontier_OutsideWest_Text_Red, BattleFrontier_OutsideWest_EventScript_RedReward
	msgbox BattleFrontier_OutsideWest_Text_Red, MSGBOX_DEFAULT

BattleFrontier_OutsideWest_EventScript_RedReward::
	goto_if_set FLAG_RECEIVED_OLD_SEA_MAP, BattleFrontier_OutsideWest_EventScript_RedEnd
	giveitem ITEM_OLD_SEA_MAP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	setflag FLAG_RECEIVED_OLD_SEA_MAP

BattleFrontier_OutsideWest_EventScript_RedEnd::
	release
	end

BattleFrontier_OutsideWest_Text_Red:
	.string "...$"

BattleFrontier_OutsideWest_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination::
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	end

BattleFrontier_OutsideWest_EventScript_NoSSTicket::
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToSlateport::
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToLilycove::
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination::
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_BoardFerry::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_FRONTIER_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_FRONTIER_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	return

BattleFrontier_OutsideWest_EventScript_CancelFerrySelect::
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
	waitmessage
	applymovement LOCALID_FRONTIER_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_Maniac2::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
	applymovement LOCALID_FRONTIER_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
	return

BattleFrontier_OutsideWest_EventScript_Girl::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign:
	.string "Este é o BATTLE DOME! Seu caminho\n"
	.string "para se tornar uma estrela\l"
	.string "imbatível!$"

BattleFrontier_OutsideWest_Text_BattleFactorySign:
	.string "Esta é a BATTLE FACTORY! Procure\n"
	.string "os Pokémon mais fortes!$"

BattleFrontier_OutsideWest_Text_BattlePikeSign:
	.string "Este é o BATTLE PIKE! Escolha um\n"
	.string "dos três caminhos!$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
	.string "Esta é a BATTLE TOWER.\p"
	.string "Os treinadores trazem seus Pokémon\n"
	.string "mais bem treinados para disputar\l"
	.string "partidas eliminatórias.$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
	.string "Oi, veio pegar a balsa? Posso ver\n"
	.string "seu ticket?$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
	.string "{PLAYER} nao tem a PASSAGEM...\p"
	.string "Sinto muito.\p"
	.string "Você precisa de uma PASSAGEM para\n"
	.string "embarcar.$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
	.string "{PLAYER} mostrou a PASSAGEM.\p"
	.string "Perfeito! É só disso que precisa!\p"
	.string "Para onde quer ir?$"

BattleFrontier_OutsideWest_Text_SlateportItIs:
	.string "SLATEPORT CITY, entao!$"

BattleFrontier_OutsideWest_Text_LilycoveItIs:
	.string "LILYCOVE CITY, entao!$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
	.string "Viaje com a gente outra hora!$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
	.string "Pode embarcar e esperar a partida.$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
	.string "Entao, para onde quer ir?$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
	.string "Sou o melhor entre meus amigos.\n"
	.string "Mas aqui... Nao consegui fazer\l"
	.string "nada!$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower:
	.string "Quero ir à BATTLE TOWER, mas nao\n"
	.string "acho o lugar nem com o mapa da\l"
	.string "BATTLE FRONTIER.\p"
	.string "Aqui é grande demais!$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
	.string "Eu queria tentar um desafio assim\n"
	.string "que chegasse.\p"
	.string "Mas enjoei durante a viagem de\n"
	.string "barco... Urgh...$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
	.string "Nao é qualquer pessoa que pode vir\n"
	.string "aqui, sabia?\p"
	.string "Só trazem treinadores que\n"
	.string "mostraram ser fortes.\p"
	.string "Por isso, muitos nem sabem da\n"
	.string "BATTLE FRONTIER.$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
	.string "Ei, mano...\p"
	.string "Tem certeza de que dá para\n"
	.string "participar sem nenhum Pokémon?$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
	.string "É... Tenho certeza de que vai dar\n"
	.string "certo.\p"
	.string "Eu acho...\p"
	.string "Lembra daquele cara grande e\n"
	.string "assustador? Ele disse: “Eu\l"
	.string "empresto Pokémon!”$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
	.string "Aquela é a BATTLE FACTORY. Dá\n"
	.string "para alugar Pokémon fortes lá.\p"
	.string "Mas fico pensando: quem treina\n"
	.string "esses Pokémon de aluguel?$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
	.string "Tenho medo de entrar no BATTLE\n"
	.string "PIKE por causa do SEVIPER...\p"
	.string "M-mas vim até aqui, entao vou\n"
	.string "tentar vencer todos os desafios!\l"
	.string "...Treme...$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
	.string "Vamos brincar de pedra, papel e\n"
	.string "tesoura! Um, dois, três!\p"
	.string "... ... ... ... ... ...$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
	.string "Oba! Ganhei! Vou tentar o desafio\n"
	.string "do BATTLE PIKE!$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
	.string "Ah, nao... Perdi.\p"
	.string "Acho que hoje estou sem sorte.\n"
	.string "Vou deixar o desafio do BATTLE\l"
	.string "PIKE para amanha.$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
	.string "Acho que sou a única pessoa aqui\n"
	.string "que, por algum motivo, prefere\l"
	.string "pescar a batalhar.\p"
	.string "Hein? Nao dá para pescar nada\n"
	.string "aqui? Que pena...$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
	.string "Hoje vou continuar batalhando até\n"
	.string "ganhar um Símbolo, aconteça o que\l"
	.string "acontecer.$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
	.string "Ah, vai desafiar o BATTLE DOME?\p"
	.string "Boa sorte. Tomara que a gente\n"
	.string "vença e se encontre nos desafios.$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
	.string "Vovô, aqui! O BATTLE DOME é aqui!\n"
	.string "Vai com tudo, vovô!$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
	.string "Ah, entao este é o BATTLE DOME?\n"
	.string "Nao vou perder para esses\l"
	.string "cavalheiros!\p"
	.string "Mas onde fica a entrada?$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
	.string "Até pouco tempo atrás, nao tinha\n"
	.string "nada aqui.\p"
	.string "Agora olha só! Incrível! Vou\n"
	.string "trazer minha mae para conhecer.$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
	.string "Finalmente cheguei à BATTLE\n"
	.string "FRONTIER!\p"
	.string "Vou chamar atençao pela beleza e\n"
	.string "pelo talento!$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
	.string "Nhac, nhac...\p"
	.string "Parece que esta praça está cheia\n"
	.string "de gente forte.\p"
	.string "Nhac, nhac...$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
	.string "Croc, nhac...\p"
	.string "Um tempo atrás, encontrei uma moça\n"
	.string "no BATTLE PIKE.\p"
	.string "Ela tinha um olhar bem assustador,\n"
	.string "de quem estava de mau humor.\p"
	.string "Croc, nhac...\p"
	.string "Ela ficou furiosa: “Você nao para\n"
	.string "de comer?!” Depois acabou comigo.\p"
	.string "Foi uma experiência de arrepiar,\n"
	.string "pode ter certeza.\p"
	.string "Croc, nhac...$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
	.string "Hein? Você está se ouvindo? Isso\n"
	.string "nao é nada!\p"
	.string "Da última vez que torci por ele,\n"
	.string "nossos olhares se cruzaram e até\l"
	.string "saíram faíscas!$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
	.string "O quêêê?! Ah, tá!\p"
	.string "Isso só aconteceu porque eu\n"
	.string "estava sentada do seu lado!\p"
	.string "O DOME ACE só olhou pra cá porque\n"
	.string "eu estava gritando mais alto!$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine:
	.string "Ah, quietas! Parem com esse\n"
	.string "barulho!\p"
	.string "Vocês, fas de ocasiao, deviam\n"
	.string "torcer por algum líder de ginásio!\p"
	.string "O DOME ACE é meu! Ele é meu único\n"
	.string "ídolo!$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
	.string "Aquelas pessoas discutindo ali...\p"
	.string "É difícil acreditar, mas já foram\n"
	.string "treinadores. E bons!\p"
	.string "Eram muito fortes e famosos.\p"
	.string "Mas um certo treinador acabou com\n"
	.string "eles num torneio.\p"
	.string "A derrota foi tao grande que\n"
	.string "ficaram encantados por ele.\p"
	.string "Agora sao fas. Vao torcer pelo\n"
	.string "ídolo no BATTLE DOME todos os\l"
	.string "dias.$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
	.string "Ouvi dizer que alguém viu um\n"
	.string "Pokémon com uma cauda muito\l"
	.string "comprida em algum lugar da BATTLE\l"
	.string "FRONTIER.\p"
	.string "Deve ser uma graça. Tenho\n"
	.string "certeza...\p"
	.string "Os desafios podem esperar. Preciso\n"
	.string "encontrar essa criaturinha!$"

