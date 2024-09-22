/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:16:39 by jmafueni          #+#    #+#             */
/*   Updated: 2024/08/09 13:37:01 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_handler(int key, t_data *data)
{
	(void)key;
	mlx_destroy_window(data->vars->mlx_ptr, data->vars->win_ptr);
	exit(0);
	return (0);
}

int	handle_input(int key, t_data *data)
{
	if (key == XK_Escape)
		mlx_destroy_window(data->vars->mlx_ptr, data->vars->win_ptr);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->vars->mlx_ptr, data->vars->win_ptr);
	printf("Keypress:  %d\n", keysym);
	return (0);
}

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