_This project has been created as part of 42 curriculum by kevnguye@student.42prague.com_

# Description
The goal of this project is to replicate the behaviour of function printf() on certain conversions in C language.

To meet this goal we need to implement these following conversions:
- %c Prints a single character.
- %s Prints a string (as defined by the common C convention).
- %p The void * pointer argument has to be printed in hexadecimal format.
- %d Prints a decimal (base 10) number.
- %i Prints an integer in base 10.
- %u Prints an unsigned decimal (base 10) number.
- %x Prints a number in hexadecimal (base 16) lowercase format.
- %X Prints a number in hexadecimal (base 16) uppercase format.
- %% Prints a percent sign.

# Instructions
First thing to do is to clone git repository into your computer. You need to open your terminal and write command:
```
git clone [address of git repository] [name of the directory]
```
After that you will with `cd` get into directory of that file and then with `ls */**` you will see every file that is inside of that directory.
```
cd [name of the directory]
ls */**
```
It should look like this after `cd`:
```
ft_printf_final [master●] % 
```
and after `ls *`:
```
ft_formats.c      ft_printf_dec.c  ft_printf_percentage.c  ft_printf_unsigned_n.c
ft_printf.c       ft_printf.h      ft_printf_ptr.c         Makefile
ft_printf_char.c  ft_printf_hex.c  ft_printf_str.c         README.md

libft:
ft_atoi.c     ft_lstadd_back.c   ft_memchr.c      ft_split.c     ft_strncmp.c
ft_bzero.c    ft_lstadd_front.c  ft_memcmp.c      ft_strchr.c    ft_strnstr.c
ft_calloc.c   ft_lstclear.c      ft_memcpy.c      ft_strdup.c    ft_strrchr.c
ft_isalnum.c  ft_lstdelone.c     ft_memmove.c     ft_striteri.c  ft_strtrim.c
ft_isalpha.c  ft_lstiter.c       ft_memset.c      ft_strjoin.c   ft_substr.c
ft_isascii.c  ft_lstlast.c       ft_putchar_fd.c  ft_strlcat.c   ft_tolower.c
ft_isdigit.c  ft_lstmap.c        ft_putendl_fd.c  ft_strlcpy.c   ft_toupper.c
ft_isprint.c  ft_lstnew.c        ft_putnbr_fd.c   ft_strlen.c    libft.h
ft_itoa.c     ft_lstsize.c       ft_putstr_fd.c   ft_strmapi.c   Makefile
```
If it is same? then great! Let's move to another step.

What I would recommend is to open this directory inside VSCode for better readability of the codes. It is done with command:
```
code .
```
## Makefile
For this project we also created Makefile not only because it was mandatory but also for saving our time.

Makefile is like recept or configuration file that with command `make` tells, how it must compile and assemble software project.

Here's the content of project's Makefile:
```makefile
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
```
## Compiling
For compiling you just need to write `make` and then do `cc -Wall -Wextra -Werror [c.file that is for testing the functionality of the function ft_printf()] libftprintf.a`
```
make
cc -Wall -Wextra -Werror [c.file that is for testing the functionality of the function ft_printf()] libftprintf.a
```
The outcome of these commands will be file named a.out which with `./a.out` will show the output of the testing c.file.
```
./a.out
```

# Resources
- https://cplusplus.com/reference/cstdio/printf/
- https://gemini.google.com

The AI was mainly used for ideas of how to approach this project.

# Detailed explanation
The project consists of:
- **libft** - the library that was created from other project called _libft_
- **ft_formats.c** - what character comes after %
- **ft_printf_char.c** - call function inside file if character after % is c
- **ft_printf_dec.c** - call function inside file if character after % is i or d
- **ft_printf_hex.c** - call function inside file if character after % is x or X
- **ft_printf_percentage.c** - call function inside file if character after % is %
- **ft_printf_ptr.c** - call function inside file if character after % is p
- **ft_printf_str.c** - call function inside file if character after % is s
- **ft_printf_unsigned_n.c** - call function inside file if character after % is u
- **ft_printf.c** - primary function that starts everything

## ft_printf.c
```c
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		printf_length;
	va_list	args;

	i = 0;
	printf_length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			printf_length += ft_formats(&args, format[i]);
		}
		else
			printf_length += ft_printf_char(format[i]);
		i++;
	}
	va_end(args);
	return (printf_length);
}
```
This function will read firstly format and then decide with if-else if the format starts with `%` or not. If format starts with `%` then it will call function ft_formats() and if not then it will call function ft_printf_char(). At the same time he will also count the number of characters inside format.

## ft_formats.c
```c
#include "ft_printf.h"

int	ft_formats(va_list *args, const char format)
{
	int	printf_length;

	printf_length = 0;
	if (format == 'c')
		printf_length += ft_printf_char(va_arg(*args, int));
	else if (format == 's')
		printf_length += ft_printf_str(va_arg(*args, char *));
	else if (format == 'p')
		printf_length += ft_printf_ptr(va_arg(*args, void *));
	else if (format == 'd' || format == 'i')
		printf_length += ft_printf_dec(va_arg(*args, int));
	else if (format == 'u')
		printf_length += ft_printf_unsigned_n(va_arg(*args, unsigned int));
	else if (format == 'x' || format == 'X')
		printf_length += ft_printf_hex(va_arg(*args, unsigned long long),
				format);
	else if (format == '%')
		printf_length += ft_printf_percentage();
	return (printf_length);
}
```
This function check what character comes after % and also at the same time will return the number of characters.

