/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:50:12 by kevnguye          #+#    #+#             */
/*   Updated: 2025/12/03 16:29:28 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		n = n - 1;
	if (n < 0)
	{
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_printf_dec(int n)
{
	int	printf_length;

	printf_length = ft_intlen(n);
	if (n < 0)
		printf_length++;
	ft_putnbr_fd(n, 1);
	return (printf_length);
}
