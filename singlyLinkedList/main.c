#include <stdio.h>

#include "sllist.h"



int main() {

  struct sllist myList;

  myList.length = 0;

  struct node node1 = {5};
  append(&myList, &node1);
  
  struct node node2 = {7};
  append(&myList, &node2);
  
  printf("%d\n", myList.head->value);
  printf("%d\n", myList.head->next->value);

  printf("%d\n", myList.length);

  return 0;
}