#!/bin/bash

#This test makes the assumption that instructions ST and ZJMP work correctly.

# Need to test
# - Write in register
# - Modify the carry
# - Has restricted address for indirect parameters.

source $(dirname $0)/param.sh

echo "### TESTING LD ###"
./../../asm champ/02_ld_champ.s
./../corewar -dump ${n_dump} champ/02_ld_champ.cor > result/02_ld_result.txt
./../corezaz -d ${n_dump} champ/02_ld_champ.cor > result/02_ld_zaz.txt
diff result/02_ld_result.txt result/02_ld_zaz.txt

result=$?
source $(dirname $0)/result.sh