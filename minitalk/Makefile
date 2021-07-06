NAME = minitalk

CC = gcc -Werror -Wextra -Wall

SRC-S = 

SRC-C = 

OBJ-C = $(SRC-C:.c=.o)

OBJ-S = $(SRC-S:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ-S) -o minitalk-server
	$(CC) $(OBJ-C) -o minitalk-client

clean:
	rm -f $(OBJ-C) $(OBJ-S)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
