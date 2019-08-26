#!/bin/bash

YELLOW='\033[0;33m'
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'
TOTAL=1
OK=0
ZERO=0
ISOK="Writing output program to"

rm -rf ./results/asm_invalid/our_output*
rm -rf ./results/asm_invalid/zaz_output*

for file in ./asm_invalid/*.s;
do
	echo $YELLOW"[TEST $TOTAL]: `basename $file`"$NC
	./../asm $file > ./results/asm_invalid/our_output_$TOTAL 2>&1
	./../ressources/vm_champs/asm $file > ./results/asm_invalid/zaz_output_$TOTAL

	DATA1=$(cat ./results/asm_invalid/our_output_$TOTAL)
	DATA2=$(cat ./results/asm_invalid/zaz_output_$TOTAL)
	printf "\nOur Output: $DATA1"
	printf "\nZaz Output: $DATA2\n\n"
	if [ "$DATA1" != "$ISOK $file" ] && [ "$DATA2" != "$ISOK $file" ]; then
		echo $GREEN"[OK]\n"$NC
		OK=$((OK+1))
	else
		echo $RED"[KO]\n"$NC
	fi
	TOTAL=$((TOTAL+1))
done;

TOTAL=$((TOTAL-1))

echo "\n\n-------------------------\n"
echo "Results : $OK / $TOTAL\n"

if  [ $OK != $TOTAL ]; then
	echo $RED"FAILED\n" $NC
else
	echo $GREEN"PERFECT ✔" $NC
fi
