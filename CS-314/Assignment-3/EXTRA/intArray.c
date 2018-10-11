#include "intArray.h"

struct IntArray* mallocIntArray(int length) {
	struct IntArray * array = malloc(1 * sizeof(struct IntArray));
	array->length = length;
	array->dataPtr = malloc(length * sizeof(int));
	return array;
}

void freeIntArray(struct IntArray * array) {
	free(array->dataPtr);
	free(array);
}

void readIntArray(struct IntArray * array) {
	int value, valid, gc;
	for( int i = 0; i < array->length; i++) {
		printf("Enter int: ");
		valid = scanf("%d", &value);
		while(valid != 1) {
			while((gc = getchar()) != EOF && gc != 0);
			printf("Invalid input.\n");
			printf("Enter int: ");
			valid = scanf("%d", &value);
		}
		array->dataPtr[i] = value;
	}
}

void swap(int * x, int * y) {
	int x_val = *x;
	*x = *y;
	*y = x_val;
}

void printIntArray(struct IntArray * array) {
	printf("[ ");
	for(int i = 0; i < array->length - 1; i++) {
		printf("%d, ", array->dataPtr[i]);
	}
	printf("%d ]\n", array->dataPtr[array->length - 1]);
}
