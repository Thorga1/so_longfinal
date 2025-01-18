 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:24:55 by tordner           #+#    #+#             */
/*   Updated: 2025/01/15 15:01:00 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_data *data)
{
	printf("moves = %d\n", data->count_moves);
	printf("collectibles left = %d\n\n", data->count_collectible);
	for (int i = 0; data->map[i]; i++)
		printf("%s\n", data->map[i]);
	printf("\n");
}

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
