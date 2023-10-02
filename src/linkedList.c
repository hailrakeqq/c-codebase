#include <stdio.h>
#include <stdlib.h>

struct linkedList {
    void *data;

    struct linkedList *nextNode;
    struct linkedList *prevNode;
};

struct linkedList* createNode(void* data){
    struct linkedList *linkedList = (struct linkedList *)malloc(sizeof(struct linkedList));
    if(linkedList == NULL){
        perror("Memory allocatin failed.\n");
        exit(1);
    }

    linkedList->data = data;
    linkedList->prevNode = NULL;
    linkedList->nextNode = NULL;

    return linkedList;
}

int count(struct linkedList* linkedList){
  int count = 0;
  linkedList head = linkedList;
  while(head->nextNode != NULL) {
    count++;
    head->nextNode = head->nextNode->nextNode;
  }
  
  return count;
}

void insertToBegin(struct linkedList* linkedList, void* data){
  struct linkedList *newNode = (struct linkedList*) malloc(sizeof(struct linkedList));
  newNode->data = data;
  newNode->prevNode = NULL;
  newNode->nextNode = linkedList;
  
  linkedList->prevNode = newNode;
}

void insertToEnd(struct linkedList* linkedList, void* data){
  
}

void removeAtBegin(struct linkedList *lk) {

}

void removeAtEnd(struct linkedList* lk) {

}

void remove(struct linkedList* linkedList, void* data){

}

void printLinkedList(struct linkedList* linkedList) {
  struct linkedList current = linkedList;
  while(current != NULL) {
    printf("%p\n")",current->data);
    current = current->nextNode;
  }
}


void freeLinkedList(struct linkedList* linkedList){

}
