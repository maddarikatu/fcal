#define UNIX	"11 Nivôse CLXXVIII"
#define UNIX_LEAP	259
#define SECINJ	86400

struct Date {
	int fr_anne, fr_moin, fr_decade,
		fr_ajour, fr_mjour,
		fr_heur, fr_min, fr_sec;
	char rom[32];
};

/* const char jour_decade[10][9] = {
	"primidi",
	"duodi",
	"tridi",
	"quartidi",
	"quintidi",
	"sextidi",
	"octidi",
	"nonidi",
	"décadi"
};

const char moins[12][13] = {
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
}; */

char *araro(int n, char *dest);
