#include "global.h"
#include "strings.h"
#include "battle_pyramid_bag.h"
#include "item_menu.h"

ALIGNED(4)
const u8 gText_ExpandedPlaceholder_Empty[] = _("");
const u8 gText_ExpandedPlaceholder_Kun[] = _("");
const u8 gText_ExpandedPlaceholder_Chan[] = _("");
const u8 gText_ExpandedPlaceholder_Sapphire[] = _("SAPPHIRE");
const u8 gText_ExpandedPlaceholder_Ruby[] = _("RUBY");
const u8 gText_ExpandedPlaceholder_Emerald[] = _("EMERALD");
const u8 gText_ExpandedPlaceholder_Aqua[] = _("AQUA");
const u8 gText_ExpandedPlaceholder_Magma[] = _("MAGMA");
const u8 gText_ExpandedPlaceholder_Archie[] = _("ARCHIE");
const u8 gText_ExpandedPlaceholder_Maxie[] = _("MAXIE");
const u8 gText_ExpandedPlaceholder_Kyogre[] = _("KYOGRE");
const u8 gText_ExpandedPlaceholder_Groudon[] = _("GROUDON");
const u8 gText_ExpandedPlaceholder_Brendan[] = _("BRENDAN");
const u8 gText_ExpandedPlaceholder_May[] = _("MAY");
const u8 gText_ExpandedPlaceholder_Red[] = _("RED");
const u8 gText_ExpandedPlaceholder_Green[] = _("GREEN");
const u8 gText_EggNickname[POKEMON_NAME_LENGTH + 1] = _("EGG");
const u8 gText_Pokemon[POKEMON_NAME_LENGTH + 1] = _("POKéMON");
const u8 gText_Player[] = _("PLAYER"); // Unused
const u8 gText_Pokedex[] = _("POKéDEX"); // Unused
const u8 gText_Time[] = _("TIME");
const u8 gText_Badges[] = _("BADGES"); // Unused
const u8 gText_AButton[] = _("A Button"); // Unused
const u8 gText_BButton[] = _("B Button"); // Unused
const u8 gText_RButton[] = _("R Button"); // Unused
const u8 gText_LButton[] = _("L Button"); // Unused
const u8 gText_Start[] = _("START"); // Unused
const u8 gText_Select[] = _("SELECT"); // Unused
const u8 gText_ControlPad[] = _("+ Control Pad"); // Unused
const u8 gText_LButtonRButton[] = _("L Button  R Button"); // Unused
const u8 gText_Controls[] = _("CONTROLS"); // Unused
ALIGNED(4) const u8 gText_PickOk[] = _("{DPAD_UPDOWN}PICK {A_BUTTON}OK"); // Unused
ALIGNED(4) const u8 gText_Next[] = _("{A_BUTTON}NEXT");
ALIGNED(4) const u8 gText_NextBack[] = _("{A_BUTTON}NEXT {B_BUTTON}BACK");
ALIGNED(4) const u8 gText_PickNextCancel[] = _("{DPAD_UPDOWN}PICK {A_BUTTON}NEXT {B_BUTTON}CANCEL");
ALIGNED(4) const u8 gText_PickCancel[] = _("{DPAD_UPDOWN}PICK {A_BUTTON}{B_BUTTON}CANCEL");
ALIGNED(4) const u8 gText_AButtonExit[] = _("{A_BUTTON}EXIT");
const u8 gText_Boy[] = _("Menino");
const u8 gText_Girl[] = _("Menina");
const u8 gText_ThisIsAPokemon[] = _("Esse aqui é um Pokémon.{PAUSE 96}\p");
const u8 gText_5MarksPokemon[] = _("????? POKéMON");
const u8 gText_CryOf[] = _("CRY OF");
const u8 gText_SizeComparedTo[] = _("SIZE COMPARED TO ");
const u8 gText_SelectorArrow[] = _("▶");
const u8 gText_EmptySpace[] = _(" "); // Unused
const u8 gText_WelcomeToHOF[] = _("Bem-vindo ao Hall of Fame!");
const u8 gText_HOFDexRating[] = _("Pokémon vistos: {STR_VAR_1}!\n"
        "Capturados: {STR_VAR_2}!\l"
        "Avaliaçao da Pokédex pelo Prof.\l"
        "Birch! PROF. BIRCH: Vamos ver...\p");
const u8 gText_HOFDexSaving[] = _("SALVANDO... NAO DESLIGUE O JOGO.");
const u8 gText_HOFCorrupted[] = _("Os dados do Hall of Fame estao\n"
        "corrompidos.");
const u8 gText_HOFNumber[] = _("HALL OF FAME Nº {STR_VAR_1}");
const u8 gText_LeagueChamp[] = _("CAMPEAO DA LIGA! PARABÉNS!");
const u8 gText_Number[] = _("No. ");
const u8 gText_Level[] = _("Lv. ");
const u8 gText_IdNumberSlash[] = _("IDNo. /"); // Unused
const u8 gText_Name[] = _("NAME");
const u8 gText_IDNumber[] = _("IDNo.");
const u8 gText_BirchInTrouble[] = _("O Prof. Birch está em perigo!\n"
        "Solte um Pokémon e salve ele!");
const u8 gText_ConfirmStarterChoice[] = _("Quer escolher esse Pokémon?");
const u8 gText_Pokemon4[] = _("POKéMON"); // Unused
const u8 gText_FlyToWhere[] = _("Usar Fly para onde?");
const u8 gMenuText_Use[] = _("USE");
const u8 gMenuText_Toss[] = _("TOSS");
const u8 gMenuText_Register[] = _("REGISTER");
const u8 gMenuText_Give[] = _("GIVE");
const u8 gMenuText_Confirm[] = _("CONFIRM");
const u8 gText_Cancel[] = _("Cancelar");
const u8 gText_Cancel2[] = _("Cancelar");
const u8 gText_EmptyString2[] = _("");
const u8 gText_None[] = _("NONE");
const u8 gText_FiveMarks[] = _("?????");
const u8 gText_Slash[] = _("/");
const u8 gText_OneDash[] = _("-");
const u8 gText_TwoDashes[] = _("--");
const u8 gText_ThreeDashes[] = _("---");
const u8 gText_MaleSymbol[] = _("♂");
const u8 gText_FemaleSymbol[] = _("♀");
const u8 gText_LevelSymbol[] = _("{LV}");
const u8 gText_NumberClear01[] = _("{NO}{CLEAR 1}");
const u8 gText_RightArrow[] = _("{RIGHT_ARROW}"); // Unused
const u8 gText_IDNumber2[] = _("{ID}{NO}");
const u8 gText_Space[] = _(" ");
const u8 gText_SelectorArrow2[] = _("▶");
const u8 gText_GoBackPrevMenu[] = _("Voltar ao menu\n"
        "anterior.");
const u8 gText_WhatWouldYouLike[] = _("Oque quer fazer?");
const u8 gMenuText_Give2[] = _("GIVE");
const u8 gText_xVar1[] = _("×{STR_VAR_1}");
const u8 gText_Berry2[] = _(" BERRY"); // Unused
const u8 gText_Coins[] = _("{STR_VAR_1} COINS");
const u8 gText_CloseBag[] = _("CLOSE BAG");
const u8 gText_Var1IsSelected[] = _("{STR_VAR_1}\nis selected.");
const u8 gText_CantWriteMail[] = _("Nao pode escrever uma carta aqui.");
const u8 gText_NoPokemon[] = _("Nao há Pokémon.");
const u8 gText_MoveVar1Where[] = _("Mover {STR_VAR_1} para onde?");
const u8 gText_Var1CantBeHeld[] = _("Nao pode equipar {STR_VAR_1}.");
const u8 gText_TossHowManyVar1s[] = _("Jogar fora quantos\n"
        "{STR_VAR_1}?");
const u8 gText_ThrewAwayVar2Var1s[] = _("Jogou fora {STR_VAR_2}\n"
        "{STR_VAR_1}.");
const u8 gText_ConfirmTossItems[] = _("Pode jogar fora {STR_VAR_2}\n"
        "{STR_VAR_1}?");
const u8 gText_DadsAdvice[] = _("Conselho do pai... {PLAYER}, tudo\n"
        "tem sua hora e seu lugar!{PAUSE_UNTIL_PRESS}");
const u8 gText_PlayerUsedVar2[] = _("{PLAYER} usou {STR_VAR_2}.{PAUSE_UNTIL_PRESS}");
const u8 gText_RepelEffectsLingered[] = _("Mas o efeito de um Repel ainda\n"
        "está ativo.{PAUSE_UNTIL_PRESS}");
const u8 gText_LureEffectsLingered[] = _("Mas o efeito de um Lure ainda está\n"
        "ativo.{PAUSE_UNTIL_PRESS}");
const u8 gText_BoxFull[] = _("A Box está cheia.{PAUSE_UNTIL_PRESS}");
const u8 gText_TheField[] = _("the field");
const u8 gText_TheBattle[] = _("the battle");
const u8 gText_ThePokemonList[] = _("the POKéMON LIST");
const u8 gText_TheShop[] = _("the shop");
const u8 gText_ThePC[] = _("the PC");

const u8 *const gBagMenu_ReturnToStrings[] =
{
    [ITEMMENULOCATION_FIELD]               = gText_TheField,
    [ITEMMENULOCATION_BATTLE]              = gText_TheBattle,
    [ITEMMENULOCATION_PARTY]               = gText_ThePokemonList,
    [ITEMMENULOCATION_SHOP]                = gText_TheShop,
    [ITEMMENULOCATION_BERRY_TREE]          = gText_TheField,
    [ITEMMENULOCATION_BERRY_BLENDER_CRUSH] = gText_TheField,
    [ITEMMENULOCATION_ITEMPC]              = gText_ThePC,
    [ITEMMENULOCATION_FAVOR_LADY]          = gText_TheField,
    [ITEMMENULOCATION_QUIZ_LADY]           = gText_TheField,
    [ITEMMENULOCATION_APPRENTICE]          = gText_TheField,
    [ITEMMENULOCATION_WALLY]               = gText_TheBattle,
    [ITEMMENULOCATION_PCBOX]               = gText_ThePC,
    [ITEMMENULOCATION_BERRY_TREE_MULCH]    = gText_TheField,
};

const u8 *const gPyramidBagMenu_ReturnToStrings[] =
{
    [PYRAMIDBAG_LOC_FIELD]       = gText_TheField,
    [PYRAMIDBAG_LOC_BATTLE]      = gText_TheBattle,
    [PYRAMIDBAG_LOC_PARTY]       = gText_ThePokemonList,
    [PYRAMIDBAG_LOC_CHOOSE_TOSS] = gText_TheField
};

const u8 gText_ReturnToVar1[] = _("Return to\n{STR_VAR_1}.");

const u8 *const gPocketNamesStringsTable[] =
{
    [POCKET_ITEMS]      = COMPOUND_STRING("ITEMS"),
    [POCKET_POKE_BALLS] = COMPOUND_STRING("POKé BALLS"),
    [POCKET_TM_HM]      = COMPOUND_STRING("TMs & HMs"),
    [POCKET_BERRIES]    = COMPOUND_STRING("BERRIES"),
    [POCKET_KEY_ITEMS]  = COMPOUND_STRING("KEY ITEMS")
};

const u8 gText_NumberItem_TMBerry[] = _("{NO}{STR_VAR_1}{CLEAR 3}{STR_VAR_2}");
const u8 gText_NumberItem_HM[] = _("{CLEAR_TO 17}{STR_VAR_1}{CLEAR 5}{STR_VAR_2}");

const u8 gText_ShopBuy[] = _("BUY");
const u8 gText_ShopSell[] = _("SELL");
const u8 gText_ShopQuit[] = _("QUIT");
const u8 gText_ThatItemIsSoldOut[] = _("Desculpa, esse item esgotou.{PAUSE_UNTIL_PRESS}");
const u8 gText_SoldOut[] = _("SOLD OUT");
const u8 gText_InBagVar1[] = _("IN BAG: {STR_VAR_1}");
const u8 gText_QuitShopping[] = _("Quit shopping.");
const u8 gText_Var1CertainlyHowMany[] = _("{STR_VAR_1}? Claro. Quantos\n"
        "quer?");
const u8 gText_Var1CertainlyHowMany2[] = _("{STR_VAR_1}? Claro. Quantos\n"
        "quer?");
const u8 gText_Var1AndYouWantedVar2[] = _("{STR_VAR_1}? Você quer\n"
        "{STR_VAR_2}? Fica\l"
        "¥{STR_VAR_3}.");
const u8 gText_Var1IsItThatllBeVar2[] = _("{STR_VAR_1}, certo? Fica\n"
        "¥{STR_VAR_2}. Vai querer?");
const u8 gText_YouWantedVar1ThatllBeVar2[] = _("Você quer {STR_VAR_1}? Fica\n"
        "¥{STR_VAR_2}. Tudo bem?");
