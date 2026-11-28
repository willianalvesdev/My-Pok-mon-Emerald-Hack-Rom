PacifidlogTown_House4_MapScripts::
	.byte 0

PacifidlogTown_House4_EventScript_LittleGirl::
	msgbox PacifidlogTown_House4_Text_SkyPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Woman::
	msgbox PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Boy::
	lock
	faceplayer
	msgbox PacifidlogTown_House4_Text_WhereDidYouComeFrom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PacifidlogTown_House4_EventScript_Yes
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House4_EventScript_No
	end

PacifidlogTown_House4_EventScript_Yes::
	msgbox PacifidlogTown_House4_Text_YesTown, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_EventScript_No::
	msgbox PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon:
	.string "Disseram que viram um Pokémon\n"
	.string "voando bem alto sobre Hoenn.\p"
	.string "Será que ele voa o tempo todo?\n"
	.string "Nao precisa descansar em algum\l"
	.string "lugar?$"

PacifidlogTown_House4_Text_SkyPokemon:
	.string "Um Pokémon do céu! Um Pokémon do\n"
	.string "céu!$"

PacifidlogTown_House4_Text_WhereDidYouComeFrom:
	.string "De onde você veio?$"

PacifidlogTown_House4_Text_YesTown:
	.string "Sim? Cidade Sim?\p"
	.string "Nunca ouvi falar desse lugar.$"

PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere:
	.string "Nao? Como assim? Você precisa ter\n"
	.string "vindo de algum lugar.\p"
	.string "Espera! Nao vai me dizer que\n"
	.string "nasceu no fundo do mar?$"

