/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:56:04 by tordner           #+#    #+#             */
/*   Updated: 2025/01/15 15:01:34 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
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
