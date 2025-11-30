/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 02:46:07 by kevnguye          #+#    #+#             */
/*   Updated: 2025/11/30 11:28:27 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(2, fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
		ft_putnbr_fd(-n, fd);
	else if (n > 9)
	{
		ft_putchar_fd(n / 10, fd);
		ft_putchar_fd(n % 10, fd);
	}
	else if (n <= 9)
	{
		n = n + '0';
		ft_putchar_fd(n, fd);
	}
}
