MtPyre_5F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_4F_EventScript_Tasha::
	trainerbattle_single TRAINER_TASHA, MtPyre_4F_Text_TashaIntro, MtPyre_4F_Text_TashaDefeat
	msgbox MtPyre_4F_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_4F_Text_TashaIntro:
	.string "Adoro tudo oque assusta... Nao\n"
	.string "consigo evitar...\p"
	.string "Quando tô aqui, tremo de medo...$"

MtPyre_4F_Text_TashaDefeat:
	.string "Perder... Eu nao gosto...$"

MtPyre_4F_Text_TashaPostBattle:
	.string "Quero ver coisas assustadoras...\n"
	.string "Nao consigo ir embora...\p"
	.string "Fica... Você nao quer ficar comigo?$"

