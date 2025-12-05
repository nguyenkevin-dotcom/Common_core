/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:47:57 by kevnguye          #+#    #+#             */
/*   Updated: 2025/12/04 20:02:13 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *temp_space)
{
	
}

char	*get_next_line(int fd)
{
	static char	*temp_space;
	char		*output;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	temp_space = read_line(fd, temp_space);
	if (!temp_space)
		return (NULL);
	output = ft_line(temp_space);
	temp_space = ft_next(temp_space);
	return (output);
}