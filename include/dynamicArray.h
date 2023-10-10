#ifndef DARRAY_H
#define DDARRAY_H
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "utils.h"

typedef enum {
    Ascending_Sort,
    Descending_Sort
} SORT_TYPES;

typedef struct  {
  void **array;

  size_t currentSize;
  size_t capacity;
} dynamicArray;

void initDynamicArray(dynamicArray *arr, size_t initialSize);
void add(dynamicArray *arr, void *item);
void remove(dynamicArray *arr, void *item);
void removeAll(dynamicArray *arr, void *item);
void removeAt(dynamicArray *arr, size_t index);
uint8_t contains(dynamicArray *arr, void *item);
size_t indexOf(dynamicArray *arr,void *item);
void reverse(dynamicArray *arr);
void sort(dynamicArray *arr, SORT_TYPES sortType);
void freeDynamicArray(dynamicArray *arr);
#endif // !DARRAY_H
