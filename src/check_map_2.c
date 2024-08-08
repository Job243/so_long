/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:10:04 by jmafueni          #+#    #+#             */
/*   Updated: 2024/08/08 16:07:55 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_rectangular(char **map)
{
    int len;
    int i;

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

int has_valid_borders(char **map)
{
    int len;
    int i;

    i = 0;
    len = ft_strlen(map[0]);
    while (map[0][i])
    {
        if (map[0][i] != '1' || map[len - 1][i] != '1')
            return (0);
        i++;
    }
    i = 0;
    while (map[i])
    {
        if (map[i][0] != '1' || map[i][len - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}

int has_required_elements(char **map)
{
    int has_player;
    int has_exit;
    int has_collectible;
    int i;
    int j;

    i = 0;
    j = 0;
    has_player = 0;
    has_exit = 0;
    has_collectible = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
                has_player = 1;
            else if (map[i][j] == 'E')
                has_exit = 1;
            else if (map[i][j] == 'C')
                has_collectible = 1;
            j++;
        }
        i++;
    }
    return (has_player && has_exit && has_collectible);
}

int validate_map(char **map)
{
    if (!is_rectangular(map))
    {
        printf("Error: Map is not rectangular.\n");
        return (0);
    }
    if (!has_valid_borders(map))
    {
        printf("Error: Map borders are not valid.\n");
        return (0);
    }
    if (!has_required_elements(map))
    {
        printf("Error: Map does not have required elements.\n");
        return (0);
    }
    return (1);
}
