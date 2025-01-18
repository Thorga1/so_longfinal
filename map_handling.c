/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorgal <thorgal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:34:37 by tordner           #+#    #+#             */
/*   Updated: 2025/01/18 18:46:53 by thorgal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data)
{
	char	temp;

	find_player(data);
	if (data->map[data->i - 1][data->j] == '0')
	{
		data->count_moves++;
		temp = data->map[data->i - 1][data->j];
		data->map[data->i - 1][data->j] = data->map[data->i][data->j];
		data->map[data->i][data->j] = temp;
	}
	else if (data->map[data->i - 1][data->j] == 'C')
	{
		data->count_moves++;
		data->count_collectible--;
		temp = '0';
		data->map[data->i - 1][data->j] = data->map[data->i][data->j];
		data->map[data->i][data->j] = temp;
	}
	else if (data->map[data->i - 1][data->j] == 'E'
		&& data->count_collectible == 0)
	{
		data->count_moves++;
		exit_game(data);
	}
}

void	move_down(t_data *data)
{
	char	temp;

	find_player(data);
	if (data->map[data->i + 1][data->j] == '0')
	{
		data->count_moves++;
		temp = data->map[data->i + 1][data->j];
		data->map[data->i + 1][data->j] = data->map[data->i][data->j];
		data->map[data->i][data->j] = temp;
	}
	else if (data->map[data->i + 1][data->j] == 'C')
	{
		data->count_moves++;
		data->count_collectible--;
		temp = '0';
		data->map[data->i + 1][data->j] = data->map[data->i][data->j];
		data->map[data->i][data->j] = temp;
	}
	else if (data->map[data->i + 1][data->j] == 'E'
		&& data->count_collectible == 0)
	{
		data->count_moves++;
		exit_game(data);
	}
}

void	move_left(t_data *data)
{
	char	temp;

	find_player(data);
	if (data->map[data->i][data->j - 1] == '0')
	{
		data->count_moves++;
		temp = data->map[data->i][data->j - 1];
		data->map[data->i][data->j - 1] = data->map[data->i][data->j];
		data->map[data->i][data->j] = temp;
	}
	else if (data->map[data->i][data->j - 1] == 'C')
	{
		data->count_moves++;
		data->count_collectible--;
		temp = '0';
		data->map[data->i][data->j - 1] = data->map[data->i][data->j];
		data->map[data->i][data->j] = temp;
	}
	else if (data->map[data->i][data->j - 1] == 'E'
		&& data->count_collectible == 0)
	{
		data->count_moves++;
		exit_game(data);
	}
}

void	move_right(t_data *data)
{
	char	temp;

	find_player(data);
	if (data->map[data->i][data->j + 1] == '0')
	{
		data->count_moves++;
		temp = data->map[data->i][data->j + 1];
		data->map[data->i][data->j + 1] = data->map[data->i][data->j];
		data->map[data->i][data->j] = temp;
	}
	else if (data->map[data->i][data->j + 1] == 'C')
	{
		data->count_moves++;
		data->count_collectible--;
		temp = '0';
		data->map[data->i][data->j + 1] = data->map[data->i][data->j];
		data->map[data->i][data->j] = temp;
	}
	else if (data->map[data->i][data->j + 1] == 'E'
		&& data->count_collectible == 0)
	{
		data->count_moves++;
		exit_game(data);
	}
}

int	key_handling(int key, t_data *data)
{
	if (key == ESC)
		exit_game(data);
	if (key == UP_ARROW)
		move_up(data);
	else if (key == DOWN_ARROW)
		move_down(data);
	else if (key == LEFT_ARROW)
		move_left(data);
	else if (key == RIGHT_ARROW)
		move_right(data);
	draw_map(data);
	return (key);
}
