# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skayed <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 17:09:30 by skayed            #+#    #+#              #
#    Updated: 2025/01/27 17:09:35 by skayed           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#MACROS
NAME = libftprintf.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror 

SRCS = ft_printf.c ft_put_uns.c ft_putchar.c ft_putnbr_dec.c \
ft_putptr.c ft_putstr.c ft_strlen.c ft_putnbr_hex.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean 
	$(RM) $(NAME)

re: fclean all

