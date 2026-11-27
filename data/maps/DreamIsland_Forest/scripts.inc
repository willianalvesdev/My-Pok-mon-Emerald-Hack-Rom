DreamIsland_Forest_MapScripts::
	.byte 0


DreamIsland_Forest_EventScript_Darkrai::
	lockall
	faceplayer
	waitse
	playmoncry SPECIES_DARKRAI, CRY_MODE_ENCOUNTER
	delay 30
	waitmoncry
	seteventmon SPECIES_DARKRAI, 50
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DreamIsland_Forest_WakeUp
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DreamIsland_Forest_WakeUp
	setflag FLAG_FINISHED_DREAM_DARKRAI
	call_if_eq VAR_RESULT, B_OUTCOME_LOST, DreamIsland_Forest_RestoreParty
	call_if_eq VAR_RESULT, B_OUTCOME_DREW, DreamIsland_Forest_RestoreParty

DreamIsland_Forest_WakeUp:
	fadescreen FADE_TO_BLACK
	delay 40
	warpsilent MAP_SOOTOPOLIS_CITY_DREAM_HOUSE, 2, 4
	waitstate
	end

DreamIsland_Forest_RestoreParty:
	special HealPlayerParty
	return
