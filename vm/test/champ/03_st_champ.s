.comment "Champion de test de l'instruction ST."
.name "Test ST"

live:	live %1
		ld %1,r1
		st r1,256
		st r1,-5
		ld %8,r2
		st r2,r3
		st r3,256
		st r1,1280
		zjmp %:carry
		st r16,256
		zjmp %:live
carry:	st r1,256
		zjmp %:carry
