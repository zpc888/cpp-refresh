#include <stdio.h>
#include <stdlib.h>

int main() {
    int* int_ptr = malloc(10 * sizeof(int));
    for (int i=0; i<10; i++) {
        *(int_ptr + i) = (i+1) * 1000;
    }
	// 1000 = 0x03E8    0xE8 = -24
	// 2000 = 0x07D0    0xD0 = -48
	// 3000 = 0x0BB8    0xD0 = -72
	// for x86, normally it is Little Endian
	//
	// to test your system, you can use 
	//
	// echo I | tr -d '[:space:]' | od -to2 | head -n1 | awk '{print $2}' | cut -c6
	// if 1 => Little Endian
	// if 0 => Big Endian
	// 
    void* void_ptr = int_ptr;
    printf("base pointer address: int-ptr = %p; void-ptr = %p\n", int_ptr, void_ptr);
    for (int i=0; i<10; i++) {
        printf("offset [%d] address  : int-ptr = %p; void-ptr = %p; de-reference pointer int=%d; void=%d\n"
                , i, int_ptr + i, void_ptr + i, *(int_ptr + i), *((char*)(void_ptr + i)));
    }
	/*
	 // Little Endian Output:  -ptr address will change for each run
offset [0] address  : int-ptr = 0x7fa0c65058e0; void-ptr = 0x7fa0c65058e0; de-reference pointer int=1000; void=-24
offset [1] address  : int-ptr = 0x7fa0c65058e4; void-ptr = 0x7fa0c65058e1; de-reference pointer int=2000; void=3
offset [2] address  : int-ptr = 0x7fa0c65058e8; void-ptr = 0x7fa0c65058e2; de-reference pointer int=3000; void=0
offset [3] address  : int-ptr = 0x7fa0c65058ec; void-ptr = 0x7fa0c65058e3; de-reference pointer int=4000; void=0
offset [4] address  : int-ptr = 0x7fa0c65058f0; void-ptr = 0x7fa0c65058e4; de-reference pointer int=5000; void=-48
offset [5] address  : int-ptr = 0x7fa0c65058f4; void-ptr = 0x7fa0c65058e5; de-reference pointer int=6000; void=7
offset [6] address  : int-ptr = 0x7fa0c65058f8; void-ptr = 0x7fa0c65058e6; de-reference pointer int=7000; void=0
offset [7] address  : int-ptr = 0x7fa0c65058fc; void-ptr = 0x7fa0c65058e7; de-reference pointer int=8000; void=0
offset [8] address  : int-ptr = 0x7fa0c6505900; void-ptr = 0x7fa0c65058e8; de-reference pointer int=9000; void=-72
offset [9] address  : int-ptr = 0x7fa0c6505904; void-ptr = 0x7fa0c65058e9; de-reference pointer int=10000; void=11

	 // Big Endian Output:  -ptr address will change for each run
offset [0] address  : int-ptr = 0x7fa0c65058e0; void-ptr = 0x7fa0c65058e0; de-reference pointer int=1000; void=0
offset [1] address  : int-ptr = 0x7fa0c65058e4; void-ptr = 0x7fa0c65058e1; de-reference pointer int=2000; void=0
offset [2] address  : int-ptr = 0x7fa0c65058e8; void-ptr = 0x7fa0c65058e2; de-reference pointer int=3000; void=3
offset [3] address  : int-ptr = 0x7fa0c65058ec; void-ptr = 0x7fa0c65058e3; de-reference pointer int=4000; void=-24
offset [4] address  : int-ptr = 0x7fa0c65058f0; void-ptr = 0x7fa0c65058e4; de-reference pointer int=5000; void=0
offset [5] address  : int-ptr = 0x7fa0c65058f4; void-ptr = 0x7fa0c65058e5; de-reference pointer int=6000; void=0
offset [6] address  : int-ptr = 0x7fa0c65058f8; void-ptr = 0x7fa0c65058e6; de-reference pointer int=7000; void=7
offset [7] address  : int-ptr = 0x7fa0c65058fc; void-ptr = 0x7fa0c65058e7; de-reference pointer int=8000; void=-48
offset [8] address  : int-ptr = 0x7fa0c6505900; void-ptr = 0x7fa0c65058e8; de-reference pointer int=9000; void=0
offset [9] address  : int-ptr = 0x7fa0c6505904; void-ptr = 0x7fa0c65058e9; de-reference pointer int=10000; void=0
	*/
    return 0;
}
