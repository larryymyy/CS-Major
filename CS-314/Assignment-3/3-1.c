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
/* length specifies the length of the array */
/* dataPtr is the actual array, initialized in mallocIntArray with the length */
struct IntArray {
	int length;
	int *dataPtr;
};

/* Method prototypes */
struct IntArray* mallocIntArray(int length);		/* Allocates memory for an IntArray */
void freeIntArray(struct IntArray *arrayPtr);		/* Frees the memory used by an IntArray */
void readIntArray(struct IntArray *array);			/* Reads integers into an IntArray */
void swap(int *xp, int *yp);						/* Swaps two values in memory, particularly integers */
void sortIntArray(struct IntArray *array);			/* Sorts an IntArray */
void printArray(struct IntArray *array);			/* Prints out an IntArray */

/* Allocates memory for the integer array */
struct IntArray* mallocIntArray(int length) {
	/* Malloc the struct (Allocates memory for each of the properties of IntArray) */
	struct IntArray * intArray = malloc(1 * sizeof(struct IntArray));

	/* Set the length of the IntArray to the provided lenght (Input from user) */
	intArray->length = length;

	/* Malloc the IntArray's dataPtr with the specified length */
	intArray->dataPtr = malloc(length * sizeof(int));

	/* Return the pointer the newly allocated IntArray */
	return intArray;
};

/* Frees the memory used by the integer array */
void freeIntArray(struct IntArray *arrayPtr) {

	/* MUST free IntArray's dataPtr before freeing the actual IntArray */
	/* Otherwise, a memory leak could occur */

	/* Free the memory used by dataPtr */
	free(arrayPtr->dataPtr);

	/* Free the memory used by the IntArray */
	free(arrayPtr);
}

/* Obtains values for the integer array */
void readIntArray(struct IntArray *array) {
	/* Caps the user input to the size of the array, so as to avoid overflows */
	for(int i = 0; i < array->length; i++) {
		/* value is the actual value placed into the array at dataPtr[i] */
		/* temp is used to collect garbage in case the user inputs a non-integer */
		/* valid is used to determine the validity of the user's input (is it an integer or not?) */
		int value, temp, valid;
		
		/* Collect input */
		printf("Enter int: ");
		valid = scanf("%d", &value); /* scanf returns 1 if valid, 0 if invalid, and EOF if no stream to read from */
		
		/* Loop until a valid input is collected */
		/* (if needed, if a valid input was collected the first time, no loop will occur) */
		while(valid != 1) {

			/* Clear Garbage (otherwise scanf will use the \n character as input, leading to an infinite loop) */
			while((temp = getchar()) != EOF && temp != '\n');

			/* Alert user to invalid input */
			printf("Invalid input\n");

			/* Re-collect input */
			printf("Enter int: ");
			valid = scanf("%d", &value);
		}

		/* Insert valid input at dataPtr[i] */
		array->dataPtr[i] = value;
	}
}

/* Swaps two values in memory */
void swap(int *xp, int *yp) {
	/* Pretty self-explanatory. */
	/* Store x in a temp variable */
	/* Set x to y */
	/* Set y to temp */
	int temp = *(xp);
	*(xp) = *(yp);
	*(yp) = temp;
}

/* Algorithm obtained from: https://en.wikipedia.org/wiki/Selection_sort#Implementation */
void sortIntArray(struct IntArray *array) {
	int n = array->length; /* To avoid typing out array->length over and over */
	int * data = array->dataPtr; /* To avoid typing out array->dataPtr[] */
	for(int i = 0; i < n-1; i++) {
		/* Current index's element is assumed to be minimum value */
		int min = i;

		/* Loop through the rest of the array to see if a smaller value exists */
		/* If found, set minimum index to the new minimum index */
		for(int j = i + 1; j < n; j++) {
			if(data[j] < data[min]) {
				min = j;
			}
		}

		/* If a new minimum was found, swap dataPtr[i] with the new minimum */
		if(min != i) {
			swap(&data[i], &data[min]);
		}
	}
}

/* Prints out the IntArray */
void printArray(struct IntArray *array) {
	printf("[ ");
	for(int i = 0; i < array->length - 1; i++) {
		printf("%d, ", array->dataPtr[i]);
	}
	printf("%d ]\n", array->dataPtr[array->length - 1]);
	return;
}

/* Main Method */
int main() {
	struct IntArray * array;

	/* Same idea as the readIntArray input method, except no negative or zero values allowed */
	int length = 0, valid, temp;
	printf("Enter length: ");
	valid = scanf("%d", &length);
	if (length <= 0) /* If length <= 0, it is an invalid input */
		valid = 0;
	while(valid != 1) {
		while((temp = getchar()) != EOF && temp != '\n');
		printf("Invalid input\n");
		printf("Enter length: ");
		valid = scanf("%d", &length);
		if (length <= 0)
			valid = 0;
	}

	array = mallocIntArray(length);		/* malloc array */
	readIntArray(array);				/* read values into array */
	sortIntArray(array);				/* sort array */
	printArray(array);					/* print out */
	freeIntArray(array);				/* free memory */

	return EXIT_SUCCESS;
}
