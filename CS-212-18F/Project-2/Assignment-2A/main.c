#include <stdio.h>

int is_prime(int n) {
	/* If n == 2, then it must be prime */
	/* Checking particularly for two, as we will be incrementing by two later (i.e. checking only odds) */
	if(n == 2)
		return 1;
	/* n < 2 => 1 or less => NOT prime */
	/* n % 2 == 0 => even => NOT prime */
	if(n < 2 || (n << 31 >> 31) == 0)
		return 0;
	/* Loop all values from 3 to sqrt(n), incrementing by two */
	for(int i = 3; i * i <= n; i += 2)
		/* if n divisible by iterator's current value, then it must NOT be prime */
		if(n % i == 0)
			return 0;

	/* If execution reaches this point, it MUST be prime */
	return 1;
}

int main() {
	/* Loop all values from 5 to 100, incrementing by two */
	/* No need to check even values, as they will always be composite */
	for(int i = 5; i <= 100; i += 2) {
		if(is_prime(i))
			printf("%d is a prime number\n", i);
	}
	return 0;
}
