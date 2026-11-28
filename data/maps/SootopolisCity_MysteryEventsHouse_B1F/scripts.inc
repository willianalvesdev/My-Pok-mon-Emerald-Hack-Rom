SootopolisCity_MysteryEventsHouse_B1F_MapScripts::
	.byte 0

SootopolisCity_MysteryEventsHouse_B1F_EventScript_Gustavo::
	trainerbattle_single TRAINER_GUSTAVO, SootopolisCity_MysteryEventsHouse_B1F_Text_GustavoIntro, SootopolisCity_MysteryEventsHouse_B1F_Text_GustavoDefeat, SootopolisCity_MysteryEventsHouse_B1F_EventScript_GustavoReward

SootopolisCity_MysteryEventsHouse_B1F_EventScript_GustavoReward::
	goto_if_set FLAG_RECEIVED_MYSTIC_TICKET, SootopolisCity_MysteryEventsHouse_B1F_EventScript_GustavoEnd
	giveitem ITEM_MYSTIC_TICKET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_RECEIVED_MYSTIC_TICKET

SootopolisCity_MysteryEventsHouse_B1F_EventScript_GustavoEnd::
	release
	end

SootopolisCity_MysteryEventsHouse_B1F_Text_GustavoIntro:
	.string "Como ousa desafiar o rei do\n"
	.string "Emerald? Vou te mostrar meu poder\l"
	.string "máximo!$"

SootopolisCity_MysteryEventsHouse_B1F_Text_GustavoDefeat:
	.string "Uuh, nunca me senti tao humilhado\n"
	.string "desde que fui molestado pelo\l"
	.string "suicune...$"
