#include <stdio.h>
#include <stdlib.h>

// assume pointer is 4 bytes in size
//
int a[5] = {3, 1, 4, 1, 5};			// assume &a = 0x1000
int *b[3] = { &a[0], &a[2], &a[4]}; // assume &b = 0x2000
int** c = &b[1];                    // assume &c = 0x3000
int d = 0;                          // assume &d = 0x4000

/*
 * a 0x1000    3
 *   0x1004    1
 *   0x1008    4
 *   0x100C    1
 *   0x1010    5
 * 
 * b 0x2000    0x1000
 *   0x2004    0x1008
 *   0x2008    0x1010
 * 
 * c 0x3000 => 0x2004
 *
 * d 0x4000    0x0
 *
 */

void q_1() {
	**c = 3;					// L1
	// ld $c, r0       // r0 = 0x3000
	// ld (r0), r0     // r0 = 0x2004
	// ld (r0), r0     // r0 = 0x1008
	// ld $3,   r1
	// st r1, (r0)     // 0x10008 <- 3
	d = c - b;					// L2
	a[d]++;                     // L3
	
	// L1 touched address is 0x1008    value = 3
	// L2 touched address is 0x4000    value = 1
	// L3 touched address is 0x1004    value = 2
}

void q_2() {
    *b = c[0];
	*(&a[2]) = b[0][2];

	// address = 0x1000 value = 0x1008
	// address = 0x1008 value = 4
	//
	// address = 0x2000 value = 0x1008
	// address = 0x1008 value = 5
}


