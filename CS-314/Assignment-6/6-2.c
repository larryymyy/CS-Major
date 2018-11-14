/*
   Kevin Conte
   951620146

   16 November 2018
   =====================================
   Assignment 6
   Part 2
 */

#include <locale.h>
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
	float sum = 0.0f;
	for(i = 0; i < length - 3; i += 4) {
		/* Calculate accumulators */
		float a = u[i] * v[i];
		float b = u[i + 1] * v[i + 1];
		float c = u[i + 2] * v[i + 2];
		float d = u[i + 3] * v[i + 3];

		sum += a + b + c + d;
	}
	*dest = sum;
}


int main(int argc, char * argv[]) {
	setlocale(LC_NUMERIC, "");

	unsigned long long N = strtoull(argv[1], NULL, 10);

	struct timeval start, end;
	long elapsed;

	float * u = malloc(sizeof(float) * N);
	float * v = malloc(sizeof(float) * N);
	float result;

	for(int i = 0; i < N; i += 4) {
		u[i] = (float)i;
		v[i] = (float)i + 2.0;
	}

	printf("N = %'llu\n", N);

	gettimeofday(&start, NULL);
	inner(u, v, N, &result);
	gettimeofday(&end, NULL);
	elapsed = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);
	printf("inner: %.3f sec\n", elapsed / 1000000.0);

	gettimeofday(&start, NULL);
	inner2(u, v, N, &result);
	gettimeofday(&end, NULL);
	elapsed = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);
	printf("inner2: %.3f sec\n", elapsed / 1000000.0);

	free(u);
	free(v);

	return 0;
}
