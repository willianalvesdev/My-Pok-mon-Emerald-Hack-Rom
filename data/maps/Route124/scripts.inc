Route124_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route124_OnTransition
	.byte 0

Route124_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

Route124_EventScript_HuntersHouseSign::
	msgbox Route124_Text_HuntersHouse, MSGBOX_SIGN
	end

Route124_EventScript_EVResetHouseSign::
	msgbox Route124_Text_EVResetHouseSign, MSGBOX_SIGN
	end

Route124_Text_EVResetHouseSign:
	.string "Casa de Treino\n"
	.string "Serviço gratuito de reset de EVs.$"

Route124_EventScript_GoldsmithHouseSign::
	msgbox Route124_Text_GoldsmithHouseSign, MSGBOX_SIGN
	end

Route124_Text_GoldsmithHouseSign:
	.string "Casa do Ourives\n"
	.string "Compra de Nuggets.$"

Route124_EventScript_ShinyCollectorHouseSign::
	msgbox Route124_Text_ShinyCollectorHouseSign, MSGBOX_SIGN
	end

Route124_Text_ShinyCollectorHouseSign:
	.string "Casa do Colecionador de Shinies.$"

Route124_EventScript_FishermansHouseSign::
	msgbox Route124_Text_FishermansHouseSign, MSGBOX_SIGN
	end

Route124_Text_FishermansHouseSign:
	.string "Casa do Pescador$"

Route124_EventScript_FeebasFisherman::
	lock
	faceplayer
	goto_if_set FLAG_ROUTE124_FISHERMAN_RECEIVED_FEEBAS, Route124_FeebasFisherman_Thanks
	msgbox Route124_Text_FeebasFisherman_Story, MSGBOX_DEFAULT
	setvar VAR_0x8004, SPECIES_FEEBAS
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	goto_if_eq VAR_RESULT, FALSE, Route124_FeebasFisherman_End
	msgbox Route124_Text_FeebasFisherman_Offer, MSGBOX_YESNO
	goto_if_ne VAR_RESULT, YES, Route124_FeebasFisherman_End
	special ChoosePartyMon
	goto_if_ge VAR_0x8004, PARTY_SIZE, Route124_FeebasFisherman_End
	setvar VAR_0x8005, FALSE
	callnative Script_TryDonateFeebas, requests_effects=1
	goto_if_ne VAR_RESULT, MON_DONATION_OK, Route124_FeebasFisherman_Refuse
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	msgbox Route124_Text_FeebasFisherman_Confirm, MSGBOX_YESNO
	goto_if_ne VAR_RESULT, YES, Route124_FeebasFisherman_End
	setvar VAR_0x8005, TRUE
	callnative Script_TryDonateFeebas, requests_effects=1
	goto_if_ne VAR_RESULT, MON_DONATION_OK, Route124_FeebasFisherman_Refuse
	playfanfare MUS_OBTAIN_ITEM
	msgbox Route124_Text_FeebasFisherman_Reward, MSGBOX_DEFAULT
	waitfanfare
	goto Route124_FeebasFisherman_End

Route124_FeebasFisherman_Refuse:
	switch VAR_RESULT
	case MON_DONATION_ALREADY_REWARDED, Route124_FeebasFisherman_Thanks
	case MON_DONATION_NEEDS_PARTNER, Route124_FeebasFisherman_NeedsPartner
	case MON_DONATION_HAS_ITEM, Route124_FeebasFisherman_HasItem
	case MON_DONATION_BAG_FULL, Route124_FeebasFisherman_BagFull
	msgbox Route124_Text_FeebasFisherman_Invalid, MSGBOX_DEFAULT
	goto Route124_FeebasFisherman_End

Route124_FeebasFisherman_NeedsPartner:
	msgbox Route124_Text_FeebasFisherman_NeedsPartner, MSGBOX_DEFAULT
	goto Route124_FeebasFisherman_End

Route124_FeebasFisherman_HasItem:
	msgbox Route124_Text_FeebasFisherman_HasItem, MSGBOX_DEFAULT
	goto Route124_FeebasFisherman_End

Route124_FeebasFisherman_BagFull:
	msgbox Route124_Text_FeebasFisherman_BagFull, MSGBOX_DEFAULT
	goto Route124_FeebasFisherman_End

Route124_FeebasFisherman_Thanks:
	msgbox Route124_Text_FeebasFisherman_Thanks, MSGBOX_DEFAULT

Route124_FeebasFisherman_End:
	release
	end

Route124_Text_FeebasFisherman_Story:
	.string "Pesco há anos atrás de um Feebas.\n"
	.string "Nunca vi nem a cauda!$"

Route124_Text_FeebasFisherman_Offer:
	.string "Pera, você tem um Feebas? Me dá\n"
	.string "um em troca de cinco Pamtre\l"
	.string "Berries?$"

