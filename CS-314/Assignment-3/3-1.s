	.file	"3-1.c"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	mallocIntArray
	.type	mallocIntArray, @function
mallocIntArray:
.LFB38:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movl	%edi, %ebx
	movl	$16, %edi
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	call	malloc
	movslq	%ebx, %rdi
	movq	%rax, %rbp
	movl	%ebx, (%rax)
	salq	$2, %rdi
	call	malloc
	movq	%rax, 8(%rbp)
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	movq	%rbp, %rax
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE38:
	.size	mallocIntArray, .-mallocIntArray
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.section	.text.unlikely
.LCOLDB1:
	.text
.LHOTB1:
	.p2align 4,,15
	.globl	freeIntArray
	.type	freeIntArray, @function
freeIntArray:
.LFB39:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	movq	8(%rdi), %rdi
	call	free
	movq	%rbx, %rdi
	popq	%rbx
	.cfi_def_cfa_offset 8
	jmp	free
	.cfi_endproc
.LFE39:
	.size	freeIntArray, .-freeIntArray
	.section	.text.unlikely
.LCOLDE1:
	.text
.LHOTE1:
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC2:
	.string	"Enter int: "
.LC3:
	.string	"%d"
.LC4:
	.string	"Invalid input"
	.section	.text.unlikely
.LCOLDB5:
	.text
.LHOTB5:
	.p2align 4,,15
	.globl	readIntArray
	.type	readIntArray, @function
readIntArray:
.LFB40:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	subq	$16, %rsp
	.cfi_def_cfa_offset 48
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	movl	(%rdi), %eax
	testl	%eax, %eax
	jle	.L5
	movq	%rdi, %r12
	xorl	%ebp, %ebp
	xorl	%ebx, %ebx
	.p2align 4,,10
	.p2align 3
.L8:
	movl	$.LC2, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	leaq	4(%rsp), %rsi
	xorl	%eax, %eax
	movl	$.LC3, %edi
	call	__isoc99_scanf
	cmpl	$1, %eax
	jne	.L10
	jmp	.L25
	.p2align 4,,10
	.p2align 3
.L26:
	cmpl	$-1, %eax
	je	.L14
.L10:
	movq	stdin(%rip), %rdi
	call	_IO_getc
	cmpl	$10, %eax
	jne	.L26
.L14:
	movl	$.LC4, %edi
	call	puts
	jmp	.L8
.L25:
	movq	8(%r12), %rax
	movl	4(%rsp), %edx
	addl	$1, %ebx
	movl	%edx, (%rax,%rbp)
	addq	$4, %rbp
	cmpl	%ebx, (%r12)
	jg	.L8
