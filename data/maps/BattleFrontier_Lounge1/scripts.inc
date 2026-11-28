BattleFrontier_Lounge1_MapScripts::
	.byte 0

@ NPC that rates pokemon based on their IVs
BattleFrontier_Lounge1_EventScript_Breeder::
	lock
	faceplayer
	call_if_unset FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_BreederIntro
	call_if_set FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder
	setflag FLAG_MET_BATTLE_FRONTIER_BREEDER
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder::
	chooseboxmon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_ShowMonToBreeder
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge1_EventScript_BreederIntro::
	msgbox BattleFrontier_Lounge1_Text_PokemonBreederIntro, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder::
	msgbox BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon, MSGBOX_DEFAULT
	return

@ BufferVarsForIVRater buffers the following values
@ VAR_0x8005: Sum of the mons IVs
@ VAR_0x8006: Stat id of highest IV stat
@ VAR_0x8007: IV of the highest IV stat
BattleFrontier_Lounge1_EventScript_ShowMonToBreeder::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge1_EventScript_ShowEggToBreeder
	special BufferVarsForIVRater
	goto_if_le VAR_0x8005, 90, BattleFrontier_Lounge1_EventScript_AverageTotalIVs       @ Average of 15
	goto_if_le VAR_0x8005, 120, BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs @ Average of 20
	goto_if_le VAR_0x8005, 150, BattleFrontier_Lounge1_EventScript_HighTotalIVs         @ Average of 25
	goto_if_ge VAR_0x8005, 151, BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs     @ Average of > 25
	end

BattleFrontier_Lounge1_EventScript_ShowEggToBreeder::
	msgbox BattleFrontier_Lounge1_Text_EvenICantTell, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

@ Comment on the highest IV stat
BattleFrontier_Lounge1_EventScript_HighestIVStat::
	goto_if_eq VAR_0x8006, STAT_HP, BattleFrontier_Lounge1_EventScript_HighestIVHP
	goto_if_eq VAR_0x8006, STAT_ATK, BattleFrontier_Lounge1_EventScript_HighestIVAtk
	goto_if_eq VAR_0x8006, STAT_DEF, BattleFrontier_Lounge1_EventScript_HighestIVDef
	goto_if_eq VAR_0x8006, STAT_SPEED, BattleFrontier_Lounge1_EventScript_HighestIVSpeed
	goto_if_eq VAR_0x8006, STAT_SPATK, BattleFrontier_Lounge1_EventScript_HighestIVSpAtk
	goto_if_eq VAR_0x8006, STAT_SPDEF, BattleFrontier_Lounge1_EventScript_HighestIVSpDef
	end

@ Comment on the highest IV value
BattleFrontier_Lounge1_EventScript_HighestIVValue::
	goto_if_le VAR_0x8007, 15, BattleFrontier_Lounge1_EventScript_HighestIVLow
	goto_if_le VAR_0x8007, 25, BattleFrontier_Lounge1_EventScript_HighestIVMid
	goto_if_le VAR_0x8007, 30, BattleFrontier_Lounge1_EventScript_HighestIVHigh
	goto_if_ge VAR_0x8007, 31, BattleFrontier_Lounge1_EventScript_HighestIVMax
	end

BattleFrontier_Lounge1_EventScript_EndBreederComments::
	release
	end

BattleFrontier_Lounge1_EventScript_AverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_AverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_BetterThanAverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_ImpressiveAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_OutstandingAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighestIVHP::
	msgbox BattleFrontier_Lounge1_Text_BestAspectHP, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpeed::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpeed, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVLow::
	msgbox BattleFrontier_Lounge1_Text_StatRelativelyGood, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMid::
	msgbox BattleFrontier_Lounge1_Text_StatImpressive, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVHigh::
	msgbox BattleFrontier_Lounge1_Text_StatOutstanding, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMax::
	msgbox BattleFrontier_Lounge1_Text_StatFlawless, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_CancelMonSelect::
	msgbox BattleFrontier_Lounge1_Text_NoTimeForMyAdvice, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge1_EventScript_Boy1::
	msgbox BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding, MSGBOX_NPC
	end

BattleFrontier_Lounge1_EventScript_Boy2::
	msgbox BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt, MSGBOX_NPC
	end

