LilycoveCity_LilycoveMuseum_1F_MapScripts::
	.byte 0

LilycoveCity_LilycoveMuseum_1F_EventScript_Greeter::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Curator::
	lockall
	applymovement LOCALID_MUSEUM_1F_CURATOR, Common_Movement_FacePlayer
	message LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings
	waitmessage
	multichoice 20, 8, MULTI_VIEWED_PAINTINGS, TRUE
	goto_if_eq VAR_RESULT, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings
	goto_if_eq VAR_RESULT, 1, LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested
	goto_if_eq VAR_RESULT, YES, LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat, MSGBOX_SIGN
	releaseall
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe, MSGBOX_SIGN
	applymovement LOCALID_MUSEUM_1F_CURATOR, LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs
	waitmovement 0
	removeobject LOCALID_MUSEUM_1F_CURATOR
	switch VAR_FACING
	case DIR_NORTH, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth
	case DIR_WEST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest
	case DIR_EAST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth::
	lockall
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest::
	lockall
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast::
	lockall
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs:
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest:
	walk_left
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast:
	walk_right
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth:
	walk_up
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_EventScript_OldPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FantasyPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_WomanPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_LegendaryPokemonPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_GrassPokemonPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_BerryPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_EventScript_BirdSculpture::
	msgbox LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PokeBallSculpture::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_StoneTablet::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SchoolKidM::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist1::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NinjaBoy::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman1::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman2::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PsychicM::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist2::
	lock
	faceplayer
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MUSEUM_1F_ARTIST_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FatMan::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum:
	.string "Bem-vindo ao Lilycove Museum.\p"
	.string "Fique à vontade pra conhecer nossa\n"
	.string "coleçao de obras sobre Pokémon.$"

LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings:
	.string "Sou o responsável pelo museu.\p"
	.string "Fico feliz em ver alguém tao jovem\n"
	.string "por aqui.\p"
	.string "Já deu uma olhada nas pinturas?$"

LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime:
	.string "Ah, entao nao vou atrapalhar. Pode\n"
	.string "olhar com calma.$"

LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings:
	.string "Ah, parece que você é um treinador\n"
	.string "Pokémon.\p"
	.string "Gosta de pinturas também?$"

LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat:
	.string "Entendo...\p"
	.string "Mesmo assim, agradeço sua visita.$"

LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe:
	.string "Ah, que ótimo! Você gosta de\n"
	.string "pinturas!\p"
	.string "Pode vir comigo um instante?$"

LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting:
	.string "É uma pintura muito antiga. A tinta\n"
	.string "está descascando em alguns\l"
	.string "lugares.$"

LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery:
	.string "É uma paisagem estranha, com um\n"
	.string "cenário fantástico.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman:
	.string "É a pintura de uma mulher sorrindo,\n"
	.string "com um Pokémon no colo.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon:
	.string "É a pintura de um Pokémon lendário\n"
	.string "de muito tempo atrás.\p"
	.string "O artista imaginou como ele seria.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon:
	.string "É uma pintura de Pokémon do tipo\n"
	.string "Grass balançando com a brisa.\p"
	.string "Eles parecem gostar do vento leve.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries:
	.string "É uma pintura de Berries que\n"
	.string "parecem deliciosas.\p"
	.string "Dá até fome!$"

LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica:
	.string "É uma cópia de uma escultura\n"
	.string "famosa.\p"
	.string "Ela mostra um antigo Pokémon\n"
	.string "pássaro.$"

LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone:
	.string "É uma Poké Ball enorme, feita de\n"
	.string "pedra preta.\p"
	.string "Parece que era usada em festas de\n"
	.string "muito tempo atrás.$"

LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText:
	.string "É uma placa enorme de pedra. Tem\n"
	.string "desenhos de Pokémon e muitos\l"
	.string "símbolos pequenos de uma língua\l"
	.string "antiga que você nao consegue ler.$"

LilycoveCity_LilycoveMuseum_1F_Text_WorksOfMagnificence:
	.string "Hum... Que obras maravilhosas...$"

LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts:
	.string "Batalhar com Pokémon é divertido,\n"
	.string "eu sei.\p"
	.string "Mas também precisamos dar valor à\n"
	.string "arte.$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration:
	.string "Este museu tem pinturas incríveis.\p"
	.string "E o responsável por ele é uma\n"
	.string "ótima pessoa.\p"
	.string "Pra artistas como eu, este lugar é\n"
	.string "uma inspiraçao.$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty:
	.string "Essa moça é bonita! Parece a\n"
	.string "mamae!$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable:
	.string "Esse Pokémon é uma graça! Igual\n"
	.string "ao nosso filho!$"

LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings:
	.string "Ouvi dizer que chegaram pinturas\n"
	.string "novas e vim correndo.\p"
	.string "Elas estao no segundo andar?$"

LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful:
	.string "O responsável pelo museu anda tao\n"
	.string "alegre!\p"
	.string "Aposto que aconteceu alguma coisa\n"
	.string "boa.$"

LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings:
	.string "Quero aprender olhando as grandes\n"
	.string "pinturas daqui.\p"
	.string "Meu sonho é ter uma obra minha em\n"
	.string "exposiçao neste museu.$"

LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination:
	.string "O museu virou um dos lugares\n"
	.string "favoritos dos turistas.\p"
	.string "Isso é ótimo pra Lilycove e pra\n"
	.string "Hoenn toda!\p"
	.string "Ouvi dizer que um único treinador\n"
	.string "conseguiu todas as pinturas lá de\l"
	.string "cima.$"

