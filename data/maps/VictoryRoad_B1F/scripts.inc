VictoryRoad_B1F_MapScripts::
	.byte 0

VictoryRoad_B1F_EventScript_Samuel::
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Mitchell::
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Halle::
	trainerbattle_single TRAINER_HALLE, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_Text_SamuelIntro:
	.string "Pensar que tô tao perto da Liga\n"
	.string "Pokémon...\p"
	.string "Me dá um nervoso...$"

VictoryRoad_B1F_Text_SamuelDefeat:
	.string "Nao consegui fazer nada...$"

VictoryRoad_B1F_Text_SamuelPostBattle:
	.string "A Liga Pokémon ficou longe de\n"
	.string "novo... Que decepçao...$"

VictoryRoad_B1F_Text_ShannonIntro:
	.string "Pra vencer na Liga Pokémon, você\n"
	.string "precisa da confiança dos seus\l"
	.string "Pokémon.$"

VictoryRoad_B1F_Text_ShannonDefeat:
	.string "Vocês confiam de verdade uns nos\n"
	.string "outros.$"

VictoryRoad_B1F_Text_ShannonPostBattle:
	.string "Com o tempo juntos, a confiança\n"
	.string "entre Pokémon e treinador cresce.$"

VictoryRoad_B1F_Text_MichelleIntro:
	.string "Este nao é o objetivo final. É só\n"
	.string "o caminho até a Liga Pokémon.$"

VictoryRoad_B1F_Text_MichelleDefeat:
	.string "É assim que se faz!$"

VictoryRoad_B1F_Text_MichellePostBattle:
	.string "Você vai se sair bem! Seus Pokémon\n"
	.string "tao todos animados!$"

VictoryRoad_B1F_Text_MitchellIntro:
	.string "Meus Pokémon sao incríveis de\n"
	.string "outro mundo!$"

VictoryRoad_B1F_Text_MitchellDefeat:
	.string "Nunca conheci alguém como você.$"

VictoryRoad_B1F_Text_MitchellPostBattle:
	.string "Mesmo fora da batalha, sinto uma\n"
	.string "força enorme vindo de você e seus\l"
	.string "Pokémon.$"

VictoryRoad_B1F_Text_HalleIntro:
	.string "Calma, nao precisa ficar na\n"
	.string "defensiva! Vamos relaxar um pouco!$"

VictoryRoad_B1F_Text_HalleDefeat:
	.string "Nossa! Maravilhoso!$"

VictoryRoad_B1F_Text_HallePostBattle:
	.string "É, esta é a Victory Road.\p"
	.string "Mas nao é tao diferente dos\n"
	.string "caminhos que você já passou.\p"
	.string "Tente aproveitar o resto da\n"
	.string "viagem!$"

