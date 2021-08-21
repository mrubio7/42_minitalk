NAME = minitalk

CC = gcc -Werror -Wextra -Wall

SRC-S =	server.c

SRC-C =	client.c

OBJ-C = $(SRC-C:.c=.o)

OBJ-S = $(SRC-S:.c=.o)

LIB = libft/libft.a

all: $(NAME)

MAKELIBS:
	make -s -C ./libft/

$(NAME): $(OBJ-C) $(OBJ-S) MAKELIBS
	$(CC) $(OBJ-S) -o server
	$(CC) $(OBJ-C) $(LIB) -o client

clean:
	rm -f libft/*.o
	rm -f $(OBJ-S)
	rm -f $(OBJ-C)

fclean: clean
	rm -f libft/*.a
	rm -f client
	rm -f server

re: fclean all

.PHONY: clean fclean all re
