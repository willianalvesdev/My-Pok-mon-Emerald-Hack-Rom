SSTidalRooms_MapScripts::
	.byte 0

SSTidalRooms_EventScript_SnatchGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalRooms_EventScript_ExplainSnatch
	msgbox SSTidalRooms_Text_NotSuspiciousTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SNATCH
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_ExplainSnatch::
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_Bed::
	lockall
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	call SSTidalRooms_EventScript_ProgessCruiseAfterBed
	releaseall
	end

SSTidalRooms_EventScript_Colton::
	trainerbattle_single TRAINER_COLTON, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat
	msgbox SSTidalRooms_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Micah::
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat
	msgbox SSTidalRooms_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Thomas::
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat
	msgbox SSTidalRooms_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Jed::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_JedIntro, SSTidalRooms_Text_JedDefeat, SSTidalRooms_Text_JedNotEnoughMons
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Lea::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_LeaIntro, SSTidalRooms_Text_LeaDefeat, SSTidalRooms_Text_LeaNotEnoughMons
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Garret::
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat
	msgbox SSTidalRooms_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Naomi::
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat
	msgbox SSTidalRooms_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_Text_TakeRestOnBed:
	.string "Tem uma cama... Hora de descansar.$"

SSTidalRooms_Text_ColtonIntro:
	.string "Vou bastante a Lilycove City.\p"
	.string "Gosto de assistir aos concursos.$"

SSTidalRooms_Text_ColtonDefeat:
	.string "Foi uma batalha muito divertida!$"

SSTidalRooms_Text_ColtonPostBattle:
	.string "Só de imaginar os Pokémon que vou\n"
	.string "ver no próximo concurso já fico\l"
	.string "animado. Mal posso esperar!$"

SSTidalRooms_Text_MicahIntro:
	.string "Seus amigos sao fortes?$"

SSTidalRooms_Text_MicahDefeat:
	.string "Seus amigos sao fortes mesmo.$"

SSTidalRooms_Text_MicahPostBattle:
	.string "Um amigo nao precisa ser humano.\n"
	.string "Pra mim, os Pokémon sao grandes\l"
	.string "amigos!$"

SSTidalRooms_Text_ThomasIntro:
	.string "Criança... Você bateu na porta?$"

SSTidalRooms_Text_ThomasDefeat:
	.string "Uma derrota deve ser aceita sem\n"
	.string "pressa nem desespero.$"

SSTidalRooms_Text_ThomasPostBattle:
	.string "Manter a calma em qualquer\n"
	.string "situaçao é parte de ser um\l"
	.string "cavalheiro.$"

SSTidalRooms_Text_JedIntro:
	.string "JED: Fico até com vergonha, mas...\n"
	.string "Vamos mostrar a força do nosso\l"
	.string "amor!$"

SSTidalRooms_Text_JedDefeat:
	.string "JED: Ah...$"

SSTidalRooms_Text_JedPostBattle:
	.string "JED: É a primeira vez que a força\n"
	.string "do nosso amor nao vence! Você\l"
	.string "deve ser um treinador incrível!$"

SSTidalRooms_Text_JedNotEnoughMons:
	.string "JED: Só tem um Pokémon? Nao fica\n"
	.string "meio solitário assim?$"

SSTidalRooms_Text_LeaIntro:
	.string "LEA: É um pouco bobo, mas... Vamos\n"
	.string "mostrar a força do nosso amor!$"

SSTidalRooms_Text_LeaDefeat:
	.string "LEA: Ah, nao!$"

SSTidalRooms_Text_LeaPostBattle:
	.string "LEA: Nao acredito! A força do\n"
	.string "nosso amor falhou... Você deve ser\l"
	.string "um treinador incrível!$"

SSTidalRooms_Text_LeaNotEnoughMons:
	.string "LEA: Queria batalhar... Mas você\n"
	.string "nem tem dois Pokémon...$"

SSTidalRooms_Text_GarretIntro:
	.string "Ah, chegou na hora certa.\p"
	.string "Tô entediado. Pode me divertir um\n"
	.string "pouco.$"

SSTidalRooms_Text_GarretDefeat:
	.string "...Já chega.$"

SSTidalRooms_Text_GarretPostBattle:
	.string "Talvez eu peça pro meu pai comprar\n"
	.string "um iate pra mim. Um iate só pra mim\l"
	.string "e meus Pokémon!$"

SSTidalRooms_Text_NaomiIntro:
	.string "Ah, que treinador adorável. Quer\n"
	.string "tomar um chá? Ou prefere batalhar?$"

SSTidalRooms_Text_NaomiDefeat:
	.string "Entendo. Você é do tipo que gosta\n"
	.string "de açao.$"

SSTidalRooms_Text_NaomiPostBattle:
	.string "Viajar pelo mundo num navio de\n"
	.string "luxo tem seu charme...\p"
	.string "Mas admito que conhecer Hoenn\n"
	.string "neste barco também é muito\l"
	.string "agradável.$"

SSTidalRooms_Text_NotSuspiciousTakeThis:
	.string "É... Oi! Nao tô fazendo nada\n"
	.string "suspeito! Pode levar isto! De\l"
	.string "graça!\p"
	.string "Eu nao roubei de ninguém, juro!\n"
	.string "Nunca faria isso! Pode usar sem\l"
	.string "medo!$"

SSTidalRooms_Text_ExplainSnatch:
	.string "Snatch rouba os efeitos positivos\n"
	.string "de certos golpes antes que um\l"
	.string "adversário ou aliado use eles.$"

