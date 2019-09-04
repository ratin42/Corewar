.name "champ.s"
.comment "this is a comment..."

        sti r1, %:live, %1
        ld %0, r12
fork:
        live %1
        fork %256
live:
        live %1
        zjmp %:live
