StarterEggs_EventScript_HoennRustboro::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_STARTER_EGG_HOENN_RUSTBORO, StarterEggs_EventScript_AlreadyGiven
	setvar VAR_0x8005, 0
	call StarterEggs_EventScript_PickHoenn
	call StarterEggs_EventScript_Offer
	goto_if_ne VAR_RESULT, MON_GIVEN_TO_PARTY, StarterEggs_EventScript_End
	setflag FLAG_RECEIVED_STARTER_EGG_HOENN_RUSTBORO
	goto StarterEggs_EventScript_Received

StarterEggs_EventScript_HoennPacifidlog::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_STARTER_EGG_HOENN_PACIFIDLOG, StarterEggs_EventScript_AlreadyGiven
	setvar VAR_0x8005, 1
	call StarterEggs_EventScript_PickHoenn
	call StarterEggs_EventScript_Offer
	goto_if_ne VAR_RESULT, MON_GIVEN_TO_PARTY, StarterEggs_EventScript_End
	setflag FLAG_RECEIVED_STARTER_EGG_HOENN_PACIFIDLOG
	goto StarterEggs_EventScript_Received

StarterEggs_EventScript_JohtoFortree::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_STARTER_EGG_JOHTO_FORTREE, StarterEggs_EventScript_AlreadyGiven
	goto_if_lt VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, StarterEggs_EventScript_JohtoLocked
	setvar VAR_0x8005, 0
	call StarterEggs_EventScript_PickJohto
	call StarterEggs_EventScript_Offer
	goto_if_ne VAR_RESULT, MON_GIVEN_TO_PARTY, StarterEggs_EventScript_End
	setflag FLAG_RECEIVED_STARTER_EGG_JOHTO_FORTREE
	goto StarterEggs_EventScript_Received

StarterEggs_EventScript_JohtoMossdeep::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_STARTER_EGG_JOHTO_MOSSDEEP, StarterEggs_EventScript_AlreadyGiven
	goto_if_lt VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, StarterEggs_EventScript_JohtoLocked
	setvar VAR_0x8005, 1
	call StarterEggs_EventScript_PickJohto
	call StarterEggs_EventScript_Offer
	goto_if_ne VAR_RESULT, MON_GIVEN_TO_PARTY, StarterEggs_EventScript_End
	setflag FLAG_RECEIVED_STARTER_EGG_JOHTO_MOSSDEEP
	goto StarterEggs_EventScript_Received

StarterEggs_EventScript_KantoFallarbor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_STARTER_EGG_KANTO_FALLARBOR, StarterEggs_EventScript_AlreadyGiven
	setvar VAR_0x8004, SPECIES_BULBASAUR
	call StarterEggs_EventScript_Offer
	goto_if_ne VAR_RESULT, MON_GIVEN_TO_PARTY, StarterEggs_EventScript_End
	setflag FLAG_RECEIVED_STARTER_EGG_KANTO_FALLARBOR
	goto StarterEggs_EventScript_Received

StarterEggs_EventScript_KantoRoute123::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_STARTER_EGG_KANTO_ROUTE123, StarterEggs_EventScript_AlreadyGiven
	setvar VAR_0x8004, SPECIES_CHARMANDER
	call StarterEggs_EventScript_Offer
	goto_if_ne VAR_RESULT, MON_GIVEN_TO_PARTY, StarterEggs_EventScript_End
	setflag FLAG_RECEIVED_STARTER_EGG_KANTO_ROUTE123
	goto StarterEggs_EventScript_Received

StarterEggs_EventScript_KantoRoute124::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_STARTER_EGG_KANTO_ROUTE124, StarterEggs_EventScript_AlreadyGiven
	setvar VAR_0x8004, SPECIES_SQUIRTLE
	call StarterEggs_EventScript_Offer
	goto_if_ne VAR_RESULT, MON_GIVEN_TO_PARTY, StarterEggs_EventScript_End
	setflag FLAG_RECEIVED_STARTER_EGG_KANTO_ROUTE124
	goto StarterEggs_EventScript_Received

StarterEggs_EventScript_PickHoenn::
	copyvar VAR_0x8006, VAR_STARTER_MON
	goto_if_eq VAR_0x8006, 0, StarterEggs_EventScript_HoennFirst
	goto_if_eq VAR_0x8006, 1, StarterEggs_EventScript_HoennSecond
	goto StarterEggs_EventScript_HoennThird

StarterEggs_EventScript_HoennFirst:
	setvar VAR_0x8004, SPECIES_TORCHIC
	call_if_eq VAR_0x8005, 1, StarterEggs_EventScript_HoennFirstOther
	return

