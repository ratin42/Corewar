.comment "Champion de test de l'instruction FORK."
.name "Test FORK"

live:	live %1
		ld %42, r1
		st r1,256
		fork %25
		zjmp %:live
		st r1,256
		and %3,%4,r5
		zjmp %:live
fork:	st r1,256
		and %3,%4,r6
		zjmp %:fork
