BattleFrontier_Lounge5_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	chooseboxmon
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge5_EventScript_NatureGirlEgg
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlEgg::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting::
	.string "Hehehe! Eu entendo o que os\n"
	.string "Pokémon pensam!\p"
	.string "Por favor, posso ver seus Pokémon?$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
	.string "Ah, que pao-duro!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow::
	.string "Hum...\p"
	.string "Este aqui diz que gosta de\n"
	.string "batalhar! Continua lutando mesmo\l"
	.string "quando está bem machucado!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighDefenseLow::
	.string "Hum...\p"
	.string "Este aqui diz que gosta de\n"
	.string "batalhar! Mas, quando se machuca\l"
	.string "bastante, começa a se preocupar\l"
	.string "consigo mesmo!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighSupportLow::
	.string "Hum...\p"
	.string "Este aqui diz que gosta de\n"
	.string "batalhar! Mas, quando se machuca\l"
	.string "bastante, começa a usar truques!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighAttackLow::
	.string "Hum...\p"
	.string "Este aqui diz que gosta de se\n"
	.string "proteger! Mas, quando se machuca\l"
	.string "bastante, parte para o ataque!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighDefenseLow::
	.string "Hum...\p"
	.string "Este aqui diz que gosta de se\n"
	.string "proteger! Ele se preocupa consigo\l"
	.string "mesmo, esteja machucado ou nao!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighSupportLow::
	.string "Hum...\p"
	.string "Este aqui diz que gosta de se\n"
	.string "proteger! Mas, quando se machuca\l"
	.string "bastante, começa a usar truques!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighAttackLow::
	.string "Hum...\p"
	.string "Este aqui diz que gosta de usar\n"
	.string "truques! Mas, quando se machuca\l"
	.string "bastante, parte para o ataque!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighDefenseLow::
	.string "Hum...\p"
	.string "Este aqui diz que gosta de usar\n"
	.string "truques! Mas, quando se machuca\l"
	.string "bastante, começa a se preocupar\l"
	.string "consigo mesmo!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighSupportLow::
	.string "Hum...\p"
	.string "Este aqui diz que gosta de usar\n"
	.string "truques! Continua assim mesmo\l"
	.string "quando está bem machucado!$"

BattleFrontier_Lounge5_Text_NatureGirlEgg::
	.string "Que bobagem! O Ovo está dormindo!\n"
	.string "Nao consigo conversar com ele!$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
	.string "Que gracinha! Aquela menina diz\n"
	.string "que entende os Pokémon!$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
	.string "Acho que essa menininha está\n"
	.string "dizendo algo bem importante.$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
	.string "Eu sei de uma coisa!\p"
	.string "Aquela menina brinca muito na casa\n"
	.string "vermelha!$"

