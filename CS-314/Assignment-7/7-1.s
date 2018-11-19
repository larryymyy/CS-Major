	.file	"7-1.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
#APP
# 11 "7-1.c" 1
	# OUTER LOOP
# 0 "" 2
#NO_APP
	movl	$0, %edx
	jmp	.L2
.L5:
#APP
# 13 "7-1.c" 1
	# INNER LOOP
# 0 "" 2
#NO_APP
	movl	$0, %eax
	jmp	.L3
.L4:
	addl	$1, %eax
.L3:
	cmpl	$15, %eax
	jle	.L4
	addl	$1, %edx
.L2:
	cmpl	$15, %edx
	jle	.L5
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
