Route116_TunnelersRestHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_OnTransition
	.byte 0

Route116_TunnelersRestHouse_OnTransition:
	setflag FLAG_LANDMARK_TUNNELERS_REST_HOUSE
	end

Route116_TunnelersRestHouse_EventScript_Tunneler1::
	msgbox Route116_TunnelersRestHouse_Text_WeHadToStopBoring, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler2::
	msgbox Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler3::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_TunnelOpened
	msgbox Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_EventScript_TunnelOpened::
	msgbox Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_Text_WeHadToStopBoring:
	.string "Aquele Rusturf Tunnel...\p"
	.string "No começo, uma equipe enorme usava\n"
	.string "máquinas modernas pra abrir caminho\l"
	.string "pela pedra. Mas tivemos que parar.\p"
	.string "O trabalho ia prejudicar os\n"
	.string "Pokémon selvagens da regiao.\p"
	.string "Agora só ficamos aqui sem fazer\n"
	.string "nada.$"

Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf:
	.string "Tem um homem cavando sozinho até\n"
	.string "Verdanturf. Ele quer muito abrir o\l"
	.string "caminho.\p"
	.string "Diz que, cavando aos poucos e sem\n"
	.string "máquinas, nao vai assustar os\l"
	.string "Pokémon nem prejudicar a natureza.\p"
	.string "Será que já conseguiu?$"

Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel:
	.string "Sem o túnel, você precisa\n"
	.string "atravessar o mar até Dewford,\l"
	.string "navegar pra Slateport e passar por\l"
	.string "Mauville pra chegar a Verdanturf.$"

Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough:
	.string "Ficou sabendo? O túnel até\n"
	.string "Verdanturf foi aberto!\p"
	.string "Às vezes, quando a gente quer\n"
	.string "muito, os sonhos se realizam.$"

