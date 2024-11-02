#include "../lib/alloc.h"

void free_alloc(void *ptr)
{
    Block *block = (Block *)ptr - 1;
    block->free = 1;
}