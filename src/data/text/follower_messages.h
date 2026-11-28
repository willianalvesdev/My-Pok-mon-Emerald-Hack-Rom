extern const u8 EventScript_FollowerIsShivering[];
extern const u8 EventScript_FollowerNostalgia[];
extern const u8 EventScript_FollowerHopping[];
extern const u8 EventScript_FollowerJumpOnPlayer[];
extern const u8 EventScript_FollowerCuddling[];
extern const u8 EventScript_FollowerShiverCuddling[];
extern const u8 EventScript_FollowerGetCloser[];
extern const u8 EventScript_FollowerPokingPlayer[];
extern const u8 EventScript_FollowerLookAround[];
extern const u8 EventScript_FollowerLookAway[];
extern const u8 EventScript_FollowerLookAwayBark[];
extern const u8 EventScript_FollowerLookAwayPoke[];
extern const u8 EventScript_FollowerPokeGround[];
extern const u8 EventScript_FollowerStartled[];
extern const u8 EventScript_FollowerFastHopping[];
extern const u8 EventScript_FollowerDizzy[];
extern const u8 EventScript_FollowerLookAroundScared[];
extern const u8 EventScript_FollowerDance[];
extern const u8 EventScript_FollowerLookUp[];

// 'Generic', unconditional happy messages
static const u8 sHappyMsg00[] = _("{STR_VAR_1} começou a cutucar\n"
        "sua barriga.");
static const u8 sHappyMsg01[] = _("{STR_VAR_1} está feliz, mas com\n"
        "vergonha.");
static const u8 sHappyMsg02[] = _("{STR_VAR_1} segue feliz pelo\n"
        "caminho.");
static const u8 sHappyMsg03[] = _("{STR_VAR_1} is composed.");
static const u8 sHappyMsg04[] = _("{STR_VAR_1} parece adorar\n"
        "passear com você!");
static const u8 sHappyMsg05[] = _("{STR_VAR_1} está cheio de\n"
        "saúde.");
static const u8 sHappyMsg06[] = _("{STR_VAR_1} parece muito feliz.");
static const u8 sHappyMsg07[] = _("{STR_VAR_1} fez um esforço a\n"
        "mais.");
static const u8 sHappyMsg08[] = _("{STR_VAR_1} está sentindo os\n"
        "cheiros ao redor.");
static const u8 sHappyMsg09[] = _("{STR_VAR_1} está pulando de\n"
        "alegria!");
static const u8 sHappyMsg10[] = _("{STR_VAR_1} continua se\n"
        "sentindo muito bem!");
static const u8 sHappyMsg11[] = _("Seu Pokémon sentiu cheiro de\n"
        "fumaça.");
static const u8 sHappyMsg12[] = _("{STR_VAR_1} está cutucando sua\n"
        "barriga.");
static const u8 sHappyMsg13[] = _("Seu Pokémon se espreguiçou e está\n"
        "relaxando.");
static const u8 sHappyMsg14[] = _("{STR_VAR_1} parece querer ir na\n"
        "frente!");
static const u8 sHappyMsg15[] = _("{STR_VAR_1} está dando seu\n"
        "melhor para acompanhar você.");
static const u8 sHappyMsg16[] = _("{STR_VAR_1} se aconchegou\n"
        "feliz em você!");
static const u8 sHappyMsg17[] = _("{STR_VAR_1} está cheio de vida!");
static const u8 sHappyMsg18[] = _("{STR_VAR_1} parece muito feliz!");
static const u8 sHappyMsg19[] = _("{STR_VAR_1} está tao feliz que\n"
        "nao para quieto!");
static const u8 sHappyMsg20[] = _("{STR_VAR_1} nodded slowly.");
static const u8 sHappyMsg21[] = _("{STR_VAR_1} está cheio de\n"
        "vontade!");
static const u8 sHappyMsg22[] = _("{STR_VAR_1} anda por aí\n"
        "ouvindo os sons diferentes.");
static const u8 sHappyMsg23[] = _("{STR_VAR_1} parece muito\n"
        "interessado.");
static const u8 sHappyMsg24[] = _("{STR_VAR_1} está se forçando a\n"
        "continuar.");
static const u8 sHappyMsg25[] = _("{STR_VAR_1} olhou para você\n"
        "com alegria!");
static const u8 sHappyMsg26[] = _("{STR_VAR_1} olhou feliz para\n"
        "você e sorriu.");
static const u8 sHappyMsg27[] = _("Seu Pokémon está sentindo o cheiro\n"
        "das flores.");
static const u8 sHappyMsg28[] = _("{STR_VAR_1} parece muito feliz\n"
        "por ver você!");
static const u8 sHappyMsg29[] = _("{STR_VAR_1} virou para você e\n"
        "abriu um sorriso.");
static const u8 sHappyMsg30[] = _("{STR_VAR_1} se aconchegou\n"
        "feliz em você!");
// Conditional messages begin here, index 31
static const u8 sHappyMsg31[] = _("Seu Pokémon parece feliz com o\n"
        "tempo bom.");
static const u8 sHappyMsg32[] = _("{STR_VAR_1} está muito calmo e\n"
        "confiante!");

const struct FollowerMsgInfo gFollowerHappyMessages[] = {
    {sHappyMsg00, EventScript_FollowerPokingPlayer},
    {sHappyMsg01}, {sHappyMsg02}, {sHappyMsg03}, {sHappyMsg04}, {sHappyMsg05}, {sHappyMsg06}, {sHappyMsg07},
    {sHappyMsg08, EventScript_FollowerLookAround},
    {sHappyMsg09, EventScript_FollowerHopping},
    {sHappyMsg10}, {sHappyMsg11},
    {sHappyMsg12, EventScript_FollowerPokingPlayer},
    {sHappyMsg13, EventScript_FollowerLookAround},
    {sHappyMsg14}, {sHappyMsg15},
    {sHappyMsg16, EventScript_FollowerCuddling},
    {sHappyMsg17}, {sHappyMsg18},
    {sHappyMsg19, EventScript_FollowerFastHopping},
    {sHappyMsg20}, {sHappyMsg21}, {sHappyMsg22}, {sHappyMsg23}, {sHappyMsg24}, {sHappyMsg25}, {sHappyMsg26}, {sHappyMsg27}, {sHappyMsg28}, {sHappyMsg29},
    {sHappyMsg30, EventScript_FollowerCuddling},
    {sHappyMsg31}, {sHappyMsg32},
};

// Unconditional neutral messages
static const u8 sNeutralMsg00[] = _("{STR_VAR_1} está cutucando o\n"
        "chao sem parar.");
static const u8 sNeutralMsg01[] = _("{STR_VAR_1} está de guarda.");
static const u8 sNeutralMsg02[] = _("{STR_VAR_1} olha para o nada\n"
        "com paciência.");
static const u8 sNeutralMsg03[] = _("{STR_VAR_1} está andando por\n"
        "aí.");
static const u8 sNeutralMsg04[] = _("Seu Pokémon deu um bocejo alto!");
static const u8 sNeutralMsg05[] = _("Seu Pokémon olha ao redor sem\n"
        "parar.");
static const u8 sNeutralMsg06[] = _("{STR_VAR_1} está olhando para\n"
        "você e sorrindo.");
static const u8 sNeutralMsg07[] = _("{STR_VAR_1} olha ao redor com\n"
        "inquietaçao.");
static const u8 sNeutralMsg08[] = _("{STR_VAR_1} soltou um grito de\n"
        "batalha.");
static const u8 sNeutralMsg09[] = _("{STR_VAR_1} fez uma dança\n"
        "incrível!");
static const u8 sNeutralMsg10[] = _("{STR_VAR_1} está cheio de\n"
        "vontade.");
static const u8 sNeutralMsg11[] = _("{STR_VAR_1} está olhando para\n"
        "longe com atençao.");
static const u8 sNeutralMsg12[] = _("{STR_VAR_1} está de olho em\n"
        "tudo!");
static const u8 sNeutralMsg13[] = _("{STR_VAR_1} olhou para longe e\n"
        "latiu!");

const struct FollowerMsgInfo gFollowerNeutralMessages[] = {
    {sNeutralMsg00, EventScript_FollowerPokeGround},
    {sNeutralMsg01},
    {sNeutralMsg02, EventScript_FollowerLookAway},
    {sNeutralMsg03, EventScript_FollowerLookAround},
    {sNeutralMsg04},
    {sNeutralMsg05, EventScript_FollowerLookAround},
    {sNeutralMsg06}, {sNeutralMsg07}, {sNeutralMsg08},
    {sNeutralMsg09, EventScript_FollowerDance},
    {sNeutralMsg10},
    {sNeutralMsg11, EventScript_FollowerLookAway},
    {sNeutralMsg12},
    {sNeutralMsg13, EventScript_FollowerLookAwayBark},
};

// Unconditional sad messages
static const u8 sSadMsg00[] = _("{STR_VAR_1} is dizzy.");
static const u8 sSadMsg01[] = _("{STR_VAR_1} está pisando nos\n"
        "seus pés!");
static const u8 sSadMsg02[] = _("{STR_VAR_1} parece um pouco\n"
        "cansado.");
// Conditional messages begin, index 3
static const u8 sSadMsg03[] = _("{STR_VAR_1} nao está feliz.");
static const u8 sSadMsg04[] = _("{STR_VAR_1} vai cair!\n");
static const u8 sSadMsg05[] = _("{STR_VAR_1} parece prestes a\n"
        "cair!");
static const u8 sSadMsg06[] = _("{STR_VAR_1} está se esforçando\n"
        "muito para acompanhar você...");
static const u8 sSadMsg07[] = _("{STR_VAR_1} is nervous.");

const struct FollowerMsgInfo gFollowerSadMessages[] = {
    {sSadMsg00, EventScript_FollowerDizzy},
    {sSadMsg01}, {sSadMsg02},
    {sSadMsg03}, {sSadMsg04}, {sSadMsg05}, {sSadMsg06}, {sSadMsg07},
};

// Unconditional upset messages
static const u8 sUpsetMsg00[] = _("{STR_VAR_1} parece triste por\n"
        "algum motivo...");
static const u8 sUpsetMsg01[] = _("{STR_VAR_1} está fazendo uma\n"
        "cara triste.");
static const u8 sUpsetMsg02[] = _("...Seu Pokémon parece estar com um\n"
        "pouco de frio.");
// Conditional messages, index 3
static const u8 sUpsetMsg03[] = _("{STR_VAR_1} está se abrigando\n"
        "da chuva na grama.");

const struct FollowerMsgInfo gFollowerUpsetMessages[] = {
    {sUpsetMsg00}, {sUpsetMsg01},
    {sUpsetMsg02, EventScript_FollowerIsShivering},
    {sUpsetMsg03},
};

// Unconditional angry messages
static const u8 sAngryMsg00[] = _("{STR_VAR_1} soltou um rugido!");
static const u8 sAngryMsg01[] = _("{STR_VAR_1} está fazendo cara\n"
        "de bravo!");
static const u8 sAngryMsg02[] = _("{STR_VAR_1} parece com raiva\n"
        "por algum motivo.");
static const u8 sAngryMsg03[] = _("Seu Pokémon virou de costas e fez\n"
        "uma cara de desafio.");
static const u8 sAngryMsg04[] = _("{STR_VAR_1} cried out.");

const struct FollowerMsgInfo gFollowerAngryMessages[] = {
    {sAngryMsg00}, {sAngryMsg01}, {sAngryMsg02},
    {sAngryMsg03, EventScript_FollowerLookAway},
    {sAngryMsg04},
};

// Unconditional pensive messages
static const u8 sPensiveMsg00[] = _("{STR_VAR_1} está olhando para\n"
        "baixo sem parar.");
static const u8 sPensiveMsg01[] = _("{STR_VAR_1} está observando a\n"
        "área.");
static const u8 sPensiveMsg02[] = _("{STR_VAR_1} está olhando lá\n"
        "embaixo.");
static const u8 sPensiveMsg03[] = _("{STR_VAR_1} está lutando\n"
        "contra o sono...");
static const u8 sPensiveMsg04[] = _("{STR_VAR_1} parece estar\n"
        "andando por aí.");
