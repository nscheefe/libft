/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nscheefe <nscheefe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:30:59 by nscheefe          #+#    #+#             */
/*   Updated: 2023/01/04 18:55:05 by nscheefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *buffer)
{
	unsigned int	i;
	char			*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	i = ft_count_line(buffer);
	line = malloc(i + 1 + (buffer[i] == '\n'));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_temprest(char *temp)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (!temp)
		return (NULL);
	i = ft_count_line(temp);
	if (!temp[i])
		return (free(temp), NULL);
	new = (char *)malloc(ft_strlen_gnl(temp) - i + 1 + (temp[i] == '\n'));
	if (!new)
		return (NULL);
	i++;
	while (temp[i])
		new[j++] = temp[i++];
	new[j] = '\0';
	return (free (temp), new);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*temp[1024];
	int			wr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	wr = 1;
	while (!ft_strchr_gnl(temp[fd], '\n') && wr != 0)
	{
		wr = read(fd, line, BUFFER_SIZE);
		if (wr == -1)
			return (free(line), ft_bzero_gnl(temp[fd] \
			, ft_strlen_gnl(temp[fd])), NULL);
		line[wr] = '\0';
		temp[fd] = ft_strjoin_gnl(temp[fd], line);
	}
	free (line);
	line = ft_get_line(temp[fd]);
	temp[fd] = ft_temprest(temp[fd]);
	return (line);
}
