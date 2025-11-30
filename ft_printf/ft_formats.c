/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 10:55:38 by kevnguye          #+#    #+#             */
/*   Updated: 2025/11/30 11:50:36 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int	printf_length;

	printf_length = 0;
	if (format == 'c')
		printf_length += ft_printf_char(args);
	else if (format == 's')
		printf_length += ft_printf_str(args);
	else if (format == 'p')
		printf_length += ft_printf_hex(args);
	return (printf_length);
}
