BattleFrontier_Lounge2_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMultiLink
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid
@ <= FRONTIER_MANIAC_TOWER_LINK is any Battle Tower mode
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews
@ >= FRONTIER_MANIAC_DOME is any facility other than Battle Tower
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMultiLink::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro::
	.string "Oi! Quando o assunto é notícia da\n"
	.string "BATTLE FRONTIER, sou o número um.\p"
	.string "Pode me chamar de fanático pela\n"
	.string "Frontier.\p"
	.string "Só para confirmar: você é um\n"
	.string "treinador, certo?\p"
	.string "Vou contar as novidades mais\n"
	.string "quentes que descobri por aqui.$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord::
	.string "Oi! Veio saber das últimas\n"
	.string "notícias? Tudo bem, eu conto!$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight::
	.string "E aí? E aí?\p"
	.string "Minhas informaçoes têm ajudado\n"
	.string "bastante, né?$"

BattleFrontier_Lounge2_Text_FacilityIsHottest::
	.string "Deixe eu ver...\p"
	.string "Parece que {STR_VAR_1} é o\n"
	.string "lugar do momento.$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest::
	.string "Deixe eu ver...\p"
	.string "Parece que a BATTLE TOWER\n"
	.string "{STR_VAR_1} está em alta.$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere::
	.string "Aposto que você nao sabia!\p"
	.string "Um daqueles grandes treinadores\n"
	.string "que SCOTT chama de FRONTIER\l"
	.string "BRAINS fica lá.\p"
	.string "Quem cuida do lugar é a misteriosa\n"
	.string "SALON MAIDEN.$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons::
	.string "Já enfrentou a SALON MAIDEN?\p"
	.string "Dizem que, quando está avaliando o\n"
	.string "adversário, ela usa estes Pokémon:\p"
	.string "Um Pokémon PSI do tipo Psíquico,\n"
	.string "um Pokémon Vulcao do tipo Fogo e\l"
	.string "um Pokémon Dorminhoco do tipo\l"
	.string "Normal.$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons::
	.string "Já enfrentou a SALON MAIDEN\n"
	.string "quando ela luta a sério?\p"
	.string "Dizem que, quando vai com tudo,\n"
	.string "ela usa estes Pokémon:\p"
	.string "Um Pokémon Eon dos tipos Dragao e\n"
	.string "Psíquico, um Pokémon Trovao do\l"
	.string "tipo Elétrico e um Pokémon\l"
	.string "Dorminhoco do tipo Normal.$"

