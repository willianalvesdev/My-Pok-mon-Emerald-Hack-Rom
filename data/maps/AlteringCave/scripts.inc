AlteringCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_OnTransition
	.byte 0

AlteringCave_OnTransition:
	setflag FLAG_LANDMARK_ALTERING_CAVE
	end

AlteringCave_EventScript_Willian::
	trainerbattle_single TRAINER_WILLIAN, AlteringCave_Text_WillianIntro, AlteringCave_Text_WillianDefeat, AlteringCave_EventScript_WillianReward

AlteringCave_EventScript_WillianReward::
	goto_if_set FLAG_RECEIVED_AURORA_TICKET, AlteringCave_EventScript_WillianEnd
	giveitem ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_AURORA_TICKET

AlteringCave_EventScript_WillianEnd::
	release
	end

AlteringCave_Text_WillianIntro:
	.string "Um jogador jamais vencerá\n"
	.string "o ADM SUPREMO$"

AlteringCave_Text_WillianDefeat:
	.string "Eu nao estava jogando sério,\n"
	.string "mas você mereceu isso:$"

