/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:20:52 by juyojeon          #+#    #+#             */
/*   Updated: 2023/09/11 22:16:04 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	print_image(t_data *data)
{
	print_background(data);
	ray_casting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

void	ray_casting(t_data *data)
{
	int	h;
	int	i;
	
	//length of ray from current position to next x or y-side
    double sidedist_x;
    double sidedist_y;
	double deltaDistX;
	double deltaDistY;
    double perpWallDist;
	//what direction to step in x or y-direction (either +1 or -1)
	int stepX;
	int stepY;
	//was there a wall hit?
	int	hit;
	//was a NS or a EW wall hit?
	int	side;
	int line_h;
	
	int drawStart;
	int drawEnd;
;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		camera_x = 2 * i / (double)(WINDOW_WIDTH - 1) - 1;
		raydir_x = data->player.dir_x + data->player.plane_x * camera_x;
		raydir_y = data->player.dir_y + data->player.plane_y * camera_x;
		// DDA 알고리즘		

       //length of ray from one x or y-side to next x or y-side
		deltaDistX = fabs(1 / raydir_x);
		deltaDistY = fabs(1 / raydir_y);

      //calculate step and initial sideDist
      if (raydir_x < 0)
      {
        stepX = -1;
        sidedist_x = (data->player.x - (int)data->player.x) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sidedist_x = ((int)data->player.x + 1.0 - data->player.x) * deltaDistX;
      }
      if (raydir_y < 0)
      {
        stepY = -1;
        sidedist_y = (data->player.y - (int)data->player.y) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sidedist_y = ((int)data->player.y + 1.0 - data->player.y) * deltaDistY;
      }
    
	  //perform DDA
	hit = 0;
      while (hit == 0)
      {
        //jump to next map square, OR in x-direction, OR in y-direction
        if (sidedist_x < sidedist_y)
        {
          sidedist_x += deltaDistX;
          (int)data->player.x += stepX;
          side = 0;
        }
        else
        {
          sidedist_y += deltaDistY;
          (int)data->player.y += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if (map[(int)data->player.x][(int)data->player.y] > 0)
			hit = 1;
      }
		if(side == 0)
			perpWallDist = (sidedist_x - deltaDistX);
      	else
			perpWallDist = (sidedist_y - deltaDistY);

      //Calculate height of line to draw on screen
      line_h = (int)(h / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
	drawStart = -line_h / 2 + h / 2;
      if (drawStart < 0)
	  	drawStart = 0;
	drawEnd = line_h / 2 + h / 2;
      if (drawEnd >= h)
	  	drawEnd = h - 1;

      //choose wall color
	int	rgb;
	rgb = 204 << 16 | 255 << 8 | 255;

		//give x and y sides different brightness
		if (side == 1)
			rgb = rgb / 2;

		//draw the pixels of the stripe as a vertical line
		int	y = drawStart;
		char	*dst;
		while (y < drawEnd)
		{
			dst = data->addr + (y * data->line_length + i * (data->bits_per_pixel / 8));
			*(unsigned int *)dst = rgb;
			y++;
		}
		i++;	
	}
	return (0);
}

void	print_background(t_data *data)
{
	int		color;
	char	*dst;
	int		i;

	dst = data->img.data;
	i = 0;
	color = data->ceiling_color;
	while (i < WINDOW_WIDTH * WINDOW_HEIGHT / 2)
	{
		*(unsigned int *)dst = color;
		dst += data->img.bpp / 8;
		i++;
	}
	color = data->floor_color;
	while (i < WINDOW_WIDTH * WINDOW_HEIGHT)
	{
		*(unsigned int *)dst = color;
		dst += data->img.bpp / 8;
		i++;
	}
}