static const u8 sPensiveMsg05[] = _("{STR_VAR_1} olha ao redor sem\n"
        "prestar atençao.");
static const u8 sPensiveMsg06[] = _("{STR_VAR_1} deu um bocejo\n"
        "muito alto!");
static const u8 sPensiveMsg07[] = _("{STR_VAR_1} está relaxando à\n"
        "vontade.");
static const u8 sPensiveMsg08[] = _("{STR_VAR_1} nao tira os olhos\n"
        "do seu rosto.");
static const u8 sPensiveMsg09[] = _("{STR_VAR_1} olha com atençao\n"
        "para seu rosto.");
static const u8 sPensiveMsg10[] = _("{STR_VAR_1} está prestando\n"
        "atençao em você.");
static const u8 sPensiveMsg11[] = _("{STR_VAR_1} está olhando para\n"
        "as profundezas.");
static const u8 sPensiveMsg12[] = _("{STR_VAR_1} está cheirando o\n"
        "chao.");
static const u8 sPensiveMsg13[] = _("Seu Pokémon olha fixamente para o\n"
        "nada.");
static const u8 sPensiveMsg14[] = _("{STR_VAR_1} lançou um olhar\n"
        "atento!");
static const u8 sPensiveMsg15[] = _("{STR_VAR_1} is concentrating.");
static const u8 sPensiveMsg16[] = _("{STR_VAR_1} virou para você e\n"
        "fez que sim.");
static const u8 sPensiveMsg17[] = _("{STR_VAR_1} parece um pouco\n"
        "nervoso...");
static const u8 sPensiveMsg18[] = _("{STR_VAR_1} está olhando suas\n"
        "pegadas.");
static const u8 sPensiveMsg19[] = _("{STR_VAR_1} olha direto nos\n"
        "seus olhos.");

const struct FollowerMsgInfo gFollowerPensiveMessages[] = {
    {sPensiveMsg00},
    {sPensiveMsg01, EventScript_FollowerLookAround},
    {sPensiveMsg02}, {sPensiveMsg03}, {sPensiveMsg04},
    {sPensiveMsg05, EventScript_FollowerLookAround},
    {sPensiveMsg06}, {sPensiveMsg07}, {sPensiveMsg08}, {sPensiveMsg09}, {sPensiveMsg10},
    {sPensiveMsg11, EventScript_FollowerLookAway},
    {sPensiveMsg12, EventScript_FollowerPokeGround},
    {sPensiveMsg13, EventScript_FollowerLookAway},
    {sPensiveMsg14}, {sPensiveMsg15}, {sPensiveMsg16}, {sPensiveMsg17}, {sPensiveMsg18}, {sPensiveMsg19},
};

// All 'love' messages are unconditional
static const u8 sLoveMsg00[] = _("{STR_VAR_1} de repente começou\n"
        "a chegar mais perto!");
static const u8 sLoveMsg01[] = _("As bochechas de {STR_VAR_1}\n"
        "estao ficando rosadas!");
static const u8 sLoveMsg02[] = _("Opa! {STR_VAR_1} abraçou você\n"
        "do nada!");
static const u8 sLoveMsg03[] = _("Opa! Deu vontade de brincar em\n"
        "{STR_VAR_1}!");
static const u8 sLoveMsg04[] = _("{STR_VAR_1} está se esfregando\n"
        "nas suas pernas!");
static const u8 sLoveMsg05[] = _("{STR_VAR_1} blushes.");
static const u8 sLoveMsg06[] = _("Ah! {STR_VAR_1} se aconchegou\n"
        "em você!");
static const u8 sLoveMsg07[] = _("{STR_VAR_1} olha para você com\n"
        "muito carinho!");
static const u8 sLoveMsg08[] = _("{STR_VAR_1} chegou mais perto\n"
        "de você.");
static const u8 sLoveMsg09[] = _("{STR_VAR_1} está ficando perto\n"
        "dos seus pés.");

