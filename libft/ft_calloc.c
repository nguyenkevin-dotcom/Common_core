/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:32:09 by kevnguye          #+#    #+#             */
/*   Updated: 2025/11/12 16:56:20 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
