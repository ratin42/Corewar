#!/bin/bash

#This test makes the assumption that instructions LD and ZJMP work correctly.

# Need to test
# - Write in register
# - Write on memory (positive and negative value)
# - Modify the carry
# - Has restricted address

source $(dirname $0)/color.sh

echo "### TESTING ST ###"
./../../asm champ/03_st_champ.s
./../corewar -dump 400 champ/03_st_champ.cor > result/03_st_result.txt
./../corezaz -d 400 champ/03_st_champ.cor > result/03_st_zaz.txt
diff result/03_st_result.txt result/03_st_zaz.txt

source $(dirname $0)/result.sh