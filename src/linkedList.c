#include "../include/linkedList.h"

struct linkedList *createNode(void *data) {
  struct linkedList *linkedList = (struct linkedList *)malloc(sizeof(struct linkedList));
  if (linkedList == NULL) {
    perror("Memory allocatin failed.\n");
    exit(1);
  }

  linkedList->head = (struct node *)malloc(sizeof(struct node)); 
  if (linkedList->head == NULL) {
    perror("Memory allocation failed.\n");
    free(linkedList);
    exit(1);
  }

  linkedList->head->data = data;
  linkedList->head->prevNode = NULL;
  linkedList->head->nextNode = NULL;

  return linkedList;
}

int compareNode(struct node *fNode, struct node *sNode) {
  if (fNode->data == sNode->data && fNode->nextNode == sNode->nextNode &&
      fNode->prevNode == sNode->prevNode)
    return 1;

  return 0;
}

int count(struct linkedList *ll) {
  int count = 0;
  struct node *head = ll->head;
  while (head->nextNode != NULL) {
    count++;
    head->nextNode = head->nextNode->nextNode;
  }

  return count;
}

void insertToBegin(struct linkedList *ll, void *data) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->prevNode = NULL;
  newNode->nextNode = ll->head;

  ll->head->prevNode = newNode;
}

void insertToEnd(struct linkedList *ll, void *data) {
  struct node *currentNode = ll->head;

  while (currentNode->nextNode != NULL)
    currentNode = currentNode->nextNode;

  struct node *newNode =
      (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->prevNode = currentNode;
  newNode->nextNode = NULL;

  currentNode->nextNode = newNode;
}

void insertAtPosition(struct linkedList *ll, int position, void *data) {
  struct node *newNode =
      (struct node *)malloc(sizeof(struct node));
  if (newNode == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }

  if (position == 0) {
    insertToBegin(ll, data);
  } else {
    struct node *currentNode = ll->head;
    int currentPosition = 0;

    while (currentNode != NULL && currentPosition < position - 1) {
      currentPosition++;
      currentNode = currentNode->nextNode;
    }

    if (currentNode == NULL) {
      fprintf(stderr, "Invalid position for insertion\n");
      exit(1);
    }
    newNode->data = data;
    newNode->nextNode = currentNode->nextNode;
    newNode->prevNode = currentNode;

    currentNode->nextNode = newNode;
  }
}

int getNodePosition(struct linkedList *ll, struct node *targetNode) {
  int i = 0;
  struct node *currentNode = ll->head;

  if (compareNode(currentNode, targetNode))
    return i;

  while (currentNode->nextNode != NULL) {
    if (compareNode(currentNode, targetNode))
      return i;

    currentNode = currentNode->nextNode;
    i++;
  }
}

void removeAtBegin(struct linkedList *ll) {
  ll->head = ll->head->nextNode;
  free(ll->head->prevNode);
  ll->head->prevNode = NULL;
}

void removeAtEnd(struct linkedList *ll) {
  struct node *currentNode = ll->head;
  while (currentNode->nextNode->nextNode != NULL)
    currentNode = currentNode->nextNode;

  free(currentNode->nextNode);
  currentNode->nextNode = NULL;
}

void removeNode(struct linkedList *ll, struct node *targetNode) {
  struct node *currentNode = ll->head;

  if (compareNode(currentNode, targetNode)) {
    removeAtBegin(ll);
    return;
  }

  if (currentNode->prevNode == NULL && currentNode->nextNode == NULL) {
    freeLinkedList(ll);
    return;
  }

  while (currentNode->nextNode != NULL) {
    if (compareNode(currentNode, targetNode)) {
      if (currentNode->prevNode != NULL && currentNode->nextNode != NULL) {
        currentNode->nextNode->prevNode = currentNode->prevNode;
        currentNode->prevNode->nextNode = currentNode->nextNode;
      }
      if (currentNode->nextNode == NULL)
        currentNode->prevNode->nextNode = NULL;

      free(currentNode);
      return;
    }
  }
}

void freeLinkedList(struct linkedList *ll) {
  struct node *currentNode = ll->head;
  struct node *nextNode;

  while (currentNode->nextNode != NULL) {
    nextNode = currentNode->nextNode;
    free(currentNode);
    currentNode = nextNode;
  }

  ll = NULL;
}