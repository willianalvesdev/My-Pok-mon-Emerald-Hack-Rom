Route119_WeatherInstitute_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
	end

Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, 0, 5
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere::
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_1F_EventScript_StudyingRain  @ Both defeated
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_StudyingRain::
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_Bed::
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_Grunt1Intro:
	.string "O chefe se interessou pelas\n"
	.string "pesquisas daqui e mandou a gente\l"
	.string "vir.\p"
	.string "Para de se meter!$"

Route119_WeatherInstitute_1F_Text_Grunt1Defeat:
	.string "Droga... Derrotado por uma\n"
	.string "criança...$"

Route119_WeatherInstitute_1F_Text_Grunt1PostBattle:
	.string "Nosso chefe sabe de tudo.\p"
	.string "Mas eu sou só um capanga. Como\n"
	.string "vou saber oque ele pensa?\p"
	.string "Meu cargo nao vem com acesso à\n"
	.string "cabeça do chefe.$"

Route119_WeatherInstitute_1F_Text_Grunt4Intro:
	.string "Hein? Oque uma criança ta fazendo\n"
	.string "aqui?$"

Route119_WeatherInstitute_1F_Text_Grunt4Defeat:
	.string "Hein? Eu perdi?!$"

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle:
	.string "Ah, nao... Vao reclamar muito por\n"
	.string "eu ter perdido pra uma criança...\p"
	.string "Vou deitar naquela cama e fingir\n"
	.string "que já tava dormindo.$"

Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
	.string "Enquanto eu dormia, todo mundo\n"
	.string "subiu!$"

Route119_WeatherInstitute_1F_Text_WowYoureStrong:
	.string "Nossa, você é forte mesmo!\p"
	.string "Queria ser um treinador Pokémon\n"
	.string "igual a você!$"

Route119_WeatherInstitute_1F_Text_ProfStudyingRain:
	.string "O professor adora chuva. Isso é\n"
	.string "fato.\p"
	.string "Mas, se nao parar de chover, as\n"
	.string "pessoas vao ter problemas. Isso\l"
	.string "também é fato.\p"
	.string "Por isso ele estuda como\n"
	.string "aproveitar melhor a chuva.$"

Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather:
	.string "No segundo andar, estudamos o\n"
	.string "clima de Hoenn.\p"
	.string "Ultimamente apareceram secas e\n"
	.string "chuvas fortes em alguns lugares,\l"
	.string "mas só por pouco tempo...$"

Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
	.string "Oi! Você salvou a gente!\p"
	.string "Só nao entendo oque a Team Aqua\n"
	.string "queria.$"

Route119_WeatherInstitute_1F_Text_TakeRestInBed:
	.string "Tem uma cama... Hora de descansar.$"

