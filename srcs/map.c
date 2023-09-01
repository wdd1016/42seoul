/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:30:17 by juyojeon          #+#    #+#             */
/*   Updated: 2023/09/01 17:48:08 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	texture_background_parsing(int fd, int line_num);

void	ft_map_parsing(char *path, t_data *data)
{
	int	fd;
	int	i;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_exit("Error : Map file open failed\n");
	i = 0;
	while (++i <= 4)
		texture_background_parsing(fd, i);
	coordinate_parsing(fd);
}

static void	texture_background_parsing(int fd, int line_num)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		error_exit("Error : Map file parsing failed\n");
	// if (line_num == 1 && line[0] == 'N' && line[1] == 'O')
	// 	 mlx_xpm_file_to_image()
	// else if (line_num == 2 && line[0] == 'S' && line[1] == 'O')
	// 	ft_texture_parsing(line, &g_texture[1]);
	// else if (line_num == 3 && line[0] == 'W' && line[1] == 'E')
	// 	ft_texture_parsing(line, &g_texture[2]);
	// else if (line_num == 4 && line[0] == 'E' && line[1] == 'A')
	// 	ft_texture_parsing(line, &g_texture[3]);
	// else
	// 	error_exit("Error : Map file parsing failed\n");
}
