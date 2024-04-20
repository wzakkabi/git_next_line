/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 01:23:57 by wzakkabi          #+#    #+#             */
/*   Updated: 2024/04/20 19:24:07 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buf;
	ssize_t		x;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd == 1 || fd == 2)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!ft_strchr(save, '\n'))
	{
		x = read(fd, buf, BUFFER_SIZE);
		if (x <= 0)
			break ;
		buf[x] = 0;
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
