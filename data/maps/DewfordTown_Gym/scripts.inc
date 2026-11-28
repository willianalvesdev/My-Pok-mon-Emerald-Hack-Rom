DewfordTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
	.byte 0

DewfordTown_Gym_OnTransition:
	call DewfordTown_Gym_EventScript_SetFlashLevel
	end

DewfordTown_Gym_EventScript_SetFlashLevel::
	goto_if_defeated TRAINER_BRAWLY_1, DewfordTown_Gym_EventScript_SetLightsOn
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 0, DewfordTown_Gym_EventScript_SetFlashLevel7
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_SetFlashLevel6
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_SetFlashLevel5
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_SetFlashLevel4
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_SetFlashLevel3
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_SetFlashLevel2
	goto DewfordTown_Gym_EventScript_SetFlashLevel1

DewfordTown_Gym_EventScript_SetLightsOn::
	setflashlevel 0
	return

@ Brightest
DewfordTown_Gym_EventScript_SetFlashLevel1::
	setflashlevel 1
	return

DewfordTown_Gym_EventScript_SetFlashLevel2::
	setflashlevel 2
	return

DewfordTown_Gym_EventScript_SetFlashLevel3::
	setflashlevel 3
	return

DewfordTown_Gym_EventScript_SetFlashLevel4::
	setflashlevel 4
	return

DewfordTown_Gym_EventScript_SetFlashLevel5::
	setflashlevel 5
	return

DewfordTown_Gym_EventScript_SetFlashLevel6::
	setflashlevel 6
	return

@ Darkest
DewfordTown_Gym_EventScript_SetFlashLevel7::
	setflashlevel 7
	return

DewfordTown_Gym_EventScript_BrightenRoom::
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	nop1
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
	goto_if_eq VAR_0x8000, 6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers

DewfordTown_Gym_EventScript_NoLightChange::
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
DewfordTown_Gym_EventScript_AnimateFlash1Trainer::
	playse SE_SWITCH
	animateflash 6
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash2Trainers::
	playse SE_SWITCH
	animateflash 5
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash3Trainers::
	playse SE_SWITCH
	animateflash 4
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash4Trainers::
	playse SE_SWITCH
	animateflash 3
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash5Trainers::
	playse SE_SWITCH
	animateflash 2
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash6Trainers::
	playse SE_SWITCH
	animateflash 1
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlashFullBrightness::
	playse SE_SWITCH
	animateflash 0
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_CountTrainersDefeated::
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckJocelyn::
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLaura::
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckBrenden::
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckCristian::
	goto_if_not_defeated TRAINER_CRISTIAN, DewfordTown_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLilith::
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_StopCountingTrainers::
	return

DewfordTown_Gym_EventScript_Brawly::
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, DewfordTown_Gym_EventScript_GiveBulkUp2
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_BrawlyDefeated::
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call DewfordTown_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

DewfordTown_Gym_EventScript_GiveBulkUp::
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	return

DewfordTown_Gym_EventScript_GiveBulkUp2:
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	release
	end

DewfordTown_Gym_EventScript_BrawlyRematch::
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_Takao::
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_TakaoBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Jocelyn::
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_JocelynBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LauraBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Brenden::
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_BrendenBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Cristian::
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_CristianBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Lilith::
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LilithBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_GymGuidePostVictory::
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_GymStatueCertified::
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_EventScript_GymStatue::
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_Text_GymGuideAdvice:
	.string "Ei, tudo certo, futuro campeao\n"
	.string "{PLAYER}?\p"
	.string "BRAWLY, o líder de DEWFORD, usa\n"
	.string "POKÉMONS do tipo Lutador.\p"
	.string "Enfrentar ele com POKÉMONS do tipo\n"
	.string "Normal é pedir pra apanhar.\p"
	.string "Os golpes de luta dao muito dano\n"
	.string "neles, entao cuidado!\p"
	.string "Além disso, aqui é escuro como o\n"
	.string "fundo do mar.\p"
	.string "Mas vai ficando mais claro quando\n"
	.string "você vence os treinadores.\p"
	.string "Agora vai lá!$"

DewfordTown_Gym_Text_GymGuidePostVictory:
	.string "Nossa! Agora ficou claro demais\n"
	.string "aqui!\p"
	.string "Seu futuro também ta brilhando!$"

DewfordTown_Gym_Text_TakaoIntro:
	.string "Aqui quem tem força manda! Pode\n"
	.string "vir!$"

DewfordTown_Gym_Text_TakaoDefeat:
	.string "Faltou força...$"

DewfordTown_Gym_Text_TakaoPostBattle:
	.string "Sua técnica venceu minha força!\n"
	.string "Você sabe mesmo oque faz!$"

DewfordTown_Gym_Text_JocelynIntro:
	.string "Nem precisa chamar o BRAWLY!\p"
	.string "Eu mesma vou acabar com você!$"

DewfordTown_Gym_Text_JocelynDefeat:
	.string "Mas... Como? Como eu perdi tao\n"
	.string "fácil?$"

