# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ratin <ratin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 18:46:26 by ratin             #+#    #+#              #
#    Updated: 2019/08/08 17:29:18 by ratin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = asm

SRC_PATH1		:=	srcs
OBJ_PATH		:=	obj
INC_PATH		:=	includes
LIB_PATH		:=	libft

SRC_NAME1		:=	op.c \
					asm.c \
					debug.c \
					param.c \
					param2.c \
					param3.c \
					swap_endian.c \
					get_opc.c \
					get_file.c \
					get_label.c \
					free_prog.c \
					parse_func.c \
					count_size.c \
					get_label2.c \
					get_opcode.c \
					write_file.c \
					get_header.c \
					param_conv.c \
					param_conv2.c \
					instruction.c \
					param_error.c \
					label_correc.c \
					param_creation.c \
					get_instruction.c \
					convert_instruction.c \

INC_NAME		:=	corewar.h
LIB				:=	$(LIB_PATH)/libft.a
LIB_LINK		:=	-L $(LIB_PATH) -lft
OBJ1			:=	$(addprefix $(OBJ_PATH)/,$(SRC_NAME1:.c=.o))
INCS			:=	-I $(LIB_PATH)/$(INC_DIR) -I $(INC_DIR)
CC				:=	gcc
CFLAGS			:=	-Wall -Wextra -g
C_GREEN			:=	"\033[32m"
C_BLUE			:=	"\033[36m"
C_BASE			:=	"\033[00m"
PRINTF=test $(VERBOSE)$(TRAVIS) || printf


all: obj $(LIB) $(NAME1)

$(LIB):
	@make -C $(LIB_PATH)
	@ @$(PRINTF) "Libft:	"
	@ @$(PRINTF) "\x1b[32m✔\x1b[0m\n\n"

$(NAME1): $(OBJ1)
	@$(CC) $(CFLAGS) $(OBJ1) $(LIB) -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH1)/%.c $(INC_PATH)/*
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_PATH)/
	@ @echo "file =" $(C_BLUE){ $< } $(C_BASE)

obj:
	@mkdir -p obj

clean:
	@rm -rf $(OBJ) $(LIB_PATH)/*.o
	@rm -rf obj

fclean: clean
	@rm -f $(NAME1)
	@rm -f $(NAME2)
	@make -C $(LIB_PATH) fclean

re: fclean all

.PHONY: all fclean clean re norme
