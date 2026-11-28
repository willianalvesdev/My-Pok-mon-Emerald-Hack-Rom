.equ GAVE_PROFILE,  VAR_TEMP_1

MysteryEventClub_EventScript_Woman::
	lock
	faceplayer
	goto_if_eq GAVE_PROFILE, TRUE, EventScript_AlreadyGaveProfile
	goto_if_set FLAG_SYS_SET_TRAINER_CARD_PROFILE, EventScript_GivenProfileBefore
	msgbox Text_IdLoveToHearYourProfile
	goto EventScript_AskForProfile
	end

EventScript_AlreadyGaveProfile:
	msgbox Text_TellMoreNextTime
	release
	end

EventScript_AskForProfile:
	message Text_TellMeWhatsYourProfile
	waitmessage
	multichoice 18, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, EventScript_AcceptGiveProfile
	case 1, EventScript_DeclineGiveProfile
	case 2, EventScript_ProfileInfo
	case MULTI_B_PRESSED, EventScript_DeclineGiveProfile
	end

EventScript_ProfileInfo:
	msgbox Text_ExplainProfile
	goto EventScript_AskForProfile
	end

EventScript_AcceptGiveProfile:
	msgbox Text_WhatsYourProfile
	closemessage
	goto EventScript_GiveProfile
	end

EventScript_CancelGiveProfile:
	msgbox Text_DecidedNotTo
	release
	end

EventScript_GaveProfile:
	setvar GAVE_PROFILE, TRUE
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox Text_ProfileSaysSomethingAboutYou
	release
	end

EventScript_DeclineGiveProfile:
	msgbox Text_DontBeLikeThat
	release
	end

EventScript_GivenProfileBefore:
	msgbox Text_HiWeMeetAgain
	goto EventScript_AskForNewProfile
	end

EventScript_AskForNewProfile:
	message Text_ChangeYourProfile
	waitmessage
	multichoice 18, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, EventScript_AcceptGiveNewProfile
	case 1, EventScript_DeclineGiveNewProfile
	case 2, EventScript_ProfileInfo2
	@case MULTI_B_PRESSED, EventScript_DeclineGiveNewProfile
	end

EventScript_ProfileInfo2:
	msgbox Text_ExplainProfile
	goto EventScript_AskForNewProfile
	end

EventScript_AcceptGiveNewProfile:
	msgbox Text_WhatAreYouLikeNow
	closemessage
	goto EventScript_GiveProfile
	end

EventScript_DeclineGiveNewProfile:
	msgbox Text_LikeProfileWayItIs
	release
	end

EventScript_GaveSpecialProfile:
	setvar GAVE_PROFILE, TRUE
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox Text_HeardThatBefore
	release
	end

EventScript_GiveProfile:
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_0x8004, 0, EventScript_GaveSpecialProfile
	goto_if_eq VAR_RESULT, FALSE, EventScript_CancelGiveProfile
	goto_if_eq VAR_RESULT, TRUE, EventScript_GaveProfile
	end

Text_IdLoveToHearYourProfile:
	.string "Oi, prazer!\p"
	.string "Poxa, nem vai dar um oi de volta?\p"
	.string "Vamos, me conta sobre você. Quero\n"
	.string "conhecer seu perfil!$"

Text_TellMeWhatsYourProfile:
	.string "Me conta uma coisa boa sobre você.\n"
	.string "Como é seu perfil?$"

Text_ExplainProfile:
	.string "Você escreve um perfil com quatro\n"
	.string "palavras ou frases.\p"
	.string "Tem várias opçoes, separadas em\n"
	.string "grupos pra facilitar.\p"
	.string "Primeiro escolha um grupo, depois\n"
	.string "uma palavra ou frase.\p"
	.string "É mais fácil do que parece.\n"
	.string "Experimenta!$"

Text_WhatsYourProfile:
	.string "Como é seu perfil?$"

Text_DontBeLikeThat:
	.string "Ah... Nao seja assim. Pode me\n"
	.string "contar seu perfil.$"

Text_DecidedNotTo:
	.string "Ah, desistiu? Você muda de ideia\n"
	.string "rápido, né?$"

Text_HiWeMeetAgain:
	.string "Oi! A gente se encontrou de novo!$"

Text_ChangeYourProfile:
	.string "Quer mudar seu perfil?$"

Text_WhatAreYouLikeNow:
	.string "Como você ta agora? Quero saber.$"

Text_LikeProfileWayItIs:
	.string "Certo, gosta do perfil como ele\n"
	.string "ta.\p"
	.string "Também acho que ficou bom.$"

Text_ProfileSaysSomethingAboutYou:
	.string "Hum... Seu perfil mostra bem quem\n"
	.string "você é.\p"
	.string "Agora que conheço você melhor,\n"
	.string "somos ainda mais amigos!$"

Text_HeardThatBefore:
	.string "Ah, já ouvi isso antes...\p"
	.string "Acho que meu primo que mora longe\n"
	.string "sempre dizia.$"

Text_TellMoreNextTime:
	.string "Na próxima, me conta mais sobre\n"
	.string "você!$"