DewfordTown_Gym_Text_JocelynPostBattle:
	.string "Vou usar essa derrota como motivo\n"
	.string "pra treinar mais!\p"
	.string "Um dia vou ser líder de ginásio...\p"
	.string "Nao, vou ser campea da POKéMON\n"
	.string "LEAGUE!$"

DewfordTown_Gym_Text_LauraIntro:
	.string "Nao pense em me ignorar! Depois\n"
	.string "nao venha chorar!$"

DewfordTown_Gym_Text_LauraDefeat:
	.string "Buaaaa! Eu perdi!$"

DewfordTown_Gym_Text_LauraPostBattle:
	.string "Batalho no escuro pra fortalecer\n"
	.string "meu coraçao.\p"
	.string "Mas desse jeito eu nunca consigo\n"
	.string "ver o rosto do BRAWLY...$"

DewfordTown_Gym_Text_LilithIntro:
	.string "Ufufu... Ta andando sem rumo no\n"
	.string "escuro?$"

DewfordTown_Gym_Text_LilithDefeat:
	.string "Ah, você... Nao quero nem saber!$"

DewfordTown_Gym_Text_LilithPostBattle:
	.string "Tomara que você se perca e volte\n"
	.string "parar lá na entrada!$"

DewfordTown_Gym_Text_BrendenIntro:
	.string "Vou te mostrar a coragem de um\n"
	.string "homem do mar!$"

DewfordTown_Gym_Text_BrendenDefeat:
	.string "Como isso aconteceu? Eu nao\n"
	.string "costumo perder desse jeito!$"

DewfordTown_Gym_Text_BrendenPostBattle:
	.string "Você merece enfrentar nosso líder,\n"
	.string "sim!$"

DewfordTown_Gym_Text_CristianIntro:
	.string "Quer passar? Entao vai ter que me\n"
	.string "vencer!$"

DewfordTown_Gym_Text_CristianDefeat:
	.string "Grrrr! Você acabou comigo!$"

DewfordTown_Gym_Text_CristianPostBattle:
	.string "Você venceu! Vai atrás daquela\n"
	.string "insígnia!$"

DewfordTown_Gym_Text_BrawlyIntro:
	.string "Sou BRAWLY, o líder de DEWFORD!\p"
	.string "Fiquei forte enfrentando as ondas\n"
	.string "daqui e treinando naquela caverna\l"
	.string "escura!\p"
	.string "Veio me desafiar? Quero ver do que\n"
	.string "você é capaz!$"

DewfordTown_Gym_Text_BrawlyDefeat:
	.string "Uau! Você fez uma onda bem maior\n"
	.string "do que eu esperava!\p"
	.string "Acabou me levando junto!\p"
	.string "Ta certo, você ganhou. Pegue esta\n"
	.string "insígnia!$"

DewfordTown_Gym_Text_ReceivedKnuckleBadge:
	.string "{PLAYER} recebeu a KNUCKLE BADGE\n"
	.string "de BRAWLY.$"

DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis:
	.string "Com a KNUCKLE BADGE, todos os\n"
	.string "POKÉMONS até o nível 30 obedecem\l"
	.string "você, até os recebidos por troca.\p"
	.string "Você também poderá usar FLASH\n"
	.string "fora das batalhas.\p"
	.string "Pode ficar com esta TM também.$"

DewfordTown_Gym_Text_ExplainBulkUp:
	.string "A TM08 ensina BULK UP.\p"
	.string "Esse golpe aumenta o Ataque e a\n"
	.string "Defesa.\p"
	.string "... ... ... ... ... ...$"

DewfordTown_Gym_Text_RegisteredBrawly:
	.string "O líder BRAWLY foi registrado no\n"
	.string "POKéNAV.$"

DewfordTown_Gym_Text_BrawlyPostBattle:
	.string "Seu talento ainda vai crescer como\n"
	.string "uma onda gigante e surpreender\l"
	.string "muitos treinadores!$"

DewfordTown_Gym_Text_GymStatue:
	.string "Ginásio Pokémon de DEWFORD TOWN$"

DewfordTown_Gym_Text_GymStatueCertified:
	.string "Ginásio Pokémon de DEWFORD TOWN\p"
	.string "Treinadores reconhecidos por\n"
	.string "BRAWLY: {PLAYER}$"

DewfordTown_Gym_Text_BrawlyPreRematch:
	.string "BRAWLY: Uma onda recua, mas sempre\n"
	.string "volta pra praia.\p"
	.string "Eu sabia que um talento como você\n"
	.string "ia voltar!\p"
	.string "Mostre o quanto cresceu!$"

DewfordTown_Gym_Text_BrawlyRematchDefeat:
	.string "Uau! Fui levado pela onda de novo!$"

DewfordTown_Gym_Text_BrawlyPostRematch:
	.string "BRAWLY: O mundo das batalhas é\n"
	.string "enorme e profundo. Você nunca vê\l"
	.string "o fundo. Igual ao mar de HOENN!$"

DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons:
	.string "BRAWLY: Uma onda recua, mas sempre\n"
	.string "volta pra praia.\p"
	.string "Eu sabia que um talento como você\n"
	.string "ia voltar!\p"
	.string "Opa, você só tem um POKÉMON em\n"
	.string "condiçoes de lutar.\p"
	.string "Volte com pelo menos dois, ta?$"
