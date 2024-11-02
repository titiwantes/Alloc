
#include "lib/alloc.h"

void display_blocks()
{
  Block *block = head;
  if (!block)
  {
    printf("No blocks\n");
    return;
  }
  do
  {
    printf("Block: %p, Size: %ld, Free: %d\n", block, block->size, block->free);
    block = block->next;
  } while (block != head);

  printf("\n");
}

int main()
{
  printf("BLOCK_SIZE: %ld\n", BLOCK_SIZE);
  display_blocks();
  printf("-----Test m_alloc-----\n");
  char *ptr1 = m_alloc(10);
  memset(ptr1, 'A', 10);
  printf("%s\n", ptr1);
  display_blocks();
  printf("-----Test c_alloc-----\n");
  char *ptr2 = c_alloc(10, sizeof(char));
  memset(ptr2, 'B', 10);
  printf("%s\n", ptr2);
  display_blocks();
  printf("-----Test free_alloc-----\n");
  free_alloc(ptr2);
  display_blocks();
  printf("-----Test re_alloc-----\n");
  char *ptr3 = re_alloc(ptr1, 20);
  printf("%s\n", ptr3);
  display_blocks();

  return 0;
}
