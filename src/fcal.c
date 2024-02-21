#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#include "fcal.h"
#include "config.h"

static int
l_aberration_pour_calculer_les_bissextiles(int j)
{
  // Unironically the same as remainder of 365.24225 but not sure if that messes up some dates :/
  int n = ((j % 146097) % 36524) % 1461;

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
  d.fr_anne = MIN_YEAR + (j / 365.24225);
  d.fr_biss = biss_bool(d.fr_anne);
  d.fr_ajour = l_aberration_pour_calculer_les_bissextiles(j) - 1;
  // if (!d.fr_biss) d.fr_ajour--;
  d.fr_decade = d.fr_ajour / 10;
  d.fr_moin = d.fr_ajour / 30;
  d.fr_mjour = d.fr_ajour % 30;
  d.fr_djour = d.fr_ajour % 10;

  araro(d.fr_anne, d.rom);

  return d;
}

  date_t
args_a_rev(args_t *args)
{
  date_t d = {0};

  d.fr_anne = args->y;
  d.fr_biss = biss_bool(args->y);
  d.fr_moin = args->m - 1;
  d.fr_mjour = args->d - 1;
  d.fr_ajour = (d.fr_moin + 1) * 30 + d.fr_mjour + 1;
  d.fr_djour = d.fr_mjour % 10;

  araro(d.fr_anne, d.rom);

  return d;
}

  int
args_a_jours(args_t *args)
{
  return (long)((args->y - MIN_YEAR) * 365.24225 + (args->m - 1) * 30 + args->d);
}

  int
main(int argc, char **argv)
{
  setlocale(LC_ALL, "fr_FR-UTF.8");
  // TODO: fix 5 and 6 of supplementary days
  args_t args = fcal_opts(argc, argv);
  if (fcal_test_opt(&args, FCAL_OPT_HELP)) {
    print_help(argv[0]);
    return 0;
  }

  if (fcal_test_opt(&args, FCAL_OPT_VERS)) {
    printf("%s version %s\n", argv[0], __FCAL_VERSION);
    return 0;
  }

  date_t d;
  if (fcal_test_opt(&args, FCAL_OPT_CURR)) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    long tfr = t - 1569025800L + tmoff(tm);
    d = ger_a_rev(tfr / 86400);
  } else {
    d = args_a_rev(&args);
  }

  if (fcal_test_opt(&args, FCAL_OPT_STRO)) {
    montrer_date(&d);
    return 0;
  }
  if (fcal_test_opt(&args, FCAL_OPT_YEAR)) {
    printf("\033[1m         %d\033[0m\n", d.fr_anne);
    int d_fr_moin = d.fr_moin;
    for (int i = 0; i < 13; i++) {
      d.fr_moin = i;
      fr_cal(&d, &args, (fcal_test_opt(&args, FCAL_OPT_HDAY) && d_fr_moin == i));
    }
  } else {
    fr_cal(&d, &args, fcal_test_opt(&args, FCAL_OPT_HDAY));
  }

  if (fcal_test_opt(&args, FCAL_OPT_STRC))
    montrer_date(&d);

  return 0;
}
