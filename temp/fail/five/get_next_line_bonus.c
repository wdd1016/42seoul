/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:10:23 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/24 17:15:04 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnlfree(t_list *firlist, t_list *uselist, int choice)
{
	t_list	*temp;

	if (choice == ALL)
	{
		while (firlist->next)
		{
			temp = firlist->next;
			firlist->next = temp->next;
			if (temp->buffer)
				free(temp->buffer);
			free(temp);
		}
	}
	else if (choice == USE)
	{
		temp = firlist;
		while (temp->next != uselist)
			temp = temp->next;
		temp->next = uselist->next;
		if (uselist->buffer)
			free(uselist->buffer);
		free(uselist);
	}
	return (0);
}

char	*ft_make_buffer(t_list *firlist, t_list *uselist, int fd)
{
	char	*newbuffer;
	char	*tempbuffer;
	ssize_t	len;

	len = BUFFER_SIZE;
	while (len == BUFFER_SIZE && uselist->state == NORMAL)
	{
		newbuffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!newbuffer)
			return (ft_gnlfree(firlist, uselist, ALL));
		len = read(fd, newbuffer, BUFFER_SIZE);
		if (len < 0)
		{
			free(newbuffer);
			return (ft_gnlfree(firlist, uselist, USE));
		}
		else if (len == 0)
		{
			free(newbuffer);
			if (uselist->buffer)
				return (uselist->buffer);
			else
				return (ft_gnlfree(firlist, uselist, USE));
		}
		else
		{
			newbuffer[len] = '\0';
			tempbuffer = ft_gnl_strjoin(uselist, newbuffer, len);
			if (!tempbuffer)
			{
				free(newbuffer);
				return (ft_gnlfree(firlist, uselist, ALL));
			}
			ft_process_len(uselist, newbuffer, len);
			if (uselist->buffer)
				free(uselist->buffer);
			uselist->buffer = tempbuffer;
			free(newbuffer);
		}
	}
	return (tempbuffer);
}

char	*ft_handle_buffer(t_list *firlist, t_list *uselist, int fd)
{
	char	*str_return;
	char	*str_remain;
	int		temp;

	if (uselist->len_remain == 0)
		if (ft_make_buffer(firlist, uselist, fd) == 0)
			return (0);
	if (uselist->len_return == 0)
		return (ft_gnlfree(firlist, uselist, USE));
	str_return = (char *)malloc(uselist->len_return + 1);
	if (!str_return)
		return (ft_gnlfree(firlist, uselist, ALL));
	ft_strlcpy(str_return, uselist->buffer, uselist->len_return + 1);
	if (uselist->len_remain == 0)
	{
		ft_gnlfree(firlist, uselist, USE);
		return (str_return);
	}
	str_remain = (char *)malloc(uselist->len_remain + 1);
	if (!str_remain)
		return (ft_gnlfree(firlist, uselist, ALL));
	ft_strlcpy(str_remain, uselist->buffer + uselist->len_return, \
	uselist->len_remain + 1);
	free(uselist->buffer);
	uselist->buffer = str_remain;
	temp = uselist->len_remain;
	uselist->len_remain = 0;
	uselist->len_return = 0;
	ft_process_len(uselist, str_remain, temp);
	uselist->state = NORMAL;
	return (str_return);
}

int	ft_make_fdlist(t_list *firlist, int fd)
{
	t_list	*newlist;

	newlist = (t_list *)malloc(sizeof(t_list));
	if (!newlist)
		return (0);
	newlist->next = firlist->next;
	firlist->next = newlist;
	newlist->fdnumber = fd;
	newlist->state = 0;
	newlist->len_return = 0;
	newlist->len_remain = 0;
	newlist->buffer = 0;
	return (1);
}

char	*get_next_line(int fd)
{
	static t_list	firlist = {0, -1, 0, 0, 0, 0};
	t_list			*uselist;

	if (fd != -1)
		uselist = &firlist;
	else
		uselist = firlist.next;
	while (uselist && uselist->fdnumber != fd)
		uselist = uselist->next;
	if (!uselist)
	{
		if (ft_make_fdlist(&firlist, fd) == 0)
			return (0);
		uselist = firlist.next;
	}
	return (ft_handle_buffer(&firlist, uselist, fd));
}
