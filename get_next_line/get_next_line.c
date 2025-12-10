/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:47:57 by kevnguye          #+#    #+#             */
/*   Updated: 2025/12/10 22:33:48 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *temp_space, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(temp_space, buffer);
	free(temp_space);
	return (temp);
}

char	*ft_next(char *temp_space)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (temp_space[i] && temp_space[i] != '\n')
		i++;
	if (!temp_space[i])
	{
		free(temp_space);
		return (NULL);
	}
	line = ft_calloc(ft_strlen(temp_space) - i + 1, sizeof(char));
	i++;
	j = 0;
	while (temp_space[i])
		line[j++] = temp_space[i++];
	free(temp_space);
	return (line);
}

char	*ft_line(char *temp_space)
{
	char	*line;
	int		i;

	i = 0;
	if (!temp_space[i])
		return (NULL);
	while (temp_space[i] && temp_space[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (temp_space[i] && temp_space[i] != '\n')
	{
		line[i] = temp_space[i];
		i++;
	}
	if (temp_space[i] && temp_space[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_line(int fd, char *temp_space)
{
	char	*buffer;
	int		bytes;

	if (!temp_space)
		temp_space = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = 0;
		temp_space = ft_free(temp_space, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (temp_space);
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
