/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_poulpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:22:10 by lbenatar          #+#    #+#             */
/*   Updated: 2024/12/10 17:22:12 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_poulpy_w(t_data *data)
{
	if (data->map[data->poulpy_y - 1][data->poulpy_x] != '1'
			&& (data->map[data->poulpy_y - 1][data->poulpy_x] != 'E'
			|| data->count_food == 0))
	{
		ft_put_image(data, data->back, data->poulpy_x, data->poulpy_y);
		data->poulpy_y -= 1;
		data->count_move += 1;
		ft_put_image(data, data->poulpy, data->poulpy_x, data->poulpy_y);
		return (1);
	}
	else if (data->map[data->poulpy_y - 1][data->poulpy_x] == 'E'
			&& data->count_food != 0)
		ft_printf("\nPoulpy n'a pas devore tous les crabes!!!\n");
	return (0);
}

int	move_poulpy_s(t_data *data)
{
	if (data->map[data->poulpy_y + 1][data->poulpy_x] != '1'
		&& (data->map[data->poulpy_y + 1][data->poulpy_x] != 'E'
			|| data->count_food == 0))
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->back,
			data->poulpy_x * 32, data->poulpy_y * 32);
		data->poulpy_y += 1;
		data->count_move += 1;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->poulpy,
			data->poulpy_x * 32, data->poulpy_y * 32);
		return (1);
	}
	else if (data->map[data->poulpy_y + 1][data->poulpy_x] == 'E'
			&& data->count_food != 0)
		ft_printf("\nPoulpy n'a pas devore tous les crabes!!!\n");
	return (0);
}

int	move_poulpy_a(t_data *data)
{
	if (data->map[data->poulpy_y][data->poulpy_x - 1] != '1'
		&& (data->map[data->poulpy_y][data->poulpy_x - 1] != 'E'
			|| data->count_food == 0))
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->back,
			data->poulpy_x * 32, data->poulpy_y * 32);
		data->poulpy_x -= 1;
		data->count_move += 1;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->poulpy,
			data->poulpy_x * 32, data->poulpy_y * 32);
		return (1);
	}
	else if (data->map[data->poulpy_y][data->poulpy_x - 1] == 'E'
			&& data->count_food != 0)
		ft_printf("\nPoulpy n'a pas devore tous les crabes!!!\n");
	return (0);
}

int	move_poulpy_d(t_data *data)
{
	if (data->map[data->poulpy_y][data->poulpy_x + 1] != '1'
		&& (data->map[data->poulpy_y][data->poulpy_x + 1] != 'E'
			|| data->count_food == 0))
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->back,
			data->poulpy_x * 32, data->poulpy_y * 32);
		data->poulpy_x += 1;
		data->count_move += 1;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->poulpy,
			data->poulpy_x * 32, data->poulpy_y * 32);
		return (1);
	}
	else if (data->map[data->poulpy_y][data->poulpy_x + 1] == 'E'
			&& data->count_food != 0)
		ft_printf("\nPoulpy n'a pas devore tous les crabes!!!\n");
	return (0);
}
