#!/bin/bash

make -C .. -s
./instruction/02_ld_test.sh
./instruction/03_st_test.sh
./instruction/04_add_test.sh
./instruction/05_sub_test.sh
./instruction/06_and_test.sh
./instruction/07_or_test.sh
./instruction/08_xor_test.sh
./instruction/10_ldi_test.sh
./instruction/11_sti_test.sh
./instruction/12_fork_test.sh
./instruction/13_lld_test.sh
./instruction/14_lldi_test.sh
./instruction/15_lfork_test.sh
./instruction/16_aff_test.sh
