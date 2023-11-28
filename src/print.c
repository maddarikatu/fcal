#include <stdio.h>

#include "fcal.h"

void
print_help(char *argv0) {
	printf("Usage: %s -[hsSvy] [[[day] month] year]\n", argv0);
	printf("\t-h:\tprint this help message.\n");
	printf("\t-s:\tprint date string (after calendar).\n");
	printf("\t-S:\tprint date string (only).\n");
	printf("\t-v:\tprint version.\n\n");
	printf("\t-w:\tprint week numbers.\n");
	printf("\t-y:\tprint the whole year.\n");
}

void
montrer_date(date_t *d)
{
	if (d->fr_moin == 12)
		// fetes
		printf("Aujourd'hui, nous sommes le %s %d de les jours suplementaires, de l'anné %s du calendrier républicain, fête %s\n",
				jour_decade_fr[d->fr_djour], d->fr_mjour + 1, d->rom, nomjour_fr[d->fr_ajour]);
	else
		// non fetes
		printf("Aujourd'hui, nous sommes le %s %d %s, de l'anné %s du calendrier républicain, jour du/de la %s\n",
				jour_decade_fr[d->fr_djour], d->fr_mjour + 1, moins_fr[d->fr_moin], d->rom, nomjour_fr[d->fr_ajour]);
}

void
__fr_cal_fetes(date_t *d, args_t *args, int show_day)
{
	if (args->opt_years) {
		printf("\033[1m         jours supplémentaires\033[0m\n");
	} else {
		printf("\033[1m         jours supplémentaires, anné %d\033[0m\n", d->fr_anne);
	}
	if (args->opt_week_numbers) printf("        | ");
	for (int i = 0; i < 10; i++) printf(" %s ", jour_code_fr[i]);
	putchar('\n');

	if (args->opt_week_numbers) printf("Dec. 37 | ");
	for (int a = 0; a < ((d->fr_biss) ? 6 : 5); a++) {
		if (a == d->fr_mjour && show_day)
			printf(" \033[47;30m%2d\033[0m ", a+1);
		else
			printf(" %2d ", a+1);
	}
	puts("\n");
}

void
fr_cal(date_t *d, args_t *args, int show_day)
{
	if (d->fr_moin == 12) {
		__fr_cal_fetes(d, args, show_day);
		return;
	}
	if (args->opt_years) {
		printf("\033[1m         %s\033[0m\n", moins_fr[d->fr_moin]);
	} else {
		printf("\033[1m         %s, anné %d\033[0m\n", moins_fr[d->fr_moin], d->fr_anne);
	}
	if (args->opt_week_numbers) printf("        | ");
	for (int i = 0; i < 10; i++) printf(" %s ", jour_code_fr[i]);
	putchar('\n');

	for (int i = 0; i < 3; i++) {
		 if (args->opt_week_numbers) printf("Dec. %2d | ", d->fr_moin * 3 + i + 1);
		for (int j = 0; j < 10; j++) {
			int a = j + i*10;
			if (a == d->fr_mjour && show_day)
				printf(" \033[47;30m%2d\033[0m ", a+1);
			else
				printf(" %2d ", a+1);
		}
		putchar('\n');
	}
	putchar('\n');
}
