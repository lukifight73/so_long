/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:22:23 by lbenatar          #+#    #+#             */
/*   Updated: 2024/12/10 17:22:24 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	liberator_data(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->food);
	mlx_destroy_image(data->mlx_ptr, data->poulpy);
	mlx_destroy_image(data->mlx_ptr, data->back);
	mlx_destroy_image(data->mlx_ptr, data->exit);
	mlx_destroy_image(data->mlx_ptr, data->wall);
	liberator_map(data->map);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
}

void	liberator_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	liberator_map_int(int **map, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	mini_liberator(int **map2, int **map3, t_data *data, t_cord *c)
{
	liberator_map_int(map2, data);
	liberator_map_int(map3, data);
	free(c);
}

void	liberator_pics(t_data *data)
{
	if (data->food)
		mlx_destroy_image(data->mlx_ptr, data->food);
	if (data->poulpy)
		mlx_destroy_image(data->mlx_ptr, data->poulpy);
	if (data->back)
		mlx_destroy_image(data->mlx_ptr, data->back);
	if (data->exit)
		mlx_destroy_image(data->mlx_ptr, data->exit);
	if (data->wall)
		mlx_destroy_image(data->mlx_ptr, data->wall);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
}
