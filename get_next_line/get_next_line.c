/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:10:23 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/23 13:00:48 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_buffer	*ft_make_gnl_struct(t_buffer **gnl, int fd);
static char		*ft_handle_buffer(t_buffer **gnl, t_buffer *u_gnl, ssize_t len);
static char		*ft_cutting_string(t_buffer **gnl, t_buffer *u_gnl, int len);
static char		*ft_gnl_free(t_buffer **gnl, t_buffer *u_gnl, int num, \
char *str_for_free);

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
		return (ft_handle_buffer(&gnl, gnl, BUFFER_SIZE));
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
	return (ft_handle_buffer(&gnl, u_gnl, BUFFER_SIZE));
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
/* struct make & add_back */

static char	*ft_handle_buffer(t_buffer **gnl, t_buffer *u_gnl, ssize_t len)
{
	char	*str_temp;

	u_gnl->last_idx = ft_strchr_idx(u_gnl->buffer, '\n');
	while (u_gnl->last_idx == ERROR && len == BUFFER_SIZE)
	{
		str_temp = (char *)ft_calloc(1, BUFFER_SIZE + 1);
		if (!str_temp)
			return (ft_gnl_free(gnl, u_gnl, ALL, 0));
		len = read(u_gnl->fd_num, str_temp, BUFFER_SIZE);
		if (len == ERROR)
			return (ft_gnl_free(gnl, u_gnl, CURRENT, str_temp));
		else if (len == 0)
			free(str_temp);
		else if (len > 0 && u_gnl->buffer == 0)
			u_gnl->buffer = str_temp;
		else
			u_gnl->buffer = ft_strjoin_free(u_gnl->buffer, str_temp);
		u_gnl->last_idx = ft_strchr_idx(u_gnl->buffer, '\n');
	}
	if (u_gnl->last_idx == ERROR)
		u_gnl->last_idx = ft_strlen(u_gnl->buffer);
	if (u_gnl->buffer)
		return (ft_cutting_string(gnl, u_gnl, 0));
	else
		return (ft_gnl_free(gnl, u_gnl, CURRENT, 0));
}
/* dynamic allocation error : all structs free <-> */
/* read error : current struct free */

static char	*ft_cutting_string(t_buffer **gnl, t_buffer *u_gnl, int len)
{
	char	*str_return;
	char	*str_split;
	char	*str_temp;

	str_temp = u_gnl->buffer;
	str_return = (char *)ft_calloc(1, u_gnl->last_idx + 2);
	if (!str_return)
		return (ft_gnl_free(gnl, u_gnl, ALL, 0));
	ft_strlcpy(str_return, str_temp, u_gnl->last_idx + 2);
	str_temp += u_gnl->last_idx + 1;
	if (*str_temp == '\0')
	{
		ft_gnl_free(gnl, u_gnl, CURRENT, 0);
		return (str_return);
	}
	len = ft_strlen(u_gnl->buffer) - (u_gnl->last_idx + 1);
	str_split = (char *)ft_calloc(1, len + 1);
	if (!str_split)
		return (ft_gnl_free(gnl, u_gnl, ALL, str_return));
	ft_strlcpy(str_split, str_temp, len + 1);
	str_temp = u_gnl->buffer;
	u_gnl->buffer = str_split;
	free(str_temp);
	return (str_return);
}
/* make return string & remaining string
if remaining string = 0 -> current struct free */

static char	*ft_gnl_free(t_buffer **gnl, t_buffer *u_gnl, int num, \
char *str_for_free)
{
	t_buffer	*temp_b;

	if (str_for_free)
		free(str_for_free);
	if (num == CURRENT)
	{
		temp_b = *gnl;
		while (temp_b->next != 0 && temp_b->next != u_gnl)
			temp_b = temp_b->next;
		temp_b->next = u_gnl->next;
		if (*gnl == u_gnl)
			*gnl = 0;
		if (u_gnl->buffer)
			free(u_gnl->buffer);
		free(u_gnl);
		return (0);
	}
	while (*gnl)
	{
		temp_b = *gnl;
		*gnl = (*gnl)->next;
		free(temp_b->buffer);
		free(temp_b);
	}
	return (0);
}
/* num : all - all structs free, current - current fd struct free */