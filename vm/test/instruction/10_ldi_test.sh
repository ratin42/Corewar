#!/bin/bash

#This test makes the assumption that instructions LD and ZJMP work correctly.

# Need to test
# - Write on memory (positive and negative value)
# - All combination of arg2(RG/ID/D2) and arg3(ID/D2)
# - Modify the carry
# - Has restricted address

source $(dirname $0)/color.sh

echo "### TESTING LDI ###"
./../../asm champ/10_ldi_champ.s
./../corewar -dump ${n_dump} champ/10_ldi_champ.cor > result/10_ldi_result.txt
./../corezaz -d ${n_dump} champ/10_ldi_champ.cor > result/10_ldi_zaz.txt
diff result/10_ldi_result.txt result/10_ldi_zaz.txt

result=$?
source $(dirname $0)/result.sh
