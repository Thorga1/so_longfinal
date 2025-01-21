/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorgal <thorgal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:56:04 by tordner           #+#    #+#             */
/*   Updated: 2025/01/21 04:07:34 by thorgal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

int	map_setup(t_data *data, char *file)
{
	int		fd;
	char	buf[2048];
	int		size;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (write(1, "Error: invalid file\n", 20), 1);
	size = read(fd, buf, sizeof(buf));
	close(fd);
	buf[size] = '\0';
	data->dup_map = ft_split(buf, '\n');
	data->map = ft_split(buf, '\n');
	return (0);
}

int	data_setup(t_data *data, char *file)
{
	data->mlx = NULL;
	data->win = NULL;
	data->map = NULL;
	data->dup_map = NULL;
	data->img_wall = NULL;
	data->img_floor = NULL;
	data->img_collectible = NULL;
	data->img_player = NULL;
	data->img_exit = NULL;
	data->count_exit = 0;
	data->count_entrance = 0;
	data->count_collectible = 0;
	data->count_moves = 0;
	if (map_setup(data, file))
		return (1);
	if (check_map(data))
		return (1);
	mlx_setup(data);
	return (0);
}
