EventScript_StartDexNavBattle::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	dowildbattle	
	release
	end

EventScript_NotFoundNearby::
	msgbox sText_NotFoundNearby, MSGBOX_SIGN
	end

EventScript_MovedTooFast::
	msgbox sText_TryMovingSlower, MSGBOX_SIGN
	end

EventScript_PokemonGotAway::
	msgbox sText_PokemonGotAway, MSGBOX_SIGN
	end

EventScript_LostSignal::
	msgbox sText_LostSignal, MSGBOX_SIGN
	end

EventScript_TooDark::
	msgbox sText_TooDark, MSGBOX_SIGN
	end

sText_NotFoundNearby:
	.string "Nao foi encontrado por perto.\n"
	.string "Procure em outra área!$"

sText_TryMovingSlower:
	.string "O Pokémon fugiu! Tente andar mais\n"
	.string "devagar.$"

sText_PokemonGotAway:
	.string "O Pokémon fugiu!$"

sText_LostSignal:
	.string "Nenhuma reaçao. O sinal foi\n"
	.string "perdido!$"

sText_TooDark:
	.string "Está escuro demais pra procurar\n"
	.string "Pokémon!$"
