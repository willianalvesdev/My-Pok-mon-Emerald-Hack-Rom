LilycoveCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
	.byte 0

LilycoveCity_House3_OnTransition:
	random 4
	copyvar VAR_TEMP_1, VAR_RESULT
	end

LilycoveCity_House3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_House3_EventScript_DeclinePokeblockLearn
	msgbox LilycoveCity_House3_Text_ExplainPokeblocks, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_DeclinePokeblockLearn::
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_Man::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_GameBoyKid1::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid2::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid3::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid4::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_WereDoingMultiBattle::
	msgbox LilycoveCity_House3_Text_GoingToWinMultiBattles, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereMixingRecords::
	msgbox LilycoveCity_House3_Text_LikeMixingAtRecordCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereBlendingBerries::
	msgbox LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereDoingContest::
	msgbox LilycoveCity_House3_Text_GoingToEnterContest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks:
	.string "Nossa! Você viaja sozinho? Tao\n"
	.string "jovem! Muito bem!\p"
	.string "Meus filhos podiam aprender umas\n"
	.string "coisas com você.\p"
	.string "Eu? Sou especialista em\n"
	.string "{POKEBLOCK}S.\p"
	.string "Quando resolvo caprichar, faço\n"
	.string "{POKEBLOCK}S ótimos.\p"
	.string "Quer aprender a fazer {POKEBLOCK}S\n"
	.string "comigo?$"

LilycoveCity_House3_Text_OhAreYouSure:
	.string "Ah, tem certeza?\p"
	.string "Você nao precisa aprender tudo\n"
	.string "sozinho, meu bem!$"

LilycoveCity_House3_Text_ExplainPokeblocks:
	.string "Que bom! Presta atençao, porque a\n"
	.string "explicaçao é um pouco longa.\p"
	.string "Todo {POKEBLOCK} tem um valor de\n"
	.string "textura. Quanto menor esse valor,\l"
	.string "melhor. Guarda isso!\p"
	.string "Um bom {POKEBLOCK} tem textura\n"
	.string "baixa e nível alto.\p"
	.string "Seu Pokémon consegue comer mais\n"
	.string "{POKEBLOCK}S bons do que {POKEBLOCK}S\l"
	.string "comuns.\p"
	.string "Pra fazer {POKEBLOCK}S macios, use\n"
	.string "Berries de tipos diferentes. A\l"
	.string "escolha delas muda a textura dos\l"
	.string "{POKEBLOCK}S.\p"
	.string "Quanto mais gente misturando as\n"
	.string "Berries, mais macios ficam os\l"
	.string "{POKEBLOCK}S.\p"
	.string "Por isso vale a pena chamar outras\n"
	.string "pessoas pra preparar junto.\p"
	.string "É o principal que você precisa\n"
	.string "saber sobre {POKEBLOCK}S.\p"
	.string "Com Pokémon queridos, bons\n"
	.string "{POKEBLOCK}S e uma família\l"
	.string "carinhosa, o mundo seria mais\l"
	.string "feliz.\p"
	.string "Nao desiste, meu bem!$"

LilycoveCity_House3_Text_HappyToHaveQuadruplets:
	.string "Quando minha esposa teve\n"
	.string "quadrigêmeos, quase caí pra trás.\p"
	.string "Mas ver os quatro brincando juntos\n"
	.string "me deixa feliz.$"

LilycoveCity_House3_Text_GoingToWinMultiBattles:
	.string "Vamos fazer batalhas em grupo, mas\n"
	.string "eu já sei que vou ganhar!$"

LilycoveCity_House3_Text_LikeMixingAtRecordCorner:
	.string "A gente gosta de misturar coisas\n"
	.string "no Record Corner.\p"
	.string "Mas oque é que mistura mesmo?$"

LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender:
	.string "Vamos fazer {POKEBLOCK}S incríveis\n"
	.string "no Berry Blender!$"

LilycoveCity_House3_Text_GoingToEnterContest:
	.string "Quero mostrar como meu Pokémon é\n"
	.string "forte. Vamos entrar num concurso\l"
	.string "juntos!$"

