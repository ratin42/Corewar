.comment "I'M ALIIIIVE"
.name "zork"

l2:		stir1, %:live, %1  
		and r1, %0	, r1

live:	live %1
		zjmp %:live

