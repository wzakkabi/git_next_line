/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 06:06:29 by wzakkabi          #+#    #+#             */
/*   Updated: 2022/11/15 23:52:13 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*save[10240];
	char		*buf;
	ssize_t		x;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd == 1 || fd == 2)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!ft_strchr(save[fd], '\n'))
	{
		x = read(fd, buf, BUFFER_SIZE);
		if (x <= 0)
			break ;
		save[fd] = ft_strjoin(save[fd], buf, x);
	}
	free(buf);
	if (ft_strlen(save[fd]) > 0 && x >= 0)
	{
		buf = nwline(save[fd]);
		save[fd] = cutline(save[fd]);
		return (buf);
	}
	free(save[fd]);
	return (save[fd] = NULL);
}
