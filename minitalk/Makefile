NAME = minitalk

CC = gcc -Werror -Wextra -Wall

SRC = utils.c

SRC-S =	server.c

SRC-C =	client.c

OBJ-C = $(SRC-C:.c=.o)

OBJ-S = $(SRC-S:.c=.o)

OBJ = $(SRC:.c=.o)

PRINTF = ft_printf/libftprintf.a

all: $(NAME)

MAKEPRINTF:
	make -s -C ./ft_printf/

MAKEPRINTF_CLEAN:
	make clean -s -C ./ft_printf/

MAKEPRINTF_FCLEAN:
	make fclean -s -C ./ft_printf/

$(NAME): $(OBJ-C) $(OBJ-S) $(OBJ) MAKEPRINTF
	$(CC) $(OBJ-S) $(OBJ) $(PRINTF) -o server
	$(CC) $(OBJ-C) $(OBJ) $(PRINTF) -o client

clean: MAKEPRINTF_CLEAN
	rm -f $(OBJ)
	rm -f $(OBJ-S)
	rm -f $(OBJ-C)

fclean: clean MAKEPRINTF_FCLEAN
	rm -f client
	rm -f server

re: fclean all

.PHONY: clean fclean all re
