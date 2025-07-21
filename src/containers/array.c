#include "containers/array.h"
#include "macros/debug.h"
#include <stdlib.h>
#include <string.h>

MEMIO u8 array_new(ARRAY_T **self, size_t element_size, size_t array_size) {
  ARRAY_T *array;
  array = malloc(sizeof(ARRAY_T));
  if (array == NULL)
    return 1;
  uchar *data;
  data = malloc(element_size * array_size);
  if (data == NULL) {
    free(array);
    return 2;
  }
  array->data = data;
  array->element_size = element_size;
  array->array_size = array_size;
  *self = array;
  return 0;
}
MEMIO u8 array_delete(ARRAY_T *self) {
  free(self->data);
  free(self);
  return 0;
}

UNSAFE void array_get_element_ptr_unsafe(ARRAY_T *self, size_t idx,
                                         void **ret) {
  *ret = (self->data + idx * self->element_size);
  return;
}
UNSAFE void array_get_element_data_unsafe(ARRAY_T *self, size_t idx,
                                          void *ret) {
  memcpy(ret, self->data + idx * self->element_size, self->element_size);
  return;
}
u8 array_get_element_ptr(ARRAY_T *self, size_t idx, void **ret) {
  if (idx >= self->array_size)
    return 1;
  ASSERT_NOT_NULL(
      (void *)ret,
      "function[array_get_element_ptr]: input[*ret] pointer is NULL");
  array_get_element_ptr_unsafe(self, idx, ret);
  return 0;
}
u8 array_get_element_data(ARRAY_T *self, size_t idx, void *ret) {
  if (idx >= self->array_size)
    return 1;
  ASSERT_NOT_NULL(
      (void *)ret,
      "function[array_get_element_data]: input[ret] pointer is NULL");
  array_get_element_data_unsafe(self, idx, ret);
  return 0;
}

UNSAFE void array_set_unsafe(ARRAY_T *self, size_t idx, void *val) {
  memcpy(self->data + idx * self->element_size, val, self->element_size);
  return;
}

u8 array_set(ARRAY_T *self, size_t idx, void *val) {
  if (idx >= self->array_size)
    return 1;
  ASSERT_NOT_NULL((void *)val,
                  "function[array_set]: input[ret] pointer is NULL");
  array_set_unsafe(self, idx, val);
  return 0;
}
