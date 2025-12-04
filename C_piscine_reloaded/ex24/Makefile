SRCS_SRC = $(addprefix srcs/, $(addsuffix .c, ft_putchar ft_putstr ft_strcmp ft_strlen ft_swap))
SRCS_OBJS := $(SRCS_SRC:%.c=%.o)
NAME = libft.a
CC = cc
CCFLAGS = -Wall -Werror -Wextra
INC_DIR = .
CPPFLAGS = -I $(INC_DIR)
RM = rm -f
ARNAME = ar rcs $(NAME)
RANNAME = ranlib $(NAME)

all: $(NAME)

$(NAME): $(SRCS_OBJS)
	$(ARNAME) $(SRCS_OBJS)
	$(RANNAME)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CCFLAGS) -c $< -o $@

clean:
	$(RM) $(SRCS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re