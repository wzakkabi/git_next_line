/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 01:23:57 by wzakkabi          #+#    #+#             */
/*   Updated: 2022/11/10 00:12:44 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

size_t ft_strlen(char *p)
{
	size_t x;
	
	x = 0;
	while (p[x] != '\0')
		x++;
	return (x);
}
char	*ft_strchr(char *s, int c)
{
	int	x;

	x = 0;
	while (s[x] != '\0')
	{
		if (s[x] == c)
			return (s + x);
		x++;
	}
	return (NULL);
}
char *cutline(char *p)
{
	char *pp;
	int y = 0, x = 0;
	while (p[x] && p[x] != '\n' )
		x++;
	x++;
	y = x;
	while(p[x] != '\0')
		x++;
	pp = malloc(((x - y) + 1) * sizeof(char));
	x = 0;
	while(p[y] != '\0')
		pp[x++] = p[y++];
	free(p);
	return pp;
}

char	*ft_strjoin(char  *s1, char  *s2)
{
	char	*p;
	int x = 0, y = 0;
	p = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while(s1[x] != '\0')
	{
		p[x] = s1[x];
		x++;
	}
	while(s2[y] != '\0')
		p[x++] = s2[y++];
	p[x] = '\0';
	//free(s2);
	return (p);
}
char *nwline(char *p)
{
	char *str;
	int x = 0;
	
	while(p[x] != '\n' && p[x] != '\0')
		x++;
	str = malloc((x + 2) * sizeof(char ));
	x = 0;
	while (p[x] != '\0' && p[x] != '\n')
	{
		str[x] = p[x];
		x++;
	}
	str[x] = '\n';
	x++;
	str[x] = '\0';
	return str;	
}

char	*get_next_line(int fd)
{
	char buf[BUFFER_SIZE + 1] = "";
	static char *save = "";
	char *p;
	int x  = 1;
	while(x > 0 && !ft_strchr(save, '\n'))
	{
		x = read(fd, buf, BUFFER_SIZE);
		save = ft_strjoin(buf, save);
	}
	p = nwline(save);
	save = cutline(save);
	return p;
}

int main()
{
	int fd = open("./pp.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

}