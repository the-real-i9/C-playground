#include <stdio.h>

#include "sllist.h"

sllist_t *myList;

void cleanup() {
  freeSllist(myList);
}

int main() {
  
  myList = newSllist();
  
  atexit(&cleanup);

  pushBack(myList, (any_t)(__int64_t) 2);
  pushBack(myList, (any_t)(__int64_t) 4);
  pushBack(myList, (any_t)(__int64_t) 6);
  pushBack(myList, (any_t)(__int64_t) 9);
  __int64_t poppedBackValue = (__int64_t) popBack(myList);
  __int64_t poppedFrontValue = (__int64_t) popFront(myList);

  insert(myList, 2, (any_t)(__int64_t) 7);
  insert(myList, 1, (any_t)(__int64_t) 5);
  insert(myList, size(myList), (any_t)(__int64_t) 8);
  insert(myList, 0, (any_t)(__int64_t) 3);
  
  erase(myList, 2);
  // traverse myList;
  
  any_t *myListArr = toArray(myList);
  int i = 0;
  while (i < size(myList)) {
    printf("%ld\n", (__int64_t) myListArr[i]);

    i++;
  }
  free(myListArr);
  
  printf("Size: %d\n", size(myList));

  printf("Popped back value: %ld\n", poppedBackValue);
  printf("Popped front value: %ld\n", poppedFrontValue);

  int targInd = size(myList) - 1;
  printf("Value at index[%d]: %ld\n", targInd, (__int64_t) valueAt(myList, targInd));

  int targEndInd = 1;
  printf("Value at end index[%d]: %ld\n", targEndInd, (__int64_t) valueAtEnd(myList, targEndInd));

  return 0;
}