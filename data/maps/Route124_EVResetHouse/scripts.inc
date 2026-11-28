Route124_EVResetHouse_MapScripts::
	.byte 0

Route124_EVResetHouse_EventScript_Scientist::
	lock
	faceplayer
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, 0, Route124_EVResetHouse_NoPokemon
	msgbox Route124_EVResetHouse_Text_Offer, MSGBOX_YESNO
	goto_if_ne VAR_RESULT, YES, Route124_EVResetHouse_Cancel
	msgbox Route124_EVResetHouse_Text_Choose, MSGBOX_DEFAULT
	special ChoosePartyMon
	goto_if_ge VAR_0x8004, PARTY_SIZE, Route124_EVResetHouse_Cancel
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, Route124_EVResetHouse_Egg
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	msgbox Route124_EVResetHouse_Text_Confirm, MSGBOX_YESNO
	goto_if_ne VAR_RESULT, YES, Route124_EVResetHouse_Cancel
	specialvar VAR_RESULT, Script_ResetChosenMonEVs
	goto_if_eq VAR_RESULT, FALSE, Route124_EVResetHouse_NoPokemon
	msgbox Route124_EVResetHouse_Text_Done, MSGBOX_DEFAULT
	release
	end

Route124_EVResetHouse_Cancel:
	msgbox Route124_EVResetHouse_Text_Cancel, MSGBOX_DEFAULT
	release
	end

Route124_EVResetHouse_NoPokemon:
	msgbox Route124_EVResetHouse_Text_NoPokemon, MSGBOX_DEFAULT
	release
	end

Route124_EVResetHouse_Egg:
	msgbox Route124_EVResetHouse_Text_Egg, MSGBOX_DEFAULT
	release
	end

Route124_EVResetHouse_Text_Offer:
	.string "Posso zerar todos os EVs de um\n"
	.string "Pokémon do seu time. Quer fazer\l"
	.string "isso agora?$"

Route124_EVResetHouse_Text_Choose:
	.string "Escolha um Pokémon do seu time.$"

Route124_EVResetHouse_Text_Confirm:
	.string "Quer zerar todos os EVs de\n"
	.string "{STR_VAR_1}?$"

Route124_EVResetHouse_Text_Done:
	.string "Pronto! Zerei os EVs dos seis\n"
	.string "atributos de {STR_VAR_1}.$"

Route124_EVResetHouse_Text_Cancel:
	.string "Pode voltar quando quiser.$"

Route124_EVResetHouse_Text_NoPokemon:
	.string "Traga um Pokémon do seu time.$"

Route124_EVResetHouse_Text_Egg:
	.string "Ovo ainda nao pode treinar.$"
