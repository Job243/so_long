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

	if (!map || !map[0])
		return (0);
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

int	count_char(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	if (!map)
		return(0);
	i = 0;
	count = 0;
	while (map[i])
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

	if (!map || rows < 1 || cols < 1)
		return (0);
	i = 0;
	while (i < cols)
	{
		if (map[0][i] != '1' || map[rows - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < rows)
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	validate_map(char **map)
{
	int	cols;
	int	rows;
	
	rows = 0;
	while (map[rows])
		rows++;
	cols = ft_strlen(map[0]);
	if (!is_rectangular(map))
	{
		printf("Error: Map is not rectangular.\n");
		return (0);
	}
	if (!is_enclosed_in_wall(map, rows, cols))
	{
		printf("Error : Map is not enclosed. \n");
		return (0);
	}
	return (1);
}

int	validate_char(char **map)
{
	if (count_char(map, 'E') != 1)
	{
		printf("Error : There should be exactly one exit.\n");
		return (0);
	}
	if (count_char(map, 'P') != 1)
	{
		printf("Error : There should be exactly one starting player.\n");
		return (0);
	}
	if (count_char(map, 'C') < 1)
	{
		printf("Error : there should be at least one collectible.\n");
		return (0);
	}
	return (1);
}