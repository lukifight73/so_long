/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_collectibles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:30:14 by lbenatar          #+#    #+#             */
/*   Updated: 2024/12/10 17:30:15 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_chemin(int **map2, t_data *data, char **map)
{
	t_cord	*c;
	int		**map3;

	c = (t_cord *)malloc(sizeof(t_cord));
	if (!c)
		return (-1);
	init_c(c, data, map2);
	map3 = copy_map(map, data);
	if (!map3)
	{
		liberator_map_int(map2, data);
		free(c);
		return (-1);
	}
	if (get_all_collectible(map2, data, c, map3) == -1
		|| get_to_exit(map3, data, c) == -1)
	{
		mini_liberator(map2, map3, data, c);
		return (-1);
	}
	mini_liberator(map2, map3, data, c);
	return (1);
}

int	get_all_collectible(int **map, t_data *data, t_cord *c, int **map3)
{
	int	count;

	count = 0;
	while (count != data->count_food)
	{
		if (map[c->y][c->x - 1] == 10 || map[c->y][c->x - 1] == -7)
			count += get_collectible_x(map, data, c, -1);
		else if (map[c->y + 1][c->x] == 10 || map[c->y + 1][c->x] == -7)
			count += get_collectible_y(map, data, c, 1);
		else if (map[c->y][c->x + 1] == 10 || map[c->y][c->x + 1] == -7)
			count += get_collectible_x(map, data, c, 1);
		else if (map[c->y - 1][c->x] == 10 || map[c->y - 1][c->x] == -7)
			count += get_collectible_y(map, data, c, -1);
		else
		{
			if (reverse_walking(map, data, c) == -1)
				return (-1);
		}
		data->remp++;
	}
	init_c(c, data, map3);
	return (1);
}

int	get_collectible_x(int **map, t_data *data, t_cord *c, int i)
{
	c->x += i;
	if (map[c->y][c->x] == -7)
		i = 1;
	else
		i = 0;
	map[c->y][c->x] = data->remp;
	return (i);
}

int	get_collectible_y(int **map, t_data *data, t_cord *c, int i)
{
	c->y += i;
	if (map[c->y][c->x] == -7)
		i = 1;
	else
		i = 0;
	map[c->y][c->x] = data->remp;
	return (i);
}
