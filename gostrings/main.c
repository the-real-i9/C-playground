#include <stdio.h>
#include <stdlib.h>

#include "gostrings.h"

int main() {

  char str[] = "Hello World!";

  char theClone[sizeof str];

  clone(theClone, str);

  puts(theClone);

  return 0;
}