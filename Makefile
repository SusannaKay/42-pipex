NAME = pipex
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRC	= main.c path_cmd.c pipex_struct.c
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ) $(MINILIBX) $(LIBFT)
	gcc $(OBJ) $(CFLAGS) $(LIBFT) $(NAME)

clean:

	rm -f $(OBJ)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(OBJ)
	make -C $(LIBFT_PATH) fclean

re: fclean all

%.o: %.c
	gcc $(CFLAGS)$(LIBFT_PATH) -O3 -c $< -o $@


$(LIBFT):
	make -C $(LIBFT_PATH)

.PHONY: all bonus clean fclean re