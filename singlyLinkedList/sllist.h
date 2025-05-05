#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *next;
} Node;

typedef struct sllist {
  struct node *head;
  struct node *tail;
  int length;
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
  list->length = 0;
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

  list->length = list->length > 0 ? list->length = list->length + 1 : 1;
}

void traverse(Sllist *list) {
  Node *current = list->head;

  while (current != NULL) {
    printf("%d\n", current->value);
    current = current->next;
  }
}