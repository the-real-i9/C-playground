#include <stdio.h>
#include <stdlib.h>

typedef void * any_t;

typedef struct node {
  any_t value;
  struct node *next;
} node_t;

typedef struct sllist {
  node_t *head;
  node_t *tail;
  int size;
} sllist_t;

sllist_t *newSllist() {
  sllist_t *list = malloc(sizeof(sllist_t));

  list->head = NULL;
  list->tail = NULL;
  list->size = 0;

  return list;
}

node_t *newNode(any_t value) {
  node_t *node = malloc(sizeof(node_t));
  node->value = value;
  node->next = NULL;

  return node;
}

void freeSllist(sllist_t *list) {
  node_t *current = list->head;
  node_t *next;

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

int size(sllist_t *list) {
  return list->size;
}

int empty(sllist_t *list) {
  if (size(list))
    return 0;

  return 1;
}

any_t valueAt(sllist_t *list, int index) {
  if (empty(list)) {
    fputs("error: valueAt(): list is empty\n", stderr);
    exit(1);
  }

  if (index < 0 || index >= size(list)) {
    fputs("error: valueAt(): index specified out of bounds\n", stderr);
    exit(1);
  }

  node_t *current = list->head;

  int i = 0;
  while (i < index) {
    current = current->next;
    i++;
  }

  return current->value;
}

void pushFront(sllist_t *list, any_t value) {

  node_t *node = newNode(value);

  if (list->head == NULL) {
    list->head = node;
    list->tail = node;
  } else {
    node->next = list->head;
    list->head = node;
  }

  list->size = size(list) + 1;
}

any_t popFront(sllist_t *list) {
  if (empty(list)) {
    fputs("error: popFront(): list is empty\n", stderr);
    exit(1);
  }

  if (size(list) == 1) {
    node_t *frontNode = list->head;

    any_t frontValue = frontNode->value;

    free(frontNode);
    
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return frontValue;
  }

  node_t *frontNode = list->head;

  list->head = frontNode->next;

  any_t frontValue = frontNode->value;

  free(frontNode);

  list->size = size(list) - 1;

  return frontValue;
}

void pushBack(sllist_t *list, any_t value) {

  node_t *node = newNode(value);

  // if list's empty
  if (list->head == NULL) {
    list->head = node;
    list->tail = node;
  } else {
    list->tail->next = node;
    list->tail = node;
  }

  list->size = size(list) + 1;
}

any_t popBack(sllist_t *list) {
  if (empty(list)) {
    fputs("error: popBack(): list is empty\n", stderr);
    exit(1);
  }

  if (size(list) == 1) {
    node_t *backNode = list->head;

    any_t backValue = backNode->value;

    free(backNode);
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return backValue;
  }

  node_t *secondToBackNode = list->head;

  while (secondToBackNode->next->next != NULL) {
    secondToBackNode = secondToBackNode->next;

  }

  node_t *oldBackNode = secondToBackNode->next;

  secondToBackNode->next = NULL;

  list->tail = secondToBackNode;

  any_t oldBackValue = oldBackNode->value;

  free(oldBackNode);

  list->size = size(list) - 1;

  return oldBackValue;
}

any_t front(sllist_t *list) {
  return list->head->value;
}

any_t back(sllist_t *list) {
  return list->tail->value;
}

void insert(sllist_t *list, int index, any_t value) {
  if (index > size(list)) {
    fputs("error: insert(): index out of bounds\n", stderr);
    exit(1);
  }

  if (index == size(list)) {
    pushBack(list, value);

    return;
  }

  if (index == 0) {
    pushFront(list, value);

    return;
  }

  node_t *node = newNode(value);

  node_t *nodeBeforeIndex = list->head;
  node_t *nodeAtIndex = nodeBeforeIndex->next;

  int i = 0;
  while (i < index - 1) {
    nodeBeforeIndex = nodeAtIndex;
    nodeAtIndex = nodeBeforeIndex->next;

    i++;
  }

  node->next = nodeAtIndex;
  nodeBeforeIndex->next = node;

  list->size = size(list) + 1;
}

void erase(sllist_t *list, int index) {
  if (index > size(list)) {
    fputs("error: insert(): index out of bounds\n", stderr);
    exit(1);
  }

  if (index == size(list)) {
    popBack(list);

    return;
  }

  if (index == 0) {
    popFront(list);

    return;
  }

  node_t *nodeBeforeIndex = list->head;
  node_t *nodeAtIndex = nodeBeforeIndex->next;

  int i = 0;
  while (i < index - 1) {
    nodeBeforeIndex = nodeAtIndex;
    nodeAtIndex = nodeBeforeIndex->next;

    i++;
  }

  nodeBeforeIndex->next = nodeAtIndex->next;

  free(nodeAtIndex);

  list->size = size(list) - 1;
}

any_t valueAtEnd(sllist_t *list, int index) {
  int resolvedIndex = (size(list) - 1) - index;

  if (resolvedIndex < 0 || resolvedIndex >= size(list)) {
    fputs("error: valueAtEnd(): index out of bounds\n", stderr);
    exit(1);
  }

  return valueAt(list, resolvedIndex);
}

void reverse(sllist_t *list) {
  node_t *travNode = list->head;

  node_t *workNode;

  int listSize = size(list);

  int i = 0;
  while (i < listSize) {
    node_t *currNode = travNode;
    node_t *nNode = newNode(currNode->value);
    if (i > 0) {
      nNode->next = workNode;
    } else {
      list->tail = nNode;
    }
    
    workNode = nNode;
    travNode = currNode->next;

    free(currNode);

    i++;
  }
  
  list->head = workNode;
}

any_t *toArray(sllist_t *list) {
  any_t *arr = malloc(size(list) * sizeof(any_t));

  node_t *current = list->head;

  int i = 0;
  while (current != NULL) {
    *(arr + i) = current->value;

    current = current->next;

    i++;
  }

  return arr;
}

