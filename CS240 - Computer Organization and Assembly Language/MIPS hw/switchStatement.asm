.text
main:
	li $s1, 2 #g
	li $s2, 3 #h
	li $s3, 4 #i
	li $s4, 5 #j
	
	li $s5, 4 #k
	
if:
	bne $s5, $zero, elseIf
	
	add $s0, $s3, $s4
	move $a0, $s0
	li $v0, 1
	syscall
elseIf:
	li $t1, 1
	bne $s5, $t1, elseIf2
	
	add $s0, $s1, $s2
	move $a0, $s0
	li $v0, 1
	syscall
elseIf2:
	li $t2, 2
	bne $s5, $t2, elseIf3
	
	sub $s0, $s1, $s2
	move $a0, $s0
	li $v0, 1
	syscall
elseIf3:
	li $t3, 3
	bne $s5, $t3, exit
	
	sub $s0, $s3, $s4
	move $a0, $s0
	li $v0, 1
	syscall
exit:
	li $v0, 10
	syscall
	