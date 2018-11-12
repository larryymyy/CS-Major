/*
   Kevin Conte
   951620146

   16 November 2018
   =====================================
   Assignment 6
   Part 2
 */

#include <stdio.h>

/* Provided C Code */
# if 0
void inner(float * u, float * v, int length, float * dest) {
	int i;
	float sum = 0.0f;
	for(i = 0; i < length; i++) {
		sum += u[i] * v[i];
	}
	*dest = sum;
}
#endif

/* Provided x86-64 Code */
#if 0
.L87:
	movss (%rbx, %rdx, 4), %xmm0 # Get u[i]
	mulss (%rax, %rdx, 4), %xmm0 # Multiply by v[i]
	adds %xmm0, %xmm1            # Add to sum
	addq $1, %rdx                # Increment i
	cmpq %rcx, %rdx              # Compare i to length
	jl .L87                      # If <, keep looping
#endif


int main() {
	return 0;
}
