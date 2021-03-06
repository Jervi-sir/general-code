.text
.globl main

main:
	jal	enter_amount 
	jal 	enter_num 
	jal	contains 
	jal 	sort 
	jal 	contains 
	jal 	search_for 
	jal 	search 
	jal 	search_results 
	j 	done # Exit
	
enter_amount:
	la 	$a0, amount_num 
	li 	$v0, 4 
	syscall
	li 	$v0, 5 
	syscall
	move 	$t0, $v0 
	li 	$t1, 0 
	li 	$t2, 1 
	jr 	$ra 
enter_num:
	addi 	$t2, $t2, 1 
	la 	$a0, num 
	li	$v0, 4 
	syscall
	li 	$v0, 5 
	syscall
	sw 	$v0, array($t1) 
	addi 	$t1, $t1, 4 
	ble 	$t2, $t0, enter_num 
	jr	$ra 
contains:                             
	li 	$t1, 0 
	li 	$t2, 1 
	la	$a0, array_contains 
	li 	$v0, 4 
	syscall
print_array:
	addi 	$t2, $t2, 1 
	lw 	$a0, array($t1) 
	li 	$v0, 1 
	syscall
	la 	$a0, nl
	li 	$v0, 4 
	syscall
	addi 	$t1, $t1, 4 
	ble	$t2, $t0, print_array
	jr 	$ra 
sort:
	li 	$t2, 0 
outer:
	addi 	$t2, $t2, 1 
	la 	$a1, array 
	li 	$t1, 0 
	sub 	$t3, $t0, 1 
	addi 	$t4, $t2, 1 
	ble 	$t2, $t3, inner 
	jr 	$ra 
inner:
	lw 	$t5, 0($a1) 
	lw 	$t6, 4($a1) 
	bgt	$t5, $t6, swap 
	j 	continue 
swap:
	sw 	$t6, 0($a1) 
	sw 	$t5, 4($a1) 
continue:
	addi 	$a1, $a1, 4
	addi 	$t4, $t4, 1 
	bgt 	$t4, $t0, outer 
	j 	inner 
search_for: 
	la 	$a0, search_num 
	li 	$v0, 4 
	syscall
	li 	$v0, 5 
	syscall
	move 	$t0, $v0 
	li 	$t2, 0
	li 	$t4, 2
	li 	$t6, 4
	jr 	$ra 
search:
	bgt 	$t2, $t3, return 

middle_num:
	add	$t7, $t2, $t3 
	div 	$t7, $t4
	mflo	$t8 
	mult 	$t8, $t6 
	mflo 	$t1 
	lw 	$t5, array($t1) 
	bgt 	$t5, $t0, lower 
	blt	$t5, $t0, upper 
	li 	$s0, 1 
	jr 	$ra 
	
	
upper:	add 	$t2, $t8, 1 				#the mistake was here 
	j 	search 
lower: 
	sub 	$t3, $t8, 1 
	j 	search 
return:
	li	$s0, 0 
	jr 	$ra 
search_results:
	beqz 	$s0, not_found 
found:
	move 	$a0, $t0 
	li 	$v0, 1 
	syscall
	la 	$a0, f 
	li 	$v0, 4 
	syscall
	div 	$t1, $t6 
	mflo 	$a0 
	li 	$v0, 1 
	syscall
	la 	$a0, cl_bracket 
	li 	$v0, 4 
	syscall
	jr 	$ra 
not_found:
	move 	$a0, $t0 
	li 	$v0, 1 
	syscall
	la 	$a0, nf 
	li 	$v0, 4 
	syscall
	jr 	$ra 
done:
	la 	$a0, complete 
	li 	$v0, 4 
	syscall
	li 	$v0, 10 
	syscall

.data
amount_num: .asciiz "How many numbers do you have? "
num: .asciiz "Enter a number: "
nl: .asciiz "\n"
array_contains: .asciiz "\nThe array contains the following: \n"
complete: .asciiz "\nprogram complete"

.align 2
array: .space 40
search_num: .asciiz "\nEnter number to search for: "
f: .asciiz " was found at array["
cl_bracket: .asciiz "]"
nf: .asciiz " was not found"
