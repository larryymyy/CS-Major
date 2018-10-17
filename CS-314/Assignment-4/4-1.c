/*
   Kevin Conte
   951620146

   26 October 2018
   =====================================
   Assignment 4
   Part 1
 */

#include <stdio.h>
#include <stdlib.h>

/*
   x86-64
   ------
   %rdi = a
   %rsi = b
===========================================================================
loop:
	movq  %rsi, %rcx	# %rcx = b (to grab least significant bit)
	movl  $1, %edx		# mask = 1
	movl  $0, %eax		# result = 0
.L2:
	testq %rdx, %rdx	# test if mask == 0
	je    .L4			# mask == 0 -> jump to .L4
	movq  %rdx, %r8		# %r8 = mask
	andq  %rdi, %r8		# a & %r8  [a & mask]
	orq   %r8, %rax		# result |= %r8  [result |= (a & mask)]
	salq  %cl, %rdx		# mask <<= b
	jmp   .L2			# jump to .L4
.L4:
	ret					# return result
 */

long loop(long a, long b) {
	long result = 0;
	for(long mask = 1; mask != 0; mask <<= b) { /* Loop until mask is 0, by shifting left by 'b' bits */
		result |= (a & mask); /* Or the value of result with (a & mask) */
	}
	return result; /* Return result */
}

int main() {
	long a = 1;
	long b = 5;
	printf("loop(%ld, %ld): %ld\n", a, b, loop(a, b));

	a = 2;
	b = 4;
	printf("loop(%ld, %ld): %ld\n", a, b, loop(a, b));

	a = b = 3;
	printf("loop(%ld, %ld): %ld\n", a, b, loop(a, b));

	a = 4;
	b = 2;
	printf("loop(%ld, %ld): %ld\n", a, b, loop(a, b));

	a = 5;
	b = 1;
	printf("loop(%ld, %ld): %ld\n", a, b, loop(a, b));
	return EXIT_SUCCESS;
}
