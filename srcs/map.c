/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:30:17 by juyojeon          #+#    #+#             */
/*   Updated: 2023/09/01 15:41:21 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/get_next_line.h"

void	ft_map_parsing(char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_exit("Map file open failed");
	texture_background_parsing(fd);
	coordinate_parsing(fd);
}

void	tetexture_background_parsing(int fd)
{
	while ()
}