const u8 gText_HereYouGoThankYou[] = _("Aqui está! Muito obrigado.");
const u8 gText_ThankYouIllSendItHome[] = _("Obrigado! Vou mandar pro PC da sua\n"
        "casa.");
const u8 gText_ThanksIllSendItHome[] = _("Valeu! Vou mandar pro seu PC em\n"
        "casa.");
const u8 gText_YouDontHaveMoney[] = _("Você nao tem dinheiro suficiente.{PAUSE_UNTIL_PRESS}");
const u8 gText_NoMoreRoomForThis[] = _("Nao há mais espaço para esse item.{PAUSE_UNTIL_PRESS}");
const u8 gText_SpaceForVar1Full[] = _("O espaço para {STR_VAR_1} está\n"
        "cheio.{PAUSE_UNTIL_PRESS}");
const u8 gText_AnythingElseICanHelp[] = _("Posso ajudar com mais alguma\n"
        "coisa?");
const u8 gText_CanIHelpWithAnythingElse[] = _("Quer mais alguma coisa?");
const u8 gText_ThrowInPremierBall[] = _("Vai uma Premier Ball de brinde.{PAUSE_UNTIL_PRESS}");
const u8 gText_ThrowInPremierBalls[] = _("Vao {STR_VAR_1} Premier Balls\n"
        "de brinde.{PAUSE_UNTIL_PRESS}");
const u8 gText_CantBuyKeyItem[] = _("{STR_VAR_2}? Ah, nao. Nao\n"
        "posso comprar isso.{PAUSE_UNTIL_PRESS}");
const u8 gText_HowManyToSell[] = _("{STR_VAR_2}? Quantos quer\n"
        "vender?");
const u8 gText_ICanPayVar1[] = _("Posso pagar ¥{STR_VAR_1}. Tudo\n"
        "bem?");
const u8 gText_TurnedOverVar1ForVar2[] = _("Entregou {STR_VAR_2} e recebeu\n"
        "¥{STR_VAR_1}.");
