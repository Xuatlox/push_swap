SRC = ./push_swap.c
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap.a
OBJ = $(SRC:.c=.o)
.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)
	ar -rc $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)