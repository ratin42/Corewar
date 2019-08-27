.comment "Champion de test de l'option verbosity."
.name "Test VERBO"

live:	live %1				#01
		ld %55,r1			#02
		ld -4,r2			#02
		st r1,256			#03
		add r1,r2,r3		#04
		sub r1,r2,r3		#05
		and r1,-5,r3		#06
		or r1,-5,r3			#07
		xor r1,-5,r3		#08
		ldi 1,%2,r4			#10
		sti	r2,%233,%-22		#11
		sti	r2,%233,r1		#11
		fork %12140			#12
		lld %22,r5			#13
		lldi 1,%200,r5		#14
		lfork %21140			#15
		aff r1				#16
		or r1,r2,r3			#07
		zjmp %-30			#09
		and r7,r8,r9		#06
		zjmp %-30			#09



