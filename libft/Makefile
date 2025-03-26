#MACROS
NAME = libft.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror 

SRCS = ft_isascii.c ft_memcpy.c ft_strlcat.c ft_strrchr.c ft_atoi.c\
ft_isdigit.c ft_memmove.c ft_strlcpy.c ft_tolower.c ft_bzero.c\
ft_isprint.c ft_memset.c ft_strlen.c ft_toupper.c ft_calloc.c\
ft_memchr.c ft_strchr.c ft_strncmp.c ft_isalpha.c ft_memcmp.c\
ft_strdup.c ft_strnstr.c ft_isalnum.c ft_substr.c ft_strjoin.c\
ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
ft_itoa.c ft_split.c ft_strmapi.c ft_striteri.c ft_putnbr_fd.c\
get_next_line.c

SRCS_B = ft_lstnew.c ft_lstadd_front.c ft_lstlast.c ft_lstadd_back.c\
ft_lstdelone.c ft_lstsize.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

PRINTF_PATH = ./ft_printf
PRINTF = $(PRINTF_PATH)/libftprintf.a

all: $(NAME) $(PRINTF)

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

$(NAME) : $(OBJS) $(PRINTF)
	cp $(PRINTF) .
	ar -x libftprintf.a 
	ar rcs $(NAME) $(OBJS) *.o
	$(RM) *.o libftprintf.a

$(PRINTF) :
	make -C $(PRINTF_PATH)

clean:
	$(RM) $(OBJS) $(OBJS_B) 
	make -C $(PRINTF_PATH) clean

fclean: clean 
	$(RM) $(NAME)
	make -C $(PRINTF_PATH) fclean

re: fclean all

bonus: $(OBJS_B)
	ar rcs $(NAME) $(OBJS_B)

