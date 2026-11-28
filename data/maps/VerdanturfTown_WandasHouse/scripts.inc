VerdanturfTown_WandasHouse_MapScripts::
	.byte 0

VerdanturfTown_WandasHouse_EventScript_Wally::
	lock
	faceplayer
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeech, MSGBOX_DEFAULT
	setflag FLAG_WALLY_SPEECH
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech::
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeechShort, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff
	msgbox VerdanturfTown_WandasHouse_Text_WallysNextDoor, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff::
	msgbox VerdanturfTown_WandasHouse_Text_WallySlippedOff, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyGoneThatFar, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandasBoyfriend::
	msgbox VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay, MSGBOX_NPC
	end

VerdanturfTown_WandasHouse_EventScript_Wanda::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WandaDontWorry
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_MeetWanda
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_MeetWanda::
	msgbox VerdanturfTown_WandasHouse_Text_MeetWanda, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaDontWorry::
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAunt::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen::
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened::
	msgbox VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_Text_StrongerSpeech:
	.string "WALLY: Perdi pra você, {PLAYER},\n"
	.string "mas já nao tô triste.\p"
	.string "Encontrei um objetivo novo. Com\n"
	.string "meu Ralts, vou desafiar os\l"
	.string "ginásios e virar um grande\l"
	.string "treinador.\p"
	.string "Pode esperar, {PLAYER}. Vou ficar\n"
	.string "mais forte que você.\p"
	.string "Quando conseguir, vou pedir outra\n"
	.string "batalha.$"

VerdanturfTown_WandasHouse_Text_StrongerSpeechShort:
	.string "WALLY: Pode esperar, {PLAYER}. Vou\n"
	.string "ficar mais forte que você.\p"
	.string "Quando conseguir, vou pedir outra\n"
	.string "batalha.$"

VerdanturfTown_WandasHouse_Text_WallysNextDoor:
	.string "TIO: Ah, {PLAYER}{KUN}! Wally ta na casa\n"
	.string "ao lado.\p"
	.string "Preciso contar uma coisa: o\n"
	.string "ambiente daqui fez muito bem pra\l"
	.string "saúde dele.\p"
	.string "Talvez nao seja só o ambiente.\n"
	.string "Acho que os Pokémon também deram\l"
	.string "esperança ao menino.$"

VerdanturfTown_WandasHouse_Text_WallySlippedOff:
	.string "Wally foi embora... Saiu sozinho...$"

VerdanturfTown_WandasHouse_Text_WallyGoneThatFar:
	.string "TIO: É mesmo? Wally foi tao longe\n"
	.string "sozinho...\p"
	.string "Preciso dar valor a ele. É filho do\n"
	.string "meu irmao, afinal.$"

VerdanturfTown_WandasHouse_Text_MeetWanda:
	.string "WANDA: Você é...? Ah, entendi!\p"
	.string "É {PLAYER}, de quem Wally falou.\n"
	.string "Sou prima dele. Prazer!\p"
	.string "Acho que ele ficou muito mais\n"
	.string "animado e saudável desde que veio\l"
	.string "pra cá.$"

VerdanturfTown_WandasHouse_Text_DontWorryAboutWally:
	.string "WANDA: Nao se preocupe com Wally.\n"
	.string "Ele vai ficar bem.\p"
	.string "Conheço meu primo, e ele também\n"
	.string "tem os Pokémon com ele.$"

VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay:
	.string "Graças a você, posso ver minha\n"
	.string "namorada todo dia. Se tô feliz?\l"
	.string "Pode apostar!$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven:
	.string "O namorado da minha filha é muito\n"
	.string "dedicado.\p"
	.string "Cava o túnel sem parar só pra ver\n"
	.string "ela.\p"
	.string "Ela fica preocupada e vai bastante\n"
	.string "até lá.$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging:
	.string "É incrível. O namorado da minha\n"
	.string "filha tava cavando o túnel com as\l"
	.string "próprias maos!$"

VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally:
	.string "Se acontecesse alguma coisa com\n"
	.string "Wally, eu nao conseguiria olhar\l"
	.string "pros pais dele em Petalburg...$"

VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande:
	.string "Wally tava em Ever Grande?\p"
	.string "Os pais dele em Petalburg iam ficar\n"
	.string "surpresos!$"

