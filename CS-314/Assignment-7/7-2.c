/*
   Kevin Conte
   951620146

   30 November 2018
   =====================================
   Assignment 7
   Part 2
 */

#include <stdio.h>

unsigned int getOffset(unsigned int address) {
    // Four bits needed to identify offset within block

    // Mask the last 4 bits of the address and return
    unsigned int mask = 0x0000000F;
    return address & mask;
}

unsigned int getSet(unsigned int address) {
    // Four bits needed to identify set withing cache

    // Mask next 4 bits of the address and return
    unsigned int mask = 0x000000F0;
    return (address & mask) >> 4;
}

unsigned int getTag(unsigned int address) {
    // Remaining bits identify its tag

    // Mask remaining bits of the address and return
    unsigned int mask = 0xFFFFFF00;
    return (address & mask) >> 8;
}

int main() {
    // Test Cases
    unsigned int addr = 0x12345678;
    printf("0x%X: offset: %X - tag: %X - set: %X\n",
            addr,
            getOffset(addr),
            getTag(addr),
            getSet(addr));

    addr = 0x87654321;
    printf("0x%X: offset: %X - tag: %X - set: %X\n",
            addr,
            getOffset(addr),
            getTag(addr),
            getSet(addr));

	return 0;
}
