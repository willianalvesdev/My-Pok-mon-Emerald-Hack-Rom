SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 1
	end

SootopolisCity_Gym_1F_OnResume:
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad:
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
	goto_if_lt VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	goto_if_lt VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs::
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs::
	return

SootopolisCity_Gym_1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement LOCALID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_Juan::
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_JuanDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_JuanRematch
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanDefeated::
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge::
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanRematch::
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreRematch, SootopolisCity_Gym_1F_Text_JuanRematchDefeat, SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified::
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue::
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "E aí, {PLAYER}, futuro campeao!\p"
	.string "Juan, líder de Sootopolis, é\n"
	.string "especialista em Pokémon Water.\p"
	.string "Pra chegar até ele, você precisa\n"
	.string "passar pelo chao de gelo...\p"
	.string "Desculpa, mas é só isso que sei. O\n"
	.string "resto é com você!$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "Nossa! Venceu até Juan, que diziam\n"
	.string "ser o melhor de Hoenn!\p"
	.string "Confira seu cartao de treinador.\p"
	.string "Se já tem todas as insígnias, pode\n"
	.string "desafiar a Liga Pokémon!$"

SootopolisCity_Gym_1F_Text_JuanIntro:
	.string "Deixe eu perguntar: você sabia?\n"
	.string "Ah, nao preciso fazer tanto\l"
	.string "mistério.\p"
	.string "Fui eu que ensinei a Wallace tudo\n"
	.string "sobre Pokémon.\p"
	.string "Um dia deixei meu posto de líder e\n"
	.string "confiei o ginásio a ele.\p"
	.string "Mas surgiu um bom motivo pra eu\n"
	.string "voltar.\p"
	.string "Já conversamos bastante. Vamos\n"
	.string "começar?\p"
	.string "Quero que veja nossa arte: uma\n"
	.string "grande ilusao de água criada por\l"
	.string "mim e meus Pokémon!$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
SootopolisCity_Gym_1F_Text_JuanDefeat:
	.string "Ahahaha, excelente! Muito bem,\n"
	.string "você venceu.\p"
	.string "Vejo em você um talento capaz de\n"
	.string "superar qualquer desafio.\p"
	.string "Mas, perto de mim ou de Wallace,\n"
	.string "ainda falta um pouco de elegância.\p"
	.string "Quer meu casaco emprestado?\p"
	.string "...\p"
	.string "Hahaha, é brincadeira!\p"
	.string "No lugar da roupa, vou dar a Rain\n"
	.string "Badge!$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{PLAYER} recebeu a Rain Badge de\n"
	.string "Juan.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "Com a Rain Badge, todos os seus\n"
	.string "Pokémon vao obedecer a você.\p"
	.string "Ela também permite usar Waterfall\n"
	.string "pra subir cachoeiras.\p"
	.string "E, pra lembrar da nossa batalha,\n"
	.string "leve isto...$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "A TM que entreguei tem Water\n"
	.string "Pulse.\p"
	.string "As ondas do golpe às vezes deixam\n"
	.string "o alvo confuso.\p"
	.string "...$"

SootopolisCity_Gym_1F_Text_RegisteredJuan:
	.string "O líder Juan foi registrado no\n"
	.string "PokéNav.$"

SootopolisCity_Gym_1F_Text_JuanPostBattle:
	.string "Quem reúne todas as insígnias de\n"
	.string "Hoenn deve seguir pro grande\l"
	.string "desafio: a Liga Pokémon.\p"
	.string "Viaje até o extremo leste de\n"
	.string "Hoenn, na ilha Ever Grande.\p"
	.string "É lá que fica a Liga.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "Falta só uma insígnia de Hoenn.\p"
	.string "Se quiser desafiar a Liga, precisa\n"
	.string "vencer o ginásio de Fortree.$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "Ginásio Pokémon de Sootopolis City$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string "Ginásio Pokémon de Sootopolis City\p"
	.string "Treinadores aprovados por Juan:\n"
	.string "{PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch:
	.string "JUAN: Ah, este ginásio tinha\n"
	.string "voltado à paz de sempre...\p"
	.string "Mas nosso jovem furacao voltou\n"
	.string "pra testar a gente!\p"
	.string "Claro, meu amigo! Vou adorar\n"
	.string "dançar com você quantas vezes\l"
	.string "quiser!$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
	.string "Ahahaha, você venceu! Me derrotou\n"
	.string "de novo!$"

SootopolisCity_Gym_1F_Text_JuanPostRematch:
	.string "JUAN: Se pedisse que fosse meu\n"
	.string "aprendiz, sei que você recusaria.\p"
	.string "Queria dar meu casaco a você, mas\n"
	.string "imagino que também recusaria.\p"
	.string "Isso, meu amigo, é um sinal de\n"
	.string "grandeza!$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
	.string "JUAN: Ah, este ginásio tinha\n"
	.string "voltado à paz de sempre...\p"
	.string "Mas nosso jovem furacao voltou\n"
	.string "pra testar a gente!\p"
	.string "Vou adorar dançar com você...\p"
	.string "Ah, nao. Você só trouxe um\n"
	.string "Pokémon.\p"
	.string "Volte com pelo menos dois, por\n"
	.string "favor.$"

