/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:10:23 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/24 06:14:04 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_make_fdlist(t_fdlist *firlist, int fd);
static char	*ft_handle_buffer(t_fdlist *firlist, t_fdlist *uselist);
static char	*ft_make_buffer(t_fdlist *firlist, t_fdlist *uselist);
static void	*ft_allfree(t_fdlist *firlist, t_fdlist *uselist, int choice);

char	*get_next_line(int fd)
{
	static t_fdlist	firlist = { 0, };
	t_fdlist		*uselist;

	uselist = &firlist;
	while (uselist && uselist->fdnumber != fd)
		uselist = uselist->next;
	if (!uselist)
	{
		if (ft_make_fdlist(&firlist, fd) == 0)
			return (ft_allfree(&firlist, uselist, ALL));
		uselist = firlist.next;
	}
	return(ft_handle_buffer(&firlist, uselist));
}

static int	ft_make_fdlist(t_fdlist *firlist, int fd)
{
	t_fdlist	*newlist;

	newlist = (t_fdlist *)malloc(sizeof(t_fdlist));
	if (!newlist)
		return (0);
	newlist->next = firlist->next;
	firlist->next = newlist;
	newlist->buflist = (t_buffer *)malloc(sizeof(t_buffer));
	if (newlist->buflist == 0)
		return (0);
	newlist->fdnumber = fd;
	newlist->strlen	= 0;
	newlist->buflist->buffer = 0;
	newlist->buflist->next = 0;
	return (1);
}

static char	*ft_handle_buffer(t_fdlist *firlist, t_fdlist *uselist)
{
	t_buffer	*usebuffer;
	char		*str_return;
	char		*str_temp;
	int			i;
	int			j;


	usebuffer = uselist->buflist;
	if (usebuffer->next == 0 || ft_strchrindex(usebuffer->next->buffer, '\n') == -1)
		if (ft_make_buffer(firlist, uselist) == 0)
			return (0);
	str_return = (char *)malloc(uselist->strlen + 1);
	if (!str_return)
		return (ft_allfree(firlist, uselist, ALL));
	str_temp = str_return;
	while (usebuffer->next)
	{
		usebuffer = usebuffer->next;
		i = 0;
		while ((usebuffer->buffer)[i] && (usebuffer->buffer)[i] != '\n')
			*str_temp++ = (usebuffer->buffer)[i++];
		if ((usebuffer->buffer)[i] == '\n')
		{
			*str_temp++ = '\n';
			i++;
			break ;
		}
	}
	*str_temp = '\0';
	if ((usebuffer->buffer)[i] == '\0')
	{
		ft_allfree(firlist, uselist, USE);
		return (str_return);
	}
	else
	{
		str_temp = (char *)malloc(ft_strlen(usebuffer->buffer) - i + 1);
		if (!str_temp)
			return (ft_allfree(firlist, uselist, ALL));
		j = 0;
		while ((usebuffer->buffer)[i])
			str_temp[j++] = (usebuffer->buffer)[i++];
		str_temp[j] = '\0';
		usebuffer = uselist->buflist->next;
		while (usebuffer->next)
		{
			usebuffer = uselist->buflist->next;
			uselist->buflist->next = usebuffer->next;
			free(usebuffer->buffer);
			free(usebuffer);
		}
		free(uselist->buflist->next->buffer);
		uselist->buflist->next->buffer = str_temp;
		uselist->strlen = ft_strlen(str_temp);
		return (str_return);
	}
}

static char	*ft_make_buffer(t_fdlist *firlist, t_fdlist *uselist)
{
	t_buffer	*usebuffer;
	ssize_t		len;
	ssize_t		lastindex;

	usebuffer = uselist->buflist;
	if (usebuffer->next)
		usebuffer = usebuffer->next;
	len = BUFFER_SIZE;
	lastindex = -1;
	while (len == BUFFER_SIZE && lastindex == -1)
	{
		usebuffer->next = (t_buffer *)malloc(sizeof(t_buffer));
		if (usebuffer->next == 0)
			return (ft_allfree(firlist, uselist, ALL));
		usebuffer = usebuffer->next;
		usebuffer->next = 0;
		usebuffer->buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (usebuffer->buffer == 0)
			return (ft_allfree(firlist, uselist, ALL));
		len = read(uselist->fdnumber, usebuffer->buffer, BUFFER_SIZE);
		if (len == -1)
			return (ft_allfree(firlist, uselist, USE));
		else if (len == 0 && uselist->buflist->next == 0)
			return (ft_allfree(firlist, uselist, USE));
		else
		{
			(usebuffer->buffer)[len] = '\0';
			lastindex = ft_strchrindex(usebuffer->buffer, '\n');
			if (lastindex == -1)
				uselist->strlen += len;
			else
				uselist->strlen += lastindex + 1;
		}
	}
	return (usebuffer->buffer);
}

static void	*ft_allfree(t_fdlist *firlist, t_fdlist *uselist, int choice)
{
	t_fdlist	*templist;
	t_buffer	*temp;

	if (choice == ALL)
	{
		while (firlist->next)
		{
			templist = firlist->next;
			firlist->next = templist->next;
			free(templist->buflist->buffer);
			free(templist->buflist);
			free(templist);
		}
	}
	else if (choice == USE)
	{
		while (uselist->buflist->next)
		{
			temp = uselist->buflist->next;
			uselist->buflist->next = temp->next;
			free(temp->buffer);
			free(temp);
		}
		templist = firlist;
		while (templist->next != uselist)
			templist = templist->next;
		templist->next = uselist->next;
		free(uselist);
	}
	return (0);
}
