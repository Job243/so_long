/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:10:04 by jmafueni          #+#    #+#             */
/*   Updated: 2024/09/26 17:22:26 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	count_elements(t_data *data, int *player_count,
		int *exit_count, int *collectibles_count)
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
				(*player_count)++;
			else if (data->map[i][j] == 'E')
				(*exit_count)++;
			else if (data->map[i][j] == 'C')
				(*collectibles_count)++;
			j++;
		}
		i++;
	}
}

int	count_char(t_data *data)
{
	int	player_count;
	int	exit_count;
	int	collectible_count;

	player_count = 0;
	exit_count = 0;
	collectible_count = 0;
	if (!data || !data->game)
		return (0);
	count_elements(data, &player_count, &exit_count, &collectible_count);
	if (player_count != 1 || exit_count != 1 || collectible_count == 0)
		return (0);
	data->game->total_exit = exit_count;
	data->game->total_player = player_count;
	data->game->total_item = collectible_count;
	return (1);
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
	i = 1;
	while (i < rows - 1)
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
	int	y;

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
	int	rows;
	int	cols;

	rows = 0;
	while (data->map[rows])
		rows++;
	cols = ft_strlen(data->map[0]);
	data->game->rows = rows;
	data->game->cols = cols;
	if (!is_rectangular(data->map))
		return (map_error("Error: Map is not rectangular.\n", data), 0);
	if (!is_enclosed_in_wall(data->map, data->game->rows, data->game->cols))
		return (map_error("Error : Map is not enclosed. \n", data), 0);
	if (!count_char(data))
		return (map_error("Error : Invalid numbers of P, E or C.\n", data), 0);
	if (!validate_char(data->map))
		return (map_error("Error : Map contains invalid characters.\n"
				, data), 0);
	if (!check_path(data))
		return (map_error("Error : Path not found.\n", data), 0);
	return (1);
}
