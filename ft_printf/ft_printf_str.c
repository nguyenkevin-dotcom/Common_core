/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 11:40:37 by kevnguye          #+#    #+#             */
/*   Updated: 2025/12/03 16:32:37 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(char *str)
{
	int		printf_length;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	printf_length = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (printf_length);
}
