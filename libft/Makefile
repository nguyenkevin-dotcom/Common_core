.PHONY: all clean fclean re

SRCS = $(addsuffix .c, ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy ft_strlcat ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split ft_itoa)
SRCS_OBJS = $(SRCS:%.c=%.o)
NAME = libft.a
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
INC_DIR = .
CPPFLAGS = -I $(INC_DIR)
ARNAME = ar rcs $(NAME)
RANNAME = ranlib $(NAME)
RM = rm -f

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