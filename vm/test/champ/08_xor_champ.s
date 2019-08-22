.comment "Champion de test de l'instruction XOR."
.name "Test XOR"

#need to check when the carry is modified
live:	live %1
		ld %3,r1
		ld %4,r2
		ld %7,r3
		ld %15,r4
		xor r1,r3,r9
		st r9,256
		xor -3,r4,r10
		st r10,256
		xor 27341,r1,r11
		st r11,256
		xor -3,6,r12
		st r12,256
		xor r3,%14,r13
		st r13,256
		xor -3,%27,r14
		st r14,256
		xor %91,%110,r15
		st r15,256
		xor %15,%8,r16
		zjmp %:live
		st r15,256
		st r16,256
		xor r1,r2,r16
		zjmp %:live
carry:	st r1,256
		xor r1,r2,r7
		zjmp %:carry
