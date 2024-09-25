/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:16:39 by jmafueni          #+#    #+#             */
/*   Updated: 2024/09/25 16:30:49 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **tab)
{
    size_t	i;

	i = 0;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_vars(t_data *data)
{
	if (data->game)
	{
		free(data->game);
		data->game = NULL;
	}
	if (data->vars)
	{
		free(data->vars);
		data->vars = NULL;
	}
}
