MagmaHideout_4F_MapScripts::
	.byte 0

MagmaHideout_4F_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON_SLEEPING
	addobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	waitstate
	delay 60
	applymovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	waitmovement 0
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setvar VAR_SLATEPORT_CITY_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAGMA_HIDEOUT_4F_MAXIE
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_1
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_2
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_3
	removeobject LOCALID_MAGMA_HIDEOUT_4F_TABITHA
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_GroudonExit:
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_Grunt11::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro:
	.string "Também queria ver Groudon, mas nao\n"
	.string "deixam eu ver nem a cauda dele...\p"
	.string "Isso me deixa tao irritado!\p"
	.string "Ah, nao! Falei do Groudon!$"

MagmaHideout_4F_Text_Grunt11Defeat:
	.string "Nao dá pra vencer com a cabeça\n"
	.string "tao cheia...$"

MagmaHideout_4F_Text_Grunt11PostBattle:
	.string "Será que Groudon tem cauda mesmo?\p"
	.string "Nao me mostram nem a foto da vaga\n"
	.string "que eu aceitei.$"

MagmaHideout_4F_Text_Grunt12Intro:
	.string "Fuhahaha! Logo, logo nosso grande\n"
	.string "objetivo vai se realizar!$"

MagmaHideout_4F_Text_Grunt12Defeat:
	.string "Grrr... Cheguei tao longe pra isso?$"

MagmaHideout_4F_Text_Grunt12PostBattle:
	.string "Senhor Maxie! Um invasor ta indo\n"
	.string "na sua direçao!$"

MagmaHideout_4F_Text_Grunt13Intro:
	.string "Ainda nao acabou! Nao vai passar\n"
	.string "por mim tao fácil!$"

MagmaHideout_4F_Text_Grunt13Defeat:
	.string "Eu caí tao fácil assim?$"

MagmaHideout_4F_Text_Grunt13PostBattle:
	.string "V-vamos mais uma...\p"
	.string "Prometo que dessa vez eu lembro\n"
	.string "de atacar.$"

MagmaHideout_4F_Text_TabithaIntro:
	.string "Hehehe! Já que chegou até aqui,\n"
	.string "vou contar!\p"
	.string "É isso mesmo! Groudon ta dormindo\n"
	.string "logo à frente!\p"
	.string "Maxie acabou de ir até ele!\p"
	.string "Ele vai acordar a qualquer\n"
	.string "momento! Hehe! Hehehe!$"

MagmaHideout_4F_Text_TabithaDefeat:
	.string "Perdi de novo... Hehe...$"

MagmaHideout_4F_Text_TabithaPostBattle:
	.string "...Enquanto você perdia tempo\n"
	.string "comigo, Maxie já deve ter acordado\l"
	.string "Groudon...$"

MagmaHideout_4F_Text_MaxieAwakenGroudon:
	.string "MAXIE: Groudon...\p"
	.string "Nada conseguiu despertar você\n"
	.string "desse sono em meio ao magma...\p"
	.string "Era esta Blue Orb que você\n"
	.string "procurava, nao era?\p"
	.string "Eu a trouxe. Deixe que seu brilho\n"
	.string "desperte você!\p"
	.string "E mostre... Mostre toda a força do\n"
	.string "seu poder!$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
	.string "MAXIE: Groudon! Oque houve?\p"
	.string "A Blue Orb nao era a chave?\p"
	.string "Groudon! Pra onde você foi...?$"

MagmaHideout_4F_Text_MaxieOhItWasYou:
	.string "MAXIE: Ah, entao foi você?\p"
	.string "Tenho visto você se metendo onde\n"
	.string "nao foi chamado...\p"
	.string "Agora entendi! Você deve ter feito\n"
	.string "algum truque!$"

MagmaHideout_4F_Text_MaxieDefeat:
	.string "Como você consegue lidar tao bem\n"
	.string "com os Pokémon?$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:
	.string "MAXIE: Deve existir algum motivo\n"
	.string "pra Groudon ter fugido...\p"
	.string "É isso que você quer dizer, nao é?\p"
	.string "...\p"
	.string "Hum... Acha que eu nao sei disso?\p"
	.string "Sem Groudon, nao tenho mais motivo\n"
	.string "pra ficar neste vulcao.\p"
	.string "Vou atrás dele. Nos despedimos\n"
	.string "aqui!$"
