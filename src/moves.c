/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:56:55 by jmafueni          #+#    #+#             */
/*   Updated: 2024/09/25 22:39:48 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../ft_printf/ft_printf.h"

void	move_player(t_data *data, int new_x, int new_y)
{
	if (move_check(data, new_x, new_y))
	{
		data->map[data->game->player_y][data->game->player_x] = '0';
		data->game->player_x = new_x;
		data->game->player_y = new_y;
		data->game->move_count++;
		ft_printf("Move count: %d\n", data->game->move_count);
		print_map(data);
	}
}

int	move_check(t_data *data, int x, int y)
{
	if (data->map[y][x] == '0' || data->map[y][x] == 'C' ||
		(data->map[y][x] == 'E' && (data->game->total_item == 0)))
	{
		if (data->map[y][x] == 'C')
		{
			data->game->total_item--;
			data->map[y][x] = '0';
		}
		if (data->map[y][x] == 'E' && (data->game->total_item == 0))
		{
			ft_putstr_fd("You Won!\n", 2);
			exit_game(data);
		}
		data->map[y][x] = 'P';
		return (1);
	}
	return (0);
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == 65307)
		exit_game(data);
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

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		ft_putstr_fd("Usage: ./program <map_file.ber>\n", 1);
		return (1);
	}
	if (!read_ber(&data, av[1]))
	{
		ft_putstr_fd("Failed to read map file.\n", 1);
		return (1);
	}
	if (!validate_map(&data))
	{
		map_error("Error: Invalid map\n", &data);
		free_vars(&data);
		return (1);
	}
	so_long(&data);
	return (0);
}
