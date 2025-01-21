/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorgal <thorgal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:39:23 by thorgal           #+#    #+#             */
/*   Updated: 2025/01/21 04:13:36 by thorgal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*load_image(t_data *data, char *path)
{
	int		width;
	int		height;
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, path, &width, &height);
	if (!img || width != TILE_SIZE || height != TILE_SIZE)
	{
		write(1, "Error: Failed to load image\n", 28);
		exit(1);
	}
	return (img);
}

void	load_images(t_data *data)
{
	data->img_wall = load_image(data, "textures/wall.xpm");
	data->img_floor = load_image(data, "textures/floor.xpm");
	data->img_collectible = load_image(data, "textures/collectible.xpm");
	data->img_player = load_image(data, "textures/player.xpm");
	data->img_exit = load_image(data, "textures/exit.xpm");
}

static void	draw_tile(t_data *data, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img_wall, x, y);
	else if (tile == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img_floor, x, y);
	else if (tile == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img_collectible,
			x, y);
	else if (tile == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->img_player, x, y);
	else if (tile == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img_exit, x, y);
}

void	count_move(t_data *data)
{
	write(1, "moves = ", 8);
	ft_putnbr(data->count_moves);
	ft_putchar('\n');
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;
	int	i;
	int	j;

	count_move(data);
	mlx_clear_window(data->mlx, data->win);
	y = 0;
	i = 0;
	while (data->map[i])
	{
		x = 0;
		j = 0;
		while (data->map[i][j])
		{
			draw_tile(data, data->map[i][j], x, y);
			x += TILE_SIZE;
			j++;
		}
		y += TILE_SIZE;
		i++;
	}
}
