MauvilleCity_GameCorner_MapScripts::
	.byte 0

	@ Game Corner prices
	.set TM_DOUBLE_TEAM_COINS, 1500
	.set TM_PSYCHIC_COINS, 3500
	.set TM_FLAMETHROWER_COINS, 4000
	.set TM_THUNDERBOLT_COINS, 4000
	.set TM_ICE_BEAM_COINS, 4000
	.set TM_SHADOW_BALL_COINS, 4000
	.set TM_SLUDGE_BOMB_COINS, 5000
	.set TM_EARTHQUAKE_COINS, 7000
	.set DOLL_COINS, 1000

	.set COINS_PRICE_50,  1000
	.set COINS_PRICE_550, 10000

MauvilleCity_GameCorner_EventScript_CoinsClerk::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NeedCoinCase
	message MauvilleCity_GameCorner_Text_WereYouLookingForCoins
	waitmessage
	showmoneybox 0, 0
	showcoinsbox 0, 5
	goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50

MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 0, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
	case 1, MauvilleCity_GameCorner_EventScript_Buy550Coins
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
	end

@ Unused
MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault550::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 1, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
	case 1, MauvilleCity_GameCorner_EventScript_Buy550Coins
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
	end

MauvilleCity_GameCorner_EventScript_Buy50Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 50), MauvilleCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_50
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 50
	removemoney COINS_PRICE_50
	updatemoneybox
	updatecoinsbox
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox
	release
	end

MauvilleCity_GameCorner_EventScript_Buy550Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 550), MauvilleCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_550
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 550
	removemoney COINS_PRICE_550
	updatemoneybox
	updatecoinsbox
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox
	release
	end

MauvilleCity_GameCorner_EventScript_NeedCoinCase::
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_NotEnoughMoney::
	msgbox MauvilleCity_GameCorner_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox
	release
	end

MauvilleCity_GameCorner_EventScript_CancelBuyCoins::
	msgbox MauvilleCity_GameCorner_Text_DontNeedCoinsThen, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox
	release
	end

MauvilleCity_GameCorner_EventScript_NoRoomForCoins::
	msgbox MauvilleCity_GameCorner_Text_CoinCaseIsFull, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox
	release
	end

MauvilleCity_GameCorner_EventScript_PrizeCornerDolls::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage
	release
	end

MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 0, 0
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize

MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize

MauvilleCity_GameCorner_EventScript_ChooseDollPrize::
	multichoice 12, 0, MULTI_GAME_CORNER_DOLLS, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_TreeckoDoll
	case 1, MauvilleCity_GameCorner_EventScript_TorchicDoll
	case 2, MauvilleCity_GameCorner_EventScript_MudkipDoll
	case 3, MauvilleCity_GameCorner_EventScript_CancelDollSelect
	goto MauvilleCity_GameCorner_EventScript_CancelDollSelect
	end

MauvilleCity_GameCorner_EventScript_TreeckoDoll::
	setvar VAR_TEMP_1, 1
	bufferdecorationname STR_VAR_1, DECOR_TREECKO_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize

MauvilleCity_GameCorner_EventScript_TorchicDoll::
	setvar VAR_TEMP_1, 2
	bufferdecorationname STR_VAR_1, DECOR_TORCHIC_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize

MauvilleCity_GameCorner_EventScript_MudkipDoll::
	setvar VAR_TEMP_1, 3
	bufferdecorationname STR_VAR_1, DECOR_MUDKIP_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize

MauvilleCity_GameCorner_EventScript_ConfirmDollPrize::
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_CancelDollSelect
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_BuyTreeckoDoll
	case 2, MauvilleCity_GameCorner_EventScript_BuyTorchicDoll
	case 3, MauvilleCity_GameCorner_EventScript_BuyMudkipDoll
	end

MauvilleCity_GameCorner_EventScript_BuyTreeckoDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname STR_VAR_2, DECOR_TREECKO_DOLL
	checkdecorspace DECOR_TREECKO_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll
	removecoins DOLL_COINS
	adddecoration DECOR_TREECKO_DOLL
	updatecoinsbox
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTorchicDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname STR_VAR_2, DECOR_TORCHIC_DOLL
	checkdecorspace DECOR_TORCHIC_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll
	removecoins DOLL_COINS
	adddecoration DECOR_TORCHIC_DOLL
	updatecoinsbox
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_BuyMudkipDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname STR_VAR_2, DECOR_MUDKIP_DOLL
	checkdecorspace DECOR_MUDKIP_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll
	removecoins DOLL_COINS
	adddecoration DECOR_MUDKIP_DOLL
	updatecoinsbox
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll::
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_NoRoomForDoll::
	call Common_EventScript_NoRoomForDecor
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_CancelDollSelect::
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
	hidecoinsbox
	release
	end

