#include <stdio.h>
#include "../include/linkedList.h"

int main() {
    struct linkedList *ll = createNode("test");
    // insertToEnd(ll, "it's second item");
    // int intData = 3;
    // insertToEnd(ll, &intData);
    // printLinkedList(ll);
    freeLinkedList(ll);
}