#include <stdio.h>
#include <math.h>

int main() {
	printf("1-a\n");
	printf("--------+----------+------------\n");
	for(int i = 1; i <= 10; i++) {
		int m = 0;
		for(int j = 0; j < i; j++) {
			for(int k = 0; k < j * j; k++) {
				m++;
			}
		}
		printf("i:%4d  |  m:%4d  |  O(n\u00B3):%4d\n",
				i,
				m,
				i * i * i);
	}
	printf("--------+----------+------------\n\n\n");

	printf("1-b\n");
	printf("--------+----------+--------------\n");
	for(int i = 1; i <= 10; i++) {
		int m = 0;
		for(int j = 0; j < i * i; j++) {
			for(int k = 0; k < j; k++) {
				m++;
			}
		}
		printf("i:%4d  |  m:%4d  |  O(n\u00B3):%5d\n",
				i,
				m,
				i * i * i * i);
	}
	return 0;
}