MauvilleCity_GameCorner_EventScript_PrizeCornerTMs::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_ChooseTMPrizeMessage
	release
	end

MauvilleCity_GameCorner_EventScript_ChooseTMPrizeMessage::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	showcoinsbox 0, 0
	goto MauvilleCity_GameCorner_EventScript_ChooseTMPrize

MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_ChooseTMPrize

MauvilleCity_GameCorner_EventScript_ChooseTMPrize::
	dynmultichoice 12, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, MauvilleCity_GameCorner_Text_MenuTMDoubleTeam, MauvilleCity_GameCorner_Text_MenuTMPsychic, MauvilleCity_GameCorner_Text_MenuTMFlamethrower, MauvilleCity_GameCorner_Text_MenuTMThunderbolt, MauvilleCity_GameCorner_Text_MenuTMIceBeam, MauvilleCity_GameCorner_Text_MenuTMShadowBall, MauvilleCity_GameCorner_Text_MenuTMSludgeBomb, MauvilleCity_GameCorner_Text_MenuTMEarthquake, gText_Exit
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_TMDoubleTeam
	case 1, MauvilleCity_GameCorner_EventScript_TMPsychic
	case 2, MauvilleCity_GameCorner_EventScript_TMFlamethrower
	case 3, MauvilleCity_GameCorner_EventScript_TMThunderbolt
	case 4, MauvilleCity_GameCorner_EventScript_TMIceBeam
	case 5, MauvilleCity_GameCorner_EventScript_TMShadowBall
	case 6, MauvilleCity_GameCorner_EventScript_TMSludgeBomb
	case 7, MauvilleCity_GameCorner_EventScript_TMEarthquake
	goto MauvilleCity_GameCorner_EventScript_CancelTMSelect
	end

MauvilleCity_GameCorner_EventScript_TMDoubleTeam::
	setvar VAR_TEMP_1, TM_DOUBLE_TEAM_COINS
	setvar VAR_0x8004, ITEM_TM_DOUBLE_TEAM
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_TMPsychic::
	setvar VAR_TEMP_1, TM_PSYCHIC_COINS
	setvar VAR_0x8004, ITEM_TM_PSYCHIC
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_TMFlamethrower::
	setvar VAR_TEMP_1, TM_FLAMETHROWER_COINS
	setvar VAR_0x8004, ITEM_TM_FLAMETHROWER
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_TMThunderbolt::
	setvar VAR_TEMP_1, TM_THUNDERBOLT_COINS
	setvar VAR_0x8004, ITEM_TM_THUNDERBOLT
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_TMIceBeam::
	setvar VAR_TEMP_1, TM_ICE_BEAM_COINS
	setvar VAR_0x8004, ITEM_TM_ICE_BEAM
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_TMShadowBall::
	setvar VAR_TEMP_1, TM_SHADOW_BALL_COINS
	setvar VAR_0x8004, ITEM_TM_SHADOW_BALL
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_TMSludgeBomb::
	setvar VAR_TEMP_1, TM_SLUDGE_BOMB_COINS
	setvar VAR_0x8004, ITEM_TM_SLUDGE_BOMB
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_TMEarthquake::
	setvar VAR_TEMP_1, TM_EARTHQUAKE_COINS
	setvar VAR_0x8004, ITEM_TM_EARTHQUAKE
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_ConfirmTMPrize::
	bufferitemname STR_VAR_1, VAR_0x8004
	special BufferTMHMMoveName
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsTheTMX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_CancelTMSelect
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, VAR_TEMP_1, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	additem VAR_0x8004
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
	removecoins VAR_TEMP_1
	updatecoinsbox
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM::
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_NoRoomForTM::
	call Common_EventScript_BagIsFull
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_CancelTMSelect::
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
	hidecoinsbox
	release
	end

MauvilleCity_GameCorner_EventScript_Woman2::
	msgbox MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay, MSGBOX_NPC
	end

MauvilleCity_GameCorner_EventScript_Gentleman::
	msgbox MauvilleCity_GameCorner_Text_RouletteOnlyLuck, MSGBOX_NPC
	end

