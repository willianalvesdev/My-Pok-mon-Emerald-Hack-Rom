MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash::
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
	.string "Uhuu!\p"
	.string "Me chamam de cara do Rock Smash,\n"
	.string "mas acho meio sem graça.\p"
	.string "Eu mereço um título melhor. Mestre\n"
	.string "Supremo do Rock Smash já serve.\p"
	.string "Uhuu! Seus Pokémon parecem\n"
	.string "fortes! Gostei!\p"
	.string "Toma esta HM!$"

MauvilleCity_House1_Text_ExplainRockSmash:
	.string "Essa HM tem Rock Smash.\p"
	.string "Se encontrar pedras bloqueando o\n"
	.string "caminho, use esse golpe pra\l"
	.string "quebrar elas!\p"
	.string "É isso aí! Pode quebrar sem medo!\n"
	.string "Uhuu!$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
	.string "Ah, quando você quebra uma pedra,\n"
	.string "pode aparecer um Pokémon escondido\l"
	.string "nela.\p"
	.string "Uhuu!$"

