SeafloorCavern_Room9_MapScripts::
	.byte 0

SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre::
	lockall
	setvar VAR_0x8004, LOCALID_SEAFLOOR_CAVERN_ARCHIE
	setvar VAR_0x8005, LOCALID_SEAFLOOR_CAVERN_MAXIE
	setvar VAR_0x8006, LOCALID_SEAFLOOR_CAVERN_GRUNT_1
	setvar VAR_0x8007, LOCALID_SEAFLOOR_CAVERN_GRUNT_2
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_PLAYER, SeafloorCavern_Room9_Movement_Delay32
	waitmovement 0
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SeafloorCavern_Room9_Text_ArchieHoldItRightThere, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8004
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieSoItWasYou, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieBeholdKyogre, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieYouMustDisappear, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ARCHIE, SeafloorCavern_Room9_Text_ArchieDefeat
	msgbox SeafloorCavern_Room9_Text_ArchieWithThisRedOrb, MSGBOX_DEFAULT
	setweather WEATHER_NONE
	doweather
	special Script_FadeOutMapMusic
	msgbox SeafloorCavern_Room9_Text_RedOrbShinesByItself, MSGBOX_DEFAULT
	special WaitWeather
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 16, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	closemessage
	setvar VAR_RESULT, 0
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_SEAFLOOR_CAVERN_KYOGRE_SLEEPING
	addobject LOCALID_SEAFLOOR_CAVERN_KYOGRE
	waitstate
	delay 60
	applymovement LOCALID_SEAFLOOR_CAVERN_KYOGRE, SeafloorCavern_Room9_Movement_KyogreApproach
	waitmovement 0
	special FadeOutOrbEffect
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_SEAFLOOR_CAVERN_KYOGRE, SeafloorCavern_Room9_Movement_KyogreExit
	waitmovement 0
	removeobject LOCALID_SEAFLOOR_CAVERN_KYOGRE
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	setvar VAR_0x8004, LOCALID_SEAFLOOR_CAVERN_ARCHIE
	setvar VAR_0x8005, LOCALID_SEAFLOOR_CAVERN_MAXIE
	setvar VAR_0x8006, LOCALID_SEAFLOOR_CAVERN_GRUNT_1
	setvar VAR_0x8007, LOCALID_SEAFLOOR_CAVERN_GRUNT_2
	msgbox SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo, MSGBOX_DEFAULT
	playse SE_PC_LOGIN
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieAMessageFromOutside, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieListenMessage
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard, MSGBOX_DEFAULT
	closemessage
	playse SE_PC_OFF
	delay 20
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8005
	addobject VAR_0x8006
	addobject VAR_0x8007
	applymovement VAR_0x8007, SeafloorCavern_Room9_Movement_MagmaGruntArrive
	applymovement VAR_0x8006, SeafloorCavern_Room9_Movement_MagmaGruntArrive
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieArrive
	waitmovement 0
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement VAR_0x8004, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8004, Common_Movement_Delay48
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty, MSGBOX_DEFAULT
	msgbox SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieExit
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieExit
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_MaxieComeOnPlayer, MSGBOX_DEFAULT
	setvar VAR_ROUTE128_STATE, 1
	setvar VAR_SOOTOPOLIS_CITY_STATE, 1
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	clearflag FLAG_HIDE_ROUTE_128_ARCHIE
	clearflag FLAG_HIDE_ROUTE_128_MAXIE
	setflag FLAG_SYS_WEATHER_CTRL
	setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	setvar VAR_STEVENS_HOUSE_STATE, 2
	setvar VAR_SEAFLOOR_CAVERN_STATE, 1
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS
	setflag FLAG_HIDE_MAP_NAME_POPUP
	warp MAP_ROUTE128, 38, 22
	waitstate
	releaseall
	end

SeafloorCavern_Room9_Movement_ArchieApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_Unused1:
	walk_left
	walk_left
	step_end

SeafloorCavern_Room9_Movement_ArchieListenMessage:
	walk_left
	delay_16
	step_end

SeafloorCavern_Room9_Movement_Unused2:
	walk_right
	step_end

SeafloorCavern_Room9_Movement_ArchieExit:
	face_up
	lock_facing_direction
	walk_down
	unlock_facing_direction
	walk_in_place_faster_right
	step_end

SeafloorCavern_Room9_Movement_KyogreApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

