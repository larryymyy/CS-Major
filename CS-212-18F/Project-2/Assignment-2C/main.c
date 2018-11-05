#include <stdio.h>
#include <stdlib.h>

int parseInt(char * src, int * dest);

int main(int argc, char * argv[]) {
	if(argc != 4) {
		printf("Usage: %s <integer> <+ or -> <integer>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	char * first_number = argv[1];
	int val1, val2;
	char * operation = argv[2];
	char * second_number = argv[3];
	
	int valid = parseInt(first_number, &val1);
	if(valid != 1) {
		printf("[VAL 1] Usage: %s <integer> <+ or -> <integer>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	valid = parseInt(second_number, &val2);
	if(valid != 1) {
		printf("[VAL 2] Usage: %s <integer> <+ or -> <integer>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int result = val1;
	switch(operation[0]) {
		case '-':
			result -= val2;
			break;
		case '+':
			result += val2;
			break;
		default:
			printf("Invalid operator!\n");
			exit(EXIT_FAILURE);
	}
	printf("%d\n", result);

	exit(EXIT_SUCCESS);
}

int parseInt(char * src, int * dest) {
	int i = 0;
	if(src[0] == '-')
		i++;
	*dest = 0;
	while(src[i] != '\0') {
		*dest *= 10;
		if(src[i] - '0' < 0 || src[i] - '0' > 9)
			return 0;
		*dest += (src[i++] - '0');
	}
	if(src[0] == '-')
		*dest *= -1;
	return 1;
}
