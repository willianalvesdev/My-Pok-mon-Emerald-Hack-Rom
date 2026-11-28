@ All the LOCALID constants used in this file are essentially redundant.
@ They're all used to have the NPC the player talked to turn back so they're facing
@ their original direction (because they're watching/participating in the contests).
@ They could all be substituted for VAR_LAST_TALKED.
LilycoveCity_ContestHall_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1::
	lockall
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest:
	.string "Meu Pokémon já ganhou o concurso\n"
	.string "de beleza daqui.\p"
	.string "E hoje ganhou o de inteligência\n"
	.string "também!\p"
	.string "Daqui a pouco ele faz minha\n"
	.string "declaraçao de imposto.$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests:
	.string "Já participei de vários concursos e\n"
	.string "tô entendendo como funciona.\p"
	.string "Num concurso de estilo, os golpes\n"
	.string "estilosos rendem boas\l"
	.string "apresentaçoes.\p"
	.string "Mas golpes de inteligência ou\n"
	.string "fofura nao funcionam tao bem, por\l"
	.string "exemplo.$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks:
	.string "Aquele rapaz que ganhou tinha um\n"
	.string "monte de {POKEBLOCK}S diferentes.\p"
	.string "Será que ter tantos assim ajuda a\n"
	.string "vencer?$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous:
	.string "Nossa, esse lugar é enorme!\p"
	.string "Até o clima aqui é diferente. Nao\n"
	.string "parece um salao de concurso do\l"
	.string "interior.$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal:
	.string "APRESENTADOR: Pokémon inteligentes\n"
	.string "e seus treinadores, tudo pronto?!\p"
	.string "Mostrem o melhor de vocês! Podem\n"
	.string "começar!$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest:
	.string "JUIZ: Ta gostando do concurso?\p"
	.string "Volte com três amigos. Vocês podem\n"
	.string "participar juntos!$"

LilycoveCity_ContestHall_Text_EnteredWrongContest:
	.string "Ai, ai, ai... Entrei no concurso\n"
	.string "errado.\p"
	.string "Meu Pokémon é durao, mas inscrevi\n"
	.string "ele no concurso de inteligência...\p"
	.string "Vai lá! Usa Rock Smash com cara de\n"
	.string "quem sabe matemática!$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart:
	.string "Passei anos usando tudo oque sei\n"
	.string "pra criar este Pokémon inteligente.\p"
	.string "Ele nao vai perder tao fácil pro\n"
	.string "Pokémon de um novato.\p"
	.string "Minha querida, você ta vendo isso?$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext:
	.string "É agora!\p"
	.string "Se meu Pokémon usar um golpe de\n"
	.string "inteligência na próxima\l"
	.string "apresentaçao, o público vai à\l"
	.string "loucura!$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife:
	.string "Ah, nao!\p"
	.string "O Leech Life do meu Zubat é tao\n"
	.string "fofo que eu usei várias vezes!\p"
	.string "Mas esse povo nao gostou nada!$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa:
	.string "Kiaaaah! Você ta lindo, vovô!$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves:
	.string "Mesmo quando usam a mesma espécie\n"
	.string "de Pokémon, os treinadores\l"
	.string "escolhem golpes diferentes nas\l"
	.string "apresentaçoes.\p"
	.string "Cada um tem seu estilo, igual nas\n"
	.string "batalhas.$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers:
	.string "Esses Pokémon parecem bem mais\n"
	.string "inteligentes que os treinadores\l"
	.string "deles.\p"
	.string "E olha que uns ainda tao comendo\n"
	.string "o próprio troféu.$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests:
	.string "No fim das contas, ainda prefiro\n"
	.string "os concursos de inteligência.\p"
	.string "Aquele verde... É tao... Tao...\n"
	.string "legal.$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest:
	.string "APRESENTADOR: Vai participar do\n"
	.string "concurso de beleza também? Boa\l"
	.string "sorte!$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty:
	.string "JUIZ: Ah, que Pokémon lindos!\p"
	.string "Fiquei tao distraído olhando que\n"
	.string "quase esqueci de dar as notas!$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty:
	.string "Nao existe outro Pokémon tao lindo\n"
	.string "quanto o meu.\p"
	.string "Todo mundo vai ficar olhando só\n"
	.string "pra ele.$"

LilycoveCity_ContestHall_Text_OverdidGrooming:
	.string "Uaaaah!\p"
	.string "Escovei e arrumei meu Pokémon com\n"
	.string "todo cuidado pro concurso...\p"
	.string "Mas exagerei e agora o pelo ta\n"
	.string "todo bagunçado!\p"
	.string "Oque eu faço?$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam:
	.string "Esse Aurora Beam brilha tanto que\n"
	.string "o juiz nem vai conseguir enxergar!\p"
	.string "Espera... Assim ele também nao vai\n"
	.string "ver a apresentaçao!$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe:
	.string "Esse Pokémon lindo parece comigo\n"
	.string "quando eu era jovem.\p"
	.string "Quando falei isso, meu marido\n"
	.string "cuspiu o café.\p"
	.string "Eu disse alguma coisa engraçada?$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy:
	.string "Ganhar um concurso de beleza me\n"
	.string "deixa feliz.\p"
	.string "Mais feliz que o normal, pelo\n"
	.string "menos.$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon:
	.string "Wahahahah!\p"
	.string "Olha só esses Pokémon lindos! Eu\n"
	.string "adoro esse brilho todo!$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone:
	.string "Só beleza nem sempre garante a\n"
	.string "vitória.\p"
	.string "Você precisa cuidar do seu Pokémon\n"
	.string "e deixar ele bem brilhante, igual o\l"
	.string "meu.$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest:
	.string "APRESENTADOR: Opa! Estamos no\n"
	.string "meio de um concurso!\p"
	.string "Faça sua inscriçao no balcao e\n"
	.string "depois venha participar, tudo bem?$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals:
	.string "JUIZ: Que apresentaçoes mais\n"
	.string "fofas!\p"
	.string "Meu Deus! Que Water Sport\n"
	.string "adorável!$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted:
	.string "Ah, nao... Meu querido Azurill se\n"
	.string "distraiu olhando outro Pokémon.$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest:
	.string "Meu Pokémon nunca ganhou uma\n"
	.string "batalha.\p"
	.string "Mas coloca ele num concurso pra\n"
	.string "você ver!$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel:
	.string "O Petal Dance do meu Pokémon é\n"
	.string "lindo.\p"
	.string "Nao vou deixar ninguém atrapalhar\n"
	.string "a apresentaçao dele.$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter:
	.string "Os Pokémon de todo mundo sao\n"
	.string "muito fofos.\p"
	.string "Mas quando o meu fizer uma\n"
	.string "apresentaçao de fofura...\p"
	.string "Tenho certeza que vai ser o mais\n"
	.string "fofo de todos.$"

LilycoveCity_ContestHall_Text_MyChildIsInContest:
	.string "Meu filho ta participando desse\n"
	.string "concurso.$"

LilycoveCity_ContestHall_Text_ComeOnDear:
	.string "Vai, meu bem! Você consegue! Seu\n"
	.string "Pokémon é o melhor!$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest:
	.string "Acho que aquela menina é a mais\n"
	.string "bonita daqui.\p"
	.string "Como assim? O concurso é pros\n"
	.string "Pokémon?$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn:
	.string "Ver tantos Pokémon fofos me deu\n"
	.string "vontade de ter um também!\p"
	.string "Vou sair pra capturar alguns!$"

LilycoveCity_ContestHall_Text_BeautyContestStage:
	.string "Palco do concurso de beleza\p"
	.string "Venha se encantar com Pokémon\n"
	.string "lindos!$"

LilycoveCity_ContestHall_Text_CuteContestStage:
	.string "Palco do concurso de fofura\p"
	.string "Venha conhecer Pokémon adoráveis!$"

LilycoveCity_ContestHall_Text_SmartContestStage:
	.string "Palco do concurso de inteligência\p"
	.string "Venha se impressionar com Pokémon\n"
	.string "inteligentes!$"

