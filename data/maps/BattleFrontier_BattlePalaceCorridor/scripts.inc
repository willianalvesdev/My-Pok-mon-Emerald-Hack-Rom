BattleFrontier_BattlePalaceCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceCorridor_OnFrame
	.byte 0

BattleFrontier_BattlePalaceCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePalaceCorridor_EventScript_WalkThroughCorridor
	.2byte 0

BattleFrontier_BattlePalaceCorridor_EventScript_WalkThroughCorridor::
	delay 16
	applymovement LOCALID_PALACE_CORRIDOR_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_EnterCorridor
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_EnterCorridor
	waitmovement 0
	lockall
	palace_getcomment
	call_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment1
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment2
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment3
	call_if_eq VAR_RESULT, 3, BattleFrontier_BattlePalaceCorridor_EventScript_StreakComment
	call_if_eq VAR_RESULT, 4, BattleFrontier_BattlePalaceCorridor_EventScript_LongStreakComment
	closemessage
	frontier_get FRONTIER_DATA_LVL_MODE
	goto_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattlePalaceCorridor_EventScript_WalkToOpenBattleRoom
	applymovement LOCALID_PALACE_CORRIDOR_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkTo50BattleRoom
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkTo50BattleRoom
	waitmovement 0
	opendoor 6, 3
	waitdooranim
	applymovement LOCALID_PALACE_CORRIDOR_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantEnterBattleRoom
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerEnterBattleRoom
	waitmovement 0
	closedoor 6, 3
	waitdooranim
	goto BattleFrontier_BattlePalaceCorridor_EventScript_WarpToBattleRoom

BattleFrontier_BattlePalaceCorridor_EventScript_WalkToOpenBattleRoom::
	applymovement LOCALID_PALACE_CORRIDOR_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkToOpenBattleRoom
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkToOpenBattleRoom
	waitmovement 0
	opendoor 10, 3
	waitdooranim
	applymovement LOCALID_PALACE_CORRIDOR_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantEnterBattleRoom
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerEnterBattleRoom
	waitmovement 0
	closedoor 10, 3
	waitdooranim
BattleFrontier_BattlePalaceCorridor_EventScript_WarpToBattleRoom::
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM, 7, 4
	waitstate
	end

BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment1::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_PeopleAndMonAreSame, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment2::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_LetMonDoWhatItLikes, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment3::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_MonDifferentWhenCornered, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_EventScript_StreakComment::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_BeginningToUnderstandNature, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_EventScript_LongStreakComment::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_HeartfeltBondBetweenYouAndMons, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_Movement_EnterCorridor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkTo50BattleRoom:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkTo50BattleRoom:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkToOpenBattleRoom:
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkToOpenBattleRoom:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_PlayerEnterBattleRoom:
	walk_up
BattleFrontier_BattlePalaceCorridor_Movement_AttendantEnterBattleRoom:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceCorridor_Text_PeopleAndMonAreSame:
	.string "Pessoas e Pokémon sao parecidos...\p"
	.string "Cada um tem seu jeito, e isso faz\n"
	.string "com que tenham facilidade para\l"
	.string "algumas coisas e dificuldade para\l"
	.string "outras.$"

BattleFrontier_BattlePalaceCorridor_Text_LetMonDoWhatItLikes:
	.string "Em vez de obrigar um Pokémon a\n"
	.string "fazer algo de que nao gosta, deixe\l"
	.string "que ele faça o que gosta e sabe\l"
	.string "fazer.\p"
	.string "Tente pensar como ele e imagine\n"
	.string "quais golpes ele gostaria de usar.$"

BattleFrontier_BattlePalaceCorridor_Text_MonDifferentWhenCornered:
	.string "A natureza de um Pokémon é uma\n"
	.string "coisa curiosa...\p"
	.string "Alguns mudam totalmente de\n"
	.string "comportamento quando estao em\l"
	.string "apuros.$"

BattleFrontier_BattlePalaceCorridor_Text_BeginningToUnderstandNature:
	.string "Está começando a entender como a\n"
	.string "natureza de um Pokémon afeta o\l"
	.string "jeito dele?$"

BattleFrontier_BattlePalaceCorridor_Text_HeartfeltBondBetweenYouAndMons:
	.string "Ah... Vejo uma ligaçao forte e\n"
	.string "sincera entre você e seus\l"
	.string "Pokémon...$"

