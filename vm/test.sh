#!/bin/bash

first='../test_fx/vm_champs/Kappa.cor'
second='../test_fx/vm_champs/MarineKing.cor'
i=0
n=25000
incre=1000
while [[ $i -eq 0 ]]
do	
	echo $n
	((n +=  $incre))
	./corewar -v 31 -dump $n $first $second > ours.txt
	./corezaz -v 31 -d $n $first $second > zaz.txt
	diff ours.txt zaz.txt > diff.txt
	i=$?
done
