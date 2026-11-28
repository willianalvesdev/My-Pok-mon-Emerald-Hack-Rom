FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition:
	special RotatingGate_InitPuzzle
	setflag FLAG_TEMP_HIDE_FOLLOWER @ Hide follower bc of rotating gates
	end

FortreeCity_Gym_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
FortreeCity_Gym_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona::
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM_AERIAL_ACE, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated::
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo::
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint::
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley::
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto::
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius::
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified::
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue::
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice:
	.string "Ei, tudo certo, futuro campeao\n"
	.string "{PLAYER}?\p"
	.string "WINONA, a líder de FORTREE, é\n"
	.string "especialista em POKÉMONS do tipo\l"
	.string "Voador.\p"
	.string "Ela espera no fundo do ginásio,\n"
	.string "depois das portas giratórias.\p"
	.string "Ta esperando novos treinadores\n"
	.string "prontos pra voar alto!\p"
	.string "Vai lá!$"

FortreeCity_Gym_Text_GymGuidePostVictory:
	.string "Você conseguiu! Agora decolou de\n"
	.string "vez!$"

FortreeCity_Gym_Text_JaredIntro:
	.string "Veja o jeito elegante dos\n"
	.string "POKÉMONS pássaros de batalhar!$"

FortreeCity_Gym_Text_JaredDefeat:
	.string "Você... Você é forte...$"

FortreeCity_Gym_Text_JaredPostBattle:
	.string "Um treinador precisa pensar rápido\n"
	.string "pra lidar com imprevistos.\p"
	.string "Você consegue encontrar o caminho\n"
	.string "até nossa líder?$"

FortreeCity_Gym_Text_EdwardoIntro:
	.string "Quem gosta de POKÉMONS pássaros\n"
	.string "sonha em fazer parte deste\l"
	.string "ginásio.\p"
	.string "Como membro daqui, nao posso\n"
	.string "perder!$"

FortreeCity_Gym_Text_EdwardoDefeat:
	.string "Isso foi demais pra mim...$"

FortreeCity_Gym_Text_EdwardoPostBattle:
	.string "O mundo é enorme e ta cheio de\n"
	.string "treinadores fortes.\p"
	.string "Vou continuar treinando e ficar\n"
	.string "ainda mais forte.$"

FortreeCity_Gym_Text_FlintIntro:
	.string "Nao precisa incomodar nossa líder\n"
	.string "WINONA com isso!\p"
	.string "Eu já sou suficiente pra você!$"

FortreeCity_Gym_Text_FlintDefeat:
	.string "WINONA, eu... Eu perdi!$"

FortreeCity_Gym_Text_FlintPostBattle:
	.string "WINONA é bonita e forte. É a líder\n"
	.string "perfeita!\p"
	.string "...Fica vermelho...$"

FortreeCity_Gym_Text_AshleyIntro:
	.string "Aprendi pessoalmente com a WINONA!\n"
	.string "Nao vai ser fácil me vencer!$"

FortreeCity_Gym_Text_AshleyDefeat:
	.string "Fui derrotada...$"

FortreeCity_Gym_Text_AshleyPostBattle:
	.string "Graças à WINONA, o pessoal de\n"
	.string "FORTREE pode viver sem medo.$"

FortreeCity_Gym_Text_HumbertoIntro:
	.string "Quando WINONA batalha, o rosto\n"
	.string "dela brilha de determinaçao...\p"
	.string "Nao vou deixar você ver uma cena\n"
	.string "tao linda!$"

FortreeCity_Gym_Text_HumbertoDefeat:
	.string "Urgh! Nao consegui te parar.$"

FortreeCity_Gym_Text_HumbertoPostBattle:
	.string "Tome cuidado! Se ficar olhando pra\n"
	.string "WINONA e esquecer da batalha, vai\l"
	.string "levar um tombo!$"

FortreeCity_Gym_Text_DariusIntro:
	.string "Você sabe que existem muitos tipos\n"
	.string "diferentes de POKÉMONS voadores,\l"
	.string "né?\p"
	.string "Sabe mesmo?$"

