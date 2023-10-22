#include <stdio.h>
#include <stdlib.h>

#include "fcal.h"

args_t
fcal_opts(int argc, char **argv)
{
	args_t args = {0};

	if (argc == 1) {
		args.opt_curr = 1;
		args.opt_show_day = 0;

		return args;
	}

	// TODO: parser allows flags after date (int[3] -> int[n++] ?)
	int o;
	for (o = 1; argv[o] != NULL && argv[o][0] == '-'; o++) {
		int i = 1;
		while (argv[o][i]) {
			switch (argv[o][i]) {
				case 'h':
					args.opt_help = 1;
					break;
				case 'v':
					args.opt_ver = 1;
					break;
				case 's':
					args.opt_string = 1;
					break;
				case 'S':
					args.opt_string = 2;
					break;
				case 'w':
					args.opt_week_numbers = 1;
					break;
				case 'y':
					args.opt_years = 1;
					break;
				default:
					fprintf(stderr, "Unknown option: '%c'.\n", argv[o][i]);
					exit(1);
			}
			i++;
		}
		if (i == 1) {
			fprintf(stderr, "Error: asked for option and then didn't provide one.\n");
			exit(1);
		}
	}

	if (argc > o) {
		args.opt_curr = 0;
	} else {
		args.opt_curr = 1;
		return args;
	}

	if (argc - o > 3) {
		fprintf(stderr, "Error: too many arguments.\n");
		exit(1);
	}

	if (argc - o >= 1) args.y = atoi(argv[argc-1]);
	if (argc - o >= 2) args.m = atoi(argv[argc-2]); else args.m = 1;
	if (argc - o == 3) {
		args.d = atoi(argv[argc-3]);
		args.opt_show_day = 1;
	} else {
		args.d = 1;
		args.opt_show_day = 0;
	}

	if (!args.opt_curr && args.y < 228) {
		fprintf(stderr, "Currently not supporting dates before year 228 (gregorian 2020)\n");
		exit(1);
	}

	return args;
}
