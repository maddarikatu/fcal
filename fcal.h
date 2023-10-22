#ifndef FCAL_H_
#define FCAL_H_

#define __FCAL_VERSION "0.1-1"

typedef struct {
	int opt_week_numbers,
	    opt_string,
	    opt_years,
	    opt_help,
	    opt_ver,
	    opt_curr;
	int d, m, y;
} args_t;

typedef struct {
	int fr_anne,
		fr_moin,
		fr_decade,
		fr_ajour,
		fr_mjour,
		fr_djour,
		fr_biss;
	char rom[32];
} date_t;

// Calculate if leap year (bissextile)
static inline int biss_bool(int a) { return (a % 4 == 0 && (a % 100 != 0 || a % 400 == 0)); }

/* In araro.c*/
// Make roman numeral string from int n
char *araro(int n, char *dest);

/* In opts.c */
// Argument parser
// Returns args_t table
args_t fcal_opts(int argc, char **argv);

/* In fca.c */
// Returns days since 1er vendémieire 228 as an integer
int args_a_jours(args_t *args);
// struct date_t generaton from days
date_t ger_a_rev(int j);

/* in print.c */
// Print help message to stdout
void print_help(char *argv0);
// Print day string to stdout
void montrer_date(date_t *d);
// Print month calendar
void fr_cal(date_t *d);

#endif // FCAL_H_
