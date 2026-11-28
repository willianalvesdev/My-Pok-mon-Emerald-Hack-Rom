PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject LOCALID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_HOUSE_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string "Você é... Ah, {PLAYER}{KUN}, né?\p"
	.string "Obrigado por passar um tempo com\n"
	.string "Wally.\p"
	.string "Ele tem a saúde frágil desde bebê.\n"
	.string "Mandamos ele passar um tempo com\l"
	.string "nossos parentes em Verdanturf\l"
	.string "Town.\p"
	.string "O ar de lá é bem mais limpo.\p"
	.string "Oque? Cadê Wally? Ele já foi.\p"
	.string "Onde será que ele ta agora?$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string "Como será que Wally ta?$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string "{PLAYER}{KUN}! Desculpa trazer você\n"
	.string "assim, de repente.\p"
	.string "Wally melhorou muito desde que foi\n"
	.string "pra Verdanturf Town. Devemos isso\l"
	.string "a você!\p"
	.string "Você ajudou ele a capturar um\n"
	.string "Pokémon antes de sair daqui, né?\p"
	.string "Aquilo deixou ele muito feliz. E\n"
	.string "eu, como pai, também fiquei.\p"
	.string "É bom saber que ele tem uma\n"
	.string "amizade como a sua.\p"
	.string "Nao é pra comprar sua amizade nem\n"
	.string "nada, mas queria dar isto a você.$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.string "Se seu Pokémon souber Surf, você\n"
	.string "vai poder conhecer um monte de\l"
	.string "lugares.$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string "Wally vai voltar pra casa em\n"
	.string "breve. Tô ansioso por isso.$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string "Hein? Você viu Wally em Ever\n"
	.string "Grande City?\p"
	.string "Ah, {PLAYER}{KUN}, nao brinca.\p"
	.string "Ele pode estar melhor, mas nao iria\n"
	.string "tao longe sozinho.$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string "Wally contou tao feliz que tinha\n"
	.string "capturado um Pokémon...\p"
	.string "Fazia tempo que nao via ele sorrir\n"
	.string "assim.$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string "Nao conta pro meu marido...\p"
	.string "Mas Wally saiu de Verdanturf Town\n"
	.string "sem avisar ninguém.\p"
	.string "Ele pode ter a saúde frágil, mas\n"
	.string "tem uma vontade enorme.\p"
	.string "Tenho certeza que um dia volta pra\n"
	.string "casa sao e salvo!$"

