	.set APRICORNS_PER_BALL, 10

Route131_ApricornWorkshop_MapScripts::
	.byte 0

Route131_ApricornWorkshop_EventScript_Crafter::
	lock
	faceplayer
	message ApricornWorkshop_Text_ChooseBall
	waitmessage
	multichoicegrid 1, 1, MULTI_APRICORN_BALLS, 2, FALSE
	switch VAR_RESULT
	case 0, ApricornWorkshop_White
	case 1, ApricornWorkshop_Pink
	case 2, ApricornWorkshop_Red
	case 3, ApricornWorkshop_Blue
	case 4, ApricornWorkshop_Yellow
	case 5, ApricornWorkshop_Green
	case 6, ApricornWorkshop_Black
	goto ApricornWorkshop_End

	.macro apricorn_recipe apricorn:req, ball:req
	setvar VAR_0x8008, \apricorn
	setvar VAR_0x8009, \ball
	goto ApricornWorkshop_Offer
	.endm

ApricornWorkshop_White:
	apricorn_recipe ITEM_WHITE_APRICORN, ITEM_FAST_BALL

ApricornWorkshop_Pink:
	apricorn_recipe ITEM_PINK_APRICORN, ITEM_LOVE_BALL

ApricornWorkshop_Red:
	apricorn_recipe ITEM_RED_APRICORN, ITEM_LEVEL_BALL

ApricornWorkshop_Blue:
	apricorn_recipe ITEM_BLUE_APRICORN, ITEM_LURE_BALL

ApricornWorkshop_Yellow:
	apricorn_recipe ITEM_YELLOW_APRICORN, ITEM_MOON_BALL

ApricornWorkshop_Green:
	apricorn_recipe ITEM_GREEN_APRICORN, ITEM_FRIEND_BALL

ApricornWorkshop_Black:
	apricorn_recipe ITEM_BLACK_APRICORN, ITEM_HEAVY_BALL

	.purgem apricorn_recipe

ApricornWorkshop_Offer:
	bufferitemname STR_VAR_1, VAR_0x8008
	bufferitemname STR_VAR_2, VAR_0x8009
	checkitem VAR_0x8008, APRICORNS_PER_BALL
	goto_if_eq VAR_RESULT, FALSE, ApricornWorkshop_NotEnough
	msgbox ApricornWorkshop_Text_Confirm, MSGBOX_YESNO
	goto_if_ne VAR_RESULT, YES, ApricornWorkshop_End
	additem VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem VAR_0x8008, APRICORNS_PER_BALL
	goto_if_eq VAR_RESULT, FALSE, ApricornWorkshop_UndoBall
	playse SE_SHOP
	msgbox ApricornWorkshop_Text_Done, MSGBOX_DEFAULT
	goto ApricornWorkshop_End

ApricornWorkshop_UndoBall:
	removeitem VAR_0x8009

ApricornWorkshop_NotEnough:
	msgbox ApricornWorkshop_Text_NotEnough, MSGBOX_DEFAULT

ApricornWorkshop_End:
	release
	end

ApricornWorkshop_Text_ChooseBall:
	.string "Faço Poké Balls com Apricorns!\p"
	.string "Cada bola custa 10 da mesma cor.\n"
	.string "Qual você quer?$"

ApricornWorkshop_Text_Confirm:
	.string "Usar 10 {STR_VAR_1}\n"
	.string "para fazer uma {STR_VAR_2}?$"

ApricornWorkshop_Text_NotEnough:
	.string "Para essa bola, preciso de 10\n"
	.string "{STR_VAR_1}.$"

ApricornWorkshop_Text_Done:
	.string "Pronto! Aqui está sua {STR_VAR_2}.$"
