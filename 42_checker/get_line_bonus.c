/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:32:14 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/18 00:10:55 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*before_nl(char *buf)
{
	int		i;
	int		j;
	char	*new_buf;

	i = 0;
	if (!buf || !buf[0])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	new_buf = malloc(i + 1);
	if (!new_buf)
		return (NULL);
	i = 0;
	j = 0;
	while (buf[j] && buf[j] != '\n')
		new_buf[j++] = buf[i++];
	if (buf[j] == '\n')
		new_buf[j++] = '\n';
	new_buf[j] = '\0';
	return (new_buf);
}

char	*after_nl(char *buf)
{
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	j = 0;
	if (!buf)
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	buffer = malloc(ft_strlen(buf) - i + 1);
	if (!buffer)
		return (NULL);
	while (buf[i])
		buffer[j++] = buf[i++];
	buffer[j] = '\0';
	return (buffer);
}

char	*ex_line(char **save)
{
	char	*line;
	char	*new_saved;
	char	*tmp;

	if (!*save)
		return (NULL);
	if ((*save)[0] == '\0')
		return (flush_leftover(save));
	tmp = *save;
	line = before_nl(tmp);
	if (!line)
		return (NULL);
	new_saved = after_nl(tmp);
	if (!new_saved)
	{
		free(line);
		return (NULL);
	}
	*save = new_saved;
	free(tmp);
	return (line);
}

char	*read_join(char *buffer, char *save, int fd)
{
	int		n;
	char	*tmp;

	n = 1;
	while (!(nl_found(save)) && n > 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n < 0)
		{
			free(save);
			save = NULL;
			return (NULL);
		}
		buffer[n] = '\0';
		tmp = save;
		save = ft_strjoin(save, buffer);
		if (!save)
		{
			free(tmp);
			return (NULL);
		}
		free(tmp);
	}
	return (save);
}

char	*get_line(int fd)
{
	char		*buffer;
	static char	*save;
	char		*line;

	if (fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	save = read_join(buffer, save, fd);
	if (!save || !save[0])
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	line = ex_line(&save);
	if (!line)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	free(buffer);
	return (line);
}
