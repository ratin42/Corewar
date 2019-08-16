NAME = asm

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I $(LIBFT) -I$(INC_FOLD)

C_GREEN = "\033[32m"
C_BLUE = "\033[36m"
C_BASE = "\033[00m"

LIBFT = ../common_files/libft/

LIBFT.a = ../common_files/libft/libft.a

INC_FOLD = includes/

INC = includes/corewar.h \
	  includes/struct.h \

SRC = srcs/op.c \
	  srcs/asm.c \
	  srcs/debug.c \
	  srcs/param.c \
	  srcs/param2.c \
	  srcs/param3.c \
	  srcs/swap_endian.c \
	  srcs/get_opc.c \
	  srcs/get_file.c \
	  srcs/get_label.c \
	  srcs/free_prog.c \
	  srcs/parse_func.c \
	  srcs/count_size.c \
	  srcs/get_label2.c \
	  srcs/get_opcode.c \
	  srcs/write_file.c \
	  srcs/get_header.c \
	  srcs/param_conv.c \
	  srcs/param_conv2.c \
	  srcs/instruction.c \
	  srcs/param_error.c \
	  srcs/label_correc.c \
	  srcs/param_creation.c \
	  srcs/get_instruction.c \
	  srcs/convert_instruction.c

OBJ = $(SRC:.c=.o)

all: $(NAME) $(LIBFT)

$(NAME): $(LIBFT) $(INC_FOLD) Makefile $(OBJ)
	@make -C $(LIBFT)
	@$(CC) $(OBJ) $(LIBFT.a) -o $(NAME)
	@printf "\x1b[32mASM Ready ✔\x1b[0m\n\n"

%.o: %.c $(INC)
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo "file =" $(C_GREEN){ $< } $(C_BASE)

clean:
	@make -C $(LIBFT) clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C $(LIBFT) fclean
	@/bin/rm -f $(NAME)
	@echo "\033[31m$(NAME) deleted\033[0m"

re: fclean all

.PHONY: all fclean clean re
