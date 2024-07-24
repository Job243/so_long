/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:03:29 by jmafueni          #+#    #+#             */
/*   Updated: 2024/07/24 15:49:50 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int file_exists(const char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return 0;
	}
	close(fd);
	return (1);
}

char *read_file(const char *filename)
{
	int fd;
	int bytes_read;
	char *buffer;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return NULL;
	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return NULL;
	bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
	if (bytes_read <= 0)
	{
		free(buffer);
		close(fd);
		return NULL;
	}
	buffer[bytes_read] = '\0';
	close(fd);
	return (buffer);
}
