MossdeepCity_Mart_MapScripts::
	.byte 0

MossdeepCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MossdeepCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MossdeepCity_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	pokemartlistend

MossdeepCity_Mart_EventScript_Woman::
	msgbox MossdeepCity_Mart_Text_ReviveIsFantastic, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Boy::
	msgbox MossdeepCity_Mart_Text_MaxRepelLastsLongest, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Sailor::
	msgbox MossdeepCity_Mart_Text_NetAndDiveBallsRare, MSGBOX_NPC
	end

MossdeepCity_Mart_Text_ReviveIsFantastic:
	.string "Revive é ótimo!\p"
	.string "Use num Pokémon desmaiado pra ele\n"
	.string "acordar.\p"
	.string "Mas cuidado: Revive nao recupera\n"
	.string "os PP dos golpes.$"

MossdeepCity_Mart_Text_MaxRepelLastsLongest:
	.string "Max Repel afasta os Pokémon\n"
	.string "fracos.\p"
	.string "É o repelente que dura mais tempo.$"

MossdeepCity_Mart_Text_NetAndDiveBallsRare:
	.string "Net Ball e Dive Ball sao Poké\n"
	.string "Balls raras fabricadas em\l"
	.string "Mossdeep.\p"
	.string "A Net Ball funciona bem com\n"
	.string "Pokémon dos tipos Bug e Water.\p"
	.string "A Dive Ball funciona melhor no\n"
	.string "fundo do mar.$"

