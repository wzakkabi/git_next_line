/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 03:41:54 by wzakkabi          #+#    #+#             */
/*   Updated: 2022/11/14 04:01:54 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	if (!str)
		return (0);
	while (str[x] != '\0')
		x++;
	return (x);
}

char	*ft_strchr(char *s, int c)
{
	int	x;

	x = 0;
	if (!s)
		return (NULL);
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
	char	*line;
	int		x;

	x = 0;
	while (save[x] && save[x] != '\n')
		x++;
	if (save[x] == '\n')
		x++;
	line = malloc((x + 1) * sizeof(char));
	if (!line)
		return (NULL);
	x = 0;
	while (save[x] && save[x] != '\n')
	{
		line[x] = save[x];
		x++;
	}
	if (save[x] == '\n')
	{
		line[x] = save[x];
		x++;
	}
	line[x] = '\0';
	return (line);
}

char	*cutline(char *save)
{
	char	*cut;
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (save[x] && save[x] != '\n')
		x++;
	if (save[x] == '\n')
		x++;
	cut = malloc((ft_strlen(save) - x) + 1 * sizeof(char));
	if (!cut)
		return (NULL);
	while (save[x])
		cut[y++] = save[x++];
	cut[y] = '\0';
	if (save)
		free(save);
	return (cut);
}
