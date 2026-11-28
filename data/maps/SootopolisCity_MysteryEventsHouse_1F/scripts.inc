SootopolisCity_MysteryEventsHouse_1F_MapScripts::
	.byte 0

SootopolisCity_MysteryEventsHouse_1F_EventScript_OldMan::
	lock
	faceplayer
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_OnlyAmusementWatchingBattles, MSGBOX_DEFAULT
	release
	end

SootopolisCity_MysteryEventsHouse_1F_Text_OnlyAmusementWatchingBattles:
	.string "Quando era jovem, viajei pelo\n"
	.string "mundo como treinador Pokémon.\p"
	.string "Agora que fiquei velho, minha\n"
	.string "diversao é ver os jovens\l"
	.string "batalhando.$"
