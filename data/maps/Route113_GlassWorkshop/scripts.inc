Route113_GlassWorkshop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route113_GlassWorkshop_OnTransition
	.byte 0

	.set BLUE_FLUTE_PRICE,   250
	.set YELLOW_FLUTE_PRICE, 500
	.set RED_FLUTE_PRICE,    500
	.set WHITE_FLUTE_PRICE,  1000
	.set BLACK_FLUTE_PRICE,  1000
	.set PRETTY_CHAIR_PRICE, 6000
	.set PRETTY_DESK_PRICE,  8000
	.set LOWEST_ASH_PRICE,   BLUE_FLUTE_PRICE

Route113_GlassWorkshop_OnTransition:
	setflag FLAG_LANDMARK_GLASS_WORKSHOP
	call_if_eq VAR_GLASS_WORKSHOP_STATE, 1, Route113_GlassWorkshop_EventScript_ReenterWorkshopAfterSootSack
	end

Route113_GlassWorkshop_EventScript_ReenterWorkshopAfterSootSack::
	setvar VAR_GLASS_WORKSHOP_STATE, 2
	return

Route113_GlassWorkshop_EventScript_GlassWorker::
	lock
	faceplayer
	goto_if_ge VAR_GLASS_WORKSHOP_STATE, 10, Route113_GlassWorkshop_EventScript_GiveItemAfterNoRoom
	goto_if_eq VAR_GLASS_WORKSHOP_STATE, 2, Route113_GlassWorkshop_EventScript_CheckCollectedAsh
	goto_if_eq VAR_GLASS_WORKSHOP_STATE, 1, Route113_GlassWorkshop_EventScript_ExplainSootSack
	msgbox Route113_GlassWorkshop_Text_GoCollectAshWithThis, MSGBOX_DEFAULT
	giveitem ITEM_SOOT_SACK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_GLASS_WORKSHOP_STATE, 1
	msgbox Route113_GlassWorkshop_Text_ExplainSootSack, MSGBOX_DEFAULT
	release
	end

Route113_GlassWorkshop_EventScript_ExplainSootSack::
	msgbox Route113_GlassWorkshop_Text_ExplainSootSack, MSGBOX_DEFAULT
	release
	end

Route113_GlassWorkshop_EventScript_CheckCollectedAsh::
	checkitem ITEM_SOOT_SACK
	goto_if_eq VAR_RESULT, FALSE, Route113_GlassWorkshop_EventScript_SootSackNotInBag
	msgbox Route113_GlassWorkshop_Text_LetsSeeCollectedAshes, MSGBOX_DEFAULT
	goto_if_lt VAR_ASH_GATHER_COUNT, LOWEST_ASH_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAsh
	message Route113_GlassWorkshop_Text_WhichGlassItemWoudYouLike
	waitmessage
	goto Route113_GlassWorkshop_EventScript_ChooseGlassItem
	end

Route113_GlassWorkshop_EventScript_SootSackNotInBag::
	msgbox Route113_GlassWorkshop_Text_HaventGotYourSootSack, MSGBOX_DEFAULT
	release
	end

Route113_GlassWorkshop_EventScript_ChooseGlassItem::
	setvar VAR_0x8009, 0
	setvar VAR_0x8004, SCROLL_MULTI_GLASS_WORKSHOP_VENDOR
	special ShowScrollableMultichoice
	switch VAR_RESULT
	case 0, Route113_GlassWorkshop_EventScript_BlueFlute
	case 1, Route113_GlassWorkshop_EventScript_YellowFlute
	case 2, Route113_GlassWorkshop_EventScript_RedFlute
	case 3, Route113_GlassWorkshop_EventScript_WhiteFlute
	case 4, Route113_GlassWorkshop_EventScript_BlackFlute
	case 5, Route113_GlassWorkshop_EventScript_PrettyChair
	case 6, Route113_GlassWorkshop_EventScript_PrettyDesk
	case 7, Route113_GlassWorkshop_EventScript_CancelGlassItemSelect
	case MULTI_B_PRESSED, Route113_GlassWorkshop_EventScript_CancelGlassItemSelect
	end

