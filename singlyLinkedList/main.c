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
  int poppedFrontValue = popFront(myList);
  int poppedBackValue = popBack(myList);

  traverse(myList);
  
  printf("Size: %d\n", myList->size);

  printf("Popped front value: %d\n", poppedFrontValue);
  printf("Popped back value: %d\n", poppedBackValue);

  int targInd = size(myList) - 1;
  printf("Value at index[%d]: %d\n", targInd, valueAt(myList, targInd));

  return 0;
}