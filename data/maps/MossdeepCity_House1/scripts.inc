MossdeepCity_House1_MapScripts::
	.byte 0

MossdeepCity_House1_EventScript_BlackBelt::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox MossdeepCity_House1_Text_HmmYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetPokeblockNameByMonNature
	goto_if_eq VAR_RESULT, 0, MossdeepCity_House1_EventScript_NeutralNature
	msgbox MossdeepCity_House1_Text_ItLikesXPokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_NeutralNature::
	msgbox MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_Woman::
	msgbox MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes, MSGBOX_NPC
	end

MossdeepCity_House1_Text_HmmYourPokemon:
	.string "Hum! Seu {STR_VAR_1}...$"

MossdeepCity_House1_Text_ItLikesXPokeblocks:
	.string "Gosta de {STR_VAR_1}S, nao é?\p"
	.string "Tenho certeza! Gosta muito de\n"
	.string "{STR_VAR_1}S!$"

MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks:
	.string "Parece que nao tem preferência por\n"
	.string "nenhum tipo de {POKEBLOCK}.$"

MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes:
	.string "Meu marido sabe o tipo de\n"
	.string "{POKEBLOCK}S que um Pokémon gosta\l"
	.string "só de olhar.$"

