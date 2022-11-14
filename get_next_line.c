/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 01:23:57 by wzakkabi          #+#    #+#             */
/*   Updated: 2022/11/14 04:44:07 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

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
	static char	*save;
	char		*buf;
	ssize_t		x;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd == 1 || fd == 2)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if(!buf)
		return NULL;
	while (!ft_strchr(save, '\n'))
	{
		x = read(fd, buf, BUFFER_SIZE);
		if (x <= 0)
			break ;
		buf[x] = '\0';
		save = ft_strjoin(save, buf);
	}
	free(buf);
	if (ft_strlen(save) > 0 && x >= 0)
	{
		buf = nwline(save);
		save = cutline(save);
		return (buf);
	}
	free(save);
	return (save = NULL);
}

// int main()
// {
// 		int fd;
// 	fd = open("./read_error.txt", O_RDONLY);
// 	for(int i = 0; i < 5; i++)
// 		printf("%s", get_next_line(fd));
// }
