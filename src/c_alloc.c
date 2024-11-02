#include "../lib/alloc.h"

void *c_alloc(size_t num, size_t size)
{
    size_t block_size = num * size;
    Block *block = head;

    Block *last = head ? head->prev : NULL;

    if (block)
    {
        do
        {
            if (block->free && block->size >= block_size)
            {
                block->free = 0;
                return (void *)(block + 1);
            }
            block = block->next;
        } while (block != head);
    }

    block = request_block(last, block_size);
    if (!block)
        return NULL;

    return (void *)(block + 1);
}
