/*
   Kevin A. Conte
   951620146

   3 Oct 2018
   ================================================

   Assignment #1

   Part 1-2
*/

#include <stdio.h>

/* combine() prototype */
unsigned int combine(unsigned int a, unsigned int b);


/* main method */
int main() {

	unsigned int a = 0x12345678;
	unsigned int b = 0xABCDEF00;
	unsigned int c = combine(a, b);
	printf("combine(0x%08X, 0x%08X): 0x%08X\n", a, b, c);

	a = 0xABCDEF00;
	b = 0x12345678;
	c = combine(a, b);
	printf("combine(0x%08X, 0x%08X): 0x%08X\n", a, b, c);

	return 0;
}

/* combine() implementation */
unsigned int combine(unsigned int a, unsigned int b) {
	unsigned int result = a >> 16 << 16;
	result |= (b << 16 >> 16);
	return result;
}
