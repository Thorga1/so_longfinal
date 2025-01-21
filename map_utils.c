/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorgal <thorgal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:24:55 by tordner           #+#    #+#             */
/*   Updated: 2025/01/21 04:07:17 by thorgal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
				break ;
			j++;
		}
		if (data->map[i][j] == 'P')
			break ;
		i++;
	}
	data->i = i;
	data->j = j;
	return (0);
}

int	is_collectible_reachable(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'C' && data->dup_map[i][j] != 'X')
	{
		free_map(data->dup_map);
		data->dup_map = NULL;
		write(1, "Error: Collectible unreachable\n", 31);
		return (1);
	}
	return (0);
}

int	is_exit_reachable(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'E' && data->dup_map[i][j] != 'X')
	{
		free_map(data->dup_map);
		data->dup_map = NULL;
		write(1, "Error: Exit unreachable\n", 25);
		return (1);
	}
	return (0);
}
