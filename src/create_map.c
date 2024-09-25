/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:58:45 by jmafueni          #+#    #+#             */
/*   Updated: 2024/09/25 22:37:48 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_vars(t_data *data)
{
	t_game	*tmp_game;
	t_vars	*tmp_vars;

	tmp_game = (t_game *)malloc(sizeof(t_game));
	data->game = tmp_game;
	if (!data->game)
		return (0);
	data->game->player_x = 0;
	data->game->player_y = 0;
	data->game->move_count = 0;
	data->game->item_collected = 0;
	data->game->total_player = 0;
	data->game->total_exit = 0;
	data->game->total_item = 0;
	data->fd = 0;
	tmp_vars = (t_vars *)malloc(sizeof(t_vars));
	data->vars = tmp_vars;
	if (!data->vars)
		return (0);
	return (1);
}

int	line_number(char *file)
{
	char	*line;
	int		fd;
	int		count_line;

	count_line = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		count_line++;
		line = get_next_line(fd);
	}
	close(fd);
	return (count_line);
}

int	validate_and_count_lines(t_data *data, char *ber, int *line_count)
{
	if (!check_map_name(ber))
	{
		ft_putstr_fd("Error: Wrong file extension\n", 2);
		return (0);
	}
	*line_count = line_number(ber);
	if (*line_count <= 0)
	{
		ft_putstr_fd("Error: File does not exist or is empty\n", 2);
		return (0);
	}
	data->fd = open(ber, O_RDONLY);
	if (data->fd < 0)
	{
		ft_putstr_fd("Error: Failed to open file\n", 2);
		return (0);
	}
	return (1);
}

int	read_map_data(t_data *data, int line_count)
{
	int		i;
	char	*line;

	data->map = ft_calloc(line_count + 1, sizeof(char *));
	if (!data->map)
		return (close(data->fd), 0);
	i = 0;
	while (i < line_count)
	{
		line = get_next_line(data->fd);
		if (!line)
			break ;
		data->map[i] = ft_strtrim(line, " \n");
		free(line);
		i++;
	}
	close(data->fd);
	if (i != line_count)
	{
		map_error(NULL, data);
		return (0);
	}
	return (1);
}

int	read_ber(t_data *data, char *ber)
{
	int	line_count;

	line_count = 0;
	if (!validate_and_count_lines(data, ber, &line_count))
		return (0);
	if (!read_map_data(data, line_count))
		return (0);
	if (!init_vars(data))
	{
		map_error(NULL, data);
		return (0);
	}
	return (1);
}
