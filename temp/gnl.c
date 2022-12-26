/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:51:02 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/26 23:11:07 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_buffer
{
	char			buffer[BUFFER_SIZE + 1];
	struct s_buffer	*next;
}	t_buffer;

typedef struct s_fdlist
{
	t_buffer		*buflist;
	int				fdnumber;
	size_t			strlen;
	struct s_fdlist	*next;
}	t_fdlist;

# define ALL 1
# define USE 2
# define BUF 3

ssize_t	ft_strchrindex(char *s, int c);
size_t	ft_strlen(char *s);
char	*get_next_line(int fd);
char	*ft_handle_buffer(t_fdlist *firlist, t_fdlist *uselist);
char	*ft_make_buffer(t_fdlist *firlist, t_fdlist *uselist);
void	*ft_allfree(t_fdlist *firlist, t_fdlist *uselist, int choice);

int	main(void)
{
	int		idx;
	int		fd;
	int		fd2;
	int		fd3;
	char	*str;

	idx = 1;
	fd = open("variable_nls.txt", O_RDWR);
	fd2 = open("1-brouette", O_RDWR);
	fd3 = open("error.txt", O_RDWR);
	while (idx < 20)
	{
		str = get_next_line(-2);
		printf("%d: <%s>\n", idx, str);
		idx++;
	}
	return (0);
}


char	*get_next_line(int fd)
{
	static t_fdlist	firlist = {0, -1, 0, 0};
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
			return (ft_allfree(&firlist, uselist, ALL));
		uselist->next = firlist.next;
		firlist.next = uselist;
		uselist->fdnumber = fd;
		uselist->strlen = 0;
		*(uselist->buflist->buffer) = '\0';
		uselist->buflist->next = 0;
	}
	return (ft_handle_buffer(&firlist, uselist));
}

char	*ft_handle_buffer(t_fdlist *firlist, t_fdlist *uselist)
{
	t_buffer	*usebuffer;
	t_buffer	*remain;
	char		*str_return;
	size_t		i;
	size_t		j;

	usebuffer = uselist->buflist;
	if (ft_make_buffer(firlist, uselist) == 0)
		return (0);
	str_return = (char *)malloc(uselist->strlen + 1);
	if (!str_return)
		return (ft_allfree(firlist, uselist, ALL));
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
		ft_allfree(firlist, uselist, USE);
		return (str_return);
	}
	remain = (t_buffer *)malloc(sizeof(t_buffer));
	if (!remain)
	{
		free(str_return);
		return (ft_allfree(firlist, uselist, ALL));
	}
	remain->next = 0;
	i = 0;
	while ((usebuffer->buffer)[j])
		(remain->buffer)[i++] = (usebuffer->buffer)[j++];
	(remain->buffer)[i] = '\0';
	ft_allfree(firlist, uselist, BUF);
	uselist->buflist->next = remain;
	uselist->strlen = ft_strchrindex(remain->buffer, '\n') + 1;
	if (uselist->strlen == 0)
		uselist->strlen = ft_strlen(remain->buffer);
	return (str_return);
}

char	*ft_make_buffer(t_fdlist *firlist, t_fdlist *uselist)
{
	t_buffer	*usebuffer;
	ssize_t		len;
	ssize_t		lastindex;

	usebuffer = uselist->buflist;
	if (usebuffer->next)
		usebuffer = usebuffer->next;
	len = BUFFER_SIZE;
	lastindex = ft_strchrindex(usebuffer->buffer, '\n');
	while (len == BUFFER_SIZE && lastindex == -1)
	{
		usebuffer->next = (t_buffer *)malloc(sizeof(t_buffer));
		if (usebuffer->next == 0)
			return (ft_allfree(firlist, uselist, ALL));
		usebuffer = usebuffer->next;
		usebuffer->next = 0;
		len = read(uselist->fdnumber, usebuffer->buffer, BUFFER_SIZE);
		if (len == -1)
			return (ft_allfree(firlist, uselist, USE));
		else if (len == 0 && uselist->strlen == 0)
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

void	*ft_allfree(t_fdlist *firlist, t_fdlist *uselist, int choice)
{
	t_fdlist	*templist;
	t_buffer	*temp;

	if (choice == ALL)
	{
		while (firlist->next)
		{
			templist = firlist->next;
			firlist->next = templist->next;
			while (templist->buflist)
			{
				temp = templist->buflist;
				templist->buflist->next = temp->next;
				free (temp);
			}
			free(templist);
		}
	}
	else if (choice == USE || choice == BUF)
	{
		while (uselist->buflist->next)
		{
			temp = uselist->buflist->next;
			uselist->buflist->next = temp->next;
			free(temp);
		}
		if (choice == USE)
		{
			free(uselist->buflist);
			templist = firlist;
			while (templist->next != uselist)
				templist = templist->next;
			templist->next = uselist->next;
			free(uselist);
		}
	}
	return (0);
}


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
