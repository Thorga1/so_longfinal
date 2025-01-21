/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorgal <thorgal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:06:40 by tordner           #+#    #+#             */
/*   Updated: 2025/01/21 04:10:38 by thorgal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_setup(t_data *data)
{
	char	*name;

	name = "so long";
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1000, 800, name);
	load_images(data);
}
