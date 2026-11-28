DewfordTown_Hall_MapScripts::
	.byte 0

DewfordTown_Hall_EventScript_Girl::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special IsTrendyPhraseBoring
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_GirlBoredOfTrend::
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Woman::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Man::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferDeepLinkPhrase
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
	end

DewfordTown_Hall_EventScript_ConfirmTrendLink::
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_RejectTrendLink::
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_ExpertM::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_Twin::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_TWIN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_LittleBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Bookshelf::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_Painting::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
	case 1, DewfordTown_Hall_EventScript_SmileTitle
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
	case 2, DewfordTown_Hall_EventScript_LastTitle
	case 6, DewfordTown_Hall_EventScript_LastTitle
	case 3, DewfordTown_Hall_EventScript_BirthTitle
	case 7, DewfordTown_Hall_EventScript_LastTitle
	end

DewfordTown_Hall_EventScript_ScreamTitle::
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SmileTitle::
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_LastTitle::
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_BirthTitle::
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SchoolKidM::
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_PsychicM::
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_DoTrendDebate::
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
	end

DewfordTown_Hall_EventScript_TrendDebate1::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate2::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate3::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate4::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate5::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_DontMovePlayer1::
	return

DewfordTown_Hall_EventScript_DebateReact1::
	applymovement LOCALID_DEWFORD_HALL_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
	end

DewfordTown_Hall_EventScript_PlayerReactWest::
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

DewfordTown_Hall_EventScript_DontMovePlayer2::
	return

DewfordTown_Hall_EventScript_DebateReact2::
	applymovement LOCALID_DEWFORD_HALL_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
	end

DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerReactEast::
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_SludgeBombMan::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
	release
	end

DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
	.string "Oque ta na moda?\n"
	.string "“{STR_VAR_1}“, claro!\p"
	.string "Nem consigo imaginar a vida sem\n"
	.string "“{STR_VAR_1}“!$"

DewfordTown_Hall_Text_GettingBoredOfTrend:
	.string "Oque ta na moda?\n"
	.string "“{STR_VAR_1}“, claro!\p"
	.string "Mas já tô enjoando um pouco.\p"
	.string "Preciso descobrir a próxima\n"
	.string "novidade.$"

DewfordTown_Hall_Text_TeachingMonAboutTrend:
	.string "Tô ensinando meu POKÉMON sobre\n"
	.string "“{STR_VAR_1}“, mas nao ta\l"
	.string "dando muito certo.\p"
	.string "Acho que é demais pra ele.$"

DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
	.string "Tô estudando essa moda de\n"
	.string "“{STR_VAR_1}“.\p"
	.string "É verdade que tem uma ligaçao\n"
	.string "forte entre “{STR_VAR_1}“ e\l"
	.string "“{STR_VAR_2}“?$"

DewfordTown_Hall_Text_MyHunchWasRight:
	.string "Ah! Entao eu estava certo!\p"
	.string "Mais um passo pra ficar por dentro\n"
	.string "de tudo!$"

DewfordTown_Hall_Text_NotEasyToKeepUp:
	.string "O quê?! É mesmo?!\p"
	.string "Nao é fácil pra um velho como eu\n"
	.string "acompanhar essas modas!$"

DewfordTown_Hall_Text_TVShowAboutTrend:
	.string "Essa história toda de\n"
	.string "“{STR_VAR_1}“... Nao tem um\l"
	.string "programa na televisao sobre isso?$"

DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
	.string "Do outro lado do mar...\p"
	.string "“{STR_VAR_1}“ é ainda mais\n"
	.string "famoso?$"

DewfordTown_Hall_Text_CollectTrendMerchandise:
	.string "Coleciono produtos oficiais de\n"
	.string "“{STR_VAR_1}“.\p"
	.string "Tenho bonecos oficiais de\n"
	.string "“{STR_VAR_1}“...\p"
	.string "Roupas da marca\n"
	.string "“{STR_VAR_1}“...\p"
	.string "E livros ilustrados oficiais de\n"
	.string "“{STR_VAR_1}“.\p"
	.string "Hehe, isso tudo é meu! Nao vou\n"
	.string "dividir com você!$"

