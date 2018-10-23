pcount_r:
	movl	$0, %eax
	testq	%rdi, %rdi
	je	.L6
	pushq	%rbx
	movq	%rdi, %rbx
	andl	$1, %ebx
	shrq	%rdi
	call	pcount_r
	addq	%rbx, %rax
	popq	%rbx
.L6:
	ret
