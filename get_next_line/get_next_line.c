/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:10:23 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/16 08:15:11 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_handle_buffer(t_buffer *gnl, t_buffer *use_gnl, char *n_buffer, \
int *num_list);
static char	*ft_new_buffer(t_buffer *gnl, t_buffer *use_gnl, int *num_list);
static t_buffer	*ft_make_gnl_struct(t_buffer *gnl, int fd);
static char	*ft_gnl_free_anyway(t_buffer *gnl, t_buffer *use_gnl, int num, \
char *returnstring);

char	*get_next_line(int fd)
{
	static t_buffer	*gnl;
	t_buffer		*use_gnl;
	int				num_list;

	num_list = 0;
	if (!gnl)
	{
		gnl = ft_make_gnl_struct(gnl, fd);
		if (!gnl)
			return (0);
		return (ft_new_buffer(gnl, gnl, num_list));
	}
	use_gnl = gnl;
	while (use_gnl->fd_num != fd && use_gnl)
		use_gnl = use_gnl->next;
	if (!use_gnl)
	{
		use_gnl = ft_make_gnl_struct(gnl, fd);
		if (!use_gnl)
			return (ft_gnl_free_anyway(gnl, use_gnl, ALL_FD, 0));
		return (ft_new_buffer(gnl, use_gnl, num_list));
	}
	num_list = 1;
	return (ft_handle_buffer(gnl, use_gnl, \
	use_gnl->bufferlist->buffer, num_list));
}

static char	*ft_handle_buffer(t_buffer *gnl, t_buffer *use_gnl, char *n_buffer, \
int *num_list)
{
	char	*str_line;
	int 	idx;

	if ((*num_list) == 1)
		idx = ft_strchr_idx(n_buffer, '\n', use_gnl->index);
	else
		idx = ft_strchr_idx(n_buffer, '\n', 0);
	if (idx || (*num_list) < 0)
	{
		str_line = (char *)malloc(BUFFER_SIZE * ((*num_list) - 1) \
		- use_gnl->index + idx + 2);
		if (!str_line)
			return ft_gnl_free_anyway(gnl, use_gnl, ALL_FD, 0);
		// strline to copy charaters
		if (n_buffer[idx + 1] == '\0' || idx == 0)
			return (ft_gnl_free_anyway(gnl, use_gnl, CURRENT_FD, str_line));
		else
		return (ft_gnl_free_anyway(gnl, use_gnl, ONNY_BUFFER, str_line));
	}
	else
		return (ft_new_buffer(gnl, use_gnl, num_list));
}

static char	*ft_new_buffer(t_buffer *gnl, t_buffer *use_gnl, int *num_list)
{
	t_list	*new_buflist;
	int		state;

	new_buflist = (t_list *)malloc(sizeof(t_list));
	if (!new_buflist)
		return (ft_gnl_free_anyway(gnl, use_gnl, ALL_FD, 0));
	if (use_gnl->bufferlist == 0)
		use_gnl->bufferlist = new_buflist;
	else
		ft_lstadd_back(use_gnl->bufferlist, new_buflist, T_LIST);	
	new_buflist->buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!new_buflist->buffer)
		return (ft_gnl_free_anyway(gnl, use_gnl, ALL_FD, 0));
	new_buflist->buffer[BUFFER_SIZE] = '\0';
	(*num_list)++;
	state = read(use_gnl->fd_num, new_buflist->buffer, BUFFER_SIZE);
	if (state == -1)
		return (ft_gnl_free_anyway(gnl, use_gnl, ALL_FD, 0));
	else if (state == 0)
		(*num_list) = -(*num_list);
	return (ft_handle_buffer(gnl, use_gnl, new_buflist->buffer, num_list));
}

static t_buffer	*ft_make_gnl_struct(t_buffer *gnl, int fd)
{
	t_buffer	*new_gnl;

	new_gnl = (t_buffer *)malloc(sizeof(t_buffer));
	if (!new_gnl)
		return (0);
	ft_memset(new_gnl, 0, sizeof(t_buffer));
	new_gnl->fd_num = fd;
	if (gnl == 0)
		return (new_gnl);
	else
	{
		ft_lstadd_back(gnl, new_gnl, T_BUFFER);
		return (new_gnl);
	}
}

static char	*ft_gnl_free_anyway(t_buffer *gnl, t_buffer *use_gnl, int num, \
char *returnstring)
{
	if (num == ALL_FD)
	{

	}
	else if (num == CURRENT_FD)
	{

	}
	else
	{
		
	}
}