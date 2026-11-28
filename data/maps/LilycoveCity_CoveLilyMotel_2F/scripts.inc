LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
	.string "Sou o responsável pelo projeto do\n"
	.string "jogo.\p"
	.string "Ah, você ta completando uma\n"
	.string "Pokédex?\p"
	.string "Dá trabalho, mas nao desiste.\p"
	.string "Quando completar, vem me mostrar!$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string "Nossa! Incrível mesmo!\p"
	.string "Você completou a Pokédex! Dá pra\n"
	.string "ver o quanto gosta de Pokémon!\p"
	.string "Fiquei impressionado!\p"
	.string "Quero dar uma coisa pra reconhecer\n"
	.string "tudo oque você fez.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string "Eu? Ta falando comigo? Sou o\n"
	.string "programador.\p"
	.string "Queria saber como sao as máquinas\n"
	.string "do cassino daqui.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string "Sou o artista que faz os gráficos!\p"
	.string "Os Pokémon de Hoenn sao\n"
	.string "interessantes, né?$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
	.string "As treinadoras com boia sao uma\n"
	.string "graça. Batalhar com elas é muito\l"
	.string "divertido!\p"
	.string "E as gêmeas? Sao adoráveis! Uma\n"
	.string "batalha em dupla com elas é\l"
	.string "diversao garantida!$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string "Essa brisa do mar deixa meu\n"
	.string "coraçao leve. É bom demais ficar\l"
	.string "aqui!$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string "Você nunca sabe quando alguém vai\n"
	.string "chamar pra uma batalha.\p"
	.string "Por isso nunca saio de casa sem\n"
	.string "meu Game Boy Advance.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "SCOTT: ... Zzz...\p"
	.string "Hein?! Ah, desculpa! Peguei no\n"
	.string "sono!\p"
	.string "Vim conhecer os concursos Pokémon.\n"
	.string "Parece bem divertido, mas...\p"
	.string "Eu ainda prefiro batalhas e\n"
	.string "treinadores fortes. É mais a minha\l"
	.string "praia.\p"
	.string "{PLAYER}{KUN}, aproveita tudo! Ginásios,\n"
	.string "concursos, Battle Tent, oque der\l"
	.string "vontade!$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "SCOTT: Ganhar um concurso também\n"
	.string "exige estratégia.\p"
	.string "Pensar nessas estratégias pode\n"
	.string "ajudar você a virar um treinador\l"
	.string "melhor.$"

