#include <stdio.h>
#include "../include/linkedList.h"
void linkedListTest(){
    struct linkedList *ll = createNode("test");
    insertToEnd(ll, "it's second item");
    int intData = 3;
    insertToEnd(ll, &intData);

    printf("1 item address: %p\n", ll->head);
    printf("1 item value: %s\n", (char*)ll->head->data);
    printf("1 item prev address: %p\n", ll->head->prevNode);
    printf("1 item next address: %p\n", ll->head->nextNode);
    printf("2 item address: %p\n", ll->head->nextNode);
    printf("2 item value: %s\n", (char*)ll->head->nextNode->data);
    printf("2 item prev address: %p\n", ll->head->nextNode->prevNode);
    printf("2 item next address: %p\n", ll->head->nextNode->nextNode);
    printf("3 item address: %p\n", ll->head->nextNode->nextNode);
    printf("3 item value: %d\n", *(int*)ll->head->nextNode->nextNode->data);
    printf("3 item prev address: %p\n", ll->head->nextNode->nextNode->prevNode);
    printf("3 item next address: %p\n", ll->head->nextNode->nextNode->nextNode);
    freeLinkedList(ll);
}

int main() {
    return 0;
}