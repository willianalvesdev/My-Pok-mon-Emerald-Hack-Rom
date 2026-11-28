LilycoveCity_MoveDeletersHouse_MapScripts::
	.byte 0

LilycoveCity_MoveDeletersHouse_EventScript_MoveDeleter::
	lockall
	applymovement LOCALID_MOVE_DELETER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget::
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldForget, MSGBOX_DEFAULT
	chooseboxmon SELECT_PC_MON_MOVE_DELETER
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_EggCantForgetMoves
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, LilycoveCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
	special BufferMoveDeleterNicknameAndMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, LilycoveCity_MoveDeletersHouse_EventScript_TryForgetMove
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_TryForgetMove::
	special IsLastMonThatKnowsSurf
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_LastMonWithSurf
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_EggCantForgetMoves::
	msgbox LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain::
	msgbox LilycoveCity_MoveDeletersHouse_Text_ComeAgain, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_LastMonWithSurf::
	special BufferMoveDeleterNicknameAndMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove:
	.string "Ah... É, sou o Move Deleter.\p"
	.string "Posso fazer os Pokémon esquecerem\n"
	.string "golpes.\p"
	.string "Quer que eu faça isso?$"

LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldForget:
	.string "Qual Pokémon deve esquecer um\n"
	.string "golpe?$"

LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten:
	.string "Qual golpe deve ser esquecido?$"

LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove:
	.string "{STR_VAR_1} só sabe um golpe,\n"
	.string "entao nao pode esquecer...$"

LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten:
	.string "Hum! Quer que {STR_VAR_1}\n"
	.string "esqueça {STR_VAR_2}?$"

LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove:
	.string "Deu tudo certo!\p"
	.string "{STR_VAR_1} esqueceu\n"
	.string "{STR_VAR_2} completamente.$"

LilycoveCity_MoveDeletersHouse_Text_ComeAgain:
	.string "Volte quando quiser que algum\n"
	.string "Pokémon esqueça um golpe.$"

LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves:
	.string "Como assim? Um ovo nao devia saber\n"
	.string "nenhum golpe.$"

LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf:
	.string "Hum!\p"
	.string "Seu {STR_VAR_1} nao parece\n"
	.string "querer esquecer Surf.$"

