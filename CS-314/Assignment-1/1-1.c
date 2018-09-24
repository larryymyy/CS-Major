/*
   Kevin A. Conte
   951620146

   3 Oct 2018
   ================================================

   Assignment #1

   Part 1-1
*/

#include <stdio.h>
#include <locale.h> /* Allows for number formatting */

/* Prototypes */
void printBytes(unsigned char *start, int len);
void printShort(short x);
void printInt(int x);
void printLong(long x);
void printFloat(float x);
void printDouble(double x);

/* main method */
int main() {

	setlocale(LC_NUMERIC, "");	/* allow number formatting in the form %'d, %'ld, etc. */

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
	long   long_test  =  1234567891011; 
	float  float_test =  1.234567e12; 
	double double_test = 1.234567e123;

	printf("Short Test:\nValue: %'d\nBytes:", short_test);
	printShort(short_test);

	printf("\nInt Test:\nValue: %'d\nBytes:", int_test);
	printInt(int_test);

	printf("\nLong Test:\nValue: %'ld\nBytes:", long_test);
	printLong(long_test);
	
	printf("\nFloat Test:\nValue: %'f\nBytes:", float_test);
	printFloat(float_test);

	printf("\nDouble Test:\nValue: %'f\nBytes:", double_test);
	printDouble(double_test);

	return 0;
}

/* Code Provided by Assignment Description */
/* ================================================ */

void printBytes(unsigned char *start, int len) {
	for(int i = 0; i < len; i++) {
		printf(" 0x%.2x", start[i]);
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

/* printShort() implementation */
void printShort(short x) {
	printBytes((unsigned char *) &x, sizeof(short));
}

/* printLong() implementation */
void printLong(long x) {
	printBytes((unsigned char *) &x, sizeof(long));
}

/* printDouble() implementation */
void printDouble(double x) {
	printBytes((unsigned char *) &x, sizeof(double));
}
