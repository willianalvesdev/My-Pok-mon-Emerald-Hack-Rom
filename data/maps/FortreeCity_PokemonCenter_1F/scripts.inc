FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FORTREE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
	.string "Ei, você ta completando uma\n"
	.string "POKéDEX?\p"
	.string "Hum... Minha sugestao é ir pra\n"
	.string "SAFARI ZONE.$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "Já usou o RECORD CORNER?\p"
	.string "É bem legal. Ele mistura e\n"
	.string "compartilha os registros dos\l"
	.string "treinadores.\p"
	.string "Nao sei bem como funciona, mas é\n"
	.string "interessante!$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "Nossa, você tem um POKéNAV! Igual\n"
	.string "ao meu!\p"
	.string "Conhece o sistema MATCH CALL\n"
	.string "dele?\p"
	.string "Dá pra conversar a qualquer hora\n"
	.string "com os treinadores registrados.\p"
	.string "Ele também mostra quem quer uma\n"
	.string "revanche.\p"
	.string "É muito útil! O pessoal da DEVON\n"
	.string "entende do assunto!$"

