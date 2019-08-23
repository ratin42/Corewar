#!/bin/bash

#This test makes the assumption that instructions LD, ST and ZJMP work correctly.

# Need to test
# - All the combination of parameters
# - Modify the carry
# - Has restricted address

source $(dirname $0)/color.sh

echo "### TESTING XOR ###"
./../../asm champ/08_xor_champ.s
./../corewar -dump 400 champ/08_xor_champ.cor > result/08_xor_result.txt
./../corezaz -d 400 champ/08_xor_champ.cor > result/08_xor_zaz.txt
diff result/08_xor_result.txt result/08_xor_zaz.txt

result=$?
source $(dirname $0)/result.sh

