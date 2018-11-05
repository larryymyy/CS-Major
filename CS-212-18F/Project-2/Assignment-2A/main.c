#include <stdio.h>

int is_prime(int n) {
	if(n == 2)
		return 1;
	if(n < 2 || (n << 31 >> 31) == 0)
		return 0;
	for(int i = 3; i * i <= n; i += 2)
		if(n % i == 0)
			return 0;
	return 1;
}

int main() {
	for(int i = 5; i <= 100; i++) {
		if(is_prime(i))
			printf("%d is a prime number\n", i);
	}
	return 0;
}
