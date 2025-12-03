/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:07:44 by kevnguye          #+#    #+#             */
/*   Updated: 2025/12/03 16:33:46 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_to_hex(unsigned int n, const char format)
{
	char	*base;
	int		len;

	base = "0123456789abcdef";
	if (format == 'X')
		base = "0123456789ABCDEF";
	len = 0;
	if (n >= 16)
		len += ft_put_to_hex(n / 16, format);
	write(1, &base[n % 16], 1);
	len++;
	return (len);
}

int	ft_printf_hex(unsigned long long n, const char format)
{
	int	printf_length;

	printf_length = 0;
	printf_length += ft_put_to_hex(n, format);
	return (printf_length);
}
