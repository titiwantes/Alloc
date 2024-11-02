#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Block
{
    size_t size;
    int free;
    struct Block *next;
} Block;

#define BLOCK_SIZE sizeof(Block)

extern Block *head;

// m_alloc.c
void *m_alloc(size_t size);
Block *request_block(Block *last, size_t size);

// c_alloc.c
void *c_alloc(size_t num, size_t size);

// re_alloc.c
void *re_alloc(void *ptr, size_t size);

// free_alloc.h
void free_alloc(void *ptr);