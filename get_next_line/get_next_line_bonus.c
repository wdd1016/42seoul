/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:10:23 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/23 00:26:11 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_buffer	*ft_make_gnl_struct(t_buffer **gnl, int fd);
static char		*ft_handle_buffer(t_buffer **gnl, t_buffer *u_gnl);
static char		*ft_process_string(t_buffer **gnl, t_buffer *u_gnl);
static char		*ft_gnl_free(t_buffer **gnl, t_buffer *u_gnl, int num, \
char *fre);

char	*get_next_line(int fd)
{
	static t_buffer	*gnl = 0;
	t_buffer		*u_gnl;
	int				num_list;

	num_list = 0;
	if (!gnl)
	{
		if (!ft_make_gnl_struct(&gnl, fd))
			return (0);
		return (ft_handle_buffer(&gnl, gnl));
	}
	u_gnl = gnl;
	while (u_gnl->next && u_gnl->fd_num != fd)
		u_gnl = u_gnl->next;
	if (u_gnl->fd_num != fd)
	{
		u_gnl = ft_make_gnl_struct(&gnl, fd);
		if (u_gnl == 0)
			return (ft_gnl_free(&gnl, u_gnl, ALL, 0));
	}
	return (ft_handle_buffer(&gnl, u_gnl));
}

static t_buffer	*ft_make_gnl_struct(t_buffer **gnl, int fd)
{
	t_buffer	*new_gnl;
	t_buffer	*temp;

	new_gnl = (t_buffer *)ft_calloc(1, sizeof(t_buffer));
	if (!new_gnl)
		return (0);
	new_gnl->fd_num = fd;
	if (*gnl == 0)
		*gnl = new_gnl;
	else
	{
		temp = *gnl;
		while (temp->next)
			temp = temp->next;
		temp->next = new_gnl;
	}
	return (new_gnl);
}

static char	*ft_handle_buffer(t_buffer **gnl, t_buffer *u_gnl)
{
	char	*str_new;
	char	*str_temp;
	ssize_t	state;

	u_gnl->last_idx = ft_strchr_idx(u_gnl->buffer, '\n');
	while (u_gnl->last_idx == -1 && u_gnl->f_st == NORMAL)
	{
		str_new = (char *)ft_calloc(1, BUFFER_SIZE + 1);
		if (!str_new)
			return (ft_gnl_free(gnl, u_gnl, ALL, 0));
		state = read(u_gnl->fd_num, str_new, BUFFER_SIZE);
		if (state < 0)
			return (ft_gnl_free(gnl, u_gnl, CURRENT, str_new));
		else if (state < BUFFER_SIZE)
			u_gnl->f_st = EOFS;
		if (state > 0 && u_gnl->buffer)
		{
			str_temp = u_gnl->buffer;
			u_gnl->buffer = ft_strjoin_free(u_gnl->buffer, str_new);
			free(str_temp);
			free(str_new);
		}
		else if (state == 0)
		{
			free(str_new);
		}
		else if (state > 0)
			u_gnl->buffer = str_new;
		u_gnl->last_idx = ft_strchr_idx(u_gnl->buffer, '\n');
	}
	str_temp = u_gnl->buffer;
	if ((u_gnl->f_st == EOFS && u_gnl->last_idx == -1) || \
	(u_gnl->buffer)[u_gnl->last_idx + 1] == '\0')
		ft_gnl_free(gnl, u_gnl, CURRENT, 0);
	else
		str_temp = ft_process_string(gnl, u_gnl);
	return (str_temp);
}

static char	*ft_process_string(t_buffer **gnl, t_buffer *u_gnl)
{
	char	*str_return;
	char	*str_split;
	char	*str_buftemp;
	char	*str_restemp;
	int		size;

	str_buftemp = u_gnl->buffer;
	size = u_gnl->last_idx + 1;
	str_return = (char *)ft_calloc(1, size + 1);
	if (!str_return)
		return (ft_gnl_free(gnl, u_gnl, ALL, 0));
	str_restemp = str_return;
	while (size-- > 0)
		*str_restemp++ = *str_buftemp++;
	size = ft_strlen(u_gnl->buffer) - (u_gnl->last_idx + 1);
	str_split = (char *)ft_calloc(1, size + 1);
	if (!str_split)
		return (ft_gnl_free(gnl, u_gnl, ALL, str_return));
	str_restemp = str_split;
	while (size-- > 0)
		*str_restemp++ = *str_buftemp++;
	str_buftemp = u_gnl->buffer;
	u_gnl->buffer = str_split;
	free(str_buftemp);
	return (str_return);
}

static char	*ft_gnl_free(t_buffer **gnl, t_buffer *u_gnl, int num, char *fre)
{
	t_buffer	*temp_b;

	if (fre)
		free(fre);
	if (num == ALL)
	{
		while (*gnl)
		{
			temp_b = *gnl;
			*gnl = (*gnl)->next;
			free(temp_b->buffer);
			free(temp_b);
		}
	}
	else if (num == CURRENT)
	{
		temp_b = *gnl;
		while (temp_b->next != 0 && temp_b->next != u_gnl)
			temp_b = temp_b->next;
		temp_b->next = u_gnl->next;
		if (*gnl == u_gnl)
			*gnl = 0;
		free(u_gnl);
	}
	return (0);
}
