MtPyre_3F_MapScripts::
	.byte 0

MtPyre_3F_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat
	msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Kayla::
	trainerbattle_single TRAINER_KAYLA, MtPyre_3F_Text_KaylaIntro, MtPyre_3F_Text_KaylaDefeat
	msgbox MtPyre_3F_Text_KaylaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Gabrielle::
	trainerbattle_single TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleIntro, MtPyre_3F_Text_GabrielleDefeat, MtPyre_3F_EventScript_RegisterGabrielle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_3F_EventScript_RematchGabrielle
	msgbox MtPyre_3F_Text_GabriellePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_3F_EventScript_RegisterGabrielle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_3F_Text_GabrielleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GABRIELLE_1
	release
	end

MtPyre_3F_EventScript_RematchGabrielle::
	trainerbattle_rematch TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleRematchIntro, MtPyre_3F_Text_GabrielleRematchDefeat
	msgbox MtPyre_3F_Text_GabriellePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_Text_WilliamIntro:
	.string "A energia desta montanha aumentou\n"
	.string "meus poderes psíquicos!\p"
	.string "Uma criança como você acha que\n"
	.string "pode vencer?$"

MtPyre_3F_Text_WilliamDefeat:
	.string "Que pena de mim...$"

MtPyre_3F_Text_WilliamPostBattle:
	.string "Meus poderes com certeza ficaram\n"
	.string "várias vezes mais fortes, mas...$"

MtPyre_3F_Text_KaylaIntro:
	.string "Ahahahaha!\p"
	.string "Aqui nao é lugar pra crianças.\n"
	.string "Muito menos pra você!$"

MtPyre_3F_Text_KaylaDefeat:
	.string "Perdi sem nem ter chance...$"

MtPyre_3F_Text_KaylaPostBattle:
	.string "Ainda preciso treinar mais...\p"
	.string "Tenho que continuar subindo até o\n"
	.string "topo...\p"
	.string "Vamos, eu consigo!$"

MtPyre_3F_Text_GabrielleIntro:
	.string "Por que você veio aqui?$"

MtPyre_3F_Text_GabrielleDefeat:
	.string "Foi incrível! Você é um treinador\n"
	.string "muito especial.$"

MtPyre_3F_Text_GabriellePostBattle:
	.string "Os Pokémon que já se foram. Os\n"
	.string "que estao com você agora.\p"
	.string "E os que ainda vai encontrar...\p"
	.string "Todos merecem o mesmo carinho. Nao\n"
	.string "esqueça disso.$"

MtPyre_3F_Text_GabrielleRegister:
	.string "Queria ver seus Pokémon quando\n"
	.string "crescerem mais...\p"
	.string "Por favor, me empreste seu\n"
	.string "PokéNav.$"

MtPyre_3F_Text_GabrielleRematchIntro:
	.string "Ah, é você...\p"
	.string "Veio me mostrar como seus Pokémon\n"
	.string "cresceram?$"

MtPyre_3F_Text_GabrielleRematchDefeat:
	.string "Que incrível! Você é uma pessoa\n"
	.string "especial.$"

MtPyre_3F_Text_GabriellePostRematch:
	.string "Os Pokémon que já se foram. Os\n"
	.string "que estao com você agora.\p"
	.string "E os que ainda vai encontrar...\p"
	.string "Todos merecem o mesmo carinho.\n"
	.string "Vejo que você nao esqueceu disso.$"

