MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	.byte 0

MossdeepCity_OnTransition:
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	end

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
	lockall
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
	waitmovement 0
	removeobject LOCALID_MOSSDEEP_MAXIE
	removeobject LOCALID_MOSSDEEP_GRUNT_1
	removeobject LOCALID_MOSSDEEP_GRUNT_2
	removeobject LOCALID_MOSSDEEP_GRUNT_3
	removeobject LOCALID_MOSSDEEP_GRUNT_4
	delay 30
	setvar VAR_MOSSDEEP_CITY_STATE, 2
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	releaseall
	end

MossdeepCity_Movement_MaxieGestureToSpaceCenter:
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_GruntFaceSpaceCenter:
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_MaxieEnterSpaceCenter:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt1EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt2EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt3EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt4EnterSpaceCenter:
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_MOSSDEEP_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Text_WantKingsRockStevenGaveMe:
	.string "Ganhei isto do Steven, mas nao sei\n"
	.string "pra que serve.\p"
	.string "Acho que se chama King's Rock.\n"
	.string "Você quer?$"

MossdeepCity_Text_YouCanKeepIt:
	.string "Pra que você quer isso? Você é\n"
	.string "estranho.\p"
	.string "Pode ficar, mas nao conta pro\n"
	.string "Steven.$"

MossdeepCity_Text_StevensHouseOverThere:
	.string "A casa do Steven fica bem ali!$"

MossdeepCity_Text_WhatToDoWithWeirdRock:
	.string "Você também acha, né? Oque se faz\n"
	.string "com uma pedra esquisita dessas?$"

MossdeepCity_Text_WailmerWatching:
	.string "Dá pra ver Wailmer selvagens perto\n"
	.string "de Mossdeep.\p"
	.string "Como era o nome disso mesmo?\p"
	.string "Wai, wai, wai...\p"
	.string "Observaçao de Wailmer!$"

MossdeepCity_Text_SpaceCenterReceivedLetter:
	.string "O centro espacial da ilha lança\n"
	.string "foguetes enormes.\p"
	.string "Receberam uma carta esses dias e\n"
	.string "agora ta todo mundo agitado.$"

MossdeepCity_Text_SpaceCenterLaunchingRockets:
	.string "O centro espacial da ilha lança\n"
	.string "foguetes enormes.$"

MossdeepCity_Text_MossdeepTargetedByMagma:
	.string "Um amigo marinheiro contou que a\n"
	.string "Team Aqua montou uma base em\l"
	.string "Lilycove.\p"
	.string "Também disse que alguém apareceu e\n"
	.string "acabou com eles!\p"
	.string "Mas agora a Team Magma ta de olho\n"
	.string "em Mossdeep.\p"
	.string "Se quiser saber oque estao\n"
	.string "fazendo, vá ao centro espacial.$"

MossdeepCity_Text_FeelReliefOnLand:
	.string "Sou marinheiro, entao o mar é muito\n"
	.string "importante pra mim.\p"
	.string "Mas sabe? Voltar pra terra depois\n"
	.string "de uma viagem longa dá um alívio!$"

MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
	.string "Nao seria bom se o mundo todo\n"
	.string "fosse coberto de plantas e flores,\l"
	.string "igual a esta ilha?$"

MossdeepCity_Text_LifeNeedsSeaToLive:
	.string "Toda vida precisa do mar, mesmo\n"
	.string "quando vive em terra.\p"
	.string "Quando a vida termina, volta pra\n"
	.string "terra e vira parte do solo.\p"
	.string "E o mar sempre encontra a terra.\p"
	.string "Igual aqui, nesta praia.$"

MossdeepCity_Text_SurfExhilarating:
	.string "Viajar de barco é bom.\p"
	.string "Mas atravessar o mar com um\n"
	.string "Pokémon usando Surf...\p"
	.string "Isso sim é uma aventura! Nao\n"
	.string "acha?$"

MossdeepCity_Text_SpecialSpaceCenterRock:
	.string "Essa pedra tem um significado\n"
	.string "especial pro pessoal do centro\l"
	.string "espacial.\p"
	.string "Colocaram ela aqui pra desejar\n"
	.string "viagens seguras pros foguetes.\p"
	.string "Quando faz um pedido, você olha\n"
	.string "pras estrelas?\p"
	.string "Eu escrevo meu desejo numa\n"
	.string "fitinha.$"

MossdeepCity_Text_ItsAWhiteRock:
	.string "É uma pedra branca.$"

MossdeepCity_Text_GymSign:
	.string "Ginásio Pokémon de Mossdeep City\p"
	.string "Líderes: Liza e Tate\p"
	.string "“A dupla misteriosa!”$"

MossdeepCity_Text_CitySign:
	.string "Mossdeep City\p"
	.string "“Nosso lema: valorize os Pokémon!”$"

MossdeepCity_Text_SpaceCenterSign:
	.string "Mossdeep Space Center\p"
	.string "“O lugar mais perto do espaço.”$"

MossdeepCity_Text_ScottSomethingWrongWithTown:
	.string "SCOTT: Tudo bem, {PLAYER}{KUN}? Comigo\n"
	.string "ta ótimo!\p"
	.string "Ouvi dizer que os líderes de\n"
	.string "Mossdeep sao fortes e vim\l"
	.string "conferir.\p"
	.string "Mas a cidade ta estranha. Só falam\n"
	.string "de uma carta de ameaça e do\l"
	.string "centro espacial...\p"
	.string "Acho que isso nao tem nada a ver\n"
	.string "comigo.$"

MossdeepCity_Text_SootopolisNewGymLeader:
	.string "Ah... É bom sentir as ondas nos\n"
	.string "pés...\p"
	.string "Falando em mar, conhece\n"
	.string "Sootopolis?\p"
	.string "Acho que chegou um líder novo no\n"
	.string "ginásio de lá.\p"
	.string "Dizem que ele ensinou Wallace a\n"
	.string "batalhar.$"

