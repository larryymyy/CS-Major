#include <stdio.h>

void printBytes(unsigned char *start, int len);
void printShort(short x);
void printInt(int x);
void printLong(long x);
void printFloat(float x);
void printDouble(double x);

int main() {
	printf("Print Int:\n %d\n");
	printInt(123456789);
	return 0;
}

void printBytes(unsigned char *start, int len) {
}
