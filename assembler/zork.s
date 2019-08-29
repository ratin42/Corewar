.comment "I'm ZORK!!!!"
.name "zork"

l2:		sti r1, %:live, %-1-2
		and r1, %-1, r1

live:	live %1
		zjmp %:live

