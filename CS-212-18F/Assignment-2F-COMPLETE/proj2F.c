#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
	if(argc != 3) {
		printf("Usage: %s <input> <output>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE * input = fopen(argv[1], "r");
	FILE * output = fopen(argv[2], "w+");

	for(int i = 0; i < 5; i++) {
		fseek(input, i * 40, SEEK_SET);
		for(int j = 0; j < 5; j++) {
			int val;
			fread(&val, 4, 1, input);
			fprintf(output, "%d\n", val);
		}
	}

	fclose(input);
	fclose(output);
	exit(EXIT_SUCCESS);
}
