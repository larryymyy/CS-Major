/*
   Kevin Conte
   951620146

   26 October 2018
   =====================================
   Assignment 4
   Part 3
 */

#include <stdio.h>

/*
   Provided x86-64 Code
   ====================

.L3:
	movq (%rax), %rcx    # t1 = a[i][j]
	movq (%rdx), %rsi    # t2 = a[j][i]
	movq %rsi, (%rax)    # a[i][j] = t2
	movq %rcx, (%rdx)    # a[j][i] = t1
	addq $8, %rax        # columnPtr += sizeof(long)
	addq $32, %rdx       # rowPtr += sizeof(long) * N
	cmpq %r9, %rax       # j < i ?
	jne  .L3             # loop
 */

#define N 4
typedef long array_t[N][N];


// Transpose method
void transpose(array_t a) {
	long * ptr = &a[0][0]; // Address of the first element, use offsets to find correct value
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < i; ++j) {
			long t1 = *(ptr + (i * N) + j); // t1 = a[i][j]
			*(ptr + (i * N) + j) = *(ptr + (j * N) + i); // a[i][j] = a[j][i]
			*(ptr + (j * N) + i) = t1; // a[j][i] = t1
		}
	}
}


// Prints out the array
void print_array(array_t a) {
	for(int i = 0; i < N; i++) {
		printf("[ ");
		for(int j = 0; j < N - 1; j++) {
			printf("%ld, ", a[i][j]);
		}
		printf("%ld ]\n", a[i][N - 1]);
	}
	printf("\n");
}


// Main Method
int main() {
	// Declare array
	array_t array = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};

	// Print Array
	print_array(array);

	// Transpose Array
	transpose(array);

	// Print Array
	print_array(array);
	return 0;
}
