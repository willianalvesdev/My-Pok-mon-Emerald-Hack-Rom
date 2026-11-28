RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_OldMan::
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman::
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

@ Misspelling on purpose, see nickname
RustboroCity_House3_EventScript_Pekachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Text_IGivePerfectlySuitedNicknames:
	.string "Dou apelidos que combinam\n"
	.string "perfeitamente com meus Pokémon!\p"
	.string "É minha forma de mostrar...\n"
	.string "Originalidade! Isso!$"

RustboroCity_House3_Text_NamingPikachuPekachu:
	.string "Mas chamar um Pikachu de Pekachu?\n"
	.string "Nao muda quase nada.\p"
	.string "É bom ter um nome fácil de\n"
	.string "entender, mas...$"

RustboroCity_House3_Text_Pekachu:
	.string "PEKACHU: Peka!$"

