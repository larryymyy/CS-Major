/*
   Kevin Conte
   951620146

   26 October 2018
   =====================================
   Assignment 4
   Part 1
 */

#include <stdio.h>

#define N 4
typedef int array_t[N][N];

// Provided C code
#if 1
int dim() {
	return N;
}

void f(array_t a, int x, int y) {
	for(int i = 0; i < dim(); ++i) {
		for(int j = 0; j < dim(); ++j) {
			*a[i][j] = i * x * y + j;
		}
	}
}
#endif


int main() {
	array_t a = {
		{ 1,  2,  3,  4},
		{ 5,  6,  7,  8},
		{ 9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	return 0;
}
