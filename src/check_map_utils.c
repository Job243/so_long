/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:03:29 by jmafueni          #+#    #+#             */
/*   Updated: 2024/09/27 16:53:13 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_map_name(char *s)
{
	size_t	len;

	len = ft_strlen(s);
	if (len >= 4 && s[len - 4] == '.' && s[len - 3] == 'b'
		&& s[len - 2] == 'e' && s[len - 1] == 'r')
		return (1);
	return (0);
}

void	floodfill(char **map, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x] ||
		x >= (int)strlen(map[y]) || map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'E')
	{
		game->found_exit = 1;
		return ;
	}
	if (map[y][x] == 'C')
		game->found_item++;
	if (map[y][x] != 'P')
		map[y][x] = 'V';
	floodfill(map, x + 1, y, game);
	floodfill(map, x - 1, y, game);
	floodfill(map, x, y + 1, game);
	floodfill(map, x, y - 1, game);
}

int	find_player_position(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->game->player_x = x;
				data->game->player_y = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

char	**initialize_tmp_map(t_data *data)
{
	int		i;
	char	**tmp_map;

	tmp_map = (char **)malloc(sizeof(char *) * (data->game->rows + 1));
	if (!tmp_map)
		return (NULL);
	i = 0;
	while (i < data->game->rows)
	{
		tmp_map[i] = ft_strdup(data->map[i]);
		if (!tmp_map[i])
		{
			ft_free(tmp_map);
			return (NULL);
		}
		i++;
	}
	tmp_map[data->game->rows] = NULL;
	return (tmp_map);
}

int	check_path(t_data *data)
{
	char	**tmp_map;

	if (!find_player_position(data))
		return (0);
	data->game->found_exit = 0;
	data->game->found_item = 0;
	tmp_map = initialize_tmp_map(data);
	if (!tmp_map)
		return (0);
	floodfill(tmp_map, data->game->player_x, data->game->player_y, data->game);
	ft_free(tmp_map);
	return (data->game->found_exit == 1
		&& data->game->found_item == data->game->total_item);
}
