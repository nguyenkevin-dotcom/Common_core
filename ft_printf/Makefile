NAME = libftprintf.a

SRC = ft_printf.c ft_formats.c ft_printf_char.c ft_printf_str.c ft_printf_ptr.c \
	ft_printf_dec.c ft_printf_unsigned_n.c ft_printf_hex.c \
	ft_printf_percentage.c
OBJS = $(SRC:%.c=%.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I . -I ./libft
RM = rm -f
ARNAME = ar rcs $(NAME)

LIBFT = ./libft/libft.a
LIBFT_TMP = .tmp_libft_objs

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	mkdir -p $(LIBFT_TMP)
	cd $(LIBFT_TMP) && ar x ../libft/libft.a
	$(ARNAME) $(OBJS) $(LIBFT_TMP)/*.o
	rm -rf $(LIBFT_TMP)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	make -C ./libft clean
	$(RM) $(OBJS)
	
fclean: clean
	make -C ./libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY = all clean fclean re