const struct FollowerMsgInfo gFollowerLoveMessages[] = {
    {sLoveMsg00, EventScript_FollowerGetCloser},
    {sLoveMsg01},
    {sLoveMsg02, EventScript_FollowerCuddling},
    {sLoveMsg03},
    {sLoveMsg04, EventScript_FollowerCuddling},
    {sLoveMsg05},
    {sLoveMsg06, EventScript_FollowerCuddling},
    {sLoveMsg07},
    {sLoveMsg08, EventScript_FollowerGetCloser},
    {sLoveMsg09},
};

// Unconditional surprised messages
static const u8 sSurpriseMsg00[] = _("{STR_VAR_1} está quase caindo!");
static const u8 sSurpriseMsg01[] = _("{STR_VAR_1} esbarrou em você!");
static const u8 sSurpriseMsg02[] = _("{STR_VAR_1} ainda nao parece\n"
        "acostumado com o próprio nome.");
static const u8 sSurpriseMsg03[] = _("{STR_VAR_1} está olhando lá\n"
        "embaixo.");
static const u8 sSurpriseMsg04[] = _("Seu Pokémon tropeçou e quase\n"
        "caiu!");
static const u8 sSurpriseMsg05[] = _("{STR_VAR_1} sentiu alguma coisa\n"
        "e está uivando!");
static const u8 sSurpriseMsg06[] = _("{STR_VAR_1} parece com as\n"
        "energias renovadas!");
static const u8 sSurpriseMsg07[] = _("{STR_VAR_1} virou de repente e\n"
        "começou a latir!");
static const u8 sSurpriseMsg08[] = _("{STR_VAR_1} virou de repente!");
static const u8 sSurpriseMsg09[] = _("Seu Pokémon se assustou quando\n"
        "você falou com ele de repente!");
static const u8 sSurpriseMsg10[] = _("Snif, snif... Tem uma coisa com\n"
        "cheiro muito bom!");
static const u8 sSurpriseMsg11[] = _("{STR_VAR_1} feels refreshed.");
static const u8 sSurpriseMsg12[] = _("{STR_VAR_1} está cambaleando e\n"
        "parece prestes a cair.");
static const u8 sSurpriseMsg13[] = _("{STR_VAR_1} corre o risco de\n"
        "cair.");
static const u8 sSurpriseMsg14[] = _("{STR_VAR_1} está andando com\n"
        "cuidado.");
static const u8 sSurpriseMsg15[] = _("{STR_VAR_1} está ficando tenso\n"
        "e nervoso.");
static const u8 sSurpriseMsg16[] = _("{STR_VAR_1} sentiu algo\n"
        "estranho e se assustou!");
static const u8 sSurpriseMsg17[] = _("{STR_VAR_1} ficou com medo e\n"
        "se aconchegou em você!");
static const u8 sSurpriseMsg18[] = _("{STR_VAR_1} está sentindo uma\n"
        "presença estranha...");
static const u8 sSurpriseMsg19[] = _("{STR_VAR_1} está ficando tenso\n"
        "e nervoso.");
// Conditional messages, index 20
static const u8 sSurpriseMsg20[] = _("{STR_VAR_1} parece muito\n"
        "surpreso com a chuva!");

const struct FollowerMsgInfo gFollowerSurpriseMessages[] = {
    {sSurpriseMsg00},
    {sSurpriseMsg01, EventScript_FollowerPokingPlayer},
    {sSurpriseMsg02}, {sSurpriseMsg03}, {sSurpriseMsg04}, {sSurpriseMsg05}, {sSurpriseMsg06},
    {sSurpriseMsg07, EventScript_FollowerLookAwayBark},
    {sSurpriseMsg08, EventScript_FollowerLookAway},
    {sSurpriseMsg09},
    {sSurpriseMsg10, EventScript_FollowerLookAround},
    {sSurpriseMsg11}, {sSurpriseMsg12}, {sSurpriseMsg13}, {sSurpriseMsg14}, {sSurpriseMsg15}, {sSurpriseMsg16},
    {sSurpriseMsg17, EventScript_FollowerCuddling},
    {sSurpriseMsg18},
    {sSurpriseMsg19, EventScript_FollowerLookAround},
    {sSurpriseMsg20},
};

