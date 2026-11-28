SootopolisCity_LotadAndSeedotHouse_MapScripts::
	.byte 0

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotBrother::
	special GetSeedotSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot, MSGBOX_DEFAULT
	setvar VAR_0x8009, SPECIES_SEEDOT
	chooseboxmon SELECT_PC_MON_TRADE
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot
	special CompareSeedotSize
	goto_if_eq VAR_RESULT, COMPARE_SIZE_INCORRECT_SPECIES, SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot
	goto_if_eq VAR_RESULT, COMPARE_SIZE_SMALLER, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot
	goto_if_eq VAR_RESULT, COMPARE_SIZE_LARGER, SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadBrother::
	special GetLotadSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad, MSGBOX_DEFAULT
	setvar VAR_0x8009, SPECIES_LOTAD
	chooseboxmon SELECT_PC_MON_TRADE
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad
	special CompareLotadSize
	goto_if_eq VAR_RESULT, COMPARE_SIZE_INCORRECT_SPECIES, SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad
	goto_if_eq VAR_RESULT, COMPARE_SIZE_SMALLER, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad
	goto_if_eq VAR_RESULT, COMPARE_SIZE_LARGER, SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotSizeRecord::
	special GetSeedotSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadSizeRecord::
	special GetLotadSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot:
	.string "Conhece Seedot? Quase nao aparece\n"
	.string "em Sootopolis.\p"
	.string "Adoro Seedot grandes. Quanto\n"
	.string "maior, melhor!\p"
	.string "Mas meu irmao diz que Lotad é\n"
	.string "maior. Que bobagem! Seedot tem que\l"
	.string "ser maior!\p"
	.string "Hein? Você tem um Seedot? P-por\n"
	.string "favor, mostra!$"

SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad:
	.string "{STR_VAR_2}! Nossa, esse é\n"
	.string "grande!\p"
	.string "Talvez seja maior que o Lotad\n"
	.string "enorme que meu irmao viu!\p"
	.string "Obrigado por mostrar. Aceite isto!$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion1:
	.string "{PLAYER} recebeu uma Potion.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1:
	.string "Hein? Sua bolsa ta cheia.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot:
	.string "{STR_VAR_2}, é?\p"
	.string "Hum... Já vi Seedot maior que\n"
	.string "esse.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot:
	.string "Ah, esse é interessante... Mas nao\n"
	.string "é um Seedot!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot:
	.string "Nao tem um Seedot grande? Que\n"
	.string "pena...\p"
	.string "Se encontrar um, venha me mostrar.$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory:
	.string "O maior Seedot da história! O\n"
	.string "gigante de {STR_VAR_2}, medindo\l"
	.string "{STR_VAR_3}!\p"
	.string "Sempre quis um Seedot maior que um\n"
	.string "Lotad!$"

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad:
	.string "Conhece Lotad? Ele é raro em\n"
	.string "Sootopolis.\p"
	.string "Adoro, adoro mesmo, Lotad grandes!\p"
	.string "Meu irmao diz que Seedot é maior.\n"
	.string "Mas ta errado! Todo mundo sabe\l"
	.string "que Lotad é bem maior.\p"
	.string "Hein? Você tem um Lotad? P-por\n"
	.string "favor, mostra!$"

SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot:
	.string "{STR_VAR_2}! Nossa, como é\n"
	.string "grande!\p"
	.string "Talvez seja maior que o Seedot\n"
	.string "enorme que meu irmao viu.\p"
	.string "Obrigado por mostrar! Aceite isto!$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion2:
	.string "{PLAYER} recebeu uma Potion.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2:
	.string "Hein? Sua bolsa ta cheia.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad:
	.string "{STR_VAR_2}?\p"
	.string "Hum... Já vi Lotad maior que esse.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad:
	.string "Olha só, interessante! Mas nao é\n"
	.string "um Lotad!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad:
	.string "Nao tem um Lotad grande? Que\n"
	.string "pena...\p"
	.string "Se encontrar um, venha me mostrar!$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory:
	.string "O maior Lotad da história! O\n"
	.string "gigante de {STR_VAR_2}, medindo\l"
	.string "{STR_VAR_3}!\p"
	.string "Sempre quis um Lotad maior que um\n"
	.string "Seedot!$"

