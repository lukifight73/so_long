/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:36:09 by lbenatar          #+#    #+#             */
/*   Updated: 2024/12/10 17:36:10 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_elements_aux(t_data *data, int i, int j, char c)
{
	if (c == 'P')
	{
		data->entry_x = j;
		data->entry_y = i;
	}
	if (c == 'E')
	{
		data->exit_x = j;
		data->exit_y = i;
	}
	return (1);
}

int	verif_mapber(char *mapber)
{
	int	i;

	i = 0;
	while (mapber[i])
		i++;
	if (mapber[i - 1] != 'r' || mapber[i - 2] != 'e'
		|| mapber[i - 3] != 'b' || mapber[i - 4] != '.')
		return (-1);
	return (1);
}

int	verif_elements(char **map, int p, int e, t_data *data)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				p += verif_elements_aux(data, i, j, 'P');
			if (map[i][j] == 'C')
				c++;
			if (map[i][j] == 'E')
				e += verif_elements_aux(data, i, j, 'E');
			j++;
		}
		i++;
	}
	data->count_food = c;
	if (p != 1 || c < 1 || e != 1)
		return (-1);
	return (c);
}

int	verif_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != 'C' && map[i][j] != 'P'
				&& map[i][j] != 'E')
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	verif_map_format(char **map, t_data *data)
{
	int	i;
	int	count;
	int	j;

	count = ft_strlen8(map[0]);
	i = 1;
	j = 0;
	while (map[i + 1])
	{
		if (count != ft_strlen8(map[i]))
			return (-1);
		if (map[i][0] != '1' || map[i][count - 1] != '1')
			return (-1);
		i++;
	}
	while (map[0][j])
	{
		if (map[i][j] != '1' || map[0][j] != '1')
			return (-1);
		j++;
	}
	if (i < 2 || j < 2)
		return (-1);
	data->case_tot = (j - 1) * (i - 1);
	return (1);
}
