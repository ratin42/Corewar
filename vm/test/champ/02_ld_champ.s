.comment "Champion de test de l'instruction LD."
.name "Test LD"

live:	live %1
		ld %55,r1
		st r1,256
		ld -4,r2
		st r2,256
		ld 6,r3
		st r3,256
		ld 1030,r4
		st r4,256
		ld -1028,r5
		st r5,256
		ld %40,r8
		zjmp %:carry
		ld %0,r9
		zjmp %:live
carry:	st r1,256
		zjmp %:carry
