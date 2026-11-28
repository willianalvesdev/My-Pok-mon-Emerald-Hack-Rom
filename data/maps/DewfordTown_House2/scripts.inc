DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf::
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf::
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy::
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf:
	.string "Olha só isso!\p"
	.string "É um SILK SCARF. Ta no auge da\n"
	.string "moda!\p"
	.string "Ah, seus olhos brilharam! Você\n"
	.string "reconhece meu estilo!\p"
	.string "Gostei de você! Tome, quero que\n"
	.string "fique com ele!$"

DewfordTown_House2_Text_NoRoom:
	.string "Ah, ta sem espaço?\p"
	.string "Escuta bem, esse SCARF nao pode\n"
	.string "faltar! Eu venderia todos os meus\l"
	.string "itens pra conseguir um!$"

DewfordTown_House2_Text_ExplainSilkScarf:
	.string "O SILK SCARF aumenta a força dos\n"
	.string "golpes do tipo Normal.\p"
	.string "É um SCARF maravilhoso, combina\n"
	.string "com quase todo POKÉMON!$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "Nossa, você atravessou o mar pra\n"
	.string "visitar DEWFORD?\p"
	.string "Veio porque ouviu falar do BRAWLY?\p"
	.string "Ele é tao legal... Todo mundo\n"
	.string "admira ele.$"

