	.macro apricorn_shop item:req
	lock
	faceplayer
	message ApricornShop_Text_Welcome
	waitmessage
	pokemart 1f
	release
	end
	.align 2
1:
	.2byte \item
	pokemartlistend
	.endm

ApricornShop_EventScript_White::
	apricorn_shop ITEM_WHITE_APRICORN

ApricornShop_EventScript_Pink::
	apricorn_shop ITEM_PINK_APRICORN

ApricornShop_EventScript_Red::
	apricorn_shop ITEM_RED_APRICORN

ApricornShop_EventScript_Blue::
	apricorn_shop ITEM_BLUE_APRICORN

ApricornShop_EventScript_Yellow::
	apricorn_shop ITEM_YELLOW_APRICORN

ApricornShop_EventScript_Green::
	apricorn_shop ITEM_GREEN_APRICORN

ApricornShop_EventScript_Black::
	apricorn_shop ITEM_BLACK_APRICORN

	.purgem apricorn_shop

ApricornShop_Text_Welcome:
	.string "Tenho Apricorns por ¥50 cada.\n"
	.string "Pode comprar quantas quiser!$"
