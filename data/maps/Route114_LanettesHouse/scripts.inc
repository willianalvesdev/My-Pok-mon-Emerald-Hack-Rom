Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "LANETTE: Ah, {PLAYER}{KUN}!\p"
	.string "Desculpa a bagunça. Quando me\n"
	.string "concentro nas pesquisas, tudo fica\l"
	.string "assim...\p"
	.string "Que vergonha... Tome isto e nao\n"
	.string "conte pra ninguém.$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "Um conselho sobre meu sistema de\n"
	.string "armazenamento Pokémon?\p"
	.string "Organize as Boxes de um jeito que\n"
	.string "ajude você a encontrar os\l"
	.string "Pokémon.$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "Sao as anotaçoes de pesquisa de\n"
	.string "Lanette. Tem informaçoes sobre as\l"
	.string "Boxes.\p"
	.string "Cada Box deve guardar 30 Pokémon.\p"
	.string "Cada treinador deve conseguir\n"
	.string "guardar 510 Pokémon no PC.\p"
	.string "Continuar lendo?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "Adicionar marcas pra facilitar a\n"
	.string "organizaçao dos Pokémon.\p"
	.string "Permitir mudar os nomes e papéis\n"
	.string "de parede das Boxes pra deixar os\l"
	.string "Pokémon mais à vontade.\p"
	.string "Continuar lendo?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "Ao guardar um Pokémon, ele deve ir\n"
	.string "pra última Box que você olhou.\p"
	.string "Se ela estiver cheia, vai pra\n"
	.string "próxima.\p"
	.string "Ou seja, quando você olha uma\n"
	.string "Box, ela vira automaticamente a\l"
	.string "Box de destino.$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{PLAYER} fechou o caderno.$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "Tem uma mensagem no PC.\p"
	.string "...\p"
	.string "“Seu sistema de armazenamento é\n"
	.string "mais prático que o meu.\p"
	.string "Tem funçoes fáceis de usar que\n"
	.string "deixam ele útil e divertido.\p"
	.string "Tenho orgulho de ter ajudado no\n"
	.string "desenvolvimento.\p"
	.string "Espero que continue suas pesquisas\n"
	.string "nessa área.\p"
	.string "De Bill.”$"

