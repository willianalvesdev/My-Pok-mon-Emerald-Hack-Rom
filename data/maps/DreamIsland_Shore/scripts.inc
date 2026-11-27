DreamIsland_Shore_MapScripts::
	.byte 0

DreamIsland_Shore_EventScript_EnterForest::
	lockall
	warpsilent MAP_DREAM_ISLAND_FOREST, 11, 17
	waitstate
	end
