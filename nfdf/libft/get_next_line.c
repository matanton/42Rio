/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:32:09 by matanton          #+#    #+#             */
/*   Updated: 2023/01/26 15:19:09 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_read_line(int fd, char *save);
static char	*ft_get_line(char *save);
static char	*ft_save_rest(char *save);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[4096];

	if (read(fd, 0, 0) || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = ft_read_line(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = ft_get_line(save[fd]);
	save[fd] = ft_save_rest(save[fd]);
	return (line);
}

static char	*ft_read_line(int fd, char *save)
{
	int		size;
	char	*buf;

	buf = malloc((BUFFER_SIZE + 1 * sizeof(char *)));
	if (!buf)
		return (NULL);
	size = 1;
	while (size != 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
			return (NULL);
		buf[size] = '\0';
		if (save == NULL)
		{
			save = malloc(1);
			save[0] = '\0';
		}
		save = ft_strjoin(save, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free (buf);
	return (save);
}

static char	*ft_get_line(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char *));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_save_rest(char *save)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free (save);
		return (NULL);
	}
	rest = malloc(((ft_strlen(save) - i) + 1) * sizeof(char *));
	if (!rest)
		return (NULL);
	if (save[i] == '\n')
		i++;
	j = 0;
	while (save[i])
		rest[j++] = save[i++];
	rest[j] = '\0';
	free (save);
	return (rest);
}
