all:
	@make -C assembler
	@make -C vm
	@make -C disasm
	@mv ./vm/corewar ./corewar
	@mv ./assembler/asm ./asm
	@mv ./disasm/disassembler ./disassembler

clean:
	@make -C assembler clean
	@make -C vm clean
	@make -C disasm clean

fclean:
	@make -C assembler fclean
	@make -C vm fclean
	@make -C disasm fclean
	@rm -rf asm
	@rm -rf corewar
	@rm -rf disassembler

re: fclean all
