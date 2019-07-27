.name "zork"
.comment "hey"

l2: 	sti r1, %:live, %:live
		and r1, %0, r1

live:	live %1
		zjmp %:live
