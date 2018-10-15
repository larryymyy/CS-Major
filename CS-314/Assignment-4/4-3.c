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
   ------
.L3:
	cmpq %rcx, %rsi		# (i - j)
	jle  .L7			# jump to .L7 if i <= j
	movq (%rdx), %r9	# t1 = a[i][j]
	movq (%rax), %r8	# t2 = a[j][i]
	movq %r9, (%rax)	# a[i][j] = t2
	movq %r8, (%rdx)	# a[j][i] = t1
	addq $8, %rax
	addq $32, %rdx
	addq $1, %rcx
	jmp .L3
 */
int main() {
	return EXIT_SUCCESS;
}
