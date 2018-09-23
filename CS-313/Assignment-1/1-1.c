/*
   Kevin A. Conte
   951620146

   3 Oct 2018
   ================================================

   Assignment #1

   Part 1-1
*/

#include <stdio.h>
#include <locale.h>

/* Code Provided by Assignment Description */
/* ================================================ */

void printBytes(unsigned char *start, int len) {
	for(int i = 0; i < len; i++) {
		printf(" %.2x", start[i]);
	}
	printf("\n");
}

void printInt(int x) {
	printBytes((unsigned char *) &x, sizeof(int));
}

void printFloat(float x) {
	printBytes((unsigned char*) &x, sizeof(float));
}

/* ================================================ */

void printShort(short x) {
	printBytes((unsigned char *) &x, sizeof(short));
}

void printLong(long x) {
	printBytes((unsigned char *) &x, sizeof(long));
}

void printDouble(double x) {
	printBytes((unsigned char *) &x, sizeof(double));
}

int main(int argc, char **argv) {

	setlocale(LC_NUMERIC, "");

	/*
	   Observations
	   ============
	   
	   printBytes() prints out in the opposite order than I expected.
	   i.e.:
	   		I expected printInt(255) to produce: 00 00 00 ff
			but it produced: ff 00 00 00

			I suspect it means that the computer reads values in reverse order
			(or at least stores them in memory in reverse) for it to perform
			arithmetic properly.

			It is interesting that the bits are not reversed, but whole bytes
	*/

	short  short_test =  12345;
	int    int_test   =  1234567890;
	long   long_test  =  1234567891011121314; 
	float  float_test =  1.012345e32; 
	double double_test = 1.0123456789123456e64;

	printf("Short Test:  %'d ->", short_test);
	printShort(short_test);

	printf("Int Test:    %'d ->", int_test);
	printInt(int_test);

	printf("Long Test:   %'ld ->", long_test);
	printLong(long_test);
	
	printf("Float Test:  %'f ->", float_test);
	printFloat(float_test);

	printf("Double Test: %'f ->", double_test);
	printDouble(double_test);

	return 0;
}
