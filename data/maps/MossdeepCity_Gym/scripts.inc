MossdeepCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
	.byte 0

@ NOTE: Mossdeep Gym was redesigned between R/S and E. Leftover (and now functionally unused) scripts are commented below

MossdeepCity_Gym_OnTransition:
	setflag FLAG_TEMP_HIDE_FOLLOWER @ Hide follower since it can collide with moving statues
	end

@ All the below checks are leftover from RS. FLAG_MOSSDEEP_GYM_SWITCH_X is never set
MossdeepCity_Gym_OnLoad:
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_CheckSwitch2::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_CheckSwitch3::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_CheckSwitch4::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
	end

@ All the below set metatile scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_SetSwitch1Metatiles::
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_SetSwitch2Metatiles::
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_SetSwitch3Metatiles::
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_SetSwitch4Metatiles::
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	end

MossdeepCity_Gym_EventScript_TateAndLiza::
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_Gym_EventScript_TateAndLizaRematch
	goto_if_unset FLAG_RECEIVED_TM_CALM_MIND, MossdeepCity_Gym_EventScript_GiveCalmMind2
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaDefeated::
	message MossdeepCity_Gym_Text_ReceivedMindBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_BADGE07_GET
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	clearflag FLAG_UNKNOWN_0x393
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setvar VAR_MOSSDEEP_CITY_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	call MossdeepCity_Gym_EventScript_GiveCalmMind
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind2::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	return

MossdeepCity_Gym_EventScript_TateAndLizaRematch::
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
	end

@ All the below switch scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed::
	special DrawWholeMapView
	playse SE_CLICK
	releaseall
	end

MossdeepCity_Gym_EventScript_ClearSwitch1::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch2::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Down, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch3::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch4::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_WarpToEntrance::
	lockall
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 7, 30
	waitstate
	releaseall
	end

MossdeepCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonIntro, MossdeepCity_Gym_Text_PrestonDefeat
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Virgil::
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilIntro, MossdeepCity_Gym_Text_VirgilDefeat
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakeIntro, MossdeepCity_Gym_Text_BlakeDefeat
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Hannah::
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_Gym_Text_HannahIntro, MossdeepCity_Gym_Text_HannahDefeat
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaIntro, MossdeepCity_Gym_Text_SamanthaDefeat
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Maura::
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraIntro, MossdeepCity_Gym_Text_MauraDefeat
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Sylvia::
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaIntro, MossdeepCity_Gym_Text_SylviaDefeat
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NateIntro, MossdeepCity_Gym_Text_NateDefeat
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Macey::
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyIntro, MossdeepCity_Gym_Text_MaceyDefeat
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Clifford::
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordIntro, MossdeepCity_Gym_Text_CliffordDefeat
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nicholas::
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasIntro, MossdeepCity_Gym_Text_NicholasDefeat
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Kathleen::
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenIntro, MossdeepCity_Gym_Text_KathleenDefeat
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

@ Leftover from RS, functionally unused
MossdeepCity_Gym_Movement_WaitAfterSwitchUse:
	delay_16
	delay_16
	step_end

MossdeepCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_GymStatueCertified::
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_GymStatue::
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_YellowFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_BlueFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 1
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_GreenFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 2
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_PurpleFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 3
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_RedFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 4
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_Text_GymGuideAdvice:
	.string "E aí, {PLAYER}, futuro campeao!\p"
	.string "Os líderes daqui usam Pokémon do\n"
	.string "tipo Psychic.\p"
	.string "Pokémon dos tipos Fighting ou\n"
	.string "Poison vao sofrer bastante contra\l"
	.string "eles.\p"
	.string "Eles também combinam muito bem os\n"
	.string "ataques.\p"
	.string "Pra vencer, você precisa mostrar\n"
	.string "sua parceria com seus Pokémon. Vai\l"
	.string "lá!$"

