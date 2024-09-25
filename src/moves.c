/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:56:55 by jmafueni          #+#    #+#             */
/*   Updated: 2024/09/23 18:57:13 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_data *data, int new_x, int new_y)
{
	if (move_check(data, new_x, new_y))
	{
		data->game->player_x = new_x;
		data->game->player_y = new_y;
		print_map(data);
	}
}

int	move_check(t_data *data, int x, int y)
{
	if (data->map[y][x] == '0' || data->map[y][x] == 'C' ||
		(data->map[y][x] == 'E' && (data->game->total_item == 0)))
	{
		data->game->player_x = x;
		data->game->player_y = y;
		if (data->map[y][x] == 'C')
			data->game->total_item--;
		if (data->map[y][x] == 'E' && (data->game->total_item == 0))
			exit(1);
		data->map[y][x] = 'P';
		return (1);
	}
	return (0);
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(data->vars->mlx_ptr, data->vars->win_ptr);
		exit(0);
	}
	else if (keycode == 119 || keycode == 65362)
		move_player(data, data->game->player_x, data->game->player_y - 1);
	else if (keycode == 97 || keycode == 65361)
		move_player(data, data->game->player_x - 1, data->game->player_y);
	else if (keycode == 115 || keycode == 65364)
		move_player(data, data->game->player_x, data->game->player_y + 1);
	else if (keycode == 100 || keycode == 65363)
		move_player(data, data->game->player_x + 1, data->game->player_y);
	return (0);
}
