MtPyre_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition:
	call_if_eq VAR_MT_PYRE_STATE, 2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
	end

MtPyre_Summit_EventScript_SetArchieMaxiePositions::
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_MAXIE, 23, 6
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_ARCHIE, 22, 6
	end

MtPyre_Summit_EventScript_TeamAquaTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaExits::
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieFacePlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieFacePlayer2
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_1
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_2
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_3
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_4
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	fadedefaultbgm
	fadescreenswapbuffers FADE_FROM_BLACK
	delay 20
	setvar VAR_MT_PYRE_STATE, 1
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
	giveitem ITEM_MAGMA_EMBLEM
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	releaseall
	end

MtPyre_Summit_EventScript_ArchieFacePlayer0::
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
	waitmovement 0
	return

@ Archie is already facing player
MtPyre_Summit_EventScript_ArchieFacePlayer1::
	return

MtPyre_Summit_EventScript_ArchieFacePlayer2::
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

MtPyre_Summit_Movement_OldLadyApproachPlayer0:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer1:
	walk_down
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer2:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer0:
	walk_left
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer2:
	walk_right
	walk_in_place_faster_down
	step_end

MtPyre_Summit_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza::
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale::
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale::
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale::
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
	call_if_ge VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyOrbsReturned::
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
	playse SE_PIN
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
	delay 30
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_MAXIE
	setvar VAR_MT_PYRE_STATE, 3
	releaseall
	end

MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_Movement_PlayerFaceMaxie0:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_PlayerFaceMaxie:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_ArchieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_MaxieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
	delay_16
	delay_8
	walk_left
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer2:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieWatchMaxie:
	delay_16
	walk_in_place_faster_up
	step_end

MtPyre_Summit_Movement_PlayerWatchMaxie:
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie0:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie1:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie2:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_Text_Grunt1Intro:
	.string "Nao! Os capangas da Team Magma\n"
	.string "chegaram primeiro!\p"
	.string "Nao podemos ficar pra trás!$"

MtPyre_Summit_Text_Grunt1Defeat:
	.string "Achei que você era alguém da Team\n"
	.string "Magma voltando...$"

MtPyre_Summit_Text_Grunt1PostBattle:
	.string "Ta bom, você é forte... Mas tem um\n"
	.string "monte de gente do nosso lado!$"

MtPyre_Summit_Text_Grunt2Intro:
	.string "Hah! Deu azar!\p"
	.string "Se chegasse antes, só enfrentava\n"
	.string "aqueles fracos da Team Magma.\p"
	.string "Agora vai ter que enfrentar a\n"
	.string "gente!$"

MtPyre_Summit_Text_Grunt2Defeat:
	.string "Urgh... Devia ter deixado você\n"
	.string "enfrentar a Team Magma primeiro...$"

MtPyre_Summit_Text_Grunt2PostBattle:
	.string "Você nem sabe de nada! Por que ta\n"
	.string "se metendo?$"

MtPyre_Summit_Text_Grunt3Intro:
	.string "Você... A gente viu você no Mt.\n"
	.string "Chimney.\p"
	.string "Nao faz parte de nenhuma equipe,\n"
	.string "entao oque veio fazer aqui?$"

MtPyre_Summit_Text_Grunt3Defeat:
	.string "Se vai atrapalhar alguém,\n"
	.string "atrapalha a Team Magma...$"

MtPyre_Summit_Text_Grunt3PostBattle:
	.string "Heh, nao importa! Conseguimos\n"
	.string "ganhar tempo!\p"
	.string "O chefe já deve ter pegado oque\n"
	.string "queria!$"

MtPyre_Summit_Text_Grunt4Intro:
	.string "Ah, já sei! Você tentou entrar pra\n"
	.string "Team Magma e nao deixaram!\p"
	.string "Mas nem pense que a Team Aqua vai\n"
	.string "aceitar você!$"

MtPyre_Summit_Text_Grunt4Defeat:
	.string "Se quer tanto entrar pra Team\n"
	.string "Aqua, a gente pode conversar...\p"
	.string "Seu currículo acabou de melhorar\n"
	.string "bastante.$"

MtPyre_Summit_Text_Grunt4PostBattle:
	.string "Nós e nosso líder trabalhamos\n"
	.string "muito bem juntos.$"

MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo:
	.string "ARCHIE: Maxie chegou antes, mas\n"
	.string "também conseguimos oque queríamos.\p"
	.string "A Red Orb guardada no Mt. Pyre\n"
	.string "agora está comigo, Archie!\p"
	.string "Fufufu... Agora podemos realizar\n"
	.string "nosso grande objetivo!\p"
	.string "Muito bem, equipe! Vamos embora!$"

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
	.string "Ah, nao... Isso nao pode\n"
	.string "acontecer...\p"
	.string "Levaram a Blue Orb e também a Red\n"
	.string "Orb...\p"
	.string "As duas nunca deveriam ser\n"
	.string "separadas. Elas precisam ficar\l"
	.string "juntas.\p"
	.string "Oque aqueles homens querem fazer\n"
	.string "com elas?\p"
	.string "...\p"
	.string "Foi a Team Magma que veio buscar a\n"
	.string "Blue Orb primeiro, nao foi?\p"
	.string "Na pressa, deixaram isto aqui. Nao\n"
	.string "sei bem oque é.\p"
	.string "Quero que você fique com isso.\n"
	.string "Talvez seja útil.$"

