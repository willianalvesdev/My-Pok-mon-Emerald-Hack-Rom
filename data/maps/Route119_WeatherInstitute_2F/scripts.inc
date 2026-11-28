Route119_WeatherInstitute_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_2F_OnTransition
	.byte 0

Route119_WeatherInstitute_2F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 1, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone
	call_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear
	end

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, 1, 6
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, 4, 6
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, 2, 2
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, MOVEMENT_TYPE_FACE_UP
	return

Route119_WeatherInstitute_2F_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_5, Route119_WeatherInstitute_2F_Text_Grunt5Intro, Route119_WeatherInstitute_2F_Text_Grunt5Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_2, Route119_WeatherInstitute_2F_Text_Grunt2Intro, Route119_WeatherInstitute_2F_Text_Grunt2Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_3, Route119_WeatherInstitute_2F_Text_Grunt3Intro, Route119_WeatherInstitute_2F_Text_Grunt3Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_WEATHER_INSTITUTE, Route119_WeatherInstitute_2F_Text_ShellyIntro, Route119_WeatherInstitute_2F_Text_ShellyDefeat, Route119_WeatherInstitute_2F_EventScript_ShellyDefeated
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_ShellyDefeated::
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_DEFAULT
	closemessage
	addobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_3
	applymovement LOCALID_WEATHER_INSTITUTE_2F_GRUNT_3, Route119_WeatherInstitute_2F_Movement_GruntApproachShelly
	applymovement LOCALID_PLAYER, Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_WEATHER_INSTITUTE_2F_SHELLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WEATHER_INSTITUTE_2F_SHELLY, Common_Movement_Delay48
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre, MSGBOX_DEFAULT
	closemessage
	setvar VAR_WEATHER_INSTITUTE_STATE, 1
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_ROUTE_119_TEAM_AQUA
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M
	removeobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_1
	removeobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_2
	removeobject LOCALID_WEATHER_INSTITUTE_2F_SHELLY
	removeobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_4
	removeobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_3
	applymovement LOCALID_PLAYER, Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition
	waitmovement 0
	fadescreen FADE_FROM_BLACK
	applymovement LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer
	waitmovement 0
	copyobjectxytoperm LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastform::
	msgbox Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon, MSGBOX_DEFAULT
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CASTFORM_NORMAL
	givemon SPECIES_CASTFORM_NORMAL, 25, ITEM_MYSTIC_WATER
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty::
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC::
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	end

Route119_WeatherInstitute_2F_EventScript_SendCastformToPC::
	call Common_EventScript_TransferredToPC
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_CASTFORM_NORMAL
	return

Route119_WeatherInstitute_2F_EventScript_ExplainCastform::
	msgbox Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_CASTFORM
	release
	end

Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather::
	goto_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather
	msgbox Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather::
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather  @ Both defeated
	call_if_unset FLAG_TEMP_2, Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather
	specialvar VAR_RESULT, GetAbnormalWeatherMapNameAndType
	goto_if_eq VAR_RESULT, 1, Route119_WeatherInstitute_2F_EventScript_KyogreWeather
	msgbox Route119_WeatherInstitute_2F_Text_GroudonWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_KyogreWeather::
	msgbox Route119_WeatherInstitute_2F_Text_KyogreWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather::
	special CreateAbnormalWeatherEvent
	setflag FLAG_TEMP_2
	return

Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather::
	msgbox Route119_WeatherInstitute_2F_Text_NoAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_Movement_GruntApproachShelly:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	ride_water_current_up
	walk_in_place_faster_down
	step_end

Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition:
	slide_down
	walk_in_place_faster_left
	step_end

Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer:
	walk_right
	walk_right
	walk_right
	step_end

Route119_WeatherInstitute_2F_EventScript_WeatherScientist::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CASTFORM, Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_Text_Grunt2Intro:
	.string "O instituto criou um Pokémon ligado\n"
	.string "ao clima. Viemos buscar ele!$"

Route119_WeatherInstitute_2F_Text_Grunt2Defeat:
	.string "Nosso plano ta sendo estragado\n"
	.string "por uma criança?$"

Route119_WeatherInstitute_2F_Text_Grunt2PostBattle:
	.string "Se esse Pokémon controla o clima,\n"
	.string "a Team Aqua precisa dele!$"

