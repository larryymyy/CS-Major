#include <stdio.h>
#include <stdlib.h>

enum flags {
	VALID,
	TOO_MANY_DIGITS,
	WRONG_CHARACTERS,
	INVALID_OPERATION
};

void parse(char * src, int * dest, enum flags * flag);
void report_error(enum flags flag);

int main(int argc, char * argv[]) {
	if(argc != 4) {
		printf("Usage: %s <integer> <+/-> <integer>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int val1, val2;
	enum flags valid;
	parse(argv[1], &val1, &valid);
	if(valid != VALID)
		report_error(valid);
	parse(argv[3], &val2, &valid);
	if(valid != VALID)
		report_error(valid);

	if(argv[2][1] != '\0')
		report_error(INVALID_OPERATION);

	switch(argv[2][0]) {
		case '-':
			printf("%d\n", val1 - val2);
			break;
		case '+':
			printf("%d\n", val1 + val2);
			break;
		default:
			report_error(INVALID_OPERATION);
			break;
	}

	exit(EXIT_SUCCESS);
}

void parse(char * src, int * dest, enum flags * flag) {
	*flag = VALID;
	int i = 0;
	*dest = 0;
	if(src[0] == '-')
		i++;
	while(src[i] != '\0') {
		*dest *= 10;
		if(src[i] - '0' < 0 || src[i] - '0' > 9) {
			*flag = WRONG_CHARACTERS;
			return;
		}
		*dest += (src[i] - '0');
		i++;
	}
	if(i >= 10)
		*flag = TOO_MANY_DIGITS;
	if(src[0] == '-')
		*dest *= -1;
}

void report_error(enum flags flag) {
	switch(flag) {
		case TOO_MANY_DIGITS:
			printf("ERROR: number has 10 or more digits\n");
			break;
		case WRONG_CHARACTERS:
			printf("ERROR: number has character that is outside 0-9\n");
			break;
		case INVALID_OPERATION:
			printf("ERROR: operation may only be + or -\n");
			break;
		default:
			break;
	}
	exit(EXIT_FAILURE);
}
