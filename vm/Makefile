# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ratin <ratin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/08 22:09:10 by hlombard          #+#    #+#              #
#    Updated: 2019/08/11 19:26:17 by ratin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I $(LIBFT) -I$(INC_FOLD)

LIBFT = libft/

LIBFT.a = libft/libft.a

INC_FOLD = includes/

INC = includes/vm.h

SRC = srcs/corewar.c \
	  srcs/parsing/parsing.c \
	  srcs/parsing/read_process.c \
	  srcs/parsing/order.c \
	  srcs/options/options.c \
	  srcs/debug/debug_tools.c \
	  srcs/exec/game.c \
	  srcs/exec/cycles.c \
	  srcs/utility/get_type.c \
	  srcs/utility/update_pc.c \
	  srcs/utility/inst_tool.c \
	  srcs/utility/ft_plst_manipulators.c \
	  srcs/utility/ft_arg_manipulators.c \
	  srcs/instructions/inst_get_params.c \
	  srcs/instructions/inst_add.c \
	  srcs/instructions/inst_sub.c \
	  srcs/instructions/inst_aff.c \
	  srcs/instructions/inst_sti.c \
	  srcs/ncurses/init.c \
	  srcs/instructions/inst_and.c \
	  srcs/instructions/inst_st.c \
#	  srcs/instructions/inst_fork.c \
	  srcs/instructions/inst_ld.c \
	  srcs/instructions/inst_ldi.c \
	  srcs/instructions/inst_lfork.c \
	  srcs/instructions/inst_live.c \
	  srcs/instructions/inst_lld.c \
	  srcs/instructions/inst_lldi.c \
	  srcs/instructions/inst_or.c \
	  srcs/instructions/inst_xor.c \
	  srcs/instructions/inst_zjmp.c \


OBJ = $(SRC:.c=.o)

all: $(NAME) $(LIBFT)

$(NAME): $(LIBFT) $(INC_FOLD) Makefile $(OBJ)
	@make -C $(LIBFT)
	$(CC) $(OBJ) $(LIBFT.a) -lncurses -o $(NAME)
	@echo "\033[32mReady ?\033[0m"

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@make -C $(LIBFT) clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C $(LIBFT) fclean
	@/bin/rm -f $(NAME)
	@echo "\033[31m$(NAME) deleted\033[0m"

re: fclean all

.PHONY: all fclean clean re
