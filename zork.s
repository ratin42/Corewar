.name "zork"
.comment "hey"

l2: 	sti r1, %:live , %1 #ksaflksdaflk
		and r1, %-1, r1

live:	live %1
		zjmp %:live
