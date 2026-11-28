VerdanturfTown_Mart_MapScripts::
	.byte 0

VerdanturfTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VerdanturfTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
VerdanturfTown_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_DUSK_BALL
	.2byte ITEM_HEAL_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_FLUFFY_TAIL
	pokemartlistend

VerdanturfTown_Mart_EventScript_Boy::
	msgbox VerdanturfTown_Mart_Text_XSpecialIsCrucial, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_ExpertF::
	msgbox VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_Lass::
	msgbox VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon, MSGBOX_NPC
	end

VerdanturfTown_Mart_Text_XSpecialIsCrucial:
	.string "X Special é muito importante nas\n"
	.string "batalhas.\p"
	.string "Ele aumenta a força de alguns\n"
	.string "golpes, mesmo que só por uma luta.$"

VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent:
	.string "Parece que nao vendem um guia pra\n"
	.string "ganhar na Battle Tent...\p"
	.string "Vou ter que pensar por conta\n"
	.string "própria mesmo.$"

VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon:
	.string "A Nest Ball funciona melhor com\n"
	.string "Pokémon fracos.\p"
	.string "Você pode comprar ela em\n"
	.string "Verdanturf.$"

