#include <stdlib.h>
#include <stdio.h>

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

int main(void){
  dynamicArray da = {.capacity=4, .size=0};
  da.numbers = malloc(da.capacity * sizeof(*da.numbers));

  for (int i = 0; i<4; i++){
    append(&da, i);
  }
  insert(&da, 2, 5);
  append(&da, 5);

  int res = removeElem(&da, 5);
  for (int i = 0; i<8; i++){
    printf("%d\n", da.numbers[i]);
  }
  printf("Array size: %zu\n", da.size);
  printf("Array capacity: %zu\n", da.capacity);

  free(da.numbers);
}

int upsize(dynamicArray* array){
  array->capacity = array->capacity*2;
  int *new_numbers = realloc(array->numbers, array->capacity*(sizeof *array->numbers));

  if (new_numbers == NULL){
    printf("Failed to expand capacity\n");
    return -1;
  }
  array->numbers = new_numbers;
  return 0;
}

int downsize(dynamicArray* array){
  array->capacity = array->capacity/2;
  int *new_numbers = realloc(array->numbers, array->capacity*(sizeof *array->numbers));

  if (new_numbers == NULL){
    printf("Failed to reduce capacity\n");
    return -1;
  }

  array->numbers = new_numbers;
  return 0;
}

int insert(dynamicArray* array, int idx, int val){
  if (idx > array->size || idx <0){
    return -1;
  }
  if (array->size == array->capacity){
    int res = upsize(array);
    if (res == -1)
      return -2;
  }

  for (int i = array->size; i> idx; i--){
    array->numbers[i] = array->numbers[i-1];
  }

  array->numbers[idx] = val;
  array->size++;
  return 0;
}

int append(dynamicArray* array, int val){
  return insert(array, array->size, val);
}

int delete(dynamicArray* array, int idx, int *deleted){
  if (idx >= array->size || idx < 0)
    return -1;

  *deleted = array->numbers[idx];
  for (int i=idx; i<array->size-1; i++){
    array->numbers[i] = array->numbers[i+1];
  }
  array->size--;
  if (array->size*2 == array->capacity){
    int res = downsize(array);
    if (res == -1)
    //-2 to differentiate realloc failure as opposed to idx error
      return -2;
  }
  return 0;
}

int pop(dynamicArray* array, int* popItem){
  return delete(array, array->size-1, popItem);
}

int removeElem(dynamicArray* array, int val){
  for (int i = 0; i<array->size; i++){
    if (array->numbers[i]==val){
      int deleted;
      int res = delete(array, i, &deleted);
      if (res != 0)
        return res;
    }
  }
  return 0;
}
