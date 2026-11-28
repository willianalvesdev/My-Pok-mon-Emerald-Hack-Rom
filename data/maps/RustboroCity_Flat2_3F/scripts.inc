RustboroCity_Flat2_3F_MapScripts::
	.byte 0

RustboroCity_Flat2_3F_EventScript_DevonEmployee::
	msgbox RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones, MSGBOX_NPC
	end

RustboroCity_Flat2_3F_EventScript_Woman::
	msgbox RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones, MSGBOX_NPC
	end

RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones:
	.string "O presidente da Devon gosta de\n"
	.string "colecionar pedras raras.$"

RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones:
	.string "Acho que o filho do presidente\n"
	.string "também coleciona pedras raras.$"

