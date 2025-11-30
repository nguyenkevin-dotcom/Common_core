/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 11:50:45 by kevnguye          #+#    #+#             */
/*   Updated: 2025/11/30 12:25:49 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static	int ft_put_to_hex(unsigned long n)
{
	char	*base;
	int		len;
	
	base = "012345689abcdef";
	len = 0;
	if (n >= 16)
		len += ft_put_to_hex(n / 16);
	write(1, &base[n % 16], 1);
	len++;
	return (len);
	
}

int	ft_printf_hex(void *ptr)
{
	unsigned long	address;
	int 	printf_length;
	
	address = (unsigned long)ptr;
	printf_length = 0;
	// n = va_arg(args, int);
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	printf_length += 2;
	printf_length += ft_put_to_hex(address);
	return (printf_length);
}

int	main(void)
{
	int dec = 42;
	char	*str = "Hello";

	ft_printf_hex(&dec);
	printf("\n");
	printf("%p\n", &dec);
	printf("\n");
	ft_printf_hex(str);
	printf("\n");
	printf("%p\n", str);
	return (0);
}