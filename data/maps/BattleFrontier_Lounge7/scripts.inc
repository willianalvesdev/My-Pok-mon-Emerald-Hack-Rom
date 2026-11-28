BattleFrontier_Lounge7_MapScripts::
	.byte 0

@special ChooseMonForMoveTutor
BattleFrontier_Lounge7_EventScript_LeftMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor
	msgbox BattleFrontier_Lounge7_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor::
	msgbox BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_Softboiled::
	setvar VAR_0x8008, 16
	setvar VAR_0x8005, MOVE_SOFT_BOILED
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SeismicToss::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_SEISMIC_TOSS
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_DreamEater::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_DREAM_EATER
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaPunch::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_MEGA_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaKick::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_MEGA_KICK
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_BodySlam::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_BODY_SLAM
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RockSlide::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_ROCK_SLIDE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Counter::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_COUNTER
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderWave::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_THUNDER_WAVE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SwordsDance::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_SWORDS_DANCE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RightMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor
	msgbox BattleFrontier_Lounge7_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor::
	msgbox BattleFrontier_Lounge7_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_DefenseCurl::
	setvar VAR_0x8008, 16
	setvar VAR_0x8005, MOVE_DEFENSE_CURL
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Snore::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_SNORE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MudSlap::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_MUD_SLAP
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Swift::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_SWIFT
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcyWind::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_ICY_WIND
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Endure::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_ENDURE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_PsychUp::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_PSYCH_UP
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcePunch::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_ICE_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderPunch::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_THUNDER_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_FirePunch::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_FIRE_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_CancelChooseMon::
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection::
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	msgbox BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge7_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge7_EventScript_TeachTutorMove
	msgbox BattleFrontier_Lounge7_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseNewMove
	end


BattleFrontier_Lounge7_EventScript_TeachTutorMove::
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	chooseboxmon SELECT_PC_MON_MOVE_TUTOR
	waitstate
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_Lounge7_EventScript_CancelChooseMon
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleFrontier_Lounge7_EventScript_ChooseNewMove::
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_Sailor::
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful, MSGBOX_NPC
	end

BattleFrontier_Lounge7_Text_LeftTutorIntro:
	.string "Buhahaha!\p"
	.string "Hoje nem parece, mas já fui uma\n"
	.string "treinadora muito forte.\p"
	.string "Eu era conhecida como a mais forte\n"
	.string "entre as belas treinadoras!\p"
	.string "... ... ... ... ... ...\p"
	.string "O que foi? Nao acredita em mim?\p"
	.string "Nao sou como aquela convencida\n"
	.string "ali. Eu tenho talento de verdade!\p"
	.string "Vou provar. Posso ensinar golpes\n"
	.string "especiais e fofos aos seus\l"
	.string "Pokémon.\p"
	.string "Mas minhas aulas têm um preço. Que\n"
	.string "tal pagar com alguns Pontos de\l"
	.string "Batalha?$"

BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack:
	.string "Buhahaha!\p"
	.string "Voltou para aprender golpes\n"
	.string "especiais e fofos para seus\l"
	.string "Pokémon?$"

BattleFrontier_Lounge7_Text_TeachWhichMove:
	.string "Certo, certo, olha aqui! Qual\n"
	.string "golpe devo ensinar?$"

BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints:
	.string "O golpe {STR_VAR_1}? Custa\n"
	.string "{STR_VAR_2} Pontos de Batalha,\l"
	.string "tudo bem?$"

BattleFrontier_Lounge7_Text_TeachMoveToWhichMon:
	.string "Certo, agora escolha o Pokémon que\n"
	.string "vai aprender o golpe.$"

BattleFrontier_Lounge7_Text_HaventGotEnoughPoints:
	.string "Mas o quê...? Você nao tem Pontos\n"
	.string "de Batalha suficientes!$"

BattleFrontier_Lounge7_Text_IllTakeBattlePoints:
	.string "Viu como eu sou boa? Vou ficar com\n"
	.string "seus Pontos de Batalha, obrigada!$"

BattleFrontier_Lounge7_Text_YouDontWantTo:
	.string "O quê? Nao quer...\p"
	.string "Quando quiser ver meu talento, é\n"
	.string "só voltar aqui!$"

BattleFrontier_Lounge7_Text_RightTutorIntro:
	.string "Ihihihi!\p"
	.string "Hoje é difícil de acreditar, mas eu\n"
	.string "já fui uma treinadora incrível.\p"
	.string "Eu era conhecida como uma nadadora\n"
	.string "imbatível!\p"
	.string "... ... ... ... ... ...\p"
	.string "O que foi? Nao acredita em mim?\p"
	.string "Nao sou como aquela boba ali. Eu\n"
	.string "tenho experiência de verdade!\p"
	.string "Posso provar. Ensino golpes fortes\n"
	.string "e bonitos aos seus Pokémon.\p"
	.string "Mas minhas aulas têm um preço. Que\n"
	.string "tal pagar com alguns Pontos de\l"
	.string "Batalha?$"

