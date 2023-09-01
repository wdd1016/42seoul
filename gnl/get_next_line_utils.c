/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:12:00 by juyojeon          #+#    #+#             */
/*   Updated: 2023/09/01 15:39:38 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

ssize_t	ft_strchrindex(char *s, int c)
{
	char	temp;
	int		i;

	temp = (char)c;
	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == temp)
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(char *s)
{
	char	*copy;

	if (!s)
		return (0);
	copy = s;
	while (*s)
		s++;
	return ((size_t)s - (size_t)copy);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = (char *)s;
	while (i < n)
	{
		*temp = 0;
		i++;
		temp++;
	}
}

void	*ft_gnlfree_all(t_fdlist *firlist, char *str_rtn)
{
	t_fdlist	*templist;
	t_buffer	*temp;

	while (firlist->next)
	{
		templist = firlist->next;
		firlist->next = templist->next;
		while (templist->buflist)
		{
			temp = templist->buflist;
			templist->buflist = temp->next;
			free (temp);
		}
		free(templist);
	}
	return (str_rtn);
}

void	*ft_gnlfree_use(t_fdlist *firlist, t_fdlist *uselist, char *str_rtn)
{
	t_fdlist	*templist;
	t_buffer	*temp;

	while (uselist->buflist)
	{
		temp = uselist->buflist;
		uselist->buflist = temp->next;
		free(temp);
	}
	templist = firlist;
	while (templist->next != uselist)
		templist = templist->next;
	templist->next = uselist->next;
	free(uselist);
	return (str_rtn);
}
