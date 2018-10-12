#include "main.h"

int main() {
	setlocale(LC_NUMERIC, "");
	srand(time(NULL));
	struct IntArray * array;

	int length = 0, valid, gc;

	printf("Enter length: ");
	valid = scanf("%d", &length);

	if (length <= 0)
		valid = 0;
	
	while (valid != 1) {
		while ((gc = getchar()) != EOF && gc != '\n');
		printf("Invalid input.\n");
		printf("Enter length: ");
		valid = scanf("%d", &length);
		if (length <= 0)
			valid = 0;
	}

	array = mallocIntArray(length);

	//readIntArray(array);
	/* Values in [-999, 999] */
	for(int i = 0; i < array->length; i++) {
		array->dataPtr[i] = rand() % 1000;
		array->dataPtr[i] *= (rand() % 2 == 0) ? -1 : 1;
	}

	printIntArray(array);
	sort(array, DEFAULT);
	printIntArray(array);
	freeIntArray(array);

	return EXIT_SUCCESS;
}
