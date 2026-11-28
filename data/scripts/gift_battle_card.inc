MysteryGiftScript_BattleCard::
	setvaddress MysteryGiftScript_BattleCard
	vgoto_if_set FLAG_MYSTERY_GIFT_DONE, MysteryGiftScript_BattleCardInfo
	setorcopyvar VAR_RESULT, GET_CARD_BATTLES_WON
	specialvar VAR_0x8008, GetMysteryGiftCardStat
	vgoto_if_ne VAR_0x8008, REQUIRED_CARD_BATTLES, MysteryGiftScript_BattleCardInfo
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard_WonPrize
	waitmessage
	waitbuttonpress
	giveitem ITEM_POTION
	release
	setflag FLAG_MYSTERY_GIFT_DONE
	end

MysteryGiftScript_BattleCardInfo:
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftBattleCountCard:
	.string "Obrigado por usar o sistema\n"
	.string "Mystery Gift.\p"
	.string "Seu Battle Count Card registra\n"
	.string "suas batalhas contra treinadores\l"
	.string "que têm o mesmo cartao.\p"
	.string "Procure essas pessoas e batalhe\n"
	.string "com elas.\p"
	.string "Você pode conferir a classificaçao\n"
	.string "geral nas notícias. Experimente!$"

sText_MysteryGiftBattleCountCard_WonPrize:
	.string "Obrigado por usar o sistema\n"
	.string "Mystery Gift.\p"
	.string "Parabéns! Você ganhou um prêmio\n"
	.string "por vencer três batalhas!\p"
	.string "Esperamos que isso anime você a\n"
	.string "continuar batalhando.$"
