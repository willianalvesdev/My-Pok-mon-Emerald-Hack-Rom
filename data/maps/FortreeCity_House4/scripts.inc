FortreeCity_House4_MapScripts::
	.byte 0

FortreeCity_House4_EventScript_Woman::
	msgbox FortreeCity_House4_Text_BringsWorldCloserTogether, MSGBOX_NPC
	end

FortreeCity_House4_EventScript_Boy::
	lockall
	goto_if_set FLAG_RECEIVED_MENTAL_HERB, FortreeCity_House4_EventScript_ReceivedMentalHerb
	goto_if_set FLAG_WINGULL_DELIVERED_MAIL, FortreeCity_House4_EventScript_WingullReturned
	goto_if_set FLAG_WINGULL_SENT_ON_ERRAND, FortreeCity_House4_EventScript_WingullOnErrand
	msgbox FortreeCity_House4_Text_GoBirdPokemon, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_WINGULL_SENT_ON_ERRAND
	clearflag FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL
	applymovement LOCALID_FORTREE_HOUSE_WINGULL, FortreeCity_House4_Movement_WingullExit
	waitmovement 0
	removeobject LOCALID_FORTREE_HOUSE_WINGULL
	releaseall
	end

FortreeCity_House4_EventScript_WingullOnErrand::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_AskedWingullToRunErrand, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_EventScript_WingullReturned::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb, MSGBOX_DEFAULT
	giveitem ITEM_MENTAL_HERB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MENTAL_HERB
	releaseall
	end

FortreeCity_House4_EventScript_ReceivedMentalHerb::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_FriendsFarAwayThanksToWingull, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_Movement_WingullExit:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_down
	delay_8
	step_end

FortreeCity_House4_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox FortreeCity_House4_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House4_Text_BringsWorldCloserTogether:
	.string "Com os POKÉMONS por perto, as\n"
	.string "pessoas fazem cada vez mais\l"
	.string "amigos.\p"
	.string "Isso aproxima o mundo inteiro.\n"
	.string "Acho maravilhoso!$"

FortreeCity_House4_Text_GoBirdPokemon:
	.string "Vai lá, meu pássaro!$"

FortreeCity_House4_Text_AskedWingullToRunErrand:
	.string "Hehe, pedi pro meu WINGULL fazer\n"
	.string "uma entrega pra mim.$"

FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb:
	.string "Boa! Voltou, WINGULL!\p"
	.string "Hein? Oque é isso? Oque ele ta\n"
	.string "segurando?\p"
	.string "Uma MENTAL HERB? Deve ter pegado\n"
	.string "em algum lugar.\p"
	.string "Como nao sou treinador, pode ficar\n"
	.string "com ela.$"

FortreeCity_House4_Text_FriendsFarAwayThanksToWingull:
	.string "Graças ao meu WINGULL, tenho\n"
	.string "amigos que moram bem longe.$"

FortreeCity_House4_Text_Wingull:
	.string "WINGULL: Pihyoh!$"

