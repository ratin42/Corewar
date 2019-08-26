#!/bin/bash

YELLOW='\033[0;33m'
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'
TOTAL=1
OK=0
ZERO=0

rm -rf ./results/asm_valid/our_output*
rm -rf ./results/asm_valid/zaz_output*
rm -rf ./results/asm_valid/diff*

for file in ./asm_valid/*.s;
do
	echo $YELLOW"[TEST $TOTAL]: `basename $file`"$NC
	./../asm $file 2>&- > ./results/asm_valid/our_output_$TOTAL
	./../ressources/vm_champs/asm $file 2>&- > ./results/asm_valid/zaz_output_$TOTAL
	diff ./results/asm_valid/our_output_$TOTAL ./results/asm_valid/zaz_output_$TOTAL > ./results/asm_valid/diff_$TOTAL
	if [ "$?" = "$ZERO" ]; then
		echo $GREEN"[OK]\n"$NC
		OK=$((OK+1))
	else
		echo $RED"[KO]\n"$NC
		echo "Check details ? Y/n "
		read ANSWER
		if [ "$ANSWER" = "Y" ] ; then
			clear
			cat ./results/asm_valid/diff_$TOTAL
			echo "\n\nContinue tests ? Y/n"
			read ANSWER
			if [ "$ANSWER" != "Y" ] ; then
				TOTAL=$((TOTAL+1))
				break;
			fi
		fi
	fi
	TOTAL=$((TOTAL+1))
done;

TOTAL=$((TOTAL-1))

echo "\n\n-------------------------\n"
echo "Results : $OK / $TOTAL\n"

if  [ $OK != $TOTAL ]; then
	echo $RED"FAILED check details in ./results/asm_valid/\n" $NC
else
	echo $GREEN"PERFECT ✔" $NC
fi

for file in ./asm_valid/*.cor
do
	rm -rf $file
done;
