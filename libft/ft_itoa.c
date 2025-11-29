/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:14:45 by kevnguye          #+#    #+#             */
/*   Updated: 2025/11/14 14:57:09 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_intlen(int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;

	len = ft_intlen(n);
	if (n < 0)
	{
		n = -n;
		len = len + 1;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		len--;
		str[len] = (n % 10) + '0';
		n = n / 10;
	}
	if ((str[len] == '0') && (str[len + 1] >= '1' && str[len + 1] <= '9'))
		str[len] = '-';
	return (str);
}

/*
int	main(void)
{
	size_t	n = -121564;
	char	*inttostr;

	inttostr = ft_itoa(n);
	printf("The int n = %ld, with function ft_itoa turns into string: \'%s\'", n, inttostr);
	free(inttostr);
	return (0);
}
*/
