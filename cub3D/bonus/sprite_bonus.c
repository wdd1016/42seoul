/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 23:43:27 by juyojeon          #+#    #+#             */
/*   Updated: 2023/09/20 22:11:35 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

typedef struct s_sprite_cast
{
	double	spr_x;
	double	spr_y;
	double	inv_det;
	double	t_form_x;
	double	t_form_y;
	int		spr_screen_x;
	int		spr_hgt;
	int		draw_start_y;
	int		draw_end_y;
	int		spr_width;
	int		draw_start_x;
	int		draw_end_x;
	int		tex_x;
	int		tex_y;
	int		x;
	int		y;
}	t_sprite_cast;

static void	set_sprite_cast_info(t_sprite_cast *info, t_player *player, \
								t_sprite *sprite);

void	sort_sprites(t_data *data)
{
	t_sprite	temp;
	int			i;
	int			j;

	i = -1;
	while (++i < data->num_sprites)
	{
		data->sprite[i].dist = ((data->player.x - data->sprite[i].x) * \
		(data->player.x - data->sprite[i].x) + (data->player.y - \
		data->sprite[i].y) * (data->player.y - data->sprite[i].y));
	}
	i = -1;
	while (++i < data->num_sprites - 1)
	{
		j = -1;
		while (++j < data->num_sprites - 1 - i)
		{
			if (data->sprite[j].dist < data->sprite[j + 1].dist)
			{
				temp = data->sprite[j];
				data->sprite[j] = data->sprite[j + 1];
				data->sprite[j + 1] = temp;
			}
		}
	}
}

void	input_sprite(t_data *data, t_img *s_img, t_sprite *sprite)
{
	t_sprite_cast	info;
	unsigned int	color;

	set_sprite_cast_info(&info, &data->player, sprite);
	info.x = info.draw_start_x - 1;
	while (++info.x < info.draw_end_x)
	{
		info.tex_x = (int)(256 * (info.x - (-info.spr_width / 2 \
		+ info.spr_screen_x)) * s_img->width / info.spr_width) / 256;
		if (info.t_form_y > 0 && info.x > 0 && info.x < WINDOW_WIDTH \
			&& info.t_form_y < (data->z_buffer)[info.x])
		{
			info.y = info.draw_start_y - 1;
			while (++info.y < info.draw_end_y)
			{
				info.tex_y = (((info.y * 256 - WINDOW_HEIGHT * 128 + \
				info.spr_hgt * 128) * s_img->height) / info.spr_hgt) / 256;
				color = *((unsigned int *)(s_img->addr + info.tex_y \
							* s_img->size_l + info.tex_x * (s_img->bpp / 8)));
				if ((color & 0x00FFFFFF) != 0)
					*((unsigned int *)(data->img.addr + info.y * \
					data->img.size_l + info.x * (data->img.bpp / 8))) = color;
			}
		}
	}
}

static void	set_sprite_cast_info(t_sprite_cast *info, t_player *player, \
								t_sprite *sprite)
{
	info->spr_x = sprite->x - player->x;
	info->spr_y = sprite->y - player->y;
	info->inv_det = 1.0 / (player->plane_x * player->dir_y \
					- player->dir_x * player->plane_y);
	info->t_form_x = info->inv_det * (player->dir_y * info->spr_x \
					- player->dir_x * info->spr_y);
	info->t_form_y = info->inv_det * (-player->plane_y * info->spr_x \
					+ player->plane_x * info->spr_y);
	info->spr_screen_x = (int)((WINDOW_WIDTH / 2) \
						* (1 + info->t_form_x / info->t_form_y));
	info->spr_hgt = abs((int)(WINDOW_HEIGHT / info->t_form_y));
	info->draw_start_y = (-info->spr_hgt / 2) + (WINDOW_HEIGHT / 2);
	if (info->draw_start_y < 0)
		info->draw_start_y = 0;
	info->draw_end_y = (info->spr_hgt / 2) + (WINDOW_HEIGHT / 2);
	if (info->draw_end_y >= WINDOW_HEIGHT)
		info->draw_end_y = WINDOW_HEIGHT - 1;
	info->spr_width = abs((int)(WINDOW_HEIGHT / info->t_form_y));
	info->draw_start_x = (-info->spr_width / 2) + info->spr_screen_x;
	if (info->draw_start_x < 0)
		info->draw_start_x = 0;
	info->draw_end_x = (info->spr_width / 2) + info->spr_screen_x;
	if (info->draw_end_x >= WINDOW_WIDTH)
		info->draw_end_x = WINDOW_WIDTH - 1;
}
