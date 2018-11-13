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

/* ==== START PROVIDED CODE ==== */
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
/* ====  END PROVIDED CODE  ==== */

void f_optimized(array_t a, int x, int y) {
	int val;
	/* N is globally defined, no need to call a function for it */
	for(int i = 0; i < N; ++i) {
		/* Rather than calculate the multiplication part of val in the inner loop, */
		/* Calculate it once and add j to it each iteration */
		/* This reduces the number of multiplication calls by N */
		val = i * x * y;
		for(int j = 0; j < N; ++j) {
			a[i][j] = val + j;
		}
	}
}

void print_array(array_t a) {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			printf("%2d ", a[i][j]);
		}
		printf("\n");
	}
}

int main() {
	array_t a = {
		{ 1, 2, 3, 4},
		{ 5, 6, 7, 8},
		{ 9,10,11,12},
		{13,14,15,16}
	};

	print_array(a);
	printf("\n");

	f_optimized(a, 2, 2);

	print_array(a);
	printf("\n");
	return 0;
}
