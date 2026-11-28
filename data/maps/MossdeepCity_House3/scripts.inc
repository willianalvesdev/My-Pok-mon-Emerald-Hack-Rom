MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_ReceivedSuperRod
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_House3_EventScript_DeclineSuperRod
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox MossdeepCity_House3_Text_TryDroppingRodInWater, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_ReceivedSuperRod::
	msgbox MossdeepCity_House3_Text_GoAfterSeafloorPokemon, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_DeclineSuperRod::
	msgbox MossdeepCity_House3_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_YouWantSuperRod:
	.string "Ei, treinador! A Super Rod é super\n"
	.string "de verdade!\p"
	.string "Essa belezinha pesca até Pokémon\n"
	.string "lá do fundo do mar!\p"
	.string "Oque acha? Você quer, né?$"

MossdeepCity_House3_Text_SuperRodIsSuper:
	.string "Pode acreditar! A Super Rod é\n"
	.string "super mesmo!$"

MossdeepCity_House3_Text_TryDroppingRodInWater:
	.string "Se encontrar água, joga a vara e\n"
	.string "vê oque aparece!$"

MossdeepCity_House3_Text_DontYouLikeToFish:
	.string "Hein? Você nao gosta de pescar?$"

MossdeepCity_House3_Text_GoAfterSeafloorPokemon:
	.string "Use sua Super Rod pra pescar\n"
	.string "Pokémon do fundo do mar.$"

