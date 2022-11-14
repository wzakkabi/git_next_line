/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 01:23:57 by wzakkabi          #+#    #+#             */
/*   Updated: 2022/11/14 02:29:30 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	if(!str)
		return 0;
	while (str[x] != '\0')
		x++;
	return (x);
}
char	*ft_strchr(char *s, int c)
{
	int	x;

	x = 0;
	if(!s)
		return NULL;
	while (s[x] != '\0')
	{
		if (s[x] == c)
			return (s + x);
		x++;
	}
	return (NULL);
}

char	*nwline(char *save)
{
	char *line;
	int x = 0;
	while(save[x] && save[x] != '\n')
		x++;
	if(save[x] == '\n')
		x++;
	line = malloc((x + 1)  * sizeof(char));
	if(!line)
		return NULL;
	x = 0;
	while(save[x] && save[x] != '\n')
	{
		line[x] = save[x];
		x++;
	}
	if(save[x] == '\n')
	{
		line[x] = save[x];
		x++; 
	}
	line[x] = '\0';
	return line;
}

char	*cutline(char *save)
{
	char *cut;
	int x = 0;
	int y = 0;
	while(save[x] && save[x] != '\n')
		x++;
	if(save[x] == '\n')
		x++;
	cut = malloc((ft_strlen(save) - x) + 1 * sizeof(char));
	if(!cut)
		return NULL;
	while(save[x])
		cut[y++] = save[x++];
	cut[y] = '\0';
	if(save)
		free(save);
	return cut;
}

char	*ft_strjoin(char *save, char *buf)
{
	char *p;
	int x = 0;
	int y = 0;
	p = malloc((ft_strlen(save) + ft_strlen(buf) + 1) * sizeof(char));
	if(!p)
		return NULL;
	if(save)
	{
		while(save[x])
		{
		p[x] = save[x];
		x++;
		}
	}
	while(buf[y])
		p[x++]= buf[y++];
	p[x] = '\0';
	if(save)
		free(save);
	return p;
}

char	*get_next_line(int fd)
{
	static char *save;
	char *buf;
	char *line;
	int x = 1;
	if(fd < 0 || BUFFER_SIZE <= 0 || fd == 1 || fd == 2 )
		return NULL;
	buf = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if(!buf)
		return NULL;
	while(!ft_strchr(save, '\n') && x != 0)
	{
		x = read(fd, buf, BUFFER_SIZE);
		buf[x] = '\0';
		if(x < 0)
		{
			free(buf);
			return 0;
		}
		save = ft_strjoin(save, buf);
	}
	free(buf);
	if(ft_strlen(save) > 0)
	{
	line = nwline(save);
	save = cutline(save);
	return line;
	}
	if(save)
		free(save);
	save = NULL;
	return NULL;
}

// int main()
// {
// 		int fd;
// 	fd = open("./read_error.txt", O_RDONLY);
// 	for(int i = 0; i < 5; i++)
// 		printf("%s", get_next_line(fd));
// }
