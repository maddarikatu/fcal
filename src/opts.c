#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fcal.h"

//       help (h): -7
//    version (v): -21
// onlystring (s): -14
//     string (S): -18
//      weeks (w): -22
//       year (y): -24
//      years (y): -24

void
fcal_opts_long(char *opt, args_t *args)
{
  switch (strcmp("abcdefghij", opt)) {
    case -7:
      args->opt_help = 1;
      break;
    case -21:
      args->opt_ver = 1;
      break;
    case -14:
      args->opt_string = 1;
      break;
    case -18:
      args->opt_string = 2;
      break;
    case -22:
      args->opt_week_numbers = 1;
      break;
    case -24:
      args->opt_years = 1;
      break;
    case '-':

    default:
      fprintf(stderr, "Unknown option: '%s'.\n", opt);
      exit(1);
  }
}

args_t
fcal_opts(int argc, char **argv)
{
  args_t args = {0};

  // TODO: parser allows flags after date (int[3] -> int[n++] ?)
  int o;
  for (o = 1; argv[o] != NULL && argv[o][0] == '-'; o++) {
    int after_longopt = 0;
    int i = 1;
    while (argv[o][i] && !after_longopt) {
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
        case '-':
          fcal_opts_long(&argv[o][i+1], &args);
          after_longopt = 1;
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
    args.opt_show_day = 1;
    args.opt_curr = 1;

    return args;
  }

  if (argc - o > 3) {
    fprintf(stderr, "Error: too many arguments.\n");
    exit(1);
  }

  if (argc - o >= 1) {
    args.y = atoi(argv[argc-1]);
    if (argc - o == 1) args.opt_years = 1;
  }
  if (argc - o >= 2) args.m = atoi(argv[argc-2]); else args.m = 1;
  if (argc - o == 3) {
    args.d = atoi(argv[argc-3]);
    args.opt_show_day = 1;
  } else {
    args.d = 1;
    args.opt_show_day = 0;
  }

  return args;
}
