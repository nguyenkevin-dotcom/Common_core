/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_n.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:15:51 by kevnguye          #+#    #+#             */
/*   Updated: 2025/12/03 16:31:14 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_unsigned(unsigned int n, int *count)
{
	if (n > 9)
		ft_putnbr_unsigned(n / 10, count);
	n = (n % 10) + '0';
	ft_putchar_fd(n, 1);
	(*count)++;
}

int	ft_printf_unsigned_n(unsigned int n)
{
	int				count;

	count = 0;
	ft_putnbr_unsigned(n, &count);
	return (count);
}
