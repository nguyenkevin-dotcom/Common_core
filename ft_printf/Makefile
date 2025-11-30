NAME = libftprintf.a

SRC = ft_printf.c ft_formats.c ft_printf_char.c ft_printf_str.c ft_printf_hex.c
OBJS = $(SRC:%.c=%.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I . -I libft
RM = rm -f
ARNAME = ar rcs $(NAME)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	ar x $(LIBFT)
	$(ARNAME) $(OBJS) ft_*.o
	$(RM) ft_*.o

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

re: fclean all

.PHONY = all clean fclean re