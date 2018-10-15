/*
   Kevin Conte
   951620146

   26 October 2018
   =====================================
   Assignment 4
   Part 2
 */

#include <stdio.h>
#include <stdlib.h>

/*
int sum(int from, int to) {
	int result = 0;
	do {
		result += from;
		++from;
	} while (from <= to);
	return result;
}
*/

long sum(long from, long to) {
	long result = 0;
	/* Ensure that argument *from* is in %rdi */
	/* argument *to* is in %rsi, *result* is in %rax - do not modify */
	__asm__("movq %0, %%rdi # from in rdi;" :: "r" ( from ));
	__asm__("movq %0, %%rsi # to in rsi;" :: "r" ( to ));
	__asm__("movq %0, %%rax # result in rax;" :: "r" ( result ));

	/* Your x86-64 code goes below - comment each instruction... */
	__asm__(".LOOP:				# label for loop;");
	__asm__("addq %rdi, %rax	# result += from;");
	__asm__("incq %rdi			# ++from;");
	__asm__("cmpq %rsi, %rdi	# compare *from* to *to*;");
	__asm__("jle .LOOP			# Jump if *from* <= *to* to LOOP");

	/* Ensure that *result* is in %rax for return - do not modify. */
	__asm__("movq %%rax, %0 # result in rax;" : "=r" ( result ));
	return result;
}

int main() {

	long from = 1;
	long to = 6;
	printf("sum(%ld, %ld): %ld\n", from, to, sum(from, to));

	from = 3;
	to = 5;
	printf("sum(%ld, %ld): %ld\n", from, to, sum(from, to));

	return EXIT_SUCCESS;
}
