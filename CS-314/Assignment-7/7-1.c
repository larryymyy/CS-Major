struct ColorPoint {
	long c;
	long m;
	long y;
	long k;
};

int main() {
	struct ColorPoint square[16][16];
	long sum = 0;
	__asm__("# OUTER LOOP");
	for(int i = 0; i < 16; i++) {
		__asm__("# INNER LOOP");
		for(int j = 0; j < 16; j++) {
			sum += square[i][j].c;
			sum += square[i][j].m;
			sum += square[i][j].y;
			sum += square[i][j].k;
		}
	}
}