.L5:
	movq	8(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L27
	addq	$16, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
.L27:
	.cfi_restore_state
	call	__stack_chk_fail
	.cfi_endproc
.LFE40:
	.size	readIntArray, .-readIntArray
	.section	.text.unlikely
.LCOLDE5:
	.text
.LHOTE5:
	.section	.text.unlikely
.LCOLDB6:
	.text
.LHOTB6:
	.p2align 4,,15
	.globl	swap
	.type	swap, @function
swap:
.LFB41:
	.cfi_startproc
	movl	(%rdi), %eax
	movl	(%rsi), %edx
	movl	%edx, (%rdi)
	movl	%eax, (%rsi)
	ret
	.cfi_endproc
.LFE41:
	.size	swap, .-swap
	.section	.text.unlikely
.LCOLDE6:
	.text
.LHOTE6:
	.section	.text.unlikely
.LCOLDB7:
	.text
.LHOTB7:
	.p2align 4,,15
	.globl	sortIntArray
	.type	sortIntArray, @function
sortIntArray:
.LFB42:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	xorl	%r11d, %r11d
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movl	(%rdi), %r9d
	movq	8(%rdi), %r10
	leal	-1(%r9), %r13d
	leaq	4(%r10), %rbx
	cmpl	%r13d, %r11d
	jge	.L36
	.p2align 4,,10
	.p2align 3
.L33:
	leal	1(%r11), %ebp
	cmpl	%ebp, %r9d
	jle	.L31
	movl	-4(%rbx), %r12d
	movq	%rbx, %rsi
	movl	%ebp, %ecx
	movl	%r11d, %edi
	movl	%r12d, %eax
	.p2align 4,,10
	.p2align 3
.L32:
	movl	(%rsi), %edx
	movslq	%edi, %r8
	leaq	(%r10,%r8,4), %r8
	cmpl	%eax, %edx
	cmovl	%ecx, %edi
	cmovl	%rsi, %r8
	cmpl	%edx, %eax
	cmovg	%edx, %eax
	addl	$1, %ecx
	addq	$4, %rsi
	cmpl	%ecx, %r9d
	jne	.L32
	cmpl	%edi, %r11d
	je	.L31
	movl	%eax, -4(%rbx)
	movl	%r12d, (%r8)
.L31:
	movl	%ebp, %r11d
	addq	$4, %rbx
	cmpl	%r13d, %r11d
	jl	.L33
.L36:
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE42:
	.size	sortIntArray, .-sortIntArray
	.section	.text.unlikely
.LCOLDE7:
	.text
.LHOTE7:
	.section	.rodata.str1.1
.LC8:
	.string	"[ "
.LC9:
	.string	"%d, "
.LC10:
	.string	"%d ]\n"
	.section	.text.unlikely
.LCOLDB11:
	.text
.LHOTB11:
	.p2align 4,,15
	.globl	printArray
	.type	printArray, @function
printArray:
.LFB43:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	movq	%rdi, %r12
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	xorl	%eax, %eax
	movl	$.LC8, %esi
	movl	$1, %edi
	call	__printf_chk
	movslq	(%r12), %rax
	cmpl	$1, %eax
	jle	.L38
	xorl	%ebp, %ebp
	xorl	%ebx, %ebx
	.p2align 4,,10
	.p2align 3
.L39:
	movq	8(%r12), %rax
	movl	$.LC9, %esi
	movl	$1, %edi
	addl	$1, %ebx
	movl	(%rax,%rbp), %edx
	xorl	%eax, %eax
	addq	$4, %rbp
	call	__printf_chk
	movslq	(%r12), %rax
	leal	-1(%rax), %edx
	cmpl	%ebx, %edx
	jg	.L39
.L38:
	movq	8(%r12), %rdx
	movl	$.LC10, %esi
	movl	$1, %edi
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	movl	-4(%rdx,%rax,4), %edx
	xorl	%eax, %eax
	jmp	__printf_chk
	.cfi_endproc
.LFE43:
	.size	printArray, .-printArray
	.section	.text.unlikely
.LCOLDE11:
	.text
.LHOTE11:
	.section	.rodata.str1.1
.LC12:
	.string	"Enter length: "
	.section	.text.unlikely
.LCOLDB13:
	.section	.text.startup,"ax",@progbits
.LHOTB13:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB44:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$.LC12, %esi
	movl	$1, %edi
	subq	$16, %rsp
	.cfi_def_cfa_offset 32
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	movl	$0, 4(%rsp)
	.p2align 4,,10
	.p2align 3
.L59:
	call	__printf_chk
	leaq	4(%rsp), %rsi
	movl	$.LC3, %edi
	xorl	%eax, %eax
	call	__isoc99_scanf
	movl	4(%rsp), %edi
	testl	%edi, %edi
	jle	.L45
	cmpl	$1, %eax
	jne	.L45
	jmp	.L44
	.p2align 4,,10
	.p2align 3
.L61:
	cmpl	$-1, %eax
	je	.L48
.L45:
	movq	stdin(%rip), %rdi
	call	_IO_getc
	cmpl	$10, %eax
	jne	.L61
.L48:
	movl	$.LC4, %edi
	call	puts
	movl	$.LC12, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	jmp	.L59
.L44:
	call	mallocIntArray
	movq	%rax, %rbx
	movq	%rax, %rdi
	call	readIntArray
	movq	%rbx, %rdi
	call	sortIntArray
	movq	%rbx, %rdi
	call	printArray
	movq	8(%rbx), %rdi
	call	free
	movq	%rbx, %rdi
	call	free
	xorl	%eax, %eax
	movq	8(%rsp), %rdx
	xorq	%fs:40, %rdx
	jne	.L62
	addq	$16, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L62:
	.cfi_restore_state
	call	__stack_chk_fail
	.cfi_endproc
.LFE44:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE13:
	.section	.text.startup
.LHOTE13:
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
