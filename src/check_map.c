/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:10:04 by jmafueni          #+#    #+#             */
/*   Updated: 2024/08/09 15:52:55 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(char **map)
{
	int	len;
	int	i;

	if (!map || !map[0])
		return (0);
	i = 1;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	count_char(t_data *data)
{
	int	x;
	int	y;

	data->game->total_item = 0;
	data->game->total_player = 0;
	data->game->total_exit = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
				data->game->total_player++;
			else if (data->map[y][x] == 'E')
				data->game->total_exit++;
			else if (data->map[y][x] == 'C')
				data->game->total_item++;
			x++;
		}
		y++;
	}
	return (data->game->total_exit == 1 && data->game->total_player == 1
			&& data->game->total_item > 0);
}

int	is_enclosed_in_wall(char **map, int rows, int cols)
{
	int	i;

	if (!map || rows < 1 || cols < 1)
		return (0);
	i = 0;
	while (i < cols)
	{
		if (map[0][i] != '1' || map[rows - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < rows)
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	validate_char(char **map)
{
	int	x;
	int y;

	if (!map)
		return (0);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] != 'P' && map[y][x] != 'E' && map[y][x] != 'C'
				&& map[y][x] != '0' && map[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	validate_map(t_data *data)
{
	int	cols;
	int	rows;
	
	rows = 0;
	while (data->map[rows])
		rows++;
	cols = ft_strlen(data->map[0]);
	if (!is_rectangular(data->map))
		return (map_error("Error: Map is not rectangular.\n", data), 0);
	if (!is_enclosed_in_wall(data->map, rows, cols))
		return (map_error("Error : Map is not enclosed. \n", data), 0);
	if (!count_char(data))
		return (map_error("Error : Invalid numbers of players, exits or collectibles.\n", data), 0);
	if (!validate_char(data->map))
		return (map_error("Error : Map contains invalid characters.\n", data), 0);
	return (1);
}
