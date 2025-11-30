/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 02:23:21 by kevnguye          #+#    #+#             */
/*   Updated: 2025/11/30 02:51:56 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*strs;

	len = ft_strlen(s);
	i = 0;
	strs = malloc(sizeof(char) * (len + 1));
	if (strs == NULL)
		return (NULL);
	while (i < len)
	{
		strs[i] = f(i, s[i]);
		i++;
	}
	strs[i] = '\0';
	return (strs);
}
