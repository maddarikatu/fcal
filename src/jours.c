#include "fcal.h"

// TODO: Add prepositions and articles to names
char *nomjour_fr[366] = {
	"raisin",
	"safran",
	"châtaigne",
	"colchique",
	"cheval",
	"balsamine",
	"carotte",
	"amaranthe",
	"panais",
	"cuve",
	"pomme de terre",
	"immortelle",
	"potiron",
	"réséda",
	"ane",
	"belle de nuit",
	"citrouille",
	"sarrasin",
	"tournesol",
	"pressoir",
	"chanvre",
	"pêche",
	"navet",
	"amarillis",
	"bœuf",
	"aubergine",
	"piment",
	"pomme",
	"céleri",
	"poire",
	"betterave",
	"oie",
	"héliotrope",
	"figue",
	"scorsonère",
	"alisier",
	"charrue",
	"salsifis",
	"macre",
	"topinambour",
	"endive",
	"dindon",
	"chervis",
	"cresson",
	"dentelaire",
	"grenade",
	"herse",
	"bacchante",
	"azerole",
	"garance",
	"orange",
	"faisan",
	"pistache",
	"macjonc",
	"raiponce",
	"turneps",
	"chicorée",
	"nèfle",
	"cochon",
	"mâche",
	"chou-fleur",
	"miel",
	"genièvre",
	"pioche",
	"cire",
	"raifort",
	"cèdre",
	"sapin",
	"chevreuil",
	"ajonc",
	"cyprès",
	"lierre",
	"sabine",
	"hoyau",
	"erable sucré",
	"bruyère",
	"roseau",
	"oseille",
	"grillon",
	"pignon",
	"liège",
	"tomate",
	"orge",
	"tonneau",
	"coing",
	"cormier",
	"rouleau",
	"truffe",
	"olive",
	"pelle",
	"tourbe",
	"houille",
	"bitume",
	"soufre",
	"chien",
	"lave",
	"terre végétale",
	"fumier",
	"salpêtre",
	"fléau",
	"granit",
	"argile",
	"ardoise",
	"grès",
	"lapin chèvre",
	"silex",
	"marne",
	"pierre à chaux",
	"marbre",
	"van",
	"pierre à plâtre",
	"sel",
	"fer",
	"cuivre",
	"chat",
	"etain",
	"plomb",
	"zinc",
	"mercure",
	"crible",
	"lauréole",
	"mousse",
	"fragon",
	"perce neige",
	"taureau",
	"laurier thym",
	"amadouvier",
	"mézéréon",
	"peuplier",
	"coignée",
	"ellébore",
	"brocoli",
	"laurier",
	"avelinier",
	"vache",
	"buis",
	"lichen",
	"if",
	"pulmonaire",
	"serpette",
	"thlaspi",
	"thimèle",
	"chiendent",
	"trainasse",
	"lièvre",
	"guède",
	"noisetier",
	"cyclamen",
	"chélidoine",
	"traineau",
	"tussilage",
	"cornouiller",
	"violier",
	"troëne",
	"bouc",
	"asaret",
	"alaterne",
	"violette",
	"marceau",
	"bêche",
	"narcisse",
	"orme",
	"fumeterre",
	"vélar",
	"chèvre",
	"epinard",
	"doronic",
	"mouron",
	"cerfeuil",
	"cordeau",
	"mandragore",
	"persil",
	"cochiéaria",
	"pâquerette",
	"thon",
	"pissenlit",
	"sylve",
	"capillaire",
	"frêne",
	"plantoir",
	"primevère",
	"platane",
	"asperge",
	"tulipe",
	"poule",
	"bette",
	"bouleau",
	"jonquille",
	"aulne",
	"couvoir",
	"pervenche",
	"charme",
	"morille",
	"hêtre",
	"abeille",
	"laitue",
	"mélèze",
	"cigüe",
	"radis",
	"ruche",
	"gainier",
	"romaine",
	"marronnier",
	"roquette",
	"pigeon",
	"lilas",
	"anémone",
	"pensée",
	"myrtille",
	"greffoir",
	"rose",
	"chêne",
	"fougère",
	"aubépine",
	"rossignol",
	"ancolie",
	"muguet",
	"champignon",
	"hyacinthe",
	"rateau",
	"rhubarbe",
	"sainfoin",
	"bâton d'or",
	"chamerops",
	"ver à soie",
	"consoude",
	"pimprenelle",
	"corbeille d'or",
	"arroche",
	"sarcloir",
	"statice",
	"fritillaire",
	"bourache",
	"valériane",
	"carpe",
	"fusain",
	"civette",
	"buglosse",
	"sénevé",
	"houlette",
	"luzerne",
	"hémérocalle",
	"trèfle",
	"angélique",
	"canard",
	"mélisse",
	"fromental",
	"martagon",
	"serpolet",
	"faux",
	"fraise",
	"bétoine",
	"pois",
	"acacia",
	"caille",
	"œillet",
	"sureau",
	"pavot",
	"tilleul",
	"fouche",
	"barbeau",
	"camomille",
	"chèvre-feuille",
	"caille-lait",
	"tanche",
	"jasmin",
	"verveine",
	"thym",
	"pivoine",
	"chariot",
	"seigle",
	"avoine",
	"oignon",
	"véronique",
	"mulet",
	"romarin",
	"concombre",
	"echalotte",
	"absinthe",
	"faucille",
	"coriandre",
	"artichaut",
	"girofle",
	"lavande",
	"chamois",
	"tabac",
	"groseille",
	"gesse",
	"cerise",
	"parc",
	"menthe",
	"cumin",
	"haricot",
	"orcanète",
	"pintade",
	"sauge",
	"ail",
	"vesce",
	"blé",
	"chalémie",
	"epeautre",
	"bouillon blanc",
	"melon",
	"ivraie",
	"bélier",
	"prêle",
	"armoise",
	"carthame",
	"mûre",
	"arrosoir",
	"panis",
	"salicorne",
	"abricot",
	"basilic",
	"brebis",
	"guimauvre",
	"lin",
	"amande",
	"gentiane",
	"ecluse",
	"carline",
	"câprier",
	"lentille",
	"aunée",
	"loutre",
	"myrte",
	"colza",
	"lupin",
	"coton",
	"moulin",
	"prune",
	"millet",
	"lycoperdon",
	"escourgeon",
	"saumon",
	"tubéreuse",
	"sucrion",
	"apocyn",
	"réglisse",
	"echelle",
	"pastèque",
	"fenouil",
	"epine vinette",
	"noix",
	"truite",
	"citron",
	"cardère",
	"nerprun",
	"tagette",
	"hotte",
	"eglantier",
	"noisette",
	"houblon",
	"sorgho",
	"ecrevisse",
	"bigarade",
	"verge d'or",
	"maïs",
	"marron",
	"panier",
	"de la vertu",
	"du génie",
	"du travail",
	"de l'opinion",
	"des récompenses",
	"de la révolution"
};

char *jour_decade_fr[10] = {
	"primidi",
	"duodi",
	"tridi",
	"quartidi",
	"quintidi",
	"sextidi",
	"septidi",
	"octidi",
	"nonidi",
	"décadi"
};

char *jour_code_fr[10] = {
	"PR",
	"DU",
	"TR",
	"QA",
	"QI",
	"SX",
	"SP",
	"OC",
	"NO",
	"DE"
};

char *saison_fr[4] = {
	"d'automne",
	"du'hivern",
	"de printemps",
	"d'été"
};

char *moins_fr[12] = {
	"vendémiaire",
	"brumaire",
	"frimaire",
	"nivôse",
	"pluviôse",
	"ventôse",
	"germinal",
	"floréal",
	"prairial",
	"messidor",
	"thermidor",
	"fructidor"
};