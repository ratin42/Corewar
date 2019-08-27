#!/bin/bash

YELLOW='\033[0;33m'
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'
TOTAL=1
OK=0
ZERO=0
NB=0

rm -rf ./results/disassembler/our_output*
rm -rf ./results/disassembler/zaz_output*
rm -rf ./results/disassembler/diff*

echo "Which cycle to compare ? "
read CYCLE

#Transform all .s into .s.original and create .cor

for file in ./asm_valid/*.s
do
	./../ressources/vm_champs/asm $file 2>&1 1>&-
	mv $file $file.original
done;

#Create .cor.original copy

for file in ./asm_valid/*.cor;
do
	cp $file $file.original
done;

#Delete all .s files

for file in ./asm_valid/*.s
do
	rm -rf $file
done

#Disassemble .cor into a .s file and delete all .cor

for file in ./asm_valid/*.cor
do
	./../disassembler $file
	rm -rf $file
done;

#Reassemble and create .cor files

for file in ./asm_valid/*.s
do
	./../ressources/vm_champs/asm $file
done;

#Stocking output from original .cor file

for file in ./asm_valid/*.cor.original
do
	./../ressources/vm_champs/corewar -d $CYCLE $file > ./results/disassembler/original_$NB
	NB=$((NB+1))
done;

NB=$((0))

#Stocking output from .cor file generated with our disassembled .s file

for file in ./asm_valid/*.cor
do
	./../ressources/vm_champs/corewar -d $CYCLE $file > ./results/disassembler/new_$NB
	NB=$((NB + 1))
	rm -rf $file
done;

NB=$((0))

#Comparing outputs

for file in ./results/disassembler/*
do
	diff ./results/disassembler/original_$NB ./results/disassembler/new_$NB > ./results/disassembler/diff_$NB
	if [ "$?" = "$ZERO" ];then
		echo $GREEN"[OK]\n"$NC
		OK=$((OK+1))
	else
		echo $RED"[KO]\n"$NC
		echo "Check Details ? Y/n"
		read ANSWER
		if [ "$ANSWER" = "Y" ]; then
			clear
			cat ./results/disassembler/diff_$NB
			echo "\n\nContinue tests ? Y/n"
			read ANSWER
			if [ "$ANSWER" != "Y" ] ; then
				NB=$((NB + 1))
				break;
			fi
		fi
	fi
		NB=$((NB + 1))
done;

echo "\n\n-------------------------\n"
echo "Results : $OK / $NB\n"

if  [ $OK != $NB ]; then
	echo $RED"FAILED check details in ./results/vm_dump/\n" $NC
else
	echo $GREEN"PERFECT ✔" $NC
fi

#Restoring asm_valid folder back to original

for file in ./asm_valid/*.s.original
do
	mv "$file" "${file/.s.original/.s}"
done;

for file in ./asm_valid/*.cor.original
do
	rm -rf $file
done;
