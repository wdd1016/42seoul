/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:30:17 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/24 17:53:39 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

void	map_parsing(char *path)
{
	int		fd;

	if (ft_strnstr(path, ".cub", ft_strlen(path)) != ft_strlen(path) - 4)
		error_exit("Map file extension must be .cub");
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_exit("Map file open failed");
	texture_background_parsing(fd);
	coordinate_parsing(fd);
}

