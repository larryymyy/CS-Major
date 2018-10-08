#include <stdio.h>
#include <stdlib.h>

int main() {
	int *array = (int *)malloc(2 * sizeof(int));
	printf("[ %d %d ]\n", array[0], array[1]);

	free(array);
	return EXIT_SUCCESS;
}
