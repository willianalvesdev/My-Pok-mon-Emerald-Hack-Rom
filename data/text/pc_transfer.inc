gText_PkmnTransferredSomeonesPC::
	.string "{STR_VAR_2} foi enviado para o\n"
	.string "PC de alguém. Foi colocado na Box\l"
	.string "“{STR_VAR_1}“.$"

gText_PkmnTransferredLanettesPC::
	.string "{STR_VAR_2} foi enviado para o\n"
#if IS_FRLG
	.string "PC de Bill.\p"
#else
	.string "PC de Lanette.\p"
#endif
	.string "Foi colocado na Box\n"
	.string "“{STR_VAR_1}“.$"

gText_PkmnTransferredSomeonesPCBoxFull::
	.string "A Box “{STR_VAR_3}“ no PC de\n"
	.string "alguém estava cheia.\l"
	.string "{STR_VAR_2} foi enviado para a\l"
	.string "Box “{STR_VAR_1}“.$"

gText_PkmnTransferredLanettesPCBoxFull::
	.string "A Box “{STR_VAR_3}“ no\n"
#if IS_FRLG
	.string "PC de Bill estava cheia.\p"
#else
	.string "PC de Lanette estava cheia.\p"
#endif
	.string "{STR_VAR_2} foi enviado para a\n"
	.string "Box “{STR_VAR_1}“.$"

gText_PkmnSentToPCAfterCatch::
	.string "{STR_VAR_2} foi enviado para o\n"
	.string "PC de {B_PC_CREATOR_NAME}. Foi\l"
	.string "colocado na Box “{STR_VAR_1}“.$"

gText_PlayerObtainedTheMon::
	.string "{PLAYER} recebeu {STR_VAR_1}!$"

gText_NoMoreRoomForPokemon::
	.string "Nao há mais espaço para Pokémon!\n"
	.string "Todas as Boxes estao cheias!$"

gText_NicknameThisPokemon::
	.string "Quer dar um apelido a esse\n"
	.string "{STR_VAR_1}?$"
