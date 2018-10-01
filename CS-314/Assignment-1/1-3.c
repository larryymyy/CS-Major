/*
   Kevin A. Conte
   951620146

   3 Oct 2018
   ================================================

   Assignment #1

   Part 1-3
*/

#include <stdio.h>

/* replace() prototype */
unsigned int replace(unsigned int x, int a, unsigned char b);


/* main method */
int main() {
	
	unsigned int x = 0x12345678;
	int a = 2;
	unsigned char b = 0xAB;
	unsigned int result = replace(x, a, b);
	printf("replace(0x%08X, %d, 0x%02X): 0x%08X\n", x, a, b, result);

	a = 0;
	result = replace(x, a, b);
	printf("replace(0x%08X, %d, 0x%02X): 0x%08X\n", x, a, b, result);

	return 0;
}

/* replace() implementation */
unsigned int replace(unsigned int x, int a, unsigned char b) {
	unsigned int mask = ~(0xff << (a << 3)); /* (a << 3) equivalent to (a * 8), as in number of bytes to shift left */
	unsigned int shift = b << (a << 3);

	/*
	   Example
	   =======
	   x = 0x12345678
	   a = 2
	   b = 0xab
	   mask = 0x00ff0000
	   ~mask = 0xff00ffff
	   shift = 0x00ab0000

	   Calculation:

	           0xff00ffff
	       AND|0x12345678
		       ----------
			   0x12005678
		    OR|0x00AB0000 (shifted char)
		       ----------
			   0x12AB5678

		Equation: (mask & x) | shift
				  (0xff00ffff & 012345678) | 0x00ab0000
	*/
	return (mask & x) | shift;
}
