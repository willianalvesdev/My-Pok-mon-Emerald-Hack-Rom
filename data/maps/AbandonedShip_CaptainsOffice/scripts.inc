AbandonedShip_CaptainsOffice_MapScripts::
	.byte 0

AbandonedShip_CaptainsOffice_EventScript_CaptSternAide::
	lock
	faceplayer
	goto_if_set FLAG_EXCHANGED_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner
	goto_if_set FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_2_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	msgbox AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner::
	msgbox AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus::
	msgbox AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner:
	.string "To investigando este navio em nome\n"
	.string "do CAPT STERN.\p"
	.string "Ele também me pediu para encontrar\n"
	.string "um tal de SCANNER, mas eu nao\l"
	.string "consegui achar...$"

AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner:
	.string "É um Scanner!\p"
	.string "Ei, pode entregar isso aqui ao\n"
	.string "CAPT STERN.?\p"
	.string "Quero investigar melhor este navio.$"

AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus:
	.string "Este navio chama S.S. CACTUS.\n"
	.string "Parece ser bem antigo.$"

