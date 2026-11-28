Aide_EventScript_HaventCaughtEnough::
	msgbox Aide_Text_HaventCaughtEnoughMonsForItem
	release
	end

Aide_EventScript_NoRoomForItem::
	msgbox Aide_Text_DontHaveAnyRoomForItem
	release
	end

Aide_EventScript_DeclineCheckMons::
	msgbox Aide_Text_GetEnoughMonsComeBackForItem
	release
	end

Aide_Text_HaventCaughtEnoughMonsForItem::
	.string "Vamos ver... Opa! Você só capturou\n"
	.string "{STR_VAR_3} espécies!\p"
	.string "Precisa de {STR_VAR_1} pra\n"
	.string "conseguir {STR_VAR_2}.$"

Aide_Text_GetEnoughMonsComeBackForItem::
	.string "Ah, entendi.\p"
	.string "Quando capturar {STR_VAR_1}\n"
	.string "espécies, volte pra buscar\l"
	.string "{STR_VAR_2}.$"

Aide_Text_DontHaveAnyRoomForItem::
	.string "Ah! Você nao tem espaço pra\n"
	.string "{STR_VAR_2}.$"
