#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


// Assignment 1
// =======================================================================================

// Part 1
void printBytes(unsigned char * start, int len) {
    for(int i = 0; i < len; ++i) {
        printf(" 0x%.2X", start[i]);
    }
    printf("\n");
}

void printInt(int x) {
    printBytes((unsigned char *) &x, sizeof(int));
}

void printFloat(float x) {
    printBytes((unsigned char *) &x, sizeof(float));
}

void printShort(short x) {
    printBytes((unsigned char * ) &x, sizeof(short));
}

void printLong(long x) {
    printBytes((unsigned char *) &x, sizeof(long));
}

void printDouble(double x) {
    printBytes((unsigned char *) &x, sizeof(double));
}


// Part 2
unsigned int combine(unsigned int x, unsigned int y) {
    unsigned int xMask = 0xFFFF0000;
    unsigned int yMask = 0x0000FFFF;
    unsigned int result = (x & xMask) | (y & yMask);
    return result;
}


// Part 3
unsigned int replace(unsigned int x, int i, unsigned char b) {
    unsigned int byte = b << (i << 3); // Align b to correct position
    unsigned int mask = ~(0xFF << (i << 3)); // Create mask where byte is to be replaced
    unsigned int result = (x & mask) | byte; // And with mask, or with byte
    return result; // return result
}


// Part 4
int oddBit(unsigned int x) {
    unsigned int mask = 0xAAAAAAAA; // Mask has 1's in all odd positions
    return !!(x & mask); // and x with mask, and double-not it. if x & mask > 1, oddBit returns 1; else 0
}

// Assignment 2
// =======================================================================================

// Part 1
int mask(int n) {
    return 0x7FFFFFFF >> (31 - n);
}


// Part 2
unsigned int extract(unsigned int x, int i) {
    unsigned int mask = 0xFF << (i << 3); // Create mask to capture correct byte
    int result = x & mask;
    result <<= (24 - (i << 3));
    result >>= 24;
    return result;;
}


// Part 3
int ge(float x, float y) {
    unsigned int ux = *((unsigned int *) &x); // convert x to raw bits
    unsigned int uy = *((unsigned int *) &y); // convert y to raw bits
    unsigned int sx = ux >> 31; // extract sign bit of ux
    unsigned int sy = uy >> 31; // extract sign bit of uy
    ux <<= 1; // drop sign bit of ux
    uy <<= 1; // drop sign bit of uy

    return ((sx == sy) && (sx == 1) && (ux <= uy)) || // x and y both negative
           ((sx == sy) && (sx == 0) && (ux >= uy)) || // x and y both positive
           ((sx != sy) && (ux == uy)) ||              // both zero (pos or neg)
           ((sx != sy) && (sx == 0));                 // x positive and y negative
}



// Assignment 3
// =======================================================================================
struct IntArray {
    int length;
    int * dataPtr;
};

struct IntArray * mallocIntArray(int length) {
    struct IntArray * arr = malloc(sizeof(struct IntArray));
    arr->length = length;
    arr->dataPtr = malloc(sizeof(int) * length);
    return arr;
}

void freeIntArray(struct IntArray * arrayPtr) {
    free(arrayPtr->dataPtr);
    free(arrayPtr);
}

void readIntArray(struct IntArray * array) {
    int valid, val, gc;
    if(array->length  < 1) {
        fprintf(stderr, "Array has no capacity!\n");
        return;
    }

    for(int i = 0; i < array->length; i++) {
        valid = scanf("%d", &val);
        while(valid != 1) {
            while((gc = getchar()) != EOF && gc != '\n');
            fprintf(stderr, "Invalid input\n");
            valid = scanf("%d", &val);
        }
        array->dataPtr[i] = val;
    }
}

void swap(int * xp, int * yp) {
    int t = *xp;
    *xp = *yp;
    *yp = t;
}

void sortIntArray(struct IntArray * array) {
    for(int i = 0; i < array->length - 1; i++) {
        int min = i;
        for(int j = i; j < array->length; j++) {
            if(array->dataPtr[j] < array->dataPtr[min]) {
                min = j;
            }
        }
        if(min != i) {
            swap(&array->dataPtr[i], &array->dataPtr[min]);
        }
    }
}

void printIntArray(struct IntArray * array) {
    printf("[ ");
    for(int i = 0; i < array->length - 1; i++) {
        printf("%d, ", array->dataPtr[i]);
    }
    printf("%d ]\n", array->dataPtr[array->length - 1]);
}


// Part 2
long decode(long a, long b, long c) {
    b -= c;
    a *= b;
    b <<= 63;
    b >>= 63;
    return a ^ b;
}

// =======================================================================================

