#include "../include/dynamicArray.h"

static void shiftArray(dynamicArray *arr, size_t *index){
    for (int j = index; j < arr->currentSize - 1;j++){
        arr->array[j] = arr->array[j + 1];
    }
}

static void deleteItem(dynamicArray *arr, size_t *index){
    shiftArray(arr, index);
    arr->currentSize--;
    *index--;
}

void initDynamicArray(dynamicArray *arr, size_t initialSize){
    arr->array = malloc(initialSize * sizeof (void *));

    if(arr == NULL){
        fprintf(stderr, "Allocation memory failed.\n");
        exit(1);
    }

    arr->capacity = initialSize;
    arr->currentSize = 0;
}

void add(dynamicArray *dynamicArray, void *item){
    if(dynamicArray->currentSize == dynamicArray->capacity) {
        dynamicArray->capacity *= 2;
        dynamicArray->array = realloc(dynamicArray->array, dynamicArray->capacity * sizeof(void *));
        if(dynamicArray->array == NULL){
            fprintf(stderr, "Reallocation memory failed.\n");
            exit(1);
        }
    }

    dynamicArray->array[dynamicArray->currentSize] = item;
    dynamicArray->currentSize++;
}

void remove(dynamicArray *arr, void *searchedTarget){
    for (int i = 0; i < arr->currentSize; i++){
        if(arr->array[i] == searchedTarget){
            deleteItem(arr, &i);
            break;
        }
    }
} 

void removeAll(dynamicArray *arr, void *searchedTarget){
    for (int i = 0; i < arr->currentSize; i++){
        if(arr->array[i] == searchedTarget){
            deleteItem(arr, &i);
        }
    }
} 

void removeAt(dynamicArray *arr, size_t index){
    if(index < arr->currentSize){
        deleteItem(arr, &index);
    } else {
        fprintf(stderr, "Index outside of array range.\n");
        exit(1);
    }
} 

uint8_t contains(dynamicArray *arr, void *item){
    for (int i = 0; i < arr->currentSize; i++){
        if(arr->array[i] == item)
            return 1;
    }

    return 0;
}

size_t indexOf(dynamicArray *arr, void *item){
    for (int i = 0; i < arr->currentSize; i++){
        if(arr->array[i] == item)
            return i;
    }
    return -1;
}

void reverse(dynamicArray *arr){
    if (arr->currentSize <= 1) {
        return;
    }

    for (size_t i = 0, j = arr->currentSize - 1; i < j; i++, j--) 
        swap(arr->array[i], arr->array[j]);
}

void sort(dynamicArray *arr, SORT_TYPES sortType){

} 

void freeDynamicArray(dynamicArray *arr){
    free(arr->array);
    arr->array = NULL;
    arr->currentSize = 0;
    arr->capacity = 0;
} 
