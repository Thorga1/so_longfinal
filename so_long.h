/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorgal <thorgal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:21:00 by tordner           #+#    #+#             */
/*   Updated: 2025/01/18 17:51:05 by thorgal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define W 1920
# define H 1080
# define ESC 65307
# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define TILE_SIZE 32

typedef struct s_data
{
	int		count_entrance;
	int		count_exit;
	int		count_collectible;
	int		count_moves;
	void	*mlx;
	void	*win;
	char	**map;
	char	**dup_map;
	int		i;
	int		j;

	void	*img_wall;
	void	*img_floor;
	void	*img_collectible;
	void	*img_player;
	void	*img_exit;
}			t_data;

int			errors(int ac, char **av);
int			data_setup(t_data *data, char *file);
int			check_map(t_data *data);
char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *src);
int			check_rectangular_map(t_data *data);
void		free_map(char **map);
void		mlx_setup(t_data *data);
void		start_window(t_data *data);
int			key_handling(int key, t_data *data);
int			exit_game(t_data *data);
int			validate_map_reachability(t_data *data);
void		move_up(t_data *data);
int			find_player(t_data *data);
void		print_map(t_data *data);
void		flood_fill(char **map, int x, int y);
void		draw_map(t_data *data);


#endif
