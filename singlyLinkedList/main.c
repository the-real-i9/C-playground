#include <stdio.h>

#include "sllist.h"

Sllist *myList;

void cleanup() {
  freeSllist(myList);
}

int main() {
  
  myList = newSllist();
  
  atexit(&cleanup);

  pushFront(myList, 5);  
  pushFront(myList, 7);
  pushFront(myList, 9);
  pushFront(myList, 11);
  int poppedValue = popFront(myList);

  traverse(myList);
  
  printf("Size: %d\n", myList->size);

  printf("Popped value: %d\n", poppedValue);

  int targInd = size(myList) - 1;
  printf("Value at index[%d]: %d\n", targInd, valueAt(myList, targInd));

  return 0;
}