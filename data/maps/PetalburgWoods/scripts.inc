PetalburgWoods_MapScripts::
	.byte 0

PetalburgWoods_EventScript_DevonResearcherLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro::
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_PETALBURG_WOODS_GRUNT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull::
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish::
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound:
	.string "Hum... Nao encontro nenhum...$"

PetalburgWoods_Text_HaveYouSeenShroomish:
	.string "Oi, viu algum Shroomish por aqui?\p"
	.string "Eu gosto muito desse Pokémon.$"

PetalburgWoods_Text_IWasGoingToAmbushYou:
	.string "Ia te pegar de surpresa, mas você\n"
	.string "ficou uma eternidade andando por\l"
	.string "Petalburg Woods!\p"
	.string "Cansei de esperar e vim logo!$"

PetalburgWoods_Text_HandOverThosePapers:
	.string "Você! Pesquisador da Devon!\p"
	.string "Passa esses documentos!$"

PetalburgWoods_Text_YouHaveToHelpMe:
	.string "Aiiiih!\p"
	.string "Você é um treinador Pokémon, né?\n"
	.string "Me ajuda, por favor!$"

PetalburgWoods_Text_NoOneCrossesTeamAqua:
	.string "Hein? Oque pensa que ta fazendo?\n"
	.string "Vai proteger ele?\p"
	.string "A Team Aqua nao tem pena de quem\n"
	.string "atrapalha, nem de criança!\p"
	.string "Vamos batalhar!$"

PetalburgWoods_Text_YoureKiddingMe:
	.string "Ta brincando! Você é forte!$"

PetalburgWoods_Text_YouveGotSomeNerve:
	.string "Grrr... Que coragem se meter com a\n"
	.string "Team Aqua! Vamos batalhar de\l"
	.string "novo!\p"
	.string "Era oque eu queria dizer, mas meus\n"
	.string "Pokémon já pediram demissao...\p"
	.string "Também temos coisa pra resolver em\n"
	.string "Rustboro. Hoje vou deixar você ir!$"

PetalburgWoods_Text_ThatWasAwfullyClose:
	.string "Ufa... Foi por pouco!\p"
	.string "Graças a você, ele nao levou estes\n"
	.string "documentos importantes.\p"
	.string "Já sei! Vou te dar uma Great Ball\n"
	.string "pra agradecer!$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
	.string "Aquele bandido da Team Aqua nao\n"
	.string "disse que também queria alguma\l"
	.string "coisa em Rustboro?$"

PetalburgWoods_Text_ICantBeWastingTime:
	.string "Eita! A situaçao é séria! Nao\n"
	.string "posso perder tempo!$"

PetalburgWoods_Text_YoureLoadedWithItems:
	.string "Você ta cheio de itens. Nao\n"
	.string "consigo dar esta Great Ball.$"

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "Capturei um monte de Pokémon!\p"
	.string "Vamos, vamos, equipe de Pokémon\n"
	.string "Bug!$"

PetalburgWoods_Text_ICouldntWin:
	.string "Com tanto Pokémon assim, ainda nao\n"
	.string "consegui ganhar...$"

PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "Capturei tantos Pokémon que\n"
	.string "acabaram minhas Poké Balls.$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
	.string "Se levar Pokémon Bug pra escola,\n"
	.string "você fica popular na hora!$"

PetalburgWoods_Text_CantBePopularIfILose:
	.string "Nao dá pra ser popular perdendo...$"

PetalburgWoods_Text_PeopleRespectYou:
	.string "Com um Pokémon Bug bem grande,\n"
	.string "todo mundo te respeita.\p"
	.string "Principalmente quem tem medo de\n"
	.string "inseto.$"

PetalburgWoods_Text_IWantRematch1:
	.string "Quero uma revanche quando meus\n"
	.string "Pokémon Bug crescerem!\p"
	.string "Vou registrar você no meu PokéNav!$"

PetalburgWoods_Text_IWantRematch2:
	.string "Quero uma revanche quando meus\n"
	.string "Pokémon Bug crescerem!\p"
	.string "Vou registrar você no meu PokéNav!$"

PetalburgWoods_Text_MyPokemonHaveGrown:
	.string "Meus Pokémon Bug cresceram. Vou\n"
	.string "ficar popular de novo!$"

PetalburgWoods_Text_CantBePopularIfLose:
	.string "Nao dá pra ser popular perdendo...$"

PetalburgWoods_Text_IveBeenTrainingHard:
	.string "Com Pokémon fortes, a gente fica\n"
	.string "popular, né? Por isso tô treinando\l"
	.string "muito.$"

PetalburgWoods_Text_StayOutOfTallGrass:
	.string "Ei! Seus Pokémon tao bem?\p"
	.string "Se estiverem fracos e você quiser\n"
	.string "evitar batalhas, fique fora do\l"
	.string "mato alto.$"

PetalburgWoods_Text_HiddenItemsExplanation:
	.string "Às vezes tem coisas no chao que\n"
	.string "você nao consegue ver.\p"
	.string "Por isso sempre olho por onde\n"
	.string "ando.$"

PetalburgWoods_Text_TryUsingThisItem:
	.string "Que legal! É a insígnia do ginásio\n"
	.string "de Rustboro!\p"
	.string "Você deve ser um treinador.\n"
	.string "Experimenta usar este item.$"

PetalburgWoods_Text_MiracleSeedExplanation:
	.string "É uma Miracle Seed. Quando um\n"
	.string "Pokémon segura ela, seus golpes do\l"
	.string "tipo Grass ficam mais fortes.\p"
	.string "Acho que existem outros itens\n"
	.string "úteis pros Pokémon segurarem\l"
	.string "também.$"

PetalburgWoods_Text_TrainerTipsExperience:
	.string "DICAS DE TREINADOR\p"
	.string "Todo Pokémon que entra numa\n"
	.string "batalha recebe pontos de\l"
	.string "experiência.\p"
	.string "Pra treinar um Pokémon fraco,\n"
	.string "coloque ele em primeiro na equipe e\l"
	.string "troque assim que a batalha\l"
	.string "começar.\p"
	.string "Ele ganha experiência sem correr\n"
	.string "tanto risco.$"

PetalburgWoods_Text_TrainerTipsPP:
	.string "DICAS DE TREINADOR\p"
	.string "Além do HP, os Pokémon têm PP,\n"
	.string "usados pra executar golpes nas\l"
	.string "batalhas.\p"
	.string "Se os PP acabarem, leve o Pokémon\n"
	.string "a um Centro Pokémon.$"