MossdeepCity_Gym_Text_GymGuidePostVictory:
	.string "Nossa, você é incrível! Que baita\n"
	.string "treinador!$"

MossdeepCity_Gym_Text_PrestonIntro:
	.string "Uma batalha depende da força do\n"
	.string "espírito! Quem tem o espírito\l"
	.string "fraco nao vence!$"

MossdeepCity_Gym_Text_PrestonDefeat:
	.string "Perdi! Preciso fortalecer meu\n"
	.string "espírito!$"

MossdeepCity_Gym_Text_PrestonPostBattle:
	.string "Quem fica em dúvida acaba\n"
	.string "perdendo. Fica o aviso.$"

MossdeepCity_Gym_Text_VirgilIntro:
	.string "Quero ver seu talento!$"

MossdeepCity_Gym_Text_VirgilDefeat:
	.string "Seu talento é incrível!$"

MossdeepCity_Gym_Text_VirgilPostBattle:
	.string "Se existem gênios no mundo, nossos\n"
	.string "líderes sao dois deles!\p"
	.string "Mas talvez você tenha ainda mais\n"
	.string "talento...$"

MossdeepCity_Gym_Text_BlakeIntro:
	.string "Fufufufu... Vou levantar esta Poké\n"
	.string "Ball com a força da mente!\p"
	.string "Uoooooaaaah!\p"
	.string "...\p"
	.string "Às vezes a mente ta sem sinal.$"

MossdeepCity_Gym_Text_BlakeDefeat:
	.string "Minha habilidade nas batalhas\n"
	.string "também ficou sem sinal!$"

MossdeepCity_Gym_Text_BlakePostBattle:
	.string "A Poké Ball era pesada demais. Mas\n"
	.string "este pedacinho de poeira...\p"
	.string "Fuuuuuuuh!\p"
	.string "...\p"
	.string "Nao tô trapaceando! Eu nao soprei,\n"
	.string "juro!$"

MossdeepCity_Gym_Text_HannahIntro:
	.string "Quando perder pra mim, nao fica\n"
	.string "triste.\p"
	.string "Você nao é fraco. Eu que sou\n"
	.string "forte demais!$"

MossdeepCity_Gym_Text_HannahDefeat:
	.string "Você é forte demais!$"

MossdeepCity_Gym_Text_HannahPostBattle:
	.string "Nao vou ficar triste por perder. Só\n"
	.string "preciso treinar mais.\p"
	.string "Pensar positivo é meu ponto forte!$"

MossdeepCity_Gym_Text_SamanthaIntro:
	.string "Eu vejo... Vejo seu futuro...\p"
	.string "Se conseguir me vencer, conto oque\n"
	.string "vai acontecer!$"

MossdeepCity_Gym_Text_SamanthaDefeat:
	.string "Eu me rendo!$"

MossdeepCity_Gym_Text_SamanthaPostBattle:
	.string "Você vai ter uma batalha muito\n"
	.string "difícil com nossos líderes...\p"
	.string "O resultado... Esse eu deixo pro\n"
	.string "próximo episódio!$"

MossdeepCity_Gym_Text_MauraIntro:
	.string "Os caminhos por onde passou...\n"
	.string "Tudo oque viveu...\p"
	.string "Venha com tudo oque aprendeu!$"

MossdeepCity_Gym_Text_MauraDefeat:
	.string "Você seguiu um grande caminho!$"

MossdeepCity_Gym_Text_MauraPostBattle:
	.string "Um bom futuro espera quem se\n"
	.string "esforça.\p"
	.string "Quem nao faz nada acaba se\n"
	.string "arrependendo.\p"
	.string "Cada um colhe oque planta...$"

MossdeepCity_Gym_Text_SylviaIntro:
	.string "Mesmo arriscando minha vida, vou\n"
	.string "vencer esta batalha!$"

MossdeepCity_Gym_Text_SylviaDefeat:
	.string "Oque você faz... Me assusta...$"

