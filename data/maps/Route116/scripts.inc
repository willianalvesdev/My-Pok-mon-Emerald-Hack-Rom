Route116_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route116_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route116_OnFrame
	.byte 0

Route116_OnTransition:
	call_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_SetWandasBoyfriendPos
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_NORTH, AbnormalWeather_StartGroudonWeather
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_SOUTH, AbnormalWeather_StartGroudonWeather
	end

Route116_EventScript_SetWandasBoyfriendPos::
	setobjectxyperm LOCALID_ROUTE116_WANDAS_BF, 38, 10
	return

Route116_OnLoad:
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_NORTH, AbnormalWeather_EventScript_PlaceTilesRoute116North
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_SOUTH, AbnormalWeather_EventScript_PlaceTilesRoute116South
	end

Route116_OnFrame:
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route116_EventScript_WandasBoyfriend::
	lock
	faceplayer
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_BoyfriendGruntLeftTunnel
	goto_if_set FLAG_DEVON_GOODS_STOLEN, Route116_EventScript_BoyfriendGruntInTunnel
	msgbox Route116_Text_WantToDigTunnel, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_BoyfriendGruntLeftTunnel::
	msgbox Route116_Text_GoonHightailedItOutOfTunnel, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_BoyfriendGruntInTunnel::
	msgbox Route116_Text_DiggingTunnelWhenGoonOrderedMeOut, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_DevonEmployee::
	lock
	faceplayer
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, Route116_EventScript_TryGiveRepeatBallAgain
	msgbox Route116_Text_ThankYouTokenOfAppreciation, MSGBOX_DEFAULT
	goto Route116_EventScript_GiveRepeatBall
	end

Route116_EventScript_GiveRepeatBall::
	setflag FLAG_MET_DEVON_EMPLOYEE
	giveitem ITEM_REPEAT_BALL
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_NoRoomForRepeatBall
	msgbox Route116_Text_NewBallAvailableAtMart, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, Route116_EventScript_DevonEmployeeExit
	call_if_eq VAR_FACING, DIR_SOUTH, Route116_EventScript_DevonEmployeeExit
	call_if_eq VAR_FACING, DIR_WEST, Route116_EventScript_DevonEmployeeExit
	call_if_eq VAR_FACING, DIR_EAST, Route116_EventScript_DevonEmployeeExitEast
	removeobject VAR_LAST_TALKED
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setflag FLAG_RECEIVED_REPEAT_BALL
	release
	end

Route116_EventScript_DevonEmployeeExit::
	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExit
	waitmovement 0
	return

Route116_EventScript_DevonEmployeeExitEast::
	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExitEast
	waitmovement 0
	return

Route116_EventScript_TryGiveRepeatBallAgain::
	msgbox Route116_Text_TokenOfAppreciation, MSGBOX_DEFAULT
	goto Route116_EventScript_GiveRepeatBall
	end

Route116_EventScript_NoRoomForRepeatBall::
	msgbox Route116_Text_BagIsJamPacked, MSGBOX_DEFAULT
	release
	end

Route116_Movement_DevonEmployeeExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route116_Movement_DevonEmployeeExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route116_EventScript_RouteSignRustboro::
	msgbox Route116_Text_RouteSignRustboro, MSGBOX_SIGN
	end

Route116_EventScript_RusturfTunnelSign::
	msgbox Route116_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

Route116_EventScript_TunnelersRestHouseSign::
	msgbox Route116_Text_TunnelersRestHouse, MSGBOX_SIGN
	end

Route116_EventScript_TrainerTipsBToStopEvolution::
	msgbox Route116_Text_TrainerTipsBToStopEvolution, MSGBOX_SIGN
	end

Route116_EventScript_TrainerTipsBagHasPockets::
	msgbox Route116_Text_TrainerTipsBagHasPockets, MSGBOX_SIGN
	end

Route116_EventScript_Briney::
	lock
	faceplayer
	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
	setvar VAR_ROUTE116_STATE, 2
	release
	end

Route116_EventScript_BrineyTrigger::
	lockall
	applymovement LOCALID_ROUTE116_BRINEY, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
	setvar VAR_ROUTE116_STATE, 2
	releaseall
	end

Route116_EventScript_GlassesMan::
	lock
	faceplayer
	checkitem ITEM_BLACK_GLASSES
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_PlayerHasGlasses
	specialvar VAR_RESULT, FoundBlackGlasses
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_FoundGlassesNotOnPlayer
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_FoundGlassesNotOnPlayer::
	msgbox Route116_Text_CantFindGlassesNotHere, MSGBOX_DEFAULT
	closemessage
	goto Route116_EventScript_GlassesManExit
	end

