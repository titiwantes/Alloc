#include "../lib/alloc.h"

void free_alloc(void *ptr)
{
    Block *block = (Block *)ptr - 1;
    block->free = 1;

    if (block->prev && block->prev->free)
    {
        block->prev->next = block->next;
        if (block->next)
            block->next->prev = block->prev;
        block->prev->size += block->size + BLOCK_SIZE;
        block = block->prev;
    }
}