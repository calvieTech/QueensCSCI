#Calvin Thang
# Mips - For Loop

.data
print: .asciiz "x = "
printNewLine: .asciiz "\n"

.text
	
main:
	li $t0, 0
	li $t1, 10
loop:
	la $a0, print
	li $v0, 4
	syscall
	
	la $a0, ($t0)
	li $v0, 1
	syscall
	
	la $a0, printNewLine
	li $v0, 4
	syscall
	
	
	add $t0, $t0, 1
	
	beq $t0, $t1, end
	
	j loop
end:
	li $v0, 10
	syscall
	
	
	
