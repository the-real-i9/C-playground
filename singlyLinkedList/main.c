#include <stdio.h>

#include "sllist.h"

int main() {

  Sllist *myList = newSllist();

  append(myList, 5);  
  append(myList, 7);
  append(myList, 9);
  append(myList, 11);
  
  traverse(myList);

  printf("%d\n", myList->length);

  free_sllist(myList);

  return 0;
}