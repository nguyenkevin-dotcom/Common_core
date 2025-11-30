/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 11:50:45 by kevnguye          #+#    #+#             */
/*   Updated: 2025/11/30 21:58:24 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int ft_put_to_hex(unsigned long n)
{
	char	*base;
	int		len;
	
	base = "0123456789abcdef";
	len = 0;
	if (n >= 16)
		len += ft_put_to_hex(n / 16);
	write(1, &base[n % 16], 1);
	len++;
	return (len);
	
}

int	ft_printf_hex(va_list args)
{
	unsigned long	address;
	int 	printf_length;
	
	address = va_arg(args, unsigned long long);
	if (!address)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	printf_length = 0;
	write(1, "0x", 2);
	printf_length += 2;
	printf_length += ft_put_to_hex(address);
	return (printf_length);
}
