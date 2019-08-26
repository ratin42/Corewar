#!/bin/bash

./../../asm champ/${test}_champ.s
./../corewar -dump ${n_dump} champ/${test}_champ.cor > result/${test}_result.txt
./../corezaz -d ${n_dump} champ/${test}_champ.cor > result/${test}_zaz.txt
diff result/${test}_result.txt result/${test}_zaz.txt
result=$?