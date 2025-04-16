#include <stdio.h>
#include <stdlib.h>

#include "gostrings.h"

int main() {

  char str[] = "Hello World!";
  char substr[] = "x";

  printf("%d\n", contains(str, substr));

  return 0;
}