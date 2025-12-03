/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:21:02 by kevnguye          #+#    #+#             */
/*   Updated: 2025/12/03 00:33:43 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		printf_length;
	va_list	args;

	i = 0;
	printf_length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			printf_length += ft_formats(&args, format[i]);
		}
		else
			printf_length += ft_printf_char(format[i]);
		i++;
	}
	va_end(args);
	return (printf_length);
}
