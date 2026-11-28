VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen::
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_Text_ManTryingToDigTunnel:
	.string "Meu pai contou que este túnel ta\n"
	.string "cheio de Pokémon medrosos.\p"
	.string "Eles se assustam com barulhos\n"
	.string "altos e fazem uma confusao. Por\l"
	.string "isso pararam a obra.\p"
	.string "Mas tem um homem tentando cavar o\n"
	.string "túnel sozinho!$"

VerdanturfTown_Text_ManDugTunnelForLove:
	.string "Um homem cavou um túnel pra\n"
	.string "encontrar a mulher que ama.\p"
	.string "Nao entendi muito, mas ta bom!$"

VerdanturfTown_Text_AirCleanHere:
	.string "O vento nunca traz cinzas do\n"
	.string "vulcao pra cá.\p"
	.string "O ar é limpo e gostoso. Morar aqui\n"
	.string "deve fazer bem até pra quem tem a\l"
	.string "saúde frágil.$"

VerdanturfTown_Text_MakeBattleTentDebut:
	.string "Eu e meus Pokémon estamos\n"
	.string "ganhando sem parar.\p"
	.string "Resolvi estrear na Battle Tent\n"
	.string "daqui.$"

VerdanturfTown_Text_GuyTryingToBustThroughCave:
	.string "Viu a caverna ao lado do Poké\n"
	.string "Mart?\p"
	.string "Tem um cara quebrando pedras pra\n"
	.string "abrir o caminho pro outro lado.\p"
	.string "Seria ótimo passar por ali. Ia\n"
	.string "facilitar a visita a Rustboro.$"

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.string "A caverna ao lado do Poké Mart\n"
	.string "agora atravessa até o outro lado.\p"
	.string "Ficou muito mais fácil ir a\n"
	.string "Rustboro comprar as novidades da\l"
	.string "Devon.$"

VerdanturfTown_Text_TownSign:
	.string "Verdanturf Town\p"
	.string "“Onde o vento traz o cheiro bom da\n"
	.string "grama.”$"

VerdanturfTown_Text_WandasHouse:
	.string "Casa de Wanda$"

VerdanturfTown_Text_BattleTentSign:
	.string "Battle Tent de Verdanturf\p"
	.string "“Encha os olhos com grandes\n"
	.string "batalhas!”$"

VerdanturfTown_Text_RusturfTunnelSign:
	.string "Rusturf Tunnel\p"
	.string "“Ligando Rustboro e Verdanturf.\p"
	.string "A construçao do túnel foi\n"
	.string "cancelada.”$"

