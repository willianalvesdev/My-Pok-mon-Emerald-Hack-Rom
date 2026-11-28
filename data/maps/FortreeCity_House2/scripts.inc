FortreeCity_House2_MapScripts::
	.byte 0

FortreeCity_House2_EventScript_HiddenPowerGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_HIDDEN_POWER, FortreeCity_House2_EventScript_ExplainHiddenPower
	call_if_unset FLAG_MET_HIDDEN_POWER_GIVER, FortreeCity_House2_EventScript_Greeting
	msgbox FortreeCity_House2_Text_CoinInWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand2, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_YourHiddenPowerHasAwoken, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_HIDDEN_POWER
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_Greeting::
	msgbox FortreeCity_House2_Text_HiddenPowersArousedByNature, MSGBOX_DEFAULT
	setflag FLAG_MET_HIDDEN_POWER_GIVER
	return

FortreeCity_House2_EventScript_ExplainHiddenPower::
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_WrongGuess::
	msgbox FortreeCity_House2_Text_YouGuessedWrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_Text_HiddenPowersArousedByNature:
	.string "Pessoas... POKÉMONS...\p"
	.string "Viver junto da natureza desperta\n"
	.string "os poderes escondidos de cada\l"
	.string "um...$"

FortreeCity_House2_Text_CoinInWhichHand:
	.string "Deixe esta velha ver se seu poder\n"
	.string "escondido já despertou...\p"
	.string "Tenho uma moeda na mao.\p"
	.string "Agora me diga, ela ta na mao\n"
	.string "direita ou na esquerda?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand:
	.string "Ah! Acertou!\p"
	.string "Vamos tentar de novo.\p"
	.string "Em qual mao está a moeda? Direita\n"
	.string "ou esquerda?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand2:
	.string "Ah! Acertou!\p"
	.string "Vamos tentar de novo.\p"
	.string "Em qual mao está a moeda? Direita\n"
	.string "ou esquerda?$"

FortreeCity_House2_Text_YourHiddenPowerHasAwoken:
	.string "Ah, muito bem! Seu poder escondido\n"
	.string "despertou!\p"
	.string "Pegue isto e desperte o poder\n"
	.string "escondido dos seus POKÉMONS\l"
	.string "também.$"

FortreeCity_House2_Text_ExplainHiddenPower:
	.string "HIDDEN POWER é um golpe que muda\n"
	.string "de acordo com o POKÉMON.$"

FortreeCity_House2_Text_YouGuessedWrong:
	.string "Nao, que pena. Você errou.$"