Route119_WeatherInstitute_2F_Text_Grunt3Intro:
	.string "Somos a Team Aqua! Onde tem\n"
	.string "alguma coisa rara, a gente\l"
	.string "aparece!$"

Route119_WeatherInstitute_2F_Text_Grunt3Defeat:
	.string "Você me pegou!$"

Route119_WeatherInstitute_2F_Text_Grunt3PostBattle:
	.string "Você nao faz ideia do que a Team\n"
	.string "Aqua quer! Sai do nosso caminho!$"

Route119_WeatherInstitute_2F_Text_Grunt5Intro:
	.string "Nao vai dizer que também quer\n"
	.string "aquele Pokémon do clima?\p"
	.string "Pode esquecer! A gente chegou\n"
	.string "primeiro!$"

Route119_WeatherInstitute_2F_Text_Grunt5Defeat:
	.string "Ah, olha como ficaram meus\n"
	.string "Pokémon...$"

Route119_WeatherInstitute_2F_Text_Grunt5PostBattle:
	.string "Hum, e daí? Oque queremos...\p"
	.string "Oque queremos de verdade nao ta\n"
	.string "aqui... Ihihihihi...$"

Route119_WeatherInstitute_2F_Text_ShellyIntro:
	.string "Ahahahaha!\p"
	.string "Vai se meter nos assuntos da Team\n"
	.string "Aqua?\p"
	.string "Ou você nao tem medo de nada, ou\n"
	.string "nao entende nada. Talvez os dois!\p"
	.string "Essa sua carinha chega a irritar.\n"
	.string "Vou acabar com você!$"

Route119_WeatherInstitute_2F_Text_ShellyDefeat:
	.string "Ahahahaha! Você é forte de um\n"
	.string "jeito irritante!$"

Route119_WeatherInstitute_2F_Text_ShellyPostBattle:
	.string "Já nao bastava a Team Magma\n"
	.string "fazendo besteira, agora tem você!\p"
	.string "Por que gosta tanto de se meter\n"
	.string "nos nossos assuntos?$"

Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy:
	.string "Temos um problema!\p"
	.string "Um grupo da Team Magma acabou de\n"
	.string "passar pelo Weather Institute.\p"
	.string "Parece que tao indo pro Mt. Pyre!$"

Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre:
	.string "Oque?!\p"
	.string "Nao podemos perder mais tempo!\n"
	.string "Também precisamos ir pro Mt. Pyre!\p"
	.string "Ahahahaha! Team Magma, esperem\n"
	.string "só!$"

Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon:
	.string "Obrigado! Você deixou a gente em\n"
	.string "segurança!\p"
	.string "Pode ser um jeito estranho de\n"
	.string "agradecer, mas aceite este\l"
	.string "Pokémon.$"

@ Unused
Route119_WeatherInstitute_2F_Text_NoRoomForPokemon:
	.string "Hum? Parece que nao tem espaço\n"
	.string "pra este Pokémon.$"

Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform:
	.string "{PLAYER} recebeu Castform!$"

Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather:
	.string "Esse Pokémon muda de forma de\n"
	.string "acordo com o clima.\p"
	.string "Temos vários aqui no instituto.\n"
	.string "Pode levar ele.$"

Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous:
	.string "Pesquiso a chuva faz muitos anos,\n"
	.string "mas acho absurdo pensar que\l"
	.string "humanos podem mudar o clima como\l"
	.string "quiserem.$"

Route119_WeatherInstitute_2F_Text_GroudonWeather:
	.string "Acompanho o clima de Hoenn.\p"
	.string "Neste momento, registramos uma\n"
	.string "seca em {STR_VAR_1}.\p"
	.string "Será que isso quer dizer que,\n"
	.string "perto de {STR_VAR_1}...$"

Route119_WeatherInstitute_2F_Text_KyogreWeather:
	.string "Acompanho o clima de Hoenn.\p"
	.string "Neste momento, registramos uma\n"
	.string "chuva muito forte em\l"
	.string "{STR_VAR_1}.\p"
	.string "Será que isso quer dizer que,\n"
	.string "perto de {STR_VAR_1}...$"

Route119_WeatherInstitute_2F_Text_NoAbnormalWeather:
	.string "Nao recebemos mais relatos de\n"
	.string "clima fora do normal.\p"
	.string "Uma chuva de vez em quando faz\n"
	.string "bem.$"

