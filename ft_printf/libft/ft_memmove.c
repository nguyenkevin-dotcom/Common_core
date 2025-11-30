/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:39:03 by kevnguye          #+#    #+#             */
/*   Updated: 2025/11/10 16:11:36 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_src;
	unsigned char	*ptr_dest;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	ptr_src = (unsigned char *) src;
	ptr_dest = (unsigned char *) dest;
	i = 0;
	if (ptr_dest > ptr_src)
	{
		while (n-- > 0)
		{
			ptr_dest[n] = ptr_src[n];
		}
	}
	else
	{
		while (i++ < n)
		{
			ptr_dest[i] = ptr_src[i];
		}
	}
	return (dest);
}
