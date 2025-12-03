/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 11:50:45 by kevnguye          #+#    #+#             */
/*   Updated: 2025/12/03 01:21:58 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int ft_put_to_hex(unsigned long long n)
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

int	ft_printf_ptr(void *ptr)
{
	int 				printf_length;
	unsigned long long	address;
	
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	address = (unsigned long long)ptr;
	printf_length = 0;
	write(1, "0x", 2);
	printf_length += 2;
	printf_length += ft_put_to_hex(address);
	return (printf_length);
}
