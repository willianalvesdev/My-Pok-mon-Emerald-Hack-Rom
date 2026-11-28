PetalburgCity_House2_MapScripts::
	.byte 0

PetalburgCity_House2_EventScript_Woman::
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
	end

PetalburgCity_House2_EventScript_SchoolKid::
	msgbox PetalburgCity_House2_Text_BattledNormanOnce, MSGBOX_NPC
	end

PetalburgCity_House2_Text_NormanBecameGymLeader:
	.string "Norman é o novo líder da cidade.\p"
	.string "Acho que ele trouxe a família de\n"
	.string "um lugar bem longe.$"

PetalburgCity_House2_Text_BattledNormanOnce:
	.string "Batalhei com Norman uma vez.\n"
	.string "Nossa, ele é forte demais!\p"
	.string "Como posso explicar? Parece que\n"
	.string "ele vive pros Pokémon.$"

