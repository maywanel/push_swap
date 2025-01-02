/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mes <moel-mes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 06:10:47 by moel-mes          #+#    #+#             */
/*   Updated: 2024/11/21 14:14:07 by moel-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*memory(char **line, int n)
{
	char	*tmp;
	int		l;

	l = ft_strlen(*line);
	tmp = ft_substr(*line, n, l + 1);
	free(*line);
	*line = NULL;
	return (tmp);
}

char	*the_line(char **line, int n)
{
	char	*tmp;

	tmp = ft_substr(*line, 0, n + 1);
	*line = memory(line, n + 1);
	return (tmp);
}

char	*read_line(int fd, char **line, char *buf)
{
	int		r;
	int		n;
	char	*last_line;

	r = read(fd, buf, BUFFER_SIZE);
	while (r > 0)
	{
		buf[r] = '\0';
		*line = ft_strjoin(*line, buf);
		if (!(*line))
			return (NULL);
		n = check_line(*line);
		if (n != -1)
			return (the_line(&(*line), n));
		r = read(fd, buf, BUFFER_SIZE);
	}
	if (*line && *line[0] != '\0' && r >= 0)
	{
		last_line = ft_strdup(*line);
		free(*line);
		*line = NULL;
		return (last_line);
	}
	free(*line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buf;
	int			n;
	char		*l;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!line)
		line = ft_strdup("");
	if (!line)
		return (NULL);
	n = check_line(line);
	if (n != -1)
		return (the_line(&line, n));
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
	{
		free(line);
		return (NULL);
	}
	l = read_line(fd, &line, buf);
	if (!l)
		line = NULL;
	free(buf);
	return (l);
}
