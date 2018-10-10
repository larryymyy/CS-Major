#include <stdio.h>
#include <stdlib.h>

void f(int x) {
	x = 30;
}

void g(int * x) {
	*x = 40;
}
int main() {
	int *array = (int *)malloc(2 * sizeof(int));
	printf("1 [ %d %d ]\n", array[0], array[1]);

	array[0] = 10;
	array[1] = 20;
	printf("2 [ %d %d ]\n", array[0], array[1]);

	f(array[0]);
	printf("3 [ %d %d ]\n", array[0], array[1]);
	
	g(&array[1]);
	printf("4 [ %d %d ]\n", array[0], array[1]);

	free(array);
	return EXIT_SUCCESS;
}
