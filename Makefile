SRC = push_swap.c \
		ft_printf.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_atoi.c \
		ft_lstadd_back.c \
		ft_lstlast.c \
		ft_lstnew.c

CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
OBJ = $(SRC:.c=.o)
.PHONY : all clean fclean re

all : re

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)
	ar rcs $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)