const u8 gText_PokedollarVar1[] = _("¥{STR_VAR_1}");
const u8 gText_HP3[] = _("HP");
const u8 gText_SpAtk3[] = _("SP. ATK");
const u8 gText_SpDef3[] = _("SP. DEF");
const u8 gText_WontHaveEffect[] = _("Nao terá efeito.{PAUSE_UNTIL_PRESS}");
const u8 gText_NextFusionMon[] = _("Escolha o {PKMN} para a fusao.");
const u8 gText_CantBeUsedOnPkmn[] = _("Nao pode usar isso nesse Pokémon.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnCantSwitchOut[] = _("Nao pode trocar {STR_VAR_1}!{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnAlreadyInBattle[] = _("{STR_VAR_1} já está na\n"
        "batalha!{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnAlreadySelected[] = _("{STR_VAR_1} já foi escolhido.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnHasNoEnergy[] = _("{STR_VAR_1} nao tem mais\n"
        "energia para batalhar!{PAUSE_UNTIL_PRESS}");
const u8 gText_CantSwitchWithAlly[] = _("Nao pode trocar o Pokémon de\n"
        "{STR_VAR_1} por um dos seus!{PAUSE_UNTIL_PRESS}");
const u8 gText_EggCantBattle[] = _("Ovo nao pode batalhar!{PAUSE_UNTIL_PRESS}");
const u8 gText_CantUseUntilNewBadge[] = _("Precisa de uma nova insígnia para\n"
        "usar isso.{PAUSE_UNTIL_PRESS}");
const u8 gText_NoMoreThanVar1Pkmn[] = _("Só podem entrar até\n"
        "{STR_VAR_1} Pokémon.{PAUSE_UNTIL_PRESS}");
const u8 gText_SendMailToPC[] = _("Enviar a carta removida para seu\n"
        "PC?");
const u8 gText_MailSentToPC[] = _("A carta foi enviada para seu PC.{PAUSE_UNTIL_PRESS}");
const u8 gText_PCMailboxFull[] = _("A caixa de correio do PC está\n"
        "cheia.{PAUSE_UNTIL_PRESS}");
const u8 gText_MailMessageWillBeLost[] = _("Se tirar a carta, a mensagem será\n"
        "perdida. Tudo bem?");
const u8 gText_RemoveMailBeforeItem[] = _("Tire a carta antes de equipar um\n"
        "item.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnWasGivenItem[] = _("{STR_VAR_1} recebeu\n"
        "{STR_VAR_2} para segurar.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnAlreadyHoldingItemSwitch[] = _("{STR_VAR_1} já está segurando\n"
        "{STR_VAR_2}. Quer trocar os\l"
        "dois itens?");
const u8 gText_PkmnNotHolding[] = _("{STR_VAR_1} nao está segurando\n"
        "nada.{PAUSE_UNTIL_PRESS}");
const u8 gText_ReceivedItemFromPkmn[] = _("Recebeu {STR_VAR_2} de\n"
        "{STR_VAR_1}.{PAUSE_UNTIL_PRESS}");
const u8 gText_MailTakenFromPkmn[] = _("A carta foi retirada do Pokémon.{PAUSE_UNTIL_PRESS}");
const u8 gText_SwitchedPkmnItem[] = _("{STR_VAR_2} foi retirado e\n"
        "substituído por {STR_VAR_1}.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnHoldingItemCantHoldMail[] = _("Esse Pokémon está segurando um\n"
        "item. Nao pode segurar uma carta.{PAUSE_UNTIL_PRESS}");
const u8 gText_MailTransferredFromMailbox[] = _("A carta foi retirada da caixa de\n"
        "correio.{PAUSE_UNTIL_PRESS}");
const u8 gText_BagFullCouldNotRemoveItem[] = _("A bolsa está cheia. Nao foi\n"
        "possível retirar o item do\l"
        "Pokémon.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnLearnedMove3[] = _("{STR_VAR_1} aprendeu\n"
        "{STR_VAR_2}!");
const u8 gText_PkmnLearnedMove4[] = _("{STR_VAR_1} learned\n{STR_VAR_2}!{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnCantLearnMove[] = _("{STR_VAR_1} nao é compatível\n"
        "com {STR_VAR_2}. Nao pode\l"
        "aprender {STR_VAR_2}.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnNeedsToReplaceMove[] = _("{STR_VAR_1} quer aprender\n"
        "{STR_VAR_2}. Mas\l"
        "{STR_VAR_1} já sabe quatro\l"
        "golpes. Quer esquecer um para\l"
        "aprender {STR_VAR_2}?");
const u8 gText_StopLearningMove2[] = _("Desistir de ensinar\n"
        "{STR_VAR_2}?");
const u8 gText_MoveNotLearned[] = _("{STR_VAR_1} nao aprendeu\n"
        "{STR_VAR_2}.{PAUSE_UNTIL_PRESS}");
const u8 gText_WhichMoveToForget[] = _("Qual golpe quer esquecer?{PAUSE_UNTIL_PRESS}");
const u8 gText_12PoofForgotMove[] = _("1, {PAUSE 15}2, e{PAUSE 15}... {PAUSE 15}... {PAUSE 15}... {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}Puf!\n"
        "{STR_VAR_1} esqueceu como usar\l"
        "{STR_VAR_2}. E...{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnAlreadyKnows[] = _("{STR_VAR_1} já sabe\n"
        "{STR_VAR_2}.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnHPRestoredByVar2[] = _("{STR_VAR_1} recuperou\n"
        "{STR_VAR_2} pontos de HP.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnCuredOfPoison[] = _("O veneno de {STR_VAR_1} foi\n"
        "curado.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnCuredOfParalysis[] = _("A paralisia de {STR_VAR_1} foi\n"
        "curada.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnWokeUp2[] = _("{STR_VAR_1} woke up.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnBurnHealed[] = _("A queimadura de {STR_VAR_1} foi\n"
        "curada.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnFrostbiteHealed[] = _("A queimadura de frio de\n"
        "{STR_VAR_1} foi curada.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnThawedOut[] = _("{STR_VAR_1} descongelou.{PAUSE_UNTIL_PRESS}");
const u8 gText_PPWasRestored[] = _("PP was restored.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnRegainhedHealth[] = _("{STR_VAR_1} regained health.{PAUSE_UNTIL_PRESS}"); // Unused
const u8 gText_PkmnBecameHealthy[] = _("{STR_VAR_1} became healthy.{PAUSE_UNTIL_PRESS}");
const u8 gText_MovesPPIncreased[] = _("{STR_VAR_1}'s PP increased.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnElevatedToLvVar2[] = _("{STR_VAR_1} subiu para o nível\n"
        "{STR_VAR_2}.");
const u8 gText_PkmnGainedExp[] = _("{STR_VAR_1} ganhou\n"
        "{STR_VAR_2} pontos de\l"
        "experiência!{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnGainedExpAndElevatedToLvVar3[] = _("{STR_VAR_1} ganhou\n"
        "{STR_VAR_2} pontos de\l"
        "experiência e subiu para o nível\l"
        "{STR_VAR_3}!");
const u8 gText_PkmnBaseVar2StatIncreased[] = _("O atributo base {STR_VAR_2} de\n"
        "{STR_VAR_1} aumentou.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnFriendlyBaseVar2Fell[] = _("{STR_VAR_1} ficou mais próximo\n"
        "de você. Seu atributo base\l"
        "{STR_VAR_2} caiu!{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnAdoresBaseVar2Fell[] = _("{STR_VAR_1} adora você! Seu\n"
        "atributo base {STR_VAR_2} caiu!{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnFriendlyBaseVar2CantFall[] = _("{STR_VAR_1} ficou mais próximo\n"
        "de você. Seu atributo base\l"
        "{STR_VAR_2} nao pode cair!{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnSnappedOutOfConfusion[] = _("{STR_VAR_1} saiu da confusao.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnGotOverInfatuation[] = _("{STR_VAR_1} superou a paixao.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnTransformed[] = _("{STR_VAR_1} transformed!{PAUSE_UNTIL_PRESS}");
const u8 gText_ThrowAwayItem[] = _("Jogar fora {STR_VAR_1}?");
const u8 gText_ItemThrownAway[] = _("{STR_VAR_1} foi jogado fora.{PAUSE_UNTIL_PRESS}");
const u8 gText_TeachWhichPokemon2[] = _("Ensinar para qual Pokémon?"); // Unused
const u8 gText_ChoosePokemon[] = _("Choose a POKéMON.");
const u8 gText_MoveToWhere[] = _("Mover para onde?");
const u8 gText_TeachWhichPokemon[] = _("Ensinar para qual Pokémon?");
const u8 gText_UseOnWhichPokemon[] = _("Usar em qual Pokémon?");
const u8 gText_GiveToWhichPokemon[] = _("Dar para qual Pokémon?");
const u8 gText_DoWhatWithPokemon[] = _("Oque fazer com esse {PKMN}?");
const u8 gText_NothingToCut[] = _("Nao há nada para usar Cut.");
const u8 gText_CantSurfHere[] = _("Nao pode usar Surf aqui.");
const u8 gText_AlreadySurfing[] = _("You're already SURFING.");
const u8 gText_CantUseHere[] = _("Nao pode usar isso aqui.");
const u8 gText_RestoreWhichMove[] = _("Recuperar qual golpe?");
const u8 gText_BoostPP[] = _("Aumentar o PP de qual golpe?");
const u8 gText_DoWhatWithItem[] = _("Oque fazer com o item?");
const u8 gText_NoPokemonForBattle[] = _("Nenhum Pokémon pode batalhar!");
const u8 gText_ChoosePokemon2[] = _("Choose a POKéMON.");
const u8 gText_NotEnoughHp[] = _("Not enough HP…");
const u8 gText_PokemonAreNeeded[] = _("Sao necessários {STR_VAR_1}\n"
        "Pokémon.");
const u8 gText_PokemonCantBeSame[] = _("Os Pokémon nao podem ser iguais.");
const u8 gText_NoIdenticalHoldItems[] = _("Nao pode repetir itens equipados.");
const u8 gText_CurrentIsTooFast[] = _("A correnteza é forte demais!");
const u8 gText_DoWhatWithMail[] = _("Oque fazer com a carta?");
const u8 gText_ChoosePokemonCancel[] = _("Escolha um Pokémon ou cancele.");
const u8 gText_ChoosePokemonConfirm[] = _("Escolha os Pokémon e confirme.");
const u8 gText_SendWhichMonToPC[] = _("Enviar qual Pokémon para o PC?");
const u8 gText_MoveItemWhere[] = _("Mover o item para onde?");
const u8 gText_XsYAnd[] = _("{STR_VAR_1}'s {STR_VAR_2} and\n");
const u8 gText_XsYWereSwapped[] = _("{STR_VAR_2} de {STR_VAR_1}\n"
        "foram trocados!{PAUSE_UNTIL_PRESS}");
const u8 gText_EnjoyCycling[] = _("Vamos aproveitar o passeio de\n"
        "bicicleta!");
const u8 gText_InUseAlready_PM[] = _("Isso já está em uso.");
const u8 gText_AlreadyHoldingOne[] = _("{STR_VAR_1} já está segurando\n"
        "{STR_VAR_2}.");
const u8 gText_WhichAppliance[] = _("Pedir qual aparelho?");
const u8 gText_NoUse[] = _("No use.");
const u8 gText_Able[] = _("ABLE");
const u8 gText_First_PM[] = _("FIRST");
const u8 gText_Second_PM[] = _("SECOND");
const u8 gText_Third_PM[] = _("THIRD");
const u8 gText_Able2[] = _("ABLE");
const u8 gText_NotAble[] = _("NOT ABLE");
const u8 gText_Able3[] = _("ABLE!");
const u8 gText_NotAble2[] = _("NAO PODE!");
const u8 gText_Learned[] = _("LEARNED");
const u8 gText_Have[] = _("HAVE");
const u8 gText_DontHave[] = _("DON'T HAVE");
const u8 gText_Fourth[] = _("FOURTH");
const u8 gText_PkmnCantParticipate[] = _("Esse Pokémon nao pode participar.{PAUSE_UNTIL_PRESS}");
const u8 gText_CancelParticipation[] = _("Cancelar a participaçao?");
const u8 gText_CancelBattle[] = _("Cancelar a batalha?");
const u8 gText_ReturnToWaitingRoom[] = _("Voltar para a sala de espera?");
const u8 gText_CancelChallenge[] = _("Cancelar o desafio?");
const u8 gText_EscapeFromHere[] = _("Quer escapar daqui e voltar para\n"
        "{STR_VAR_1}?");
const u8 gText_ReturnToHealingSpot[] = _("Quer voltar ao último local de\n"
        "cura usado em {STR_VAR_1}?");
const u8 gText_PauseUntilPress[] = _("{PAUSE_UNTIL_PRESS}");
const u8 gJPText_AreYouSureYouWantToSpinTradeMon[] = _("Pode enviar {STR_VAR_1} para a\n"
        "troca giratória?");
ALIGNED(4) const u8 gText_OnlyPkmnForBattle[] = _("Esse é seu único Pokémon que pode\n"
        "batalhar.");
ALIGNED(4) const u8 gText_PkmnCantBeTradedNow[] = _("Esse Pokémon nao pode ser trocado\n"
        "agora.");
ALIGNED(4) const u8 gText_PkmnCantBeTraded[] = _("Esse Pokémon nao pode ser\n"
        "trocado.");
ALIGNED(4) const u8 gText_EggCantBeTradedNow[] = _("Nao pode trocar um ovo agora.");
ALIGNED(4) const u8 gText_OtherTrainersPkmnCantBeTraded[] = _("O Pokémon do outro treinador nao\n"
        "pode ser trocado agora.");
ALIGNED(4) const u8 gText_OtherTrainerCantAcceptPkmn[] = _("O outro treinador nao pode receber\n"
        "esse Pokémon agora.");
ALIGNED(4) const u8 gText_CantTradeWithTrainer[] = _("Nao pode trocar com esse treinador\n"
        "agora.");
ALIGNED(4) const u8 gText_NotPkmnOtherTrainerWants[] = _("Esse nao é o tipo de Pokémon que\n"
        "o outro treinador quer.");
ALIGNED(4) const u8 gText_ThatIsntAnEgg[] = _("Isso nao é um ovo.");
const u8 gText_Register[] = _("REGISTER");
const u8 gText_Attack3[] = _("ATTACK");
const u8 gText_Defense3[] = _("DEFENSE");
const u8 gText_SpAtk4[] = _("SP. ATK");
const u8 gText_SpDef4[] = _("SP. DEF");
const u8 gText_Speed2[] = _("SPEED");
const u8 gText_HP4[] = _("HP");
const u8 gText_EmptyString8[] = _(""); // Unused
const u8 gText_OTSlash[] = _("OT/");
const u8 gText_RentalPkmn[] = _("RENTAL POKéMON");
const u8 gText_TypeSlash[] = _("TYPE/");
const u8 gText_Power[] = _("POWER");
const u8 gText_Accuracy2[] = _("ACCURACY");
const u8 gText_Appeal[] = _("APPEAL");
const u8 gText_Jam[] = _("JAM");
const u8 gText_Status[] = _("STATUS");
const u8 gText_ExpPoints[] = _("EXP. POINTS");
const u8 gText_NextLv[] = _("NEXT LV.");
const u8 gText_RibbonsVar1[] = _("RIBBONS: {STR_VAR_1}");
const u8 gText_EmptyString5[] = _("");
const u8 gText_Events[] = _("EVENTS"); // Unused
const u8 gText_Switch[] = _("SWITCH");
const u8 gText_PkmnInfo[] = _("POKéMON INFO");
const u8 gText_PkmnSkills[] = _("POKéMON SKILLS");
const u8 gText_BattleMoves[] = _("BATTLE MOVES");
const u8 gText_ContestMoves[] = _("CONTEST MOVES");
const u8 gText_Info[] = _("INFO");
const u8 gText_EggWillTakeALongTime[] = _("Parece que esse ovo vai demorar\n"
        "bastante para chocar.");
const u8 gText_EggWillTakeSomeTime[] = _("Oque será que vai nascer? Ainda\n"
        "vai levar um tempo.");
const u8 gText_EggWillHatchSoon[] = _("Ele se mexe de vez em quando.\n"
        "Deve chocar logo.");
const u8 gText_EggAboutToHatch[] = _("Está fazendo barulho. Vai chocar a\n"
        "qualquer momento!");
const u8 gText_HMMovesCantBeForgotten2[] = _("Nao pode esquecer golpes de HM\n"
        "agora.");
const u8 gText_XNatureMetAtYZ[] = _("Natureza {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}. Encontrado no {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1}, em {DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}.");
const u8 gText_XNatureHatchedAtYZ[] = _("Natureza {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}. Chocou no {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1}, em {DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}.");
const u8 gText_XNatureObtainedInTrade[] = _("Natureza {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}. Recebido numa troca.");
const u8 gText_XNatureFatefulEncounter[] = _("Natureza {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}. Recebido num encontro especial no {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1}.");
const u8 gText_XNatureProbablyMetAt[] = _("Natureza {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}. Parece ter sido encontrado no {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1}, em {DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}.");
const u8 gText_XNature[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5} nature");
const u8 gText_XNatureMetSomewhereAt[] = _("Natureza {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}. Encontrado em algum lugar no {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1}.");
const u8 gText_XNatureHatchedSomewhereAt[] = _("Natureza {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}. Chocou em algum lugar no {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1}.");
const u8 gText_OddEggFoundByCouple[] = _("Um ovo Pokémon estranho\n"
        "encontrado pelo casal do Day Care.");
const u8 gText_PeculiarEggNicePlace[] = _("Um ovo Pokémon diferente recebido\n"
        "num lugar agradável.");
const u8 gText_PeculiarEggTrade[] = _("Um ovo Pokémon diferente recebido\n"
        "numa troca.");
const u8 gText_EggFromHotSprings[] = _("Um ovo Pokémon recebido nas águas\n"
        "quentes.");
const u8 gText_EggFromTraveler[] = _("Um ovo Pokémon estranho recebido\n"
        "de um viajante.");
const u8 gText_ApostropheSBase[] = _("'s BASE");
const u8 gText_OkayToDeleteFromRegistry[] = _("Pode excluir {STR_VAR_1} do\n"
        "registro?");
const u8 gText_RegisteredDataDeleted[] = _("Os dados registrados foram\n"
        "excluídos.{PAUSE_UNTIL_PRESS}");
const u8 gText_NoRegistry[] = _("Nao há registro.{PAUSE_UNTIL_PRESS}");
const u8 gText_DelRegist[] = _("DEL REGIST.");
const u8 gText_Var3Var1SlashVar2[] = _("{STR_VAR_3}{STR_VAR_1}/{STR_VAR_2}"); // Unused
const u8 gText_Decorate[] = _("DECORATE");
const u8 gText_PutAway[] = _("PUT AWAY");
const u8 gText_Toss2[] = _("TOSS");
const u8 gText_Color161Shadow161[] = _("{COLOR 161}{SHADOW 161}");
const u8 gText_PutOutSelectedDecorItem[] = _("Coloque o enfeite escolhido.");
const u8 gText_StoreChosenDecorInPC[] = _("Guarde o enfeite escolhido no PC.");
const u8 gText_ThrowAwayUnwantedDecors[] = _("Jogue fora os enfeites que nao\n"
        "quer.");
const u8 gText_NoDecorations[] = _("Nao há enfeites.{PAUSE_UNTIL_PRESS}");
const u8 gText_Desk[] = _("DESK");
const u8 gText_Chair[] = _("CHAIR");
const u8 gText_Plant[] = _("PLANT");
const u8 gText_Ornament[] = _("ORNAMENT");
const u8 gText_Mat[] = _("MAT");
const u8 gText_Poster[] = _("POSTER");
const u8 gText_Doll[] = _("DOLL");
const u8 gText_Cushion[] = _("CUSHION");
const u8 gText_Gold[] = _("GOLD");
const u8 gText_Silver[] = _("SILVER");
const u8 gText_PlaceItHere[] = _("Colocar aqui?");
const u8 gText_CantBePlacedHere[] = _("Nao pode colocar aqui.");
const u8 gText_CancelDecorating[] = _("Cancelar a decoraçao?");
const u8 gText_InUseAlready[] = _("Isso já está em uso.");
const u8 gText_NoMoreDecorations[] = _("Nao pode colocar mais enfeites. O\n"
        "limite é {STR_VAR_1}.");
const u8 gText_NoMoreDecorations2[] = _("Nao pode colocar mais enfeites. O\n"
        "limite é {STR_VAR_1}.");
const u8 gText_MustBePlacedOnDesk[] = _("Nao pode colocar aqui. Precisa\n"
        "ficar em cima de uma mesa ou algo\l"
        "parecido."); // Unused
const u8 gText_CantPlaceInRoom[] = _("Nao pode colocar esse enfeite no\n"
        "seu quarto.");
const u8 gText_CantThrowAwayInUse[] = _("Esse enfeite está em uso. Nao\n"
        "pode jogar fora.");
const u8 gText_DecorationWillBeDiscarded[] = _("Vai jogar fora {STR_VAR_1}.\n"
        "Tudo bem?");
const u8 gText_DecorationThrownAway[] = _("O enfeite foi jogado fora.");
const u8 gText_StopPuttingAwayDecorations[] = _("Parar de guardar enfeites?");
const u8 gText_NoDecorationHere[] = _("Nao há nenhum enfeite aqui.");
const u8 gText_ReturnDecorationToPC[] = _("Devolver esse enfeite ao PC?");
const u8 gText_DecorationReturnedToPC[] = _("O enfeite foi devolvido ao PC.");
const u8 gText_NoDecorationsInUse[] = _("Nao há enfeites em uso.{PAUSE_UNTIL_PRESS}");
const u8 gText_NoItems[] = _("Nao há itens.{PAUSE_UNTIL_PRESS}");
const u8 gText_NoMailHere[] = _("Nao há cartas aqui.{PAUSE_UNTIL_PRESS}");
const u8 gText_WhatToDoWithVar1sMail[] = _("Oque quer fazer com a carta de\n"
        "{STR_VAR_1}?");
const u8 gText_MessageWillBeLost[] = _("A mensagem será perdida. Tudo bem?");
const u8 gText_BagIsFull[] = _("A bolsa está cheia.{PAUSE_UNTIL_PRESS}");
const u8 gText_MailToBagMessageErased[] = _("A carta voltou para a bolsa com a\n"
        "mensagem apagada.{PAUSE_UNTIL_PRESS}");
const u8 gText_Dad[] = _("DAD");
const u8 gText_Mom[] = _("MOM");
const u8 gText_CoolnessContest[] = _("COOLNESS CONTEST");
const u8 gText_BeautyContest[] = _("BEAUTY CONTEST");
const u8 gText_CutenessContest[] = _("CUTENESS CONTEST");
const u8 gText_SmartnessContest[] = _("SMARTNESS CONTEST");
const u8 gText_ToughnessContest[] = _("TOUGHNESS CONTEST");
const u8 gText_Information[] = _("INFORMATION");
const u8 gText_Yes[] = _("Sim");
const u8 gText_No[] = _("Nao");
const u8 gText_Lv50[] = _("LV. 50");
const u8 gText_OpenLevel[] = _("OPEN LEVEL");
const u8 gText_BattleFrontier[] = _("BATTLE FRONTIER");
const u8 gText_Cool[] = _("COOL");
const u8 gText_Beauty[] = _("BEAUTY");
const u8 gText_Cute[] = _("CUTE");
const u8 gText_Smart[] = _("SMART");
const u8 gText_Tough[] = _("TOUGH");
const u8 gText_Normal[] = _("NORMAL");
const u8 gText_Super[] = _("SUPER");
const u8 gText_Hyper[] = _("HYPER");
const u8 gText_Master[] = _("MASTER");
const u8 gText_SomeonesPC[] = _("SOMEONE'S PC");
const u8 gText_LanettesPC[] = _("LANETTE'S PC");
const u8 gText_BillsPc[] = _("BILL'S PC");
const u8 gText_PlayersPC[] = _("{PLAYER}'s PC");
const u8 gText_HallOfFame[] = _("HALL OF FAME");
const u8 gText_LogOff[] = _("LOG OFF");
const u8 gText_Single2[] = _("SINGLE");
const u8 gText_Double2[] = _("DOUBLE");
const u8 gText_Multi[] = _("MULTI");
const u8 gText_MultiLink[] = _("MULTI-LINK");
const u8 gText_MenuOptionPokedex[] = _("POKéDEX");
const u8 gText_MenuOptionPokemon[] = _("POKéMON");
const u8 gText_MenuOptionBag[] = _("BAG");
const u8 gText_MenuOptionPokenav[] = _("POKéNAV");
const u8 gText_MenuOptionSave[] = _("SAVE");
const u8 gText_MenuOptionOption[] = _("OPTION");
const u8 gText_MenuOptionExit[] = _("EXIT");
const u8 gText_SouthernIsland[] = _("SOUTHERN ISLAND");
const u8 gText_BirthIsland[] = _("BIRTH ISLAND");
const u8 gText_FarawayIsland[] = _("FARAWAY ISLAND");
const u8 gText_NavelRock[] = _("NAVEL ROCK");
const u8 gText_NormalTagMatch[] = _("NORMAL TAG MATCH");
const u8 gText_VarietyTagMatch[] = _("VARIETY TAG MATCH");
const u8 gText_UniqueTagMatch[] = _("UNIQUE TAG MATCH");
const u8 gText_ExpertTagMatch[] = _("EXPERT TAG MATCH");
const u8 gText_BattleBasics[] = _("BATTLE BASICS");
const u8 gText_PokemonNature[] = _("POKéMON NATURE");
const u8 gText_PokemonMoves[] = _("POKéMON MOVES");
const u8 gText_Underpowered[] = _("UNDERPOWERED");
const u8 gText_WhenInDanger[] = _("WHEN IN DANGER");
const u8 gText_BattlePokemon[] = _("BATTLE POKéMON");
const u8 gText_BattleTrainers[] = _("BATTLE TRAINERS");
const u8 gText_1F[] = _("1F");
const u8 gText_2F[] = _("2F");
const u8 gText_3F[] = _("3F");
const u8 gText_4F[] = _("4F");
const u8 gText_5F[] = _("5F");
const u8 gText_6F[] = _("6F");
const u8 gText_7F[] = _("7F");
const u8 gText_8F[] = _("8F");
const u8 gText_9F[] = _("9F");
const u8 gText_10F[] = _("10F");
const u8 gText_11F[] = _("11F");
const u8 gText_B1F[] = _("B1F");
const u8 gText_B2F[] = _("B2F");
const u8 gText_B3F[] = _("B3F");
const u8 gText_B4F[] = _("B4F");
const u8 gText_Rooftop[] = _("ROOFTOP");
const u8 gText_ElevatorNowOn[] = _("Now on:");
const u8 gText_BP[] = _("BP");
const u8 gText_RankingHall[] = _("RANKING HALL");
const u8 gText_ExchangeService[] = _("EXCHANGE SERVICE");
const u8 gText_SlateportCity[] = _("SLATEPORT CITY");
const u8 gText_Exit[] = _("Sair");
const u8 gText_YourPartysFull[] = _("Your party's full!{PAUSE_UNTIL_PRESS}");
const u8 gText_InParty[] = _("IN PARTY");
const u8 gText_PokemonMaleLv[] = _("{DYNAMIC 0}{BACKGROUND WHITE}{TEXT_COLORS LIGHT_RED GREEN WHITE}♂{BACKGROUND WHITE}{TEXT_COLORS DARK_GRAY LIGHT_GRAY WHITE}/{LV}{DYNAMIC 1}"); // Unused
const u8 gText_PokemonFemaleLv[] = _("{DYNAMIC 0}{BACKGROUND WHITE}{TEXT_COLORS LIGHT_GREEN BLUE WHITE}♀{BACKGROUND WHITE}{TEXT_COLORS DARK_GRAY LIGHT_GRAY WHITE}/{LV}{DYNAMIC 1}"); // Unused
const u8 gText_PokemonNoGenderLv[] = _("{DYNAMIC 0}/{LV}{DYNAMIC 1}"); // Unused
const u8 gText_PokemonMaleLv2[] = _("{DYNAMIC 0}{BACKGROUND WHITE}{TEXT_COLORS LIGHT_RED GREEN WHITE}♂{BACKGROUND WHITE}{TEXT_COLORS DARK_GRAY LIGHT_GRAY WHITE}/{LV}{DYNAMIC 1}{DYNAMIC 2}"); // Unused
const u8 gText_PokemonFemaleLv2[] = _("{DYNAMIC 0}{BACKGROUND WHITE}{TEXT_COLORS LIGHT_GREEN BLUE WHITE}♀{BACKGROUND WHITE}{TEXT_COLORS DARK_GRAY LIGHT_GRAY WHITE}/{LV}{DYNAMIC 1}{DYNAMIC 2}"); // Unused
const u8 gText_PokemonNoGenderLv2[] = _("{DYNAMIC 0}/{LV}{DYNAMIC 1}{DYNAMIC 2}"); // Unused
const u8 gText_CombineFourWordsOrPhrases[] = _("Combine four words or phrases");
const u8 gText_AndMakeYourProfile[] = _("e crie seu perfil.");
const u8 gText_CombineSixWordsOrPhrases[] = _("Combine six words or phrases");
const u8 gText_AndMakeAMessage[] = _("e escreva uma mensagem.");
const u8 gText_FindWordsThatDescribeYour[] = _("Find words that describe your");
const u8 gText_FeelingsRightNow[] = _("feelings right now.");
const u8 gText_WithFourPhrases[] = _("With four phrases,"); // Unused
const u8 gText_CombineNineWordsOrPhrases[] = _("Combine nine words or phrases");
const u8 gText_AndMakeAMessage2[] = _("e escreva uma mensagem.");
const u8 gText_ChangeJustOneWordOrPhrase[] = _("Change just one word or phrase");
const u8 gText_AndImproveTheBardsSong[] = _("e melhore a música do Bard.");
const u8 gText_YourProfile[] = _("Your profile");
const u8 gText_YourFeelingAtTheBattlesStart[] = _("Your feeling at the battle's start");
const u8 gText_WhatYouSayIfYouWin[] = _("What you say if you win a battle");
const u8 gText_WhatYouSayIfYouLose[] = _("What you say if you lose a battle");
const u8 gText_TheAnswer[] = _("The answer");
const u8 gText_TheMailMessage[] = _("The MAIL message");
const u8 gText_TheMailSalutation[] = _("The MAIL salutation"); // Unused
const u8 gText_TheBardsSong2[] = _("The new song");
const u8 gText_CombineTwoWordsOrPhrases[] = _("Combine two words or phrases");
const u8 gText_AndMakeATrendySaying[] = _("e crie uma expressao da moda.");
const u8 gText_TheTrendySaying[] = _("The trendy saying");
const u8 gText_IsAsShownOkay[] = _("ficou assim. Tudo bem?");
const u8 gText_CombineTwoWordsOrPhrases2[] = _("Combine two words or phrases");
const u8 gText_ToTeachHerAGoodSaying[] = _("para ensinar uma boa expressao a\n"
        "ela.");
const u8 gText_FindWordsWhichFit[] = _("Find words which fit");
const u8 gText_TheTrainersImage[] = _("the TRAINER's image.");
const u8 gText_TheImage[] = _("The image:");
const u8 gText_OutOfTheListedChoices[] = _("Out of the listed choices,");
const u8 gText_SelectTheAnswerToTheQuiz[] = _("escolha a resposta do quiz!");
const u8 gText_AndCreateAQuiz[] = _("e crie um quiz!");
const u8 gText_PickAWordOrPhraseAnd[] = _("Pick a word or phrase and");
const u8 gText_SetTheQuizAnswer[] = _("defina a resposta do quiz.");
const u8 gText_TheAnswerColon[] = _("The answer:");
const u8 gText_TheQuizColon[] = _("The quiz:"); // Unused
const u8 gText_ApprenticePhrase[] = _("Apprentice's phrase:");
const u8 gText_QuitEditing[] = _("Parar de editar?");
const u8 gText_StopGivingPkmnMail[] = _("Desistir de dar a carta ao\n"
        "Pokémon?");
const u8 gText_AndFillOutTheQuestionnaire[] = _("e responda ao questionário.");
const u8 gText_LetsReplyToTheInterview[] = _("Vamos responder à entrevista!");
const u8 gText_AllTextBeingEditedWill[] = _("All the text being edited will");
const u8 gText_BeDeletedThatOkay[] = _("será excluído. Tudo bem?");
const u8 gText_QuitEditing2[] = _("Parar de editar?"); // Unused
const u8 gText_EditedTextWillNotBeSaved[] = _("O texto editado nao será salvo."); // Unused
const u8 gText_IsThatOkay[] = _("Tudo bem?"); // Unused
const u8 gText_PleaseEnterPhraseOrWord[] = _("Digite uma frase ou palavra."); // Unused
const u8 gText_EntireTextCantBeDeleted[] = _("Nao pode apagar o texto inteiro.");
const u8 gText_OnlyOnePhrase[] = _("Só pode mudar uma frase.");
const u8 gText_OriginalSongWillBeUsed[] = _("A música original será usada.");
const u8 gText_ThatsTrendyAlready[] = _("Isso já está na moda!"); // Unused
const u8 gText_CombineTwoWordsOrPhrases3[] = _("Junte duas palavras ou frases.");
const u8 gText_QuitGivingInfo[] = _("Parar de dar informaçoes?"); // Unused
const u8 gText_StopGivingPkmnMail2[] = _("Desistir de dar a carta ao\n"
        "Pokémon?"); // Unused
const u8 gText_CreateAQuiz2[] = _("Crie um quiz!"); // Unused
const u8 gText_SetTheAnswer[] = _("Defina a resposta!"); // Unused
const u8 gText_CancelSelection[] = _("Cancelar a escolha?"); // Unused
const u8 gText_Profile[] = _("PROFILE");
const u8 gText_AtTheBattlesStart[] = _("No começo da batalha:");
const u8 gText_UponWinningABattle[] = _("Ao vencer uma batalha:");
const u8 gText_UponLosingABattle[] = _("Ao perder uma batalha:");
const u8 gText_TheBardsSong[] = _("The BARD's Song");
const u8 gText_WhatsHipAndHappening[] = _("Oque está na moda?");
const u8 gText_Interview[] = _("Interview");
const u8 gText_GoodSaying[] = _("Good saying");
const u8 gText_FansQuestion[] = _("Fan's question");
const u8 gJPText_WhatIsTheQuizAnswer[] = _("クイズの こたえは？"); // Unused
const u8 gText_ApprenticesPhrase[] = _("Apprentice's phrase");
const u8 gText_Questionnaire[] = _("QUESTIONNAIRE");
const u8 gText_YouCannotQuitHere[] = _("Nao pode sair agora.");
const u8 gText_SectionMustBeCompleted[] = _("Precisa completar essa parte.");
const u8 gText_F700sQuiz[] = _("{DYNAMIC 0}'s quiz");
const u8 gText_Lady[] = _("Lady");
const u8 gText_AfterYouHaveReadTheQuiz[] = _("After you have read the quiz");
const u8 gText_QuestionPressTheAButton[] = _("pergunta, aperte o botao A.");
const u8 gText_TheQuizAnswerIs[] = _("Qual é a resposta do quiz?");
const u8 gText_LikeToQuitQuiz[] = _("Would you like to quit this quiz");
const u8 gText_ChallengeQuestionMark[] = _("challenge?");
const u8 gText_IsThisQuizOK[] = _("Esse quiz está bom?");
const u8 gText_CreateAQuiz[] = _("Crie um quiz!");
const u8 gText_SelectTheAnswer[] = _("Escolha a resposta!");
const u8 gText_LyricsCantBeDeleted[] = _("Nao pode apagar a letra da música.");
const u8 gText_PokemonLeague[] = _("POKéMON LEAGUE");
const u8 gText_PokemonCenter[] = _("POKéMON CENTER");
const u8 gText_Coolness[] = _("Coolness ");
const u8 gText_Beauty3[] = _("Beauty ");
const u8 gText_Cuteness[] = _("Cuteness ");
const u8 gText_Smartness[] = _("Smartness ");
const u8 gText_Toughness[] = _("Toughness ");
const u8 gText_SaveFailedCheckingBackup[] = _("Falha ao salvar. Conferindo a\n"
        "memória de salvamento... Aguarde.\l"
        "{COLOR RED}“Tempo necessário: cerca de 1\l"
        "minuto”");
const u8 gText_BackupMemoryDamaged[] = _("A memória de salvamento está\n"
        "danificada ou a bateria interna\l"
        "acabou. Você ainda pode jogar, mas\l"
        "nao pode salvar.");
const u8 gText_GamePlayCannotBeContinued[] = _("{COLOR RED}“Nao é possível continuar.\n"
        "Voltando para a tela inicial...”");
const u8 gText_CheckCompleted[] = _("Conferência concluída. Tentando\n"
        "salvar novamente. Aguarde.");
const u8 gText_SaveCompleteGameCannotContinue[] = _("Jogo salvo. {COLOR RED}“Nao é possível\n"
        "continuar. Voltando para a tela\l"
        "inicial.”");
const u8 gText_SaveCompletePressA[] = _("Jogo salvo. {COLOR RED}“Aperte o botao A.”");
const u8 gText_Ferry[] = _("FERRY");
const u8 gText_SecretBase[] = _("SECRET BASE");
const u8 gText_Hideout[] = _("HIDEOUT");
const u8 gText_ResetRTCConfirmCancel[] = _("Reiniciar o relógio? A: Confirmar,\n"
        "B: Cancelar");
const u8 gText_PresentTime[] = _("Present time in game");
const u8 gText_PreviousTime[] = _("Previous time in game");
const u8 gText_PleaseResetTime[] = _("Acerte a hora novamente.");
const u8 gText_ClockHasBeenReset[] = _("O relógio foi reiniciado. Os dados\n"
        "serao salvos. Aguarde.");
const u8 gText_SaveCompleted[] = _("Save completed.");
const u8 gText_SaveFailed[] = _("Save failed…");
const u8 gText_NoSaveFileCantSetTime[] = _("Nao há jogo salvo, entao nao pode\n"
        "acertar a hora.");
const u8 gText_InGameClockUsable[] = _("O sistema de ajuste do relógio foi\n"
        "liberado.");
const u8 gText_Spicy2[] = _("spicy");
const u8 gText_Dry2[] = _("dry");
const u8 gText_Sweet2[] = _("sweet");
const u8 gText_Bitter2[] = _("bitter");
const u8 gText_Sour2[] = _("sour");
const u8 gText_Single[] = _("SINGLE");
const u8 gText_Double[] = _("DOUBLE");
const u8 gText_Knockout[] = _("KNOCKOUT");
const u8 gText_Mixed[] = _("MIXED");
const u8 gText_First[] = _("first");
const u8 gText_Second[] = _("second");
const u8 gText_Third[] = _("third");
#if OW_POISON_DAMAGE < GEN_4
const u8 gText_PkmnFainted_FldPsn[] = _("{STR_VAR_1} fainted…\p\n");
#else
const u8 gText_PkmnFainted_FldPsn[] = _("{STR_VAR_1} resistiu ao\n"
        "envenenamento. O veneno passou!\p");
#endif
const u8 gText_Marco[] = _("MARCO");
const u8 gText_TrainerCardName[] = _("NAME: ");
const u8 gText_TrainerCardIDNo[] = _("IDNo.");
const u8 gText_TrainerCardMoney[] = _("MONEY");
const u8 gText_PokeDollar[] = _("¥"); // Unused
const u8 gText_TrainerCardPokedex[] = _("POKéDEX");
const u8 gText_EmptyString6[] = _("");
const u8 gText_Colon2[] = _(":");
const u8 gText_Points[] = _(" points"); // Unused
const u8 gText_TrainerCardTime[] = _("TIME");
const u8 gJPText_BattlePoints[] = _("ゲ-ムポイント"); // Unused. Name presumed, translation is Game Points
const u8 gText_Var1sTrainerCard[] = _("{STR_VAR_1}'s TRAINER CARD");
const u8 gText_HallOfFameDebut[] = _("HALL OF FAME DEBUT  ");
const u8 gText_LinkBattles[] = _("LINK BATTLES");
const u8 gText_LinkCableBattles[] = _("LINK CABLE BATTLES");
const u8 gText_WinsLosses[] = _("V:{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} D:{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_2}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}");
const u8 gText_PokemonTrades[] = _("POKéMON TRADES");
const u8 gText_UnionTradesAndBattles[] = _("UNION TRADES & BATTLES");
const u8 gText_BerryCrush[] = _("BERRY CRUSH");
const u8 gText_WaitingTrainerFinishReading[] = _("Esperando o outro treinador\n"
        "terminar de ler seu cartao.");
const u8 gText_PokeblocksWithFriends[] = _("{POKEBLOCK}S W/FRIENDS");
const u8 gText_NumPokeblocks[] = _("{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}");
const u8 gText_WonContestsWFriends[] = _("WON CONTESTS W/FRIENDS");
const u8 gText_BattlePtsWon[] = _("BATTLE POINTS WON");
const u8 gText_NumBP[] = _("{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}BP");
const u8 gText_BattleTower[] = _("BATTLE TOWER");
const u8 gText_WinsStraight[] = _("V/{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}\n"
        "SEGUIDAS/{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_2}");
const u8 gText_BattleTower2[] = _("BATTLE TOWER");
const u8 gText_BattleDome[] = _("BATTLE DOME");
const u8 gText_BattlePalace[] = _("BATTLE PALACE");
const u8 gText_BattleFactory[] = _("BATTLE FACTORY");
const u8 gText_BattleArena[] = _("BATTLE ARENA");
const u8 gText_BattlePike[] = _("BATTLE PIKE");
const u8 gText_BattlePyramid[] = _("BATTLE PYRAMID");

ALIGNED(4) const u8 gText_FacilitySingle[] = _("{STR_VAR_1} SINGLE");
ALIGNED(4) const u8 gText_FacilityDouble[] = _("{STR_VAR_1} DOUBLE");
ALIGNED(4) const u8 gText_FacilityMulti[] = _("{STR_VAR_1} MULTI");
ALIGNED(4) const u8 gText_FacilityLink[] = _("{STR_VAR_1} LINK");
ALIGNED(4) const u8 gText_Facility[] = _("{STR_VAR_1}");

const u8 gText_Give[] = _("Give");
const u8 gText_NoNeed[] = _("No need");
const u8 gText_AnnouncingResults[] = _("Anunciando os resultados!");
const u8 gText_PreliminaryResults[] = _("Resultados da primeira avaliaçao!");
const u8 gText_Round2Results[] = _("Resultados da segunda avaliaçao!");
const u8 gText_ContestantsMonWon[] = _("O {STR_VAR_2} de\n"
        "{STR_VAR_1} venceu!");
const u8 gText_CommunicationStandby[] = _("Communication standby…");
const u8 gText_ColorDarkGray[] = _("{COLOR DARK_GRAY}");
const u8 gText_ColorDynamic6WhiteDynamic5[] = _("{BACKGROUND WHITE}{TEXT_COLORS DYNAMIC_COLOR6 DYNAMIC_COLOR5 WHITE}"); // Unused
const u8 gText_HealthboxNickname[] = _("{BACKGROUND DARK_GRAY}{ACCENT DARK_GRAY}");
const u8 gText_EmptySpace2[] = _(" "); // Unused
const u8 gText_HealthboxGender_Male[] = _("{COLOR DYNAMIC_COLOR2}♂");
const u8 gText_HealthboxGender_Female[] = _("{COLOR DYNAMIC_COLOR1}♀");
const u8 gText_HealthboxGender_None[] = _("{COLOR DYNAMIC_COLOR2}");
const u8 gText_Upper[] = _("UPPER");
const u8 gText_Lower[] = _("lower");
const u8 gText_Others[] = _("OTHERS");
const u8 gText_Symbols[] = _("SYMBOLS");
const u8 gText_Register2[] = _("REGISTER");
const u8 gText_Exit2[] = _("Sair");
const u8 gText_QuitChatting[] = _("Sair da conversa?");
const u8 gText_RegisterTextWhere[] = _("Registrar o texto onde?");
const u8 gText_RegisterTextHere[] = _("Registrar o texto aqui?");
const u8 gText_InputText[] = _("Input text.");
const u8 gText_F700JoinedChat[] = _("{DYNAMIC 0} entrou na\n"
        "conversa!");
const u8 gText_F700LeftChat[] = _("{DYNAMIC 0} saiu da conversa.");
const u8 gJPText_PlayersXPokemon[] = _("{DYNAMIC 0}の{DYNAMIC 1}ひきめ:"); // Unused
const u8 gJPText_PlayersXPokmonDoesNotExist[] = _("{DYNAMIC 0}の{DYNAMIC 1}ひきめは いません"); // Unused
const u8 gText_ExitingChat[] = _("Exiting the chat…");
const u8 gText_LeaderLeftEndingChat[] = _("O líder, {DYNAMIC 0}, saiu e\n"
        "encerrou a conversa.");
const u8 gText_RegisteredTextChangedOKToSave[] = _("O texto registrado mudou. Pode\n"
        "salvar o jogo?");
const u8 gText_AlreadySavedFile_Chat[] = _("Já existe um jogo salvo. Pode\n"
        "substituir?");
const u8 gText_SavingDontTurnOff_Chat[] = _("SALVANDO... NAO DESLIGUE O JOGO.");
const u8 gText_PlayerSavedGame_Chat[] = _("{DYNAMIC 0} salvou o jogo.");
const u8 gText_IfLeaderLeavesChatEnds[] = _("Se o líder sair, a conversa vai\n"
        "acabar. Tudo bem?");
const u8 gText_Hello[] = _("HELLO");
const u8 gText_Pokemon2[] = _("POKéMON");
const u8 gText_Trade[] = _("TRADE");
const u8 gText_Battle[] = _("BATTLE");
const u8 gText_Lets[] = _("LET'S");
const u8 gText_Ok[] = _("OK!");
const u8 gText_Sorry[] = _("SORRY");
const u8 gText_YaySmileEmoji[] = _("YAY{EMOJI_BIGSMILE}");
const u8 gText_ThankYou[] = _("THANK YOU");
const u8 gText_ByeBye[] = _("BYE-BYE!");
const u8 gText_HatchedFromEgg[] = _("{STR_VAR_1} saiu do ovo!");
const u8 gText_NicknameHatchPrompt[] = _("Quer dar um apelido ao\n"
        "{STR_VAR_1} que acabou de\l"
        "nascer?");
ALIGNED(4) const u8 gText_ReadyPickBerry[] = _("Pronto para o Berry Crush? Escolha\n"
        "uma Berry.\p");
ALIGNED(4) const u8 gText_WaitForAllChooseBerry[] = _("Espere todos escolherem uma Berry.");
ALIGNED(4) const u8 gText_EndedWithXUnitsPowder[] = _("{PAUSE_MUSIC}{PLAY_BGM MUS_LEVEL_UP}Você conseguiu {STR_VAR_1}\n"
        "unidades de Berry Powder bem\l"
        "fininho.{RESUME_MUSIC} Agora tem {STR_VAR_2}\l"
        "unidades de Berry Powder.\p");
ALIGNED(4) const u8 gText_RecordingGameResults[] = _("Salvando os resultados do jogo.\n"
        "Aguarde.");
ALIGNED(4) const u8 gText_PlayBerryCrushAgain[] = _("Quer jogar Berry Crush de novo?");
ALIGNED(4) const u8 gText_YouHaveNoBerries[] = _("Você nao tem Berries. O jogo será\n"
        "cancelado.");
ALIGNED(4) const u8 gText_MemberDroppedOut[] = _("Um participante saiu. O jogo será\n"
        "cancelado.");
ALIGNED(4) const u8 gText_TimesUpNoGoodPowder[] = _("O tempo acabou. Nao foi possível\n"
        "fazer um bom Berry Powder...\p");
ALIGNED(4) const u8 gText_CommunicationStandby2[] = _("Communication standby…");
ALIGNED(4) const u8 gText_1DotBlueF700[] = _("1. {COLOR BLUE}{SHADOW LIGHT_BLUE}{DYNAMIC 0}");
ALIGNED(4) const u8 gText_1DotF700[] = _("1. {DYNAMIC 0}");
ALIGNED(4) const u8 gText_SpaceTimes2[] = _(" time(s)");
ALIGNED(4) const u8 gText_XDotY[] = _("{STR_VAR_1}.{STR_VAR_2}");
ALIGNED(4) const u8 gText_Var1Berry[] = _("{STR_VAR_1} BERRY");
ALIGNED(4) const u8 gText_TimeColon[] = _("Time:");
ALIGNED(4) const u8 gText_PressingSpeed[] = _("Pressing Speed:");
ALIGNED(4) const u8 gText_Silkiness[] = _("Silkiness:");
ALIGNED(4) const u8 gText_StrVar1[] = _("{STR_VAR_1}");
ALIGNED(4) const u8 gText_SpaceMin[] = _(" min. ");
ALIGNED(4) const u8 gText_XDotY2[] = _("{STR_VAR_1}.{STR_VAR_2}");
ALIGNED(4) const u8 gText_SpaceSec[] = _(" sec.");
ALIGNED(4) const u8 gText_XDotY3[] = _("{STR_VAR_1}.{STR_VAR_2}");
ALIGNED(4) const u8 gText_TimesPerSec[] = _(" Times/sec.");
ALIGNED(4) const u8 gText_Var1Percent[] = _("{STR_VAR_1}%");
ALIGNED(4) const u8 gText_PressesRankings[] = _("Classificaçao por apertos");
ALIGNED(4) const u8 gText_CrushingResults[] = _("Crushing Results");
ALIGNED(4) const u8 gText_NeatnessRankings[] = _("Neatness Rankings");
ALIGNED(4) const u8 gText_CoopRankings[] = _("Cooperative Rankings");
ALIGNED(4) const u8 gText_PressingPowerRankings[] = _("Pressing-Power Rankings");
const u8 gText_BerryCrush2[] = _("BERRY CRUSH");
const u8 gText_PressingSpeedRankings[] = _("Pressing-Speed Rankings");
const u8 gText_Var1Players[] = _("{STR_VAR_1} PLAYERS");
const u8 gText_SymbolsEarned[] = _("Symbols Earned");
const u8 gText_BattleRecord[] = _("Battle Record");
const u8 gText_BattlePoints[] = _("Battle Points");
const u8 gText_UnusedCancel[] = _("CANCEL"); // Unused
const u8 gText_EmptyString7[] = _("");
const u8 gText_CheckFrontierMap[] = _("Ver o mapa da Battle Frontier.");
const u8 gText_CheckTrainerCard[] = _("Check TRAINER CARD.");
const u8 gText_ViewRecordedBattle[] = _("View recorded battle.");
const u8 gText_PutAwayFrontierPass[] = _("Guardar o Frontier Pass.");
const u8 gText_CurrentBattlePoints[] = _("Seus Battle Points atuais.");
const u8 gText_CollectedSymbols[] = _("Your collected Symbols.");
const u8 gText_BattleTowerAbilitySymbol[] = _("Battle Tower - Ability Symbol");
const u8 gText_BattleDomeTacticsSymbol[] = _("Battle Dome - Tactics Symbol");
const u8 gText_BattlePalaceSpiritsSymbol[] = _("Battle Palace - Spirits Symbol");
const u8 gText_BattleArenaGutsSymbol[] = _("Battle Arena - Guts Symbol");
const u8 gText_BattleFactoryKnowledgeSymbol[] = _("Battle Factory - Knowledge Symbol");
const u8 gText_BattlePikeLuckSymbol[] = _("Battle Pike - Luck Symbol");
const u8 gText_BattlePyramidBraveSymbol[] = _("Battle Pyramid - Brave Symbol");
const u8 gText_ThereIsNoBattleRecord[] = _("Nao há batalha gravada.");
const u8 gText_BattleTower3[] = _("BATTLE TOWER");
const u8 gText_BattleDome2[] = _("BATTLE DOME");
const u8 gText_BattlePalace2[] = _("BATTLE PALACE");
const u8 gText_BattleArena2[] = _("BATTLE ARENA");
const u8 gText_BattleFactory2[] = _("BATTLE FACTORY");
const u8 gText_BattlePike2[] = _("BATTLE PIKE");
const u8 gText_BattlePyramid2[] = _("BATTLE PYRAMID");
const u8 gText_BattleTowerDesc[] = _("Vença os adversários e chegue ao\n"
        "topo! Sua habilidade será testada.");
const u8 gText_BattleDomeDesc[] = _("Continue vencendo no torneio! Sua\n"
        "estratégia será testada.");
const u8 gText_BattlePalaceDesc[] = _("Veja seus Pokémon batalharem! Seu\n"
        "espírito será testado.");
const u8 gText_BattleArenaDesc[] = _("Vença com seu time de Pokémon!\n"
        "Sua firmeza será testada.");
const u8 gText_BattleFactoryDesc[] = _("Busque a vitória com Pokémon\n"
        "emprestados! Seu conhecimento será\l"
        "testado.");
const u8 gText_BattlePikeDesc[] = _("Escolha um de três caminhos! Sua\n"
        "sorte será testada.");
const u8 gText_BattlePyramidDesc[] = _("Explore para chegar ao topo! Sua\n"
        "coragem será testada.");
const u8 gText_Powder[] = _("POWDER");
const u8 gText_BerryPickingRecords[] = _("DODRIO BERRY-PICKING RECORDS");
const u8 gText_BerriesPicked[] = _("BERRIES picked:");
const u8 gText_BestScore[] = _("Best score:");
const u8 gText_BerriesInRowFivePlayers[] = _("Berries colhidas em sequência com\n"
        "cinco jogadores:");
const u8 gText_BerryPickingResults[] = _("Anunciando os resultados da\n"
        "colheita!");
const u8 gText_10P30P50P50P[] = _("{CLEAR_TO 3}10P{CLEAR_TO 43}30P{CLEAR_TO 83}50P{CLEAR_TO 119}{EMOJI_MINUS}50P");
const u8 gText_AnnouncingRankings[] = _("Anunciando a classificaçao!");
const u8 gText_AnnouncingPrizes[] = _("Anunciando os prêmios!");
const u8 gText_1Colon[] = _("1:");
const u8 gText_2Colon[] = _("2:");
const u8 gText_3Colon[] = _("3:");
const u8 gText_4Colon[] = _("4:");
const u8 gText_5Colon[] = _("5:");
const u8 gText_FirstPlacePrize[] = _("O primeiro lugar ganha\n"
        "{DYNAMIC 0}!");
const u8 gText_CantHoldAnyMore[] = _("Nao pode carregar mais!");
const u8 gText_FilledStorageSpace[] = _("Todo o espaço foi ocupado.");
const u8 gText_WantToPlayAgain[] = _("Quer jogar de novo?");
const u8 gText_SomeoneDroppedOut[] = _("Alguém saiu. A conexao será\n"
        "encerrada.");
const u8 gText_SpacePoints[] = _(" points");
const u8 gText_CommunicationStandby3[] = _("Communication standby…");
const u8 gText_SpacePoints2[] = _(" points");
const u8 gText_SpaceTimes3[] = _(" time(s)");
const u8 gText_PkmnJumpRecords[] = _("POKéMON JUMP RECORDS");
const u8 gText_JumpsInARow[] = _("Pulos seguidos:");
const u8 gText_BestScore2[] = _("Best score:");
const u8 gText_ExcellentsInARow[] = _("EXCELENTES seguidos:");
const u8 gText_AwesomeWonF701F700[] = _("Que pontuaçao! Você ganhou\n"
        "{DYNAMIC 1} {DYNAMIC 0}!");
const u8 gText_FilledStorageSpace2[] = _("Todo o espaço foi ocupado.");
const u8 gText_CantHoldMore[] = _("Nao pode carregar mais!");
const u8 gText_WantToPlayAgain2[] = _("Quer jogar de novo?");
const u8 gText_SomeoneDroppedOut2[] = _("Alguém saiu. A conexao será\n"
        "encerrada.");
const u8 gText_CommunicationStandby4[] = _("Communication standby…");
const u8 gText_LinkContestResults[] = _("Resultados de {PLAYER} nos Link\n"
        "Contests");
const u8 gText_1st[] = _("1st");
const u8 gText_2nd[] = _("2nd");
const u8 gText_3rd[] = _("3rd");
const u8 gText_4th[] = _("4th");
const u8 gText_Friend[] = _("Friend");
const u8 gText_Pokemon3[] = _("POKeMON"); // Unused
const u8 gJPText_MysteryGift[] = _("ふしぎなもらいもの");
const u8 gJPText_DecideStop[] = _("{A_BUTTON}けってい {B_BUTTON}やめる");
const u8 gJPText_ReceiveMysteryGiftWithEReader[] = _("カードeリーダー{PLUS}　で\nふしぎなもらいものを　よみこみます");
const u8 gJPText_SelectConnectFromEReaderMenu[] = _("カードeリーダー{PLUS}の　メニューから\n‘つうしん'を　えらび");
const u8 gJPText_SelectConnectWithGBA[] = _("‘ゲームボーイアドバンスとつうしん'\nを　せんたく　してください");
const u8 gJPText_SelectConnectAndPressA[] = _("カードeリーダー{PLUS}の　‘つうしん'を\nえらんで　Aボタンを　おしてください"); // Unused
const u8 gJPText_LinkIsIncorrect[] = _("せつぞくが　まちがっています");
const u8 gJPText_CardReadingHasBeenHalted[] = _("カードの　よみこみを\nちゅうし　しました");
const u8 gJPText_UnableConnectWithEReader[] = _("カードeリーダー{PLUS}と\nつうしん　できません"); // Unused
const u8 gJPText_Connecting[] = _("つうしん　ちゅう　です");
const u8 gJPText_ConnectionErrorCheckLink[] = _("つうしん　エラーです\nせつぞくを　たしかめて　ください");
const u8 gJPText_ConnectionErrorTryAgain[] = _("つうしん　エラーです\nはじめから　やりなおして　ください"); // Link error
const u8 gJPText_AllowEReaderToLoadCard[] = _("カードeリーダー{PLUS}　に\nカードを　よみこませて　ください");
const u8 gJPText_ConnectionComplete[] = _("つうしん　しゅうりょう！");
const u8 gJPText_NewTrainerHasComeToHoenn[] = _("あらたな　トレーナーが\nホウエンに　やってきた！");
const u8 gJPText_PleaseWaitAMoment[] = _("しばらく　おまちください");
const u8 gJPText_WriteErrorUnableToSaveData[] = _("かきこみ　エラー　です\nデータが　ほぞん　できませんでした");
const u8 gText_SingleBattleRoomResults[] = _("Resultados de {PLAYER} na sala\n"
        "individual");
const u8 gText_DoubleBattleRoomResults[] = _("Resultados de {PLAYER} na sala de\n"
        "duplas");
const u8 gText_MultiBattleRoomResults[] = _("Resultados de {PLAYER} na sala\n"
        "Multi");
const u8 gText_LinkMultiBattleRoomResults[] = _("Resultados de {PLAYER} na sala Link\n"
        "Multi");
const u8 gText_SingleBattleTourneyResults[] = _("Resultados de {PLAYER} no torneio\n"
        "individual");
const u8 gText_DoubleBattleTourneyResults[] = _("Resultados de {PLAYER} no torneio\n"
        "de duplas");
const u8 gText_SingleBattleHallResults[] = _("Resultados de {PLAYER} no salao\n"
        "individual");
const u8 gText_DoubleBattleHallResults[] = _("Resultados de {PLAYER} no salao de\n"
        "duplas");
const u8 gText_BattleChoiceResults[] = _("Resultados de {PLAYER} no Battle\n"
        "Choice");
const u8 gText_SetKOTourneyResults[] = _("Resultados de {PLAYER} no torneio\n"
        "Set KO");
const u8 gText_BattleSwapSingleResults[] = _("Resultados de {PLAYER} no Battle\n"
        "Swap individual");
const u8 gText_BattleSwapDoubleResults[] = _("Resultados de {PLAYER} no Battle\n"
        "Swap em duplas");
const u8 gText_BattleQuestResults[] = _("Resultados de {PLAYER} no Battle\n"
        "Quest");
const u8 gText_Lv502[] = _("LV. 50");
const u8 gText_OpenLv[] = _("OPEN LV.");
const u8 gText_WinStreak[] = _("Win streak: {STR_VAR_1}");
const u8 gText_Current[] = _("CURRENT");
const u8 gText_Record[] = _("RECORD");
const u8 gText_Prev[] = _("PREV.");
const u8 gText_RentalSwap[] = _("Rental/Swap");
const u8 gText_Total[] = _("Total");
const u8 gText_ClearStreak[] = _("Clear streak: {STR_VAR_1}");
const u8 gText_Championships[] = _("Championships: {STR_VAR_1}");
const u8 gText_RoomsCleared[] = _("Rooms cleared: {STR_VAR_1}");
const u8 gText_TimesCleared[] = _("Times cleared:{CLEAR 5}{STR_VAR_1}");
const u8 gText_KOsInARow[] = _("Nocautes seguidos: {STR_VAR_1}");
const u8 gText_TimesVar1[] = _("Times: {STR_VAR_1}");
const u8 gText_FloorsCleared[] = _("Floors cleared: {STR_VAR_1}");

ALIGNED(4) const u8 gText_RecordsLv50[] = _("LV. 50");
ALIGNED(4) const u8 gText_RecordsOpenLevel[] = _("OPEN LEVEL");
ALIGNED(4) const u8 gText_FrontierFacilityWinStreak[] = _("Win streak: {STR_VAR_2}");
ALIGNED(4) const u8 gText_FrontierFacilityClearStreak[] = _("Clear streak: {STR_VAR_2}");
ALIGNED(4) const u8 gText_FrontierFacilityRoomsCleared[] = _("Rooms cleared: {STR_VAR_2}");
ALIGNED(4) const u8 gText_FrontierFacilityKOsStreak[] = _("Nocautes seguidos: {STR_VAR_2}");
ALIGNED(4) const u8 gText_FrontierFacilityFloorsCleared[] = _("Floors cleared: {STR_VAR_2}");
ALIGNED(4) const u8 gText_123Dot[][3] = {_("1."), _("2."), _("3.")};
const u8 gText_FrontierFacilityTotalCaughtSpeciesBanned[] = _(" e {STR_VAR_2} das espécies que\n"
        "você capturou nao podem participar");
const u8 gText_FrontierFacilityIncluding[] = _(".\pThese include ");
const u8 gText_FrontierFacilityAreInelegible[] = _(" are inelegible");

const u8 gText_YesNo[] = _("Sim\n"
        "Nao");
const u8 gText_SelectorArrow3[] = _("▶");
const u8 gText_Peekaboo[] = _("PEEKABOO!");
const u8 gText_CommErrorCheckConnections[] = _("Communication error…\nPlease check all connections,\nthen turn the power OFF and ON.");
const u8 gText_CommErrorEllipsis[] = _("Communication error…");
const u8 gText_MoveCloserToLinkPartner[] = _("Chegue mais perto dos outros\n"
        "jogadores. Evite obstáculos entre\l"
        "vocês.");
const u8 gText_ABtnRegistrationCounter[] = _("Botao A: Balcao de inscriçao");
const u8 gText_ABtnTitleScreen[] = _("Botao A: Tela inicial");
const u8 gText_NumPlayerLink[] = _("{STR_VAR_1}P LINK");
const u8 gText_BronzeCard[] = _("BRONZE");
const u8 gText_CopperCard[] = _("COPPER");
const u8 gText_SilverCard[] = _("SILVER");
const u8 gText_GoldCard[] = _("GOLD");
const u8 gText_Day[] = _("DAY");
const u8 gText_Colon3[] = _(":");
const u8 gText_Confirm2[] = _("Confirmar");
const u8 gText_Days[] = _("Days"); // Unused
const u8 gText_TimeColon2[] = _("Time:"); // Unused
const u8 gText_GameTime[] = _("Game time"); // Unused
const u8 gText_RTCTime[] = _("RTC time"); // Unused
const u8 gText_UpdatedTime[] = _("Updated time"); // Unused
const u8 gText_MenuPokedex[] = _("POKéDEX");
const u8 gText_MenuPokemon[] = _("POKéMON");
const u8 gText_MenuBag[] = _("BAG");
const u8 gText_MenuPokenav[] = _("POKéNAV");
const u8 gText_MenuPlayer[] = _("{PLAYER}");
const u8 gText_MenuSave[] = _("SAVE");
const u8 gText_MenuOption[] = _("OPTION");
const u8 gText_MenuExit[] = _("EXIT");
const u8 gText_MenuRetire[] = _("RETIRE");
const u8 gText_MenuRest[] = _("REST");
const u8 gText_MenuDexNav[] = _("DEXNAV");
const u8 gText_SafariBallStock[] = _("Safari Balls restantes:\n"
        "{STR_VAR_1}");
const u8 gText_MenuSafariStats[] = _("{STR_VAR_1}/{STR_VAR_2}\nBALLS  {STR_VAR_3}");
const u8 gText_BattlePyramidFloor[] = _("Battle Pyramid\n{STR_VAR_1}");
const u8 gText_Floor1[] = _("Floor 1");
const u8 gText_Floor2[] = _("Floor 2");
const u8 gText_Floor3[] = _("Floor 3");
const u8 gText_Floor4[] = _("Floor 4");
const u8 gText_Floor5[] = _("Floor 5");
const u8 gText_Floor6[] = _("Floor 6");
const u8 gText_Floor7[] = _("Floor 7");
const u8 gText_Peak[] = _("Peak");
const u8 gText_LinkStandby2[] = _("Esperando conexao... ... ... Botao\n"
        "B: Cancelar");
const u8 gText_PressAToLoadEvent[] = _("Aperte A para carregar o evento.\n"
        "... ... Botao B: Cancelar");
const u8 gText_LoadingEvent[] = _("Loading event…");
const u8 gText_DontRemoveCableTurnOff[] = _("Nao remova o cabo Game Link. Nao\n"
        "desligue o jogo.");
const u8 gText_EventSafelyLoaded[] = _("O evento foi carregado com\n"
        "sucesso.");
const u8 gText_LoadErrorEndingSession[] = _("Loading error.\nEnding session.");
const u8 gJPText_Player[] = _("プレイヤー"); // Unused
const u8 gJPText_Sama[] = _("さま"); // Unused
const u8 gText_DexHoenn[] = _("HOENN");
const u8 gText_DexNational[] = _("NATIONAL");
const u8 gText_PokedexDiploma[] = _("PLAYER: {CLEAR 16}{COLOR RED}{SHADOW LIGHT_RED}{PLAYER}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}\n\nThis document certifies\nthat you have successfully\ncompleted your\n{STR_VAR_1} POKéDEX.\n\n{CLEAR_TO 66}{COLOR RED}{SHADOW LIGHT_RED}GAME FREAK");
const u8 gJPText_GameFreak[] = _("{COLOR RED}{SHADOW LIGHT_RED}ゲ-ムフリ-ク"); // Unused
const u8 gText_DiplomaEmpty[] = _("{COLOR RED}{SHADOW LIGHT_RED}"); // Unused
const u8 gText_Hoenn[] = _("HOENN");
const u8 gText_Kanto[] = _("KANTO");
const u8 gText_XWillBeSentToY[] = _("{STR_VAR_2} será enviado para\n"
        "{STR_VAR_1}.");
const u8 gText_ByeByeVar1[] = _("Tchau, {STR_VAR_2}!");
const u8 gText_XSentOverY[] = _("{STR_VAR_1} enviou\n"
        "{STR_VAR_3}.");
const u8 gText_TakeGoodCareOfX[] = _("Cuide bem de {STR_VAR_3}!");

const u8 gText_ThreeQuestionMarks[] = _("???");
const u8 gText_MaxHP[] = _("MAX. HP");
const u8 gText_Attack[] = _("ATTACK");
const u8 gText_Defense[] = _("DEFENSE");
const u8 gText_Speed[] = _("SPEED");
const u8 gText_SpAtk[] = _("SP. ATK");
const u8 gText_SpDef[] = _("SP. DEF");
const u8 gText_Plus[] = _("{PLUS}");
const u8 gText_Dash[] = _("-");
const u8 gText_MixingRecords[] = _("Mixing records…");
const u8 gText_RecordMixingComplete[] = _("Mistura de registros concluída.\n"
        "Obrigado por esperar.");
const u8 gText_RentalPkmn2[] = _("RENTAL POKéMON");
const u8 gText_SelectFirstPkmn[] = _("Escolha o primeiro Pokémon.");
const u8 gText_SelectSecondPkmn[] = _("Escolha o segundo Pokémon.");
const u8 gText_SelectThirdPkmn[] = _("Escolha o terceiro Pokémon.");
const u8 gText_Rent[] = _("RENT");
const u8 gText_Summary[] = _("SUMMARY");
const u8 gText_Others2[] = _("OTHERS");
const u8 gText_Deselect[] = _("DESELECT");
const u8 gText_TheseThreePkmnOkay[] = _("Esses três Pokémon estao certos?");
const u8 gText_Yes2[] = _("Sim");
const u8 gText_No2[] = _("Nao");
const u8 gText_CantSelectSamePkmn[] = _("Nao pode repetir {PKMN}.");
const u8 gText_PkmnSwap[] = _("POKéMON SWAP");
const u8 gText_SelectPkmnToSwap[] = _("Escolha o Pokémon para trocar.");
const u8 gText_SelectPkmnToAccept[] = _("Escolha o Pokémon para receber.");
const u8 gText_Swap[] = _("SWAP");
const u8 gText_Summary2[] = _("SUMMARY");
const u8 gText_Rechoose[] = _("RECHOOSE");
const u8 gText_QuitSwapping[] = _("Parar de trocar?");
const u8 gText_Yes3[] = _("Sim");
const u8 gText_No3[] = _("Nao");
const u8 gText_PkmnForSwap[] = _("{PKMN} FOR SWAP");
const u8 gText_Cancel3[] = _("Cancelar");
const u8 gText_Swap2[] = _("SWAP"); // Unused
const u8 gText_Accept[] = _("ACCEPT"); // Unused
const u8 gText_AcceptThisPkmn[] = _("Aceitar esse Pokémon?");
const u8 gText_4Spaces[] = _("    "); // Unused
const u8 gText_SamePkmnInPartyAlready[] = _("Já tem esse {PKMN} no time.");
const u8 gText_DecimalPoint[] = _(".");
const u8 gText_SavingPlayer[] = _("PLAYER");
const u8 gText_SavingBadges[] = _("BADGES");
const u8 gText_SavingPokedex[] = _("POKéDEX");
const u8 gText_SavingTime[] = _("TIME");
const u8 gText_WirelessCommStatus[] = _("Wireless Communication Status");
const u8 gText_PeopleTrading[] = _("People trading:");
const u8 gText_PeopleBattling[] = _("People battling:");
const u8 gText_PeopleInUnionRoom[] = _("Pessoas na Union Room:");
const u8 gText_PeopleCommunicating[] = _("People communicating:");
const u8 gText_F700Players[] = _("{DYNAMIC 0} players");
const u8 gText_F701Players[] = _("{DYNAMIC 1} players");
const u8 gText_F702Players[] = _("{DYNAMIC 2} players");
const u8 gText_F703Players[] = _("{DYNAMIC 3} players");

const u8 *const gTextTable_Players[] = {
    gText_F700Players,
    gText_F701Players,
    gText_F702Players,
    gText_F703Players
};

ALIGNED(4) const u8 gText_WonderCards[] = _("WONDER CARDS");
ALIGNED(4) const u8 gText_WonderNews[] = _("WONDER NEWS");
ALIGNED(4) const u8 gText_WirelessCommunication[] = _("WIRELESS COMMUNICATION");
ALIGNED(4) const u8 gText_Friend2[] = _("FRIEND");
ALIGNED(4) const u8 gText_Exit3[] = _("Sair");
ALIGNED(4) const u8 gText_Receive[] = _("RECEIVE");
ALIGNED(4) const u8 gText_Send[] = _("SEND");
ALIGNED(4) const u8 gText_Toss[] = _("TOSS");
ALIGNED(4) const u8 gText_VarietyOfEventsImportedWireless[] = _("Vários eventos podem ser recebidos\n"
        "pela conexao sem fio.");
ALIGNED(4) const u8 gText_WonderCardsInPossession[] = _("Leia as Wonder Cards que você tem.");
ALIGNED(4) const u8 gText_ReadNewsThatArrived[] = _("Leia as notícias recebidas.");
ALIGNED(4) const u8 gText_ReturnToTitle[] = _("Voltar para a tela inicial.");
ALIGNED(4) const u8 gText_DontHaveCardNewOneInput[] = _("Você nao tem uma Wonder Card. Uma\n"
        "nova será recebida.");
ALIGNED(4) const u8 gText_DontHaveNewsNewOneInput[] = _("Você nao tem Wonder News. Uma\n"
        "nova notícia será recebida.");
ALIGNED(4) const u8 gText_WhereShouldCardBeAccessed[] = _("De onde quer receber a Wonder\n"
        "Card?");
ALIGNED(4) const u8 gText_WhereShouldNewsBeAccessed[] = _("De onde quer receber a Wonder\n"
        "News?");
ALIGNED(4) const u8 gText_CommunicationStandbyBButtonCancel[] = _("Esperando conexao... Botao B:\n"
        "Cancelar"); // Unused
ALIGNED(4) const u8 gText_Communicating[] = _("Communicating…");
ALIGNED(4) const u8 gText_CommunicationCompleted[] = _("Communication completed.");
ALIGNED(4) const u8 gText_CommunicationError[] = _("Communication error.");
ALIGNED(4) const u8 gText_CommunicationCanceled[] = _("A conexao foi cancelada.");
ALIGNED(4) const u8 gText_ThrowAwayWonderCard[] = _("Jogar fora a Wonder Card e receber\n"
        "uma nova?");
ALIGNED(4) const u8 gText_HaventReceivedCardsGift[] = _("Você ainda nao recebeu o presente\n"
        "dessa carta. Receber outra mesmo\l"
        "assim?");
ALIGNED(4) const u8 gText_WonderCardReceivedFrom[] = _("Uma Wonder Card foi recebida de\n"
        "{STR_VAR_1}.");
ALIGNED(4) const u8 gText_WonderNewsReceivedFrom[] = _("Uma Wonder News foi recebida de\n"
        "{STR_VAR_1}.");
ALIGNED(4) const u8 gText_WonderCardReceived[] = _("Uma nova Wonder Card foi recebida.");
ALIGNED(4) const u8 gText_WonderNewsReceived[] = _("Uma nova Wonder News foi recebida.");
ALIGNED(4) const u8 gText_NewStampReceived[] = _("Um novo selo foi recebido.");
ALIGNED(4) const u8 gText_NewTrainerReceived[] = _("Um novo treinador chegou.");
ALIGNED(4) const u8 gText_AlreadyHadCard[] = _("Você já tinha essa Wonder Card.");
ALIGNED(4) const u8 gText_AlreadyHadNews[] = _("Você já tinha essa Wonder News.");
ALIGNED(4) const u8 gText_AlreadyHadStamp[] = _("Você já tinha esse selo.");
ALIGNED(4) const u8 gText_NoMoreRoomForStamps[] = _("Nao há mais espaço para selos.");
ALIGNED(4) const u8 gText_RecordUploadedViaWireless[] = _("Seu registro foi enviado pela\n"
        "conexao sem fio.");
ALIGNED(4) const u8 gText_CantAcceptCardFromTrainer[] = _("Nao pode receber uma Wonder Card\n"
        "desse treinador.");
ALIGNED(4) const u8 gText_CantAcceptNewsFromTrainer[] = _("Nao pode receber Wonder News\n"
        "desse treinador.");
ALIGNED(4) const u8 gText_NothingSentOver[] = _("Nothing was sent over…");
ALIGNED(4) const u8 gText_WhatToDoWithCards[] = _("Oque quer fazer com as Wonder\n"
        "Cards?");
ALIGNED(4) const u8 gText_WhatToDoWithNews[] = _("Oque quer fazer com as Wonder\n"
        "News?");
ALIGNED(4) const u8 gText_SendingWonderCard[] = _("Sending your WONDER CARD…");
ALIGNED(4) const u8 gText_SendingWonderNews[] = _("Sending your WONDER NEWS item…");
ALIGNED(4) const u8 gText_WonderCardSentTo[] = _("Sua Wonder Card foi enviada para\n"
        "{STR_VAR_1}.");
ALIGNED(4) const u8 gText_WonderNewsSentTo[] = _("Sua Wonder News foi enviada para\n"
        "{STR_VAR_1}.");
ALIGNED(4) const u8 gText_StampSentTo[] = _("Um selo foi enviado para\n"
        "{STR_VAR_1}.");
ALIGNED(4) const u8 gText_GiftSentTo[] = _("Um presente foi enviado para\n"
        "{STR_VAR_1}.");
ALIGNED(4) const u8 gText_OtherTrainerHasCard[] = _("O outro treinador já tem a mesma\n"
        "Wonder Card.");
ALIGNED(4) const u8 gText_OtherTrainerHasNews[] = _("O outro treinador já tem a mesma\n"
        "Wonder News.");
ALIGNED(4) const u8 gText_OtherTrainerHasStamp[] = _("O outro treinador já tem esse\n"
        "selo.");
ALIGNED(4) const u8 gText_OtherTrainerCanceled[] = _("O outro treinador cancelou a\n"
        "conexao.");
ALIGNED(4) const u8 gText_CantSendGiftToTrainer[] = _("Nao pode enviar um Mystery Gift\n"
        "para esse treinador.");
ALIGNED(4) const u8 gText_IfThrowAwayCardEventWontHappen[] = _("Se jogar fora a carta, o evento\n"
        "dela nao vai acontecer. Tudo bem?");
ALIGNED(4) const u8 gText_OkayToDiscardNews[] = _("Pode apagar essa notícia?");
ALIGNED(4) const u8 gText_HaventReceivedGiftOkayToDiscard[] = _("Você ainda nao recebeu o presente.\n"
        "Pode apagar?");
ALIGNED(4) const u8 gText_DataWillBeSaved[] = _("Os dados serao salvos. Aguarde.");
ALIGNED(4) const u8 gText_SaveCompletedPressA[] = _("Jogo salvo. Aperte o botao A.");
ALIGNED(4) const u8 gText_WonderCardThrownAway[] = _("A Wonder Card foi jogada fora.");
ALIGNED(4) const u8 gText_WonderNewsThrownAway[] = _("A Wonder News foi apagada.");
ALIGNED(4) const u8 gText_MysteryGift[] = _("MYSTERY GIFT");
ALIGNED(4) const u8 gText_PickOKExit[] = _("{DPAD_UPDOWN}PICK {A_BUTTON}OK {B_BUTTON}EXIT");
ALIGNED(4) const u8 gText_PickOKCancel[] = _("{DPAD_UPDOWN}PICK {A_BUTTON}OK {B_BUTTON}CANCEL");
const u8 gText_PlayersBattleResults[] = _("{PLAYER}'s BATTLE RESULTS");
const u8 gText_TotalRecordWLD[] = _("TOTAL V:{STR_VAR_1}\n"
        "D:{STR_VAR_2} E:{STR_VAR_3}");
const u8 gText_WinLoseDraw[] = _("{CLEAR_TO 83}WIN{CLEAR_TO 128}LOSE{CLEAR_TO 176}DRAW");
const u8 gText_CommunicationStandby5[] = _("Communication standby…");
const u8 gDaycareText_GetAlongVeryWell[] = _("Os dois parecem se dar muito bem.");
const u8 gDaycareText_GetAlong[] = _("Os dois parecem se dar bem.");
const u8 gDaycareText_DontLikeOther[] = _("Os dois nao parecem gostar muito\n"
        "um do outro.");
const u8 gDaycareText_PlayOther[] = _("Os dois preferem brincar com\n"
        "outros Pokémon.");
const u8 gText_NewLine2[] = _("\n");
const u8 gText_Exit4[] = _("Sair");
const u8 gText_Lv[] = _("{LV}");
const u8 gText_TimeBoard[] = _("TIME BOARD");
const u8 gText_TimeCleared[] = _("TIME CLEARED ");
const u8 gText_XMinYDotZSec[] = _("{STR_VAR_1} min.\n"
        "{STR_VAR_2}.{STR_VAR_3} s.");
const u8 gText_TrainerHill1F[] = _("1F");
const u8 gText_TrainerHill2F[] = _("2F");
const u8 gText_TrainerHill3F[] = _("3F");
const u8 gText_TrainerHill4F[] = _("4F");
const u8 gText_TeachWhichMoveToPkmn[] = _("Ensinar qual {STR_VAR_3} a\n"
        "{STR_VAR_1}?");
const u8 gText_MoveRelearnerTeachMoveConfirm[] = _("Ensinar {STR_VAR_2}?");
const u8 gText_MoveRelearnerTeachMoveConfirmUseTm[] = _("Ensinar {STR_VAR_2}? Isso vai\n"
        "consumir um {STR_VAR_3}.");
const u8 gText_MoveRelearnerPkmnLearnedMove[] = _("{STR_VAR_1} aprendeu\n"
        "{STR_VAR_2}!");
const u8 gText_MoveRelearnerPkmnTryingToLearnMove[] = _("{STR_VAR_1} quer aprender\n"
        "{STR_VAR_2}, mas\l"
        "{STR_VAR_1} nao pode saber\l"
        "mais de quatro golpes. Esquecer um\l"
        "antigo para aprender\l"
        "{STR_VAR_2}?");
const u8 gText_MoveRelearnerStopTryingToTeachMove[] = _("Desistir de ensinar\n"
        "{STR_VAR_2}?");
const u8 gText_MoveRelearnerAndPoof[] = _("{PAUSE 32}1, {PAUSE 15}2, e {PAUSE 15}... {PAUSE 15}... {PAUSE 15}... {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}Puf!\p");
const u8 gText_MoveRelearnerPkmnForgotMoveAndLearnedNew[] = _("{STR_VAR_1} esqueceu\n"
        "{STR_VAR_3}. E...\l"
        "{STR_VAR_1} aprendeu\l"
        "{STR_VAR_2}.");
const u8 gText_MoveRelearnedPkmnDidNotLearnMove[] = _("{STR_VAR_1} nao aprendeu\n"
        "{STR_VAR_2}."); // Unused
const u8 gText_MoveRelearnerGiveUp[] = _("Desistir de ensinar um novo golpe\n"
        "a {STR_VAR_1}?");
const u8 gText_MoveRelearnerStop[] = _("Parar de procurar novos golpes\n"
        "para {STR_VAR_1}?");;
const u8 gText_MoveRelearnerWhichMoveToForget[] = _("Qual golpe quer esquecer?\p");
const u8 gText_MoveRelearnerBattleMoves[] = _("BATTLE MOVES");
const u8 gText_MoveRelearnerContestMovesTitle[] = _("CONTEST MOVES");
const u8 gText_MoveRelearnerType[] = _("TYPE/"); // Unused
const u8 gText_MoveRelearnerPP[] = _("PP/");
const u8 gText_MoveRelearnerPower[] = _("POWER/");
const u8 gText_MoveRelearnerAccuracy[] = _("ACCURACY/");
const u8 gText_MoveRelearnerAppeal[] = _("APPEAL");
const u8 gText_MoveRelearnerJam[] = _("JAM");
const u8 gText_ClearAllSaveData[] = _("Apagar todos os dados salvos?");
const u8 gText_ClearingData[] = _("Apagando dados... Aguarde.");
const u8 gText_IsThisTheCorrectTime[] = _("Essa é a hora certa?");
const u8 gText_Confirm3[] = _("Sim");
const u8 gText_Cancel4[] = _("Nao");
const u8 gText_CommStandbyAwaitingOtherPlayer[] = _("Esperando conexao... Aguardando o\n"
        "outro jogador escolher.");
const u8 gText_BattleWasRefused[] = _("A batalha foi recusada.{PAUSE 60}");
const u8 gText_RefusedBattle[] = _("Você recusou a batalha.{PAUSE 60}");
const u8 gText_NoWeather[] = _("NO WEATHER"); // Below are unused debug names for weather types
const u8 gText_Sunny[] = _("SUNNY"); // Unused
const u8 gText_Sunny2[] = _("SUNNY2"); // Unused
const u8 gText_Rain[] = _("RAIN"); // Unused
const u8 gText_Snow[] = _("SNOW"); // Unused
const u8 gText_Lightning[] = _("LIGHTNING"); // Unused
const u8 gText_Fog[] = _("FOG"); // Unused
const u8 gText_VolcanoAsh[] = _("VOLCANO ASH"); // Unused
const u8 gText_Sandstorm[] = _("SANDSTORM"); // Unused
const u8 gText_Fog2[] = _("FOG2"); // Unused
const u8 gText_Seafloor[] = _("SEAFLOOR"); // Unused
const u8 gText_Cloudy[] = _("CLOUDY"); // Unused
const u8 gText_Sunny3[] = _("SUNNY3"); // Unused
const u8 gText_HeavyRain[] = _("HEAVY RAIN"); // Unused
const u8 gText_Seafloor2[] = _("SEAFLOOR2"); // Unused
const u8 gText_DelAll[] = _("DEL. ALL");
const u8 gText_Cancel5[] = _("Cancelar");
const u8 gText_Ok2[] = _("OK");
const u8 gText_Quiz[] = _("QUIZ");
const u8 gText_Answer[] = _("ANSWER");
const u8 gText_PokeBalls[] = _("POKé BALLS");
const u8 gText_Berry[] = _("BERRY");
const u8 gText_Berries[] = _("BERRIES");
const u8 gText_ExpShareOn[] = _("O Exp. Share foi ligado.{PAUSE_UNTIL_PRESS}");
const u8 gText_ExpShareOff[] = _("O Exp. Share foi desligado.{PAUSE_UNTIL_PRESS}");
ALIGNED(4) const u8 gText_Ghost[] = _("GHOST");
const u8 gText_Boulderbadge[] = _("BOULDERBADGE");
const u8 gText_Cascadebadge[] = _("CASCADEBADGE");
const u8 gText_Thunderbadge[] = _("THUNDERBADGE");
const u8 gText_Rainbowbadge[] = _("RAINBOWBADGE");
const u8 gText_Soulbadge[] = _("SOULBADGE");
const u8 gText_Marshbadge[] = _("MARSHBADGE");
const u8 gText_Volcanobadge[] = _("VOLCANOBADGE");
const u8 gText_Earthbadge[] = _("EARTHBADGE");
const u8 gText_OakImportantToGetToKnowPokemonThroughly[] = _("OAK: É importante conhecer bem\n"
        "seus Pokémon.\p");
const u8 gText_OakThisIsListOfPokemon[] = _("Essa é a lista dos seus Pokémon,\n"
        "{PLAYER}. Abra para ver as\l"
        "habilidades e os golpes de cada\l"
        "um. Também pode escolher um\l"
        "Pokémon aqui para usar um item\l"
        "nele.{PAUSE_UNTIL_PRESS}");
