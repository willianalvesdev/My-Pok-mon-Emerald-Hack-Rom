SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end

SlateportCity_House_Text_NatureToDoWithStatGains:
	.string "Meu Pokémon tem natureza Hasty.\p"
	.string "Ele tem mais Speed que os meus\n"
	.string "outros Pokémon.\p"
	.string "Talvez a natureza influencie o\n"
	.string "crescimento dos atributos.$"

SlateportCity_House_Text_MustBeGoingToBattleTent:
	.string "Você é treinador, né?\p"
	.string "Já que veio a Slateport City, deve\n"
	.string "estar indo pra Battle Tent.$"

