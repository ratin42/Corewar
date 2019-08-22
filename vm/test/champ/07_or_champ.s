.comment "Champion de test de l'instruction OR."
.name "Test OR"

#need to check when the carry is modified
live:	live %1
		ld %3,r1
		ld %4,r2
		ld %7,r3
		ld %15,r4
		or r1,r3,r9
		st r9,256
		or -3,r4,r10
		st r10,256
		or 27341,r1,r11
		st r11,256
		or -3,6,r12
		st r12,256
		or r3,%14,r13
		st r13,256
		or -3,%27,r14
		st r14,256
		or %91,%110,r15
		st r15,256
		or %15,%8,r16
		zjmp %:live
		st r15,256
		st r16,256
		or r1,r2,r16
		zjmp %:live
carry:	st r1,256
		or r1,r2,r7
		zjmp %:carry