DewfordTown_Hall_Text_BooksAboutTrend:
	.string "“Como distinguir um bom\n"
	.string "{STR_VAR_1} de um\l"
	.string "{STR_VAR_1} ruim”...\p"
	.string "“A ligaçao entre {STR_VAR_1} e\n"
	.string "os POKÉMONS”...\p"
	.string "“{STR_VAR_1} no dia a dia”...\p"
	.string "A estante ta cheia de livros sobre\n"
	.string "“{STR_VAR_1}“.$"

DewfordTown_Hall_Text_TrendsScream:
	.string "O título é “O grito de\n"
	.string "{STR_VAR_1}“.$"

DewfordTown_Hall_Text_TrendsSmile:
	.string "O título é “O sorriso de\n"
	.string "{STR_VAR_1}“.$"

DewfordTown_Hall_Text_LastTrend:
	.string "O título é “O último\n"
	.string "{STR_VAR_1}“.$"

DewfordTown_Hall_Text_BirthOfTrend:
	.string "O título é “O nascimento de\n"
	.string "{STR_VAR_1}“.$"

DewfordTown_Hall_Text_SawTrendCoolestThing:
	.string "Eu vi “{STR_VAR_1}“! Legal, né?\p"
	.string "É a melhor coisa do momento!\p"
	.string "Foi incrível! Eu vi de verdade!$"

DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
	.string "Ah, nao, nao.\p"
	.string "Esse “{STR_VAR_1}“ que você\n"
	.string "diz ter visto nao era o verdadeiro.\p"
	.string "O de verdade é muito mais... Como\n"
	.string "eu posso dizer? Marcante, mas\l"
	.string "suave!\p"
	.string "Ah, tanto faz. É incrível!$"

DewfordTown_Hall_Text_ComposedTrendThemeSong:
	.string "Ei, escuta! Compus uma música pra\n"
	.string "“{STR_VAR_1}“.\p"
	.string "“{STR_VAR_1}“ ta muito famoso\n"
	.string "agora.\p"
	.string "Ta bom, escuta! ... ...\p"
	.string "Ah, {STR_VAR_1}!\p"
	.string "Maravilhoso {STR_VAR_1}!$"

DewfordTown_Hall_Text_WorkOnYourSinging:
	.string "... ...\p"
	.string "Meu caro, seria melhor praticar o\n"
	.string "canto antes de tentar fazer uma\l"
	.string "música sobre “{STR_VAR_1}“.$"

DewfordTown_Hall_Text_OrganizeTrendParty:
	.string "Como eu estava dizendo, a gente\n"
	.string "devia se reunir e fazer uma festa\l"
	.string "de “{STR_VAR_1}“ na ilha.$"

DewfordTown_Hall_Text_BrilliantIndeed:
	.string "Que ótima ideia!\p"
	.string "Vamos decidir de uma vez quem é o\n"
	.string "melhor em “{STR_VAR_1}“.\l"
	.string "Genial!\p"
	.string "A partir de hoje, nossa vida vai\n"
	.string "girar em torno de\l"
	.string "“{STR_VAR_1}“!$"

DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
	.string "Mas eu estava pensando...\p"
	.string "Nao acha que “{STR_VAR_1}“\n"
	.string "deixou de ser só uma moda e virou\l"
	.string "parte da nossa vida?$"

DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
	.string "Como? Chegou a tanto assim?\p"
	.string "Mas é verdade que você nao para\n"
	.string "de pensar em “{STR_VAR_1}“,\l"
	.string "acordado ou dormindo.\p"
	.string "Você é mesmo o professor de\n"
	.string "“{STR_VAR_1}“, meu amigo!$"

DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
	.string "Se a gente formar uma equipe, vai\n"
	.string "ser imbatível em tudo sobre\l"
	.string "“{STR_VAR_1}“!$"

DewfordTown_Hall_Text_WellBeTrendDuo:
	.string "Isso mesmo, meu amigo!\p"
	.string "Vamos ser a dupla de\n"
	.string "“{STR_VAR_1}“!\p"
	.string "Gostou do nome? Hahahah!$"

DewfordTown_Hall_Text_GiveYouSludgeBomb:
	.string "Pra mim, SLUDGE BOMB é o auge da\n"
	.string "moda. É o melhor.\p"
	.string "Hein? Você nao conhece SLUDGE\n"
	.string "BOMB?\p"
	.string "Que situaçao triste. Vou te dar\n"
	.string "um.$"

DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
	.string "Adoro SLUDGE BOMB.\p"
	.string "Mas POKÉMONS com o golpe\n"
	.string "“{STR_VAR_1}“ também estao na\l"
	.string "moda.$"

