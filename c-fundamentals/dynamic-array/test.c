#include <stdio.h>

#include "darray.h"

int main(void){
  int *v = darray_create(int);

  for (int i = 0; i < 5; i++){
    append(v, i);
  }

  for (int i = 0; i < get_len(v); i++){
    printf("%d. %d\n", i, v[i]);
  }
  printf("v has capacity: %zu\n", get_capacity(v));
  printf("v has len: %zu\n", get_len(v));
}
