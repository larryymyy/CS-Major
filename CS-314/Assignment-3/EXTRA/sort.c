#include "main.h"

/* Selection Sort */
void selection_sort(struct IntArray * array) {
	printf("Selection sorting...\n");
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

/* Bubble Sort */
void bubble_sort(struct IntArray * array) {
	printf("Bubble sorting...\n");
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

/* Insertion Sort */
void insertion_sort(struct IntArray * array) {
	printf("Insertion sorting...\n");
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

/* Merge Sort */
void merge_sort(struct IntArray * array) {
	printf("Merge sorting...\n");
	_merge_sort(array->dataPtr, array->length);
}

void _merge_sort(int * array, int n) {
	if(n < 2)
		return;
	int mid, i, *a, *b;
	mid = n / 2;
	a = (int *)malloc(mid * sizeof(int));
	b = (int *)malloc((n - mid) * sizeof(int));

	for(i = 0; i < mid; i++)
		a[i] = array[i];
	for(i = mid; i < n; i++)
		b[i - mid] = array[i];

	_merge_sort(a, mid);
	_merge_sort(b, n - mid);
	merge(array, a, mid, b, n - mid);
	free(a);
	free(b);
}

void merge(int * array, int * a, int aCount, int * b, int bCount) {
	int i, j, k;
	i = j = k = 0;
	while(i < aCount && j < bCount) {
		if(a[i] < b[j])
			array[k++] = a[i++];
		else
			array[k++] = b[j++];
	}
	while(i < aCount)
		array[k++] = a[i++];
	while(j < bCount)
		array[k++] = b[j++];
}

/* Heap Sort */
void heap_sort(struct IntArray * array) {
	printf("Heap sorting...\n");
	for(int i = array->length / 2 - 1; i >= 0; i--)
		heapify(array->dataPtr, array->length, i);
	for(int i = array->length - 1; i >= 0; i--) {
		swap(&array->dataPtr[0], &array->dataPtr[i]);
		heapify(array->dataPtr, i, 0);
	}
}

void heapify(int * array, int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if(l < n && array[l] > array[largest])
		largest = l;
	if(r < n && array[r] > array[largest])
		largest = r;
	if(largest != i) {
		swap(&array[i], &array[largest]);
		heapify(array, n, largest);
	}
}
