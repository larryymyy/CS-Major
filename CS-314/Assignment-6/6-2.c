/*
   Kevin Conte
   951620146

   16 November 2018
   =====================================
   Assignment 6
   Part 2
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/* ==== START PROVIDED C CODE ==== */
void inner(float * u, float * v, int length, float * dest) {
	int i;
	float sum = 0.0f;
	for (i = 0; i < length; i++) {
		sum += u[i] * v[i];
	}
	*dest = sum;
}
/* ====  END PROVIDED C CODE  ==== */

/* ==== START PROVIDED x86-64 CODE ==== */
#if 0
# u in %rbx, v in %rax, length in %rcx, i in %rdx, sum in %xmm1
.L87:
	movss (%rbx, %rdx, 4), %xmm0 # Get u[i]
	mulss (%rax, %rdx, 4), %xmm0 # Multiply by v[i]
	adds %xmm0, %xmm1            # Add to sum
	addq $1, %rdx                # Increment i
	cmpq %rcx, %rdx              # Compare i to length
	jl .L87                      # If <, keep looping
#endif
/* ====  END PROVIDED x86-64 CODE  ==== */

void inner2(float * u, float * v, int length, float * dest) {
	int i;
	for(i = 0; i < length; i += 4) {

	}
}

int main() {
	long val = 0;
	struct timeval start, end;
	gettimeofday(&start, NULL);
	gettimeofday(&end, NULL);
	long elapsed = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);
	printf("%.3f\n", elapsed / 1000000.0);
	return 0;
}