// Unconditional curious messages
static const u8 sCuriousMsg00[] = _("Seu Pokémon está procurando\n"
        "alguma coisa ao redor sem parar.");
static const u8 sCuriousMsg01[] = _("Seu Pokémon nao olhou por onde\n"
        "andava e esbarrou em você!");
static const u8 sCuriousMsg02[] = _("Snif, snif! Tem alguma coisa por\n"
        "perto?");
static const u8 sCuriousMsg03[] = _("{STR_VAR_1} está brincando de\n"
        "rolar uma pedrinha.");
static const u8 sCuriousMsg04[] = _("{STR_VAR_1} anda por aí\n"
        "procurando alguma coisa.");
static const u8 sCuriousMsg05[] = _("{STR_VAR_1} está cheirando\n"
        "você.");
static const u8 sCuriousMsg06[] = _("{STR_VAR_1} parece estar com\n"
        "um pouco de dúvida...");

const struct FollowerMsgInfo gFollowerCuriousMessages[] = {
    {sCuriousMsg00, EventScript_FollowerLookAround},
    {sCuriousMsg01, EventScript_FollowerPokingPlayer},
    {sCuriousMsg02}, {sCuriousMsg03},
    {sCuriousMsg04, EventScript_FollowerLookAround},
    {sCuriousMsg05}, {sCuriousMsg06},
};

// Unconditional music messages
static const u8 sMusicMsg00[] = _("{STR_VAR_1} está mostrando sua\n"
        "agilidade!");
static const u8 sMusicMsg01[] = _("{STR_VAR_1} anda por aí com\n"
        "alegria!");
static const u8 sMusicMsg02[] = _("Opa! {STR_VAR_1} começou a\n"
        "dançar de felicidade!");
static const u8 sMusicMsg03[] = _("{STR_VAR_1} acompanha você sem\n"
        "dificuldade!");
static const u8 sMusicMsg04[] = _("{STR_VAR_1} parece querer\n"
        "brincar com você.");
static const u8 sMusicMsg05[] = _("{STR_VAR_1} está saltitando de\n"
        "alegria.");
static const u8 sMusicMsg06[] = _("{STR_VAR_1} está cantarolando.");
static const u8 sMusicMsg07[] = _("{STR_VAR_1} está dando\n"
        "mordidinhas nos seus pés!");
static const u8 sMusicMsg08[] = _("{STR_VAR_1} vira e olha para\n"
        "você.");
static const u8 sMusicMsg09[] = _("{STR_VAR_1} está se esforçando\n"
        "para mostrar sua força!");
static const u8 sMusicMsg10[] = _("Opa! {STR_VAR_1} começou a\n"
        "dançar de felicidade!");
static const u8 sMusicMsg11[] = _("{STR_VAR_1} está alegre!");
static const u8 sMusicMsg12[] = _("{STR_VAR_1} pula por aí sem\n"
        "preocupaçao!");
static const u8 sMusicMsg13[] = _("Your POKéMON seems to be smelling a\nnostalgically familiar scent…");
// Conditional music messages, index 14
static const u8 sMusicMsg14[] = _("{STR_VAR_1} está muito feliz\n"
        "com a chuva.");

const struct FollowerMsgInfo gFollowerMusicMessages[] = {
    {sMusicMsg00, EventScript_FollowerLookAround},
    {sMusicMsg01},
    {sMusicMsg02, EventScript_FollowerDance},
    {sMusicMsg03},
    {sMusicMsg04, EventScript_FollowerHopping},
    {sMusicMsg05, EventScript_FollowerHopping},
    {sMusicMsg06}, {sMusicMsg07}, {sMusicMsg08}, {sMusicMsg09},
    {sMusicMsg10, EventScript_FollowerDance},
    {sMusicMsg11},
    {sMusicMsg12, EventScript_FollowerHopping},
    {sMusicMsg13, EventScript_FollowerNostalgia},
    {sMusicMsg14}
};


static const u8 sPoisonedMsg00[] = _("{STR_VAR_1} está tremendo por\n"
        "causa do veneno.");

const struct FollowerMsgInfo gFollowerPoisonedMessages[] = {
    {sPoisonedMsg00, EventScript_FollowerIsShivering},
};
