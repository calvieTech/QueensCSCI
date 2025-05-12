# int sumToN(int n ) {
#	if (n == 0) return 0;
#	else return n + sumToN(n-1);

	.data 
prompt: .asciiz "Type in a number: "

	.text
	.globl main


	main:
	la	$a0, prompt
	li 	$v0, 4
	syscall
	li	$v0, 5
	syscall	
	
	
	move	$s0, $v0
	move 	$a0, $s0
	jal sumToN
	move 	$s1, $v0
	
	
	sumToN:
	beq	$a0, $zero, baseCase	# if n == 0, branch to base case
	addi	$sp, $sp, -8		# else, make space for 2 items on the stack
	sw	$ra, 4($sp)		# store return address on stack
	sw	$a0, 0($sp)		# store argument n on stack
					# will need it to calculate returned value
	addi 	$a0, $a0, -1		# compute argument for next call: n = n - 1
	jal	sumToN			# jump and link to sumToN (recursive)
	

	lw	$ra, 4($sp)		# load the return address
	lw	$a0, 0($sp)		# load n from the stack
	addi 	$sp, $sp, 8		# change the stack pointer
	
	# register v0 contains result of sumToN(n-1)
	add	$v0, $a0, $v0		# add n to $v0
	move 	$t5, $v0
	
	li	$v0, 1
	move	$a0, $t5
	syscall
	
	jr	$ra			# return to parent
	
	baseCase:
	addi	$v0, $zero, 0		# assign 0 as the value in $v0
	jr	$ra			# return to parent
	
