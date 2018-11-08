#include <stdio.h>

int main() {
	FILE * file = fopen("yellow_diagonal_solution.pnm", "r");

	for(int i = 0; i < 18; i++) {
		unsigned char c = fgetc(file);
		if(c != '\n') {
			printf("0x%02X ", c);
		} else {
			printf("0x%02X\n", c);
		}
	}

	printf("\n");

	fclose(file);
	return 0;
}