For `ft_printf_char()` I chose the data structure `int` because the program will translate it into ASCII.

For `ft_printf_str()` I chose the data structure `char *` because that's the way how to define string.

For `ft_printf_ptr()` I chose the data structure `void *` because void tells us whatever data structure can be there but at the moment we don't know.

For `ft_printf_dec()` I chose the data structure `int` because we are working with whole numbers.

For `ft_printf_unsigned_n()` I chose the data structure `unsigned int` and that is self-explanatory why this data structure was chosen.

For `ft_printf_hex()` I chose the data structure `unsigned long long` because for the range of hexadecimal adress for one variable you need at least 64-bit and with `unsigned long long` in C you're guaranteed that you will get 64-bit.

For `ft_printf_percentage()` I didn't choose anything because it this functions only print percentage.

## ft_printf_char.c
```c
#include "ft_printf.h"

int	ft_printf_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
```
This function just print the character by function `ft_putchar_fd` from library _libft_ and return number of characters 1.

## ft_printf_dec.c
```c
#include "ft_printf.h"

static int	ft_intlen(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		n = n - 1;
	if (n < 0)
	{
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_printf_dec(int n)
{
	int	printf_length;

	printf_length = ft_intlen(n);
	if (n < 0)
		printf_length++;
	ft_putnbr_fd(n, 1);
	return (printf_length);
}
```

For this function i have created another function but static so it will be used only on this file.

`ft_intlen()` - is only for counting characters that will be used in `ft_printf_dec()`.

`ft_printf_dec()` is by function `ft_putnbr_fd()` from library _libft_ printing number and return the number of characters by `ft_intlen()`.

## ft_printf_hex.c 
```c
#include "ft_printf.h"

static int	ft_put_to_hex(unsigned int n, const char format)
{
	char	*base;
	int		len;

	base = "0123456789abcdef";
	if (format == 'X')
		base = "0123456789ABCDEF";
	len = 0;
	if (n >= 16)
		len += ft_put_to_hex(n / 16, format);
	write(1, &base[n % 16], 1);
	len++;
	return (len);
}

int	ft_printf_hex(unsigned long long n, const char format)
{
	int	printf_length;

	printf_length = 0;
	printf_length += ft_put_to_hex(n, format);
	return (printf_length);
}
```
This is created from 2 functions, which `ft_put_to_hex` is static. `ft_put_to_hex` is changing 10 base text or number into 16 base. And because we need to also consider capital letters i have included another argument for this function so it could take the format.

`ft_print_hex` just apply the function `ft_put_to_hex` and returns the number of characters.

## ft_printf_percentage.c
```c
#include "ft_printf.h"

int	ft_printf_percentage(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
```
This just print % and return 1 as number of characters.

## ft_printf_ptr.c
```c
#include "ft_printf.h"

static int	ft_put_to_hex(unsigned long long n)
{
	char	*base;
	int		len;

	base = "0123456789abcdef";
	len = 0;
	if (n >= 16)
		len += ft_put_to_hex(n / 16);
	write(1, &base[n % 16], 1);
	len++;
	return (len);
}

int	ft_printf_ptr(void *ptr)
{
	int					printf_length;
	unsigned long long	address;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	address = (unsigned long long)ptr;
	printf_length = 0;
	write(1, "0x", 2);
	printf_length += 2;
	printf_length += ft_put_to_hex(address);
	return (printf_length);
}
```
This file is similar to `ft_printf_hex.c` but the difference is that we don't need to be aware of case-sensitive situation and also if the value is `NULL` then instead of printing nothing we will print `"(nil)"`.

## ft_printf_str.c
```c
#include "ft_printf.h"

int	ft_printf_str(char *str)
{
	int		printf_length;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	printf_length = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (printf_length);
}
```
This is for printing string. Firstly it will check if there is even any string. If not then it will print `"(null)"`. Then it will count the length of string and then with function `ft_putstr_fd()` print the string. Return value is the length of string.

## ft_printf_unsigned_n.c
```c
static void	ft_putnbr_unsigned(unsigned int n, int *count)
{
	if (n > 9)
		ft_putnbr_unsigned(n / 10, count);
	n = (n % 10) + '0';
	ft_putchar_fd(n, 1);
	(*count)++;
}

int	ft_printf_unsigned_n(unsigned int n)
{
	int				count;

	count = 0;
	ft_putnbr_unsigned(n, &count);
	return (count);
}
```
I have approached this similarly with `ft_putnbr_fd()` but for this situation with unsigned int. Because unsigned int doesn't go into negative numbers we needed only to check whether the number is two or more decimal or one decimal. If it was two or more decimal then we needed to divide it by ten and call again that function. This action is what we call recursive style. If the number is one decimal then we will turn it into character by adding `'0'` and then print it with function `ft_putchar_fd()`. After all of that will increment `count` by one and because it is a pointer it will hold our value until the end.

## ft_printf.h
```c
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_formats(va_list *args, const char format);
int	ft_printf_char(int c);
int	ft_printf_str(char *str);
int	ft_printf_ptr(void *ptr);
int	ft_printf_dec(int n);
int	ft_printf_unsigned_n(unsigned int n);
int	ft_printf_hex(unsigned long long n, const char format);
int	ft_printf_percentage(void);
#endif
```
In header files we need to declare our functions and include libraries that we are using in this project. So when we are starting, the program needs to know what function and libraries will be used before it could reach to the core of functions.