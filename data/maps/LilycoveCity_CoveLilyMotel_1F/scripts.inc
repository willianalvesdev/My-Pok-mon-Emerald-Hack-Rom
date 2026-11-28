LilycoveCity_CoveLilyMotel_1F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV::
	lockall
	playse SE_PIN
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
	waitmovement 0
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
	waitmovement 0
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot:
	.string "Hum, entao conseguiram dobrar o\n"
	.string "número de hóspedes usando Pokémon\l"
	.string "como atraçao?\p"
	.string "Talvez eu devesse arrumar um\n"
	.string "Pokémon fofo pra ser o mascote da\l"
	.string "pousada.\p"
	.string "Será que isso traz mais hóspedes?$"

LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua:
	.string "Ah, desculpa! Me distraí vendo\n"
	.string "televisao!\p"
	.string "Desde que a Team Aqua chegou, os\n"
	.string "turistas sumiram.$"

LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV:
	.string "Ei, sai da frente! Nao tô\n"
	.string "enxergando a televisao!$"

LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem:
	.string "Incrível! Um Pokémon encontrou um\n"
	.string "objeto perdido?\p"
	.string "Se a gente tivesse um Pokémon\n"
	.string "esperto assim, podia recuperar as\l"
	.string "coisas que os hóspedes perdem.$"

LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted:
	.string "Ah, desculpa! Me distraí vendo\n"
	.string "televisao!\p"
	.string "Ouvi dizer que alguém acabou com o\n"
	.string "esconderijo da Team Aqua.\p"
	.string "Já recebemos uma reserva de um\n"
	.string "grupo enorme.\p"
	.string "O nome da empresa era... GAME\n"
	.string "alguma coisa...$"

LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar:
	.string "Incrível! Um Pokémon que cuidava\n"
	.string "da casa pegou um ladrao?\p"
	.string "Se a gente tivesse um Pokémon\n"
	.string "forte de segurança, os hóspedes\l"
	.string "iam ficar bem mais tranquilos.$"

LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner:
	.string "Ah, desculpa! Me distraí vendo\n"
	.string "televisao.\p"
	.string "Um grupo grande acabou de chegar.\n"
	.string "A reserva ta no nome de GAME\l"
	.string "FREAK. Acho que fazem jogos.\p"
	.string "Eita, preciso preparar o jantar\n"
	.string "deles!$"

