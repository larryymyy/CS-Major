/*
   Kevin Conte
   951620146

   17 October 2018
   =====================================
   Assignment 3
   Part 1
 */

#include <stdio.h>
#include <stdlib.h>

/* IntArray struct */
struct IntArray {
	int length;
	int *dataPtr;
};

/* Method prototypes */
struct IntArray* mallocIntArray(int length);
void freeIntArray(struct IntArray *arrayPtr);
void readIntArray(struct IntArray *array);
void swap(int *xp, int *yp);
void sortIntArray(struct IntArray *array);
void printArray(struct IntArray *array);

/* Allocates memory for the integer array */
struct IntArray* mallocIntArray(int length) {
	struct IntArray * intArray = malloc(1 * sizeof(struct IntArray));
	intArray->length = length;
	intArray->dataPtr = malloc(length * sizeof(int));
	return intArray;
};

/* Frees the memory used by the integer array */
void freeIntArray(struct IntArray *arrayPtr) {
	free(arrayPtr->dataPtr);
	free(arrayPtr);
	return;
}

/* Obtains values for the integer array */
void readIntArray(struct IntArray *array) {
	int i;
	for(i = 0; i < array->length; i++) {
		int value, temp, valid;
		printf("Enter int: ");
		valid = scanf("%d", &value);
		while(valid != 1) {
			while((temp = getchar()) != EOF && temp != '\n');
			printf("Invalid input\n");
			printf("Enter int: ");
			valid = scanf("%d", &value);
		}
		array->dataPtr[i] = value;
	}
	return;
}

/* Swaps two values in memory */
void swap(int *xp, int *yp) {
	int temp = *(xp);
	*(xp) = *(yp);
	*(yp) = temp;
	return;
}

/* Algorithm obtained from: https://en.wikipedia.org/wiki/Selection_sort#Implementation */
void sortIntArray(struct IntArray *array) {
	int i, j;
	int n = array->length;
	int * data = array->dataPtr;
	for(i = 0; i < n-1; i++) {
		int min = i;
		for(j = i + 1; j < n; j++) {
			if(data[j] < data[min]) {
				min = j;
			}
		}
		if(min != i) {
			swap(&data[i], &data[min]);
		}
	}
	return;
}

/* Prints out the IntArray */
void printArray(struct IntArray *array) {
	int i;
	printf("[ ");
	for(i = 0; i < array->length - 1; i++) {
		printf("%d, ", array->dataPtr[i]);
	}
	printf("%d ]\n", array->dataPtr[array->length - 1]);
	return;
}

/* Main Method */
int main() {
	struct IntArray * array;

	int length, valid, temp;
	printf("Enter length: ");
	valid = scanf("%d", &length);
	while(valid != 1) {
		while((temp = getchar()) != EOF && temp != '\n');
		printf("Invalid input\n");
		printf("Enter length: ");
		valid = scanf("%d", &length);
	}

	array = mallocIntArray(length);
	readIntArray(array);
	sortIntArray(array);
	printArray(array);
	freeIntArray(array);

	return EXIT_SUCCESS;
}
