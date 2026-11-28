Route114_FossilManiacsTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsTunnel_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_FossilManiacsTunnel_OnLoad
	.byte 0

Route114_FossilManiacsTunnel_OnTransition:
	call_if_set FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac
	end

Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac::
	setobjectxyperm LOCALID_FOSSIL_MANIAC, 6, 5
	setobjectmovementtype LOCALID_FOSSIL_MANIAC, MOVEMENT_TYPE_FACE_DOWN
	return

Route114_FossilManiacsTunnel_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass
	end

Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass::
	setmetatile 6, 1, METATILE_Fallarbor_RedRockWall, TRUE
	setmetatile 6, 2, METATILE_Fallarbor_RedRockWall, TRUE
	return

Route114_FossilManiacsTunnel_EventScript_ManiacMentionCaveIn::
	lockall
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route114_FossilManiacsTunnel_Text_NotSafeThatWay, MSGBOX_DEFAULT
	setvar VAR_FOSSIL_MANIAC_STATE, 2
	releaseall
	end

Route114_FossilManiacsTunnel_EventScript_FossilManiac::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REVIVED_FOSSIL_MON, Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	msgbox Route114_FossilManiacsTunnel_Text_LookInDesertForFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil::
	msgbox Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil::
	msgbox Route114_FossilManiacsTunnel_Text_FossilsAreWonderful, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_Text_LookInDesertForFossils:
	.string "Sou o Fossil Maniac... Sou um cara\n"
	.string "legal e adoro fósseis...\p"
	.string "Quer um? Os daqui sao todos meus.\n"
	.string "Nenhum pra você...\p"
	.string "Se quiser muito um fóssil, procure\n"
	.string "no deserto. Pode ter algum\l"
	.string "escondido entre pedras e areia...$"

Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils:
	.string "Você encontrou um fóssil, né? Que\n"
	.string "bom... Que maravilha...\p"
	.string "Oque vai fazer com ele?\p"
	.string "Ouvi dizer que a Devon pesquisa\n"
	.string "como reviver Pokémon de fósseis...\p"
	.string "Gosto tanto dos meus fósseis que\n"
	.string "nunca faria isso...$"

Route114_FossilManiacsTunnel_Text_FossilsAreWonderful:
	.string "Fósseis sao tao... Maravilhosos...$"

Route114_FossilManiacsTunnel_Text_NotSafeThatWay:
	.string "Ah... Nao é seguro ir por ali...\p"
	.string "Eu tava cavando quando a parede\n"
	.string "inteira caiu.\p"
	.string "Acho que abriu uma caverna enorme\n"
	.string "lá embaixo...\p"
	.string "Mas deixei pra lá, porque nao\n"
	.string "parece ter fósseis.$"