SeafloorCavern_Room9_Movement_KyogreExit:
	slide_up
	slide_up
	step_end

SeafloorCavern_Room9_Movement_MaxieArrive:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeafloorCavern_Room9_Movement_MaxieExit:
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_MagmaGruntArrive:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeafloorCavern_Room9_Movement_Delay32:
	delay_16
	delay_16
	step_end

SeafloorCavern_Room9_Text_ArchieHoldItRightThere:
	.string "ARCHIE: Pare aí.$"

SeafloorCavern_Room9_Text_ArchieSoItWasYou:
	.string "ARCHIE: Fufufu... Entao era você\n"
	.string "mesmo.$"

SeafloorCavern_Room9_Text_ArchieBeholdKyogre:
	.string "ARCHIE: Contemple!\p"
	.string "Veja como é bela a forma\n"
	.string "adormecida do antigo Pokémon\l"
	.string "Kyogre!\p"
	.string "Esperei tanto por este dia...$"

SeafloorCavern_Room9_Text_ArchieYouMustDisappear:
	.string "ARCHIE: Me surpreende que tenha\n"
	.string "conseguido me seguir até aqui.\p"
	.string "Mas tudo acaba agora.\p"
	.string "Pra realizar meu sonho, preciso\n"
	.string "tirar você do caminho!$"

SeafloorCavern_Room9_Text_ArchieDefeat:
	.string "Oque?! Perdi pra uma criança como\n"
	.string "você?!$"

SeafloorCavern_Room9_Text_ArchieWithThisRedOrb:
	.string "ARCHIE: Fufufu...\p"
	.string "Reconheço seu talento. Você é\n"
	.string "muito bom.\p"
	.string "Mas eu tenho isto!\p"
	.string "Com esta Red Orb, posso fazer\n"
	.string "Kyogre...$"

SeafloorCavern_Room9_Text_RedOrbShinesByItself:
	.string "A Red Orb começou a brilhar\n"
	.string "sozinha!$"

SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo:
	.string "ARCHIE: Oque?!\p"
	.string "Nao fiz nada. Por que a Red Orb...\p"
	.string "Pra onde Kyogre foi?$"

SeafloorCavern_Room9_Text_ArchieAMessageFromOutside:
	.string "ARCHIE: Hum? É uma mensagem do\n"
	.string "nosso pessoal lá fora...$"

SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard:
	.string "ARCHIE: Sim, oque foi?\p"
	.string "Hum... Está chovendo muito?\p"
	.string "Ótimo. Era oque deveria acontecer.\n"
	.string "Acordamos Kyogre pra realizar o\l"
	.string "plano da Team Aqua de aumentar os\l"
	.string "mares.\p"
	.string "Oque?! Chove muito mais do que\n"
	.string "esperávamos? Vocês estao em\l"
	.string "perigo?\p"
	.string "Nao pode ser... Isso nao é\n"
	.string "possível...\p"
	.string "Fiquem aí e acompanhem a situaçao!$"

SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear:
	.string "ARCHIE: Tem alguma coisa errada...\p"
	.string "A Red Orb deveria acordar e\n"
	.string "controlar Kyogre...\p"
	.string "Mas por quê? Por que ele\n"
	.string "desapareceu?\p"
	.string "Por quê?!$"

SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought:
	.string "MAXIE: Oque você fez, Archie?\p"
	.string "Finalmente acordou Kyogre, nao é?\p"
	.string "Oque vai acontecer se esta chuva\n"
	.string "nunca parar?\p"
	.string "Os continentes vao afundar no\n"
	.string "mar...$"

SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty:
	.string "ARCHIE: O-oque?! Nao venha agir\n"
	.string "como se fosse melhor que eu!\p"
	.string "Nao foi a Team Magma que provocou\n"
	.string "a fúria de Groudon?\p"
	.string "Enquanto eu tiver esta Red Orb,\n"
	.string "devo conseguir controlar Kyogre...\p"
	.string "Eu deveria conseguir...$"

SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue:
	.string "MAXIE: Nao temos tempo pra\n"
	.string "discutir aqui!\p"
	.string "Saia e veja com seus próprios\n"
	.string "olhos!\p"
	.string "Veja se o mundo que criou é aquele\n"
	.string "que desejávamos!$"

SeafloorCavern_Room9_Text_MaxieComeOnPlayer:
	.string "MAXIE: {PLAYER}, venha! Você\n"
	.string "também precisa sair daqui!$"
