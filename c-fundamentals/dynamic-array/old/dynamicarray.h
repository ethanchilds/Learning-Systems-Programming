#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

typedef struct {
  size_t capacity;
  size_t size;
  int* numbers;  
} dynamicArray;

int upsize(dynamicArray* array);
int downsize(dynamicArray* array);
int append(dynamicArray *array, int val);
int insert(dynamicArray *array, int idx, int val);
int delete(dynamicArray* array, int idx, int *deleted);
int pop(dynamicArray* array, int* popItem);
int removeElem(dynamicArray* array, int val);

#endif
