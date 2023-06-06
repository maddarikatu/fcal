#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "fcal.h"
#include "config.h"
#include "jours.h"

struct Date *faire_date(int sec) {
	struct Date *new = malloc(sizeof(struct Date));

	int jou = sec / SECINJ;
	jou += UNIX_LEAP;

	new->fr_anne = jou / 365.25 + UNIX_LEAP_ANNE + 1;
	if (new->fr_anne % 4) {
		if (!(new->fr_anne % 100)) {
			if (new->fr_anne % 400) {
				new->fr_biss = 1;
			} else {
				new->fr_biss = 0;
			}
		} else {
			new->fr_biss = 1;
		}
	}

	return new;
}

int main(void) {
	time_t t = time(NULL);

	struct Date *d = faire_date(t);

	printf("%s\n", d->rom);
}
