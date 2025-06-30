#include <stdio.h>

#include "sllist.h"

Sllist *myList;

void cleanup() {
  freeSllist(myList);
}

int main() {
  
  myList = newSllist();
  
  atexit(&cleanup);

  append(myList, 5);  
  append(myList, 7);
  append(myList, 9);
  append(myList, 11);
  
  traverse(myList);

  printf("Size -- %d\n", myList->size);

  int targInd = 10;
  printf("Value at index: %d -- %d\n", targInd, valueAt(myList, targInd));

  return 0;
}