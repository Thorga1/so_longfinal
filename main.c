/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorgal <thorgal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:50:08 by tordner           #+#    #+#             */
/*   Updated: 2025/01/18 18:53:34 by thorgal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_data(t_data *data)
{
	// free(data);
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