BattleFrontier_Lounge2_Text_DomeAceIsThere::
	.string "Aposto que você nao sabia!\p"
	.string "Um daqueles grandes treinadores\n"
	.string "que SCOTT chama de FRONTIER\l"
	.string "BRAINS fica lá.\p"
	.string "Quem cuida do lugar é o DOME ACE,\n"
	.string "que adora chamar atençao.$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons::
	.string "Já enfrentou o DOME ACE?\p"
	.string "Quando pega leve, ele usa estes\n"
	.string "três Pokémon:\p"
	.string "Um Pokémon Dragao dos tipos Dragao\n"
	.string "e Voador, um Pokémon Peixe de Lama\l"
	.string "dos tipos Água e Terra e um\l"
	.string "Pokémon Chama dos tipos Fogo e\l"
	.string "Voador.$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons::
	.string "Já enfrentou o DOME ACE quando\n"
	.string "ele luta a sério?\p"
	.string "Quando mostra sua estratégia, ele\n"
	.string "usa estes três Pokémon:\p"
	.string "Um Pokémon Eon dos tipos Dragao e\n"
	.string "Voador, um Pokémon Peixe de Lama\l"
	.string "dos tipos Água e Terra e um\l"
	.string "Pokémon Perna de Ferro dos tipos\l"
	.string "Aço e Psíquico.$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere::
	.string "Aposto que você nao sabia!\p"
	.string "Um daqueles grandes treinadores\n"
	.string "que SCOTT chama de FRONTIER\l"
	.string "BRAINS fica lá.\p"
	.string "Quem cuida do lugar é o FACTORY\n"
	.string "HEAD, um treinador bem diferente.$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons::
	.string "Já enfrentou o FACTORY HEAD?\p"
	.string "Deixe eu pensar... Ele escolhe\n"
	.string "três Pokémon de aluguel para\l"
	.string "batalhar.\p"
	.string "As condiçoes sao praticamente as\n"
	.string "mesmas que as suas.$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons::
	.string "Já enfrentou o FACTORY HEAD\n"
	.string "quando ele luta a sério?\p"
	.string "Mesmo assim, ele escolhe três\n"
	.string "Pokémon de aluguel.\p"
	.string "As condiçoes sao praticamente as\n"
	.string "mesmas que as suas.$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere::
	.string "Aposto que você nao sabia!\p"
	.string "Um daqueles grandes treinadores\n"
	.string "que SCOTT chama de FRONTIER\l"
	.string "BRAINS fica lá.\p"
	.string "Quem cuida do lugar é a\n"
	.string "assustadora PIKE QUEEN.$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons::
	.string "Já enfrentou a PIKE QUEEN?\p"
	.string "Dizem que, quando está de bom\n"
	.string "humor, ela usa estes três Pokémon:\p"
	.string "Um Pokémon Cobra de Presas do tipo\n"
	.string "Veneno, um Pokémon Mofo dos tipos\l"
	.string "Inseto e Pedra e um Pokémon\l"
	.string "Ternura do tipo Água.$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons::
	.string "Já enfrentou a PIKE QUEEN quando\n"
	.string "ela luta a sério?\p"
	.string "Dizem que, quando fica bem\n"
	.string "irritada, ela usa estes três\l"
	.string "Pokémon:\p"
	.string "Um Pokémon Cobra de Presas do tipo\n"
	.string "Veneno, um Pokémon Cobra de Ferro\l"
	.string "dos tipos Aço e Terra e um Pokémon\l"
	.string "Atroz dos tipos Água e Voador.$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere::
	.string "Aposto que você nao sabia!\p"
	.string "Um daqueles grandes treinadores\n"
	.string "que SCOTT chama de FRONTIER\l"
	.string "BRAINS fica lá.\p"
	.string "Quem cuida do lugar é a simpática\n"
	.string "ARENA TYCOON.$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons::
	.string "Já enfrentou a ARENA TYCOON?\p"
	.string "Dizem que, quando está testando a\n"
	.string "força do adversário, ela usa estes\l"
	.string "Pokémon:\p"
	.string "Um Pokémon Chifre Único dos tipos\n"
	.string "Inseto e Lutador, um Pokémon Luar\l"
	.string "do tipo Sombrio e um Pokémon Casca\l"
	.string "dos tipos Inseto e Fantasma.$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons::
	.string "Já enfrentou a ARENA TYCOON\n"
	.string "quando ela luta a sério?\p"
	.string "Dizem que, quando quer ganhar de\n"
	.string "verdade, ela usa estes Pokémon:\p"
	.string "Um Pokémon Luar do tipo Sombrio,\n"
	.string "um Pokémon Sombra dos tipos\l"
	.string "Fantasma e Veneno e um Pokémon\l"
	.string "Cogumelo dos tipos Planta e\l"
	.string "Lutador.$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere::
	.string "Aposto que você nao sabia!\p"
	.string "Um daqueles grandes treinadores\n"
	.string "que SCOTT chama de FRONTIER\l"
	.string "BRAINS fica lá.\p"
	.string "Quem cuida do lugar é o PALACE\n"
	.string "MAVEN, um treinador bem\l"
	.string "assustador.$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons::
	.string "Já enfrentou o PALACE MAVEN?\p"
	.string "Dizem que, quando está testando a\n"
	.string "confiança do adversário, ele usa\l"
	.string "estes Pokémon:\p"
	.string "Um Pokémon Morcego dos tipos\n"
	.string "Veneno e Voador, um Pokémon\l"
	.string "Preguiçoso do tipo Normal e um\l"
	.string "Pokémon Transporte dos tipos Água\l"
	.string "e Gelo.$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons::
	.string "Já enfrentou o PALACE MAVEN\n"
	.string "quando ele luta a sério?\p"
	.string "Dizem que, quando usa toda a\n"
	.string "força, ele traz estes Pokémon:\p"
	.string "Um Pokémon Lendário do tipo Fogo,\n"
	.string "um Pokémon Preguiçoso do tipo\l"
	.string "Normal e um Pokémon Aurora do tipo\l"
	.string "Água.$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere::
	.string "Aposto que você nao sabia!\p"
	.string "Um daqueles grandes treinadores\n"
	.string "que SCOTT chama de FRONTIER\l"
	.string "BRAINS fica lá.\p"
	.string "Quem cuida do lugar é o PYRAMID\n"
	.string "KING, um treinador cheio de\l"
	.string "energia.$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons::
	.string "Já enfrentou o PYRAMID KING?\p"
	.string "Dizem que, quando está avaliando a\n"
	.string "força do adversário, ele usa estes\l"
	.string "Pokémon:\p"
	.string "Um Pokémon Pico de Pedra do tipo\n"
	.string "Pedra, um Pokémon Iceberg do tipo\l"
	.string "Gelo e um Pokémon Ferro do tipo\l"
	.string "Aço.$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons::
	.string "Já enfrentou o PYRAMID KING\n"
	.string "quando ele luta a sério?\p"
	.string "Dizem que, quando está com tudo,\n"
	.string "ele usa estes Pokémon:\p"
	.string "Um Pokémon Congelamento dos tipos\n"
	.string "Gelo e Voador, um Pokémon Elétrico\l"
	.string "dos tipos Elétrico e Voador e um\l"
	.string "Pokémon Chama dos tipos Fogo e\l"
	.string "Voador.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1::
	.string "Tem vários lugares para disputar\n"
	.string "batalhas em dupla.\p"
	.string "Mas as Salas de Batalhas em Dupla\n"
	.string "da BATTLE TOWER sao o básico!\p"
	.string "É lá que você deve aprender como\n"
	.string "essas batalhas funcionam na\l"
	.string "BATTLE FRONTIER.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2::
	.string "Tome cuidado nas batalhas daqui.\p"
	.string "Ouvi dizer que alguns treinadores\n"
	.string "criaram estratégias só para\l"
	.string "batalhas em dupla.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3::
	.string "Quando pegar o jeito das batalhas\n"
	.string "em dupla daqui, pense em desafiar\l"
	.string "os outros lugares com esse tipo de\l"
	.string "batalha.$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice::
	.string "Todo tipo de treinador aparece no\n"
	.string "Salao de Batalha.\p"
	.string "Você pode até encontrar amigos ou\n"
	.string "aprendizes! Vale a pena olhar com\l"
	.string "atençao!$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice::
	.string "Se estiver com um amigo, vá para a\n"
	.string "Sala de Batalhas em Parceria via\l"
	.string "Link.\p"
	.string "Com um amigo forte, vocês podem\n"
	.string "esperar adversários difíceis!$"

BattleFrontier_Lounge2_Text_NewsGatheringPower::
	.string "Que talento para conseguir\n"
	.string "notícias! Meu mentor é único!$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation::
	.string "Que olhar atento! Meu mentor é\n"
	.string "único!$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion::
	.string "Que jeito de convencer os outros!\n"
	.string "Meu mentor é único!$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe::
	.string "...Que lugar é este? Estou com\n"
	.string "medo...$"

