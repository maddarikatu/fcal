#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fcal.h"

int
fcal_set_opt(args_t *args, char option)
{
  args->opts |= option;

  return args->opts;
}

int
fcal_unset_opt(args_t *args, char option)
{
  args->opts &= ~option;

  return args->opts;
}

int
fcal_test_opt(args_t *args, char option)
{
  return (args->opts & option);
}

//       help (h): -7
//    version (v): -21
// onlystring (s): -14
//     string (S): -18
//      weeks (w): -22
//       year (y): -24
//      years (y): -24

static inline void
opt_unknown(char *opt)
{
  fprintf(stderr, "Unknown option: '%s'.\n", opt);
  exit(1);
}

void
fcal_opts_long(char *opt, args_t *args)
{
#ifdef WIN32
  (void)opt;
  (void)args;
  fprintf(stderr, "Long options are not supported on Windows.\n");
  exit(1);
#else
  switch (strcmp("abcdefghij", opt)) {
    case -7:
      if (strcmp(opt, "help") == 0) fcal_set_opt(args, FCAL_OPT_HELP); else opt_unknown(opt);
      break;
    case -21:
      if (strcmp(opt, "version") == 0) fcal_set_opt(args, FCAL_OPT_VERS); else opt_unknown(opt);
      break;
    case -14:
      if (strcmp(opt, "onlystring") == 0) {
        fcal_set_opt(args, FCAL_OPT_STRC);
        fcal_unset_opt(args, FCAL_OPT_STRO);
      } else {
        opt_unknown(opt);
      }
      break;
    case -18:
      if (strcmp(opt, "string") == 0) {
        fcal_set_opt(args, FCAL_OPT_STRO);
        fcal_unset_opt(args, FCAL_OPT_STRC);
      } else {
        opt_unknown(opt);
      }
      break;
    case -22:
      if (strcmp(opt, "weeks") == 0) fcal_set_opt(args, FCAL_OPT_WEEK); else opt_unknown(opt);
      break;
    case -24:
      if (strcmp(opt, "year") == 0) fcal_set_opt(args, FCAL_OPT_YEAR); else opt_unknown(opt);
      break;
    default:
      opt_unknown(opt);
  }
#endif
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
          fcal_set_opt(&args, FCAL_OPT_HELP);
          break;
        case 'v':
          fcal_set_opt(&args, FCAL_OPT_VERS);
          break;
        case 's':
          fcal_set_opt(&args, FCAL_OPT_STRC);
          fcal_unset_opt(&args, FCAL_OPT_STRO);
          break;
        case 'S':
          fcal_set_opt(&args, FCAL_OPT_STRO);
          fcal_unset_opt(&args, FCAL_OPT_STRC);
          break;
        case 'w':
          fcal_set_opt(&args, FCAL_OPT_WEEK);
          break;
        case 'y':
          fcal_set_opt(&args, FCAL_OPT_YEAR);
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
    fcal_unset_opt(&args, FCAL_OPT_CURR);
  } else {
    fcal_set_opt(&args, FCAL_OPT_HDAY);
    fcal_set_opt(&args, FCAL_OPT_CURR);

    return args;
  }

  if (argc - o > 3) {
    fprintf(stderr, "Error: too many arguments.\n");
    exit(1);
  }

  if (argc - o >= 1) {
    args.y = atoi(argv[argc-1]);
    if (argc - o == 1) fcal_set_opt(&args, FCAL_OPT_YEAR);
  }
  if (argc - o >= 2) args.m = atoi(argv[argc-2]); else args.m = 1;
  if (argc - o == 3) {
    args.d = atoi(argv[argc-3]);
    fcal_set_opt(&args, FCAL_OPT_HDAY);
  } else {
    args.d = 1;
    fcal_unset_opt(&args, FCAL_OPT_HDAY);
  }

  return args;
}
