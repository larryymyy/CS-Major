#include <stdio.h>

long sum(long from, long to) {
    long result = 0;

    // Ensure that argument *from* is in %rdi,
    // argument *to* is in %rsi, *result* is in %rax - do not modify.
    __asm__ ("movq %0, %%rdi # from in rdi;" :: "r" ( from ));
    __asm__ ("movq %0, %%rsi # to in rsi;" :: "r" ( to ));
    __asm__ ("movq %0, %%rax # result in rax;" :: "r" ( result ));

    // Your x86-64 code goes below - comment each instruction...
    __asm__(
        ".LOOP:                 \n"
        "   addq %rdi, %rax     \n"
        "   addq $1, %rdi       \n"
        "   cmpq %rsi, %rdi     \n"
        "   jle .LOOP           \n"
    );

    // Ensure that *result* is in %rax for return - do not modify.
    __asm__ ("movq %%rax, %0 #result in rax;" : "=r" ( result ));

    return result;
}

int main() {
    // Test cases
    printf("sum(%ld, %ld): %ld\n", 1l, 6l, sum(1l, 6l));
    printf("sum(%ld, %ld): %ld\n", 3l, 5l, sum(3l, 5l));

    return 0;
}
