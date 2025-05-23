#include <stdio.h>
#include "dyarray_t.h"

DyArray *newDyArray();
void free_DyArray(DyArray *arr);
void push(DyArray *arr, int item);
void traverse(DyArray *arr);
int pop(DyArray *arr);
void insert(DyArray *arr, int index, int item);
void prepend(DyArray *arr, int item);
void delete(DyArray *arr, int index);

int main(int argc, char const *argv[]) {
  
  DyArray *myArray = newDyArray();

  push(myArray, 2);
  push(myArray, 4);
  insert(myArray, 1, 3);
  insert(myArray, 3, 5);
  prepend(myArray, 1);
  delete(myArray, 0);
  delete(myArray, 3);
  

  traverse(myArray);

  printf("Size: %d. Capacity: %d\n", myArray->size, myArray->cap);

  free_DyArray(myArray);
  
  return 0;
}
