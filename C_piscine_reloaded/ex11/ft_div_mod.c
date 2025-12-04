/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:36:34 by kevnguye          #+#    #+#             */
/*   Updated: 2025/11/06 15:44:22 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	int	res;
	int	rem;

	res = a / b;
	rem = a % b;
	*div = res;
	*mod = rem;
}
/*
int	main(void)
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	*res;
	int	*rem;

	a = 9;
	b = 2;
	c = 0;
	d = 0;
	res = &c;
	rem = &d;
	ft_div_mod(a, b, res, rem);
	printf("%d | %d", c, d);
	return (0);
}
*/
