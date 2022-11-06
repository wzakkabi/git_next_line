/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 01:23:57 by wzakkabi          #+#    #+#             */
/*   Updated: 2022/11/06 02:15:07 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

size_t	ft_strlen(const char *s)
{
	size_t	b;

	b = 0;
	while (s[b] != '\0')
	{
		b++;
	}
	return (b);
}
char	*ft_strchr(const char *s, int c)
{
	int	x;

	x = 0;
	while (s[x])
	{
		if ((unsigned char)s[x] == (unsigned char)c)
			return ((char *)s + x);
		x++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s + x);
	return (NULL);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int x = 0;

	if (!s1 || !s2)
		return (NULL);
	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (!p)
		return (NULL);
	while(s1[x])
	{
		p[x] = s1[x];
		x++;
	}
	x = 0;
	while(s2[x])
	{
		p[x + ft_strlen(s1)] = s2[x];
		x++;
	}
	p[x + ft_strlen(s1)] = '\0';
	return (p);
}

char	*get_next_line(int fd)
{
	static char test[BUFFERSIZE];
	char *buf;
	ssize_t x;

	x = read(fd, test, BUFFERSIZE);
	buf = ft_strjoin(test, buf);
	return buf;
}

int main()
{
	int fd1 = open("./pp.txt", O_RDONLY);
	printf("%s \n %d", get_next_line(fd1), fd1);
	return 0;
}