MossdeepCity_GameCorner_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_GameCorner_1F_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_GameCorner_1F_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	.byte 0

MossdeepCity_GameCorner_1F_OnWarp:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
	.2byte 0

MossdeepCity_GameCorner_1F_OnFrame:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_InfoMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_InfoMan2
	release
	end

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_OldMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_OldMan2
	release
	end


@ Everything below is leftover from RS
@ The house that was here in RS was moved to Sootopolis and replaced by the Game Corner
@ The text below is unused and duplicated in its replacement in Sootopolis City
@ And the BG Door event was moved inaccessibly into a wall

RS_MysteryEventsHouse_EventScript_Door::
	msgbox RS_MysteryEventsHouse_Text_DoorIsLocked, MSGBOX_SIGN
	end

RS_MysteryEventsHouse_Text_OldManGreeting:
	.string "Quando eu era jovem, viajei pelo\n"
	.string "mundo como treinador Pokémon.\p"
	.string "Agora que fiquei velho, minha\n"
	.string "diversao é ver os jovens\l"
	.string "batalhando.$"

RS_MysteryEventsHouse_Text_DoorIsLocked:
	.string "A porta parece trancada.$"

RS_MysteryEventsHouse_Text_ChallengeVisitingTrainer:
	.string "Um treinador chamado\n"
	.string "{STR_VAR_1} ta visitando minha\l"
	.string "casa.\p"
	.string "Quer desafiar {STR_VAR_1}?$"

RS_MysteryEventsHouse_Text_YouWontBattle:
	.string "Nao vai batalhar? Que pena, queria\n"
	.string "ver essa batalha...$"

RS_MysteryEventsHouse_Text_KeepItToA3On3:
	.string "Muito bem!\p"
	.string "Mas minha casa nao é tao\n"
	.string "resistente.\p"
	.string "Podem usar só três Pokémon de\n"
	.string "cada lado?$"

RS_MysteryEventsHouse_Text_SaveYourProgress:
	.string "Antes da batalha, é melhor salvar\n"
	.string "seu progresso.$"

RS_MysteryEventsHouse_Text_HopeToSeeAGoodMatch:
	.string "Espero ver uma boa batalha!$"

RS_MysteryEventsHouse_Text_BattleTie:
	.string "Entao terminou empatado.\p"
	.string "Foi uma ótima batalha! Nenhum dos\n"
	.string "dois quis ceder!$"

RS_MysteryEventsHouse_Text_BattleWon:
	.string "Foi incrível!\p"
	.string "Parecia que eu tava vendo minha\n"
	.string "versao mais jovem!$"

RS_MysteryEventsHouse_Text_BattleLost:
	.string "Ah, que pena!\p"
	.string "Mas foi uma boa batalha. Espero\n"
	.string "que você vença na próxima.$"
