/*
   Kevin A. Conte
   951620146

   3 Oct 2018
   ================================================

   Assignment #1

   Part 1-4
*/

#include <stdio.h>

/* oddBit() prototype */
int oddBit(unsigned int x);


/* main method */
int main() {
	
	printf("oddBit(0x%X): %d\n", 0x1, oddBit(0x1));
	printf("oddBit(0x%X): %d\n", 0x2, oddBit(0x2));
	printf("oddBit(0x%X): %d\n", 0x3, oddBit(0x3));
	printf("oddBit(0x%X): %d\n", 0x4, oddBit(0x4));
	printf("oddBit(0x%X): %d\n", 0xFFFFFFFF, oddBit(0xFFFFFFFF));
	printf("oddBit(0x%X): %d\n", 0xAAAAAAAA, oddBit(0xAAAAAAAA));
	printf("oddBit(0x%X): %d\n", 0x55555555, oddBit(0x55555555));

	return 0;
}

/* oddBit() implementation */
int oddBit(unsigned int x) {
	unsigned int mask = 0xAAAAAAAA;
	/*
	   mask = 10101010 10101010 10101010 10101010
	   x =    11111111 11111111 11111111 11111111 | AND
	   --------------------------------------------
	          10101010 10101010 10101010 10101010 >= 00000000 00000000 00000000 00000001
	*/
	return (mask & x) >= 0x1;
}
