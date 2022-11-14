/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 06:06:29 by wzakkabi          #+#    #+#             */
/*   Updated: 2022/11/14 06:24:51 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *save, char *buf)
{
	char	*p;
	int		x;
	int		y;

	x = 0;
	y = 0;
	p = malloc((ft_strlen(save) + ft_strlen(buf) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	if (save)
	{
		while (save[x])
		{
		p[x] = save[x];
		x++;
		}
	}
	while (buf[y])
		p[x++] = buf[y++];
	p[x] = '\0';
	if (save)
		free(save);
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*save[4096];
	char		buf[BUFFER_SIZE + 1];
	ssize_t		x;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd == 1 || fd == 2)
		return (NULL);
	while (!ft_strchr(save[fd], '\n'))
	{
		x = read(fd, buf, BUFFER_SIZE);
		if (x <= 0)
			break ;
		buf[x] = '\0';
		save[fd] = ft_strjoin(save[fd], buf);
	}
	if (ft_strlen(save[fd]) > 0 && x >= 0)
	{
		line = nwline(save[fd]);
		save[fd] = cutline(save[fd]);
		return (line);
	}
	free(save[fd]);
	return (save[fd] = NULL);
}
