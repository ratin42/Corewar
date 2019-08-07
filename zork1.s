.comment "I'M ALIIIIVE"
.name "zork"

live:	live %1
		zjmp %:live
        
l2:		sti r1, %:live, %1  
		and r1, %0	, r1
