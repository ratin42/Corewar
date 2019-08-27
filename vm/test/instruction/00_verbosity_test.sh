#!/bin/bash

#This test looks at the verbosity option

source $(dirname $0)/param.sh

echo "### TESTING VERBOSITY ###"
test='00_verbosity'
./../../asm champ/${test}_champ.s
./../corezaz -v 31 -d ${n_dump} champ/${test}_champ.cor > result/${test}_zaz.txt
./../corewar -v 31 -dump ${n_dump} champ/${test}_champ.cor > result/${test}_result.txt
