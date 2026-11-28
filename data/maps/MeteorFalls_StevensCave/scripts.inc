MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "STEVEN: Nossa, {PLAYER}{KUN}. Me\n"
	.string "surpreende que tenha descoberto\l"
	.string "onde me encontrar.\p"
	.string "Você acha que eu sou só um maluco\n"
	.string "por pedras? Nao pode ser.\p"
	.string "Batalhamos lado a lado no centro\n"
	.string "espacial de Sootopolis. Você sabe\l"
	.string "do que sou capaz.\p"
	.string "Entao, {PLAYER}{KUN}, se veio me\n"
	.string "desafiar pra valer, prepare-se pra\l"
	.string "dar tudo de si!$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "Você... Nao imaginava que tinha\n"
	.string "ficado tao forte...$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "STEVEN: Desde nosso primeiro\n"
	.string "encontro na Granite Cave, em\l"
	.string "Dewford, eu já sentia isso.\p"
	.string "Achei que você um dia chegaria ao\n"
	.string "posto de campeao.\p"
	.string "Minhas previsoes costumam dar\n"
	.string "certo.\p"
	.string "E agora, pra onde você vai?\p"
	.string "...\p"
	.string "Fufufu, nem eu consigo dizer.$"

