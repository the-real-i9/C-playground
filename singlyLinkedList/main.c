#include <stdio.h>

#include "sllist.h"



int main() {

  struct sllist myList = {NULL, NULL, 0};

  append(&myList, 5);
  
  append(&myList, 7);
  
  printf("%d\n", myList.head->value);
  printf("%d\n", myList.head->next->value);

  printf("%d\n", myList.length);

  free_sllist(&myList);

  return 0;
}