MysteryGiftScript_OldSeaMap::
	setvaddress MysteryGiftScript_OldSeaMap
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_OLD_SEA_MAP, OldSeaMap_Obtained
	vgoto_if_set FLAG_CAUGHT_MEW, OldSeaMap_Obtained
	checkitem ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, TRUE, OldSeaMap_Obtained
	vmessage sText_MysteryGiftOldSeaMapForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, FALSE, OldSeaMap_NoBagSpace
	giveitem ITEM_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	setflag FLAG_RECEIVED_OLD_SEA_MAP
	vmessage sText_MysteryGiftOldSeaMapUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_NoBagSpace:
	vmessage sText_MysteryGiftOldSeaMapBagFull
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_Obtained:
	vmessage sText_MysteryGiftOldSeaMapThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftOldSeaMapForYou:
	.string "Obrigado por usar o sistema\n"
	.string "Mystery Gift.\p"
	.string "Só pra confirmar: você é {PLAYER}?\p"
	.string "Recebemos este Old Sea Map no seu\n"
	.string "nome.$"

sText_MysteryGiftOldSeaMapUseAtPort:
	.string "Parece que pode ser usado no\n"
	.string "porto de Lilycove City.\p"
	.string "Por que nao vai lá descobrir?$"

sText_MysteryGiftOldSeaMapThankYou:
	.string "Obrigado por usar o sistema\n"
	.string "Mystery Gift.$"

sText_MysteryGiftOldSeaMapBagFull:
	.string "Desculpa, {PLAYER}. Seu bolso de\n"
	.string "itens importantes ta cheio.\p"
	.string "Guarde alguma coisa no PC e volte\n"
	.string "pra buscar isto.$"
