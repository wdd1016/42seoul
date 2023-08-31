/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:10:23 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/24 17:35:53 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_handle_buffer(t_fdlist *firlist, t_fdlist *uselist, \
t_buffer *usebuffer);
static char	*ft_remain_buffer(t_fdlist *uselist, t_buffer *usebuffer, \
size_t i, size_t j);
static char	*ft_make_buffer(t_fdlist *firlist, t_fdlist *uselist, \
t_buffer *usebuffer, ssize_t len);

char	*get_next_line(int fd)
{
	static t_fdlist	firlist = {0, 0, 0, 0};
	t_fdlist		*uselist;

	uselist = firlist.next;
	while (uselist && uselist->fdnumber != fd)
		uselist = uselist->next;
	if (!uselist)
	{
		uselist = (t_fdlist *)malloc(sizeof(t_fdlist));
		if (!uselist)
			return (0);
		uselist->buflist = (t_buffer *)malloc(sizeof(t_buffer));
		if (uselist->buflist == 0)
			return (ft_gnlfree_all(&firlist, 0));
		uselist->next = firlist.next;
		firlist.next = uselist;
		uselist->fdnumber = fd;
		uselist->strlen = 0;
		ft_bzero(uselist->buflist, sizeof(t_buffer));
	}
	if (ft_make_buffer(&firlist, uselist, uselist->buflist, BUFFER_SIZE))
		return (ft_handle_buffer(&firlist, uselist, uselist->buflist));
	else
		return (0);
}
/* struct make & add next of first fdlist */
/* ft_make_buffer : make t_buffer(linked list), read fd */
/* ft_handle_buffer : make string to (return, rest in fdlist) */

static char	*ft_handle_buffer(t_fdlist *firlist, t_fdlist *uselist, \
t_buffer *usebuffer)
{
	char		*str_return;
	size_t		i;
	size_t		j;

	str_return = (char *)malloc(uselist->strlen + 1);
	if (!str_return)
		return (ft_gnlfree_all(firlist, 0));
	i = 0;
	while (usebuffer->next)
	{
		usebuffer = usebuffer->next;
		j = 0;
		while (i < uselist->strlen && (usebuffer->buffer)[j])
			str_return[i++] = (usebuffer->buffer)[j++];
	}
	str_return[i] = '\0';
	if ((usebuffer->buffer)[j] == '\0')
	{
		ft_gnlfree_use(firlist, uselist, 0);
		return (str_return);
	}
	else if (ft_remain_buffer(uselist, usebuffer, i, j) == 0)
		return (ft_gnlfree_all(firlist, str_return));
	return (str_return);
}
/* make return string */
/* if remaining string = 0 -> use struct free & return str_return */

static char	*ft_remain_buffer(t_fdlist *uselist, t_buffer *usebuffer, \
size_t i, size_t j)
{
	t_buffer	*remain;
	t_buffer	*temp;

	remain = (t_buffer *)malloc(sizeof(t_buffer));
	if (!remain)
		return (0);
	remain->next = 0;
	i = 0;
	while ((usebuffer->buffer)[j])
		(remain->buffer)[i++] = (usebuffer->buffer)[j++];
	(remain->buffer)[i] = '\0';
	while (uselist->buflist->next)
	{
		temp = uselist->buflist->next;
		uselist->buflist->next = temp->next;
		free(temp);
	}
	uselist->buflist->next = remain;
	uselist->strlen = ft_strchrindex(remain->buffer, '\n') + 1;
	if (uselist->strlen == 0)
		uselist->strlen = ft_strlen(remain->buffer);
	return (remain->buffer);
}
/* make remaining string in uselist->buflist->next */

static char	*ft_make_buffer(t_fdlist *firlist, t_fdlist *uselist, \
t_buffer *usebuffer, ssize_t len)
{
	ssize_t		lastindex;

	if (usebuffer->next)
		usebuffer = usebuffer->next;
	lastindex = ft_strchrindex(usebuffer->buffer, '\n');
	while (len == BUFFER_SIZE && lastindex == -1)
	{
		usebuffer->next = (t_buffer *)malloc(sizeof(t_buffer));
		if (usebuffer->next == 0)
			return (ft_gnlfree_all(firlist, 0));
		usebuffer = usebuffer->next;
		usebuffer->next = 0;
		len = read(uselist->fdnumber, usebuffer->buffer, BUFFER_SIZE);
		if (len == -1 || (len == 0 && uselist->strlen == 0))
			return (ft_gnlfree_use(firlist, uselist, 0));
		(usebuffer->buffer)[len] = '\0';
		lastindex = ft_strchrindex(usebuffer->buffer, '\n');
		if (lastindex == -1)
			uselist->strlen += len;
		else
			uselist->strlen += lastindex + 1;
	}
	return (usebuffer->buffer);
}
/* dynamic allocation error : all fdlist structs free <-> */
/* read error : current(use) fdlist struct free */
