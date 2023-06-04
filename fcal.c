#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "fcal.h"
#include "config.h"
#include "jours.h"

void trov_jour(int sec, struct Date *date) {
	int seulj = sec / SECINJ;
	date->fr_anne = seulj / (365.25 * SECINJ) + 1;
	seulj %= (int)365.25 * SECINJ;
	date->fr_moin = seulj / (30 * SECINJ);
	date->fr_ajour = seulj / SECINJ;
	date->fr_decade = date->fr_ajour / 10;
	seulj %= 30 * SECINJ;
	date->fr_mjour = seulj / SECINJ;

	araro(date->fr_anne, date->rom);
}

void trov_heur(int sec, struct Date *date) {
	int seulh = sec % SECINJ;
	date->fr_sec = seulh % 60;
	seulh /= 60;
	date->fr_min = seulh % 60;
	seulh /= 60;
	date->fr_heur = seulh;
}

int main(void) {
	time_t t = time(NULL);

	struct Date *d = malloc(sizeof(struct Date));
	trov_jour((int)t, d);
	trov_heur((int)t, d);

	printf("%s\n", d->rom);
}
