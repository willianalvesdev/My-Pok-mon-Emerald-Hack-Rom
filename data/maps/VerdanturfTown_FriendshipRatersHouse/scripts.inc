VerdanturfTown_FriendshipRatersHouse_MapScripts::
	.byte 0

VerdanturfTown_FriendshipRatersHouse_EventScript_FriendshipRater::
	lock
	faceplayer
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case FRIENDSHIP_NONE, VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou
	case FRIENDSHIP_1_TO_49, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary
	case FRIENDSHIP_50_TO_99, VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou
	case FRIENDSHIP_100_TO_149, VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou
	case FRIENDSHIP_150_TO_199, VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot
	case FRIENDSHIP_200_TO_254, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy
	case FRIENDSHIP_MAX, VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryWary, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou:
	.string "Deixe eu olhar seu Pokémon. Vou\n"
	.string "ver o quanto ele gosta de você.\p"
	.string "Ah, seu Pokémon...$"

VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou:
	.string "Ele adora você. Nao tem como\n"
	.string "gostar mais. Fico feliz só de ver.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy:
	.string "Ele parece muito feliz. Dá pra ver\n"
	.string "que gosta bastante de você.$"

VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot:
	.string "Ele gosta bastante de você.\n"
	.string "Parece querer um pouco de mimo.$"

VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou:
	.string "Ele ta se acostumando com você.\n"
	.string "Parece confiar em você.$"

VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou:
	.string "Ainda nao se acostumou muito. Nao\n"
	.string "gosta nem desgosta de você.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryWary:
	.string "Ele ta muito desconfiado. Tem um\n"
	.string "olhar bravo. Nao gosta muito de\l"
	.string "você.$"

VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou:
	.string "É um pouco difícil dizer isso...\p"
	.string "Seu Pokémon detesta você. Isso\n"
	.string "nao incomoda?$"

VerdanturfTown_FriendshipRatersHouse_Text_Pikachu:
	.string "PIKACHU: Pika, pika!$"

