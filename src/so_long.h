/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:22:28 by lbenatar          #+#    #+#             */
/*   Updated: 2024/12/03 14:45:35 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <time.h>
# include <stdio.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <string.h>
# include <strings.h>
# include <bsd/string.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*food;
	void	*poulpy;
	void	*wall;
	void	*exit;
	void	*back;
	char	**map;
	int		count_move;
	int		count_food;
	int		poulpy_x;
	int		poulpy_y;
	int		exit_x;
	int		exit_y;
	int		entry_x;
	int		entry_y;
	int		case_tot;
	int		remp;
	int		height;
	int		width;
}			t_data;

typedef struct s_cord
{
	int	x;
	int	y;
}		t_cord;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

t_data	*verif_ber(char **map, int width, int height);
void	liberator_pics(t_data *data);
void	init_c(t_cord *c, t_data *data, int **map);
void	handle_input_bis(t_data *data, int i);
void	reverse_walking_exe(int **map, t_data *data, t_cord *c);
void	ft_put_image(t_data *data, void *pic, int x, int y);
void	get_to_exit_exe_x(int **map, t_data *data, t_cord *c, int i);
void	get_to_exit_exe_y(int **map, t_data *data, t_cord *c, int i);
void	mini_liberator(int **map2, int **map3, t_data *data, t_cord *c);
void	liberator_map_int(int **map, t_data *data);
void	liberator_data(t_data *data);
void	liberator_map(char **map);
void	join2(char *s1, char *s2, char *conc);
char	*ft_strjoin2(char *s1, char *s2);
char	*get_map_boucle(char *map, int fd, int verif);
char	*get_map(char *mapber);
int		verif_map(char **map);
int		verif_saut_ligne(char *map);
int		verif_mapber(char *mapber);
int		**copy_map(char **map, t_data *data);
int		close_window(t_data *data);
int		handle_input(int keysym, t_data *data);
int		ft_charrlen(char **map);
int		move_poulpy_w(t_data *data);
int		move_poulpy_s(t_data *data);
int		move_poulpy_a(t_data *data);
int		move_poulpy_d(t_data *data);
int		verif_chemin(int **map2, t_data *data, char **map);
int		get_all_collectible(int **map, t_data *data, t_cord *c, int **map3);
int		get_collectible_x(int **map, t_data *data, t_cord *c, int i);
int		get_collectible_y(int **map, t_data *data, t_cord *c, int i);
int		get_to_exit(int **map, t_data *data, t_cord *c);
int		is_exit_around(int **map, t_cord *c);
int		ft_strlen8(char *str);
int		c_la_muerda_autour(int **map, t_cord *c);
int		reverse_walking(int **map, t_data *data, t_cord *c);
int		check_way(int **map, t_cord *c);
int		verif_elements_aux(t_data *data, int i, int j, char c);
int		ft_init_data(t_data *data, char **map);
int		get_mlx_ptr(t_data *data);
int		verif_elements(char **map, int p, int e, t_data *data);
int		verif_map_format(char **map, t_data *data);

#endif
