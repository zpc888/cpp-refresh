#include <stdio.h>
#include <stdlib.h>

int i = 5;
int *p = &i;
int &r = i;

int main() {
	printf(" i = %d; &i = %p\n", i, &i);
	printf("*p = %d;  p = %p; &p = %p\n", *p, p, &p);
	printf(" r = %d; &r = %p\n", r, &r);

	printf("\nsetting i = 7 --------------\n");
	i = 7;
	printf(" i = %d; &i = %p\n", i, &i);
	printf("*p = %d;  p = %p; &p = %p\n", *p, p, &p);
	printf(" r = %d; &r = %p\n", r, &r);

	printf("\nsetting *p = 9 --------------\n");
	*p = 9;
	printf(" i = %d; &i = %p\n", i, &i);
	printf("*p = %d;  p = %p; &p = %p\n", *p, p, &p);
	printf(" r = %d; &r = %p\n", r, &r);

	printf("\nsetting r = 8 --------------\n");
	r = 8;
	printf(" i = %d; &i = %p\n", i, &i);
	printf("*p = %d;  p = %p; &p = %p\n", *p, p, &p);
	printf(" r = %d; &r = %p\n", r, &r);

}
