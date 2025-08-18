/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:54:32 by lbenatar          #+#    #+#             */
/*   Updated: 2024/12/05 11:09:01 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	on_met_les_murs(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->back, j * 32, i * 32);
			if (map[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->wall, j * 32, i * 32);
			j++;
		}
		i++;
		j = 0;
	}
}

void	on_met_reste(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				ft_put_image(data, data->poulpy, j, i);
				data->poulpy_x = j;
				data->poulpy_y = i;
			}
			if (map[i][j] == 'C')
				ft_put_image(data, data->food, j, i);
			if (map[i][j] == 'E')
				ft_put_image(data, data->exit, j, i);
			j++;
		}
		i++;
		j = 0;
	}
}

t_data	*ft_lstinitgraph(int width, int height, char **map)
{
	t_data	*data;

	data = verif_ber(map, width, height);
	if (!data)
		return (NULL);
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "Poulpy 3000");
	if (!data->win_ptr)
	{
		liberator_pics(data);
		return (NULL);
	}
	data->count_move = 0;
	return (data);
}

t_data	*start_game(char **map)
{
	t_data	*data;
	int		width;
	int		height;

	width = ft_strlen(map[1]) * 32;
	height = ft_charrlen(map) * 32;
	data = ft_lstinitgraph(width, height, map);
	if (!data)
	{
		liberator_map(map);
		return (NULL);
	}
	ft_printf("\nBienvenu dans un des mondes de Poulpy.\n");
	ft_printf("Aidez le a deguster tous ces delicieux crabes !!!");
	ft_printf("\n\n~Hummmmm\n~Miaaammmmm\n~J'en salive d'avance...\n\n");
	mlx_key_hook(data->win_ptr, handle_input, data);
	on_met_les_murs(map, data);
	on_met_reste(map, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	mlx_hook(data->win_ptr, 33, 0, close_window, data);
	mlx_loop(data->mlx_ptr);
	return (data);
}

int	main(int ac, char **av)
{
	char	*map1;
	char	**map;
	t_data	*data;

	if (ac != 2)
		return (0);
	map1 = get_map(av[1]);
	if (!map1 || verif_saut_ligne(map1) == -1)
	{
		ft_printf("Error\nLa map n'est pas valide.\n");
		return (0);
	}
	map = ft_split(map1, '\n');
	free(map1);
	if (!map)
	{
		ft_printf("Error\nLa map n'a pas pu être chargée.\n");
		return (0);
	}
	data = start_game(map);
	if (!data)
		return (0);
	return (0);
}