Route116_EventScript_PlayerHasGlasses::
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
	msgbox Route116_Text_MayISeeThoseGlasses, MSGBOX_DEFAULT
	specialvar VAR_RESULT, FoundBlackGlasses
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_FoundGlassesOnPlayer
	msgbox Route116_Text_NotWhatImLookingFor, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_FoundGlassesOnPlayer::
	msgbox Route116_Text_NotWhatImLookingForMaybeTheyArentHere, MSGBOX_DEFAULT
	closemessage
	goto Route116_EventScript_GlassesManExit
	end

Route116_EventScript_GlassesManExit::
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, Route116_EventScript_GlassesManExitNormal
	call_if_eq VAR_FACING, DIR_SOUTH, Route116_EventScript_GlassesManExitNormal
	call_if_eq VAR_FACING, DIR_WEST, Route116_EventScript_GlassesManExitNormal
	call_if_eq VAR_FACING, DIR_EAST, Route116_EventScript_GlassesManExitEast
	removeobject VAR_LAST_TALKED
	release
	end

Route116_EventScript_GlassesManExitNormal::
	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExit
	waitmovement 0
	return

Route116_EventScript_GlassesManExitEast::
	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExitEast
	waitmovement 0
	return

Route116_Movement_GlassesManExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route116_Movement_GlassesManExitEast:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route116_EventScript_Joey::
	trainerbattle_single TRAINER_JOEY, Route116_Text_JoeyIntro, Route116_Text_JoeyDefeat
	msgbox Route116_Text_JoeyPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Jose::
	trainerbattle_single TRAINER_JOSE, Route116_Text_JoseIntro, Route116_Text_JoseDefeat
	msgbox Route116_Text_JosePostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Jerry::
	trainerbattle_single TRAINER_JERRY_1, Route116_Text_JerryIntro, Route116_Text_JerryDefeat, Route116_EventScript_TryRegisterJerryAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_RematchJerry
	setvar VAR_0x8004, TRAINER_JERRY_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_TryRegisterJerry
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_TryRegisterJerryAfterBattle::
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerryAfterBattle
	release
	end

Route116_EventScript_RegisterJerryAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route116_Text_JerryRegister2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JERRY_1
	release
	end

Route116_EventScript_TryRegisterJerry::
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerry
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_RegisterJerry::
	msgbox Route116_Text_JerryRegister1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JERRY_1
	release
	end

Route116_EventScript_RematchJerry::
	trainerbattle_rematch TRAINER_JERRY_1, Route116_Text_JerryRematchIntro, Route116_Text_JerryRematchDefeat
	msgbox Route116_Text_JerryPostRematch, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Clark::
	trainerbattle_single TRAINER_CLARK, Route116_Text_ClarkIntro, Route116_Text_ClarkDefeat
	msgbox Route116_Text_ClarkPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Janice::
	trainerbattle_single TRAINER_JANICE, Route116_Text_JaniceIntro, Route116_Text_JaniceDefeat
	msgbox Route116_Text_JanicePostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Karen::
	trainerbattle_single TRAINER_KAREN_1, Route116_Text_KarenIntro, Route116_Text_KarenDefeat, Route116_EventScript_TryRegisterKarenAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_RematchKaren
	setvar VAR_0x8004, TRAINER_KAREN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_TryRegisterKaren
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_TryRegisterKarenAfterBattle::
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKarenAfterBattle
	release
	end

Route116_EventScript_RegisterKarenAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route116_Text_KarenRegister2, MSGBOX_DEFAULT
	register_matchcall TRAINER_KAREN_1
	release
	end

Route116_EventScript_TryRegisterKaren::
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKaren
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_RegisterKaren::
	msgbox Route116_Text_KarenRegister1, MSGBOX_DEFAULT
	register_matchcall TRAINER_KAREN_1
	release
	end

Route116_EventScript_RematchKaren::
	trainerbattle_rematch TRAINER_KAREN_1, Route116_Text_KarenRematchIntro, Route116_Text_KarenRematchDefeat
	msgbox Route116_Text_KarenPostRematch, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Sarah::
	trainerbattle_single TRAINER_SARAH, Route116_Text_SarahIntro, Route116_Text_SarahDefeat
	msgbox Route116_Text_SarahPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Dawson::
	trainerbattle_single TRAINER_DAWSON, Route116_Text_DawsonIntro, Route116_Text_DawsonDefeat
	msgbox Route116_Text_DawsonPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Devan::
	trainerbattle_single TRAINER_DEVAN, Route116_Text_DevanIntro, Route116_Text_DevanDefeat
	msgbox Route116_Text_DevanPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Johnson::
	trainerbattle_single TRAINER_JOHNSON, Route116_Text_JohnsonIntro, Route116_Text_JohnsonDefeat
	msgbox Route116_Text_JohnsonPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_Text_ScoundrelMadeOffWithPeeko:
	.string "Ah, oque eu faço?\p"
	.string "Eu e Peeko estávamos caminhando\n"
	.string "quando um bandido estranho atacou\l"
	.string "a gente...\p"
	.string "Ele levou minha querida Peeko!\p"
	.string "Uroooooar! Peeko!$"

