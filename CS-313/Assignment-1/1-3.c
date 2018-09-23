/*
   Kevin A. Conte
   951620146

   3 Oct 2018
   ================================================

   Assignment #1

   Part 1-3
*/

#include <stdio.h>

unsigned int replace(unsigned int x, int a, unsigned char b) {
	unsigned int mask = 0xff << (a << 3); /* (a << 3) equivalent to 8*a */
	unsigned int shift = b << (a << 3);

	/*
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

		Equation: (~mask & x) | shift
				  (0xff00ffff & 012345678) | 0x00ab0000
	*/
	return (~mask & x) | shift;
}

int main(int argc, char **argv) {
	
	unsigned int x = 0x12345678;
	int a = 2;
	unsigned char b = 0xAB;
	unsigned int result = replace(x, a, b);
	printf("replace(%#08x, %d, %#02x): %#08x\n", x, a, b, result);

	a = 0;
	result = replace(x, a, b);
	printf("replace(%#08x, %d, %#02x): %#08x\n", x, a, b, result);

	return 0;
}
