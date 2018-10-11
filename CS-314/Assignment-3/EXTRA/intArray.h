#include <stdio.h>
#include <stdlib.h>

struct IntArray {
	int length;
	int *dataPtr;
};

struct IntArray* mallocIntArray(int length);
void freeIntArray(struct IntArray * array);
void readIntArray(struct IntArray * array);
void swap(int * x, int * y);
void printIntArray(struct IntArray * array);
