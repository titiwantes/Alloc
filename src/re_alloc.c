#include "../lib/alloc.h"

void *re_alloc(void *ptr, size_t size)
{
    if (ptr == NULL)
        return m_alloc(size);

    Block *block = (Block *)ptr - 1;

    if (block->size >= size)
        return ptr;

    if (block->next && block->next->free && block->size + block->next->size + BLOCK_SIZE >= size)
    {
        block->size += block->next->size + BLOCK_SIZE;
        block->next = block->next->next;
        if (block->next)
            block->next->prev = block;
        return ptr;
    }
    if (block->prev && block->prev->free && block->prev->size + block->size + BLOCK_SIZE >= size)
    {
        block->prev->size += block->size + BLOCK_SIZE;
        block->prev->next = block->next;
        if (block->next)
            block->next->prev = block->prev;
        return (void *)(block->prev + 1);
    }
    void *new_ptr = m_alloc(size);
    if (!new_ptr)
        return NULL;
    memcpy(new_ptr, ptr, block->size);
    free_alloc(ptr);

    return new_ptr;
}
