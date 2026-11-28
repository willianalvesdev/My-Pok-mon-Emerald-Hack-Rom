MtPyre_6F_MapScripts::
	.byte 0

MtPyre_6F_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat, MtPyre_6F_EventScript_RegisterValerie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_6F_EventScript_RematchValerie
	msgbox MtPyre_6F_Text_ValeriePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RegisterValerie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_6F_Text_ValerieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_RematchValerie::
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieRematchIntro, MtPyre_6F_Text_ValerieRematchDefeat
	msgbox MtPyre_6F_Text_ValeriePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Cedric::
	trainerbattle_single TRAINER_CEDRIC, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat
	msgbox MtPyre_6F_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_Text_ValerieIntro:
	.string "Quando tô aqui... Um poder\n"
	.string "estranho entra em mim...$"

MtPyre_6F_Text_ValerieDefeat:
	.string "O poder ta indo embora...$"

MtPyre_6F_Text_ValeriePostBattle:
	.string "Talvez esse poder venha dos\n"
	.string "espíritos dos Pokémon que nao\l"
	.string "conseguem descansar aqui...$"

MtPyre_6F_Text_ValerieRegister:
	.string "Fufufu... Perdi a batalha, mas\n"
	.string "tenho uma habilidade...\p"
	.string "Sem nem encostar no seu PokéNav...\n"
	.string "Hiyah!$"

MtPyre_6F_Text_ValerieRematchIntro:
	.string "Atrás de você... Oque é aquilo...?$"

MtPyre_6F_Text_ValerieRematchDefeat:
	.string "Alguma coisa desapareceu...$"

MtPyre_6F_Text_ValeriePostRematch:
	.string "Os Pokémon que descansam aqui...\n"
	.string "Às vezes, brincam...$"

MtPyre_6F_Text_CedricIntro:
	.string "Se perdeu? Nao precisa ter medo,\n"
	.string "eu tô aqui!$"

MtPyre_6F_Text_CedricDefeat:
	.string "Você nao tava perdido?$"

MtPyre_6F_Text_CedricPostBattle:
	.string "Achei que um treinador perdido ia\n"
	.string "estar assustado e seria fácil de\l"
	.string "vencer.\p"
	.string "Foi uma ideia suja. Nao vou fazer\n"
	.string "isso de novo...$"

