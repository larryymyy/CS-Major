#include <stdio.h>

int main() {
	printf("This is an example program used in class!\n\n\n");

	printf("Convert argb -> rgba\n");

	unsigned int argb = 0x12345678;
	unsigned int a = argb >> 24;
	unsigned int rgbx = argb << 8;
	unsigned int rgba = rgbx | a;

	printf("argb: 0x%08X\n", argb);
	printf("a:    0x%02X\n", a);
	printf("rgbx: 0x%08X\n", rgbx);
	printf("rgba: 0x%08X\n", rgba);

	return 0;
}
