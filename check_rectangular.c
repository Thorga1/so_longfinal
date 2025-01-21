/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangular.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorgal <thorgal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:06:58 by tordner           #+#    #+#             */
/*   Updated: 2025/01/21 04:05:30 by thorgal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular_map(t_data *data)
{
	int	i;
	int	first_row_length;
	int	current_row_length;

	first_row_length = 0;
	while (data->map[0][first_row_length] != '\n'
		&& data->map[0][first_row_length] != '\0')
		first_row_length++;
	i = 1;
	while (data->map[i])
	{
		current_row_length = 0;
		while (data->map[i][current_row_length] != '\n'
			&& data->map[i][current_row_length] != '\0')
			current_row_length++;
		if (current_row_length != first_row_length)
			return (write(1, "Error: Map is not rectangular\n", 30), 1);
		i++;
	}
	return (0);
}

int	init_flood_fill(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				flood_fill(data->dup_map, j, i);
				return (0);
			}
			j++;
		}
		i++;
	}
	free_map(data->dup_map);
	return (write(1, "Error: Player not found on map\n", 31), 1);
}

void	flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[y] || map[y][x] == '\0')
		return ;
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int	validate_reachability(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (is_collectible_reachable(data, i, j)
				|| is_exit_reachable(data, i, j))
				return (1);
			j++;
		}
		i++;
	}
	free_map(data->dup_map);
	data->dup_map = NULL;
	return (0);
}

int	validate_map_reachability(t_data *data)
{
	if (init_flood_fill(data) == 1)
		return (1);
	if (validate_reachability(data) == 1)
		return (1);
	return (0);
}
