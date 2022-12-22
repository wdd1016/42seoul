/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:12:00 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/21 23:58:52 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back(void *lst, void *new, int type)
{
	if (type == T_BUFFER)
	{
		while (1)
		{
			if (((t_buffer *)lst)->next == 0)
				break ;
			lst = ((t_buffer *)lst)->next;
		}
		((t_buffer *)lst)->next = (t_buffer *)new;
	}
	else if (type == T_LIST)
	{
		while (1)
		{
			if (((t_list *)lst)->next == 0)
				break ;
			lst = ((t_list *)lst)->next;
		}
		((t_list *)lst)->next = (t_list *)new;
	}
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp_b;
	unsigned char	uch_c;
	size_t			i;

	i = 0;
	uch_c = (unsigned char)c;
	temp_b = (unsigned char *)b;
	while (i < len)
	{
		temp_b[i] = uch_c;
		i++;
	}
	return (b);
}

int	ft_strchr_idx(const char *str, int ch, int startidx)
{
	char	temp;

	temp = (char)ch;
	while (str[startidx])
	{
		if (str[startidx] == temp)
			return (startidx);
		startidx++;
	}
	return (-1);
}

void	ft_buflstclear(t_buffer **gnl, t_buffer *use_gnl, int num)
{
	t_list	*temp_l;

	if (num == ALL_FD || num == CURRENT_FD)
	{
		while (use_gnl->bufferlist)
		{
			temp_l = use_gnl->bufferlist;
			use_gnl->bufferlist = use_gnl->bufferlist->next;
			free(temp_l->buffer);
			free(temp_l);
		}
		if ((*gnl) == use_gnl && num == CURRENT_FD)
			*gnl = 0;
	}
	else if (num == ONNY_BUFFER)
	{
		while (use_gnl->bufferlist->next)
		{
			temp_l = use_gnl->bufferlist;
			use_gnl->bufferlist = use_gnl->bufferlist->next;
			free(temp_l->buffer);
			free(temp_l);
		}
	}
}

void	ft_copy_buffer(t_buffer *use_gnl, char *dest, int lastindex, int index)
{
	t_list	*temp;

	temp = use_gnl->bufferlist;
	while (temp)
	{
		index = 0;
		if (temp == use_gnl->bufferlist)
			index = use_gnl->index;
		if (temp->next)
		{
			while ((temp->buffer)[index])
			{
				*(dest++) = (temp->buffer)[index];
				index++;
			}
		}
		while (index <= lastindex)
		{
			*(dest++) = (temp->buffer)[index];
			index++;
		}
		temp = temp->next;
	}
	(*dest) = '\0';
	use_gnl->index = lastindex + 1;
}
