SeafloorCavern_Room3_MapScripts::
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_5, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_Text_ShellyIntro:
	.string "Ahahahaha!\p"
	.string "Como conseguiu chegar sem um\n"
	.string "submarino? Que criança\l"
	.string "impressionante!\p"
	.string "Mas nao posso deixar você se meter\n"
	.string "aqui.\p"
	.string "E ainda quero uma revanche pelo\n"
	.string "que aconteceu no Weather\l"
	.string "Institute...\p"
	.string "Prepare-se, porque isso vai doer!$"

SeafloorCavern_Room3_Text_ShellyDefeat:
	.string "Ahahahaha!\p"
	.string "Ai!$"

SeafloorCavern_Room3_Text_ShellyPostBattle:
	.string "Ahahahaha! Você é forte demais.\p"
	.string "É uma pena que nao faça parte da\n"
	.string "Team Aqua.\p"
	.string "Podia aproveitar com a gente o\n"
	.string "mundo incrível que nosso chefe\l"
	.string "prometeu...$"

SeafloorCavern_Room3_Text_Grunt5Intro:
	.string "Precisamos do poder dos Pokémon\n"
	.string "pra realizar nosso sonho.\p"
	.string "Mas você usa esse mesmo poder pra\n"
	.string "atrapalhar a gente até aqui!\p"
	.string "A vida nunca sai como a gente\n"
	.string "quer!$"

SeafloorCavern_Room3_Text_Grunt5Defeat:
	.string "Guah!$"

SeafloorCavern_Room3_Text_Grunt5PostBattle:
	.string "A gente nem ousa questionar o\n"
	.string "líder.\p"
	.string "E você vem enfrentar ele...\p"
	.string "Talvez tenha alguma coisa especial\n"
	.string "mesmo.$"

