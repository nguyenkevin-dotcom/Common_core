/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:44:36 by kevnguye          #+#    #+#             */
/*   Updated: 2025/11/06 15:25:31 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_print_numbers(void);

/*
int	main(void)
{
	ft_print_numbers();
	return (0);
}
*/

/*
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
*/

void	ft_print_numbers(void)
{
	int	a;

	a = '0';
	while (a <= '9')
	{
		ft_putchar(a);
		a++;
	}
}
