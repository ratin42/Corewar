#!/bin/bash

#This test makes the assumption that instructions LD, AND and ZJMP work correctly.

# Need to test
# - Write in register
# - Write on memory (positive and negative value)
# - Modify the carry
# - Has restricted address

source $(dirname $0)/param.sh

echo "### TESTING ST ###"
./../../asm champ/03_st_champ.s
./../corewar -dump ${n_dump} champ/03_st_champ.cor > result/03_st_result.txt
./../corezaz -d ${n_dump} champ/03_st_champ.cor > result/03_st_zaz.txt
diff result/03_st_result.txt result/03_st_zaz.txt

result=$?
source $(dirname $0)/result.sh