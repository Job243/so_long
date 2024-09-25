/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:58:31 by jmafueni          #+#    #+#             */
/*   Updated: 2024/09/25 22:50:11 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_no_event(void)
{
	return (0);
}

int	handle_keyrelease(int keysym, void *vars)
{
	(void)vars;
	printf("Keyrelease: %d\n", keysym);
	return (0);
}

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

void	render_tile(t_data *data, char tile, int x, int y)
{
	if (tile == '1')
		print_image(data, data->img_ptr_wall, x, y);
	else if (tile == '0')
		print_image(data, data->img_ptr_floor, x, y);
	else if (tile == 'P')
		print_image(data, data->img_ptr_player, x, y);
	else if (tile == 'C')
		print_image(data, data->img_ptr_item, x, y);
	else if (tile == 'E')
		print_image(data, data->img_ptr_exit, x, y);
}

// int	input_keyboard(int key, t_data *data)
// {
// 	if (key == XX_Escape)
// 	{
// 	}
// 	if (key == XX_w || key == XX_a || key == XX_s || key == XX_d)
// 	{

// 	}
// 	return (0);
// }
