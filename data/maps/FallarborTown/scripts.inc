FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_Text_ShadyCharactersCozmosHome:
	.string "Tem alguma coisa acontecendo, e eu\n"
	.string "nao tô gostando!\p"
	.string "Vi umas pessoas suspeitas entrando\n"
	.string "e saindo da casa do Professor\l"
	.string "COZMO...$"

FallarborTown_Text_RegionKnownForMeteors:
	.string "Esta regiao é conhecida pelos\n"
	.string "meteoros desde muito tempo atrás.\p"
	.string "Dizem que METEOR FALLS surgiu\n"
	.string "quando um meteorito caiu ali.$"

FallarborTown_Text_MyPreciousAzurill:
	.string "Olha só! Este é meu precioso\n"
	.string "AZURILL!\p"
	.string "É lisinho, macio e fofinho!$"

FallarborTown_Text_Azurill:
	.string "AZURILL: Rooreelooo.$"

FallarborTown_Text_HaveYouChallengedFlannery:
	.string "Já desafiou FLANNERY, a líder do\n"
	.string "ginásio de LAVARIDGE?\p"
	.string "O avô dela era famoso. Já foi um\n"
	.string "dos membros da Elite Four da\l"
	.string "POKéMON LEAGUE.\p"
	.string "Nao vou me surpreender se ela\n"
	.string "também virar uma grande treinadora.$"

FallarborTown_Text_BattleTentSign:
	.string "BATTLE TENT de FALLARBOR\p"
	.string "“Que venham as melhores equipes!”$"

FallarborTown_Text_TownSign:
	.string "FALLARBOR TOWN\p"
	.string "“Uma comunidade de agricultores e\n"
	.string "pequenos jardins.”$"

FallarborTown_Text_MoveTutorSign:
	.string "Casa do tutor de golpes\p"
	.string "“Novos golpes para seus\n"
	.string "POKÉMONS.”$"

