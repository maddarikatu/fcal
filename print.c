#include <stdio.h>

#include "fcal.h"
#include "jours.h"

void
print_help(char *argv0) {
	printf("Usage: %s -[hsSvy] [[[day] month] year]\n", argv0);
	printf("\t-h:\tprint this help message.\n");
	printf("\t-s:\tprint date string (after calendar).\n");
	printf("\t-S:\tprint date string (only).\n");
	printf("\t-v:\tprint version.\n\n");
	printf("\t-y:\tprint the whole year.\n");
}

void
montrer_date(date_t *d)
{
	if (d->fr_moin == 12)
		// fetes
		printf("Aujourd'hui, nous sommes le %s %d de les jours suplementaires du calendrier républicain, fête %s\n",
				jour_decade[d->fr_djour], d->fr_mjour + 1, nomjour[d->fr_ajour]);
	else
		// non fetes
		printf("Aujourd'hui, nous sommes le %s %d %s, de l'anné %s du calendrier républicain, jour du/de la %s\n",
				jour_decade[d->fr_djour], d->fr_mjour + 1, moins[d->fr_moin], d->rom, nomjour[d->fr_ajour]);
}

void
__fr_cal_fetes(date_t *d, args_t *args)
{
	if (args->opt_years) {
		printf("\033[1m         jours supplémentaires\033[0m\n");
	} else {
		printf("\033[1m         jours supplémentaires, anné %d\033[0m\n", d->fr_anne);
	}
	printf("        | ");
	for (int i = 0; i < 10; i++) printf(" %s ", jour_code[i]);
	putchar('\n');

	printf("Dec. 37 | ");
	for (int a = 0; a < ((d->fr_biss) ? 6 : 5); a++) {
		if (a == d->fr_mjour && args->opt_show_day && d->fr_moin == args->m - 1)
			printf(" \033[47;30m%2d\033[0m ", a+1);
		else
			printf(" %2d ", a+1);
	}
	puts("\n");
}

void
fr_cal(date_t *d, args_t *args)
{
	if (d->fr_moin == 12) {
		__fr_cal_fetes(d, args);
		return;
	}
	if (args->opt_years) {
		printf("\033[1m         %s\033[0m\n", moins[d->fr_moin]);
	} else {
		printf("\033[1m         %s, anné %d\033[0m\n", moins[d->fr_moin], d->fr_anne);
	}
	printf("        | ");
	for (int i = 0; i < 10; i++) printf(" %s ", jour_code[i]);
	putchar('\n');

	for (int i = 0; i < 3; i++) {
		printf("Dec. %2d | ", d->fr_moin * 3 + i + 1);
		for (int j = 0; j < 10; j++) {
			int a = j + i*10;
			if (a == d->fr_mjour && args->opt_show_day && d->fr_moin == args->m - 1)
				printf(" \033[47;30m%2d\033[0m ", a+1);
			else
				printf(" %2d ", a+1);
		}
		putchar('\n');
	}
	putchar('\n');
}