MossdeepCity_Gym_Text_SylviaPostBattle:
	.string "Como ousou me vencer...?\p"
	.string "Se alguma coisa ruim acontecer com\n"
	.string "você, a culpa nao é minha...$"

MossdeepCity_Gym_Text_NateIntro:
	.string "Hohoho.\p"
	.string "Vou mostrar como o tipo Psychic\n"
	.string "pode ser resistente.$"

MossdeepCity_Gym_Text_NateDefeat:
	.string "Ah! Seu jeito de batalhar é\n"
	.string "fantástico!$"

MossdeepCity_Gym_Text_NatePostBattle:
	.string "E-eu nao me abalo com uma\n"
	.string "derrota... P-por pior que seja.$"

MossdeepCity_Gym_Text_KathleenIntro:
	.string "Vou fazer você passar por um\n"
	.string "momento assustador!$"

MossdeepCity_Gym_Text_KathleenDefeat:
	.string "N-naaao!$"

MossdeepCity_Gym_Text_KathleenPostBattle:
	.string "Sua energia pega nos outros! Sai\n"
	.string "logo de perto de mim!$"

MossdeepCity_Gym_Text_CliffordIntro:
	.string "Posso já ter passado da minha\n"
	.string "melhor fase, mas é bom nao me\l"
	.string "tratar como um coitado.$"

MossdeepCity_Gym_Text_CliffordDefeat:
	.string "Ah, você tem muita energia de\n"
	.string "jovem!$"

MossdeepCity_Gym_Text_CliffordPostBattle:
	.string "Parece que nao consegui acompanhar\n"
	.string "sua energia.$"

MossdeepCity_Gym_Text_MaceyIntro:
	.string "Você nao vai chegar até o final!\n"
	.string "Nao se depender de mim!$"

MossdeepCity_Gym_Text_MaceyDefeat:
	.string "Como você consegue ser tao forte?$"

MossdeepCity_Gym_Text_MaceyPostBattle:
	.string "Hum! Você pode ser forte, mas nao\n"
	.string "combina com o tipo Psychic!\p"
	.string "Seu jeito de batalhar é bruto\n"
	.string "demais!$"

MossdeepCity_Gym_Text_NicholasIntro:
	.string "Uroooar! Sinta o poder dos meus\n"
	.string "Pokémon em batalha!$"

MossdeepCity_Gym_Text_NicholasDefeat:
	.string "Ah! Me derrotou!$"

MossdeepCity_Gym_Text_NicholasPostBattle:
	.string "Muito bem! Agora vou desenvolver\n"
	.string "um poder Pokémon invencível!$"

MossdeepCity_Gym_Text_TateAndLizaIntro:
	.string "TATE: Hehehe... Se surpreendeu?\n"
	.string "LIZA: Fufufu... Se surpreendeu?\p"
	.string "TATE: Com dois líderes no mesmo\n"
	.string "ginásio? LIZA: Com dois líderes no\l"
	.string "mesmo ginásio?\p"
	.string "TATE: Somos gêmeos! LIZA: Somos\n"
	.string "gêmeos!\p"
	.string "TATE: Nao precisamos falar\n"
	.string "porque... LIZA: Cada um consegue\l"
	.string "saber...\p"
	.string "TATE: Oque o outro ta pensando...\n"
	.string "LIZA: Só com a mente!\p"
	.string "TATE: E essa nossa parceria...\n"
	.string "LIZA: Você consegue vencer?$"

MossdeepCity_Gym_Text_TateAndLizaDefeat:
	.string "TATE: Oque?! Nossa parceria...\n"
	.string "LIZA: Foi vencida!\p"
	.string "TATE: Nao tem jeito. Você\n"
	.string "ganhou... LIZA: Entao aceite isto\l"
	.string "pelo seu esforço.$"

