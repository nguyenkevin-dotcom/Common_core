/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 10:58:43 by kevnguye          #+#    #+#             */
/*   Updated: 2025/11/30 11:43:18 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_char(va_list args)
{
	char	c;
	
	c = va_arg(args, int);
	ft_putchar_fd(c, 1);
	return (1);
}
