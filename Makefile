SRC = sort.c \
		k_sort.c \
		sort_utils.c \
		ft_lstclear.c \
		ft_strlen.c \
		ft_lstnew.c \
		ft_lstadd_back.c \
		ft_lstsize.c \
		ft_lstlast.c \
		main.c \
		parsing.c \
		ft_atoi.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)
