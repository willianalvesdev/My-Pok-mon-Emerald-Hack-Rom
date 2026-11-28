MysteryGiftScript_AuroraTicket::
	setvaddress MysteryGiftScript_AuroraTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_AURORA_TICKET, AuroraTicket_Obtained
	vgoto_if_set FLAG_BATTLED_DEOXYS, AuroraTicket_Obtained
	checkitem ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, AuroraTicket_Obtained
	vmessage sText_AuroraTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, AuroraTicket_NoBagSpace
	giveitem ITEM_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_AURORA_TICKET
	vmessage sText_AuroraTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_NoBagSpace:
	vmessage sText_AuroraTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_Obtained:
	vmessage sText_AuroraTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_AuroraTicketForYou:
	.string "Obrigado por usar o sistema\n"
	.string "Mystery Gift.\p"
	.string "Você deve ser {PLAYER}. Temos um\n"
	.string "Ticket pra você.$"

sText_AuroraTicketUseAtPort:
	.string "Parece que pode ser usado no\n"
	.string "porto de Lilycove City.\p"
	.string "Por que nao vai lá descobrir?$"

sText_AuroraTicketThankYou:
	.string "Obrigado por usar o sistema\n"
	.string "Mystery Gift.$"

sText_AuroraTicketBagFull:
	.string "Desculpa, {PLAYER}. Seu bolso de\n"
	.string "itens importantes ta cheio.\p"
	.string "Guarde alguma coisa no PC e volte\n"
	.string "pra buscar isto.$"