MossdeepCity_Gym_Text_ReceivedMindBadge:
	.string "{PLAYER} recebeu a Mind Badge de\n"
	.string "Tate e Liza.$"

MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis:
	.string "TATE: A Mind Badge aumenta a Sp.\n"
	.string "Atk e a Sp. Def dos Pokémon.\p"
	.string "LIZA: Também permite usar Dive\n"
	.string "fora das batalhas.\p"
	.string "TATE: Leve isto também.$"

MossdeepCity_Gym_Text_ExplainCalmMind:
	.string "TATE: A TM04 tem... LIZA: Calm\n"
	.string "Mind!\p"
	.string "TATE: Aumenta a Sp. Atk e... LIZA:\n"
	.string "A Sp. Def!\p"
	.string "TATE: É um golpe perfeito... LIZA:\n"
	.string "Pros Pokémon Psychic!\p"
	.string "...$"

MossdeepCity_Gym_Text_RegisteredTateAndLiza:
	.string "Os líderes Tate e Liza foram\n"
	.string "registrados no PokéNav.$"

MossdeepCity_Gym_Text_TateAndLizaPostBattle:
	.string "TATE: A parceria entre você e seus\n"
	.string "Pokémon parece ainda mais forte\l"
	.string "que a nossa uniao de gêmeos.\p"
	.string "LIZA: Você ainda vai ficar muito\n"
	.string "mais forte! Batalhamos com você,\l"
	.string "entao sabemos.$"

MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons:
	.string "TATE: Hehehe... Se surpreendeu?\p"
	.string "LIZA: Com dois líderes no mesmo\n"
	.string "ginásio?\p"
	.string "TATE: Opa, você só tem um... LIZA:\n"
	.string "Pokémon pronto pra batalhar.\p"
	.string "TATE: Assim nao podemos lutar!\p"
	.string "LIZA: Traga mais Pokémon se quiser\n"
	.string "desafiar a gente.$"

MossdeepCity_Gym_Text_GymStatue:
	.string "Ginásio Pokémon de Mossdeep City$"

MossdeepCity_Gym_Text_GymStatueCertified:
	.string "Ginásio Pokémon de Mossdeep City\p"
	.string "Treinadores aprovados por Liza e\n"
	.string "Tate: {PLAYER}$"

MossdeepCity_Gym_Text_TateAndLizaPreRematch:
	.string "TATE: Pokémon... LIZA: Pokémon...\p"
	.string "TATE: Quando você muda a equipe...\n"
	.string "LIZA: O jeito de batalhar também\l"
	.string "muda.\p"
	.string "TATE: Mas eu... LIZA: Mas eu...\p"
	.string "TATE: Sempre vou ficar com Liza!\n"
	.string "LIZA: Sempre vou ficar com Tate!\p"
	.string "TATE: Nossa parceria... LIZA:\n"
	.string "Vamos mostrar quantas vezes\l"
	.string "precisar!$"

MossdeepCity_Gym_Text_TateAndLizaRematchDefeat:
	.string "TATE: Você e seus Pokémon... LIZA:\n"
	.string "Parecem até irmaos!$"

MossdeepCity_Gym_Text_TateAndLizaPostRematch:
	.string "TATE: Pode derrubar a gente, mas\n"
	.string "sempre vamos levantar!\p"
	.string "LIZA: Porque um sempre apoia o\n"
	.string "outro!$"

MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons:
	.string "TATE: Você voltou... LIZA: Você\n"
	.string "voltou...\p"
	.string "TATE: Pra uma revanche. LIZA: Pra\n"
	.string "uma revanche.\p"
	.string "TATE: Mas... LIZA: Pra esta\n"
	.string "batalha...\p"
	.string "TATE: Você só trouxe um Pokémon!\n"
	.string "LIZA: Você só trouxe um Pokémon!\p"
	.string "TATE: Precisa voltar com pelo\n"
	.string "menos... LIZA: Dois Pokémon.$"
