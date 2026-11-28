SlateportCity_SternsShipyard_1F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_1F_EventScript_Dock::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney::
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails:
	.string "Hum... Se isto vai aqui e aquilo\n"
	.string "vai ali...\p"
	.string "Onde encaixa esta coisa? E aquela\n"
	.string "pecinha?\p"
	.string "Aaaargh! Nao tô entendendo nada!$"

SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
	.string "Hum? Oi, sou Dock.\p"
	.string "O capitao Stern me pediu pra\n"
	.string "projetar um barco.\p"
	.string "Ah! Isso sao Devon Goods?\p"
	.string "Hum... O capitao saiu pra resolver\n"
	.string "umas coisas.\p"
	.string "Pode procurar ele e entregar o\n"
	.string "pacote?$"

SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
	.string "DOCK: Onde será que o capitao\n"
	.string "Stern foi?\p"
	.string "Pode procurar ele e entregar esse\n"
	.string "pacote?$"

SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
	.string "DOCK: Construir navios é uma arte.\p"
	.string "Tem muita coisa que uma conta nao\n"
	.string "resolve.\p"
	.string "Queria o conselho de alguém com\n"
	.string "experiência no mar...$"

SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
	.string "DOCK: Oi! Mr. Briney veio ajudar a\n"
	.string "gente.\p"
	.string "Com a experiência dele, o barco ta\n"
	.string "tomando forma.$"

SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
	.string "DOCK: O barco finalmente ficou\n"
	.string "pronto!\p"
	.string "O novo S.S. Tidal é uma maravilha\n"
	.string "da tecnologia!\p"
	.string "Mas sinto que podemos fazer algo\n"
	.string "ainda melhor. A tecnologia nunca\l"
	.string "para de avançar.$"

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
	.string "MR. BRINEY: Ah, {PLAYER}{KUN}! Quanto\n"
	.string "tempo!\p"
	.string "Desde que conheci você, este velho\n"
	.string "marinheiro ficou mais animado!\p"
	.string "Resolvi ajudar Dock a construir um\n"
	.string "barco. Assim podemos levar\l"
	.string "bastante gente.\p"
	.string "Ele é especial. Com o talento dele\n"
	.string "e minha experiência, vamos fazer\l"
	.string "um navio e tanto!$"

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
	.string "As estaçoes, o clima e a posiçao\n"
	.string "da Lua...\p"
	.string "Tudo isso muda o jeito do mar.\p"
	.string "É quase como se ele tivesse vida!$"

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
	.string "Enjoo muito fácil no mar. Por isso\n"
	.string "ajudo aqui.$"

