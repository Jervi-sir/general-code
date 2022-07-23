#insertion sort
.data
	space:	.asciiz " "		
	line:	.asciiz	"\n"		
	colonsp:	.asciiz ": "	
	array:	.word	0 : 1000	
	size:	.word	5		# compteur acctuel tableau
enter_size:	.asciiz	"Enter size  (0 < N < 1000): "
value:	.asciiz	"Input each value: "
input:	.asciiz	"enter valuer#"
fin1:	.asciiz "Sorted:"

	.text

main:
info:
	li	$v0, 4			
	la	$a0, enter_size	
	syscall				
	
	li	$v0, 5			
	syscall				
	la	$t0, size		# address of size to $t0.
	sw	$v0, 0($t0)		# store value to size.
	
	li	$v0, 4			
	la	$a0, value	
	syscall				
	li	$v0, 4			
	la	$a0, line		
	syscall				
	

	la	$t0, array		# tableu pointé par $t0.
	lw	$t1, size		# taill
	li	$t2, 0			# boucle commence de 0.
	
input1:
	bge	$t2, $t1, end_input	# while ($t2 < $t1).
	li	$v0, 4			
	la	$a0, input 
	syscall				
	li	$v0, 1			
	addi	$a0, $t2, 1		
	syscall				
	li	$v0, 4			
	la	$a0, colonsp		
	syscall				

	li	$v0, 5			
	syscall				
	sw	$v0, 0($t0)		# store dans tableau

	addi	$t0, $t0, 4		# increment pointeur par 4.
	addi	$t2, $t2, 1		# increment boucle par 1.
	j	input1			
	
end_input:
	jal	print			
	
sort_prep:
	la	$t0, array		# boucle tableau $t0.
	lw	$t1, size		# boucle tableau taill $t1.
	li	$t2, 1			# boucle.
	
sort_x:
	la	$t0, array		# pointer le tableau.
	bge	$t2, $t1, sort_x_end	# while (t2 < $t1).
	move	$t3, $t2		# copy $t2 a $t3.
	
sort_iloop:
	la	$t0, array		# load array to $t0.
	mul	$t5, $t3, 4		# multipler $t3 par 4, et store dans $t5
	add	$t0, $t0, $t5		
	ble	$t3, $zero, sort_i_end	# while (t3 > 0).
	lw	$t7, 0($t0)		# array[$t3] to $t7.
	lw	$t6, -4($t0)		# array[$t3 - 1] to $t6.
	bge	$t7, $t6, sort_i_end	# while (array[$t3] < array[$t3 - 1]).
	lw	$t4, 0($t0)
	sw	$t6, 0($t0)
	sw	$t4, -4($t0)
	subi	$t3, $t3, 1
	j	sort_iloop		

sort_i_end:
	addi	$t2, $t2, 1		# increment boucle par 1.
	j	sort_x

sort_x_end:
	li	$v0, 4			
	la	$a0, fin1	
	syscall				
	li	$v0, 4			
	la	$a0, line		
	syscall				
	jal	print			
exit:
	li	$v0, 10			
	syscall				


print:
print_prep:
	la	$t0, array
	lw	$t1, size
	li	$t2, 0
print_loop:
	bge	$t2, $t1, print_end
	li	$v0, 1
	lw	$a0, 0($t0)
	syscall
	li	$v0, 4
	la	$a0, space
	syscall
	addi	$t0, $t0, 4
	addi	$t2, $t2, 1
	j	print_loop
print_end:
	li	$v0, 4
	la	$a0, line
	syscall
	jr	$ra