RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
	.string "O quadro mostra os problemas de\n"
	.string "estado que podem afetar os\l"
	.string "Pokémon nas batalhas.$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
	.string "Qual assunto quer ler?$"

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.string "Um Pokémon envenenado perde HP\n"
	.string "aos poucos.\p"
	.string "O veneno continua depois da\n"
	.string "batalha e também tira HP enquanto\l"
	.string "você anda.\p"
	.string "Use Antidote pra curar.$"

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.string "Um Pokémon paralisado perde Speed\n"
	.string "e às vezes nao consegue agir na\l"
	.string "batalha.\p"
	.string "A paralisia continua depois da\n"
	.string "luta. Use Parlyz Heal pra curar.$"

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.string "Um Pokémon dormindo nao consegue\n"
	.string "atacar.\p"
	.string "Ele pode acordar sozinho, mas\n"
	.string "continua dormindo se a batalha\l"
	.string "acabar antes.\p"
	.string "Use Awakening pra acordar ele.$"

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.string "Uma queimadura diminui o Attack e\n"
	.string "tira HP aos poucos.\p"
	.string "Ela continua depois da batalha.\n"
	.string "Use Burn Heal pra curar.$"

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.string "Um Pokémon congelado fica sem\n"
	.string "conseguir agir.\p"
	.string "Ele continua congelado depois da\n"
	.string "batalha. Use Ice Heal pra\l"
	.string "descongelar.$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "Os alunos que nao estudam\n"
	.string "conhecem minha Quick Claw de\l"
	.string "perto.\p"
	.string "Seu jeito de usar este item vai\n"
	.string "mostrar se você é um bom aluno.$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.string "Um Pokémon segurando Quick Claw às\n"
	.string "vezes consegue agir antes do\l"
	.string "adversário.\p"
	.string "Existem muitos outros itens pra\n"
	.string "eles segurarem.\p"
	.string "Só isso já rende bastante assunto\n"
	.string "pra estudar!$"

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.string "Tô trocando Pokémon com meu amigo\n"
	.string "agora.$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.string "Sempre quis um Seedot e finalmente\n"
	.string "vou ganhar um!$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.string "Os Pokémon podem segurar itens,\n"
	.string "mas nao sabem usar coisas como\l"
	.string "Potion e Antidote sozinhos.$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "Alguns golpes deixam o Pokémon\n"
	.string "confuso.\p"
	.string "Quando ta assim, ele pode se\n"
	.string "machucar sem querer.\p"
	.string "Mas volta ao normal quando sai da\n"
	.string "batalha.$"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.string "Um Pokémon segurando uma Berry\n"
	.string "pode se curar sozinho...\p"
	.string "Existem vários itens que eles\n"
	.string "podem segurar...\p"
	.string "Nossa, é difícil anotar tudo...$"

RustboroCity_PokemonSchool_Text_StudentsNotes:
	.string "É o caderno de um aluno...\p"
	.string "Os Pokémon sao capturados com\n"
	.string "Poké Balls.\p"
	.string "Um treinador pode carregar até\n"
	.string "seis Pokémon.\p"
	.string "Treinadores capturam, cuidam dos\n"
	.string "Pokémon e batalham com eles.\p"
	.string "A missao de um treinador é vencer\n"
	.string "os treinadores fortes que esperam\l"
	.string "nos ginásios.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
	.string "Oi, a gente já se encontrou, nao?\n"
	.string "Acho que foi em Petalburg City.\p"
	.string "Vou me apresentar. Sou Scott.\p"
	.string "Viajo procurando treinadores\n"
	.string "incríveis, principalmente\l"
	.string "especialistas em batalhas.\p"
	.string "Oque trouxe você à escola? Também\n"
	.string "é treinador?\p"
	.string "Primeiro, ensine Cut a um Pokémon.\n"
	.string "Se lembro bem, alguém nesta cidade\l"
	.string "tem esse golpe.$"

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
	.string "SCOTT: Hum... Ainda nao conheço o\n"
	.string "talento dos alunos daqui. Mas eles\l"
	.string "têm futuro.$"

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
	.string "SCOTT: Ah, oque é isso?\p"
	.string "Uma Stone Badge! Muito bom.\p"
	.string "Mas eu queria ter visto sua\n"
	.string "batalha.\p"
	.string "Só pela insígnia é difícil saber\n"
	.string "como você é como treinador.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
	.string "Oi, a gente já se encontrou, nao?\n"
	.string "Acho que foi em Petalburg City.\p"
	.string "Sou Scott. Viajo procurando\n"
	.string "treinadores incríveis,\l"
	.string "principalmente especialistas em\l"
	.string "batalhas.\p"
	.string "Ah, isso é uma Stone Badge? É\n"
	.string "muito bom pra quem ta começando.\p"
	.string "Mas eu queria ter visto sua\n"
	.string "batalha. Só pela insígnia é difícil\l"
	.string "conhecer seu jeito de treinar.$"

