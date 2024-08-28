/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:16:39 by jmafueni          #+#    #+#             */
/*   Updated: 2024/08/09 13:37:01 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_check(t_data *data, int i, int j)
{
	if (data.map[i][j] == '0' || data.map[i][j] == 'C' || 
		(data.map[i][j] == 'E' && (data.game.total_item == 0))) 
	{
		data.game = (t_game){.player.x = j, player.y = i};
		if (data.map[i][j] == 'C')
			data.game.total_item--;
		if (data.game[i][j] == 'E' && (data.game.total_item == 0))
			exit(1);
		data.map[i][j] = 'P';
		return (1); 
	}
}