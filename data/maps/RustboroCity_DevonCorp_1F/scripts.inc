RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition:
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
	setobjectxyperm LOCALID_DEVON_CORP_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_DEVON_CORP_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
	.string "Oi, bem-vindo à Devon Corporation.\p"
	.string "Produzimos itens e remédios pra\n"
	.string "melhorar sua vida.$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
	.string "Um dos pesquisadores deu mole e\n"
	.string "deixou roubarem uma encomenda\l"
	.string "importante.$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
	.string "Ei, esses Running Shoes sao um dos\n"
	.string "nossos produtos!\p"
	.string "Fico feliz de ver alguém usando\n"
	.string "oque a gente faz.$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
	.string "Aquela encomenda roubada...\p"
	.string "Ela é importante, mas nao é\n"
	.string "qualquer um que sabe usar.\p"
	.string "Acho que aquele ladrao nao era\n"
	.string "muito esperto.$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.string "Parece que recuperaram os Devon\n"
	.string "Goods roubados.$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
	.string "Desculpa, só pessoas autorizadas\n"
	.string "podem entrar aqui.$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
	.string "Que falta de atençao. Como\n"
	.string "deixaram roubarem a gente?$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
	.string "Oi! Você é sempre bem-vindo aqui!$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.string "Tem amostras de pedras e metais no\n"
	.string "mostruário de vidro.\p"
	.string "O painel diz:\p"
	.string "“A Devon Corporation começou\n"
	.string "produzindo pedras em pedreiras.\l"
	.string "Também tirava ferro da areia.\p"
	.string "Com esse trabalho simples, a\n"
	.string "empresa cresceu.\p"
	.string "Hoje a Devon fabrica uma grande\n"
	.string "variedade de produtos.”$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string "O mostruário tem protótipos e\n"
	.string "produtos de teste.\p"
	.string "O painel diz:\p"
	.string "“Além dos produtos industriais, a\n"
	.string "Devon vende objetos do dia a dia e\l"
	.string "remédios.\p"
	.string "Recentemente, começou a fabricar\n"
	.string "ferramentas pra treinadores\l"
	.string "Pokémon, como Poké Balls e\l"
	.string "PokéNavs.”$"

