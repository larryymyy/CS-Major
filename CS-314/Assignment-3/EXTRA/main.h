#include "intArray.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main();

enum SORT_OPTION {
	SELECTION,
	BUBBLE,
	INSERTION,
	DEFAULT=BUBBLE
};

void sort(struct IntArray * array, enum SORT_OPTION option);

void selection_sort(struct IntArray * array);
void bubble_sort(struct IntArray * array);
void insertion_sort(struct IntArray * array);
