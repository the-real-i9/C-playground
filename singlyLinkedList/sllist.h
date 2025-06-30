#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *next;
} Node;

typedef struct sllist {
  struct node *head;
  struct node *tail;
  int size;
} Sllist;

Sllist *newSllist() {
  Sllist *list = malloc(sizeof(Sllist));

  list->head = NULL;
  list->tail = NULL;
  list->size = 0;

  return list;
}

void freeSllist(Sllist *list) {
  Node *current = list->head;
  Node *next;

  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }

  list->head = NULL;
  list->tail = NULL;
  list->size = 0;

  free(list);
}

int size(Sllist *list) {
  return list->size;
}

int empty(Sllist *list) {
  if (list->size)
    return 0;

  return 1;
}

int valueAt(Sllist *list, int index) {
  if (empty(list)) {
    fputs("error: valueAt(): list is empty\n", stderr);
    exit(1);
  }

  if (index < 0 || index >= size(list)) {
    fputs("error: valueAt(): index specified out of bounds\n", stderr);
    exit(1);
  }

  Node *current = list->head;

  int i = 0;
  while (i < index) {
    current = current->next;
    i++;
  }

  return current->value;
}

void pushFront(Sllist *list, int value) {

  Node *newNode = malloc(sizeof(Node));
  newNode->value = value;
  newNode->next = NULL;

  // if list's empty
  if (list->head == NULL) {
    list->head = newNode;
    list->tail = newNode;
  } else {
    list->tail->next = newNode;
    list->tail = newNode;
  }

  list->size = list->size + 1;
}

int popFront(Sllist *list) {
  if (empty(list)) {
    fputs("error: popFront(): list is empty\n", stderr);
    exit(1);
  }

  if (size(list) == 1) {
    Node *frontNode = list->head;

    int frontValue = frontNode->value;

    free(frontNode);
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return frontValue;
  }

  Node *secondToFrontNode = list->head;

  int i = 0;
  while (i < list->size-2) {
    secondToFrontNode = secondToFrontNode->next;

    i++;
  }

  Node *frontNode = secondToFrontNode->next;

  secondToFrontNode->next = NULL;

  int frontValue = frontNode->value;

  free(frontNode);

  list->size = list->size - 1;

  return frontValue;
}

void traverse(Sllist *list) {
  Node *current = list->head;

  while (current != NULL) {
    printf("%d\n", current->value);
    current = current->next;
  }
}

