/*
   Kevin Conte
   951620146

   26 October 2018
   =====================================
   Assignment 4
   Part 1
 */

#include <stdio.h>

/*
   Provided x86-64 Code
   ====================

loop:
	movq %rsi, %rcx    # move b into %rcx to grab least sig. byte
	movl $1, %edx      # mask = 1
	movl $0, %eax      # result = 0
.L2:
	testq %rdx, %rdx   # mask == 0 ?
	je    .L4          # if so, exit loop
	movq %rdx, %r8     # %r8 = mask
	andq %rdi, %r8     # a & mask
	orq  %r8, %rax     # result |= (a & mask)
	salq %cl, %rdx     # mask <<= b
	jmp  .L2           # loop around
.L4:
	ret                # return result
 */

// Loop method
long loop(long a, long b) {
	long result = 0;
	for (long mask = 1; mask != 0; mask <<= b) {
		result |= (a & mask);
	}
	return result;
}

// Main method
int main() {
	long a = 1;
	long b = 5;
	printf("loop(%ld, %ld): %ld\n", a, b, loop(a, b));

	a = 2;
	b = 4;
	printf("loop(%ld, %ld): %ld\n", a, b, loop(a, b));

	a = 3;
	b = 3;
	printf("loop(%ld, %ld): %ld\n", a, b, loop(a, b));

	a = 4;
	b = 2;
	printf("loop(%ld, %ld): %ld\n", a, b, loop(a, b));

	a = 5;
	b = 1;
	printf("loop(%ld, %ld): %ld\n", a, b, loop(a, b));

	return 0;
}
