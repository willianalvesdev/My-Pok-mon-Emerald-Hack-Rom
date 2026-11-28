SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	chooseboxmon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "Oi! Sou o Name Rater! Sei tudo\n"
	.string "sobre nomes!\p"
	.string "Vou gostar de avaliar o apelido do\n"
	.string "seu Pokémon.$"

SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "Qual Pokémon vai ter o apelido\n"
	.string "avaliado?$"

SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "Hum... {STR_VAR_1}, é? É um bom\n"
	.string "nome.\p"
	.string "Mas oque acha se eu sugerir um um\n"
	.string "pouco melhor?$"

SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "Ah, ótimo. Qual vai ser o novo\n"
	.string "apelido?$"

SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "Pronto! De agora em diante, este\n"
	.string "Pokémon vai se chamar\l"
	.string "{STR_VAR_1}!\p"
	.string "Ficou melhor que antes! Que sorte\n"
	.string "a sua!$"

SlateportCity_NameRatersHouse_Text_DoVisitAgain:
	.string "Entendo. Volte outra hora.$"

SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "Pronto! De agora em diante, este\n"
	.string "Pokémon vai se chamar\l"
	.string "{STR_VAR_1}!\p"
	.string "Parece igual, mas ficou muito\n"
	.string "melhor!\p"
	.string "Que sorte a sua!$"

SlateportCity_NameRatersHouse_Text_MagnificentName:
	.string "Hum... {STR_VAR_1}!\p"
	.string "Que apelido maravilhoso! Nao tem\n"
	.string "oque melhorar!\p"
	.string "Cuide bem de {STR_VAR_1}, agora\n"
	.string "e sempre.$"

SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "Calma aí. Isso é só um ovo!$"

