SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant::
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee::
	showmoneybox 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney::
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5::
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt::
	lock
	faceplayer
	delay 8
	playse SE_PIN
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_THIEF
	goto_if_eq VAR_RESULT, 0, SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief
	setflag FLAG_RECEIVED_TM_THIEF
	msgbox SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth
	goto_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	goto_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth::
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited::
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	playse SE_EXIT
	removeobject LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief::
	msgbox SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast:
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter:
	.string "Bem-vindo ao Oceanic Museum.\p"
	.string "A entrada custa ¥50. Quer entrar?$"

SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself:
	.string "Aproveite a visita.$"

SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney:
	.string "Ah, desculpa, mas parece que você\n"
	.string "nao tem dinheiro suficiente.$"

SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup:
	.string "Ah, você ta com o grupo que\n"
	.string "entrou antes?\p"
	.string "Só falta você. É melhor ir\n"
	.string "encontrar eles!$"

SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll:
	.string "Nós, da Team Aqua, trabalhamos\n"
	.string "pelo bem de todos!$"

SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere:
	.string "Mandaram a gente se reunir aqui,\n"
	.string "entao viemos...\p"
	.string "Mas o chefe, que era o mais\n"
	.string "importante, nao chegou.$"

SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich:
	.string "Se eu roubar essas coisas, será\n"
	.string "que fico rico?$"

SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds:
	.string "Posso usar oque aprender aqui pra\n"
	.string "fazer umas maldades...$"

SlateportCity_OceanicMuseum_1F_Text_RustboroBungled:
	.string "Se nossos capangas nao tivessem\n"
	.string "feito besteira em Rustboro, nao\l"
	.string "precisaríamos estar aqui!$"

SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney:
	.string "Eu nao tinha ¥50, entao demorei\n"
	.string "pra passar pela recepcionista.$"

SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling:
	.string "Quero aprender sobre o mar e usar\n"
	.string "isso nas batalhas.$"

SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel:
	.string "Fico todo animado quando vejo o\n"
	.string "mar!\p"
	.string "Pra mim, o capitao Stern é o maior\n"
	.string "exemplo!$"

SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow:
	.string "O mar nao tem fim e é profundo\n"
	.string "demais...\p"
	.string "Deve ter muitos Pokémon que a\n"
	.string "gente nem conhece.$"

SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon:
	.string "Quero um Pokémon do mar.\p"
	.string "Deve ser fresquinho e bom de\n"
	.string "abraçar.$"

SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis:
	.string "Aiiiih! Oque você ta fazendo aqui?\p"
	.string "Sou aquele membro da Team Aqua\n"
	.string "que você venceu no Rusturf\l"
	.string "Tunnel, lembra?\p"
	.string "Toma isto! Por favor, me perdoa!$"

SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain:
	.string "Essa TM combina mais com você do\n"
	.string "que comigo.\p"
	.string "Espero nunca mais ver sua cara!\n"
	.string "Wahahaha!$"

SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis:
	.string "Ah, por favor! Pega isto e me\n"
	.string "deixa ir!$"

SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment:
	.string "Um líquido azul gira dentro de um\n"
	.string "recipiente de vidro.\p"
	.string "“Este experimento usa vento pra\n"
	.string "criar um redemoinho.”$"

SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment:
	.string "Uma bola vermelha sobe e desce\n"
	.string "dentro de um recipiente de vidro.\p"
	.string "“Este experimento usa a flutuaçao\n"
	.string "da bola pra simular uma cachoeira.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay:
	.string "É uma amostra do solo do fundo do\n"
	.string "mar.\p"
	.string "“Com os anos, os restos de seres\n"
	.string "vivos se acumulam no fundo,\l"
	.string "formando camadas.\p"
	.string "Ao estudar essas camadas, podemos\n"
	.string "conhecer o passado.”$"

SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay:
	.string "É uma amostra de areia da praia.\p"
	.string "“Pedras das montanhas sao levadas\n"
	.string "pelos rios e vao se quebrando em\l"
	.string "pedaços menores.\p"
	.string "Com o tempo, viram os graos de\n"
	.string "areia das praias.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1:
	.string "CURIOSIDADE DO MAR 1\p"
	.string "Por que o mar é azul?\p"
	.string "“A luz tem várias cores. Ao passar\n"
	.string "pela água, a maior parte delas\l"
	.string "perde a força.\p"
	.string "A luz azul continua visível por\n"
	.string "mais tempo, deixando o mar com\l"
	.string "essa cor.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2:
	.string "CURIOSIDADE DO MAR 2\p"
	.string "Por que o mar é salgado?\p"
	.string "“A água do mar tem sal dissolvido.\n"
	.string "Ele vem de substâncias das pedras,\l"
	.string "levadas pela chuva até o mar.\p"
	.string "A quantidade de sal acumulado\n"
	.string "deixa a água salgada.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3:
	.string "CURIOSIDADE DO MAR 3\p"
	.string "Oque é maior, o mar ou a terra?\p"
	.string "“O mar cobre cerca de 70% do\n"
	.string "planeta. O resto é terra.\p"
	.string "Por isso, o mar ocupa mais que o\n"
	.string "dobro do espaço da terra.”$"

SlateportCity_OceanicMuseum_1F_Text_FossilDisplay:
	.string "É um fóssil com marcas onduladas.\p"
	.string "“A correnteza desenha pequenas\n"
	.string "ondas e vales no solo do fundo do\l"
	.string "mar.\p"
	.string "Quando esse solo vira fóssil, as\n"
	.string "marcas podem ficar preservadas.”$"

SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine:
	.string "Uma máquina estranha gira dentro\n"
	.string "de uma cúpula de vidro.\p"
	.string "Talvez sirva pra medir a\n"
	.string "profundidade de alguma coisa...$"

