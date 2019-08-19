all:
	@Make -C assembler
	@Make -C vm
	@Make -C disasm
	@mv ./vm/corewar ./corewar
	@mv ./assembler/asm ./asm
	@mv ./disasm/disassembler ./disassembler

clean:
	@Make -C assembler clean
	@Make -C vm clean
	@Make -C disasm clean
	@Make -C ./common_files/libft clean

fclean:
	@Make -C assembler fclean
	@Make -C vm fclean
	@Make -C disasm fclean
	@Make -C ./common_files/libft fclean
	@rm -rf asm
	@rm -rf corewar
	@rm -rf disassembler

re: fclean all