Route113_GlassWorkshop_EventScript_BlueFlute::
	setvar VAR_0x8008, ITEM_BLUE_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, BLUE_FLUTE_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, BLUE_FLUTE_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 10
	subvar VAR_ASH_GATHER_COUNT, BLUE_FLUTE_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_YellowFlute::
	setvar VAR_0x8008, ITEM_YELLOW_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, YELLOW_FLUTE_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, YELLOW_FLUTE_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 11
	subvar VAR_ASH_GATHER_COUNT, YELLOW_FLUTE_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_RedFlute::
	setvar VAR_0x8008, ITEM_RED_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, RED_FLUTE_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, RED_FLUTE_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 12
	subvar VAR_ASH_GATHER_COUNT, RED_FLUTE_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_WhiteFlute::
	setvar VAR_0x8008, ITEM_WHITE_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, WHITE_FLUTE_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, WHITE_FLUTE_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 13
	subvar VAR_ASH_GATHER_COUNT, WHITE_FLUTE_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_BlackFlute::
	setvar VAR_0x8008, ITEM_BLACK_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, BLACK_FLUTE_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, BLACK_FLUTE_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 14
	subvar VAR_ASH_GATHER_COUNT, BLACK_FLUTE_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_PrettyChair::
	setvar VAR_0x8009, 1
	setvar VAR_0x8008, DECOR_PRETTY_CHAIR
	bufferdecorationname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, PRETTY_CHAIR_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, PRETTY_CHAIR_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 15
	subvar VAR_ASH_GATHER_COUNT, PRETTY_CHAIR_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_PrettyDesk::
	setvar VAR_0x8009, 1
	setvar VAR_0x8008, DECOR_PRETTY_DESK
	bufferdecorationname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, PRETTY_DESK_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, PRETTY_DESK_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 16
	subvar VAR_ASH_GATHER_COUNT, PRETTY_DESK_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_CancelGlassItemSelect::
	msgbox Route113_GlassWorkshop_Text_AllThatAshButDontWantAnything, MSGBOX_DEFAULT
	release
	end

Route113_GlassWorkshop_EventScript_NotEnoughAsh::
	setvar VAR_0x800A, LOWEST_ASH_PRICE
	subvar VAR_0x800A, VAR_ASH_GATHER_COUNT
	buffernumberstring STR_VAR_1, VAR_0x800A
	msgbox Route113_GlassWorkshop_Text_NotEnoughAshNeedX, MSGBOX_DEFAULT
	release
	end

Route113_GlassWorkshop_EventScript_NotEnoughAshForItem::
	subvar VAR_0x800A, VAR_ASH_GATHER_COUNT
	buffernumberstring STR_VAR_2, VAR_0x800A
	message Route113_GlassWorkshop_Text_NotEnoughAshToMakeItem
	waitmessage
	goto Route113_GlassWorkshop_EventScript_ChooseGlassItem
	end

Route113_GlassWorkshop_EventScript_ChooseDifferentItem::
	message Route113_GlassWorkshop_Text_WhichWouldYouLike
	waitmessage
	goto Route113_GlassWorkshop_EventScript_ChooseGlassItem
	end

Route113_GlassWorkshop_EventScript_MakeGlassItem::
	msgbox Route113_GlassWorkshop_Text_IllMakeItemForYou, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_SELECT
	delay 30
	fadescreen FADE_FROM_BLACK
	msgbox Route113_GlassWorkshop_Text_IveFinishedGlassItem, MSGBOX_DEFAULT
	call_if_eq VAR_0x8009, 0, Route113_GlassWorkshop_EventScript_GiveGlassFlute
	call_if_eq VAR_0x8009, 1, Route113_GlassWorkshop_EventScript_GiveGlassDecor
	setvar VAR_GLASS_WORKSHOP_STATE, 2
	release
	end

Route113_GlassWorkshop_EventScript_GiveGlassFlute::
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, Route113_GlassWorkshop_EventScript_NoRoomForFlute
	return

Route113_GlassWorkshop_EventScript_GiveGlassDecor::
	givedecoration VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, Route113_GlassWorkshop_EventScript_NoRoomForDecor
	return

Route113_GlassWorkshop_EventScript_NoRoomForFlute::
	call Common_EventScript_BagIsFull
	msgbox Route113_GlassWorkshop_Text_NoRoomInBag, MSGBOX_DEFAULT
	release
	end

Route113_GlassWorkshop_EventScript_NoRoomForDecor::
	call Common_EventScript_NoRoomForDecor
	msgbox Route113_GlassWorkshop_Text_NoRoomInPC, MSGBOX_DEFAULT
	release
	end

Route113_GlassWorkshop_EventScript_GiveItemAfterNoRoom::
	switch VAR_GLASS_WORKSHOP_STATE
	case 10, Route113_GlassWorkshop_EventScript_GiveBlueFlute
	case 11, Route113_GlassWorkshop_EventScript_GiveYellowFlute
	case 12, Route113_GlassWorkshop_EventScript_GiveRedFlute
	case 13, Route113_GlassWorkshop_EventScript_GiveWhiteFlute
	case 14, Route113_GlassWorkshop_EventScript_GiveBlackFlute
	case 15, Route113_GlassWorkshop_EventScript_GivePrettyChair
	case 16, Route113_GlassWorkshop_EventScript_GivePrettyDesk
	end

Route113_GlassWorkshop_EventScript_GiveBlueFlute::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_BLUE_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

Route113_GlassWorkshop_EventScript_GiveYellowFlute::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_YELLOW_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

Route113_GlassWorkshop_EventScript_GiveRedFlute::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_RED_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

Route113_GlassWorkshop_EventScript_GiveWhiteFlute::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_WHITE_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

Route113_GlassWorkshop_EventScript_GiveBlackFlute::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_BLACK_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

