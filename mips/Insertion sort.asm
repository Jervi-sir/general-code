.data
	enter:		.asciiz	"enter array's size\n"
	enter_num:	.asciiz	"enter numbers \n"
	T:		.space	40
	sorted:		.asciiz	"array sorted\n"
.text
.globl main

main:
	la	$a0,enter
	li	$v0,4
	syscall
	
	li	$v0,5
	syscall
	move	$s0,$v0			#s0 <== taill du tableau	 
	
	la	$a0,enter_num
	li	$v0,4
	syscall
	
	add	$s1,$zero,$s0
	la	$t0,T			#pointer tableau
add_numbers:
	beqz	$s1,end_add		#for($s1 = taill; $s1>0
	addi	$s1,$s1,-1		#$s1--)
	
	li	$v0,5
	syscall
	
	sw	$v0,0($t0)
	addi	$t0,$t0,4
	j	add_numbers	
	
end_add:
	
	li	$t1,1			#pour boucle for
	li	$t2,0			#pour boucle while
	li	$t3,0			#pour varible temporary
	add	$s1,$zero,$s0		#taill du tableau
	la	$t0,T			#tableau pointer
	
Inser_sort:

	for:
	beq	$t1,$s1,end_for		 #for($t1 = 1; $t1 < $s1
	add	$t2,$t2,$s1		#$t2 = $s1
	
	
	lw	$a2,0($t0)
	lw	$a3,4($t0)
	while:#while($t2 > 0 && 
	bgt	$t2,$zero,d		#if $t2 > 0
		j	end_while
	d:	
	bgt	$a2,$a3,e		#T[i] < T[i-1]
		j	end_while
	e:
	lw	$a2,0($t0)
	lw	$a3,4($t0)
	move	$t3,$a3		# $t3 = T[i]
	sw	$a2,4($t0)		# T[i] = T[i-1]
	sw	$t3,0($t0)		# T[i-1] = $t3
	addi	$t2,$t2,-1		#$t2--
	addi	$t0,$t0,4
	j	while
	
	end_while:
	addi	$t0,$t0,4
	addi	$t1,$t1,1
	j	for
	
end_for:	
	
	add	$s1,$zero,$s0
	la	$t0,T
	
	la	$a0,sorted
	li	$v0,4
	syscall
print_array:	
	beqz	$s1,end
	sw	$a0,0($t0)
	li	$v0,1
	syscall
	addi	$s1,$s1,-1
	addi	$t0,$t0,4
	j	print_array
	
end:
	li	$v0,10
	syscall
