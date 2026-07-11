NAME = rush02

CC = CC
CFLAGS = -Wall -Wextra -Werror
INC = includes

SRC = srcs/*.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

srcs/%.o: srcs/%.c includes/dict.h
	$(CC) $(CFLAGS) -I $(INC) -c $<-o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