FortreeCity_Gym_Text_DariusDefeat:
	.string "Parece que você entende do\n"
	.string "assunto!$"

FortreeCity_Gym_Text_DariusPostBattle:
	.string "Você me venceu, mas tome cuidado!\n"
	.string "Os POKÉMONS da WINONA nao estao\l"
	.string "de brincadeira.$"

FortreeCity_Gym_Text_WinonaIntro:
	.string "Sou WINONA, a líder do ginásio de\n"
	.string "FORTREE.\p"
	.string "Aprendi a voar em sintonia com os\n"
	.string "POKÉMONS pássaros...\p"
	.string "Mesmo nas batalhas mais difíceis,\n"
	.string "vencemos com elegância...\p"
	.string "Veja a dança de batalha que vamos\n"
	.string "apresentar!$"

FortreeCity_Gym_Text_WinonaDefeat:
	.string "Nunca vi outro treinador guiar seus\n"
	.string "POKÉMONS com mais elegância que\l"
	.string "eu...\p"
	.string "Pelo seu talento, receba esta\n"
	.string "insígnia.$"

FortreeCity_Gym_Text_ReceivedFeatherBadge:
	.string "{PLAYER} recebeu a FEATHER BADGE\n"
	.string "de WINONA.$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
	.string "Com a FEATHER BADGE, todos os\n"
	.string "POKÉMONS até o nível 70 obedecem\l"
	.string "você, até os recebidos por troca.\p"
	.string "Você também pode usar FLY fora\n"
	.string "das batalhas.\p"
	.string "E isto... É um presente meu.$"

FortreeCity_Gym_Text_ExplainAerialAce:
	.string "A TM40 ensina AERIAL ACE.\p"
	.string "É tao rápido que nenhum POKÉMON\n"
	.string "deveria conseguir escapar.\p"
	.string "... ... ... ... ... ...$"

FortreeCity_Gym_Text_RegisteredWinona:
	.string "A líder WINONA foi registrada no\n"
	.string "POKéNAV.$"

FortreeCity_Gym_Text_WinonaPostBattle:
	.string "Mesmo depois dessa derrota, vou\n"
	.string "continuar me dedicando aos\l"
	.string "POKÉMONS pássaros.$"

FortreeCity_Gym_Text_GymStatue:
	.string "Ginásio Pokémon de FORTREE CITY$"

FortreeCity_Gym_Text_GymStatueCertified:
	.string "Ginásio Pokémon de FORTREE CITY\p"
	.string "Treinadores reconhecidos por\n"
	.string "WINONA: {PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch:
	.string "WINONA: Nós, humanos, nao\n"
	.string "conseguimos escapar da força que\l"
	.string "nos prende ao chao.\p"
	.string "Mas, buscando melhorar,\n"
	.string "encontramos nossa forma de voar!\p"
	.string "Você chegou ao topo como campeao.\p"
	.string "Quero ver até onde seu poder pode\n"
	.string "ir!$"

FortreeCity_Gym_Text_WinonaRematchDefeat:
	.string "De novo, nao consegui chegar à sua\n"
	.string "altura...$"

FortreeCity_Gym_Text_WinonaPostRematch:
	.string "WINONA: Mesmo derrotada, as asas\n"
	.string "do meu coraçao continuam inteiras.\p"
	.string "Posso levantar e voar de novo,\n"
	.string "quantas vezes precisar.\p"
	.string "Tenho certeza disso!$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
	.string "WINONA: Nós, humanos, nao\n"
	.string "conseguimos escapar da força que\l"
	.string "nos prende ao chao.\p"
	.string "Mas, buscando melhorar,\n"
	.string "encontramos nossa forma de voar!\p"
	.string "Você chegou ao topo como campeao.\p"
	.string "Quero ver até onde seu poder pode\n"
	.string "ir!\p"
	.string "Ah... Você só tem um POKÉMON com\n"
	.string "você?\p"
	.string "Volte com pelo menos dois.$"
