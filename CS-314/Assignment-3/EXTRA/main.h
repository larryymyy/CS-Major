#include "intArray.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main();

/* Selection Sort */
void selection_sort(struct IntArray * array);

/* Bubble Sort */
void bubble_sort(struct IntArray * array);

/* Insertion Sort */
void insertion_sort(struct IntArray * array);

/* Merge Sort */
void merge_sort(struct IntArray * array);
void _merge_sort(int * array, int n);
void merge(int * array, int * a, int aCount, int * b, int bCount);

/* Heap Sort */
void heap_sort(struct IntArray * array);
void heapify(int * array, int n, int i);
