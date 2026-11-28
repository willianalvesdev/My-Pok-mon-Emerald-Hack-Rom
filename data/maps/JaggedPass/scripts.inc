JaggedPass_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
	.byte 0

JaggedPass_OnResume:
	setstepcallback STEP_CB_ASH
	call_if_eq VAR_JAGGED_PASS_STATE, 0, JaggedPass_EventScript_CheckHasMagmaEmblem
	end

JaggedPass_EventScript_CheckHasMagmaEmblem::
	checkitem ITEM_MAGMA_EMBLEM
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
	return

JaggedPass_EventScript_SetReadyToOpenHideout::
	setvar VAR_JAGGED_PASS_STATE, 1
	return

JaggedPass_OnTransition:
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
	end

JaggedPass_EventScript_SetWeatherAsh::
	setweather WEATHER_VOLCANIC_ASH
	doweather
	return

JaggedPass_OnLoad:
	goto_if_le VAR_JAGGED_PASS_STATE, 1, JaggedPass_EventScript_ConcealHideoutEntrance
	end

JaggedPass_EventScript_ConcealHideoutEntrance::
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
	end

JaggedPass_EventScript_OpenMagmaHideout::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 3   @ shake delay
	special ShakeCamera
	waitstate
	playse SE_EFFECTIVE
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
	special DrawWholeMapView
	delay 30
	setvar VAR_JAGGED_PASS_STATE, 2
	waitse
	releaseall
	end

JaggedPass_EventScript_MagmaHideoutGuard::
	lockall
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
	waitse
	playse SE_PIN
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_GuardDefeated::
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat, JaggedPass_EventScript_RegisterDiana
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_DianaRematch
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterDiana::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DIANA_1
	release
	end

JaggedPass_EventScript_DianaRematch::
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterEthan::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ETHAN_1
	release
	end

JaggedPass_EventScript_EthanRematch::
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Julio::
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Autumn::
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_Text_EricIntro:
	.string "JAGGED PASS, no MT. CHIMNEY...\p"
	.string "Isso sim é oque eu queria numa\n"
	.string "montanha!\p"
	.string "Esse chao cheio de pedras... Mexe\n"
	.string "com minha alma!$"

JaggedPass_Text_EricDefeat:
	.string "Essa derrota deixou um gosto\n"
	.string "amargo!$"

JaggedPass_Text_EricPostBattle:
	.string "Ta bom, perdi na batalha\n"
	.string "Pokémon...\p"
	.string "Mas em amor pelas montanhas, eu\n"
	.string "ganho de você!$"

JaggedPass_Text_DianaIntro:
	.string "Aqui nao é lugar de caminhada\n"
	.string "tranquila. Nao serve pra fazer\l"
	.string "piquenique.$"

JaggedPass_Text_DianaDefeat:
	.string "Ah, nao! O chao é irregular\n"
	.string "demais...$"

JaggedPass_Text_DianaPostBattle:
	.string "Sabia que tem gente que consegue\n"
	.string "subir esse caminho cheio de pedras\l"
	.string "de bicicleta?$"

JaggedPass_Text_DianaRegister:
	.string "Você vai passar por aqui de novo?\n"
	.string "Se voltar, quero uma revanche.$"

JaggedPass_Text_DianaRematchIntro:
	.string "Piquenique é divertido em qualquer\n"
	.string "lugar. Igual aos POKÉMONS!$"

JaggedPass_Text_DianaRematchDefeat:
	.string "Só perdi porque o chao é irregular\n"
	.string "demais!\p"
	.string "Nao foi falta de treino, foi\n"
	.string "excesso de pedra!$"

JaggedPass_Text_DianaPostRematch:
	.string "Vou esquecer a derrota e\n"
	.string "aproveitar a caminhada.$"

JaggedPass_Text_EthanIntro:
	.string "É difícil andar em JAGGED PASS. Um\n"
	.string "bom lugar pra treinar.$"

JaggedPass_Text_EthanDefeat:
	.string "Acabou tudo enquanto a gente\n"
	.string "ainda procurava onde pisar...$"

JaggedPass_Text_EthanPostBattle:
	.string "Se eu tivesse uma ACRO BIKE,\n"
	.string "conseguiria pular essas bordas.$"

JaggedPass_Text_EthanRegister:
	.string "Quando me acostumar com esse\n"
	.string "chao, vou ganhar com certeza!\p"
	.string "Pode me registrar no seu POKéNAV?$"

JaggedPass_Text_EthanRematchIntro:
	.string "Já me acostumei com esse chao.\n"
	.string "Agora até canto enquanto subo.$"

JaggedPass_Text_EthanRematchDefeat:
	.string "Ainda nao é fácil batalhar nesse\n"
	.string "chao cheio de pedras...$"

JaggedPass_Text_EthanPostRematch:
	.string "Preciso buscar uma ACRO BIKE com\n"
	.string "RYDEL, em MAUVILLE CITY...$"

JaggedPass_Text_GruntIntro:
	.string "Ah! Oque você ta fazendo aqui?\p"
	.string "Oque eu tô fazendo num lugar\n"
	.string "desses?\p"
	.string "Desde quando eu preciso te dar\n"
	.string "satisfaçao?$"

JaggedPass_Text_GruntDefeat:
	.string "Urgh...\p"
	.string "Devia ter entrado logo no\n"
	.string "esconderijo...$"

JaggedPass_Text_GoWhereverYouWant:
	.string "Ta bom, ta bom! Eu admito, você é\n"
	.string "forte!\p"
	.string "Esquece de mim. Vá pra onde\n"
	.string "quiser!$"

JaggedPass_Text_BoulderShakingInResponseToEmblem:
	.string "Ah! Essa pedra está tremendo por\n"
	.string "causa do MAGMA EMBLEM!$"

JaggedPass_Text_JulioIntro:
	.string "Aaah! Descer a montanha de uma\n"
	.string "vez só dá um medo!$"

JaggedPass_Text_JulioDefeat:
	.string "Parece que tô me desmontando...$"

JaggedPass_Text_JulioPostBattle:
	.string "Minha bicicleta pulou tanto que\n"
	.string "minha bunda ta doendo...$"

JaggedPass_Text_AutumnIntro:
	.string "Subo essa colina todo dia. Confio\n"
	.string "na minha força!$"

JaggedPass_Text_AutumnDefeat:
	.string "Hum... Oque deu errado?$"

JaggedPass_Text_AutumnPostBattle:
	.string "Oque é aquela pedra estranha um\n"
	.string "pouco mais acima?$"

