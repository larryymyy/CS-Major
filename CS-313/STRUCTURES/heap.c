#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int * values;
	int length;
	int heapsize;
} Heap;

void printHeap(Heap * heap) {
	for(int i = 0; i < heap->length; i++)
		printf("%d ", heap->values[i]);
	printf("\n");
}

void swap(int * x, int * y) {
	int t = *x;
	*x = *y;
	*y = t;
}

void heapify(Heap * heap, int i) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest;
	if(left <= heap->heapsize && heap->values[left] > heap->values[i])
		largest = left;
	else
		largest = i;
	if(right <= heap->heapsize && heap->values[right] > heap->values[largest])
		largest = right;
	if(largest != i) {
		swap(&heap->values[largest], &heap->values[i]);
		heapify(heap, largest);
	}
}

void buildMaxHeap(Heap * heap) {
	heap->heapsize = heap->length - 1;
	for(int i = (heap->length / 2) - 1; i >= 0; i--) {
		heapify(heap, i);
	}
}

void sort(Heap * heap) {
	buildMaxHeap(heap);
	printHeap(heap);
	for(int i = heap->length - 1; i >= 1; i--) {
		swap(&heap->values[0], &heap->values[i]);
		heap->heapsize--;
		heapify(heap, 0);
	}
}

int main() {
	Heap * heap = malloc(sizeof(Heap));
	heap->length = 7;
	heap->values = malloc(heap->length * sizeof(int));
	for(int i = 0; i < heap->length; i++)
		heap->values[i] = i + 1;
	printHeap(heap);
	sort(heap);
	printHeap(heap);
}
