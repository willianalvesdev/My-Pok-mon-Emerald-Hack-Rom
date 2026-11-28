FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnTransition:
	setflag FLAG_VISITED_FORTREE_CITY
	end

FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end

FortreeCity_EventScript_Man::
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
	end

FortreeCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_WomanGymAccessible::
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_Girl::
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
	end

FortreeCity_EventScript_OldMan::
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
	end

FortreeCity_EventScript_Boy::
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
	end

FortreeCity_EventScript_GameboyKid::
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
	end

FortreeCity_EventScript_CitySign::
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
	end

FortreeCity_EventScript_GymSign::
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
	end

FortreeCity_EventScript_Kecleon::
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_AskUseDevonScope::
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
	release
	end

FortreeCity_EventScript_UseDevonScope::
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_Movement_KecleonFlee:
	walk_right
	step_end

FortreeCity_Text_SawGiganticPokemonInSky:
	.string "Ninguém acredita, mas vi um\n"
	.string "POKÉMON enorme no céu.\p"
	.string "Ele se mexia enquanto voava na\n"
	.string "direçao da ROUTE 131.\p"
	.string "Aliás... Snif... Você ta com cheiro\n"
	.string "de queimado.\p"
	.string "Passou por um vulcao?$"

FortreeCity_Text_SomethingBlockingGym:
	.string "Quero ir ao ginásio, mas tem alguma\n"
	.string "coisa bloqueando o caminho.\p"
	.string "Depois de todo o trabalho que tive\n"
	.string "pra treinar na ROUTE 120...$"

FortreeCity_Text_ThisTimeIllBeatWinona:
	.string "Tô com meu melhor POKÉMON. Dessa\n"
	.string "vez eu venço a WINONA.$"

FortreeCity_Text_TreesGrowByDrinkingRainwater:
	.string "O chao absorve a água da chuva, e\n"
	.string "as árvores crescem bebendo essa\l"
	.string "água...\p"
	.string "FORTREE CITY existe graças à água\n"
	.string "e à terra.$"

FortreeCity_Text_EveryoneHealthyAndLively:
	.string "As casas da cidade ficam nas\n"
	.string "árvores.\p"
	.string "Talvez por isso todo mundo aqui\n"
	.string "seja saudável e cheio de energia.\p"
	.string "Até eu me sinto trinta anos mais\n"
	.string "jovem.$"

FortreeCity_Text_BugPokemonComeThroughWindow:
	.string "Morar nas árvores é legal.\p"
	.string "Mas às vezes entra um POKÉMON do\n"
	.string "tipo Inseto pela janela. Dá um\l"
	.string "susto!\p"
	.string "Você fecha a porta, e o morador\n"
	.string "novo vem voando.$"

FortreeCity_Text_PokemonThatEvolveWhenTraded:
	.string "Ouvi dizer que alguns POKÉMONS\n"
	.string "evoluem quando sao trocados!$"

FortreeCity_Text_SomethingUnseeable:
	.string "Tem algo invisível no caminho.$"

FortreeCity_Text_UnseeableUseDevonScope:
	.string "Tem algo invisível no caminho.\p"
	.string "Quer usar o DEVON SCOPE?$"

FortreeCity_Text_UsedDevonScopePokemonFled:
	.string "{PLAYER} usou o DEVON SCOPE.\p"
	.string "Um POKÉMON invisível ficou visível!\p"
	.string "Ele se assustou e fugiu!$"

FortreeCity_Text_CitySign:
	.string "FORTREE CITY\p"
	.string "“A cidade nas árvores que vive\n"
	.string "junto da natureza.”$"

FortreeCity_Text_GymSign:
	.string "Ginásio Pokémon de FORTREE CITY\p"
	.string "Líder: WINONA\p"
	.string "“A treinadora de pássaros que alça\n"
	.string "voo pelo mundo.”$"

