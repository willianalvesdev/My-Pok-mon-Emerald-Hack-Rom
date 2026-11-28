Route111_Text_MakingRoomUseTMToMakeYourOwn:
	.string "Oque eu tô fazendo?\p"
	.string "Pensando em usar um golpe Pokémon\n"
	.string "pra criar meu próprio quarto aqui.\p"
	.string "Já sei! Vou dar esta TM pra você.\n"
	.string "Quer fazer um quarto também?$"

Route111_Text_ExplainSecretPower:
	.string "Procure uma árvore grande com\n"
	.string "cipós e use Secret Power na frente\l"
	.string "dela.\p"
	.string "Os cipós vao cair e você vai\n"
	.string "conseguir subir.\p"
	.string "Lá dentro tem espaço pra colocar\n"
	.string "suas coisas favoritas. Vai ser seu\l"
	.string "quarto secreto, uma base secreta!\p"
	.string "Faça uma também. Nao precisa ser\n"
	.string "numa árvore. Experimente usar\l"
	.string "Secret Power em pequenas marcas\l"
	.string "nas paredes de pedra.\p"
	.string "Vou procurar outros lugares. Até\n"
	.string "mais!$"

Route111_Text_DontWantThis:
	.string "Ah, nao quer? Se mudar de ideia,\n"
	.string "me avise, ta?$"

Route111_Text_DontHaveAnyRoom:
	.string "Você nao tem espaço pra isto.\p"
	.string "Vou guardar aqui. Volte depois pra\n"
	.string "pegar, ta?$"

Route111_EventScript_SecretPowerMan::
	lock
	faceplayer
	msgbox Route111_Text_MakingRoomUseTMToMakeYourOwn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_GiveSecretPower
	msgbox Route111_Text_DontWantThis, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_GiveSecretPower::
	giveitem ITEM_TM_SECRET_POWER
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_NoRoomForSecretPower
	msgbox Route111_Text_ExplainSecretPower, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	clearflag FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN
	call_if_eq VAR_FACING, DIR_WEST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_EAST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_NORTH, Route111_EventScript_SecretPowerManExitNorth
	removeobject VAR_LAST_TALKED
	release
	end

Route111_EventScript_SecretPowerManExit::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExit
	waitmovement 0
	return

Route111_EventScript_SecretPowerManExitNorth::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExitNorth
	waitmovement 0
	return

Route111_EventScript_NoRoomForSecretPower::
	msgbox Route111_Text_DontHaveAnyRoom, MSGBOX_DEFAULT
	release
	end

Route111_Movement_SecretPowerManExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route111_Movement_SecretPowerManExitNorth:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end
