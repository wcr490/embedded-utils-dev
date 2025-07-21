#include "containers/array.h"
#include "macros/debug.h"
#include "macros/type.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void array_test(void);

void array_test(void) {
  ARRAY_T *test_array;
  array_new(&test_array, sizeof(u8), 20);
  int i;
  for (i = 0; i < 20; i ++ ) {
    array_set(test_array, i, &i);
  }
  for (i = 0; i < 20; i ++) {
    u8 ret = 0;
    array_get_element_data(test_array, i, &ret);
    printf("array[%d]: %d\n", i, ret);
  }
  return;
}
