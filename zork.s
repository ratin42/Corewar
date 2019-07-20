.name "zork"
.comment "hey"

l2:		sti r1, %:live, %1
		and r1, 10, r1

live:	live %1
		zjmp %:live
