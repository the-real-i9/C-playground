#include <stddef.h>
#include <stdio.h>

struct node {
  int value;
  struct node *next;
};

struct sllist {
  struct node *head;
  struct node *tail;
  int length;
};

void append(struct sllist *list, struct node *newNode) {

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