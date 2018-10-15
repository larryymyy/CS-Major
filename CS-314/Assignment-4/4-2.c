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

int sum(int from, int to) {
	int result = 0;
	do {
		result += from;
		++from;
	} while (from <= to);
	return result;
}

long sum(long from, long to) {
	long result = 0;
	/* Ensure that argument *from* is in %rdi */
	/* argument *to* is in %rsi, *result* is in %rax - do not modify */
	__asm__("movq %0, %%rdi # from in rdi;" :: "r" ( from ));
	__asm__("movq %0, %%rsi # to in rsi;" :: "r" ( to ));
	__asm__("movq %0, %%rax # result in rax;" :: "r" ( result ));
	return result;
}

int main() {

	return EXIT_SUCCESS;
}
