#include <stdio.h>

struct ColorPoint {
	long c;
	long m;
	long y;
	long k;
};

int main() {
	struct ColorPoint pts[16][16];
	long sum = 0;
	int num_bytes = sizeof(struct ColorPoint) * 16 * 16;
	printf("bytes alloc'd: %d\n\n", num_bytes);
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 16; j++) {
			// sum += pts[i][j].c;
			// sum += pts[i][j].m;
			// sum += pts[i][j].y;
			// sum += pts[i][j].k;
			printf("pts[%2d][%2d]:  0x%lX\n",
					i,
					j,
					(unsigned long)&pts[i][j]);
		}
		printf("\n");
	}
}
