#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N 2048

int main() {
	int ** a = (int **) malloc(N * sizeof(int *));
	for(int i = 0; i < N; ++i) {
		a[i] = (int *) malloc(N * sizeof(int));
	}

	struct timeval start;
	gettimeofday(&start, NULL);

	// Do this 100 times to exaggerate the time taken.
	for(int n = 0; n < 100; ++n) {
		int sum = 0;
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j) {
				// Try swapping i and j here to change the memory-access pattern!
				sum += a[i][j];
			}
		}
	}

	struct timeval current;
	gettimeofday(&current, NULL);

	long elapsed = (current.tv_sec - start.tv_sec) * 1000000LL + (current.tv_usec - start.tv_usec);
	printf("%f\n", elapsed / 1000000.0);

	for(int i = 0; i < N; ++i) {
		free(a[i]);
	}
	free(a);
}
