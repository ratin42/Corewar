#!/bin/bash

#This test makes the assumption that instructions LD, ST and ZJMP work correctly.

# Need to test
# - All the combination of parameters
# - Modify the carry
# - Has restricted address

source $(dirname $0)/param.sh

echo "### TESTING OR ###"
./../../asm champ/07_or_champ.s
./../corewar -dump ${n_dump} champ/07_or_champ.cor > result/07_or_result.txt
./../corezaz -d ${n_dump} champ/07_or_champ.cor > result/07_or_zaz.txt
diff result/07_or_result.txt result/07_or_zaz.txt

result=$?
source $(dirname $0)/result.sh

