/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:49:28 by kevnguye          #+#    #+#             */
/*   Updated: 2025/11/06 15:26:15 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_is_negative(int n);

/*
int	main(void)
{
	ft_is_negative(42);
	ft_is_negative(0);
	ft_is_negative(-42);
	return (0);
}
*/

/*
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
*/

void	ft_is_negative(int n)
{
	char	a;
	char	b;

	a = 'P';
	b = 'N';
	if (n >= 0)
	{
		ft_putchar(a);
	}
	else
	{
		ft_putchar(b);
	}
}
