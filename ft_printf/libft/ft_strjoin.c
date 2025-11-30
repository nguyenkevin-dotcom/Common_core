/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:59:19 by kevnguye          #+#    #+#             */
/*   Updated: 2025/11/14 12:31:45 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strings;
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;

	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	strings = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (strings == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		strings[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		strings[i++] = s2[j++];
	strings[i] = '\0';
	return (strings);
}

/*
int	main(void)
{
	char	s1[] = "Chelsea ";
	char	s2[] = "CA";
	char	*s3;

	s3 = ft_strjoin(s1, s2);
	printf("Concatenating s1: \'%s\' and s2: \'%s\'\n, s1, s2); 
	printf("with function ft_strjoin() creates: %s\n",s3);
	free(s3);
	return (0);
}
*/
