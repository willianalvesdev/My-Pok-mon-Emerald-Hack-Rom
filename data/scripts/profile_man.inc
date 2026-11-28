ProfileMan_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CHAT_USED, ProfileMan_EventScript_GivenProfileBefore
	msgbox ProfileMan_Text_CollectTrainerProfiles, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_AskToSeeProfile::
	msgbox ProfileMan_Text_MayISeeYourProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateProfile
	case 1, ProfileMan_EventScript_DeclineShowProfile
	case 2, ProfileMan_EventScript_Info
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineShowProfile
	end

ProfileMan_EventScript_Info::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_CreateProfile::
	msgbox ProfileMan_Text_LetsSeeItThen, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_CancelShowProfile::
	msgbox ProfileMan_Text_NotIntoItRightNow, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_ShowProfile::
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox ProfileMan_Text_FantasticProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_DeclineShowProfile::
	msgbox ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_GivenProfileBefore::
	msgbox ProfileMan_Text_YouHaveWonderfulSmile, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_AskToSeeNewProfile::
	msgbox ProfileMan_Text_MayISeeYourNewProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateNewProfile
	case 1, ProfileMan_EventScript_DeclineNewProfile
	case 2, ProfileMan_EventScript_InfoNewProfile
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineNewProfile
	end

ProfileMan_EventScript_InfoNewProfile::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_CreateNewProfile::
	msgbox ProfileMan_Text_EvenBetterThanLastProfile, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_DeclineNewProfile::
	msgbox ProfileMan_Text_LikeProfileWayItIs, MSGBOX_DEFAULT
	release
	end

@ Unused
ProfileMan_EventScript_Ret::
	return

ProfileMan_Text_CollectTrainerProfiles:
	.string "Oi, treinador! Que sorriso bonito!\p"
	.string "Meu passatempo é colecionar perfis\n"
	.string "de treinadores Pokémon.$"

ProfileMan_Text_MayISeeYourProfile:
	.string "E entao, posso ver seu perfil?$"

ProfileMan_Text_EasyChatExplanation:
	.string "Você cria um perfil juntando\n"
	.string "quatro palavras ou frases.\p"
	.string "Vou mostrar um exemplo com quatro\n"
	.string "partes. Pode trocar cada uma delas\l"
	.string "pra deixar do seu jeito.\p"
	.string "Tem várias opçoes, organizadas em\n"
	.string "grupos como Pokémon, dia a dia e\l"
	.string "passatempos.\p"
	.string "Escolha um grupo pra abrir a lista\n"
	.string "e depois escolha uma opçao.\p"
	.string "Repita com as outras partes e seu\n"
	.string "perfil vai ficar pronto.$"

ProfileMan_Text_LetsSeeItThen:
	.string "Sim! Obrigado! Vamos ver.$"

ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile:
	.string "Ah, sério?\p"
	.string "Imaginei que alguém como você\n"
	.string "teria um perfil ótimo...$"

ProfileMan_Text_NotIntoItRightNow:
	.string "Ah, nao quer agora?\p"
	.string "Tudo bem, pode ser quando quiser!$"

ProfileMan_Text_YouHaveWonderfulSmile:
	.string "Oi, treinador! Que sorriso bonito!$"

ProfileMan_Text_MayISeeYourNewProfile:
	.string "Posso ver seu perfil novo?$"

ProfileMan_Text_EvenBetterThanLastProfile:
	.string "Sim! Obrigado!\p"
	.string "Espero que fique ainda melhor que\n"
	.string "o perfil da última vez.$"

ProfileMan_Text_LikeProfileWayItIs:
	.string "Ah, você gosta do perfil como ele\n"
	.string "ta.\p"
	.string "Entendo, ele já ficou muito bom.$"

ProfileMan_Text_FantasticProfile:
	.string "F-fantástico! Seu perfil ficou\n"
	.string "ótimo! Mostra muito bem quem você\l"
	.string "é.\p"
	.string "Qualquer um ia se interessar ao\n"
	.string "ouvir isso! Obrigado!$"

@ Unused
ProfileMan_Text_YouKnowSecretSaying:
	.string "Ah, conhece a frase secreta!\p"
	.string "Entao agora faz parte do Mystery\n"
	.string "Event Club!$"
