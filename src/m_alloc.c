#include "../lib/alloc.h"

Block *head = NULL;

Block *request_block(Block *last, size_t size)
{
    if (size + BLOCK_SIZE > (size_t)getpagesize() || size <= 0)
        return NULL;

    Block *block;

    block = sbrk(size + BLOCK_SIZE);
    if (block == (void *)-1)
        return NULL;

    block->size = size;
    block->free = 0;

    if (head == NULL)
    {
        block->next = block;
        block->prev = block;
    }
    else
    {
        block->prev = last;
        block->next = head;
        last->next = block;
        head->prev = block;
    }

    return block;
}

void *m_alloc(size_t size)
{

    if (head == NULL)
    {
        head = request_block(NULL, size);
        if (head == NULL)
            return NULL;

        return (void *)(head + 1);
    }

    Block *block = head;

    do
    {
        if (block->free && block->size >= size)
        {
            block->free = 0;
            return (void *)(block + 1);
        }
        block = block->next;
    } while (block != head);

    block = request_block((Block *)head->prev, size);
    if (block == NULL)
        return NULL;

    return (void *)(block + 1);
}
