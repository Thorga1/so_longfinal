/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorgal <thorgal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:50:08 by tordner           #+#    #+#             */
/*   Updated: 2025/01/21 04:06:49 by thorgal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_data *data)
{
	if (data->img_wall)
		mlx_destroy_image(data->mlx, data->img_wall);
	if (data->img_floor)
		mlx_destroy_image(data->mlx, data->img_floor);
	if (data->img_collectible)
		mlx_destroy_image(data->mlx, data->img_collectible);
	if (data->img_player)
		mlx_destroy_image(data->mlx, data->img_player);
	if (data->img_exit)
		mlx_destroy_image(data->mlx, data->img_exit);
}

static void	free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->map)
		free_map(data->map);
	if (data->dup_map)
		free_map(data->dup_map);
	free_images(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free(data);
}

int	exit_game(t_data *data)
{
	count_move(data);
	free_data(data);
	exit(1);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (errors(ac, av))
		return (1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	if (data_setup(data, av[1]))
	{
		free_data(data);
		return (1);
	}
	draw_map(data);
	mlx_hook(data->win, 17, (1L << 0), exit_game, data);
	mlx_key_hook(data->win, key_handling, data);
	mlx_loop(data->mlx);
	return (0);
}
