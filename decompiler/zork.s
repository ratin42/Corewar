.name "zork"
.comment "I'm ZORK!!!!"

sti r1, %15, %1
and r1, %0, r1
live %1
zjmp %-5
