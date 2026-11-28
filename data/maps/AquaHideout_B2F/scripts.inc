AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition:
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
	end

AquaHideout_B2F_EventScript_PreventMattNoticing::
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_MattNoticePlayer::
	lockall
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_TEMP_1, 1
	releaseall
	end

AquaHideout_B2F_EventScript_Matt::
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_SubmarineEscape::
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
	setvar VAR_0x8009, LOCALID_AQUA_HIDEOUT_SUBMARINE
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	release
	end

AquaHideout_B2F_Movement_SumbarineDepartLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
AquaHideout_B2F_Movement_SumbarineDepartRight:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated::
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_6, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_8, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_MattIntro:
	.string "Hehehe...\p"
	.string "Já chegou até aqui? Parece que te\n"
	.string "subestimamos!\p"
	.string "Mas agora é o fim!\p"
	.string "Sou muito superior aos meros\n"
	.string "campangas que você enfrentou até\l"
	.string "agora.\p"
	.string "Sem mais enrolaçoes, AGORA VOU TE\n"
	.string "ANIQUILAR!$"

AquaHideout_B2F_Text_MattDefeat:
	.string "Hehehe... Entao, eu também perdi...$"

AquaHideout_B2F_Text_OurBossGotThroughHisPreparations:
	.string "Hehehe!\p"
	.string "Enquanto eu te atrasava, o nosso\n"
	.string "chefe terminou seus preparativos!$"

AquaHideout_B2F_Text_MattPostBattle:
	.string "Hehehe!\p"
	.string "O nosso chefe já está a caminho\n"
	.string "de uma caverna sob o mar!\p"
	.string "Se você quer encontrá-lo, é melhor\n"
	.string "procurar no grande e largo mar\l"
	.string "além de LILYCOVE.\p"
	.string "Mas acha mesmo que irá\n"
	.string "encontrá-lo? Hehehe!$"

AquaHideout_B2F_Text_Grunt4Intro:
	.string "Wahahah, Cansei de esperar! Você\n"
	.string "também me deve uma batalha!$"

AquaHideout_B2F_Text_Grunt4Defeat:
	.string "Cansado de esperar, perdido,\n"
	.string "atordoado e humilhado...$"

AquaHideout_B2F_Text_Grunt4PostBattle:
	.string "Chefe... Eu fui bem o suficiente?$"

AquaHideout_B2F_Text_Grunt6Intro:
	.string "Painéis de teletransporte! A mais\n"
	.string "avançada tecnologia de nosso\l"
	.string "esconderijo!\p"
	.string "Você nao faz a menor ideia de onde\n"
	.string "está, nao é?\p"
	.string "Deixar o inimigo confuso e exausto,\n"
	.string "e depois... atacar com tudo! Esse\l"
	.string "é o nosso plano!$"

AquaHideout_B2F_Text_Grunt6Defeat:
	.string "O que tem de errado com você? Nem\n"
	.string "cansado você está!$"

AquaHideout_B2F_Text_Grunt6PostBattle:
	.string "Meu Deus, nao consigo me lembrar\n"
	.string "onde coloquei a MASTER BALL.\p"
	.string "Se ela sumir, o chefe vai me\n"
	.string "matar...$"

AquaHideout_B2F_Text_Grunt8Intro:
	.string "Quando eu entrei para o Team Aqua,\n"
	.string "a primeira coisa que tive de\l"
	.string "aprender foi como estes painéis de\l"
	.string "teletransporte se conectam.$"

AquaHideout_B2F_Text_Grunt8Defeat:
	.string "Eu estava ocupado demais pensando\n"
	.string "nos painéis de teletransporte...$"

AquaHideout_B2F_Text_Grunt8PostBattle:
	.string "Tenho que aprender como lutar de\n"
	.string "forma mais eficaz...$"
