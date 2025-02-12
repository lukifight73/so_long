/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:33:54 by lbenatar          #+#    #+#             */
/*   Updated: 2024/12/10 17:33:55 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	c_la_muerda_autour(int **map, t_cord *c)
{
	int	i;

	i = 0;
	if (map[c->y][c->x - 1] == -1 || map[c->y][c->x - 1] == 11
		|| map[c->y][c->x - 1] == -5)
		i++;
	if (map[c->y - 1][c->x] == -1 || map[c->y - 1][c->x] == 11
		|| map[c->y - 1][c->x] == -5)
		i++;
	if (map[c->y][c->x + 1] == -5 || map[c->y][c->x + 1] == -1
		|| map[c->y][c->x + 1] == 11)
		i++;
	if (map[c->y + 1][c->x] == -5 || map[c->y + 1][c->x] == -1
		|| map[c->y + 1][c->x] == 11)
		i++;
	if (i == 4)
		return (-1);
	return (1);
}

int	reverse_walking(int **map, t_data *data, t_cord *c)
{
	int	tot;

	tot = 0;
	map[c->y][c->x] = -1;
	while (check_way(map, c) == -1)
	{
		reverse_walking_exe(map, data, c);
		data->remp--;
		tot++;
		if (tot > data->case_tot || c_la_muerda_autour(map, c) == -1)
			return (-1);
	}
	data->remp++;
	map[c->y][c->x] = data->remp;
	return (1);
}

int	check_way(int **map, t_cord *c)
{
	if (map[c->y][c->x - 1] == 10 || map[c->y - 1][c->x] == 10
		|| map[c->y][c->x + 1] == 10 || map[c->y + 1][c->x] == 10)
		return (1);
	if (map[c->y][c->x - 1] == -7 || map[c->y - 1][c->x] == -7
		|| map[c->y][c->x + 1] == -7 || map[c->y + 1][c->x] == -7)
		return (1);
	return (-1);
}

void	reverse_walking_exe(int **map, t_data *data, t_cord *c)
{
	if (map[c->y - 1][c->x] == data->remp)
	{
		c->y--;
		map[c->y][c->x] = -1;
	}
	else if (map[c->y][c->x + 1] == data->remp)
	{
		c->x++;
		map[c->y][c->x] = -1;
	}
	else if (map[c->y + 1][c->x] == data->remp)
	{
		c->y++;
		map[c->y][c->x] = -1;
	}
	else if (map[c->y][c->x - 1] == data->remp)
	{
		c->x--;
		map[c->y][c->x] = -1;
	}
}
