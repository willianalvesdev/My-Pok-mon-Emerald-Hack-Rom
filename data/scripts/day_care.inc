Route117_EventScript_DaycareMan::
	lock
	faceplayer
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route117_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_EventScript_CheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route117_EventScript_CheckOnTwoMons
	msgbox Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareEggWaiting::
	msgbox Route117_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareAcceptEgg
	msgbox Route117_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareAcceptEgg
	msgbox Route117_Text_IllKeepIt, MSGBOX_DEFAULT
	special RejectEggFromDayCare
	release
	end

Route117_EventScript_DaycareAcceptEgg::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, PARTY_SIZE, Route117_EventScript_DaycareReceiveEgg
	msgbox Route117_Text_YouHaveNoRoomForIt, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareReceiveEgg::
	message Route117_Text_ReceivedEgg
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	msgbox Route117_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	special GiveEggFromDaycare
	release
	end

Route117_EventScript_CheckMonReceivedMail::
	specialvar VAR_RESULT, CheckDaycareMonReceivedMail
	call_if_eq VAR_RESULT, 1, Route117_EventScript_MonReceivedMail
	return

Route117_EventScript_MonReceivedMail::
	msgbox Route117_Text_FriendlyWithOtherTrainersMon, MSGBOX_DEFAULT
	return

Route117_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonIsDoingFine, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	release
	end

Route117_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonsAreDoingFine, MSGBOX_DEFAULT
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	setvar VAR_0x8004, 1
	call Route117_EventScript_CheckMonReceivedMail
	release
	end

Route117_PokemonDayCare_EventScript_DaycareWoman::
	lock
	faceplayer
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route117_PokemonDayCare_EventScript_EggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_OneMonInDaycare
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route117_PokemonDayCare_EventScript_TwoMonsInDaycare
	msgbox Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_FineThenComeAgain, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_GiveMonToRaise::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, Route117_PokemonDayCare_EventScript_OnlyOneMon
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	goto_if_eq VAR_RESULT, 2, Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons
	msgbox Route117_PokemonDayCare_Text_WhichMonShouldWeRaise, MSGBOX_DEFAULT
	chooseboxmon SELECT_PC_MON_DAYCARE
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route117_PokemonDayCare_EventScript_ComeAgain
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, Route117_PokemonDayCare_EventScript_OnlyOneAliveMon
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox Route117_PokemonDayCare_Text_WellRaiseYourMon, MSGBOX_DEFAULT
	waitmoncry
	special StoreSelectedPokemonInDaycare
	callnative UpdateFollowingPokemon
	incrementgamestat GAME_STAT_USED_DAYCARE
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_CanRaiseOneMore
	release
	end

Route117_PokemonDayCare_EventScript_ComeAgain::
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_CanRaiseOneMore::
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_OnlyOneMon::
	msgbox Route117_PokemonDayCare_Text_YouHaveJustOneMon, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_OnlyOneAliveMon::
	msgbox Route117_PokemonDayCare_Text_WhatWillYouBattleWith, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons::
	msgbox Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_EggWaiting::
	msgbox Route117_PokemonDayCare_Text_HusbandWasLookingForYou, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels::
	msgbox Route117_PokemonDayCare_Text_YourMonHasGrownXLevels, MSGBOX_DEFAULT
	return

Route117_PokemonDayCare_EventScript_DisplayLevelsGained::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	call_if_ne VAR_RESULT, 0, Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels
	return

Route117_PokemonDayCare_EventScript_OneMonInDaycare::
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_TryRetrieveMon::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, PARTY_SIZE, Route117_PokemonDayCare_EventScript_NoRoom
	specialvar VAR_RESULT, GetDaycareState
	setvar VAR_0x8004, 0
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_CostPrompt
	special ShowDaycareLevelMenu
	copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_RESULT, DAYCARE_EXITED_LEVEL_MENU, Route117_PokemonDayCare_EventScript_ComeAgain
	goto Route117_PokemonDayCare_EventScript_CostPrompt
	end

Route117_PokemonDayCare_EventScript_CostPrompt::
	special GetDaycareCostAndPrepareString
	msgbox Route117_PokemonDayCare_Text_ItWillCostX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_CheckEnoughMoney
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_CheckEnoughMoney::
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	goto_if_eq VAR_RESULT, 1, Route117_PokemonDayCare_EventScript_RetrieveMon
	msgbox Route117_PokemonDayCare_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_RetrieveMon::
	applymovement LOCALID_DAYCARE_LADY, Route117_PokemonDayCare_Movement_RetrieveDaycareMon
	waitmovement 0
	specialvar VAR_RESULT, TakePokemonFromDaycare
	special SubtractMoneyFromVar0x8005
	playse SE_SHOP
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	msgbox Route117_PokemonDayCare_Text_TookBackMon, MSGBOX_DEFAULT
	waitmoncry
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon::
	msgbox Route117_PokemonDayCare_Text_TakeOtherOneBackToo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_NoRoom::
	msgbox Route117_PokemonDayCare_Text_YourTeamIsFull, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_Movement_RetrieveDaycareMon:
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	walk_slow_up
	set_invisible
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	set_visible
	walk_slow_down
	step_end

@ Unused. Possibly a commented script, or a typo end added to the above Movement script
Route117_PokemonDayCare_EventScript_UnusedEnd::
	end

Route117_PokemonDayCare_EventScript_TwoMonsInDaycare::
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	setvar VAR_0x8004, 1
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

@ Unused
Route117_PokemonDayCare_EventScript_UnusedRetrieveMon::
	special ShowDaycareLevelMenu
	goto_if_eq VAR_RESULT, 2, Route117_PokemonDayCare_EventScript_ComeAgain
	copyvar VAR_0x8004, VAR_RESULT
	specialvar VAR_RESULT, TakePokemonFromDaycare
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

