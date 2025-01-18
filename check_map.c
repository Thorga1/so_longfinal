/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:09:39 by tordner           #+#    #+#             */
/*   Updated: 2024/12/20 15:16:08 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_left_right_walls(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] != '\n' && data->map[i][j] != '\0')
			j++;
		if (data->map[i][0] != '1' || data->map[i][j - 1] != '1')
			return (write(1, "Error: Map not enclosed by walls\n", 33), 1);
		i++;
	}
	return (0);
}

int	check_top_bot_walls(t_data *data)
{
	int	j;
	int	last_row;

	last_row = 0;
	j = 0;
	while (data->map[last_row])
		last_row++;
	last_row--;
	while (data->map[0][j] != '\n' && data->map[0][j] != '\0')
	{
		if (data->map[0][j] != '1' || data->map[last_row][j] != '1')
			return (write(1, "Error: Map not enclosed by walls\n", 33), 1);
		j++;
	}
	return (0);
}

int	check_special_characters_map(t_data *data)
{
	if (data->count_exit < 1 || data->count_entrance < 1
		|| data->count_collectible < 1)
		return (write(1, "Error: Missing essential elements (E, P, or C)\n",
				48), 1);
	if (data->count_exit > 1)
		return (write(1, "Error: Too many exits\n", 23), 1);
	if (data->count_entrance > 1)
		return (write(1, "Error: Too many starting positions\n", 36), 1);
	return (0);
}

int	check_characters_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j] != '\n' && data->map[i][j] != '\0')
		{
			if (data->map[i][j] != '0' && data->map[i][j] != '1'
				&& data->map[i][j] != 'C' && data->map[i][j] != 'E'
				&& data->map[i][j] != 'P')
				return (write(1, "Error: invalid map\n", 19), 1);
			if (data->map[i][j] == 'E')
				data->count_exit++;
			if (data->map[i][j] == 'P')
				data->count_entrance++;
			if (data->map[i][j] == 'C')
				data->count_collectible++;
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	check_map(t_data *data)
{
	if (check_rectangular_map(data) == 1 || check_characters_map(data) == 1
		|| check_special_characters_map(data) == 1
		|| check_left_right_walls(data) == 1 || check_top_bot_walls(data) == 1
		|| validate_map_reachability(data) == 1)
		return (1);
	return (0);
}
