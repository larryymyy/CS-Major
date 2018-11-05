#include <stdio.h>
#include <stdlib.h>

int main() {
	int val1;
	int val2;
	char operation;

	char current = getchar();
	while(current != ' ') {
		val1 += (current - '0');
		val1 *= 10;
		current = getchar();
	}

	while(current == ' ')
		current = getchar();

	operation = getchar();

	while(current == ' ')
		current = getchar();

	while(current != EOF && current != '\n') {
		val2 += (current - '0');
		val2 *= 10;
		current = getchar();
	}

	printf("%d %c %d\n", val1, operation, val2);

	return 0;
}
