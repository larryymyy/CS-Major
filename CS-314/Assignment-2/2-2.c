/*
   Kevin Conte
   951620146

   10 October 2018
   =====================================
   Assignment 2
   Part 2
 */

#include <stdio.h>

/* Prototype */
unsigned int extract(unsigned int x, int i);

/* Main Method */
int main() {
	printf("extract(0x12345678, 0): 0x%08X\n", extract(0x12345678, 0));
	printf("extract(0xABCDEF00, 2): 0x%08X\n", extract(0xABCDEF00, 2));
	return 0;
}

/* extract() Method */
unsigned int extract(unsigned int x, int i) {
	/* Align the mask to the correct byte index */
	/* Again, shifting left by 3 bits is equivalent to multiplying by 8 */
	unsigned int mask = 0x000000FF << (i << 3);

	/* Using a regular int to force arithmetic shifts */
	/* Isolates the specified byte with the mask */
	int result = x & mask;

	/* Pushes the byte to the most significant byte to ensure sign bit is captured */
	result <<= (24 - (i << 3));

	/* Moves the byte to the least significant byte, filling in with either 1s or 0s, depending on sign of byte */
	result >>= 24; 
	
	/* Cast back to unsigned int and return */
	return (unsigned int) result;
}
