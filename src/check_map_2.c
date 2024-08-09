/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:10:04 by jmafueni          #+#    #+#             */
/*   Updated: 2024/08/09 15:52:55 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(char **map)
{
	int	len;
	int	i;

	i = 1;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	count_char(char **map, int rows, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < rows)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	is_enclosed_in_wall(char **map, int rows, int cols)
{
	int	i;

	i = 0;
	while (i < cols)
	{
		if (map[0][i] != '1' || map[rows - 1] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < rows)
	{
		if (map[0][i] != '1' || map[cols - 1] != '1')
			return (0);
			i++;
	}
	return (1);
}

int	validate_map(char **map)
{
	if (!is_rectangular(map))
	{
		printf("Error: Map is not rectangular.\n");
		return (0);
	}
	return (1);
}
