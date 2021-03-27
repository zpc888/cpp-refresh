#include <stdlib.h>
#include <stdio.h>

int a[5] = {3, 1, 4, 1, 5};				// assume &a = 0x1000
int *b[3] = { &a[0], &a[2], &a[4]};     // assume &b = 0x2000
int **c = &b[1];                        // assume &c = 0x3000
int d = 0;                              // assume &d = 0x4000

int main() {
	printf("sizeof(int) = %d; sizeof(int*) = %d\n", sizeof(int), sizeof(int*));
	printf("c = %p &c = %p, b = %p &b = %p\n", c, &c, b, &b);
	printf("c - b = %d &c == c: %d, b == &b: %d\n", c-b, c == &c ? 1 : 0, b == &b ? 1 : 0);

	b[0] = &d;
	printf("b = %p &b = %p\n", b, &b);
	printf("b[0] = %p &b[0] = %p\n", b[0], &b[0]);
	printf("b[1] = %p &b[1] = %p\n", b[1], &b[1]);
	printf("b[2] = %p &b[2] = %p\n", b[2], &b[2]);
}