EventScript_EggHatch::
	lockall
	msgbox Text_EggHatchHuh, MSGBOX_DEFAULT
	special EggHatch
	releaseall
	end

Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon:
	.string "Sou o senhor da Day Care.\p"
	.string "Ajudo a cuidar dos queridos\n"
	.string "Pokémon dos treinadores.\p"
	.string "Se quiser deixar seus Pokémon com\n"
	.string "a gente, fale com minha esposa.$"

Route117_Text_DoYouWantEgg:
	.string "Ah, é você!\p"
	.string "Estávamos cuidando dos seus\n"
	.string "Pokémon e levamos um susto:\l"
	.string "apareceu um ovo!\p"
	.string "Nao sabemos como ele chegou aqui,\n"
	.string "mas estava com seus Pokémon.\p"
	.string "Você quer ficar com ele, né?$"

Route117_Text_YourMonIsDoingFine:
	.string "Ah, é você! Que bom ver você. Seu\n"
	.string "{STR_VAR_1} ta bem.$"

Route117_Text_IllKeepIt:
	.string "Entao vou ficar com ele. Obrigado!$"

Route117_Text_YouHaveNoRoomForIt:
	.string "Você nao tem espaço... Volte\n"
	.string "quando arrumar um lugar.$"

Route117_Text_ReceivedEgg:
	.string "{PLAYER} recebeu o ovo do senhor\n"
	.string "da Day Care.$"

Route117_Text_TakeGoodCareOfIt:
	.string "Cuide bem dele.$"

Route117_Text_FriendlyWithOtherTrainersMon:
	.string "Aliás, seu {STR_VAR_1} parecia\n"
	.string "bem próximo de {STR_VAR_3}, de\l"
	.string "{STR_VAR_2}.\p"
	.string "Acho que vi ele até recebendo uma\n"
	.string "carta.$"

@ Unused
Route117_Text_SeeWifeIfYouWantToPickUpMon:
	.string "Se quiser pegar seu Pokémon de\n"
	.string "volta, fale com minha esposa.$"

Route117_Text_YourMonsAreDoingFine:
	.string "Ah, é você! Seus {STR_VAR_1} e\n"
	.string "{STR_VAR_2} tao bem.$"

Route117_Text_IWillKeepDoYouWantIt:
	.string "Vou ficar com ele mesmo, hein.\n"
	.string "Você quer o ovo, né?$"

Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon:
	.string "Sou a senhora da Day Care.\p"
	.string "Podemos cuidar dos seus Pokémon.\p"
	.string "Quer deixar um com a gente?$"

Route117_PokemonDayCare_Text_WhichMonShouldWeRaise:
	.string "Qual Pokémon você quer deixar?$"

Route117_PokemonDayCare_Text_WellRaiseYourMon:
	.string "Certo, vamos cuidar de\n"
	.string "{STR_VAR_1} por um tempo.\p"
	.string "Volte depois pra buscar.$"

Route117_PokemonDayCare_Text_WeCanRaiseOneMore:
	.string "Podemos cuidar de dois Pokémon\n"
	.string "seus. Quer deixar mais um?$"

Route117_PokemonDayCare_Text_HusbandWasLookingForYou:
	.string "Meu marido tava procurando você.$"

Route117_PokemonDayCare_Text_FineThenComeAgain:
	.string "Ah, tudo bem. Volte sempre.$"

Route117_PokemonDayCare_Text_NotEnoughMoney:
	.string "Você nao tem dinheiro suficiente...$"

Route117_PokemonDayCare_Text_TakeOtherOneBackToo:
	.string "Vai pegar o outro de volta também?$"

Route117_PokemonDayCare_Text_ComeAgain:
	.string "Certo. Volte sempre.$"

Route117_PokemonDayCare_Text_GoodToSeeYou:
	.string "Ah, é você! Que bom ver você.\n"
	.string "Seus Pokémon tao muito bem!$"

Route117_PokemonDayCare_Text_YourMonHasGrownXLevels:
	.string "Seu {STR_VAR_1} subiu\n"
	.string "{STR_VAR_2} níveis.$"

Route117_PokemonDayCare_Text_YourTeamIsFull:
	.string "Sua equipe ta cheia. Arrume um\n"
	.string "espaço e volte aqui.$"

@ Unused
Route117_PokemonDayCare_Text_TakeBackWhichMon:
	.string "Qual Pokémon quer pegar de volta?$"

Route117_PokemonDayCare_Text_ItWillCostX:
	.string "Pra pegar {STR_VAR_1} de volta,\n"
	.string "custa ¥{STR_VAR_2}.$"

Route117_PokemonDayCare_Text_HeresYourMon:
	.string "Perfeito! Aqui está seu Pokémon.$"

Route117_PokemonDayCare_Text_TookBackMon:
	.string "{PLAYER} pegou {STR_VAR_1} de\n"
	.string "volta com a senhora da Day Care.$"

Route117_PokemonDayCare_Text_YouHaveJustOneMon:
	.string "Ah, mas você só tem um Pokémon.\p"
	.string "Volte outra hora.$"

Route117_PokemonDayCare_Text_TakeYourMonBack:
	.string "Quer pegar seu Pokémon de volta?$"

Route117_PokemonDayCare_Text_WhatWillYouBattleWith:
	.string "Se deixar esse Pokémon comigo, com\n"
	.string "qual vai batalhar?\p"
	.string "Volte outra hora.$"

Text_EggHatchHuh:
	.string "Hein?$"

Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne:
	.string "Calma aí. Se deixar esse Pokémon\n"
	.string "comigo, vai ficar com um só.\p"
	.string "É melhor capturar mais alguns\n"
	.string "antes.$"
