/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:53:21 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/09/09 21:54:58 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/cub3d.h"
# include "../mlx/mlx.h"
# include <errno.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

// #define mapWidth 24
// #define mapHeight 24
#define screenWidth 1280
#define screenHeight 768

// # define TILE_SIZE 64
# define MAP_NUM_ROWS 24
# define MAP_NUM_COLS 24

// # define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
// # define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define NUM_TEXTURES 5

# define FPS 30	// Frames Per Second

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_player
{
	double	x;
	double	y;
	float	width;
	float	height;
	int		turn_direction;
	int		walk_direction;
	float	rotation_angle;
	float	walk_speed;
	float	turn_speed;
}	t_player;

typedef struct s_ray
{
	float	ray_angle;
	float	wall_hit_x;
	float	wall_hit_y;
	float	distance;
	int		was_hit_vertical;
	int		is_ray_facing_up;
	int		is_ray_facing_down;
	int		is_ray_facing_left;
	int		is_ray_facing_right;
	int		wall_hit_content;	
}	t_ray;

typedef struct s_texture
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		width;
	int		height;
}	t_texture;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	cameraX;
	double	dirX;
	double	dirY;
	double	rayDirX;
	double	rayDirY;
	double	planeX;
	double	planeY;
	double	sideDistX;
	double	sideDistY;
	double	moveSpeed;
	double	rotSpeed;
	// t_img		img;
	// int			map[MAP_NUM_ROWS][MAP_NUM_COLS];
	t_player	player;
	// t_ray		rays[NUM_RAYS];
	t_texture	texture[NUM_TEXTURES];
	float		*z_buffer;
}	t_data;

enum e_xevent
{
	DESTROY = 17,
	KEY_W  = 13,
	KEY_A  = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_ESC = 53
};

int	map[MAP_NUM_ROWS][MAP_NUM_COLS]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,'N',0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};

