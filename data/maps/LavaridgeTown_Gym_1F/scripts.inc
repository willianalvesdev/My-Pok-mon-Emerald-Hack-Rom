LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole::
	trainerbattle_lavaridge LOCALID_COLE, TRAINER_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle_lavaridge LOCALID_AXLE, TRAINER_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle_lavaridge LOCALID_KEEGAN, TRAINER_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle_lavaridge LOCALID_DANIELLE, TRAINER_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle_lavaridge LOCALID_GERALD, TRAINER_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle_lavaridge LOCALID_JACE, TRAINER_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle_lavaridge LOCALID_JEFF, TRAINER_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle_lavaridge LOCALID_ELI, TRAINER_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
	.string "Ei, tudo certo, futuro campeao\n"
	.string "{PLAYER}?\p"
	.string "FLANNERY, a líder de LAVARIDGE,\n"
	.string "usa POKÉMONS do tipo Fogo.\p"
	.string "A paixao dela pelos POKÉMONS\n"
	.string "queima mais que um vulcao.\p"
	.string "Cuidado pra nao se queimar! Use\n"
	.string "Água pra esfriar essa batalha e vá\l"
	.string "com tudo!$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
	.string "Uau! Essa batalha foi quente\n"
	.string "demais!$"

LavaridgeTown_Gym_1F_Text_ColeIntro:
	.string "Ai, ai, ai! Ta quente!$"

LavaridgeTown_Gym_1F_Text_ColeDefeat:
	.string "O suor caiu nos meus olhos. Nao tô\n"
	.string "enxergando...$"

LavaridgeTown_Gym_1F_Text_ColePostBattle:
	.string "Ficar enterrado na areia quente\n"
	.string "ajuda a circulaçao.\p"
	.string "Também alivia dores nas juntas.$"

LavaridgeTown_Gym_1F_Text_AxleIntro:
	.string "Tô tentando relaxar. Nao venha me\n"
	.string "estressar!$"

LavaridgeTown_Gym_1F_Text_AxleDefeat:
	.string "Espero que FLANNERY te dê uma boa\n"
	.string "queimada!$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
	.string "Ah... Ufa...\p"
	.string "Ficar tempo demais nessa areia\n"
	.string "quente acaba com a energia...$"

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
	.string "Você já deve estar cansado. Quer\n"
	.string "descansar na areia quente, né?\p"
	.string "Mas todo treinador precisa\n"
	.string "aprender a manter a força de\l"
	.string "vontade.$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
	.string "Quem brinca com fogo acaba se\n"
	.string "queimando...$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
	.string "Você tem talento, mas nossa líder\n"
	.string "FLANNERY é forte.\p"
	.string "Se nao tomar cuidado, vai se\n"
	.string "queimar feio.$"

LavaridgeTown_Gym_1F_Text_GeraldIntro:
	.string "Seus POKÉMONS aguentam 392 graus\n"
	.string "de calor?$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
	.string "O fogo nao estava quente o\n"
	.string "bastante...$"

LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
	.string "A temperatura do magma é de 392\n"
	.string "graus.\p"
	.string "Se seus POKÉMONS me venceram,\n"
	.string "devem sobreviver no magma sem\l"
	.string "dificuldade.$"

LavaridgeTown_Gym_1F_Text_DanielleIntro:
	.string "É... Ta bom, vou batalhar com\n"
	.string "você.$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
	.string "Ah, mas você é forte demais.$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
	.string "Vou ser uma treinadora bonita e\n"
	.string "forte, igual à FLANNERY.$"

LavaridgeTown_Gym_B1F_Text_JaceIntro:
	.string "Vamos logo! Antes que minha\n"
	.string "empolgaçao esfrie!$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
	.string "Ta tao quente, mas meu coraçao\n"
	.string "parece de gelo...$"

LavaridgeTown_Gym_B1F_Text_JacePostBattle:
	.string "Com essa vontade de lutar, talvez\n"
	.string "você tenha uma chance contra\l"
	.string "nossa líder.$"

