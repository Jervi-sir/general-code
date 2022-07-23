.data
mssg:.asciiz" \n rentre un  nombre : "
premier:.asciiz"le nombre est premier  "
nopremier:.asciiz"le nombre n'est pas premier "


.text
main:
	la	$a0,mssg
	li	$v0,4
	syscall
	
	li	$v0,5
	syscall
	move	$t0,$v0		#le nombez
		

	li	$t1,2
	li	$s0,1
debut:	
	bgt	$t1,$t0,drapeau
	beq	$t1,$t0,drapeau	
	beqz	$s0,drapeau
	
	div	$t0,$t1
	mfhi	$t2
	
	bnez	$t2,coninue
	  li	$s0,0
	  j	not_prime
	
coninue:
	addi	$t1,$t1,1
	j	debut	

drapeau:
	bne	$s0,1,not_prime

prime:	
	la	$a0,premier
	li	$v0,4
	syscall
	j	fin

not_prime:
	la	$a0,nopremier
	li	$v0,4
	syscall
	
fin:
	li	$v0,10
	syscall
	
		
