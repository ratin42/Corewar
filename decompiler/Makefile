# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ratin <ratin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 18:46:26 by ratin             #+#    #+#              #
#    Updated: 2019/08/16 12:50:06 by ratin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = decompiler

SRC_PATH1		:=	srcs
OBJ_PATH		:=	obj
INC_PATH		:=	includes
LIB_PATH		:=	libft

SRC_NAME1		:=	decompiler.c \
					read_process.c \
					debug.c \
					create_file.c \
					print_file.c \
					create_list.c \
					inst_tool.c \
					inst_sti.c \
					inst_and.c \
					inst_live.c \
					inst_zjmp.c \
					inst_ld.c \
					get_params.c \
					get_arg.c \

INC_NAME		:=	decompiler.h
LIB				:=	$(LIB_PATH)/libft.a
LIB_LINK		:=	-L $(LIB_PATH) -lft
OBJ1			:=	$(addprefix $(OBJ_PATH)/,$(SRC_NAME1:.c=.o))
INCS			:=	-I $(LIB_PATH)/$(INC_DIR) -I $(INC_DIR)
CC				:=	gcc
CFLAGS			:=	-Wall -Wextra -Werror
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

$(OBJ_PATH)/%.o: $(SRC_PATH1)/*/%.c $(INC_PATH)/*
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
