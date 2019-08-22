.comment "Champion de test de l'instruction LDI."
.name "Test LDI"

live:	live %1
		ld %42, r1
		ld %3,r2
		ld %1,r3
		ld %20,r4
		ld %-200,r5
		ldi r2,r3,r8
		st r8,256
		ldi r4,%5,r9
		st r9,256
		ldi 2,r5,r10 #voir si ca vaut autre chose que 0
		st r10,256
		ldi 1,%2,r11 #voir si ca vaut autre chose que 0
		st r11,256
		ldi %-30,r1,r12
		st r12,256
		ldi %-224,%220,r13
		st r13,256
		ldi %1000,%24,r14
		st r14,256
		ldi %1000,%24,r15
		zjmp %:carry
		st r1,256
		ldi %56,%200,r16
		zjmp %:live
carry:	st r1,256
		zjmp %:carry
