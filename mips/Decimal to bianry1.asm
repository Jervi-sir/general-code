#Decimal to Binary
#positive Numbers only 
.data
	A:	.word	0,0,0,0,0,0,0,0,0,0		#array for div result 
	B:	.word	0,0,0,0,0,0,0,0,0,0,0		#array for reverse of A
	enter:	.asciiz	"enter number"	
	
.text
	la	$a0,enter
	li	$v0,4
	syscall
	li	$v0,5
	syscall
	
	add	$t0,$zero,$v0
	li	$t1,2
	li	$t3,0
	li	$t4,0
	
	
	#fill A array with the rest of division
while:
	blt	$t0,1,End
	div	$t0,$t1
	mfhi	$t2			#the rest
	mflo	$t0		
	
	sw	$t2,A($t3)
	addi	$t3,$t3,4		#boost array
	add	$t4,$t4,1		#as counter
	
	j	while

End:
	addi	$t3,$t3,-4		#decrese array by one case
	li	$t6,0
	li	$t7,0
	
	#reverse A array in B array
while2:
	bge	$t6,$t4,End2
	lw	$s0,A($t3)
	sw	$s0,B($t7)
	
	addi	$t3,$t3,-4		#decrese array by one case
	addi	$t6,$t6,1
	addi	$t7,$t7,4
	
	j	while2

End2:
	li	$t7,0
	li	$t6,0

	#show B component
while3:
	bge	$t6,$t4,End3
	lw	$a0,B($t7)
	li	$v0,1
	syscall
	addi	$t6,$t6,1
	addi	$t7,$t7,4
	
	j	while3

End3:
	li	$v0,10
	syscall
	