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
	.string "Ora, ora, ora, um jogador mediocre\n"
	.string "ousa desafiar o ADM SUPREMO? É\l"
	.string "oque veremos.. Boa sorte, você irá\l"
	.string "precisar.$"

AlteringCave_Text_WillianDefeat:
	.string "AHAHAHA, você só me venceu pois\n"
	.string "usei 100% do meu 1% do meu poder.\l"
	.string "Tome isto$"

