RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "E aí, tudo bem?\p"
	.string "Me diga: quer chegar ao posto de\n"
	.string "campeao?\p"
	.string "Nao sou treinador, mas posso dar\n"
	.string "umas dicas pra você ganhar.\p"
	.string "Fechado! Vamos buscar esse título\n"
	.string "juntos!\p"
	.string "Você precisa juntar insígnias, mas\n"
	.string "os líderes nao vao pegar leve. É\l"
	.string "aí que entram minhas dicas!\p"
	.string "Roxanne usa Pokémon Rock. Eles\n"
	.string "sao resistentes, mas sofrem contra\l"
	.string "golpes Water e Grass.\p"
	.string "Se vencer a líder, venha falar\n"
	.string "comigo. Vai com tudo!$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "Nossa! Que vitória incrível! Minha\n"
	.string "torcida deve ter ajudado!\p"
	.string "Olha seu cartao de treinador. A\n"
	.string "Stone Badge já deve estar\l"
	.string "registrada nele.\p"
	.string "Você subiu o primeiro degrau rumo\n"
	.string "ao título de campeao! Deve ser\l"
	.string "bom demais!$"

RustboroCity_Gym_Text_JoshIntro:
	.string "Nao subestime os treinadores deste\n"
	.string "ginásio! Vou mostrar nossa força!$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "Você foi bom demais pra mim...$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "Você ainda nao viu o poder\n"
	.string "assustador do tipo Rock!$"

RustboroCity_Gym_Text_TommyIntro:
	.string "Se nao consegue me vencer, nao\n"
	.string "tem chance contra Roxanne!$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "Nossa! Você tem futuro!$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "Roxanne é várias vezes mais forte\n"
	.string "que eu.\p"
	.string "É melhor tomar cuidado!$"

RustboroCity_Gym_Text_MarcIntro:
	.string "Podemos estar no meio da cidade,\n"
	.string "mas e daí?\p"
	.string "Meus Pokémon Rock precisam de\n"
	.string "espaço pra soltar a força!$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "Caramba! Nosso desafiante veio com\n"
	.string "tudo!$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "Admiro nossa líder.\p"
	.string "Escolher o tipo Rock tao jovem\n"
	.string "mostrou como ela é inteligente.$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "Oi, sou Roxanne, líder do ginásio\n"
	.string "Pokémon de Rustboro.\p"
	.string "Virei líder pra colocar em prática\n"
	.string "oque aprendi na escola de\l"
	.string "treinadores.\p"
	.string "Pode me mostrar como você batalha\n"
	.string "e quais Pokémon usa?$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "Entao... Eu perdi...\p"
	.string "Parece que ainda tenho muito a\n"
	.string "aprender.\p"
	.string "Entendo. Pelas regras da Liga\n"
	.string "Pokémon, quem vence um líder\l"
	.string "recebe uma insígnia.\p"
	.string "Aceite a Stone Badge oficial da\n"
	.string "Liga.$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER} recebeu a Stone Badge de\n"
	.string "Roxanne.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "A Stone Badge aumenta o Attack\n"
	.string "dos seus Pokémon.\p"
	.string "Também permite usar Cut fora das\n"
	.string "batalhas.\p"
	.string "Leve isto também.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "A TM39 tem Rock Tomb.\p"
	.string "O golpe joga pedras no adversário,\n"
	.string "causando dano e diminuindo a\l"
	.string "Speed.\p"
	.string "Uma TM ensina o golpe na hora.\p"
	.string "Mas só pode ser usada uma vez,\n"
	.string "entao pense antes de usar.$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "Com essa força, você deveria\n"
	.string "desafiar outros líderes.\p"
	.string "Batalhar com vários treinadores vai\n"
	.string "ensinar muita coisa.$"

RustboroCity_Gym_Text_GymStatue:
	.string "Ginásio Pokémon de Rustboro City$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "Ginásio Pokémon de Rustboro City\p"
	.string "Treinadores aprovados por Roxanne:\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "... Bip!\p"
	.string "ROXANNE: Oi, {PLAYER}? É Roxanne,\n"
	.string "de Rustboro City.\p"
	.string "Brawly contou que você ta\n"
	.string "avançando muito rápido entre os\l"
	.string "treinadores.\p"
	.string "Nao quero pensar que nao consigo\n"
	.string "vencer você.\p"
	.string "Vou preparar meu ginásio pra\n"
	.string "receber outro desafio seu.\p"
	.string "Espero que aguarde esse encontro\n"
	.string "com a mesma vontade que eu!\p"
	.string "... Clic!$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "A líder Roxanne foi registrada no\n"
	.string "PokéNav.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "ROXANNE: Fico feliz de ver você de\n"
	.string "novo. Sou Roxanne, a líder daqui.\p"
	.string "Com certeza nós dois passamos por\n"
	.string "muitas batalhas desde nosso\l"
	.string "encontro.\p"
	.string "Quero ver o quanto melhoramos.\n"
	.string "Vamos batalhar!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "Grr... Perdi de novo...$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string "ROXANNE: Ainda tenho muito a\n"
	.string "aprender sobre batalhas Pokémon.\p"
	.string "Saber disso me faz gostar ainda\n"
	.string "mais delas!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "ROXANNE: Fico feliz de ver você de\n"
	.string "novo. Sou Roxanne, a líder daqui.\p"
	.string "Com certeza nós dois passamos por\n"
	.string "muitas batalhas desde nosso\l"
	.string "encontro.\p"
	.string "Quero ver o quanto melhoramos...\p"
	.string "Ah, você só trouxe um Pokémon?\p"
	.string "Volte com pelo menos mais um, por\n"
	.string "favor.$"
