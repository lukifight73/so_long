/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:27:51 by lbenatar          #+#    #+#             */
/*   Updated: 2024/12/10 17:27:52 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_input_bis(t_data *data, int i)
{
	if (data->map[data->poulpy_y][data->poulpy_x] == 'C')
	{
		data->count_food -= 1;
		if (data->count_food != 0)
			ft_printf("\n~Miam \n~Il reste %d crabe(s).\n", data->count_food);
		else
			ft_printf("\n~Miam \n~Direction la sortie!\n");
		data->map[data->poulpy_y][data->poulpy_x] = '0';
	}
	if (i == 1)
		ft_printf("\nNombre de mouvements : %d", data->count_move);
	if ((data->exit_x == data->poulpy_x && data->exit_y == data->poulpy_y)
		&& data->count_food == 0)
	{
		ft_printf("\n~En route vers d'autres horizons et d'autres craaabbess..");
		ft_printf("\n\nPoulpy a fait %d mouvements!!!\n\n", data->count_move);
		liberator_data(data);
		exit(1);
	}
}

void	ft_put_image(t_data *data, void *pic, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, pic, x * 32, y * 32);
}

int	close_window(t_data *data)
{
	ft_printf("\nVous avez appuyé sur la petite croix.\n");
	ft_printf("Fermeture du jeu.\n\n");
	liberator_data(data);
	exit(1);
}

int	handle_input(int keysym, t_data *data)
{
	size_t	i;

	i = 0;
	if (keysym == XK_Escape)
	{
		ft_printf("Vous avez appuyé sur la touche échap.\n");
		ft_printf("Fermeture du jeu.\n\n");
		liberator_data(data);
		exit(1);
	}
	else if (keysym == 'w')
		i = move_poulpy_w(data);
	else if (keysym == 's')
		i = move_poulpy_s(data);
	else if (keysym == 'a')
		i = move_poulpy_a(data);
	else if (keysym == 'd')
		i = move_poulpy_d(data);
	handle_input_bis(data, i);
	return (0);
}
