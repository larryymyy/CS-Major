#include <stdio.h>
#include <stdlib.h>

long decode(long a, long b, long c);

long hard_coded = 63l;

int main() {
	long a = 1l;
	long b = 2l;
	long c = 3l;
	decode(a, b, c);
	return EXIT_SUCCESS;
}

long decode(long a, long b, long c) {
	c = c - b;
	b = b * a;
	hard_coded = hard_coded << b;
	hard_coded = hard_coded >> b;
	long temp = a;
	temp = temp ^ b;
	return 0;
}