Route116_Text_WantToDigTunnel:
	.string "Nnn... Roar!\p"
	.string "Quero cavar esse túnel!$"

Route116_Text_DiggingTunnelWhenGoonOrderedMeOut:
	.string "Nnn... Roar! Oque ta acontecendo?\p"
	.string "Eu tava cavando sem ferramentas e\n"
	.string "um bandido mandou eu sair!\p"
	.string "Os Pokémon lá dentro nao gostam\n"
	.string "de barulho alto. Podem ficar\l"
	.string "agitados.\p"
	.string "Por isso paramos de usar máquinas\n"
	.string "pesadas.\p"
	.string "Tô preocupado que ele faça alguma\n"
	.string "besteira e assuste todos.$"

Route116_Text_GoonHightailedItOutOfTunnel:
	.string "Nnn... Roar!\p"
	.string "Aquele bandido saiu correndo do\n"
	.string "túnel! Posso voltar a cavar!$"

Route116_Text_ThankYouTokenOfAppreciation:
	.string "Ah, é você!\p"
	.string "Você me ajudou em Petalburg\n"
	.string "Woods, recuperou o pacote roubado\l"
	.string "e ainda entregou ele em Slateport!\p"
	.string "O capitao Stern já avisou que\n"
	.string "recebeu. Muito obrigado mesmo!\p"
	.string "Se eu fosse uma nuvem, ia chover\n"
	.string "agradecimentos em você!\p"
	.string "Tenho uma novidade: nossa empresa\n"
	.string "criou uma Poké Ball nova.\p"
	.string "Este é nosso presente pra um\n"
	.string "treinador tao incrível!$"

Route116_Text_NewBallAvailableAtMart:
	.string "Nossa Poké Ball nova vai estar à\n"
	.string "venda no mercado de Rustboro.\p"
	.string "Experimente usar! Obrigado e até\n"
	.string "mais!$"

Route116_Text_BagIsJamPacked:
	.string "Sua bolsa ta cheia. Nao consigo\n"
	.string "dar esta Repeat Ball.$"

Route116_Text_TokenOfAppreciation:
	.string "Pra agradecer pela entrega do\n"
	.string "pacote, tenho uma Poké Ball nova\l"
	.string "de presente pra você!$"

Route116_Text_CanYouHelpMeFindGlasses:
	.string "Perdi meus óculos... Pode me\n"
	.string "ajudar a encontrar?$"

Route116_Text_MayISeeThoseGlasses:
	.string "Esses óculos! Posso olhar um\n"
	.string "instante?$"

Route116_Text_NotWhatImLookingForMaybeTheyArentHere:
	.string "Hum... Sao BlackGlasses. Nao sao\n"
	.string "os que procuro...\p"
	.string "Talvez meus óculos nem estejam\n"
	.string "por aqui...$"

Route116_Text_CantFindGlassesNotHere:
	.string "Hum... Nao encontro meus óculos em\n"
	.string "lugar nenhum... Talvez nao estejam\l"
	.string "por aqui...$"

Route116_Text_NotWhatImLookingFor:
	.string "Hum... Sao BlackGlasses. Nao sao\n"
	.string "os que procuro...$"

Route116_Text_RouteSignRustboro:
	.string "Route 116 {LEFT_ARROW} Rustboro City$"

Route116_Text_RusturfTunnelSign:
	.string "Rusturf Tunnel\p"
	.string "“Ligando Rustboro e Verdanturf.\p"
	.string "A construçao do túnel foi\n"
	.string "cancelada.”$"

Route116_Text_TunnelersRestHouse:
	.string "Casa de descanso dos escavadores$"

Route116_Text_TrainerTipsBToStopEvolution:
	.string "DICAS DE TREINADOR\p"
	.string "Pra impedir uma evoluçao, aperte B\n"
	.string "enquanto ela acontece. O Pokémon\l"
	.string "se assusta e para de evoluir.\p"
	.string "Isso se chama cancelar uma\n"
	.string "evoluçao.$"

Route116_Text_TrainerTipsBagHasPockets:
	.string "DICAS DE TREINADOR\p"
	.string "Sua bolsa tem vários bolsos.\p"
	.string "Os itens vao automaticamente pro\n"
	.string "bolso certo.\p"
	.string "Todo treinador precisa de uma\n"
	.string "bolsa.$"

