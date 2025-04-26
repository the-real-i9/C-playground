#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

struct sllist {
  struct node *head;
  struct node *tail;
  int length;
};

void free_sllist(struct sllist *list) {
  struct node *current = list->head;
  struct node *next;

  while (current != NULL) {
      next = current->next;
      free(current);
      current = next;
  }

  list->head = NULL;
  list->tail = NULL;
  list->length = 0;
}


void append(struct sllist *list, int value) {

  struct node *newNode = malloc(sizeof(struct node));
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

  // free(newNode);

  list->length = list->length > 0 ? list->length = list->length + 1 : 1;
}