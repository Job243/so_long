/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:16:39 by jmafueni          #+#    #+#             */
/*   Updated: 2024/08/09 13:37:01 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(void)
{
	return (0);
}

/*int	handle_input(int key, t_vars *vars)
{
	if (key == XK_Escape)
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	return (0);
}

int	handle_keypress(int keysym, t_vars *vars)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	printf("Keypress:  %d\n", keysym);
	return (0);
}

int	handle_keyrelease(int keysym, void *vars)
{
	printf("Keyrelease: %d\n", keysym);
	return (0);
}*/

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
        return (0);
    i = 0;
	while (str[i] != '\0')
	    i++;
	return (i);
}


int map_error(const char *message, t_data *data)
{
    if (message)
        fprintf(stderr, "%s", message);

    // Free allocated memory
    if (data->map)
    {
        for (int i = 0; data->map[i]; ++i)
            free(data->map[i]);
        free(data->map);
        data->map = NULL;  // Avoid dangling pointer issues
    }

    return (0);
}


// Function to create a sample t_data instance
t_data *create_test_data(char **map)
{
	t_data *data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return NULL;

	data->map = map;
	data->game = (t_game *)malloc(sizeof(t_game));
	if (!data->game)
	{
		free(data);
		return NULL;
	}

	// Initialize game totals to 0
	data->game->total_item = 0;
	data->game->total_player = 0;
	data->game->total_exit = 0;

	return data;
}


char *ft_strdup(const char *s1)
{
    char *copy = malloc(strlen(s1) + 1);
    if (copy)
        strcpy(copy, s1);
    return copy;
}

/*int main(void)
{
    // Initialisation de la carte
    char *map[] = {
        "11111",
        "1P0C1",
        "10011",
        "1C0E1",
        "11111",
        NULL
    };

    // Initialisation des structures
    t_game game = {0};
    t_data data = {0};

    data.map = map;
    data.game = &game;
    data.game->rows = 5;  // Nombre de lignes de la carte
    data.game->total_item = 2; // Nombre total d'items (C) sur la carte

    // Test de la fonction check_path
    if (check_path(&data)) {
        printf("Un chemin valide vers tous les items et la sortie existe.\n");
    } else {
        printf("Aucun chemin valide trouvé.\n");
    }

    return (0);
}*/

// int main()
// {
//     t_data data;
//     char *map_data[] = {
//         "111",
//         "1P1",
//         "1E1",
//         NULL
//     };

//     // Allocate and copy the map
//     data.map = malloc(4 * sizeof(char *)); // Allocate for 3 rows + NULL terminator
//     for (int i = 0; i < 3; ++i)
//     {
//         data.map[i] = strdup(map_data[i]);
//     }
//     data.map[3] = NULL; // Null-terminate the map array

//     // Validate the map
//     if (validate_map(&data))
//         printf("Map is valid.\n");
//     else
//         printf("Map is invalid.\n");

//     // Clean up
//     map_error(NULL, &data);

//     return 0;
// }

int	main(void)
{
	t_vars	vars;
	void	*img;
	int		width;
	int		height;

	width = 80;
	height = 80;
	vars.mlx_ptr = mlx_init();
	if (vars.mlx_ptr == NULL)
		return (ERR_MALLOC);
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, 900, 600, "so_long");
	if (vars.win_ptr == NULL)
	{
		free(vars.win_ptr);
		return (ERR_MALLOC);
	}
	img = mlx_xpm_file_to_image(vars.mlx_ptr, "images/player_image.xpm", &width, &height);
	if (!img)
	{
		perror("Failed to load image");
		mlx_destroy_window(vars.mlx_ptr, vars.win_ptr);
		mlx_destroy_display(vars.mlx_ptr);
		free(vars.mlx_ptr);
		return (ERR_MALLOC);
	}
	else
	{
		printf("Image loaded successfully\n");
	}
	mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, img, width, height);
	// mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, img, 0, 0);
	// mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, img, 450, 300);
	mlx_loop_hook(vars.mlx_ptr, &handle_no_event, &vars);
	mlx_hook(vars.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &vars);
	mlx_hook(vars.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &vars);
	mlx_loop(vars.mlx_ptr);
	mlx_destroy_image(vars.mlx_ptr, img);
	mlx_destroy_window(vars.mlx_ptr, vars.win_ptr);
	mlx_destroy_display(vars.mlx_ptr);
	free(vars.mlx_ptr);
	return (0);
}
