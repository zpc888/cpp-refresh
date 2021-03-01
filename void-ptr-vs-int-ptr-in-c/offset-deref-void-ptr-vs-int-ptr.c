#include <stdio.h>
#include <stdlib.h>

int main() {
    int* int_ptr = malloc(10 * sizeof(int));
    for (int i=0; i<10; i++) {
        *(int_ptr + i) = (i+1) * 1000;
    }
    void* void_ptr = int_ptr;
    printf("base pointer address: int-ptr = %p; void-ptr = %p\n", int_ptr, void_ptr);
    for (int i=0; i<10; i++) {
        printf("offset [%d] address  : int-ptr = %p; void-ptr = %p; de-reference pointer int=%d; void=%d\n"
                , i, int_ptr + i, void_ptr + i, *(int_ptr + i), *((char*)(void_ptr + i)));
    }
    return 0;
}