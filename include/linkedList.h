#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    INT_TYPE,
    FLOAT_TYPE,
    CHAR_TYPE,
    UNKNOWN_TYPE
} dataType;

struct node {
  void *data;
  dataType dataType;

  struct node *nextNode;
  struct node *prevNode;
};

struct linkedList {
  struct node *head;
};

struct linkedList *createNode(void *data);
void insertToBegin(struct linkedList *ll, void *data);
void insertToEnd(struct linkedList *ll, void *data);
void insertAtPosition(struct linkedList *ll, int position, void *data);
int getNodePosition(struct linkedList *ll, struct node *targetNode);
int compareNode(struct node *fNode, struct node *sNode);
int count(struct linkedList *ll);
void removeAtBegin(struct linkedList *ll);
void removeAtEnd(struct linkedList *ll);
void removeNode(struct linkedList *ll, struct node *targetNode);
void freeLinkedList(struct linkedList *ll);

#endif // !LINKEDLIST_H