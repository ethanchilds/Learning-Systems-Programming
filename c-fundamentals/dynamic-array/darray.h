#ifndef DARRAY_H
#define DARRAY_H

#define INIT_CAP 1
#define RESIZE_FACTOR 2

typedef struct {
  size_t capacity;
  size_t len;
  size_t stride;
}Header;

void *_darray_create(size_t init_cap, size_t stride);
void *_insert(void *darray, int idx, void *val);
int _delete(void *darray, int idx, void *dest);
size_t get_capacity(void* darray);
size_t get_len(void* darray);

#define darray_create(type) _darray_create(INIT_CAP, sizeof(type))
#define insert(darray, idx, val) darray = _insert(darray, idx, &(__typeof__(val)){val})
#define append(darray, val) darray = _insert(darray, ((Header *)darray-1)->len, &(__typeof__(val)){val})
#define delete(darray, idx, dest) _delete(darray, idx, &dest)
#define pop(darray, dest) _delete(darray, ((Header *)darray - 1)->len - 1, &dest) 

#endif
