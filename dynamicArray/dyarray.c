#include <stdlib.h>
#include <stdio.h>

#include "dyarray_t.h"

DyArray *newDyArray() {
  DyArray *newDyArr = (DyArray*)malloc(sizeof(DyArray));

  int initCap = 16;

  newDyArr->data = (int*)malloc(initCap * sizeof(int));
  newDyArr->size = 0;
  newDyArr->cap = initCap;

  return newDyArr;
}

void free_DyArray(DyArray *arr) {
  free(arr->data);

  arr->data = NULL;
  arr->size = 0;
  arr->cap = 0;
  
  free(arr);
}

static void resize(DyArray *arr, int newCap) {
  int *newDataArray = (int*)malloc(newCap * sizeof(int));

  // loop over the old arr->data
  int i = 0;
  while (i < arr->size) {
    int item = *(arr->data + i);

    // copy the items into the new array
    *(newDataArray + i) = item;

    i++;
  }
  
  // free the old arr->data
  free(arr->data);

  // update arr properties
  arr->data = newDataArray;
  arr->cap = newCap;
}

int at(DyArray *arr, int index) {
  if (index >= arr->size) {
    fprintf(stderr, "index specified is out of bounds: in function at()");
    abort();
  }

  return *(arr->data + index);
}

void push(DyArray *arr, int item) {
  if (arr->size + 1 == arr->cap) {
    resize(arr, arr->cap * 2);
  }

  *(arr->data + arr->size) = item;

  arr->size = arr->size + 1;
}

int pop(DyArray *arr) {
  if (!arr->size) {
    fprintf(stderr, "calling pop() on an empty array");
    abort();
  }

  if (arr->size == arr->cap / 4) {
    resize(arr, arr->cap / 2);
  }

  int lastItem =  *(arr->data + (arr->size - 1));

  arr->size = arr->size - 1;

  return lastItem;
}

int size(DyArray *arr) {
  return arr->size;
}

int capacity(DyArray *arr) {
  return arr->cap;
}

int is_empty(DyArray *arr) {
  if (arr->size) {
    return 0;
  }
  
  return 1;
}

void traverse(DyArray *arr) {
  int i = 0;

  while (i < arr->size) {
    printf("Index %d --- Item: %d\n", i, *(arr->data + i));

    i++;
  }
}
