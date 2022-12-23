/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:10:23 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/23 17:44:57 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_buffer	*ft_make_gnl_struct(t_buffer *gnl, int fd);
static char		*ft_handle_buffer(t_buffer **gnl, t_buffer *u_gnl, \
ssize_t len, char *str_temp);
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
		gnl = ft_make_gnl_struct(gnl, fd);
		if (gnl == 0)
			return (0);
		return (ft_handle_buffer(&gnl, gnl, BUFFER_SIZE, 0));
	}
	u_gnl = gnl;
	while (u_gnl && u_gnl->fd_num != fd)
		u_gnl = u_gnl->next;
	if (!u_gnl)
	{
		u_gnl = ft_make_gnl_struct(gnl, fd);
		if (u_gnl == 0)
			return (ft_gnl_free(&gnl, u_gnl, ALL, 0));
	}
	return (ft_handle_buffer(&gnl, u_gnl, BUFFER_SIZE, 0));
}

static t_buffer	*ft_make_gnl_struct(t_buffer *gnl, int fd)
{
	t_buffer		*new_gnl;
	t_buffer		*temp;
	unsigned int	temp_idx;
	char			*temp_zero;

	new_gnl = (t_buffer *)malloc(sizeof(t_buffer));
	if (!new_gnl)
		return (0);
	temp_idx = 0;
	temp_zero = (char *)new_gnl;
	while (temp_idx < sizeof(t_buffer))
		temp_zero[temp_idx++] = 0;
	new_gnl->fd_num = fd;
	if (gnl != 0)
	{
		temp = gnl;
		while (temp->next)
			temp = temp->next;
		temp->next = new_gnl;
	}
	return (new_gnl);
}
/* struct make & add_back */

static char	*ft_handle_buffer(t_buffer **gnl, t_buffer *u_gnl, \
ssize_t len, char *str_temp)
{
	u_gnl->last_idx = ft_strchr_idx(u_gnl->buffer, '\n');
	while (u_gnl->last_idx == ERROR && len == BUFFER_SIZE)
	{
		str_temp = (char *)malloc(BUFFER_SIZE + 1);
		if (!str_temp)
			return (ft_gnl_free(gnl, u_gnl, ALL, 0));
		len = read(u_gnl->fd_num, str_temp, BUFFER_SIZE);
		if (len == ERROR)
			return (ft_gnl_free(gnl, u_gnl, CURRENT, str_temp));
		str_temp[len] = '\0';
		if (len == 0)
			free(str_temp);
		else if (len > 0 && u_gnl->buffer == 0)
			u_gnl->buffer = str_temp;
		else
			if (ft_strjoin_free_change(u_gnl, u_gnl->buffer, str_temp) == 0)
				return (ft_gnl_free(gnl, u_gnl, ALL, 0));
		u_gnl->last_idx = ft_strchr_idx(u_gnl->buffer, '\n');
	}
	if (u_gnl->last_idx == ERROR)
		u_gnl->last_idx = ft_strlen(u_gnl->buffer) - 1;
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
	str_return = (char *)malloc(u_gnl->last_idx + 2);
	if (!str_return)
		return (ft_gnl_free(gnl, u_gnl, ALL, 0));
	ft_strlcpy(str_return, str_temp, u_gnl->last_idx + 2);
	str_temp += u_gnl->last_idx + 1;
	if (*str_temp == '\0')
	{
		free(u_gnl->buffer);
		u_gnl->buffer = 0;
		return (str_return);
	}
	len = ft_strlen(u_gnl->buffer) - (u_gnl->last_idx + 1);
	str_split = (char *)malloc(len + 1);
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

	free(str_for_free);
	if (num == CURRENT)
	{
		temp_b = *gnl;
		while (temp_b && temp_b->next != u_gnl)
			temp_b = temp_b->next;
		if (temp_b)
			temp_b->next = u_gnl->next;
		if (*gnl == u_gnl)
			*gnl = (*gnl)->next;
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