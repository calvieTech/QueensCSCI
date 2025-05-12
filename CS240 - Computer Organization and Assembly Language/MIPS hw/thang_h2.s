# Calvin Thang
# MIPS HW2

# store the strings as data
.data
askInputString: .asciiz "Please enter a positive integer: "
message: .asciiz "The result is: "

# instructions go under .text
.text
.globl main
main:
	
	# put the string askUserInput as argument for $v0
	la $a0, askInputString
	# $v0 system service code for print string
	li $v0, 4
	syscall
	
	# wait for user to give integer as input
	li $v0, 5
	syscall
	
	# move a copy of user input to $t1 register
	move $t1, $v0
	
	# if $t1{userInput} < $t2{zero}, $t3 = 1
	# if $t1 >= $t2, $t3 = 0
	slt $t3, $t1, $t2
	
	# if t3 is not 0, meaning 
	# if t1 IS less than t1, go to main
	bne $t3, $zero, main

	# move contents of $t1 into argument register
	move $a0, $t1
	# call Func
	jal Func
	
	# return function result is moved to temp register
	move $t0, $v0
	
	# print message string
	la $a0, message
	li $v0, 4
	syscall
	
	# load service code (print integer)
	li $v0, 1
	# move $t0 into $a0 to use as argument
	move $a0, $t0
	# print $a0
	syscall
	
	# system call exit (10)
	li $v0, 10
	syscall

Func:
	# make space for three words in the stack pointer
	addi $sp, $sp, -12
	# store the return address and argument onto the stack pointer
	sw $ra, 0($sp)
	sw $a0, 4($sp)
	sw $s0, 8($sp)

	# branch to FuncBasecase if argument = 0
	beq $a0, $zero, FuncBasecase
	
	
	# multiply n * 5
	mul $s0, $a0, 5
	# Func(n-1)
	sub $a0, $a0, 1	#i don think you can add a negative number
	# go back to beginning of Func
	jal Func
	# do n * 4 then save it in $t0
	sll $t0, $v0, 2
	# add values of $t0 and $s0 then put it in $v0
	add $v0, $s0, $t0
	b EndOfFunction
	
FuncBasecase:
	#return 6
	li $v0, 6
	
EndOfFunction:
	# restore the stack pointers 
	# and put them into the registers
	lw $ra, 0($sp)
	lw $a0, 4($sp)
	lw $s0, 8($sp)
	addi $sp, $sp, 12
	
	jr $ra
	
	
	

	
	
	
	
	
	
	
	
