#include <stdio.h>

int main() {
	unsigned int argb = 0x12345678;

	// convert argb to rgba (0xAARRGGBB to 0xRRGGBBAA)
	// 1. isolate a in low-order bits (0xAARRGGBB to 0x000000AA)
	unsigned int a = argb >> 24;

	// 2. make room for a to the right of rgb (0xAARRGGBB to 0xRRGGBB00)
	unsigned int rgbx = argb << 8;

	// 3. combine rgbx and a (0xRRGGBB00 | 0x000000AA to 0xRRGGBBAA)
	unsigned int rgba = rgbx | a;

	printf("0x%08X\n", rgba);

	return 0;
}
