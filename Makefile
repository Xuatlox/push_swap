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
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
.PHONY : all clean fclean re

all : re

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) -g $(SRC)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean $(NAME)
