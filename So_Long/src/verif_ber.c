/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:58:03 by lbenatar          #+#    #+#             */
/*   Updated: 2024/12/09 11:00:39 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen8(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	fill_map2(char **map, int **map2)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		map2[i] = (int *)malloc((ft_strlen8(map[i])) * sizeof(int));
		if (!map2[i])
			return (-1);
		while (map[i][j])
		{
			if (map[i][j] == '1' || map[i][j] == '0')
				map2[i][j] = map[i][j] - '0' + 10;
			if (map[i][j] == 'C')
				map2[i][j] = -7;
			if (map[i][j] == 'E')
				map2[i][j] = -5;
			if (map[i][j] == 'P')
				map2[i][j] = -3;
			j++;
		}
		i++;
	}
	return (1);
}

int	**copy_map(char **map, t_data *data)
{
	int	i;
	int	j;
	int	**map2;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	map2 = (int **)malloc((i) * sizeof(int *));
	if (!map2)
		return (NULL);
	if (fill_map2(map, map2) == -1)
	{
		liberator_map_int(map2, data);
		return (NULL);
	}
	return (map2);
}

int	verif_ber2(t_data *data, int **map2, char **map)
{
	if (verif_elements(map, 0, 0, data) == -1
		|| verif_map(map) == -1 || verif_map_format(map, data) == -1)
	{
		if (map2)
			liberator_map_int(map2, data);
		ft_printf("Error\nLa map fournie n'est pas valide!\n");
		free(data);
		return (-1);
	}
	if (verif_chemin(map2, data, map) == -1)
	{
		ft_printf("Error\nOn ne peut pas réussir avec cette map !\n");
		free(data);
		return (-1);
	}
	if (ft_init_data(data, map) == -1)
	{
		ft_printf("Error\nLes images fournies ne correspondent pas\n");
		return (-1);
	}
	return (1);
}

t_data	*verif_ber(char **map, int width, int height)
{
	t_data	*data;
	int		**map2;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->width = width / 32;
	data->height = height / 32;
	map2 = copy_map(map, data);
	if (!map2)
	{
		ft_printf("Error\nMalloc error.\n");
		free(data);
		return (NULL);
	}
	if (verif_ber2(data, map2, map) == -1)
		return (NULL);
	return (data);
}
