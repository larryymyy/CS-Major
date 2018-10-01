/*
   Kevin Conte
   951620146

   10 October 2018
   =====================================
   Assignment 2
   Part 1
 */

#include <stdio.h>

/* Prototype */
int mask(int n);

/* Main Method */
int main() {

	printf("Kevin Conte\n");
	printf("Assignment 2, Part 1\n\n");

	printf("mask(0): 0x%X\n", mask(0));
	printf("mask(1): 0x%X\n", mask(1));
	printf("mask(2): 0x%X\n", mask(2));
	printf("mask(3): 0x%X\n", mask(3));
	printf("mask(5): 0x%X\n", mask(5));
	printf("mask(8): 0x%X\n", mask(8));
	printf("mask(16): 0x%X\n", mask(16));
	printf("mask(31): 0x%X\n", mask(31));
	
	return 0;
}

/* mask() Method */
int mask(int n) {
	/* Assume the mask is full, and shift it right until it matches the input specification */
	int result = 0x7FFFFFFF; /* 01111111 11111111 11111111 11111111 */
	result >>= (31 - n); /* logical shift right by the difference between 31 and the input (i.e. n=11 -> shift right by 20 bits) */
	return result;

	// One-liner: return (0x7FFFFFFF) >> (31 - n);
}
