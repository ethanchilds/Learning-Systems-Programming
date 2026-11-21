#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "darray.h"

void *_darray_create(size_t init_cap, size_t stride){
  Header *header= malloc(sizeof(Header) + stride * init_cap);  
  if (header == NULL)
    return NULL;
  header->capacity = init_cap;
  header->len = 0;
  header->stride = stride;
  return (void *)(header +1);
}

void *_upsize(void * darray){
  Header *header = (Header *)darray - 1;
  header->capacity = header->capacity * RESIZE_FACTOR;

  Header *temp = realloc(header, sizeof(Header) + header->capacity * header->stride);
  if (temp == NULL)
    return NULL;
  temp += 1;
  return (void *)temp;
}

void *_insert(void *darray, int idx, void *val){
  Header *header = (Header *)darray - 1;
  if (idx > header->len || idx < 0){
    return darray;
  } 

  if (header->len == header->capacity){
    void *temp = _upsize(darray);
    if (temp == NULL){
      return darray;
    }
    darray = temp;
    Header *header = (Header *)darray - 1;
  }

  memmove((char *)darray + (idx + 1) * header->stride, (char *)darray + idx * header->stride, (header->len - idx) * header->stride);
  memcpy((char *)darray + idx * header->stride, val, header->stride);  
  header->len++;
  return darray;
}

int _delete(void *darray, int idx, void *dest){
  Header *header = (Header *)darray - 1;
  if (idx >= header->len || idx < 0)
    return -1; 

  memcpy(dest, (char *)darray + idx * header->stride, header->stride);
  header->len--;
  memmove((char *)darray + idx * header->stride, (char *)darray + (idx + 1) * header->stride, (header->len - idx) * header->stride);
  return 0;
}


size_t get_capacity(void* darray){
  Header *header = (Header *)darray -1;
  return header->capacity;
}

size_t get_len(void* darray){
  Header *header = (Header *)darray -1;
  return header->len;
}
