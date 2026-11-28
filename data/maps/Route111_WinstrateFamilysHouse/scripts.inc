Route111_WinstrateFamilysHouse_MapScripts::
	.byte 0

Route111_WinstrateFamilysHouse_EventScript_Victor::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTOR
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Victoria::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTORIA
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace, MSGBOX_DEFAULT
	giveitem ITEM_MACHO_BRACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MACHO_BRACE
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace::
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vivi::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VIVI
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vicky::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICKY
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo::
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou:
	.string "Nunca vi um treinador usar os\n"
	.string "Pokémon tao bem.\p"
	.string "Mas preciso avisar: meu filho é\n"
	.string "mais forte que você.\p"
	.string "Ele foi até desafiar a Liga\n"
	.string "Pokémon!$"

Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace:
	.string "Usamos esta Macho Brace pra\n"
	.string "fortalecer nossos Pokémon nos\l"
	.string "treinos.\p"
	.string "Como você venceu todo mundo, nem\n"
	.string "sei se precisa, mas queremos dar\l"
	.string "ela a você.$"

Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles:
	.string "A gente leva as batalhas Pokémon\n"
	.string "bem a sério.$"

Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers:
	.string "Mamae é mais forte que papai.\p"
	.string "Eu sou mais forte que mamae.\p"
	.string "Vovó é mais forte que eu!\p"
	.string "Mas meu irmao é mais forte até que\n"
	.string "a vovó.$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrong:
	.string "Você é forte, nao tem dúvida.\p"
	.string "Mas, se enfrentar meu neto, vai\n"
	.string "acabar chorando de raiva.\p"
	.string "Ele é mais forte que qualquer\n"
	.string "treinador que a família conhece!\p"
	.string "Já deve estar desafiando o\n"
	.string "campeao da Liga. Do jeito que\l"
	.string "conheço ele, talvez já seja o\l"
	.string "campeao!$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort:
	.string "Meu neto já deve estar desafiando\n"
	.string "o campeao da Liga.\p"
	.string "Do jeito que conheço ele, talvez\n"
	.string "já seja o campeao!$"

