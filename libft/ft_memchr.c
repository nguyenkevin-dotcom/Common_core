/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:24:46 by kevnguye          #+#    #+#             */
/*   Updated: 2025/11/11 14:05:21 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	cc;

	i = 0;
	ptr = (unsigned char *) s;
	cc = (unsigned char) c;
	while (i < n)
	{
		if (ptr[i] == cc)
			return ((void *) &ptr[i]);
		i++;
	}
	return (NULL);
}