BattleFrontier_Lounge7_Text_RightTutorWelcomeBack:
	.string "Ihihihi!\p"
	.string "Veio aprender golpes fortes e\n"
	.string "bonitos para seus Pokémon?$"

BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong:
	.string "Pelo jeito que essas senhoras\n"
	.string "falam mal uma da outra, parece que\l"
	.string "elas nao se dao bem.\p"
	.string "Mas, se fosse verdade, nao\n"
	.string "ficariam aqui juntas, né?$"

BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful:
	.string "Quando eu era criança, essas\n"
	.string "senhoras eram fortes e bonitas.\p"
	.string "Eram as estrelas entre nós,\n"
	.string "treinadores.\p"
	.string "Mesmo hoje, a idade nao diminuiu o\n"
	.string "talento delas.\p"
	.string "Na verdade, estao ainda melhores\n"
	.string "com os golpes Pokémon.\p"
	.string "Mas... Por algum motivo, nao\n"
	.string "consigo deixar de pensar...\p"
	.string "O tempo é cruel...$"

BattleFrontier_Lounge7_Text_SoftboiledDesc::
	.string "Recupera até metade do HP máximo\n"
	.string "de quem usa.$"

BattleFrontier_Lounge7_Text_SeismicTossDesc::
	.string "Causa dano igual ao nível de quem\n"
	.string "usa.$"

BattleFrontier_Lounge7_Text_DreamEaterDesc::
	.string "Recupera metade do dano causado a\n"
	.string "um adversário adormecido.$"

BattleFrontier_Lounge7_Text_MegaPunchDesc::
	.string "Um soco forte, dado com uma força\n"
	.string "incrível.$"

BattleFrontier_Lounge7_Text_MegaKickDesc::
	.string "Um chute extremamente forte.$"

BattleFrontier_Lounge7_Text_BodySlamDesc::
	.string "Uma pancada com o corpo inteiro\n"
	.string "que pode paralisar.$"

BattleFrontier_Lounge7_Text_RockSlideDesc::
	.string "Lança pedras grandes. Pode fazer o\n"
	.string "adversário recuar.$"

BattleFrontier_Lounge7_Text_CounterDesc::
	.string "Devolve um ataque físico com o\n"
	.string "dobro da força.$"

BattleFrontier_Lounge7_Text_ThunderWaveDesc::
	.string "Uma descarga elétrica fraca que\n"
	.string "paralisa o adversário.$"

BattleFrontier_Lounge7_Text_SwordsDanceDesc::
	.string "Uma dança de combate que aumenta\n"
	.string "muito o Ataque.$"

BattleFrontier_Lounge7_Text_DefenseCurlDesc::
	.string "Enrola o corpo para proteger os\n"
	.string "pontos fracos e aumentar a\l"
	.string "Defesa.$"

BattleFrontier_Lounge7_Text_SnoreDesc::
	.string "Um ataque barulhento que só pode\n"
	.string "ser usado durante o sono.$"

BattleFrontier_Lounge7_Text_MudSlapDesc::
	.string "Joga lama no rosto do adversário\n"
	.string "para reduzir sua precisao.$"

BattleFrontier_Lounge7_Text_SwiftDesc::
	.string "Dispara raios em forma de estrela\n"
	.string "que nunca erram.$"

BattleFrontier_Lounge7_Text_IcyWindDesc::
	.string "Um ataque gelado que reduz a\n"
	.string "Velocidade do adversário.$"

BattleFrontier_Lounge7_Text_EndureDesc::
	.string "Resiste a qualquer ataque por um\n"
	.string "turno, ficando com 1 HP.$"

BattleFrontier_Lounge7_Text_PsychUpDesc::
	.string "Copia as mudanças de atributos do\n"
	.string "adversário para quem usa.$"

BattleFrontier_Lounge7_Text_IcePunchDesc::
	.string "Um soco de gelo que pode congelar\n"
	.string "o adversário.$"

BattleFrontier_Lounge7_Text_ThunderPunchDesc::
	.string "Um soco elétrico que pode\n"
	.string "paralisar o adversário.$"

BattleFrontier_Lounge7_Text_FirePunchDesc::
	.string "Um soco de fogo que pode queimar\n"
	.string "o adversário.$"
