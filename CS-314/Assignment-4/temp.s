	.file	"temp.c"
	.text
	.globl	transpose
	.type	transpose, @function
transpose:
.LFB0:
	.cfi_startproc
	movl	$0, %edx			# i = 0
	jmp	.L2						# JUMP to .L2
.L3:
	movq	%rdx, %rsi			#
	salq	$5, %rsi			
	addq	%rdi, %rsi			
	movq	(%rsi,%rax,8), %r8
	movq	%rax, %rcx			
	salq	$5, %rcx			
	addq	%rdi, %rcx			
	movq	(%rcx,%rdx,8), %r9	
	movq	%r9, (%rsi,%rax,8)
	movq	%r8, (%rcx,%rdx,8)
	addq	$1, %rax
	jmp	.L4
.L5:
	movl	$0, %eax			# j = 0
.L4:
	cmpq	%rax, %rdx			# i - j
	jg	.L3						# JUMP IF GREATER THAN to .L3
	addq	$1, %rdx			# i++
.L2:
	cmpq	$3, %rdx			# i - 3
	jle	.L5						# JUMP IF LESS THAN OR EQUAL to .L5
	rep ret						# return
	.cfi_endproc
.LFE0:
	.size	transpose, .-transpose
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
