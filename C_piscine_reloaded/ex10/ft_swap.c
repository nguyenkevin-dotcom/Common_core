/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:28:49 by kevnguye          #+#    #+#             */
/*   Updated: 2025/11/06 15:44:24 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*
int	main(void)
{
	int	c;
	int	d;
	//int	*e;
	//int	*f;
	
	c = 1;
	d = 2;
	//e = &c;
	//f = &d;
	//ft_swap(e, f);
	printf("%d | %d", c, d);
	return (0);
}
*/
