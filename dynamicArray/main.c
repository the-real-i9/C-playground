#include <stdio.h>
#include "dyarray_t.h"

DyArray *newDyArray();
void free_DyArray(DyArray *arr);
int size(DyArray *arr);
int capacity(DyArray *arr);
void pushItem(DyArray *arr, int item);
void traverse(DyArray *arr);
int pop(DyArray *arr);
void insertItem(DyArray *arr, int index, int item);
void prependItem(DyArray *arr, int item);
void deleteIndex(DyArray *arr, int index);
void removeItem(DyArray *arr, int item);
int findItem(DyArray *arr, int item);

int main(int argc, char const *argv[]) {
  
  DyArray *myArray = newDyArray();

  pushItem(myArray, 2);
  pushItem(myArray, 4);
  insertItem(myArray, 1, 3);
  pushItem(myArray, 9);
  insertItem(myArray, 3, 5);
  pushItem(myArray, 9);
  prependItem(myArray, 1);
  pushItem(myArray, 9);
  deleteIndex(myArray, 0);
  pushItem(myArray, 9);
  deleteIndex(myArray, 3);
  pop(myArray);
  pushItem(myArray, 9);

  removeItem(myArray, 9);

  
  traverse(myArray);
  
  printf("Size: %d. Capacity: %d\n", size(myArray), capacity(myArray));
  
  int item = 5;
  int foundIndex = findItem(myArray, item);
  if (foundIndex < 0) {
    printf("Item %d not found\n", item);
  } else {
    printf("Item %d found at Index %d\n", item, foundIndex);
  }
  
  free_DyArray(myArray);
  
  return 0;
}
