PacifidlogTown_House5_MapScripts::
	.byte 0

PacifidlogTown_House5_EventScript_MirageIslandWatcher::
	lock
	faceplayer
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House5_EventScript_MirageIslandPresent
	msgbox PacifidlogTown_House5_Text_CantSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_MirageIslandPresent::
	msgbox PacifidlogTown_House5_Text_CanSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_Gentleman::
	msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather, MSGBOX_NPC
	end

PacifidlogTown_House5_Text_CantSeeMirageIslandToday:
	.string "Nao consigo ver Mirage Island\n"
	.string "hoje...$"

PacifidlogTown_House5_Text_CanSeeMirageIslandToday:
	.string "Ah! Nossa! Consigo ver Mirage\n"
	.string "Island hoje!$"

PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather:
	.string "Mirage Island...\p"
	.string "Talvez ela fique visível\n"
	.string "dependendo do tempo, como\l"
	.string "acontece com as miragens.\p"
	.string "Ou será que ela aparece e\n"
	.string "desaparece de verdade?$"

