This project has been created as part of the 42 curriculum by kevnguye@student.42prague.com

# Description
The main goal of project is to **create a program that is able to read and returns each line from a file descriptor**

The project contains these files:
- `get_next_line.h` -> header file for program (declaring functions, include libraries, etc.)
- `get_next_line.c` -> file where the main functions are running
- `get_next_line_utils.c` -> my own created functions that were taken from different projects (primarly from project called _libft_)

# Instructions
At the beginning we need to have IDE (Integrated Development Environment), in human language it is a place where we can run and edit our program.

My preferred IDE is called **Visual Studio Code**, but you don't need to choose the same IDE. There are many options to choose.

If you got through this step, congratulations I'm proud of you that did it. Next is to copy the address of my git repository. After that open your terminal on your computer and paste the address with `git clone` in terminal.

The output on terminal should be:
```
Cloning into 'Common_core'...
remote: Enumerating objects: 229, done.
remote: Counting objects: 100% (229/229), done.
remote: Compressing objects: 100% (71/71), done.
remote: Total 229 (delta 141), reused 205 (delta 120), pack-reused 0 (from 0)
Receiving objects: 100% (229/229), 48.09 KiB | 1.30 MiB/s, done.
Resolving deltas: 100% (141/141), done.
```

> [!CAUTION]
> before that you need to install on your git, if you don't do that it will shows git not found or something like that

Is it same? Great! Let's move to another step. Before starting the program we need file descriptor and file where we can call the functions.

For file descriptor I have created file named **text.txt** which I've used for this project:
```
Tu-tu-tu-du, Max Verstappen
Tu-tu-tu-du, Max Verstappen
Tu-tu-tu-du, Max Verstappen
Tu-tu-tu-du, Max Verstappen
Vijf ronden zijn er nog te gaan
D'r is geel en een crash, daar komt die safety car
Het wereldkampioenschap is omgekeerd
Hij heeft hem
Hij heeft hem (hey)
Hey
Hey
Tu-tu-tu-du, Max Verstappen
Tu-tu-tu-du, Max Verstappen (hey)
Tu-tu-tu-du, Max Verstappen
Tu-tu-tu-du, Max Verstappen (hey)
That's our dude
Simply, simply lovely
Yes! What happened?
(Protect advantage)
Yeah, here we go again
Oh my Lord, Max! Oh my fucking-
What? (You are the World Champion!) Yes!
Oh my god!
Whoa!
Max Verstappen, you are the World Champion
The World Champion (hey)
Hey
Hey
Tu-tu-tu-du, Max Verstappen
Tu-tu-tu-du, Max Verstappen (hey)
Tu-tu-tu-du, Max Verstappen
Tu-tu-tu-du, Max Verstappen (hey)
Sporteroverwinningen zijn zo mooi
En deze is
De allermooiste die ik in m'n leven gezien heb (what's happening?)
"What is happening?" roepen ze hier
Sjonge jonge jonge
Straatfeest (hey)
```
_If you know what this is then I like you :+1:_

File **test.c** is meant for testing your main function named `get_next_line(int fd);`in file `get_next_line.c`
```
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:58:58 by kevnguye          #+#    #+#             */
/*   Updated: 2025/12/10 21:29:32 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main() {
	int	fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		sleep(2);
		free(line);
	}
	close(fd);
	return (0);
}
```
> [!NOTE]
> `sleep` is just a feature where output are not printed instantly. Just for fun.

For compiling I also created a Makefile, because I'm lazy to always write `cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c test.c`
The content of Makefile
```
NAME = getNextLine.a

SRC = get_next_line.c get_next_line_utils.c
OBJS = $(SRC:%.c=%.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I .
RM = rm -f
ARNAME = ar rcs $(NAME)
SIZE_BUFFER = 42

all: $(NAME)

$(NAME): $(OBJS)
	$(ARNAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -D BUFFER_SIZE=$(SIZE_BUFFER)  -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
```
> [!NOTE]
> If don't know what Makefile is here's the link https://makefiletutorial.com.

Do you have everything? Let's go! Now it's time to compile and run a program

## Compiling and running program
First on terminal write `make` so we can get file **getNextLine.a**. This file is a static library and contain collection of object code modules (compiled functions and data).

Then just write `cc -Wall -Wextra -Werror test.c getNextLine.a` to get the file **a.out**. That file is the output of our whole program and to execute it, just write on terminal `./a.out`. Got the output that is same as the content of the file **text.txt**? Great! You did it! You've reached the end of the whole process. Thank you for reading this README.md.