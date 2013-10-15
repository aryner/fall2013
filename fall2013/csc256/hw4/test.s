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

