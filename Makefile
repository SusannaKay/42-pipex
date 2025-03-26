NAME = pipex
CFLAGS = -Wall -Wextra -Werror
CC = gcc

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRC = main.c path_cmd.c pipex_struct.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME) $(CFLAGS)

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
