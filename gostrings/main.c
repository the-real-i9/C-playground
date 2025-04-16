#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>

#include "gostrings.h"

int digitGt(char c) {
  if (isdigit(c)) {
    char numStr[] = {c, '\0'};
    if (atoi(numStr) > 3)
      return 1;
  }

  return 0;
}

int main() {

  char *str = "5,4,3,2,1";

  int test = containsFunc(str, digitGt);

  printf("%d\n", test);

  return 0;
}