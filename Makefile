NAME = pipex

CFLAGS = -Wall -Wextra -Werror
CC = gcc

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRC = main.c utils.c
SRC_BONUS = bonus/pipex_bonus.c bonus/utils_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME) $(CFLAGS)

$(LIBFT):
	make -C $(LIBFT_PATH)

bonus: $(OBJ_BONUS) $(LIBFT)
	$(CC) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS) $(CFLAGS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make -C $(LIBFT_PATH) fclean

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus
