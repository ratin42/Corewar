#!/bin/bash

#This test makes the assumption that instructions LD and ZJMP work correctly.

# Need to test
# - Write in register
# - Write on memory (positive and negative value)
# - Modify the carry
# - Has restricted address

source $(dirname $0)/param.sh

echo "### TESTING ADD ###"
./../../asm champ/04_add_champ.s
./../corewar -dump ${n_dump} champ/04_add_champ.cor > result/04_add_result.txt
./../corezaz -d ${n_dump} champ/04_add_champ.cor > result/04_add_zaz.txt
diff result/04_add_result.txt result/04_add_zaz.txt

result=$?
source $(dirname $0)/result.sh