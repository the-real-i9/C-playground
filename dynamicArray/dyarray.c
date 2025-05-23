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
    fprintf(stderr, "error at at(): index specified is out of bounds\n");
    abort();
  }

  return *(arr->data + index);
}

void push(DyArray *arr, int item) {
  if (arr->size == arr->cap) {
    resize(arr, arr->cap * 2);
  }

  *(arr->data + arr->size) = item;

  arr->size = arr->size + 1;
}

int pop(DyArray *arr) {
  if (!arr->size) {
    fprintf(stderr, "error at pop(): array is empty\n");
    abort();
  }

  if (arr->size == arr->cap / 4) {
    resize(arr, arr->cap / 2);
  }

  int lastItem =  *(arr->data + (arr->size - 1));

  arr->size = arr->size - 1;

  return lastItem;
}

void insert(DyArray *arr, int index, int item) {
  if (index > arr->size) {
    fprintf(stderr, "error at insert(): index can't be greater than size of array\n");
    abort();
  }

  if (arr->size == arr->cap) {
    resize(arr, arr->cap * 2);
  }

  // if index = 0, and arr->size = 1

  int targetIndex = index; // e.g. index 0
  int promoteToNextIndex = arr->size; // e.g. index 1

  while (promoteToNextIndex > targetIndex) { // index 1 > index 0
    int toPromoteIndex = promoteToNextIndex - 1; // index 0

    // item at index 0, is promoted to item at index 1
    *(arr->data + promoteToNextIndex) = *(arr->data + toPromoteIndex);

    // index 1 is now index 0, equal to target index
    // the loop will stop, index 0 is not free to be occupied
    promoteToNextIndex--;
  }

  *(arr->data + index) = item;

  arr->size = arr->size + 1;
}

void prepend(DyArray *arr, int item) {
  insert(arr, 0, item);
}

void delete(DyArray *arr, int index) {
  if (!arr->size) {
    fprintf(stderr, "error at delete(): array is empty\n");
    abort();
  }

  if (index >= arr->size) {
    fprintf(stderr, "error at delete(): index specified is out of bounds\n");
    abort();
  }

  if (index == arr->size - 1) {
    pop(arr);
    return;
  }

  if (arr->size == arr->cap / 4) {
    resize(arr, arr->cap / 2);
  }

  int demoteToPrevIndex = index;

  while (demoteToPrevIndex < arr->size - 1) {
    int toDemoteIndex = demoteToPrevIndex + 1;

    *(arr->data + demoteToPrevIndex) = *(arr->data + toDemoteIndex);

    demoteToPrevIndex++;
  }

  arr->size = arr->size - 1;
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
