#include <stdlib.h>
#include <stdio.h>

int* get_numbers_good_way_01() {
    static int ret[3];
	for (int i=0; i<3; i++) ret[i] = i + 1000;
	for (int i=0; i<3; i++) printf("\titem #%d = %d\n", i+1, ret[i]);
	return ret;
}

int* get_numbers_good_way_02() {
    int* ret = malloc(3 * sizeof(int));
	for (int i=0; i<3; i++) ret[i] = i+100;
	for (int i=0; i<3; i++) printf("\titem #%d = %d\n", i+1, ret[i]);
	return ret;
}

int* get_numbers_dangling_pointer() {
/*
	compile warning: 
		address of stack memory associated with local variable 'ret' returned [-Wreturn-stack-address]
 */
    int ret[3];
	for (int i=0; i<3; i++) ret[i] = (i+1) * (i+1);
	for (int i=0; i<3; i++) printf("\titem #%d = %d\n", i+1, ret[i]);
	return ret;
}


int main() {
	{
		printf("\n--------------------good way 01: via static variable inside method stack\n");
		int* numbers = get_numbers_good_way_01();
		printf("\tRedisplaying\n");
		for (int i=0; i<3; i++) printf("\titem #%d = %d\n", i+1, numbers[i]);
	}
	{
		printf("\n--------------------good way 02: via static variable inside method stack\n");
		int* numbers = get_numbers_good_way_02();
		printf("\tRedisplaying\n");
		for (int i=0; i<3; i++) printf("\titem #%d = %d\n", i+1, numbers[i]);
	}
	{
		printf("\n\n--------------------dangling pointer\ncalling get_numbers_dangling_pointer(), but because ret is a variable declared inside method, i.e. stack variable, it should be released right after method returns\n");
		int* numbers = get_numbers_dangling_pointer();
		printf("\tRedisplaying - wrong - get other program's data\n");
		// %#0?x --> print in hex with len = ? (including 0x)   letter in lower case
		// %#0?X --> print in hex with len = ? (including 0X)   letter in upper case
		// %#10X --> doesn't work properly, it prints 0X7FFE, i.e. as short as possible
		for (int i=0; i<3; i++) printf("\titem #%d = %12d = %#010X\n", i+1, numbers[i], numbers[i]);
	}
	return 0;
}