Route113_GlassWorkshop_EventScript_GivePrettyChair::
	setvar VAR_0x8009, 1
	setvar VAR_0x8008, DECOR_PRETTY_CHAIR
	bufferdecorationname STR_VAR_1, DECOR_PRETTY_CHAIR
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

Route113_GlassWorkshop_EventScript_GivePrettyDesk::
	setvar VAR_0x8009, 1
	setvar VAR_0x8008, DECOR_PRETTY_DESK
	bufferdecorationname STR_VAR_1, DECOR_PRETTY_DESK
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

Route113_GlassWorkshop_EventScript_TryGiveItemAgain::
	msgbox Route113_GlassWorkshop_Text_IveFinishedGlassItem, MSGBOX_DEFAULT
	call_if_eq VAR_0x8009, 0, Route113_GlassWorkshop_EventScript_GiveGlassFlute
	call_if_eq VAR_0x8009, 1, Route113_GlassWorkshop_EventScript_GiveGlassDecor
	setvar VAR_GLASS_WORKSHOP_STATE, 2
	release
	end

Route113_GlassWorkshop_EventScript_NinjaBoy::
	msgbox Route113_GlassWorkshop_Text_FunToBlowGlassFlute, MSGBOX_NPC
	end

Route113_GlassWorkshop_Text_GoCollectAshWithThis:
	.string "Esta regiao é coberta de cinzas,\n"
	.string "ufa!\p"
	.string "Tenho um talento especial, ufa.\n"
	.string "Transformo essas cinzas em vidro e\l"
	.string "faço objetos, ufa.\p"
	.string "Use isto pra juntar cinzas, ufa.$"

Route113_GlassWorkshop_Text_ExplainSootSack:
	.string "Leve essa Soot Sack e ande pelas\n"
	.string "pilhas de cinza, ufa.\p"
	.string "Ela vai juntar as cinzas do\n"
	.string "vulcao, ufa.\p"
	.string "Quando tiver bastante, volte aqui,\n"
	.string "ufa.$"

Route113_GlassWorkshop_Text_LetsSeeCollectedAshes:
	.string "Juntou cinzas, ufa? Deixa eu ver,\n"
	.string "ufa.$"

Route113_GlassWorkshop_Text_NotEnoughAshNeedX:
	.string "Hum... Ainda nao tem cinza\n"
	.string "suficiente pra fazer vidro, ufa.\p"
	.string "Você precisa andar {STR_VAR_1}\n"
	.string "passos pelas cinzas pra eu fazer\l"
	.string "uma Blue Flute, ufa.$"

Route113_GlassWorkshop_Text_WhichGlassItemWoudYouLike:
	.string "Ah! Você trouxe bastante cinza,\n"
	.string "ufa!\p"
	.string "Vou fazer um objeto de vidro pra\n"
	.string "você, ufa. Qual você quer?$"

Route113_GlassWorkshop_Text_IsThatTheItemForYou:
	.string "{STR_VAR_1}, ufa? É isso que\n"
	.string "você quer, ufa?$"

Route113_GlassWorkshop_Text_WhichWouldYouLike:
	.string "Qual você quer, ufa?$"

Route113_GlassWorkshop_Text_IllMakeItemForYou:
	.string "Entao vai ser {STR_VAR_1}, ufa!\p"
	.string "Vou preparar pra você. Espere um\n"
	.string "pouco, ufa.$"

Route113_GlassWorkshop_Text_NotEnoughAshToMakeItem:
	.string "{STR_VAR_1}, ufa?\p"
	.string "Ainda falta cinza pra fazer isso,\n"
	.string "ufa.\p"
	.string "Precisa andar {STR_VAR_2}\n"
	.string "passos pelas cinzas pra eu\l"
	.string "conseguir, ufa.\p"
	.string "Quer escolher outro objeto, ufa?$"

Route113_GlassWorkshop_Text_AllThatAshButDontWantAnything:
	.string "Juntou tudo isso de cinza e nao\n"
	.string "quer nada, ufa?$"

Route113_GlassWorkshop_Text_IveFinishedGlassItem:
	.string "Ah, terminei: {STR_VAR_1}. Pode\n"
	.string "pegar, ufa.$"

Route113_GlassWorkshop_Text_NoRoomInBag:
	.string "Opa, sua bolsa ta cheia, ufa.\p"
	.string "Vou guardar aqui. Volte depois,\n"
	.string "ufa.$"

Route113_GlassWorkshop_Text_NoRoomInPC:
	.string "Opa, seu PC ta cheio, ufa?\p"
	.string "Vou guardar aqui. Volte depois,\n"
	.string "ufa.$"

Route113_GlassWorkshop_Text_HaventGotYourSootSack:
	.string "Hein? Você nao trouxe sua Soot\n"
	.string "Sack, ufa.\p"
	.string "Precisa levar ela pra juntar\n"
	.string "cinzas, ufa.$"

Route113_GlassWorkshop_Text_FunToBlowGlassFlute:
	.string "É divertido tocar flauta de vidro\n"
	.string "enquanto meu chefe fala.\p"
	.string "Ufa, ufa! Fuu, fuu!$"