MauvilleCity_GameCorner_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_STARTER_DOLL, MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	msgbox MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_DeclineStarterDoll
	switch VAR_STARTER_MON
	case 0, MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll
	case 1, MauvilleCity_GameCorner_EventScript_GiveTorchicDoll
	case 2, MauvilleCity_GameCorner_EventScript_GiveMudkipDoll
	end

MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll::
	bufferdecorationname STR_VAR_2, DECOR_TREECKO_DOLL
	checkdecorspace DECOR_TREECKO_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_TREECKO_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_GiveTorchicDoll::
	bufferdecorationname STR_VAR_2, DECOR_TORCHIC_DOLL
	checkdecorspace DECOR_TORCHIC_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_TORCHIC_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_GiveMudkipDoll::
	bufferdecorationname STR_VAR_2, DECOR_MUDKIP_DOLL
	checkdecorspace DECOR_MUDKIP_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_MUDKIP_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll::
	call Common_EventScript_NoRoomForDecor
	msgbox MauvilleCity_GameCorner_Text_YouWantItButNotNow, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_DeclineStarterDoll::
	msgbox MauvilleCity_GameCorner_Text_DontBeNegative, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll::
	msgbox MauvilleCity_GameCorner_Text_CantWinJackpot, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_PokefanM::
	lock
	faceplayer
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_TryGive20Coins
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_TryGive20Coins::
	goto_if_set FLAG_RECEIVED_20_COINS, MauvilleCity_GameCorner_EventScript_PokefanMNormal
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, 1, MauvilleCity_GameCorner_EventScript_PokefanMNormal @ Only give 20 coins if player has no coins
	setflag FLAG_RECEIVED_20_COINS
	addcoins 20
	msgbox MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins, MSGBOX_DEFAULT
	playse SE_SHOP
	goto MauvilleCity_GameCorner_EventScript_PokefanMNormal
	end

MauvilleCity_GameCorner_EventScript_PokefanMNormal::
	msgbox MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_OldMan::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Cook::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Man::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_NPCReturnToSlots::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_GameCorner_EventScript_Maniac::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_DifficultToStopOn7, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Woman::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_SlotMachine0::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine1::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine2::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine3::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine4::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine5::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine6::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 6
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine7::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 7
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine8::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 8
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine9::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 9
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine10::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 10
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine11::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 11
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_NoCoinCase::
	msgbox MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner:
	.string "Este é o Mauville Game Corner.$"

MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins:
	.string "Veio comprar moedas pra jogar?\p"
	.string "Você precisa de uma Coin Case pra\n"
	.string "guardar elas.$"

MauvilleCity_GameCorner_Text_WereYouLookingForCoins:
	.string "Quer comprar moedas?\p"
	.string "Sao ¥1.000 por 50 moedas. Vai\n"
	.string "querer?$"

MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins:
	.string "Muito obrigado! Aqui estao suas\n"
	.string "moedas!$"

MauvilleCity_GameCorner_Text_DontHaveEnoughMoney:
	.string "Hum... Parece que você nao tem\n"
	.string "dinheiro suficiente...$"

MauvilleCity_GameCorner_Text_CoinCaseIsFull:
	.string "Opa, sua Coin Case ta cheia.$"

MauvilleCity_GameCorner_Text_DontNeedCoinsThen:
	.string "Ah, entao nao precisa de moedas?\n"
	.string "Boa sorte na aventura!$"

MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes:
	.string "Bem-vindo.\p"
	.string "Aqui você troca suas moedas por\n"
	.string "prêmios.$"

MauvilleCity_GameCorner_Text_WhichPrize:
	.string "Qual prêmio você quer?$"

MauvilleCity_GameCorner_Text_MenuTMDoubleTeam:
	.string "TM32{CLEAR_TO 72}1.500 moedas$"

MauvilleCity_GameCorner_Text_MenuTMPsychic:
	.string "TM29{CLEAR_TO 72}3.500 moedas$"

MauvilleCity_GameCorner_Text_MenuTMFlamethrower:
	.string "TM35{CLEAR_TO 72}4.000 moedas$"

MauvilleCity_GameCorner_Text_MenuTMThunderbolt:
	.string "TM24{CLEAR_TO 72}4.000 moedas$"

MauvilleCity_GameCorner_Text_MenuTMIceBeam:
	.string "TM13{CLEAR_TO 72}4.000 moedas$"

MauvilleCity_GameCorner_Text_MenuTMShadowBall:
	.string "TM30{CLEAR_TO 72}4.000 moedas$"

