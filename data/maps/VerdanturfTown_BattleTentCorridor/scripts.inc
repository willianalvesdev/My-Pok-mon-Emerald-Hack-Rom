VerdanturfTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentCorridor_OnFrame
	.byte 0

VerdanturfTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM, 6, 5
	waitstate
	releaseall
	end

VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end


@ Leftover text from when this was a Contest Hall in R/S
@ Unused
VerdanturfTown_ContestHall_Text_WhichContestYouEntering:
	.string "Vai participar de qual concurso?\n"
	.string "Quer uma dica?\p"
	.string "Mesmo num concurso de fofura, a\n"
	.string "primeira avaliaçao nao olha só a\l"
	.string "fofura.\p"
	.string "Você precisa pensar em como cuidar\n"
	.string "melhor dos seus Pokémon.$"

@ Unused
VerdanturfTown_ContestHall_Text_RaisedMonToBeCute:
	.string "Criei meu Pokémon pra ser fofo.\p"
	.string "Depois descobri que existem\n"
	.string "concursos de fofura!\p"
	.string "Ainda bem que cuidei dele com\n"
	.string "tanto carinho...$"

@ Unused
VerdanturfTown_ContestHall_Text_MyMonRules:
	.string "Meu Pokémon é o melhor!\p"
	.string "Tem estilo, força, beleza, fofura\n"
	.string "e inteligência. É completo!\p"
	.string "Vou tentar ganhar em todos os\n"
	.string "concursos!$"

@ Unused
VerdanturfTown_ContestHall_Text_NormalRankStage:
	.string "Concursos Pokémon\p"
	.string "Palco do Normal Rank!$"

