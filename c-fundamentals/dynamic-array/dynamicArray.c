#include <stdlib.h>
#include <stdio.h>

typedef struct {
  size_t capacity;
  size_t size;
  int* numbers;  
} dynamicArray;

dynamicArray* append(dynamicArray *array, int val){
  if (array->size == array->capacity){
    array->capacity = array->capacity*2;
    int *new_numbers = realloc(array->numbers, array->capacity*(sizeof *array->numbers));

    if (new_numbers == NULL){
      printf("Failed to reallocate memory\n");
      return NULL;
    }
    array->numbers = new_numbers;
  }
  array->numbers[array->size] = val;
  array->size++;
  return array;
}

int main(void){
  int valstoappend = 28;
  dynamicArray da = {.capacity=4, .size=0};
  da.numbers = calloc(da.capacity, sizeof(*da.numbers));


  for (int i = 0; i<valstoappend; i++){
    dynamicArray* tempda = append(&da, i);
    if (tempda == NULL){
      free(da.numbers);
      return 1;
    }
  }

  for (int i = 0; i<valstoappend; i++){
    printf("%d\n", da.numbers[i]);
  }

  free(da.numbers);
}
