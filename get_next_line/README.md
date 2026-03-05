_This project has been created as part of the 42 curriculum by kevnguye@student.42prague.com_

# Description
The main goal of project is to **create a program that is able to read and returns each line from a file descriptor**.

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
> before that you need to install on your pc git, if you don't do that, it will shows `git not found` or something like that

Is it same? Great! Let's move to another step. Before starting the program we need file descriptor and file where we can call the functions.

## File descriptor
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
_:+1: If you know what this is then you're my G :+1:_

## Testing your functions
File **test.c** is meant for testing your main function named `get_next_line(int fd);`in file **get_next_line.c**
```c
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
> `sleep` is just a feature where the output of each line isn't printed simultaneously but every 2 seconds. Just for fun.

## Compiling and running program
Do you have everything? Let's go! Now it's time to compile and run a program. Just write the command bellow.

<<<<<<< HEAD
### Optional: Through Makefile
Firstly on terminal write `make` so we can get file **getNextLine.a**. This file is a static library and contain collection of object code modules (compiled functions and data).

The output should be after writing `make`:
=======
>>>>>>> c3265509f26bccaa8b220f8871fd4a39c8376388
```
cc -Wall -Werror -Wextra -I . -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c test.c
```
> [!NOTE] BUFFER_SIZE can be whatever number you want, it will change the behavior of the program. 

<<<<<<< HEAD
Then just write `cc -Wall -Wextra -Werror test.c getNextLine.a` to get the file **a.out**. 

## Normal way
As the projects says you need for compiling to write 


The file **a.out** is the output of our whole program and to execute it, just write on terminal `./a.out`. Got the output that is same as the content of the file **text.txt**? 

Great! You've did it! You've reached the end of the whole process. 
Thank you for reading this README.md.
=======
After the command we get the file **a.out**. That file is the output of our whole program and to execute it, just write on terminal `./a.out`.
```
./a.out
```
Got the output that is same as the content of the file **text.txt**? 
Great! You did it! You've reached the end of the whole process.
>>>>>>> c3265509f26bccaa8b220f8871fd4a39c8376388

# How it really works
In _Description_ section I briefly meantioned what's the goal of the project and what's the purpose of each file. Now we will be focusing on how the program really works.

## get_next_line_utils.c
For this project I have used 4 own created functions that i have used in previous projects. Those functions will be used for creating new functions in **get_next_line.c**

It consists of:
- `void	*ft_calloc(size_t nmemb, size_t size);` => for memory allocation
- `char	*ft_strchr(const char *s, int c);` => for finding the exact character returning the rest of string
- `size_t	ft_strlen(const char *s);` => to return the length of string
- `char	*ft_strjoin(char const *s1, char const *s2);` => to join two separate strings
```c
#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tmp;
	size_t	total_size;
	size_t	i;

	i = 0;
	total_size = nmemb * size;
	if (total_size != 0 && total_size / size != nmemb)
		return (NULL);
	tmp = malloc(total_size);
	if (tmp == NULL)
		return (NULL);
	while (i < total_size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	cc;

	i = 0;
	cc = (char) c;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strings;
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;

	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	strings = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (strings == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		strings[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		strings[i++] = s2[j++];
	strings[i] = '\0';
	return (strings);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
```

## get_next_line.c
```c
#include "get_next_line.h"

char	*ft_free(char *res, char *buffer)
{
	char	*joined_string;

	joined_string = ft_strjoin(res, buffer);
	free(res);
	return (joined_string);
}

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*ft_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_line(int fd, char *res)
{
	char	*buffer;
	int		bytes_read;

	if (!res)
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		res = ft_free(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*temp_space;
	char		*output;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	temp_space = read_line(fd, temp_space);
	if (!temp_space)
		return (NULL);
	output = ft_line(temp_space);
	temp_space = ft_next(temp_space);
	return (output);
}
```
The file consints of 5 functions:
- `get_next_line()` - the function that will get next line of file 
- `read_line()` - will read line of the file and will save in variable called `static char	*temp_space` and the length of it will be based on `BUFFER_SIZE`
- `ft_line()` - move the content of `static char	*temp_space` until it will meet the character `\n`
- `ft_next()` - move to the next line after it found `\n`
- `ft_free()` - join the string the old buffer and the new buffer together and freeing the old buffer

# Resources
Here's the list where of resources from which I was able to create this project:
- https://www.youtube.com/watch?v=-Mt2FdJjVno&list=PLPqnnyLDYcuGXkdP_yK63cA-GSwdgb7vm&index=6
- https://quickref.me/c
- https://github.com/Tripouille/gnlTester
- https://www.codequoi.com/en/local-global-static-variables-in-c/

## Use of AI
AI was used mainly used for understanding how function `read` and `open` works. It was also used for troubleshooting.