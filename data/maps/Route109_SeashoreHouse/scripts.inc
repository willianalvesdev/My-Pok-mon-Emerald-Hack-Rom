Route109_SeashoreHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
	.byte 0

Route109_SeashoreHouse_OnTransition:
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
	end

Route109_SeashoreHouse_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction::
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_DefeatedTrainers::
	msgbox Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, MSGBOX_DEFAULT
	giveitem ITEM_SODA_POP, 6
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_BagFull
	setflag FLAG_RECEIVED_6_SODA_POP
	release
	end

Route109_SeashoreHouse_EventScript_BagFull::
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop::
	showmoneybox 0, 0
	msgbox Route109_SeashoreHouse_Text_WantToBuySodaPop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_BuySodaPop
	msgbox Route109_SeashoreHouse_Text_ThatsTooBad, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_BuySodaPop::
	checkmoney 300
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughMoney
	checkitemspace ITEM_SODA_POP
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughSpace
	msgbox Route109_SeashoreHouse_Text_HereYouGo, MSGBOX_DEFAULT
	removemoney 300
	updatemoneybox
.if OW_SHOW_ITEM_DESCRIPTIONS != OW_ITEM_DESCRIPTIONS_OFF
	hidemoneybox
	giveitem ITEM_SODA_POP
.else
	giveitem ITEM_SODA_POP
	hidemoneybox
.endif
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughMoney::
	msgbox Route109_SeashoreHouse_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughSpace::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Johanna::
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion::
	goto_if_not_defeated TRAINER_DWAYNE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_JOHANNA, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_SIMON, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
	release
	end

Route109_SeashoreHouse_EventScript_TrainersNotCompleted::
	release
	end

Route109_SeashoreHouse_Text_SeashoreHouseIntro:
	.string "Sou o dono da Seashore House, mas\n"
	.string "pode me chamar de Mr. Sea!\p"
	.string "Adoro ver batalhas Pokémon cheias\n"
	.string "de emoçao. Mostre esse fogo no\l"
	.string "coraçao!\p"
	.string "Se vencer todos os treinadores\n"
	.string "daqui, vou recompensar seu\l"
	.string "esforço.$"

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
	.string "Quero ver batalhas animadas!\p"
	.string "É por isso que cuido da Seashore\n"
	.string "House!$"

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
	.string "Você ta pegando fogo! Que\n"
	.string "batalhas incríveis!\p"
	.string "Pra agradecer pelo espetáculo,\n"
	.string "quero dar isto a você.\p"
	.string "Sao seis garrafas de Soda Pop!$"

Route109_SeashoreHouse_Text_BagFull:
	.string "Opa, sua bolsa ta cheia. Vou\n"
	.string "guardar elas pra você.$"

Route109_SeashoreHouse_Text_WantToBuySodaPop:
	.string "Quer comprar Soda Pop? Os Pokémon\n"
	.string "adoram!\p"
	.string "Só ¥300 a garrafa!$"

Route109_SeashoreHouse_Text_HereYouGo:
	.string "Aqui está!$"

Route109_SeashoreHouse_Text_NotEnoughMoney:
	.string "Você nao tem dinheiro suficiente.$"

Route109_SeashoreHouse_Text_ThatsTooBad:
	.string "Nao? Que pena.$"

Route109_SeashoreHouse_Text_DwayneIntro:
	.string "Se quer batalhar na Seashore\n"
	.string "House, nao vai encontrar ninguém\l"
	.string "mais animado que eu, camarada!$"

Route109_SeashoreHouse_Text_DwayneDefeated:
	.string "Que batalha boa! Aceito essa\n"
	.string "derrota, camarada!$"

Route109_SeashoreHouse_Text_DwaynePostBattle:
	.string "Sempre que venho a Slateport,\n"
	.string "aproveito boas batalhas e Soda Pop\l"
	.string "geladinha!$"

Route109_SeashoreHouse_Text_JohannaIntro:
	.string "Batalha sem graça nem vale o\n"
	.string "esforço.\p"
	.string "É a emoçao que deixa treinadores e\n"
	.string "Pokémon mais fortes!$"

Route109_SeashoreHouse_Text_JohannaDefeated:
	.string "Essa foi quente!$"

Route109_SeashoreHouse_Text_JohannaPostBattle:
	.string "Ufa, tô com sede. Acho que vou\n"
	.string "tomar Soda Pop.$"

Route109_SeashoreHouse_Text_SimonIntro:
	.string "Vou mostrar como meus Pokémon sao\n"
	.string "incríveis, mas nao vai chorar!$"

Route109_SeashoreHouse_Text_SimonDefeated:
	.string "...Eu perdi, mas nao vou chorar...$"

Route109_SeashoreHouse_Text_SimonPostBattle:
	.string "Se um dos meus Pokémon soubesse\n"
	.string "me levar nas costas pela água, eu\l"
	.string "nao precisava mais desta boia.$"

