#include <stdio.h>
#include <stdlib.h>

#include "fcal.h"

args_t
fcal_opts(int argc, char **argv)
{
  args_t args = {0};

  if (argc == 1) {
    args.opt_curr = 1;
    args.opt_string = 1;

    return args;
  }

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

  switch (argc - o) {
    case 3: {
      args.d = atoi(argv[o]);
      args.m = atoi(argv[o+1]);
      args.y = atoi(argv[o+2]);
      args.opt_curr = 0;
    } break;
    case 2: {
	  args.d = 1;
      args.m = atoi(argv[o]);
      args.y = atoi(argv[o+1]);
      args.opt_curr = 0;
    } break;
    case 1: {
	  args.d = 1;
	  args.m = 1;
      args.y = atoi(argv[o]);
      args.opt_curr = 0;
    } break;
    case 0:
      args.opt_curr = 1;
      break;
    default: {
      fprintf(stderr, "Error: too many arguments.\n");
      exit(1);
    } break;
  }

  if (!args.opt_curr && args.y < 228) {
    fprintf(stderr, "Currently not supporting dates before year 228 (gregorian 2020)\n");
    exit(1);
  }

  return args;
}
