#include "containers/list.h"
#include "macros/debug.h"
#include "macros/type.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void list_test();

int main(int argc, char **argv) {
  UNIT_TEST("LIST", { list_test(); });
  return 0;
}

void list_test() {
  LIST_T *test_list;
  list_new(&test_list);
  int i;
  for (i = 1; i <= 10; (i)++) {
    u8 *node = malloc(sizeof(u8));
    *node = i;
    list_insert_tail(test_list, (void *)node);
  }
  u8 *node;
  printf("node: %d\n", *((u8 *)(test_list->root.next->data)));
  printf("node: %d\n", *((u8 *)(test_list->root.prev->data)));
  // u32 size = list_size(test_list);
  // printf("size: %d\n", size);
  // for (i = 0; i < size; i++) {
  //   list_remove_head(test_list, (void **)&node);
  //   printf("head: %d\n", *node);
  //   free(node);
  // }
  u32 pos;
  LIST_NODE_T *cur_node;
  LIST_FOREACH(pos, test_list, cur_node) {
    printf("node: %d\n", *(u8 *)cur_node->data);
  }
  LIST_FOREACH_REVERSE(pos, test_list, cur_node) {
    printf("node: %d\n", *(u8 *)cur_node->data);
  }
}
