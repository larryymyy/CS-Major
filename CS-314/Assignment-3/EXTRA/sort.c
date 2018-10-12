#include "main.h"

/* Selects the appropriate sorting method */
void sort(struct IntArray * array, enum SORT_OPTION option) {
	switch(option) {
		case SELECTION:
			printf("Sorting using selection sort . . .\n");
			selection_sort(array);
			break;
		case BUBBLE:
			printf("Sorting using bubble sort . . .\n");
			bubble_sort(array);
			break;
		case INSERTION:
			printf("Sorting using insertion sort . . .\n");
			insertion_sort(array);
			break;
		default:
			printf("Sorting Method Not Implemented!\n");
			break;
	}
}

/* Sorts via selection sort */
void selection_sort(struct IntArray * array) {
	int n = array->length;
	int * data = array->dataPtr;
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (data[j] < data[min]) {
				min = j;
			}
		}
		if (min != i) {
			swap(&data[i], &data[min]);
		}
	}
}

/* Sorts via bubble sort */
void bubble_sort(struct IntArray * array) {
	int n = array->length;
	int * data = array->dataPtr;
	int swapped = 1;
	while (swapped == 1) {
		swapped = 0;
		for(int i = 0; i < n - 1; i++) {
			if (data[i] > data[i + 1]) {
				swap(&data[i], &data[i + 1]);
				swapped = 1;
			}
		}
		n--;
	}
}

/* Sorts via insertion sort */
void insertion_sort(struct IntArray * array) {
	int n = array->length, i = 1, j;
	int * data = array->dataPtr;
	for(i = 1; i < n; i++) {
		j = i;
		while(j > 0 && data[j - 1] > data[j]) {
			swap(&data[j], &data[j - 1]);
			j--;
		}
	}
}
