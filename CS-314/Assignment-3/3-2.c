/*
   Kevin Conte
   951620146

   17 October 2018
   =====================================
   Assignment 3
   Part 2
 */

#include <stdio.h>
#include <stdlib.h>

/* Method prototype */
long decode(long a, long b, long c);

/* Main Method */
int main() {

	long a = 1l;
	long b = 2l;
	long c = 4l;
	printf("decode(%ld, %ld, %ld): %ld\n", a, b, c, decode(a, b, c));

	a = 3l;
	b = 5l;
	c = 7l;
	printf("decode(%ld, %ld, %ld): %ld\n", a, b, c, decode(a, b, c));

	a = 10l;
	b = 20l;
	c = 30l;
	printf("decode(%ld, %ld, %ld): %ld\n", a, b, c, decode(a, b, c));

	return EXIT_SUCCESS;
}

/*
   Provided x86-64 Code
===========================================================================
   subq  %rdx, %rsi		# b -= c
   imulq %rsi, %rdi		# a *= b
   salq  $63, %rsi		# b <<= 63
   sarq  $63, %rsi		# b >>= 63
   movq  %rdi, %rax		# result = a
   xorq  %rsi, %rax		# result ^= b
 */

/* Decode method */
long decode(long a, long b, long c) {
	long result;
	b -= c;
	a *= b;
	b <<= 63;
	b >>= 63;
	result = a;
	result ^= b;
	return result;
}
