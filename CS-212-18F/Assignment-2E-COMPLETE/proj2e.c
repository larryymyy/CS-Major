#include <stdio.h>
#include <stdlib.h>

void parse(char * src, int * dest);

int main(int argc, char * argv[]) {
	if(argc != 4) {
		printf("Usage: %s <integer> <+ or -> <integer>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	char *number1 = argv[1];
	char *operation = argv[2];
	char *number2 = argv[3];

	int first_number = 0, second_number = 0;
	parse(number1, &first_number);
	parse(number2, &second_number);

	if((operation[0] != '-' && operation[0] != '+') || operation[1] != '\0') {
		printf("ERROR: operation may only be + or -\n");
		exit(EXIT_FAILURE);
	}

	switch(operation[0]) {
		case '-':
			printf("%d\n", first_number - second_number);
			break;
		case '+':
			printf("%d\n", first_number + second_number);
			break;
	}

	exit(EXIT_SUCCESS);
}

void parse(char * src, int * dest) {
	int i = 0;
	if(src[0] == '-')
		i++;
	char current = src[i++];

	while(1) {
		if(current == '\0') {
			break;
		} else if(current - '0' > 9 || current - '0' < 0) {
			printf("ERROR: number has character that is outside 0-9\n");
			exit(EXIT_FAILURE);
		} else if((src[0] == '-' && i > 10) ||
				  (src[0] != '-' && i > 9)) {
			printf("ERROR: number has 10 or more digits\n");
			exit(EXIT_FAILURE);
		}
		*dest *= 10;
		*dest += (current - '0');
		current = src[i++];
	}

	if(src[0] == '-')
		*dest *= -1;
}
