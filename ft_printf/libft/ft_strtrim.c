/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:36:01 by kevnguye          #+#    #+#             */
/*   Updated: 2025/11/13 17:32:47 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	same_as_set(char c, char *s_set)
{
	size_t	i;

	i = 0;
	while (s_set[i])
	{
		if (s_set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	shalf1_len;
	size_t	shalf2_len;
	char	*s_set;

	s_set = (char *) set;
	shalf1_len = 0;
	shalf2_len = ft_strlen(s1);
	while (s1[shalf1_len] && same_as_set(s1[shalf1_len], s_set))
		shalf1_len++;
	while ((shalf2_len > shalf1_len) && same_as_set(s1[shalf2_len - 1], s_set))
		shalf2_len = shalf2_len - 1;
	return (ft_substr(s1, shalf1_len, shalf2_len - shalf1_len));
}
