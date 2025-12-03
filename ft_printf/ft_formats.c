/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 10:55:38 by kevnguye          #+#    #+#             */
/*   Updated: 2025/12/03 16:23:44 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list *args, const char format)
{
	int	printf_length;

	printf_length = 0;
	if (format == 'c')
		printf_length += ft_printf_char(va_arg(*args, int));
	else if (format == 's')
		printf_length += ft_printf_str(va_arg(*args, char *));
	else if (format == 'p')
		printf_length += ft_printf_ptr(va_arg(*args, void *));
	else if (format == 'd' || format == 'i')
		printf_length += ft_printf_dec(va_arg(*args, int));
	else if (format == 'u')
		printf_length += ft_printf_unsigned_n(va_arg(*args, unsigned int));
	else if (format == 'x' || format == 'X')
		printf_length += ft_printf_hex(va_arg(*args, unsigned long long),
				format);
	else if (format == '%')
		printf_length += ft_printf_percentage();
	return (printf_length);
}
