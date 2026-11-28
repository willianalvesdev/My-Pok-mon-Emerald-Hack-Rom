CaveOfOrigin_B1F_MapScripts::
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace::
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_FacePlayer
	waitmovement 0
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza::
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin::
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre::
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember::
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar::
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	removeobject LOCALID_CAVE_OF_ORIGIN_WALLACE
	clearflag FLAG_HIDE_SKY_PILLAR_WALLACE
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory:
	.string "Entao você é {PLAYER}{KUN}? Já ouvi\n"
	.string "falar do que você fez.\p"
	.string "Meu nome é WALLACE.\p"
	.string "Eu era o líder do ginásio de\n"
	.string "SOOTOPOLIS, mas precisei deixar o\l"
	.string "cargo.\p"
	.string "Agora, meu mestre JUAN cuida do\n"
	.string "ginásio.\p"
	.string "... ... ... ... ... ...\p"
	.string "GROUDON e KYOGRE, os dois\n"
	.string "POKÉMONS causando essa destruiçao,\l"
	.string "sao considerados superantigos.\p"
	.string "Mas nao existem só esses dois.\p"
	.string "Tem mais um em algum lugar.\p"
	.string "Um POKÉMON superantigo chamado\n"
	.string "RAYQUAZA.\p"
	.string "Dizem que, há muito tempo, foi ele\n"
	.string "quem acalmou os outros dois.\p"
	.string "Mas nem eu sei onde encontrar\n"
	.string "RAYQUAZA...$"

CaveOfOrigin_B1F_Text_WhereIsRayquaza:
	.string "WALLACE: {PLAYER}{KUN}, você sabe onde\n"
	.string "RAYQUAZA está?\p"
	.string "Se souber, por favor, me conte.$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin:
	.string "WALLACE: Na CAVE OF ORIGIN?\p"
	.string "Mas a gente já está aqui! Preciso\n"
	.string "que pense melhor!\p"
	.string "Tente lembrar onde RAYQUAZA pode\n"
	.string "estar agora.$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat:
	.string "WALLACE: No MT. PYRE?\p"
	.string "Falei com a senhora de lá há\n"
	.string "pouco, e ela nao comentou nada\l"
	.string "sobre isso.\p"
	.string "Duvido que estivesse tentando\n"
	.string "esconder alguma coisa de mim...\p"
	.string "{PLAYER}{KUN}, pode pensar com mais\n"
	.string "calma?$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow:
	.string "WALLACE: O quê? Nao lembra? Hum...\n"
	.string "Isso é um problema...\p"
	.string "Tente lembrar de alguma pista.$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar:
	.string "WALLACE: No SKY PILLAR?\p"
	.string "É isso! Deve ser o SKY PILLAR!\p"
	.string "{PLAYER}{KUN}, nao temos tempo a\n"
	.string "perder! Vamos pra lá agora!$"