BattleFrontier_Lounge1_Text_PokemonBreederIntro:
	.string "Crio Pokémon há 70 anos! Sou\n"
	.string "conhecido como um dos maiores\l"
	.string "criadores de Pokémon de todos os\l"
	.string "tempos!\p"
	.string "Quando tiver tanta experiência\n"
	.string "quanto eu, vai reconhecer o\l"
	.string "potencial de um Pokémon só de\l"
	.string "olhar.\p"
	.string "Você é um treinador. Nao tem\n"
	.string "curiosidade sobre o potencial dos\l"
	.string "seus Pokémon?\p"
	.string "Vamos! Deixe eu dar uma olhada!$"

BattleFrontier_Lounge1_Text_AverageAbility:
	.string "...Hum...\p"
	.string "No geral, eu diria que este\n"
	.string "Pokémon tem um potencial dentro da\l"
	.string "média.$"

BattleFrontier_Lounge1_Text_BetterThanAverageAbility:
	.string "...Hum...\p"
	.string "No geral, eu diria que este\n"
	.string "Pokémon tem um potencial acima da\l"
	.string "média.$"

BattleFrontier_Lounge1_Text_ImpressiveAbility:
	.string "...Hum...\p"
	.string "No geral, eu diria que este\n"
	.string "Pokémon tem um potencial\l"
	.string "impressionante!$"

BattleFrontier_Lounge1_Text_OutstandingAbility:
	.string "...Hum...\p"
	.string "No geral, eu diria que este\n"
	.string "Pokémon tem um potencial fora de\l"
	.string "série!$"

BattleFrontier_Lounge1_Text_BestAspectHP:
	.string "Aliás, eu diria que o ponto forte\n"
	.string "dele é o HP...$"

BattleFrontier_Lounge1_Text_BestAspectAtk:
	.string "Aliás, eu diria que o ponto forte\n"
	.string "dele é o Ataque...$"

BattleFrontier_Lounge1_Text_BestAspectDef:
	.string "Aliás, eu diria que o ponto forte\n"
	.string "dele é a Defesa...$"

BattleFrontier_Lounge1_Text_BestAspectSpAtk:
	.string "Aliás, eu diria que o ponto forte\n"
	.string "dele é o Ataque Especial...$"

BattleFrontier_Lounge1_Text_BestAspectSpDef:
	.string "Aliás, eu diria que o ponto forte\n"
	.string "dele é a Defesa Especial...$"

BattleFrontier_Lounge1_Text_BestAspectSpeed:
	.string "Aliás, eu diria que o ponto forte\n"
	.string "dele é a Velocidade...$"

BattleFrontier_Lounge1_Text_StatRelativelyGood:
	.string "Esse atributo é bom. ...Hum... Essa\n"
	.string "é a minha avaliaçao.$"

BattleFrontier_Lounge1_Text_StatImpressive:
	.string "Esse atributo é impressionante.\n"
	.string "...Hum... Essa é a minha avaliaçao.$"

BattleFrontier_Lounge1_Text_StatOutstanding:
	.string "Esse atributo é excelente!\n"
	.string "...Hum... Essa é a minha avaliaçao.$"

BattleFrontier_Lounge1_Text_StatFlawless:
	.string "É perfeito! Nao tem o que\n"
	.string "melhorar! ...Hum... Essa é a minha\l"
	.string "avaliaçao.$"

BattleFrontier_Lounge1_Text_NoTimeForMyAdvice:
	.string "O quê? Nao tem tempo para os meus\n"
	.string "conselhos?\p"
	.string "É bom aprender com a experiência\n"
	.string "dos mais velhos!$"

@ Unused
BattleFrontier_Lounge1_Text_HaveBusinessNeedsTending:
	.string "Sim, o que foi agora?\p"
	.string "Tenho coisas para fazer! Deixe\n"
	.string "para a próxima!$"

BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon:
	.string "Ah, jovem! Quer saber o potencial\n"
	.string "dos seus Pokémon?\p"
	.string "Vamos dar uma olhada neles!$"

BattleFrontier_Lounge1_Text_EvenICantTell:
	.string "Sou especialista, mas nem eu\n"
	.string "consigo avaliar um Pokémon que\l"
	.string "ainda nao nasceu!\p"
	.string "Mostre um Pokémon! É de um\n"
	.string "Pokémon que preciso!$"

BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding:
	.string "Ele disse que meu Pokémon é\n"
	.string "excelente! Valeu a pena treinar\l"
	.string "com tanto cuidado!$"

BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt:
	.string "Ele disse que meu Pokémon é\n"
	.string "excelente! Mas nem fiz nada de\l"
	.string "especial no treino...$"

