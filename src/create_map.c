/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:16:39 by jmafueni          #+#    #+#             */
/*   Updated: 2024/08/09 13:37:01 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_var(t_data *data)
{
	data->game->player_x = 0;
	data->game->player_y = 0;
	data->game->move_count = 0;
	data->game->item_collected = 0;
	data->fd = 0;
	data->vars->mlx_ptr = NULL;
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

int	read_ber(t_data *data, char *ber)
{
	int		i;
	int		line_count;
	char	*line;

	// Vérifier l'extension du fichier
	if (!check_map_name(ber))
	{
		ft_putstr_fd("Error: Wrong file extension\n", 2);
		return (0);
	}

	// Compter le nombre de lignes
	line_count = line_number(ber);
	if (line_count <= 0)
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
		data->map[i] = line;
		i++;
	}
	close(data->fd);

	// Vérifier si toutes les lignes ont été lues correctement
	if (i != line_count)
		return (ft_putstr_fd("Error!\nMismatch in line count\n", 1), 0);

	// Initialiser les variables du jeu
	if (!init_var(data))
		return (0);

	return (1);
}


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


/*int main(int argc, char **argv)
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

    // Afficher la map pour vérification
    int i = 0;
    while (data.map[i])
    {
        printf("%s", data.map[i]); // Les lignes de la carte sont déjà terminées par un '\n' grâce à get_next_line
        free(data.map[i]); // Libérer chaque ligne après l'affichage
        i++;
    }

    free(data.map); // Libérer le tableau de la carte
    return (0);
}*/

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