int	ray_casting(t_data *data)
{
	
	// int	buffer[screenHeight][screenWidth];
	int	mapX;
	int	mapY;
	int	w;
	int	h;
	int	i;
	
	//length of ray from current position to next x or y-side
    double sideDistX;
    double sideDistY;
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
	int lineHeight;
	
	w = screenWidth;
	h = screenHeight;

	lineHeight = (int)(h / 2);

	//calculate lowest and highest pixel to fill in current stripe
	int drawStart;
	int drawEnd;	
	int	bg_rgb;

	i = 0;
	while (i < w)
	{
		int	y = 0;
		char	*dst;
		while (y < h)
		{
			if (y < h / 2)
				bg_rgb = 0;
			else
				bg_rgb = 255 << 16 | 255 << 8 | 255;

			dst = data->addr + (y * data->line_length + i * (data->bits_per_pixel / 8));
			*(unsigned int *)dst = bg_rgb;
			y++;
		}
		i++;
	}

	
	i = 0;
 	while (i < w)
    {
		// 스크린의 모든 x값(수직선)에 대해 계산

      //calculate ray position and direction
		data->cameraX = 2 * i / (double)w - 1; //x-coordinate in camera space
		data->rayDirX = data->dirX + data->planeX * data->cameraX;
		data->rayDirY = data->dirY + data->planeY * data->cameraX;

		// DDA 알고리즘
		
      //which box of the map we're in
		mapX = (int)data->player.x;
		mapY = (int)data->player.y;

       //length of ray from one x or y-side to next x or y-side
		deltaDistX = fabs(1 / data->rayDirX);
		deltaDistY = fabs(1 / data->rayDirY);

      //calculate step and initial sideDist
      if (data->rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (data->player.x - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - data->player.x) * deltaDistX;
      }
      if (data->rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (data->player.y - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - data->player.y) * deltaDistY;
      }
    
	  //perform DDA
	hit = 0;
      while (hit == 0)
      {
        //jump to next map square, OR in x-direction, OR in y-direction
        if (sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if (map[mapX][mapY] > 0)
			hit = 1;
      }
		if(side == 0)
			perpWallDist = (sideDistX - deltaDistX);
      	else
			perpWallDist = (sideDistY - deltaDistY);

	        //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		// if (side == 0)
		// 	perpWallDist = (mapX - x + (1 - stepX) / 2) / rayDirX;
		// else
		// 	perpWallDist = (mapY - data->player.y + (1 - stepY) / 2) / rayDirY;

      //Calculate height of line to draw on screen
      lineHeight = (int)(h / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
	drawStart = -lineHeight / 2 + h / 2;
      if (drawStart < 0)
	  	drawStart = 0;
	drawEnd = lineHeight / 2 + h / 2;
      if (drawEnd >= h)
	  	drawEnd = h - 1;

      //choose wall color
	int	rgb;
	rgb = 204 << 16 | 255 << 8 | 255;

	// if (map[mapX][mapY] == 1)
	// 	rgb = 204 << 16 | 255 << 8 | 255;
	// else if (map[mapX][mapY] == 2)
	// 	rgb = 204 << 16 | 204 << 8 | 255;
	// else if (map[mapX][mapY] == 3)
	// 	rgb = 204 << 16 | 255 << 8 | 255;
	// else if (map[mapX][mapY] == 4)
	// 	rgb = 204 << 16 | 255 << 8 | 204;
	// else
	// 	rgb = 204 << 16 | 255 << 8 | 0;

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
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	key_event(int key, t_data *data)
{
	double	oldDirX;
	double	oldPlaneX;
	
	if (key == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	else if (key == KEY_LEFT)
	{
//both camera direction and camera plane must be rotated
		oldDirX = data->dirX;
      	data->dirX = data->dirX * cos(data->rotSpeed) - data->dirY * sin(data->rotSpeed);
      	data->dirY = oldDirX * sin(data->rotSpeed) + data->dirY * cos(data->rotSpeed);
		oldPlaneX = data->planeX;
      	data->planeX = data->planeX * cos(data->rotSpeed) - data->planeY * sin(data->rotSpeed);
      	data->planeY = oldPlaneX * sin(data->rotSpeed) + data->planeY * cos(data->rotSpeed);
	}
	else if (key == KEY_RIGHT)
	{
   //both camera direction and camera plane must be rotated
		oldDirX = data->dirX;
      	data->dirX = data->dirX * cos(-data->rotSpeed) - data->dirY * sin(-data->rotSpeed);
      	data->dirY = oldDirX * sin(-data->rotSpeed) + data->dirY * cos(-data->rotSpeed);
		oldPlaneX = data->planeX;
     	data->planeX = data->planeX * cos(-data->rotSpeed) - data->planeY * sin(-data->rotSpeed);
      	data->planeY = oldPlaneX * sin(-data->rotSpeed) + data->planeY * cos(-data->rotSpeed);
	}
	else if (key == KEY_W)
	{
 		if(map[(int)(data->player.x + data->dirX * data->moveSpeed)][(int)data->player.y] == 0)
			data->player.x += data->dirX * data->moveSpeed;
      	if(map[(int)data->player.x][(int)(data->player.y + data->dirY * data->moveSpeed)] == 0)
			data->player.y += data->dirY * data->moveSpeed;
	}
	else if (key == KEY_A)
	{
 		if(map[(int)(data->player.x - data->dirX * data->moveSpeed)][(int)data->player.y] == 0)
			data->player.x -= data->dirX * data->moveSpeed;
      	if(map[(int)data->player.x][(int)(data->player.y - data->dirY * data->moveSpeed)] == 0)
			data->player.y -= data->dirY * data->moveSpeed;
	}
	else if (key == KEY_S)
	{

	}
	else if (key == KEY_D)
	{
		
	}
	return (0);
}

int	window_event(void)
{
	exit(0);
}

void	set_hook(t_data *data)
{
	mlx_key_hook(data->win, key_event, data); //esc key press event
	mlx_hook(data->win, DESTROY, 0, window_event, data); //close button press event
}

void	error_exit(int ernum)
{
	perror(strerror(ernum));
	exit(1);
}

void	init_data(t_data *data)
{
	data->mlx = mlx_init(); //그래픽 시스템에 연결. 연결 식별자.
	if (!data->mlx)
		error_exit(ENOMEM);
	data->win = mlx_new_window(data->mlx, screenWidth, screenHeight, "cub3D"); //창 식별자
	if (!data->win)
		error_exit(ENOMEM);
	data->img = mlx_new_image(data->mlx, screenWidth, screenHeight);
	if (!data->img)
		error_exit(ENOMEM);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
									&data->line_length, &data->endian);
										//x and y start position
	data->player.x = 22;
	data->player.y = 12;
	
	//initial direction vector
	data->dirX = -1;
	data->dirY = 0;

	//the 2d raycaster version of camera plane
	data->planeX = 0;
	data->planeY = 0.66;

	// double time = 0; //time of current frame
	// double oldTime = 0; //time of previous frame
	
	 //speed modifiers
	data->moveSpeed = FPS * 5.0; //the constant value is in squares/second
	data->rotSpeed = FPS * 3.0; //the constant value is in radians/second
}

int	main(int argc, char **argv)
{
	t_data	data;
	
	argv = 0;
	if (argc > 1)
		return (1);
	init_data(&data);
	set_hook(&data);
	ray_casting(&data);
	mlx_loop_hook(data.mlx, ray_casting, &data);
	mlx_loop(data.mlx); //rendering
	mlx_destroy_window(data.mlx, data.win);
	return (0);
}