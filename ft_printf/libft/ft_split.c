/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 09:36:46 by kevnguye          #+#    #+#             */
/*   Updated: 2025/11/30 21:59:14 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_del(char current_index, char c)
{
	if (current_index == c)
		return (1);
	return (0);
}

static int	count_words(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 1;
	if ((str[i] >= 0 && str[i] <= 31) || (str[i] == c))
		return (0);
	while (str[i])
	{
		if (is_in_del(str[i], c) && str[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static char	*get_word(const char *str, char c, size_t position)
{
	size_t	start;
	size_t	end;
	char	*word;

	start = position;
	end = start;
	while (str[end] && is_in_del(str[end], c) != 1)
		end++;
	word = ft_substr(str, start, end - start);
	return (word);
}

static void	*ft_free(char **result, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}
*/

/*
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
*/

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;
	char	**result;

	i = 0;
	j = 0;
	count = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (result == NULL)
		return (NULL);
	while (i < count)
	{
		result[i] = (char *) get_word(s, c, j);
		if (!(result[i]))
			return (ft_free(result, i + 1));
		j = j + ft_strlen(result[i]) + 1;
		i++;
	}
	result[i] = NULL;
	return (result);
}

/*
int	main(void)
{
	char	string[] = "hello fuck you";
	char	c = ' ';
	int		i;
	int		count;
	char	**splitted;

	i = 0;
	count = count_words(string, c);
	splitted = ft_split(string, c);
	while (i < count)
	{
		printf("word on splitted[%d]: %s\n", i, splitted[i]);
		i++;
	}
	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return (0);
}
*/
