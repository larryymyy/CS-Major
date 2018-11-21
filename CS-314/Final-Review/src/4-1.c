#include <stdio.h>

#if 0

a => %rdi
b => %rsi

loop:
    movq %rsi, %rcx  # %rcx = b
    movl $1, %edx    # mask = 1
    movl $0, %eax    # result = 0
.L2:
    testq %rdx, %rdx # mask == 0 ?
    je    .L4        # if mask == 0, return
    movq  %rdx, %r8  # %r8 = mask
    andq  %rdi, %r8  # %r8 &= a
    orq   %r8, %rax  # result |= %r8
    salq  %c1, %rdx  # mask <<= b
    jmp   .L2
.L4:
    ret              # return result

#endif

long loop(long a, long b) {
    long result = 0;
    for (long mask = 1; mask != 0; mask <<= b) {
        result |= (mask & a);
    }
    return result;
}

int main() {
    // Test cases
    printf("loop(%ld, %ld): %ld\n", 1l, 5l, loop(1l, 5l));
    printf("loop(%ld, %ld): %ld\n", 2l, 4l, loop(2l, 4l));
    printf("loop(%ld, %ld): %ld\n", 3l, 3l, loop(3l, 3l));
    printf("loop(%ld, %ld): %ld\n", 4l, 2l, loop(4l, 2l));
    printf("loop(%ld, %ld): %ld\n", 5l, 1l, loop(5l, 1l));

    return 0;
}
