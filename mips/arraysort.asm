#sort array decrecent / increacent
.data
	T: 	.space 100
	in: 	.asciiz"enter max array\n"
	val:	.asciiz"enter values"
	out:	.asciiz"sorted"
	choice:	.asciiz"croissant->1\ndecroissant->2\n"
	ln:	.asciiz"\n"
.text
.globl main
main:	
	li	$s0,0
	la	$a0,in			#array length
	li	$v0,4
	syscall
	li	$v0,5
	syscall
	add 	$a1,$zero,$v0		#hold max array in $a1
	
	la	$a0,choice		#sort type
	li	$v0,4
	syscall
	li	$v0,5
	syscall
	add 	$a2,$zero,$v0		#hold the choice in $a2
	
	
	la	$t0,T			#pointer the space
				#pointer for array when is added
input:					#input array values
	beq	$s0,$a1,end	
	li	$v0,5
	syscall
	sw	$v0,0($t0)
	addi	$t0,$t0,4
	addi	$s0,$s0,+1
	j	input
end:	
	addi	$s0,$zero,0		#initialize s0 =0
LOOP:
 for1:			
	beq	$s0,$a1,endfor		#for(s0 =a1,s0=0,s0--)
	addi	$s0,$s0,+1			
	add	$s1,$zero,$a1		#j = a1
	addi	$s1,$s1,-1		#j = a1-1
 	la	$t7,T
 for2:	
 	beqz	$s1,for1
 	addi	$s1,$s1,-1		#decrement by 1 for2 loop
 	
	lb	$t1,0($t7)
 	lb	$t2,4($t7)
	beq	$a2,1,cho1
	beq	$a2,2,cho2
	
cho1:  	bgt	$t1,$t2,swap1		#if decrecent
 	j	continue
 swap1:					
 	sb	$t2,0($t7)		#t2<-t1
 	sb	$t1,4($t7)		#t1<-t2
 
 continue:
 	addi	$t7,$t7,4		#increment by 1 cell
 	j	for2
 
 cho2:	bgt	$t2,$t1,swap2		#if increacent
 	j	continue
 swap2:
 	sb	$t1,0($t7)
 	sb	$t2,4($t7)
 	j	continue
 	
 endfor:
 	la	$a0,out
 	li	$v0,4
 	syscall
 	la	$t7,T
 	add	$s1,$zero,$a1	
 	
 print_array:
 	beqz	$s1,endall
 	la	$a0,ln
 	li	$v0,4
 	syscall
 	
 	lb	$a0,0($t7)
 	li	$v0,1
 	syscall
 	addi	$t7,$t7,4
 	addi	$s1,$s1,-1
 	j	print_array
 endall:
 	li	$v0,10
 	syscall
 
 