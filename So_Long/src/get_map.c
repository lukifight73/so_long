/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:21:45 by lbenatar          #+#    #+#             */
/*   Updated: 2024/12/10 17:21:47 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	join2(char *s1, char *s2, char *conc)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	while (s1[i])
	{
		conc[i] = s1[i];
		i++;
	}
	while (s2[t])
	{
		conc[i + t] = s2[t];
		t++;
	}
	free(s1);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*conc;
	int		t;
	int		i;

	i = 0;
	t = 0;
	while (s1[i])
		i++;
	while (s2[t])
		t++;
	conc = (char *)malloc((t + i + 1) * sizeof(char));
	if (!conc)
	{
		free(s1);
		return (NULL);
	}
	conc[t + i] = '\0';
	join2(s1, s2, conc);
	return (conc);
}

char	*get_map_boucle(char *map, int fd, int verif)
{
	char	buf[2];
	int		boucle;

	buf[1] = '\0';
	boucle = 0;
	while (verif == 1)
	{
		verif = read(fd, buf, 1);
		if ((verif == 0 && boucle == 0) || verif == -1)
		{
			free(map);
			close(fd);
			return (NULL);
		}
		map = ft_strjoin2(map, buf);
		if (!map)
		{
			close(fd);
			return (NULL);
		}
		boucle = 1;
	}
	close(fd);
	return (map);
}

char	*get_map(char *mapber)
{
	int		fd;
	int		verif;
	char	*map;

	verif = 1;
	if (verif_mapber(mapber) == -1)
		return (NULL);
	fd = open(mapber, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = (char *)malloc(1 * sizeof(char));
	if (!map)
		return (NULL);
	map[0] = '\0';
	map = get_map_boucle(map, fd, verif);
	if (!map)
		return (NULL);
	return (map);
}

int	ft_charrlen(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
