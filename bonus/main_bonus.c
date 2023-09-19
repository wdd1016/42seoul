/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:53:21 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/09/17 23:19:27 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int	print_image(t_data *data);
static void	free_linked_list(void *ptr, int type);
static void	free_allocated_data(t_data *data);

int	main(int argc, char *argv[])
{
	t_data	data;

	data_mlx_init(&data);
	if (argc != 2 || is_valid_format(argv[1], ".cub") == FAILURE)
		error_exit("Argument Error : [Usage] ./cub3D any.cub\n", &data);
	map_parsing(argv[1], &data);
	set_hooks(&data);
	mlx_loop_hook(data.mlx, print_image, &data);
	mlx_loop(data.mlx);
	free_allocated_data(&data);
	exit(EXIT_SUCCESS);
}

static int	print_image(t_data *data)
{
	int		x;
	int		y;
	double	turn_speed;

	if (data->mouse_mode_flag == TRUE)
	{
		mlx_mouse_get_pos(data->win, &x, &y);
		mlx_mouse_move(data->win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		if (x != WINDOW_WIDTH / 2)
		{
			turn_speed = sqrt((x - WINDOW_WIDTH / 2) * (x - WINDOW_WIDTH / 2) \
			+ (y - WINDOW_HEIGHT / 2) * (y - WINDOW_HEIGHT / 2)) / 100;
			if (x > WINDOW_WIDTH / 2)
				rotate_player(&data->player, turn_speed);
			else if (x < WINDOW_WIDTH / 2)
				rotate_player(&data->player, -turn_speed);
		}
	}
	rendering_image(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}

void	error_exit(const char *str, t_data *data)
{
	int		i;

	write(2, str, ft_strlen(str));
	if (data->map)
	{
		i = -1;
		while (++i < data->map_height)
			free(data->map[i]);
		free(data->map);
	}
	if (data->tempmap)
		free_linked_list(data->tempmap, 0);
	if (data->door)
		free_linked_list(data->door, 1);
	exit(EXIT_FAILURE);
}

static void	free_linked_list(void *ptr, int type)
{
	t_map	*temp;
	t_door	*temp_door;

	if (type == 0)
	{
		while (ptr)
		{
			temp = ptr;
			if (temp->line)
				free(temp->line);
			ptr = temp->next;
			free(temp);
		}
	}
	else if (type == 1)
	{
		while (ptr)
		{
			temp_door = ptr;
			ptr = temp_door->next;
			free(temp_door);
		}
	}
}

static void	free_allocated_data(t_data *data)
{
	t_map	*temp;
	int		i;

	if (data->map)
	{
		i = -1;
		while (++i < data->map_height)
			free(data->map[i]);
		free(data->map);
	}
	if (data->tempmap)
	{
		while (data->tempmap)
		{
			temp = data->tempmap;
			if (temp->line)
				free(temp->line);
			data->tempmap = data->tempmap->next;
			free(temp);
		}
	}
}
