/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:53:21 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/09/12 15:47:32 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/cub3d.h"
# include "./mlx/mlx.h"
# include <errno.h>
# include <string.h>

// #define mapWidth 24
// #define mapHeight 24

// # define MAP_NUM_ROWS 24
// # define MAP_NUM_COLS 24

// # define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
// # define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

# define FPS 30	// Frames Per Second

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
	// double	sidedist_x;
	// double	sidedist_y;
	double	moveSpeed;
	double	rotSpeed;
	// t_img		img;
	// int			map[MAP_NUM_ROWS][MAP_NUM_COLS];
	t_player	player;
	// t_ray		rays[NUM_RAYS];
	t_texture	texture[NUM_TEXTURES];
	float		*z_buffer;
}	t_data;

// enum e_xevent
// {
// 	DESTROY = 17,
// 	KEY_W  = 13,
// 	KEY_A  = 0,
// 	KEY_S = 1,
// 	KEY_D = 2,
// 	KEY_LEFT = 123,
// 	KEY_RIGHT = 124,
// 	KEY_ESC = 53
// };

// int	map[MAP_NUM_ROWS][MAP_NUM_COLS]=
// {
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
//   {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
//   {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,0,0,0,0,'N',0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};

int	ray_casting(t_data *data)
{
	
	int	mapX;
	int	mapY;
	int	w;
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
        sidedist_x = (data->player.x - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sidedist_x = (mapX + 1.0 - data->player.x) * deltaDistX;
      }
      if (data->rayDirY < 0)
      {
        stepY = -1;
        sidedist_y = (data->player.y - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sidedist_y = (mapY + 1.0 - data->player.y) * deltaDistY;
      }
    
	  //perform DDA
	hit = 0;
      while (hit == 0)
      {
        //jump to next map square, OR in x-direction, OR in y-direction
        if (sidedist_x < sidedist_y)
        {
          sidedist_x += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sidedist_y += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if (map[mapX][mapY] > 0)
			hit = 1;
      }
		if(side == 0)
			perpWallDist = (sidedist_x - deltaDistX);
      	else
			perpWallDist = (sidedist_y - deltaDistY);

	        //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		// if (side == 0)
		// 	perpWallDist = (mapX - x + (1 - stepX) / 2) / rayDirX;
		// else
		// 	perpWallDist = (mapY - data->player.y + (1 - stepY) / 2) / rayDirY;

      //Calculate height of line to draw on screen
      line_h = (int)(h / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
	drawStart = -line_h / 2 + h / 2;
      if (drawStart < 0)
	  	drawStart = 0;
	drawEnd = line_h / 2 + h / 2;
      if (drawEnd >= h)
	  	drawEnd = h - 1;

	int	rgb;
	rgb = 204 << 16 | 255 << 8 | 255;
	//give x and y sides different brightness
	if (side == 1)
		rgb = rgb / 2;

      //texturing calculations
      int texNum = map[mapX][mapY] - 1; //1 subtracted from it so that texture 0 can be used!

      //calculate value of wallX
      double wallX; //where exactly the wall was hit
      if (side == 0) wallX = posY + perpWallDist * rayDirY;
      else           wallX = posX + perpWallDist * rayDirX;
      wallX -= floor((wallX));

      //x coordinate on the texture
      int texX = int(wallX * double(texWidth));
      if(side == 0 && rayDirX > 0) texX = texWidth - texX - 1;
      if(side == 1 && rayDirY < 0) texX = texWidth - texX - 1;

            // How much to increase the texture coordinate per screen pixel
      double step = 1.0 * texHeight / lineHeight;
      // Starting texture coordinate
      double texPos = (drawStart - h / 2 + lineHeight / 2) * step;
      for(int y = drawStart; y<drawEnd; y++)
      {
        // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
        int texY = (int)texPos & (texHeight - 1);
        texPos += step;
        Uint32 color = texture[texNum][texHeight * texY + texX];
        //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
        if(side == 1) color = (color >> 1) & 8355711;
        buffer[y][x] = color;
      }
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
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D"); //창 식별자
	if (!data->win)
		error_exit(ENOMEM);
	data->img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
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