RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoWaldaNamingScreen
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applymovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.string "É tao difícil todo dia...\p"
	.string "Oque é difícil? Ainda pergunta?\p"
	.string "Escolher oque fazer de comida! Ter\n"
	.string "uma ideia diferente todo dia nao é\l"
	.string "fácil!$"

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
	.string "Oi! Bem-vindo à casa da família\n"
	.string "Pepper.\p"
	.string "Já cuidou de uma criança? Sou pai\n"
	.string "de primeira viagem e ainda tô\l"
	.string "aprendendo.\p"
	.string "Minha filha Walda ri muito pouco.\n"
	.string "Talvez eu consiga animar ela com\l"
	.string "alguma coisa engraçada.\p"
	.string "Conhece alguma palavra ou frase\n"
	.string "boa?$"

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
	.string "Ultimamente digo “{STR_VAR_1}”\n"
	.string "pra fazer ela rir.\p"
	.string "Você conhece alguma frase melhor?$"

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
	.string "Ah, que ótimo! Vamos ouvir sua\n"
	.string "ideia.$"

RustboroCity_Flat1_2F_Text_OhIsThatRight:
	.string "Ah, é?\p"
	.string "Se pensar numa boa ideia, pode me\n"
	.string "contar.$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
	.string "Entendi. Vamos tentar?$"

RustboroCity_Flat1_2F_Text_OhShesLaughing:
	.string "{STR_VAR_1}. {STR_VAR_1}.\p"
	.string "Ah, sim! Ela ta rindo! Tô tao feliz\n"
	.string "quanto ela!$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry:
	.string "Entendi. Vamos tentar?$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
	.string "{STR_VAR_1}. {STR_VAR_1}.\p"
	.string "Hum... Ela nem sorriu. Talvez Walda\n"
	.string "seja uma criança muito séria...$"

RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
	.string "Ah, nao conhece nenhuma palavra\n"
	.string "boa? Vou pensar em alguma coisa.\p"
	.string "Que tal “{STR_VAR_1}”? Vamos\n"
	.string "ver se funciona.$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
	.string "{STR_VAR_1}. {STR_VAR_1}.\p"
	.string "Hum... Ela nem sorriu. Talvez Walda\n"
	.string "seja uma criança muito séria...$"

RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
	.string "Ah, nao conhece nenhuma palavra\n"
	.string "boa? Vou tentar a frase de antes.\p"
	.string "Se tiver uma ideia, nao precisa ter\n"
	.string "vergonha de contar, ta?$"

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
	.string "Obrigado! Você fez minha querida\n"
	.string "Walda rir!\p"
	.string "Posso nao parecer especial, mas\n"
	.string "sou um dos principais pesquisadores\l"
	.string "da Devon.\p"
	.string "Quero fazer uma coisa por você\n"
	.string "também.\p"
	.string "Vou adicionar papéis de parede\n"
	.string "novos pras Boxes do PC.\p"
	.string "No menu de papéis de parede,\n"
	.string "escolha “FRIENDS” pra encontrar os\l"
	.string "novos.$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
	.string "É um Pokémon de pelúcia!$"

