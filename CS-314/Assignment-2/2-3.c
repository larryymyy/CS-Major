/*
   Kevin Conte
   951620146

   10 October 2018
   =====================================
   Assignment 2
   Part 3
 */

#include <stdio.h>

/* Prototype */
int ge(float x, float y);

/* Main Method */
int main() {
	printf("Kevin Conte\n");
	printf("Assignment 2, Part 3\n\n");

	printf("ge(0.0f, 0.0f):  %d\n", ge(0.0f, 0.0f));
	printf("ge(-0.0f, 0.0f): %d\n", ge(-0.0f, 0.0f));
	printf("ge(-1.0f, 0.0f): %d\n", ge(-1.0f, 0.0f));
	printf("ge(0.0f, 1.0f):  %d\n", ge(0.0f, 1.0f));
	printf("ge(1.0f, 0.0f):  %d\n", ge(1.0f, 0.0f));
	printf("ge(0.0f, -1.0f): %d\n", ge(0.0f, -1.0f));

	return 0;
}

/* ge() Method */
int ge(float x, float y) {
	unsigned int ux = *((unsigned int*) &x); /* convert x to raw bits */
	unsigned int uy = *((unsigned int*) &y); /* convert y to raw bits */
	unsigned int sx = ux >> 31; /* extract sign bit of ux */
	unsigned int sy = uy >> 31; /* extract sign bit of uy */
	ux <<= 1; /* drop sign bit of ux */
	uy <<= 1; /* drop sign bit of uy */
	
	return (ux == 0.0f && uy == 0.0f) ||
		   (sx < sy) ||
		   ((sx == sy) && (sx > 0) && (ux <= uy)) ||
		   ((sx == sy) && (sx == 0) && (ux >= uy));

}
