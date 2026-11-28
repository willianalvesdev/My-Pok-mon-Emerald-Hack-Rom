SootopolisCity_House3_MapScripts::
	.byte 0

SootopolisCity_House3_EventScript_Woman::
	lock
	faceplayer
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_HaveFans::
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_Girl::
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
	end

SootopolisCity_House3_Text_JuanHasManyFansDoYou:
	.string "Você é treinador Pokémon, né?\p"
	.string "Juan tem muitos fas. Até mais que\n"
	.string "seu aluno Wallace!\p"
	.string "Você também tem?$"

SootopolisCity_House3_Text_YouMustBePrettyStrong:
	.string "Ah, entao deve ser bem forte.$"

SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
	.string "Ah... Deve ser meio solitário.\p"
	.string "Se esforce mais um pouco pra\n"
	.string "conquistar uns fas.$"

SootopolisCity_House3_Text_TrainerFanClubWasWild:
	.string "Tem fas que vêm até de fora de\n"
	.string "Hoenn.\p"
	.string "Quando fui ao fa-clube de\n"
	.string "treinadores em Lilycove, tava uma\l"
	.string "loucura.$"

