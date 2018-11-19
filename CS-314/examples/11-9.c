#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

int main() {
	int size = 1000;
	char text[size];
	for(int i = 0; i < size; i++) {
		text[i] = rand() / (double)RAND_MAX < 0.5 ? 'A' : 'B';
	}

	struct timeval start;
	gettimeofday(&start, NULL);

	// Do this 10000 times to exaggerate the time taken.
	for(int i = 0; i < 10000; ++i) {
		for(int j = 0; j < strlen(text); ++j) {
			text[j] -= ('A' - 'a');
		}
	}

	struct timeval current;
	gettimeofday(&current, NULL);

	long elapsed = (current.tv_sec - start.tv_sec) * 1000000LL + (current.tv_usec - start.tv_usec);
	printf("%f\n", elapsed / 1000000.0);
}
