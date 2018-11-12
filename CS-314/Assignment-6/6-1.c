/*
   Kevin Conte
   951620146

   16 November 2018
   =====================================
   Assignment 6
   Part 1
 */

#include <stdio.h>

#define N 4
typedef int array_t[N][N];

/* Provided C code */
#if 0
int dim() {
	return N;
}

void f(array_t a, int x, int y) {
	for(int i = 0; i < dim(); ++i) {
		for(int j = 0; j < dim(); ++j) {
			a[i][j] = i * x * y + j;
		}
	}
}
#endif

void g(array_t a, int x, int y) {
	/* No need to call a dim() procedure since N is defined globally */
	for(int i = 0; i < N; ++i) {
		/* Introduce local variable (minimize calls to multiply) */
		int val = i * x * y;
		for(int j = 0; j < N; ++j) {
			/* Increase val by j and store at a[i][j] */
			a[i][j] = val + j;
		}
	}
}

int main() {
	array_t a = {
		{ 1,  2,  3,  4},
		{ 5,  6,  7,  8},
		{ 9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	// Print out the array
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	g(a, 2, 2);

	// Print out array after being operated on
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
