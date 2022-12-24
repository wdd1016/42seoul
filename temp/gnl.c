/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:51:02 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/24 17:06:06 by juyojeon         ###   ########.fr       */
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

typedef struct s_list
{
	char			*buffer;
	int				fdnumber;
	int				state;
	size_t			len_return;
	size_t			len_remain;
	struct s_list	*next;
}	t_list;

# define ALL 1
# define USE 2
# define NORMAL 0
# define END 1
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

void	ft_process_len(t_list *uselist, char *newbuffer, ssize_t len);
size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_gnl_strjoin(t_list *uselist, char *s2, ssize_t len);
char	*get_next_line(int fd);

int	main(void)
{
	int		idx;
	int		fd;
	int		fd2;
	int		fd3;
	char	*str;

	idx = 1;
	fd = open("limits.txt", O_RDWR);
	fd2 = open("1-brouette", O_RDWR);
	fd3 = open("error.txt", O_RDWR);
	while (idx < 5)
	{
		str = get_next_line(fd);
		printf("%d: <%s>\n", idx, str);
		idx++;
	// 	str = get_next_line(fd);
	// 	printf("%d: <%s>\n", idx, str);
	// 	idx++;
	// 	close(fd);
	// 	str = get_next_line(fd);
	// 	printf("%d: <%s>\n", idx, str);
	// 	idx++;
	// 	str = get_next_line(fd3);
	// 	printf("%d: <%s>\n", idx, str);
	// 	idx++;
	// 	fd4 = open("giant_line_nl.txt", O_RDWR);
	// 	str = get_next_line(fd4);
	// 	printf("%d: <%s>\n", idx, str);
	// 	idx++;
	// 	str = get_next_line(1007);
	// 	printf("%d: <%s>\n", idx, str);
	// 	idx++;
	// 	str = get_next_line(fd);
	// 	printf("%d: <%s>\n", idx, str);
	// 	idx++;
	// 	str = get_next_line(fd2);
	// 	printf("%d: <%s>\n", idx, str);
	// 	idx++;
	}
	// close(fd);
	// close(fd2);
	// close(fd3);
	return (0);
}


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
	while (len == BUFFER_SIZE && uselist->state == NORMAL && uselist->len_remain == 0)
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
			free(newbuffer);
		else
		{
			newbuffer[len] = '\0';
			tempbuffer = ft_gnl_strjoin(uselist, newbuffer, len);
			if (!tempbuffer)
				return (ft_gnlfree(firlist, uselist, ALL));
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

void	ft_process_len(t_list *uselist, char *newbuffer, ssize_t len)
{
	int		i;

	i = 0;
	while (newbuffer[i])
	{
		if (newbuffer[i] == '\n')
		{
			i++;
			uselist->len_return += i;
			uselist->len_remain += len - i;
			uselist->state = END;
			return ;
		}
		i++;
	}
	uselist->len_return += i;
	return ;
}

char	*ft_strchr(const char *s, int c)
{
	char	temp;

	temp = (char)c;
	while (*s)
	{
		if (*s == temp)
			return ((char *)s);
		s++;
	}
	if (*s == temp)
		return ((char *)s);
	else
		return (0);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	count;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i + 1 < dstsize)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	count = 0;
	while (src[count])
		count++;
	return (count);
}

char	*ft_gnl_strjoin(t_list *uselist, char *s2, ssize_t len)
{
	char	*str;
	char	*s1;
	char	*temp;

	str = (char *)malloc(sizeof(char) * (uselist->len_return + len + 1));
	if (!str)
		return (0);
	temp = str;
	s1 = uselist->buffer;
	if (s1)
		while (*s1)
			*temp++ = *s1++;
	if (s2)
		while (*s2)
			*temp++ = *s2++;
	*temp = '\0';
	return (str);
}
