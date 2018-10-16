/*
   Kevin Conte
   951620146

   26 October 2018
   =====================================
   Assignment 4
   Part 3
 */

#include <stdio.h>
#include <stdlib.h>

#define N 4
typedef long array_t[N][N];

/*
   x86-64
===========================================================================
.L3:
	cmpq %rcx, %rsi		# (i - j)
	jle  .L7			# jump to .L7 if i <= j
	movq (%rdx), %r9	# t1 = a[i][j]
	movq (%rax), %r8	# t2 = a[j][i]
	movq %r9, (%rax)	# a[i][j] = t2
	movq %r8, (%rdx)	# a[j][i] = t1
	addq $8, %rax		# increase column pointer by 8
	addq $32, %rdx		# increase row pointer by 32
	addq $1, %rcx		# j += 1
	jmp .L3
 */

void transpose(array_t a) {
	long * ptr = &a[0][0];
	long * ij;
	long * ji;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < i; j++) {
			ij = ptr + (N * i) + j;
			ji = ptr + (N * j) + i;
			long t1 = *ij;
			long t2 = *ji;
			*ij = t2;
			*ji = t1;
		}
	}
}

int main() {
	array_t a = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};

	printf("{ ");
	for(int i = 0; i < N; i++) {
		printf("{");
		for(int j = 0; j < N; j++) {
			printf(" %ld", a[i][j]);
		}
		printf(" } ");
	}
	printf("}\n");

	transpose(a);

	printf("{ ");
	for(int i = 0; i < N; i++) {
		printf("{");
		for(int j = 0; j < N; j++) {
			printf(" %ld", a[i][j]);
		}
		printf(" } ");
	}
	printf("}\n");

	return EXIT_SUCCESS;
}
