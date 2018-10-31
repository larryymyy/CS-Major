#include <stdio.h>
#include <stdlib.h>

void f(int x) {
	// Reassign the value x - this has no effect on functionality
	// because we don't use or return the updated value of x.
	x = 30;
}

void g (int * x) {
	// Reassigne the value in the memory location at x.
	*x = 40;
}

int main() {
	// Allocate 8 bytes of memory (amount required to hold 2 ints).
	int * array = (int *)malloc(2 * sizeof(int));
	printf("1 [ %d %d ]\n", array[0], array[1]);

	array[0] = 10;
	array[1] = 20;
	printf("2 [ %d %d ]\n", array[0], array[1]);

	// Passes the value at array[0], which is copied into the parameter x in f.
	f(array[0]);
	printf("3 [ %d %d ]\n", array[0], array[1]);

	// Passes the address of array[1], which is copied into the parameter x in g.
	g(&array[1]);
	printf("4 [ %d %d ]\n", array[0], array[1]);

	free(array);
	return 0;
}
