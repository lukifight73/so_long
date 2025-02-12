/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:36:00 by lbenatar          #+#    #+#             */
/*   Updated: 2024/12/10 17:36:01 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_ligne(char *map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i + 1])
	{
		if (map[i + 1] == '\n' && map[i] != '\n')
			count++;
		i++;
	}
	return (count);
}	

int	verif_saut_ligne(char *map)
{
	int	i;
	int	count;
	int	count2;

	count = count_ligne(map);
	count2 = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			count2++;
		if (count2 > count && map[i] != '\n')
		{
			free(map);
			return (-1);
		}
		i++;
	}
	return (1);
}	

void	init_c(t_cord *c, t_data *data, int **map)
{
	data->remp = 16;
	c->x = data->entry_x;
	c->y = data->entry_y;
	map[c->y][c->x] = 15;
}

int	get_mlx_ptr(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		free(data);
		return (-1);
	}
	return (1);
}

int	ft_init_data(t_data *data, char **map)
{
	int	salut;
	int	salut2;

	if (get_mlx_ptr(data) == -1)
		return (-1);
	data->food = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/food.xpm", &salut, &salut2);
	data->poulpy = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/poulpy.xpm", &salut, &salut2);
	data->back = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/background.xpm", &salut, &salut2);
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/exit.xpm", &salut, &salut2);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/wall.xpm", &salut, &salut2);
	if (!data->food || !data->back || !data->poulpy
		|| !data->exit || !data->wall)
	{
		liberator_pics(data);
		return (-1);
	}
	data->map = map;
	return (1);
}
