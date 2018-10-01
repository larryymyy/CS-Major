/*
   Kevin Conte
   951620146

   10 October 2018
   =====================================
   Assignment 2
   Part 3
 */

#include <stdio.h>

int ge(float x, float y);

int main() {
	printf("Kevin Conte\n");
	printf("Assignment 2, Part 3\n\n");

	ge(-0.0f, 0.0f);

	return 0;
}

int ge(float x, float y) {
	unsigned int ux = *((unsigned int*) &x);
	unsigned int uy = *((unsigned int*) &y);
	unsigned int sx = ux >> 31;
	unsigned int sy = uy >> 31;
	ux <<= 1;
	uy <<= 1;
	
	return 0;
}
