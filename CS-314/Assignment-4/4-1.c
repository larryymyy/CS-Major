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
	movq  %rsi, %rcx	# Set the %rcx register to the value of 'b'
	movl  $1, %edx		# Set the mask to the constant value '1'
	movl  $0, %eax		# Set the result to the constant value '0'
.L2:
	testq %rdx, %rdx	# Test the value of mask and set appropriate flags
	je    .L4			# If mask is equal to 0, jump to label .L4
	movq  %rdx, %r8		# Copy the value of mask into register 8
	andq  %rdi, %r8		# And the value of a with register 8
	orq   %r8, %rax		# Or the value of register 8 with result
	salq  %cl, %rdx		# Shift mask left by b
	jmp   .L2			# Jump to label .L2
.L4:
	ret					# Return result
 */

long loop(long a, long b) {
	long result = 0;
	for(long mask = 1; mask != 0; mask <<= b) {
		result |= (a & mask);
	}
	return result;
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