LavaridgeTown_Gym_B1F_Text_JeffIntro:
	.string "Viu como as chamas estao fortes?\n"
	.string "É porque já sabem que vou ganhar!$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
	.string "Alguma coisa deu errado.$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
	.string "E daí? E daí?! Eu consigo andar\n"
	.string "descalço em brasas!\p"
	.string "...Nem pense em tentar fazer isso!$"

LavaridgeTown_Gym_B1F_Text_EliIntro:
	.string "Adoro montanhas, principalmente\n"
	.string "vulcoes.$"

LavaridgeTown_Gym_B1F_Text_EliDefeat:
	.string "Parece que eu perdi sem conseguir\n"
	.string "tomar o controle da luta.$"

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
	.string "Fiquei aqui porque virei fa da\n"
	.string "força de FLANNERY.\p"
	.string "Hehehehe.$"

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
	.string "Bem-vindo... Nao, espera.\p"
	.string "Treinador insignificante, que bom\n"
	.string "que chegou até aqui!\p"
	.string "Confiaram a mim o... Nao, espera.\p"
	.string "Sou FLANNERY, a líder deste\n"
	.string "ginásio!\p"
	.string "É... Nao me subestime só porque\n"
	.string "comecei há pouco tempo!\p"
	.string "Com as técnicas que aprendi com\n"
	.string "meu avô, vou... É... Mostrar os\l"
	.string "golpes quentes que treinamos nesta\l"
	.string "terra!$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
	.string "Ah... Acho que exagerei...\p"
	.string "Faz pouco tempo que virei líder.\p"
	.string "Tentei demais ser alguém que nao\n"
	.string "sou.\p"
	.string "Preciso fazer as coisas do meu\n"
	.string "jeito. Senao, meus POKÉMONS ficam\l"
	.string "confusos.\p"
	.string "Obrigada por me ensinar isso. Você\n"
	.string "merece isto.$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "{PLAYER} recebeu a HEAT BADGE de\n"
	.string "FLANNERY.$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.string "Com a HEAT BADGE, todos os\n"
	.string "POKÉMONS até o nível 50 obedecem\l"
	.string "você, até os recebidos por troca.\p"
	.string "Você também poderá usar STRENGTH\n"
	.string "fora das batalhas.\p"
	.string "Isto é pra agradecer. Pode pegar!$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.string "A TM50 ensina OVERHEAT.\p"
	.string "Esse golpe causa muito dano.\p"
	.string "Mas também reduz bastante o\n"
	.string "Ataque Especial de quem usa. Pode\l"
	.string "nao ser a melhor escolha pra\l"
	.string "batalhas longas.$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "A líder FLANNERY foi registrada no\n"
	.string "POKéNAV.$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.string "Sua força me lembra alguém...\p"
	.string "Ah, já sei! Você batalha como\n"
	.string "NORMAN, o líder de PETALBURG.$"

LavaridgeTown_Gym_1F_Text_GymStatue:
	.string "Ginásio Pokémon de LAVARIDGE TOWN$"

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
	.string "Ginásio Pokémon de LAVARIDGE TOWN\p"
	.string "Treinadores reconhecidos por\n"
	.string "FLANNERY: {PLAYER}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "FLANNERY: Nao vou desanimar por\n"
	.string "perder uma batalha.\p"
	.string "Eu amo os POKÉMONS. Amo batalhar.\n"
	.string "E... Amo este ginásio!\p"
	.string "Vamos esquentar tudo com outra\n"
	.string "batalha!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.string "Ufa! Quase entrando em erupçao!$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "FLANNERY: Perdi, mas tô muito\n"
	.string "satisfeita.\p"
	.string "Nao é sempre que consigo\n"
	.string "aproveitar uma batalha tao quente.\p"
	.string "Vamos fazer outra dessas um dia!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.string "FLANNERY: Nao vou desanimar por\n"
	.string "perder uma batalha.\p"
	.string "Eu amo os POKÉMONS. Amo batalhar.\n"
	.string "E... Amo este ginásio!\p"
	.string "Vamos esquentar tudo com outra\n"
	.string "batalha!\p"
	.string "Ah, espera. Você só tem um\n"
	.string "POKÉMON em condiçoes de lutar?\p"
	.string "Volte com pelo menos dois quando\n"
	.string "vier me desafiar.$"
