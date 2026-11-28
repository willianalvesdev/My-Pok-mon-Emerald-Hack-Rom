RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_OnFrame
	.byte 0

RustboroCity_DevonCorp_3F_OnTransition:
	call_if_eq VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	end

RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
	setobjectxyperm LOCALID_DEVON_CORP_3F_EMPLOYEE, 3, 2
	setobjectmovementtype LOCALID_DEVON_CORP_3F_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_DevonCorp_3F_OnWarp:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
	turnobject LOCALID_PLAYER, DIR_EAST
	end

RustboroCity_DevonCorp_3F_OnFrame:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
	waitmovement 0
	delay 80
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 1
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_Movement_Unused:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk:
	delay_16
	walk_in_place_faster_down
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor:
	.string "Sou Mr. Stone, presidente da Devon\n"
	.string "Corporation.\p"
	.string "Acabei de ouvir falar de você!\n"
	.string "Salvou nossos funcionários duas\l"
	.string "vezes!\p"
	.string "Quero pedir um favor a alguém tao\n"
	.string "incrível.\p"
	.string "Sei que vai entregar um pacote no\n"
	.string "estaleiro de Slateport. Pode\l"
	.string "passar por Dewford Town no\l"
	.string "caminho?\p"
	.string "Queria que entregasse uma Letter\n"
	.string "ao Steven.$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
	.string "MR. STONE: Precisa saber que sou\n"
	.string "um bom presidente.\p"
	.string "Nao ia pedir um favor sem dar nada\n"
	.string "em troca.\p"
	.string "Por isso quero que fique com isto!$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
	.string "{PLAYER} recebeu um PokéNav.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp:
	.string "MR. STONE: Esse aparelho é um\n"
	.string "Pokémon Navigator, ou PokéNav.\p"
	.string "É muito útil pra um treinador em\n"
	.string "aventura. Tem um mapa de Hoenn.\p"
	.string "Você vai achar Dewford e Slateport\n"
	.string "com facilidade!\p"
	.string "Ah, ouvi dizer que uns criminosos,\n"
	.string "Magma e Aqua, andam causando\l"
	.string "problemas por aí.\p"
	.string "É melhor descansar antes de seguir\n"
	.string "viagem.$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
	.string "MR. STONE: Entao, {PLAYER}{KUN}, siga\n"
	.string "com cuidado!$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou:
	.string "MR. STONE: Conto com você!$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
	.string "MR. STONE: Entregou minha Letter?\n"
	.string "Muito obrigado!\p"
	.string "Quero dar isto pra agradecer. Deve\n"
	.string "ajudar você como treinador.$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare:
	.string "MR. STONE: Um Pokémon segurando\n"
	.string "Exp. Share recebe parte da\l"
	.string "experiência das batalhas.\p"
	.string "Mesmo que nao tenha entrado pra\n"
	.string "lutar.\p"
	.string "É muito útil pra treinar Pokémon\n"
	.string "fracos.$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
	.string "MR. STONE: Desde jovem, me dedico\n"
	.string "ao trabalho.\p"
	.string "Por isso nao entendo muito de\n"
	.string "modas e essas coisas.\p"
	.string "Mas todo jovem quer virar\n"
	.string "treinador da Liga Pokémon?$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere:
	.string "Este é o terceiro andar da Devon\n"
	.string "Corporation. A sala do presidente\l"
	.string "fica aqui.\p"
	.string "Nem sei como agradecer pelo que\n"
	.string "você fez.\p"
	.string "Aliás, aquele pacote que\n"
	.string "recuperou... Pode levar ao\l"
	.string "estaleiro de Slateport?\p"
	.string "Seria terrível se roubassem de\n"
	.string "novo.\p"
	.string "Hehehe... Posso contar com você?\p"
	.string "Ah, espere aqui um instante.$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
	.string "Nosso presidente quer conversar\n"
	.string "com você.\p"
	.string "Venha comigo, por favor.$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead:
	.string "Pode ir em frente.$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard:
	.string "No estaleiro de Slateport, procure\n"
	.string "o capitao Stern.$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
	.string "As novas Repeat Ball e Timer Ball\n"
	.string "da Devon fizeram muito sucesso com\l"
	.string "os treinadores.$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
	.string "É uma coleçao de pedras raras\n"
	.string "reunida pelo presidente.$"

