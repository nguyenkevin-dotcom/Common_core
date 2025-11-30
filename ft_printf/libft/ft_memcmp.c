/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:07:59 by kevnguye          #+#    #+#             */
/*   Updated: 2025/11/11 16:50:07 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;

	i = 0;
	ptr_s1 = (unsigned char *) s1;
	ptr_s2 = (unsigned char *) s2;
	while (i < n)
	{
		if ((unsigned char) ptr_s1[i] != (unsigned char) ptr_s2[i]
			|| (unsigned char) ptr_s1[i] == '\0')
			return (ptr_s1[i] - ptr_s2[i]);
		i++;
	}
	return (0);
}
