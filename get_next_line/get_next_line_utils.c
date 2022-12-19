/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:12:00 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/16 08:15:09 by juyojeon         ###   ########.fr       */
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
				break;
			lst = ((t_buffer *)lst)->next;
		}
		((t_buffer *)lst)->next = (t_buffer *)new;
	}
	else if (type == T_LIST)
	{
		while (1)
		{
			if (((t_list *)lst)->next == 0)
				break;
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

int	ft_strchr_idx(const char *str, int ch, int index)
{
	char	temp;

	temp = (char)ch;
	while (str[index])
	{
		if (str[index] == temp)
			return (index);
		index++;
	}
	if (str[index] == temp)
		return (index);
	else
		return (0);
}
