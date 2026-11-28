AquaHideout_1F_MapScripts::
	.byte 0

@ The below two entrance guards give hints about what to do to progress the story
AquaHideout_1F_EventScript_HideoutEntranceGrunt1::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint1::
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint1::
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_HideoutEntranceGrunt2::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint2::
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint2::
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_1, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_Grunt1Defeated::
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_OurBossIsSnatchingSomething:
	.string "O que você veio fazer aqui? nao ta\n"
	.string "vendo que aqui é a base do Team\l"
	.string "Aqua?\p"
	.string "Se veio atrás do chefe ele nao\n"
	.string "está aqui, ele foi buscar algo\l"
	.string "importante.\p"
	.string "... onde?\p"
	.string "Isso nao é da sua conta.$"

AquaHideout_1F_Text_WhereMightMagmaHideoutBe:
	.string "Ei Ei, por acaso você é um capanga\n"
	.string "do Team Magma?\p"
	.string "Ouvi dizer que o Team Magma está a\n"
	.string "tentar acordar um POKéMON\l"
	.string "fantástico em seu esconderijo.\p"
	.string "Mas onde será que é o esconderijo\n"
	.string "deles?$"

AquaHideout_1F_Text_BossWentToJackASubmarine:
	.string "Ei Ei Ei, Oque você ta fazendo\n"
	.string "aqui?\p"
	.string "O nosso chefe nao está aqui, ele\n"
	.string "saiu em um submarino.\p"
	.string "... onde ele foi?\p"
	.string "Acha mesmo que vou te contar?$"

AquaHideout_1F_Text_BossIsOnRoute122:
	.string "Quem é você? Oque ta fazendo\n"
	.string "aqui?\p"
	.string "O nosso chefe nao está aqui, ele\n"
	.string "foi ao MT. PYRE na ROUTE 122.\p"
	.string "... porque ele foi pra lá?\p"
	.string "Nao sei, sou novo aqui, nao me\n"
	.string "falaram nada.$"

AquaHideout_1F_Text_TeamMagmaAtMtChimney:
	.string "Por acaso você é um capanga do\n"
	.string "Team Magma?\p"
	.string "Falam por ai que o Team Magma está\n"
	.string "a tentar despertar um POKéMON\l"
	.string "muito forte no MT. CHIMNEY.\p"
	.string "Que pokémon será que é?$"

AquaHideout_1F_Text_BossIsInSlateportCity:
	.string "Quem é você? Oque ta fazendo\n"
	.string "aqui?\p"
	.string "O nosso chefe nao está aqui, ele\n"
	.string "foi pra SLATEPORT CITY!\p"
	.string "... porque ele foi pra lá?\p"
	.string "Nao sei, nao quero saber, e tenho\n"
	.string "raiva de quem sabe.$"

AquaHideout_1F_Text_Grunt1Intro:
	.string "Ayiyiyi! Um esquisitao avistado!$"

AquaHideout_1F_Text_Grunt1Defeat:
	.string "Droga, eu perdi....$"

AquaHideout_1F_Text_Grunt1PostBattle:
	.string "Eu aceito a derrota, mas eu dei\n"
	.string "meu melhor...$"

