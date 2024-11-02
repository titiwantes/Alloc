#include "../lib/alloc.h"

Block *head = NULL;

Block *request_block(Block *last, size_t size)
{
    Block *block;

    block = sbrk(size + BLOCK_SIZE);
    if (block == (void *)-1)
        return NULL;

    block->size = size;
    block->free = 0;
    block->next = NULL;

    if (last)
        last->next = block;

    return block;
}

void *m_alloc(size_t size)
{
    if (head == NULL)
    {
        head = request_block(NULL, size);
        if (head == NULL)
            return NULL;
    }
    else
    {
        Block *block = head;
        Block *last = head;

        while (block && !(block->free && block->size >= size))
        {
            last = block;
            block = block->next;
        }

        if (block == NULL)
        {
            block = request_block(last, size);
            if (block == NULL)
                return NULL;
        }
        else
        {
            block->free = 1;
        }

        return (void *)(block + 1);
    }
    return (void *)(head + 1);
}
