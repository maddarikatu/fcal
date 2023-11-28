#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "fcal.h"

/* Convert int N into roman numerals in array DEST */
char *araro(int n, char *dest) {
  char *nums[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
  int vals[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

  int i = 0;
  while (n > 0) {
    if (n >= vals[i]) {
      strcat(dest, nums[i]);
      n -= vals[i];
    } else {
      i++;
    }
  }

  return dest;
}
