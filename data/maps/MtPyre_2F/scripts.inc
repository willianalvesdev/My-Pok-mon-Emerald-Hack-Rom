MtPyre_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_SetHoleWarp
	.byte 0

MtPyre_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MT_PYRE_1F
	end

MtPyre_2F_EventScript_Woman::
	msgbox MtPyre_2F_Text_MemoriesOfSkitty, MSGBOX_NPC
	end

MtPyre_2F_EventScript_PokefanM::
	msgbox MtPyre_2F_Text_TumbledFromFloorAbove, MSGBOX_NPC
	end

MtPyre_2F_EventScript_Mark::
	trainerbattle_single TRAINER_MARK, MtPyre_2F_Text_MarkIntro, MtPyre_2F_Text_MarkDefeat
	msgbox MtPyre_2F_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Luke::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_LukeIntro, MtPyre_2F_Text_LukeDefeat, MtPyre_2F_Text_LukeNotEnoughMons
	msgbox MtPyre_2F_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Dez::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_DezIntro, MtPyre_2F_Text_DezDefeat, MtPyre_2F_Text_DezNotEnoughMons
	msgbox MtPyre_2F_Text_DezPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Leah::
	trainerbattle_single TRAINER_LEAH, MtPyre_2F_Text_LeahIntro, MtPyre_2F_Text_LeahDefeat
	msgbox MtPyre_2F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Zander::
	trainerbattle_single TRAINER_ZANDER, MtPyre_2F_Text_ZanderIntro, MtPyre_2F_Text_ZanderDefeat
	msgbox MtPyre_2F_Text_ZanderPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_Text_MemoriesOfSkitty:
	.string "As lembranças do meu querido\n"
	.string "Skitty... Só de pensar, meus olhos\l"
	.string "enchem de lágrimas.$"

MtPyre_2F_Text_TumbledFromFloorAbove:
	.string "Ai, ai... Tem buracos espalhados\n"
	.string "pelo chao.\p"
	.string "Nao percebi e caí do andar de\n"
	.string "cima.$"

MtPyre_2F_Text_MarkIntro:
	.string "Ei! Ta procurando Pokémon? Você\n"
	.string "veio atrás de mim! Que falta de\l"
	.string "educaçao!$"

MtPyre_2F_Text_MarkDefeat:
	.string "Aiiih! Desculpa, me perdoa!$"

MtPyre_2F_Text_MarkPostBattle:
	.string "Pouca gente vem aqui. Achei que ia\n"
	.string "encontrar Pokémon raros.$"

MtPyre_2F_Text_LukeIntro:
	.string "LUKE: Viemos testar nossa coragem.\p"
	.string "Heheh, se eu mostrar como sou bom,\n"
	.string "ela vai se apaixonar de vez. Tenho\l"
	.string "certeza!\p"
	.string "Já sei! Vou te vencer pra ela ver!$"

MtPyre_2F_Text_LukeDefeat:
	.string "LUKE: Opa...$"

MtPyre_2F_Text_LukePostBattle:
	.string "LUKE: A gente perdeu, mas tudo\n"
	.string "bem! Tô aqui do seu lado. Vamos\l"
	.string "passar por isso juntos!$"

MtPyre_2F_Text_LukeNotEnoughMons:
	.string "LUKE: Se quiser enfrentar a gente,\n"
	.string "traga mais Pokémon.\p"
	.string "Senao nao vou conseguir mostrar\n"
	.string "pra minha garota como sou bom!$"

MtPyre_2F_Text_DezIntro:
	.string "DEZ: Vim testar minha coragem com\n"
	.string "meu namorado.\p"
	.string "É assustador, mas com ele do lado\n"
	.string "fica tudo bem.\p"
	.string "Já sei! Vamos vencer você pro meu\n"
	.string "namorado mostrar como é forte!$"

MtPyre_2F_Text_DezDefeat:
	.string "DEZ: Uaaaah! Tô com medo!$"

MtPyre_2F_Text_DezPostBattle:
	.string "DEZ: A gente se ama, entao nem\n"
	.string "liga se perder!$"

MtPyre_2F_Text_DezNotEnoughMons:
	.string "DEZ: Se quiser desafiar a gente,\n"
	.string "traga pelo menos dois Pokémon.\p"
	.string "Meu namorado é forte. Com um só,\n"
	.string "nao vai dar.$"

MtPyre_2F_Text_LeahIntro:
	.string "Nunca vi você por aqui... Vá\n"
	.string "embora antes que alguma coisa\l"
	.string "aconteça!$"

MtPyre_2F_Text_LeahDefeat:
	.string "Hum... Você aguenta bastante.$"

MtPyre_2F_Text_LeahPostBattle:
	.string "Minha família treina aqui desde a\n"
	.string "época da minha bisavó...\p"
	.string "É meu dever proteger esta\n"
	.string "montanha...$"

MtPyre_2F_Text_ZanderIntro:
	.string "Kiaaaaah! Que medo!$"

MtPyre_2F_Text_ZanderDefeat:
	.string "Naaao! Perdi a cabeça!$"

MtPyre_2F_Text_ZanderPostBattle:
	.string "Me assusto com qualquer coisa que\n"
	.string "se mexe...\p"
	.string "Nao devia ter vindo treinar aqui.$"

