SootopolisCity_House2_MapScripts::
	.byte 0

SootopolisCity_House2_EventScript_ExpertF::
	lock
	faceplayer
	msgbox SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, SootopolisCity_House2_EventScript_KnowAboutOrbs
	call_if_eq VAR_RESULT, NO, SootopolisCity_House2_EventScript_DontKnowAboutOrbs
	release
	end

SootopolisCity_House2_EventScript_KnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_YesTwoOrbsSideBySide, MSGBOX_DEFAULT
	return

SootopolisCity_House2_EventScript_DontKnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_OughtToVisitAndSee, MSGBOX_DEFAULT
	return

SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs:
	.string "Mt. Pyre...\p"
	.string "Tem duas Orbs lado a lado no topo.\n"
	.string "Você sabia?$"

SootopolisCity_House2_Text_YesTwoOrbsSideBySide:
	.string "Sim, duas Orbs lado a lado...\p"
	.string "Ver as duas juntas dá uma\n"
	.string "sensaçao de paz...$"

SootopolisCity_House2_Text_OughtToVisitAndSee:
	.string "Ah, é? Talvez você devesse visitar\n"
	.string "e ver...$"