int main() {
    srand(time(NULL));
    // Assignment 1
    // ============
    printf("Assignment 1\n");
    printf("============\n");

    // Part 1
    printf("Part 1\n");
    printf("------\n");
    printShort (12345);
    printInt   (1234567891);
    printLong  (1234567891011121314);
    printFloat (1.234567 * 10e12);
    printDouble(1.234567 * 10e123);
    printf("\n");
    fflush(stdout);
    usleep(1000000);

    // Part 2
    printf("Part 2\n");
    printf("------\n");
    printf("combine(0x%08X, 0x%08X): 0x%08X\n",
            0x12345678,
            0xABCDEF00,
            combine(0x12345678, 0xABCDEF00));

    printf("combine(0x%08X, 0x%08X): 0x%08X\n",
            0xABCDEF00,
            0x12345678,
            combine(0xABCDEF00, 0x12345678));
    printf("\n");
    fflush(stdout);
    usleep(1000000);

    // Part 3
    printf("Part 3\n");
    printf("------\n");
    printf("replace(0x%08X, %d, 0x%X): 0x%08X\n",
            0x12345678,
            2,
            0xAB,
            replace(0x12345678, 2, 0xAB));

    printf("replace(0x%08X, %d, 0x%X): 0x%08X\n",
            0x12345678,
            0,
            0xAB,
            replace(0x12345678, 0, 0xAB));
    printf("\n");
    fflush(stdout);
    usleep(1000000);

    // Part 4
    printf("Part 4\n");
    printf("------\n");
    printf("oddBit(0x%X): %d\n", 0x1, oddBit(0x1));
    printf("oddBit(0x%X): %d\n", 0x2, oddBit(0x2));
    printf("oddBit(0x%X): %d\n", 0x3, oddBit(0x3));
    printf("oddBit(0x%X): %d\n", 0x4, oddBit(0x4));
    printf("oddBit(0x%X): %d\n", 0xFFFFFFFF, oddBit(0xFFFFFFFF));
    printf("oddBit(0x%X): %d\n", 0xAAAAAAAA, oddBit(0xAAAAAAAA));
    printf("oddBit(0x%X): %d\n", 0x55555555, oddBit(0x55555555));
    printf("\n\n\n\n");
    fflush(stdout);
    usleep(1000000);



    // Assignment 2
    // ============
    printf("Assignment 2\n");
    printf("============\n");

    // Part 1
    printf("Part 1\n");
    printf("------\n");
    printf("mask(%d): 0x%X\n", 0, mask(0));
    printf("mask(%d): 0x%X\n", 1, mask(1));
    printf("mask(%d): 0x%X\n", 2, mask(2));
    printf("mask(%d): 0x%X\n", 3, mask(3));
    printf("mask(%d): 0x%X\n", 5, mask(5));
    printf("mask(%d): 0x%X\n", 8, mask(8));
    printf("mask(%d): 0x%X\n", 16, mask(16));
    printf("mask(%d): 0x%X\n", 31, mask(31));
    printf("\n");
    fflush(stdout);
    usleep(1000000);

    // Part 2
    printf("Part 2\n");
    printf("------\n");
    printf("extract(0x%X, %d): 0x%08X\n", 0x12345678, 0, extract(0x12345678, 0));
    printf("extract(0x%X, %d): 0x%08X\n", 0xABCDEF00, 2, extract(0xABCDEF00, 2));
    printf("\n");
    fflush(stdout);
    usleep(1000000);

    // Part 3
    printf("Part 3\n");
    printf("------\n");
    printf("ge(%.1ff, %.1ff): %d\n", 0.0f, 0.0f, ge(0.0f, 0.0f));
    printf("ge(%.1ff, %.1ff): %d\n", -0.0f, 0.0f, ge(-0.0f, 0.0f));
    printf("ge(%.1ff, %.1ff): %d\n", -1.0f, 0.0f, ge(-1.0f, 0.0f));
    printf("ge(%.1ff, %.1ff): %d\n", 0.0f, 1.0f, ge(0.0f, 1.0f));
    printf("ge(%.1ff, %.1ff): %d\n", 1.0f, 0.0f, ge(1.0f, 0.0f));
    printf("ge(%.1ff, %.1ff): %d\n", 0.0f, -1.0f, ge(0.0f, -1.0f));
    printf("\n");
    fflush(stdout);
    usleep(1000000);

    // Part 4
    printf("Part 4\n");
    printf("------\n");
    printf("Convert Hexadecimal -> Decimal (2's Complement)\n");
    printf("0x000000C6 =>  198\n");
    printf("0xFFFFFEC6 => -314\n");
    printf("0xFFFFFFFF =>   -1\n");
    printf("\n");
    fflush(stdout);
    usleep(1000000);

    // Part 5
    printf("Part 5\n");
    printf("------\n");
    printf("Convert Hexadecimal -> Floating Point (IEEE 754 Single-Precision)\n");
    printf("0x80000000 =>    0.0\n");
    printf("0x439D0000 =>  314.0\n");
    printf("0xC1340000 => -11.25\n");
    printf("\n");
    fflush(stdout);
    usleep(1000000);

    // Part 6
    printf("Part 6\n");
    printf("------\n");
    printf("Convert Floating Point (IEEE 754 Single Precision) -> Hexadecimal\n");
    printf("  -1.0 => 0xBF800000\n");
    printf(" 16.75 => 0x41860000\n");
    printf("-314.0 => 0xC39D0000\n");
    printf("\n\n\n\n");
    fflush(stdout);
    usleep(1000000);



    // Assignment 3
    // ============
    printf("Assignment 3\n");
    printf("============\n");

    // Part 1
    printf("Part 1\n");
    printf("------\n");
    struct IntArray * array = mallocIntArray(16);
    for(int i = 0; i < 16; i++) {
        array->dataPtr[i] = rand() % (101) + 1;
    }
    sortIntArray(array);
    printIntArray(array);
    freeIntArray(array);
    printf("\n");
    fflush(stdout);
    usleep(1000000);

    // Part 2
    printf("Part 2\n");
    printf("------\n");
    printf("decode(%ld, %ld, %ld): %ld\n", 1l, 2l, 4l, decode(1l, 2l, 4l));
    printf("decode(%ld, %ld, %ld): %ld\n", 3l, 5l, 7l, decode(3l, 5l, 7l));
    printf("decode(%ld, %ld, %ld): %ld\n", 10l, 20l, 30l, decode(10l, 20l, 30l));
    printf("\n");
    fflush(stdout);
    usleep(1000000);

    return 0;
}
