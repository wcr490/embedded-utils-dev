#include "containers/list.h"
#include "macros/debug.h"
#include "macros/type.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_test.h"
#include "list_test.h"

int main(int argc, char **argv) {
  UNIT_TEST("LIST", { list_test(); });
  UNIT_TEST("ARRAY", { array_test(); });
  return 0;
}
