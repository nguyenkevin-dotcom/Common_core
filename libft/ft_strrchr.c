/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:18:36 by kevnguye          #+#    #+#             */
/*   Updated: 2025/11/11 14:05:43 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;
	char	cc;

	s_len = ft_strlen(s);
	cc = (char) c;
	while (s_len > 0)
	{
		if (s[s_len] == cc)
			return ((char *) &s[s_len]);
		s_len--;
	}
	if (s[s_len] == cc)
		return ((char *) &s[s_len]);
	return (NULL);
}
