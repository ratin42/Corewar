#!/bin/bash

#This test makes the assumption that instructions LD, ST and ZJMP work correctly.

# Need to test
# - All the combination of parameters
# - Modify the carry
# - Has restricted address

source $(dirname $0)/color.sh

echo "### TESTING AND ###"
./../../asm champ/06_and_champ.s
./../corewar -dump 400 champ/06_and_champ.cor > result/06_and_result.txt
./../corezaz -d 400 champ/06_and_champ.cor > result/06_and_zaz.txt
diff result/06_and_result.txt result/06_and_zaz.txt

result=$?
source $(dirname $0)/result.sh

