#include <unistd.h>

#define HEAP_CHUNK_SIZE 4096

// track beginning of memory available from sbrk()
void *heap_begin = NULL;

// track how many memory is left in our current heap allocation
size_t available_bytes = 0;

/* allocate size bytes from the heap */
void *simple_malloc(size_t size)
{
    // can't have less than 1 byte requested
    if (size < 1)
    {
        return NULL;
    }

    // add 8 bytes for bookkeeping
    size += 8;

    // 32 bytes is the minimum allocation
    if (size < 32)
    {
        size = 32;
    }

    // round up to the nearest 16-byte multiple
    else if (size%16 != 0)
    {
        size = ((size/16)+1)*16;
    }

    // if we have no memory, grab one chunk to start
    if (heap_begin == NULL)
    {
        heap_begin = sbrk(HEAP_CHUNK_SIZE);
        if (heap_begin == (void *)-1)
        {
            return NULL;
        }

        // skip the first 8 bytes so that we will return 16-byte aligned
        // addresses, after we put our 8 bytes of bookkeeping in front
        heap_begin += 8;
        available_bytes = HEAP_CHUNK_SIZE - 8;
    }

    // if the request is for more memory that we have, get enough to fulfill it
    if (size > available_bytes)
    {
        size_t needed_bytes = size - available_bytes;
        int total_new_bytes = ((needed_bytes/HEAP_CHUNK_SIZE)+1)*HEAP_CHUNK_SIZE;
        void *tmp = sbrk(total_new_bytes);
        if (tmp == (void *)-1)
        {
            return NULL;
        }
        available_bytes += total_new_bytes;
    }

    // return the front of this memory chunk to the user

    // first, write the size of the chunk to first 8 bytes
    size_t *tmp = (size_t *)heap_begin;
    *tmp = size;

    // second, set the address for the user to be 8 bytes where the size starts
    void *returned_ptr;
    returned_ptr = heap_begin + 8;

    // update heap_begin as size bytes have now been allocated to the application
    heap_begin += size;
    available_bytes -= size;

    // give the address back to the application
    return returned_ptr;
}

/* return a previously allocated memory chunk to the allocator */
void simple_free(void *ptr)
{
    // do nothing for now
    return;
}
