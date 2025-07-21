#pragma once

#include "macros/type.h"
#include "macros/flag.h"
#include "macros/common.h"
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// TYPE DEF
typedef struct ARRAY ARRAY_T;

struct ARRAY {
  uchar *data;
  size_t array_size;
  size_t element_size;
};

// FUNCTION DEF
MEMIO u8 array_new(ARRAY_T **self, size_t element_size, size_t array_size);
MEMIO u8 array_delete(ARRAY_T *self);

UNSAFE void array_get_element_ptr_unsafe(ARRAY_T *self, size_t idx, void **ret);
UNSAFE void array_get_element_data_unsafe(ARRAY_T *self, size_t idx, void *ret);
UNSAFE void array_set_unsafe(ARRAY_T *self, size_t idx, void *val);
u8 array_get_element_ptr(ARRAY_T *self, size_t idx, void **ret);
u8 array_get_element_data(ARRAY_T *self, size_t idx, void *ret);
u8 array_set(ARRAY_T *self, size_t idx, void *val);

#ifdef __cplusplus
}
#endif

