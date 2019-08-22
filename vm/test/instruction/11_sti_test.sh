#!/bin/bash

#This test makes the assumption that instructions LD and ZJMP work correctly.

# Need to test
# - Write on memory (positive and negative value)
# - All combination of arg2(RG/ID/D2) and arg3(ID/D2)
# - Modify the carry
# - Has restricted address

source $(dirname $0)/color.sh

echo "### TESTING STI ###"
./../../asm champ/11_sti_champ.s
./../corewar -dump ${n_dump} champ/11_sti_champ.cor > result/11_sti_result.txt
./../corezaz -d ${n_dump} champ/11_sti_champ.cor > result/11_sti_zaz.txt
diff result/11_sti_result.txt result/11_sti_zaz.txt

source $(dirname $0)/result.sh
