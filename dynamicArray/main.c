#include <stdio.h>
#include "dyarray_t.h"

DyArray *newDyArray();
void free_DyArray(DyArray *arr);
void push(DyArray *arr, int item);
void traverse(DyArray *arr);
int pop(DyArray *arr);

int main(int argc, char const *argv[]) {
  
  DyArray *myArray = newDyArray();

  push(myArray, 1);
  push(myArray, 2);
  push(myArray, 3);
  push(myArray, 4);
  push(myArray, 5);
  push(myArray, 6);
  push(myArray, 7);
  push(myArray, 8);
  push(myArray, 9);
  push(myArray, 10);
  push(myArray, 11);
  push(myArray, 12);
  push(myArray, 13);
  push(myArray, 14);
  push(myArray, 15);
  push(myArray, 16);
  pop(myArray);
  pop(myArray);
  pop(myArray);
  pop(myArray);
  pop(myArray);
  pop(myArray);
  pop(myArray);
  pop(myArray);
  pop(myArray);

  traverse(myArray);

  printf("\nSize: %d. Capacity: %d\n", myArray->size, myArray->cap);

  free_DyArray(myArray);
  
  return 0;
}
