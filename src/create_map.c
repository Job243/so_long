/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:58:45 by jmafueni          #+#    #+#             */
/*   Updated: 2024/09/25 16:22:55 by jmafueni         ###   ########.fr       */
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
	{
		ft_putstr_fd("Error: game structure is NULL\n", 2);
		return (0);
	}
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
	{
		ft_putstr_fd("Error: vars struture is NULL\n", 2);
		return (0);
	}
	// data->vars->mlx_ptr = NULL;
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
	while ((line = get_next_line(fd)) != NULL)
	{
		free(line);
		count_line++;
	}
	close(fd);
	return (count_line);
}

int	validate_and_count_lines(t_data *data, char *ber, int *line_count)
{
	// Vérifier l'extension du fichier
	if (!check_map_name(ber))
	{
		ft_putstr_fd("Error: Wrong file extension\n", 2);
		return (0);
	}
	// Compter le nombre de lignes
	*line_count = line_number(ber);
	if (*line_count <= 0)
	{
		ft_putstr_fd("Error: File does not exist or is empty\n", 2);
		return (0);
	}
	// Ouvrir le fichier et allouer la mémoire pour le tableau de lignes
	data->fd = open(ber, O_RDONLY);
	if (data->fd < 0)
	{
		ft_putstr_fd("Error: Failed to open file\n", 2);
		return (0);
	}
	return (1);
}

int	read_map_data(t_data *data, int	line_count)
{
	int		i;
	char	*line;

	// Allocate memory for the map
	data->map = ft_calloc(line_count + 1, sizeof(char *));
	if (!data->map)
	{
		close(data->fd);
		ft_putstr_fd("Error: Memory allocation failed\n", 2);
		return (0);
	}
	// Lire le fichier ligne par ligne
	i = 0;
	while ((line = get_next_line(data->fd)) != NULL)
	{
		if (line)
		{
			data->map[i] = ft_strtrim(line, " \n");
			free(line);
			i++;
		}
	}
	close(data->fd);
	// Vérifier si toutes les lignes ont été lues correctement
	if (i != line_count)
	{
		ft_putstr_fd("Error!\nMismatch in line count\n", 1);
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

// int	main(int ac, char **av)
// {
// 	t_data data;

// 	if (ac != 2)
// 	{
// 		ft_putstr_fd("Usage: ./so_long <map.ber>\n", 2);
// 		return (1);
// 	}
// 	// if (!init_vars(&data))
// 	// {
// 	// 	ft_putstr_fd("Error: Failed to initialize variables\n", 2);
// 	// 	return (1);
// 	// }
// 	if (!read_ber(&data,av[1]))
// 	{
// 		ft_putstr_fd("Error: Map parsing failed\n", 2);
// 		return (1);
// 	}
// 	if (!validate_map(&data))
// 	{
// 		map_error("Error: Invalid map\n", &data);
// 		return (1);
// 	}
// 	printf("Map loaded successfully\n");
// 	map_error(NULL, &data);
// 	return (0);
// }

// int	read_ber(t_data *data, char *ber)
// {
// 	int		i;
// 	int		line_count;
// 	char	*line;

// 	if (!check_map_name(ber))
// 		return (ft_putstr_fd("Error!\nWrong file extension", 1), 0);
// 	i = 0;
// 	line_count = line_number(ber);
// 	if (line_count == 0)
// 		return (ft_putstr_fd("Error!\nFile don't exist", 1), 0);
// 	data->fd = open(ber, O_RDONLY);
// 	data->map = ft_calloc(line_count + 1, sizeof(char *));
// 	if (!data->map)
// 		return(ft_putstr_fd("Error!\nFailed to open", 1), 0);
// 	while ((line = get_next_line(data->fd)) != NULL)
// 	{
// 		data->map[i] = line;
// 		i++;
// 	}
// 	if (!init_var(data))
// 		return (0);
// 	return (1);
// }


int main(int argc, char **argv)
{
	t_data data;
	// Vérifier que le bon nombre d'arguments est passé
	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./program <map_file.ber>\n", 1);
		return (1);
	}
	// Lire le fichier .ber et initialiser les données
	if (!read_ber(&data, argv[1]))
	{
		ft_putstr_fd("Failed to read map file.\n", 1);
		return (1);
	}
	if (!validate_map(&data))
	{
		map_error("Error: Invalid map\n", &data);
		return (1);
	}
	printf("Map loaded successfully\n");
	map_error(NULL, &data);
	// Afficher la map pour vérification

	return (0);
}

/*int	file_exists(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (0);
	}
	close(fd);
	return (1);
}

char	*read_file(const char *filename)
{
	int		fd;
	int		bytes_read;
	char	*buffer;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
	if (bytes_read <= 0)
	{
		free(buffer);
		close(fd);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	close(fd);
	return (buffer);
}*/

