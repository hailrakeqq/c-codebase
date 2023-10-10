#include "../include/utils.h"

void swap(void *fItem, void *sItem){
    void *temp = fItem;
    fItem = sItem;
    sItem = temp;
}