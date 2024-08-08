/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:44:35 by jmafueni          #+#    #+#             */
/*   Updated: 2024/08/08 16:09:55 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	exit(0);
}



int	check_map_name(char *s)
{
	size_t len;

	len = ft_strlen(s);
	if (s[len] == 'r' && s[len - 1] == 'e' && s[len - 2] == 'b' && s[len - 3] == '.')
		return (0);
	return (1);
}
