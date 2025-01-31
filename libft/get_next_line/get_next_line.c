/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:44:16 by rojornod          #+#    #+#             */
/*   Updated: 2024/12/16 11:29:26 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = extract_line(buffer);
	if (!line)
		return (NULL);
	line = read_and_join(fd, buffer, line);
	if (!line)
		return (NULL);
	if (line[0] == '\0')
		return (free(line), NULL);
	manage_buffer(buffer);
	return (line);
}

char	*extract_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	line = malloc((get_length(buffer) + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_and_join(int fd, char *buffer, char *line)
{
	int		bytes_read;
	char	*prev_line;

	bytes_read = 1;
	prev_line = line;
	if (!prev_line)
		prev_line = ft_strdup("");
	if (ft_strchr(line, '\n') != NULL)
		return (line);
	while (ft_strchr(buffer, '\n') == NULL && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			buffer[0] = '\0';
			return (free(prev_line), NULL);
		}
		buffer[bytes_read] = '\0';
		line = combine_strings(prev_line, buffer);
		if (!line)
			return (free(prev_line), NULL);
		free(prev_line);
		prev_line = line;
	}
	return (line);
}

void	manage_buffer(char *buffer)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strchr(buffer, '\n');
	if (!tmp)
		return ;
	tmp++;
	while (tmp[i] != '\0')
	{
		buffer[i] = tmp[i];
		i++;
	}
	buffer[i] = '\0';
}
