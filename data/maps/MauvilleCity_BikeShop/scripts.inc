MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_ChooseBike::
	message MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne
	waitmessage
	multichoice 21, 8, MULTI_BIKE, TRUE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
	case 1, MauvilleCity_BikeShop_EventScript_GetAcroBike
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
	setflag FLAG_RECEIVED_BIKE
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_GetMachBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseMachBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_GetAcroBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	special SwapRegisteredBike
	release
	end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
	end

@ If the player does not have a bike on them Rydel assumes its stored in the PC
MauvilleCity_BikeShop_EventScript_SwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_KeepBike::
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
	.string "Olha só quem chegou! Um cliente\n"
	.string "cheio de energia!\p"
	.string "Pode me chamar de Rydel. Sou o\n"
	.string "dono desta loja de bicicletas.$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string "RYDEL: Seus Running Shoes tao bem\n"
	.string "sujos...\p"
	.string "Você veio de longe?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string "RYDEL: Ah, é?\p"
	.string "Entao acho que você nao precisa\n"
	.string "de uma das minhas bicicletas.$"

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
	.string "RYDEL: Hum...\p"
	.string "Você veio andando desde\n"
	.string "Littleroot? Nossa, é longe demais!\p"
	.string "Com uma bicicleta minha, você vai\n"
	.string "pra qualquer canto sentindo o\l"
	.string "vento no rosto.\p"
	.string "Já sei! Vou te dar uma bicicleta!\p"
	.string "Ah, espera! Temos dois tipos: Mach\n"
	.string "Bike e Acro Bike.\p"
	.string "A Mach Bike é pra quem gosta de\n"
	.string "velocidade. A Acro Bike é pra quem\l"
	.string "prefere manobras.\p"
	.string "Pode escolher a que quiser! Qual\n"
	.string "vai ser?$"

MauvilleCity_BikeShop_Text_ChoseMachBike:
	.string "{PLAYER} escolheu a Mach Bike.$"

MauvilleCity_BikeShop_Text_ChoseAcroBike:
	.string "{PLAYER} escolheu a Acro Bike.$"

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
	.string "RYDEL: Quando quiser trocar de\n"
	.string "bicicleta, é só vir falar comigo!$"

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
	.string "RYDEL: Opa! Ta pensando em trocar\n"
	.string "de bicicleta?$"

MauvilleCity_BikeShop_Text_IllSwitchBikes:
	.string "RYDEL: Claro, sem problema! Vou\n"
	.string "trocar pra você!$"

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
	.string "{PLAYER} trocou a Mach Bike por uma\n"
	.string "Acro Bike.$"

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
	.string "{PLAYER} trocou a Acro Bike por uma\n"
	.string "Mach Bike.$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
	.string "RYDEL: Muito bem! Fico feliz que\n"
	.string "gostou!$"

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
	.string "Opa, cadê a bicicleta que te dei?\p"
	.string "Ah, entendi. Você guardou no PC.\p"
	.string "Tire ela de lá que eu faço a\n"
	.string "troca!\p"
	.string "Que o vento acompanhe você na\n"
	.string "aventura!$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "Tô aprendendo sobre bicicletas\n"
	.string "enquanto trabalho aqui.\p"
	.string "Se precisar de ajuda pra pedalar,\n"
	.string "tem uns manuais no fundo da loja.$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string "É um manual da Mach Bike.\p"
	.string "Qual página quer ler?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string "A bicicleta anda na direçao que\n"
	.string "você aperta no direcional.\p"
	.string "Ela ganha velocidade enquanto\n"
	.string "pedala.\p"
	.string "Solte o direcional pra ela\n"
	.string "desacelerar até parar.\p"
	.string "Quer ler outra página?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string "A Mach Bike é rápida, mas demora\n"
	.string "pra parar. Isso dificulta fazer\l"
	.string "curvas.\p"
	.string "Solte o direcional um pouco antes\n"
	.string "da curva pra reduzir a velocidade.\p"
	.string "Quer ler outra página?$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string "Existem ladeiras de areia por toda\n"
	.string "Hoenn.\p"
	.string "A areia solta impede você de subir\n"
	.string "andando.\p"
	.string "Com a Mach Bike, dá pra subir\n"
	.string "ganhando velocidade antes.\p"
	.string "Quer ler outra página?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string "É um manual da Acro Bike.\p"
	.string "Qual página quer ler?$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string "Aperte B enquanto pedala pra\n"
	.string "levantar a roda da frente.\p"
	.string "Use o direcional pra andar assim.\n"
	.string "Essa manobra se chama empinar.\p"
	.string "Quer ler outra página?$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string "Segure B pra bicicleta começar a\n"
	.string "pular no mesmo lugar.\p"
	.string "Essa manobra se chama salto\n"
	.string "parado. Você também pode andar\l"
	.string "enquanto pula.\p"
	.string "Quer ler outra página?$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "Aperte B e uma direçao ao mesmo\n"
	.string "tempo pra saltar.\p"
	.string "Aperte uma direçao pro lado pra\n"
	.string "saltar de lado.\p"
	.string "Aperte na direçao oposta pra virar\n"
	.string "durante o salto.\p"
	.string "Quer ler outra página?$"

