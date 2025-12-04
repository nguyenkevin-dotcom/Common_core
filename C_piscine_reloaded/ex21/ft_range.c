/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:38:47 by kevnguye          #+#    #+#             */
/*   Updated: 2025/11/06 18:02:17 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max);

/*
int	main(void)
{
	int	i = 0;
	int	min = 0;
	int	max = 10;
	int	*ints = ft_range(min, max);
	while (i < max)
	{
		printf("%d", ints[i]);
		i++;
	}
	free(ints);
	return (0);
}
*/

int	*ft_range(int min, int max)
{
	int	i;
	int	*ints;

	i = 0;
	ints = (int *)malloc(sizeof(int) * (max - min));
	if (max - min <= 0)
	{
		ints = NULL;
	}
	if (ints == NULL)
	{
		return (NULL);
	}
	while (min < max)
	{
		ints[i] = min;
		min++;
		i++;
	}
	return (ints);
}
