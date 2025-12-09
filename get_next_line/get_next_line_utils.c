/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 19:43:26 by kevnguye          #+#    #+#             */
/*   Updated: 2025/12/09 21:29:31 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tmp;
	size_t	total_size;
	size_t	i;

	i = 0;
	total_size = nmemb * size;
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
