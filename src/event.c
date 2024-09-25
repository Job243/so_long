/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:58:31 by jmafueni          #+#    #+#             */
/*   Updated: 2024/09/25 20:15:45 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_handler(int key, t_data *data)
{
	(void)key;
	mlx_destroy_image(data->vars->mlx_ptr, data->img_ptr_exit);
	mlx_destroy_image(data->vars->mlx_ptr, data->img_ptr_floor);
	mlx_destroy_image(data->vars->mlx_ptr, data->img_ptr_item);
	mlx_destroy_image(data->vars->mlx_ptr, data->img_ptr_player);
	mlx_destroy_image(data->vars->mlx_ptr, data->img_ptr_wall);
	mlx_destroy_window(data->vars->mlx_ptr, data->vars->win_ptr);
	exit(0);
	return (0);
}

// int	handle_keypress(int keysym, t_data *data)
// {
// 	if (keysym == XK_Escape)
// 		exit_game(data);
// 	printf("Keypress:  %d\n", keysym);
// 	return (0);
// }

int	handle_keyrelease(int keysym, void *vars)
{
	(void)vars;
	printf("Keyrelease: %d\n", keysym);
	return (0);
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
