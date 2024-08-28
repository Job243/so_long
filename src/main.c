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

/*int	handle_no_event(void *data)
{
	return (0);
}

int	handle_input(int key, t_vars *vars)
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

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*int main() {
    // Example of a valid map
    char *valid_map[] = {
        "11111",
        "1P0C1",
        "1C0E1",
        "11111",
        NULL
    };

    // Example of an invalid map with no collectibles
    char *invalid_map_no_collectibles[] = {
        "11111",
        "1P0E1",
        "11111",
        NULL
    };

    // Example of an invalid map with more than one exit
    char *invalid_map_multiple_exits[] = {
        "11111",
        "1P0E1",
        "1E0E1",
        "11111",
        NULL
    };

    // Example of an invalid map with more than one start position
    char *invalid_map_multiple_starts[] = {
        "11111",
        "1PP01",
        "1C0E1",
        "11111",
        NULL
    };

    // Test valid map
    printf("Testing valid map:\n");
    if (validate_char(valid_map)) {
        printf("The valid map passes character validation.\n");
    } else {
        printf("The valid map fails character validation.\n");
    }

    // Test map with no collectibles
    printf("\nTesting map with no collectibles:\n");
    if (validate_char(invalid_map_no_collectibles)) {
        printf("The map with no collectibles passes character validation.\n");
    } else {
        printf("The map with no collectibles fails character validation.\n");
    }

    // Test map with multiple exits
    printf("\nTesting map with multiple exits:\n");
    if (validate_char(invalid_map_multiple_exits)) {
        printf("The map with multiple exits passes character validation.\n");
    } else {
        printf("The map with multiple exits fails character validation.\n");
    }

    // Test map with multiple start positions
    printf("\nTesting map with multiple start positions:\n");
    if (validate_char(invalid_map_multiple_starts)) {
        printf("The map with multiple start positions passes character validation.\n");
    } else {
        printf("The map with multiple start positions fails character validation.\n");
    }

    return 0;
}*/

/*int	main(void)
{
	t_vars	vars;
	// void	*img;
	// int		width;
	// int		height;

	// width = 80;
	// height = 80;
	vars.mlx_ptr = mlx_init();
	if (vars.mlx_ptr == NULL)
		return (ERR_MALLOC);
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, 900, 600, "so_long");
	if (vars.win_ptr == NULL)
	{
		free(vars.win_ptr);
		return (ERR_MALLOC);
	}
	// img = mlx_xpm_file_to_image(vars.mlx_ptr, "../images/FinnSprite.xpm", &width, &height);
	// if (!img)
	// 	printf("1\n");
	// mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, img, 80, 80);
	// mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, img, 0, 0);
	// mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, img, 450, 300);
	mlx_loop_hook(vars.mlx_ptr, &handle_no_event, &vars);
	mlx_hook(vars.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &vars);
	mlx_hook(vars.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &vars);
	mlx_loop(vars.mlx_ptr);
	//mlx_destroy_image(vars.mlx_ptr, img);
	mlx_destroy_window(vars.mlx_ptr, vars.win_ptr);
	mlx_destroy_display(vars.mlx_ptr);
	free(vars.mlx_ptr);
	return (0);
}*/
