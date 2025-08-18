/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:30:22 by lbenatar          #+#    #+#             */
/*   Updated: 2024/12/10 17:30:24 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_to_exit_exe_x(int **map, t_data *data, t_cord *c, int i)
{
	c->x += i;
	map[c->y][c->x] = data->remp;
}

void	get_to_exit_exe_y(int **map, t_data *data, t_cord *c, int i)
{
	c->y += i;
	map[c->y][c->x] = data->remp;
}

int	get_to_exit(int **map, t_data *data, t_cord *c)
{
	while (!(c->x == data->exit_x && c->y == data->exit_y))
	{
		if (is_exit_around(map, c) == 1)
			return (1);
		if (map[c->y][c->x - 1] == 10 || map[c->y][c->x - 1] == -7
				|| map[c->y][c->x - 1] == -5)
			get_to_exit_exe_x(map, data, c, -1);
		else if (map[c->y + 1][c->x] == 10 || map[c->y + 1][c->x] == -7
				|| map[c->y + 1][c->x] == -5)
			get_to_exit_exe_y(map, data, c, 1);
		else if (map[c->y][c->x + 1] == 10 || map[c->y][c->x + 1] == -7
				|| map[c->y][c->x + 1] == -5)
			get_to_exit_exe_x(map, data, c, 1);
		else if (map[c->y - 1][c->x] == 10 || map[c->y - 1][c->x] == -7
				|| map[c->y - 1][c->x] == -5)
			get_to_exit_exe_y(map, data, c, -1);
		else
		{
			if (reverse_walking(map, data, c) == -1)
				return (-1);
		}
		data->remp++;
	}
	return (1);
}

int	is_exit_around(int **map, t_cord *c)
{
	if (map[c->y][c->x - 1] == -5 || map[c->y - 1][c->x] == -5
		|| map[c->y][c->x + 1] == -5 || map[c->y + 1][c->x] == -5)
		return (1);
	return (-1);
}