MtPyre_Summit_Text_OrbsHaveBeenTaken:
	.string "Aqueles homens levaram a Blue Orb\n"
	.string "e a Red Orb...\p"
	.string "Elas nunca deveriam ficar\n"
	.string "separadas... Tenho medo do que\l"
	.string "pode acontecer...$"

MtPyre_Summit_Text_GroudonKyogreAwakened:
	.string "Meu Deus...\p"
	.string "Você disse que Groudon e Kyogre\n"
	.string "acordaram?\p"
	.string "Dizem que a Blue Orb e a Red Orb\n"
	.string "acalmaram a fúria dos dois\l"
	.string "Pokémon...\p"
	.string "E que o verdadeiro dono das Orbs\n"
	.string "ainda existe.\p"
	.string "Mas ninguém sabe a quem elas\n"
	.string "pertencem. Pode ser uma pessoa ou\l"
	.string "um Pokémon...$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
	.string "Os dois homens que levaram as Orbs\n"
	.string "voltaram pra devolver elas por\l"
	.string "vontade própria.\p"
	.string "Talvez nao sejam tao maus assim...$"

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
	.string "A terra, o mar e o céu...\p"
	.string "Dizem que os Pokémon antigos\n"
	.string "representam essas forças.\p"
	.string "Assim como nós e os Pokémon temos\n"
	.string "vida, nosso mundo também está\l"
	.string "vivo.\p"
	.string "Foi isso que eles nos ensinaram...$"

MtPyre_Summit_Text_WillYouHearOutMyTale:
	.string "No Mt. Pyre, acalmamos os\n"
	.string "espíritos dos Pokémon que já se\l"
	.string "foram.\p"
	.string "Daqui do alto, dá pra ver Hoenn\n"
	.string "inteira. Talvez isso traga paz pra\l"
	.string "eles...\p"
	.string "Será coincidência você estar aqui?\p"
	.string "Quer ouvir uma história antiga de\n"
	.string "Hoenn?$"

MtPyre_Summit_Text_GroudonKyogreTale:
	.string "Aconteceu há muito, muito tempo...\p"
	.string "O mundo foi abalado por uma\n"
	.string "batalha entre o Pokémon da terra e\l"
	.string "o Pokémon do mar.\p"
	.string "O da terra ergueu montanhas e\n"
	.string "criou continentes.\p"
	.string "O do mar levantou ondas enormes e\n"
	.string "abriu os oceanos.\p"
	.string "A luta parecia nao ter fim.\n"
	.string "Grandes incêndios e tempestades\l"
	.string "tomaram o mundo.\p"
	.string "A Blue Orb e a Red Orb acabaram\n"
	.string "com o desastre.\p"
	.string "A luz das duas acalmou os\n"
	.string "adversários furiosos.\p"
	.string "Depois, os dois mergulharam nas\n"
	.string "profundezas do mar e\l"
	.string "desapareceram...$"

MtPyre_Summit_Text_WellThatTooIsFine:
	.string "Entendo... Tudo bem, entao...$"

MtPyre_Summit_Text_MaxieSilence:
	.string "MAXIE: {PLAYER}...\p"
	.string "...$"

MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
	.string "Meu papel é passar as lendas de\n"
	.string "Hoenn pras próximas geraçoes.\p"
	.string "A crise que acabou em Sootopolis\n"
	.string "mudou uma dessas lendas...\p"
	.string "Tem tempo pra ouvir a nova\n"
	.string "história?$"

MtPyre_Summit_Text_HoennTrioTale:
	.string "Aconteceu há muito, muito tempo...\p"
	.string "O mundo foi abalado por uma\n"
	.string "batalha entre o Pokémon da terra e\l"
	.string "o Pokémon do mar.\p"
	.string "O da terra ergueu montanhas e\n"
	.string "criou continentes.\p"
	.string "O do mar levantou ondas enormes e\n"
	.string "abriu os oceanos.\p"
	.string "A luta parecia nao ter fim.\n"
	.string "Grandes incêndios e tempestades\l"
	.string "tomaram o mundo.\p"
	.string "Foi entao que o Pokémon do céu\n"
	.string "desceu da tempestade.\p"
	.string "Brilhando num verde intenso, ele\n"
	.string "acalmou os dois Pokémon furiosos.\p"
	.string "Com seu dever cumprido, o Pokémon\n"
	.string "verde voltou a voar pelo céu...$"

