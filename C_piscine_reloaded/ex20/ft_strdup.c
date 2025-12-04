/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:15:25 by kevnguye          #+#    #+#             */
/*   Updated: 2025/11/06 17:44:02 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src);

/*
int	main(void)
{
	char	*s1 = "s2 must be same as s1";
	char	*s2 = ft_strdup(s1);
	printf("%s", s2);
	free(s2);
	return (0);	
}
*/

char	*ft_strdup(char *src)
{
	int		i;
	char	*strs;

	i = 0;
	while (src[i])
	{
		i++;
	}
	strs = (char *)malloc(sizeof(char) * (i + 1));
	if (strs == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (src[i])
	{
		strs[i] = src[i];
		i++;
	}
	strs[i] = '\0';
	return (strs);
}
