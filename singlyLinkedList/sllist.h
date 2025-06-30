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

void free_sllist(Sllist *list) {
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

  printf("Finished\n");
}

int size(Sllist *list) {
  return list->size;
}

int empty(Sllist *list) {
  if (list->size)
    return 1;

  return 0;
}

int valueAt(Sllist *list, int index) {
  if (index < 0 || index >= list->size) {
    fputs("error: index specified out of bounds\n", stderr);
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

Sllist *newSllist() {
  Sllist *list = malloc(sizeof(Sllist));

  list->head = NULL;
  list->tail = NULL;
  list->size = 0;

  return list;
}

void append(Sllist *list, int value) {

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

  list->size = list->size > 0 ? list->size = list->size + 1 : 1;
}

void traverse(Sllist *list) {
  Node *current = list->head;

  while (current != NULL) {
    printf("%d\n", current->value);
    current = current->next;
  }
}

