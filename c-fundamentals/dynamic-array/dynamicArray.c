#include <stdlib.h>
#include <stdio.h>

typedef struct {
  size_t capacity;
  size_t size;
  int* numbers;  
} dynamicArray;

int resize(dynamicArray* array);
dynamicArray* append(dynamicArray *array, int val);
dynamicArray* insert(dynamicArray *array, int idx, int val);

int main(void){
  dynamicArray da = {.capacity=4, .size=0};
  da.numbers = malloc(da.capacity * sizeof(*da.numbers));

  for (int i = 0; i<4; i++){
    append(&da, i);
  }

  free(da.numbers);
}

int resize(dynamicArray* array){
  array->capacity = array->capacity*2;
  int *new_numbers = realloc(array->numbers, array->capacity*(sizeof *array->numbers));

  if (new_numbers == NULL){
    printf("Failed to expand capacity\n");
    return 0;
  }
  array->numbers = new_numbers;
  return 1;
}

dynamicArray* append(dynamicArray *array, int val){
  if (array->size == array->capacity){
    int res = resize(array);
    if (res==0)
      return NULL;
  }
  array->numbers[array->size] = val;
  array->size++;
  return array;
}

dynamicArray* insert(dynamicArray *array, int idx, int val){
  if (idx >= array->size){
    return append(array, val);
  }
  if (array->size == array->capacity){
    int res = resize(array);
    if (res == 0)
      return NULL;
  }
  for (int i = array->size; i > idx; i--){
    array->numbers[i] = array->numbers[i-1];
  }
  array->numbers[idx] = val;
  array->size++;
  return array;
}
