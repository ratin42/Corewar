#!/bin/bash

#This test makes the assumption that instructions LD, ST and ZJMP work correctly.

# Need to test
# - All the combination of parameters
# - Modify the carry
# - Has restricted address

source $(dirname $0)/color.sh

echo "### TESTING SUB ###"
./../../asm champ/05_sub_champ.s
./../corewar -dump 400 champ/05_sub_champ.cor > result/05_sub_result.txt
./../corezaz -d 400 champ/05_sub_champ.cor > result/05_sub_zaz.txt
diff result/05_sub_result.txt result/05_sub_zaz.txt

source $(dirname $0)/result.sh

