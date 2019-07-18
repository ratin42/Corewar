NAME = libft.a

OBJECT = $(SRC:.c=.o)

SRC = ft_strlen.c ft_strdup.c ft_atoi.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_strcat.c ft_strcmp.c \
		ft_strcpy.c ft_tolower.c ft_toupper.c ft_strncmp.c ft_strncat.c \
		ft_strlcat.c ft_strncpy.c ft_strchr.c ft_strrchr.c ft_strstr.c \
		ft_strnstr.c ft_memcmp.c ft_memchr.c ft_memmove.c ft_memset.c \
		ft_bzero.c ft_memcpy.c ft_memccpy.c ft_putchar.c ft_putstr.c \
		ft_putnbr.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr.c \
		ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
		ft_itoa.c ft_strsplit.c ft_strtrim.c ft_strjoin.c ft_strsub.c \
		ft_strequ.c ft_strnequ.c ft_strmapi.c ft_strmap.c ft_striteri.c \
		ft_striter.c ft_strclr.c ft_strdel.c ft_strnew.c ft_memdel.c \
		ft_memalloc.c ft_lstadd.c ft_lstiter.c ft_lstnew.c ft_lstdelone.c \
		ft_lstdel.c ft_lstmap.c ft_isblank.c ft_str_is_alpha.c \
		ft_str_is_numeric.c ft_str_is_lowercase.c ft_str_is_uppercase.c \
		get_next_line.c ft_strjoin_free.c ft_print_words_tables.c \
		ft_putendl_fd.c ft_str_is_printable.c ft_strndup.c ft_strdjoin.c \
		ft_strfreedup.c ft_abs.c

C_GREEN	=	"\033[32m"
C_BLUE	=	"\033[36m"
C_BASE	=	"\033[00m"

CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJECT)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)

%.o: %.c
	@gcc -c $(CFLAGS) $^

fclean: clean
	@/bin/rm -f $(NAME)

clean:
	@/bin/rm -f $(OBJECT)
	@echo $(C_GREEN)"[CLEAN]" $(C_BASE)

re: fclean all

.PHONY: all clean fclean re
