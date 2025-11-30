/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:51:08 by kevnguye          #+#    #+#             */
/*   Updated: 2025/11/11 17:44:29 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	int		sum;

	i = 0;
	sign = 1;
	sum = 0;
	while (nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
	{
		if (nptr[i + 1] == '-')
			return (0);
		sign = sign * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		sum = sum * 10 + (nptr[i] - '0');
		i++;
	}
	return (sum * sign);
}