MauvilleCity_GameCorner_Text_MenuTMSludgeBomb:
	.string "TM36{CLEAR_TO 72}5.000 moedas$"

MauvilleCity_GameCorner_Text_MenuTMEarthquake:
	.string "TM26{CLEAR_TO 72}7,000 COINS$"

MauvilleCity_GameCorner_Text_SoYourChoiceIsTheTMX:
	.string "Entao você escolheu\n"
	.string "{STR_VAR_1} {STR_VAR_2}?$"

MauvilleCity_GameCorner_Text_SendToYourHomePC:
	.string "Obrigado! Vamos mandar pro PC da\n"
	.string "sua casa.$"

MauvilleCity_GameCorner_Text_NotEnoughCoins:
	.string "Você nao tem moedas suficientes.$"

@ Unused
MauvilleCity_GameCorner_Text_NoRoomForPlacingDecor:
	.string "Nao tem espaço pra colocar\n"
	.string "{STR_VAR_1}.$"

MauvilleCity_GameCorner_Text_OhIsThatSo:
	.string "Ah, entendi. Junte mais moedas e\n"
	.string "volte depois.$"

MauvilleCity_GameCorner_Text_SoYourChoiceIsX:
	.string "Entao você escolheu\n"
	.string "{STR_VAR_1}?$"

MauvilleCity_GameCorner_Text_HereYouGo:
	.string "Aqui está!$"

@ Unused
MauvilleCity_GameCorner_Text_CantCarryAnyMore:
	.string "Ah, você nao consegue carregar\n"
	.string "mais que isso.$"

MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne:
	.string "Fiz confusao e peguei dois bonecos\n"
	.string "iguais.\p"
	.string "Quer ficar com um?$"

MauvilleCity_GameCorner_Text_HereYouGo2:
	.string "Aqui está!$"

MauvilleCity_GameCorner_Text_YouWantItButNotNow:
	.string "Hein? Você quer, mas nao agora?$"

MauvilleCity_GameCorner_Text_DontBeNegative:
	.string "Ah, nao precisa recusar! Pode\n"
	.string "ficar com isto!$"

MauvilleCity_GameCorner_Text_CantWinJackpot:
	.string "Tem um prêmio que eu quero, mas\n"
	.string "nao consigo ganhar a bolada.$"

MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor:
	.string "Ei, pra jogar aqui você precisa de\n"
	.string "uma Coin Case.\p"
	.string "Acho que a moça da casa ao lado\n"
	.string "tem uma. Vai falar com ela!$"

MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins:
	.string "Minha sorte nao vai durar pra\n"
	.string "sempre. Já deu pra mim.\p"
	.string "Toma umas moedas!$"

MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone:
	.string "Mauville tem diversao pra todo\n"
	.string "mundo.\p"
	.string "Pra mim, é o cassino.$"

MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates:
	.string "As mesas de roleta têm apostas de\n"
	.string "valores diferentes.\p"
	.string "Confira suas moedas antes de\n"
	.string "escolher uma mesa.$"

MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime:
	.string "É fácil perder a noçao do tempo\n"
	.string "aqui. Preciso voltar pro trabalho.\p"
	.string "Meu chefe já deve estar jogando\n"
	.string "com outra equipe.$"

MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay:
	.string "Você precisa de moedas pra jogar\n"
	.string "no cassino.$"

MauvilleCity_GameCorner_Text_RouletteOnlyLuck:
	.string "Essa roleta nao é fácil...\p"
	.string "Ganhar ou perder depende só da\n"
	.string "sorte.$"

MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed:
	.string "Você pode usar até três moedas\n"
	.string "por rodada nas máquinas.$"

MauvilleCity_GameCorner_Text_DifficultToStopOn7:
	.string "É bem difícil parar no 7.\p"
	.string "Se conseguir durante o bônus Reel\n"
	.string "Time, você ganha moedas extras.$"

MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo:
	.string "Uma dica sobre as máquinas: quanto\n"
	.string "mais raios você juntar, mais\l"
	.string "chances de Reel Time consegue.\p"
	.string "Com o máximo de cinco chances, dá\n"
	.string "pra ganhar quatro bônus comuns e\l"
	.string "depois um grande.\p"
	.string "No total, sao 660 moedas. Mas é\n"
	.string "bem difícil conseguir.$"

MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase:
	.string "Você nao pode jogar sem uma Coin\n"
	.string "Case.$"

