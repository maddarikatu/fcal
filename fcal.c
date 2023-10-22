#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "fcal.h"
#include "config.h"

static int
l_aberration_pour_calculer_les_bissextiles(int j)
{
	// Unironically the same as remainder of 365.24225 but not sure if that messes up some dates :/
	int n = (j % 36524) % 1461;
	
	for (int i = 0; i < 3; i++)
	{
		if (n < 365) break;
		n -= 365;
	}

	return n;
}

date_t
ger_a_rev(int j)
{
	date_t d = {0};
	d.fr_anne = 228 + (j / 365.24225);
	d.fr_biss = biss_bool(d.fr_anne + 1);
	d.fr_ajour = l_aberration_pour_calculer_les_bissextiles(j) - 1;
	d.fr_decade = d.fr_ajour / 10;
	d.fr_moin = d.fr_ajour / 30;
	d.fr_mjour = d.fr_ajour % 30;
	d.fr_djour = d.fr_ajour % 10;

	araro(d.fr_anne + 1, d.rom);

	return d;
}

int
args_a_jours(args_t *args)
{
	return (long)((args->y - 228) * 365.24225 + (args->m - 1) * 30 + args->d);
}

int
main(int argc, char **argv)
{
	args_t args = fcal_opts(argc, argv);
	if (args.opt_help) {
		print_help(argv[0]);
		return 0;
	}

	if (args.opt_ver) {
		printf("%s version %s\n", argv[0], __FCAL_VERSION);
		return 0;
	}

	int j = 0;
	if (args.opt_curr) {
		time_t t = time(NULL);
		struct tm *tm = localtime(&t);
		long tfr = t - 1600646400L + tm->tm_gmtoff;
		j = tfr / 86400;
	} else {
		j = args_a_jours(&args);
	}

	date_t d = ger_a_rev(j);
	if (args.opt_string == 2) {
		montrer_date(&d);
		return 0;
	}
	if (args.opt_years) {
		printf("\033[1m         %d\033[0m\n", d.fr_anne);
		for (int i = 0; i < 13; i++) {
			d.fr_moin = i;
			fr_cal(&d, &args);
		}
	} else {
		fr_cal(&d, &args);
	}

	if (args.opt_string == 1)
		montrer_date(&d);

	return 0;
}
