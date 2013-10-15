	.data
str:	.byte	0:16
endl:	.asciiz	"\n"

# num	$s0

	.text
main:	li	$s0, 0x8234000a	#  int num = 0x8234000a;

	move	$a0, $s0	#  IPtoDD(num, str);
	la	$a1, str
	jal	IPtoDD
	li	$v0, 4		#  cout << str << endl;
	la	$a0, str
	syscall
	li	$v0, 4
	la	$a0, endl
	syscall

	li	$s0, 0xab0932ba	#  num = 0xab0932ba;
	move	$a0, $s0	#  IPtoDD(num, str);
	la	$a1, str
	jal	IPtoDD
	li	$v0, 4		#  cout << str << endl;
	la	$a0, str
	syscall
	li	$v0, 4
	la	$a0, endl
	syscall

	li	$v0, 10
	syscall


	# arg0 = s0, arg1 = s1, numChar = s2, shift = s3, i = s4, temp = t0

IPtoDD:	addi	$sp,$sp,-24
	sw	$ra,20($sp)
	sw	$s0,16($sp)
	sw	$s1,12($sp)
	sw	$s2,8($sp)
	sw	$s3,4($sp)
	sw	$s4,($sp)
	add	$s0,$a0,$0
	add	$s1,$a1,$0
	li	$s3,24
	li	$s4,0
	li	$t1,46		
				# for(int i=0; i<4; i++) {
for:	srl	$t0,$s0,$s3	#	temp = arg0 >> shift;
	and	$t0,$t0,0xff	#	temp = temp & 0xff
	add	$a0,$t0,$0
	add	$a1,$s1,$0
	jal	byteTD		# 	numChar = byteToDec(temp, arg1);

	add	$s1,$s1,$v0	# 	arg1 += numChar;
	addi	$t1,$0,46
	sb	$t1,($s1)
	addi	$s1,$s1,1	# 	arg1++ = '.';
	addi	$s3,$s3,-8	# 	shift -= 8;
	addi	$s4,$s4,1
	blt	$s4,4,for	# }

	addi	$s1,$s1,-1	# arg1--;
	sb	$0,($s1)	# *arg1 = 0;
	
	lw	$ra,20($sp)
	lw	$s0,16($sp)
	lw	$s1,12($sp)
	lw	$s2,8($sp)
	lw	$s3,4($sp)
	lw	$s4,($sp)
	addi	$sp,$sp,24

	jr	$ra

	# arg0 = t0, arg1 = t1, temp = t2, flag = t3, count = t4

byteTD:	li	$t3,0
	li	$t4,0
	add	$t0,$0,$a0
	add	$t1,$0,$a1

	bne	$t0,0,else	# if (arg0 == 0) {
	li	$t2,48
	sb	$t2,($t1)	# 	*arg1 = '0';
	li	$v0,1		#	return 1;
	jr	$ra		# }
				# else {
else:	div	$t2,$t0,100	#	temp = arg0/100
	beq	$t2,0,next	#	if (temp != 0) {
	addi	$t2,$t2,0x30	
	sb	$t2,($t1)
	addi	$t1,$t1,1	# 		*arg1++ = (char)temp + 0x30;
	addi	$t4,$t4,1	# 		count++;
	li	$t3,1		# 		flag = 1; }

next:	addi	$t5,$0,100
	div	$t0,$t5		
	mfhi	$t2
	div	$t2,$t2,10	# 	temp = (arg0 % 100) / 10;

	bne	$t3,0,if2
	beq	$t2,0,last	# 	if((flaq != 0) || (temp != 0)) {

if2:	addi	$t2,$t2,0x30	#
	sb	$t2,($t1)	
	addi	$t1,$t1,1	# 		*arg1++ = (char)temp + 0x30;
	addi	$t4,$t4,1	# 		count++;

last:	addi	$t5,$0,10
	div	$t0,$t5
	mfhi	$t2		# 	temp = arg0 % 10;
	addi	$t2,$t2,0x30
	sb	$t2,($t1)	# 	*arg1 = (char)temp + 0x30
	addi	$t4,$t4,1	# 	count++;
	add	$v0,$0,$t4	# 	return count;
	jr	$ra		