StarterEggs_EventScript_HoennFirstOther:
	setvar VAR_0x8004, SPECIES_MUDKIP
	return

StarterEggs_EventScript_HoennSecond:
	setvar VAR_0x8004, SPECIES_TREECKO
	call_if_eq VAR_0x8005, 1, StarterEggs_EventScript_HoennSecondOther
	return

StarterEggs_EventScript_HoennSecondOther:
	setvar VAR_0x8004, SPECIES_MUDKIP
	return

StarterEggs_EventScript_HoennThird:
	setvar VAR_0x8004, SPECIES_TREECKO
	call_if_eq VAR_0x8005, 1, StarterEggs_EventScript_HoennThirdOther
	return

StarterEggs_EventScript_HoennThirdOther:
	setvar VAR_0x8004, SPECIES_TORCHIC
	return

StarterEggs_EventScript_PickJohto::
	goto_if_eq VAR_GIFT_JOHTO_STARTER_SPECIES, SPECIES_CHIKORITA, StarterEggs_EventScript_JohtoFirst
	goto_if_eq VAR_GIFT_JOHTO_STARTER_SPECIES, SPECIES_CYNDAQUIL, StarterEggs_EventScript_JohtoSecond
	goto_if_eq VAR_GIFT_JOHTO_STARTER_SPECIES, SPECIES_TOTODILE, StarterEggs_EventScript_JohtoThird
	getcaughtmon SPECIES_CHIKORITA
	goto_if_eq VAR_RESULT, TRUE, StarterEggs_EventScript_JohtoFirst
	getcaughtmon SPECIES_CYNDAQUIL
	goto_if_eq VAR_RESULT, TRUE, StarterEggs_EventScript_JohtoSecond
	goto StarterEggs_EventScript_JohtoThird

StarterEggs_EventScript_JohtoFirst:
	setvar VAR_0x8004, SPECIES_CYNDAQUIL
	call_if_eq VAR_0x8005, 1, StarterEggs_EventScript_JohtoFirstOther
	return

StarterEggs_EventScript_JohtoFirstOther:
	setvar VAR_0x8004, SPECIES_TOTODILE
	return

StarterEggs_EventScript_JohtoSecond:
	setvar VAR_0x8004, SPECIES_CHIKORITA
	call_if_eq VAR_0x8005, 1, StarterEggs_EventScript_JohtoSecondOther
	return

StarterEggs_EventScript_JohtoSecondOther:
	setvar VAR_0x8004, SPECIES_TOTODILE
	return

StarterEggs_EventScript_JohtoThird:
	setvar VAR_0x8004, SPECIES_CHIKORITA
	call_if_eq VAR_0x8005, 1, StarterEggs_EventScript_JohtoThirdOther
	return

StarterEggs_EventScript_JohtoThirdOther:
	setvar VAR_0x8004, SPECIES_CYNDAQUIL
	return

StarterEggs_EventScript_Offer::
	msgbox StarterEggs_Text_Offer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, StarterEggs_EventScript_NotGiven
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, StarterEggs_EventScript_NoRoom
	giveegg VAR_0x8004
	return

StarterEggs_EventScript_NoRoom:
	msgbox StarterEggs_Text_NoRoom, MSGBOX_DEFAULT
StarterEggs_EventScript_NotGiven:
	setvar VAR_RESULT, MON_GIVEN_TO_PC
	return

StarterEggs_EventScript_Received:
	playfanfare MUS_OBTAIN_ITEM
	message StarterEggs_Text_Received
	waitmessage
	waitfanfare
	waitbuttonpress
	goto StarterEggs_EventScript_End

StarterEggs_EventScript_AlreadyGiven:
	msgbox StarterEggs_Text_AlreadyGiven, MSGBOX_DEFAULT
	goto StarterEggs_EventScript_End

StarterEggs_EventScript_JohtoLocked:
	msgbox StarterEggs_Text_JohtoLocked, MSGBOX_DEFAULT
StarterEggs_EventScript_End:
	release
	end

StarterEggs_Text_Offer:
	.string "Tenho um ovo de Pokémon para você.\n"
	.string "Quer levar?$"

StarterEggs_Text_NoRoom:
	.string "Volte com um espaço livre no time.$"

StarterEggs_Text_Received:
	.string "{PLAYER} recebeu um ovo de Pokémon!$"

StarterEggs_Text_AlreadyGiven:
	.string "Cuide bem do ovo que te dei!$"

StarterEggs_Text_JohtoLocked:
	.string "Volte depois de completar a Pokédex\n"
	.string "de Hoenn e escolher um inicial de\l"
	.string "Johto com o Professor Birch.$"
