/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 09:36:46 by kevnguye          #+#    #+#             */
/*   Updated: 2025/12/02 17:11:35 by kevnguye         ###   ########.fr       */
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
	while (str[i])
	{
		if (i == 0 && !is_in_del(str[i], c))
			count++;
		else if (i > 0 && !is_in_del(str[i], c) && is_in_del(str[i - 1], c))
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

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;
	char	**result;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	count = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (result == NULL)
		return (NULL);
	while (i < count)
	{
		while (s[j] && is_in_del(s[j], c))
			j++;
		result[i] = (char *) get_word(s, c, j);
		if (!(result[i]))
			return (ft_free(result, i + 1));
		j = j + ft_strlen(result[i]);
		i++;
	}
	result[i] = NULL;
	return (result);
}
