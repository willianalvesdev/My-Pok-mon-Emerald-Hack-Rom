MysteryGiftScript_VisitingTrainer::
	setvaddress MysteryGiftScript_VisitingTrainer
	special ValidateEReaderTrainer
	vgoto_if_eq VAR_RESULT, 0, MysteryGiftScript_VisitingTrainerArrived
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerInstructions
	waitmessage
	waitbuttonpress
	release
	end

MysteryGiftScript_VisitingTrainerArrived:
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerArrived
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftVisitingTrainerInstructions:
	.string "Obrigado por usar o sistema\n"
	.string "Mystery Gift.\p"
	.string "Com este Wonder Card, você pode\n"
	.string "responder a uma pesquisa num Poké\l"
	.string "Mart e convidar treinadores pra\l"
	.string "Sootopolis City.\p"
	.string "Vou contar uma senha secreta:\n"
	.string "“GIVE ME AWESOME TRAINER”.\p"
	.string "Escreva isso na pesquisa e envie\n"
	.string "pelo sistema de comunicaçao sem\l"
	.string "fio.$"

sText_MysteryGiftVisitingTrainerArrived:
	.string "Obrigado por usar o sistema\n"
	.string "Mystery Gift.\p"
	.string "Um treinador chegou a Sootopolis\n"
	.string "City procurando você. Esperamos\l"
	.string "que aproveite a batalha!\p"
	.string "Você pode convidar outros\n"
	.string "treinadores usando outras senhas.\l"
	.string "Procure mais combinaçoes.$"
