#include <stdio.h>

int is_prime(int n) {
	/* Since we will be henceforth only checking odd numbers, check for the only
	   even prime (2) first */ 
	if(n == 2)
		return 1;

	/* If n < 2, it is not prime
	   If n is even and not 2, it is not prime */
	if(n < 2 || n % 2 == 0)
		return 0;

	/* Check all numbers until the square root of n
	   (Anything greater than the square root will not divide n evenly)
	   Increment by 2 since only odd numbers need to be checked
	   (If n was divisible by an even number, it would be divisible by two, and thus even) */
	for(int i = 3; i * i <= n; i += 2)
		if(n % i == 0)
			return 0;

	/* If execution reaches this point, the number MUST be prime */
	return 1;
}

int main(int argc, char * argv[]) {
	/* Only check odd numbers since our start is greater than the only even prime number, 2 */
	for(int i = 5; i < 100; i += 2)
		/* If i is prime, print it */
		if(is_prime(i))
			printf("%d is a prime number\n", i);
	return 0;
}
