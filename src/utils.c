/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:44:35 by jmafueni          #+#    #+#             */
/*   Updated: 2024/09/25 19:05:38 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "get_next_line.h"

int	exit_game(t_data *data)
{
	mlx_destroy_image(data->vars->mlx_ptr, data->img_ptr_exit);
	mlx_destroy_image(data->vars->mlx_ptr, data->img_ptr_floor);
	mlx_destroy_image(data->vars->mlx_ptr, data->img_ptr_item);
	mlx_destroy_image(data->vars->mlx_ptr, data->img_ptr_player);
	mlx_destroy_image(data->vars->mlx_ptr, data->img_ptr_wall);
	mlx_destroy_window(data->vars->mlx_ptr, data->vars->win_ptr);
	mlx_destroy_display(data->vars->mlx_ptr);
	free(data->vars->mlx_ptr);
	ft_free(data->map);
	free_vars(data);
	exit(0);
}

int	check_map_name(char *s)
{
	size_t	len;

	len = ft_strlen(s);
	if (s[len] == 'r' && s[len - 1] == 'e'
		&& s[len - 2] == 'b' && s[len - 3] == '.')
		return (0);
	return (1);
}

int	game_loop(t_data *data)
{
	mlx_put_image_to_window(data->vars->mlx_ptr, data->vars->win_ptr, data->img_ptr_player, data->game->player_x, data->game->player_y);
	return (0);
}

int	setup_hook(t_data *data)
{
	mlx_hook(data->vars->win_ptr, 2, 1L<<0, handle_keypress, data);
	mlx_hook(data->vars->win_ptr, 17, 1L<<17, exit_game, data);
	mlx_loop_hook(data->vars->mlx_ptr, game_loop, data);
	return (0);
}

// int	map_error(char *error, t_data *data)
// {
// 	ft_free(char **map);
// 	return (ft_putstr_fd(err, 1), 0);
// }
