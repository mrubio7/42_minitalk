NAME = minitalk

CC = gcc -Werror -Wextra -Wall

SRC-S = server.c

SRC-C = client.c

OBJ-C = $(SRC-C:.c=.o)

OBJ-S = $(SRC-S:.c=.o)

all: $(NAME)

$(NAME): $(OBJ-C) $(OBJ-S)
	$(CC) $(OBJ-S) -o server
	$(CC) $(OBJ-C) -o client

clean:
	rm -f $(OBJ-S)
	rm -f $(OBJ-C)

fclean: clean
	rm -f client
	rm -f server

re: fclean all

.PHONY: clean fclean all re