Route124_Text_FeebasFisherman_Confirm:
	.string "Quer me entregar {STR_VAR_1}?\n"
	.string "Vou ficar com ele de vez.$"

Route124_Text_FeebasFisherman_Reward:
	.string "Valeu! Toma, cinco Pamtre Berries.\n"
	.string "Sao raras! Dizem que, se usar pra\l"
	.string "fazer Pokéblocks, ajudam Feebas a\l"
	.string "evoluir.$"

Route124_Text_FeebasFisherman_Invalid:
	.string "Escolha um Feebas do seu time.$"

Route124_Text_FeebasFisherman_NeedsPartner:
	.string "Você precisa deixar outro Pokémon\n"
	.string "que possa batalhar no time.$"

Route124_Text_FeebasFisherman_HasItem:
	.string "Tira o item que ele segura antes\n"
	.string "de fazer a troca.$"

Route124_Text_FeebasFisherman_BagFull:
	.string "Libera espaço na bolsa pras cinco\n"
	.string "Pamtre Berries.$"

Route124_Text_FeebasFisherman_Thanks:
	.string "Tô cuidando bem do meu Feebas.\n"
	.string "Valeu por realizar meu sonho!$"

Route124_EventScript_Spencer::
	trainerbattle_single TRAINER_SPENCER, Route124_Text_SpencerIntro, Route124_Text_SpencerDefeat
	msgbox Route124_Text_SpencerPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Roland::
	trainerbattle_single TRAINER_ROLAND, Route124_Text_RolandIntro, Route124_Text_RolandDefeat
	msgbox Route124_Text_RolandPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Jenny::
	trainerbattle_single TRAINER_JENNY_1, Route124_Text_JennyIntro, Route124_Text_JennyDefeat, Route124_EventScript_RegisterJenny
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route124_EventScript_RematchJenny
	msgbox Route124_Text_JennyPostBattle, MSGBOX_DEFAULT
	release
	end

Route124_EventScript_RegisterJenny::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route124_Text_JennyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JENNY_1
	release
	end

Route124_EventScript_RematchJenny::
	trainerbattle_rematch TRAINER_JENNY_1, Route124_Text_JennyRematchIntro, Route124_Text_JennyRematchDefeat
	msgbox Route124_Text_JennyPostRematch, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Grace::
	trainerbattle_single TRAINER_GRACE, Route124_Text_GraceIntro, Route124_Text_GraceDefeat
	msgbox Route124_Text_GracePostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Chad::
	trainerbattle_single TRAINER_CHAD, Route124_Text_ChadIntro, Route124_Text_ChadDefeat
	msgbox Route124_Text_ChadPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Lila::
	trainerbattle_double TRAINER_LILA_AND_ROY_1, Route124_Text_LilaIntro, Route124_Text_LilaDefeat, Route124_Text_LilaNotEnoughMons, Route124_EventScript_RegisterLila
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route124_EventScript_RematchLila
	msgbox Route124_Text_LilaPostBattle, MSGBOX_DEFAULT
	release
	end

Route124_EventScript_RegisterLila::
	msgbox Route124_Text_LilaRoyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LILA_AND_ROY_1
	release
	end

Route124_EventScript_RematchLila::
	trainerbattle_rematch_double TRAINER_LILA_AND_ROY_1, Route124_Text_LilaRematchIntro, Route124_Text_LilaRematchDefeat, Route124_Text_LilaRematchNotEnoughMons
	msgbox Route124_Text_LilaPostRematch, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Roy::
	trainerbattle_double TRAINER_LILA_AND_ROY_1, Route124_Text_RoyIntro, Route124_Text_RoyDefeat, Route124_Text_RoyNotEnoughMons, Route124_EventScript_RegisterRoy
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route124_EventScript_RematchRoy
	msgbox Route124_Text_RoyPostBattle, MSGBOX_DEFAULT
	release
	end

Route124_EventScript_RegisterRoy::
	msgbox Route124_Text_LilaRoyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LILA_AND_ROY_1
	release
	end

Route124_EventScript_RematchRoy::
	trainerbattle_rematch_double TRAINER_LILA_AND_ROY_1, Route124_Text_RoyRematchIntro, Route124_Text_RoyRematchDefeat, Route124_Text_RoyRematchNotEnoughMons
	msgbox Route124_Text_RoyPostRematch, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Declan::
	trainerbattle_single TRAINER_DECLAN, Route124_Text_DeclanIntro, Route124_Text_DeclanDefeat
	msgbox Route124_Text_DeclanPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Isabella::
	trainerbattle_single TRAINER_ISABELLA, Route124_Text_IsabellaIntro, Route124_Text_IsabellaDefeat
	msgbox Route124_Text_IsabellaPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_Text_HuntersHouse:
	.string "Casa do caçador de tesouros$"

