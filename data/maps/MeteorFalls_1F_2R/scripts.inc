MeteorFalls_1F_2R_MapScripts::
	.byte 0

MeteorFalls_1F_2R_EventScript_Nicolas::
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchNicolas
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterNicolas::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchNicolas::
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_John::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat, MeteorFalls_1F_2R_Text_JohnNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJohn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJohn
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJohn::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJohn::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_Jay::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJay
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJay::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT  @ John speaks for both during register
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJay::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_Text_NicolasIntro:
	.string "É aqui que nós, treinadores de\n"
	.string "Pokémon do tipo Dragon, treinamos.\p"
	.string "Até o campeao vem visitar. Agora\n"
	.string "entende como este lugar é\l"
	.string "especial?$"

MeteorFalls_1F_2R_Text_NicolasDefeat:
	.string "Urgh! Nao esperava que você fosse\n"
	.string "tao forte!$"

MeteorFalls_1F_2R_Text_NicolasPostBattle:
	.string "O caminho pela frente ainda é\n"
	.string "longo e difícil.\p"
	.string "Quando eu e meus Pokémon vamos\n"
	.string "ser os melhores?$"

MeteorFalls_1F_2R_Text_NicolasRegister:
	.string "Quero conhecer melhor sua força.\n"
	.string "Vou registrar você no meu PokéNav.$"

MeteorFalls_1F_2R_Text_NicolasRematchIntro:
	.string "Desde nosso encontro, treinamos\n"
	.string "muito pra chegar ao topo.\p"
	.string "Ajude a gente a descobrir o quanto\n"
	.string "melhorou!$"

MeteorFalls_1F_2R_Text_NicolasRematchDefeat:
	.string "Urgh! Nao esperava que você fosse\n"
	.string "tao forte!$"

MeteorFalls_1F_2R_Text_NicolasPostRematch:
	.string "Dá pra ver que você continuou\n"
	.string "treinando.\p"
	.string "Enquanto você seguir forte, eu\n"
	.string "também posso melhorar!$"

MeteorFalls_1F_2R_Text_JohnIntro:
	.string "JOHN: Sempre batalhamos juntos.\n"
	.string "Confiamos muito um no outro.$"

MeteorFalls_1F_2R_Text_JohnDefeat:
	.string "JOHN: Ah, minha querida. Nós\n"
	.string "perdemos.$"

MeteorFalls_1F_2R_Text_JohnPostBattle:
	.string "JOHN: Estamos casados faz\n"
	.string "cinquenta anos.\p"
	.string "Agora que parei pra pensar, nunca\n"
	.string "ganhei uma batalha da minha\l"
	.string "esposa.$"

MeteorFalls_1F_2R_Text_JohnNotEnoughMons:
	.string "JOHN: Olha só, um jovem treinador!\p"
	.string "Quer batalhar com a gente? Entao\n"
	.string "volte com mais Pokémon.$"

MeteorFalls_1F_2R_Text_JohnRegister:
	.string "JOHN: Jovem, se tiver outra\n"
	.string "chance, batalha com a gente de\l"
	.string "novo?$"

MeteorFalls_1F_2R_Text_JayIntro:
	.string "JAY: Estamos casados faz\n"
	.string "cinquenta anos.\p"
	.string "Nada pode quebrar nossa uniao.$"

MeteorFalls_1F_2R_Text_JayDefeat:
	.string "JAY: Ah, meu querido. Nós\n"
	.string "perdemos.$"

MeteorFalls_1F_2R_Text_JayPostBattle:
	.string "JAY: Cinquenta anos de\n"
	.string "casamento...\p"
	.string "Quando brigávamos, resolvíamos\n"
	.string "tudo numa batalha Pokémon.\p"
	.string "Ele sempre acabava lavando a\n"
	.string "louça.$"

MeteorFalls_1F_2R_Text_JayNotEnoughMons:
	.string "JAY: Olha só, um jovem treinador!\p"
	.string "Se quiser batalhar com a gente,\n"
	.string "volte com mais Pokémon.$"

MeteorFalls_1F_2R_Text_JohnRematchIntro:
	.string "JOHN: Sempre batalhamos juntos.\n"
	.string "Confiamos muito um no outro.$"

MeteorFalls_1F_2R_Text_JohnRematchDefeat:
	.string "JOHN: Ah, minha querida. Nós\n"
	.string "perdemos.$"

MeteorFalls_1F_2R_Text_JohnPostRematch:
	.string "JOHN: Cinquenta anos de\n"
	.string "casamento...\p"
	.string "Pensando bem, eu e minha querida\n"
	.string "batalhamos quase todo dia...$"

MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons:
	.string "JOHN: Olha só, um jovem treinador!\p"
	.string "Quer batalhar com a gente? Entao\n"
	.string "volte com mais Pokémon.$"

MeteorFalls_1F_2R_Text_JayRematchIntro:
	.string "JAY: Estamos casados faz\n"
	.string "cinquenta anos.\p"
	.string "Sempre apoiamos um ao outro. Foi\n"
	.string "assim que ficamos fortes.$"

MeteorFalls_1F_2R_Text_JayRematchDefeat:
	.string "JAY: Ah, meu querido. Nós\n"
	.string "perdemos.$"

MeteorFalls_1F_2R_Text_JayPostRematch:
	.string "JAY: Cinquenta anos de\n"
	.string "casamento... Aconteceu tanta\l"
	.string "coisa.\p"
	.string "Espero que a gente continue\n"
	.string "vivendo momentos felizes juntos.$"

MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons:
	.string "JAY: Olha só, um jovem treinador!\p"
	.string "Se quiser batalhar com a gente,\n"
	.string "volte com mais Pokémon.$"

