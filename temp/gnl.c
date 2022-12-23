/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:51:02 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/23 15:17:41 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


typedef struct s_buffer
{
	char	*buffer;
	int		fd_num;
	int		last_idx;
	void	*next;
}	t_buffer;

# define TRUE 1
# define FALSE 0
# define NORMAL 0
# define ERROR -1
# define ALL 1
# define CURRENT 2
# define ONNYFD 3
# define CUT 2
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

void	*ft_calloc(size_t count, size_t size);
int		ft_strchr_idx(const char *str, int ch);
size_t	ft_strlen(const char *s);
char	*ft_strjoin_free_change(t_buffer *u_gnl, char *s1, char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*get_next_line(int fd);
static t_buffer	*ft_make_gnl_struct(t_buffer **gnl, int fd);
static char		*ft_handle_buffer(t_buffer **gnl, t_buffer *u_gnl, \
ssize_t len, char *str_temp);
static char		*ft_cutting_string(t_buffer **gnl, t_buffer *u_gnl, int len);
static char		*ft_gnl_free(t_buffer **gnl, t_buffer *u_gnl, int num, \
char *str_for_free);

int	main(void)
{
	int		idx;
	int		fd;
	char	*str;

	idx = 1;
	fd = open("giant_line_nl.txt", O_RDWR);
	while (1)
	{
		str = get_next_line(fd);
		printf("%d: <%s>\n", idx, str);
		idx++;
		if (!str)
		{
			free(str);
		}
		free(str);
	}
	close(fd);
	return (0);
}

char	*get_next_line(int fd)
{
	static t_buffer	*gnl = 0;
	t_buffer		*u_gnl;
	int				num_list;

	num_list = 0;
	if (!gnl)
	{
		if (!ft_make_gnl_struct(&gnl, fd))
			return (0);
		return (ft_handle_buffer(&gnl, gnl, BUFFER_SIZE, 0));
	}
	u_gnl = gnl;
	while (u_gnl->next && u_gnl->fd_num != fd)
		u_gnl = u_gnl->next;
	if (u_gnl->fd_num != fd)
	{
		u_gnl = ft_make_gnl_struct(&gnl, fd);
		if (u_gnl == 0)
			return (ft_gnl_free(&gnl, u_gnl, ALL, 0));
	}
	return (ft_handle_buffer(&gnl, u_gnl, BUFFER_SIZE, 0));
}

static t_buffer	*ft_make_gnl_struct(t_buffer **gnl, int fd)
{
	t_buffer	*new_gnl;
	t_buffer	*temp;

	new_gnl = (t_buffer *)ft_calloc(1, sizeof(t_buffer));
	if (!new_gnl)
		return (0);
	new_gnl->fd_num = fd;
	if (*gnl == 0)
		*gnl = new_gnl;
	else
	{
		temp = *gnl;
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
		str_temp = (char *)ft_calloc(1, BUFFER_SIZE + 1);
		if (!str_temp)
			return (ft_gnl_free(gnl, u_gnl, ALL, 0));
		len = read(u_gnl->fd_num, str_temp, BUFFER_SIZE);
		if (len == ERROR)
			return (ft_gnl_free(gnl, u_gnl, CURRENT, str_temp));
		else if (len == 0)
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
		ft_gnl_free(gnl, u_gnl, CURRENT, 0);
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

	if (str_for_free)
		free(str_for_free);
	if (num == CURRENT)
	{
		temp_b = *gnl;
		while (temp_b->next != 0 && temp_b->next != u_gnl)
			temp_b = temp_b->next;
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

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	arr_size;
	char	*temp;
	void	*ptr;

	arr_size = size * count;
	ptr = malloc(arr_size);
	if (!ptr)
		return (0);
	i = 0;
	temp = (char *)ptr;
	while (i < arr_size)
	{
		temp[i] = 0;
		i++;
	}
	return (ptr);
}

int	ft_strchr_idx(const char *str, int ch)
{
	char	temp;
	int		end_idx;

	temp = (char)ch;
	end_idx = 0;
	if (!str)
		return (-1);
	while (str[end_idx])
	{
		if (str[end_idx] == temp)
			return (end_idx);
		end_idx++;
	}
	return (-1);
}

size_t	ft_strlen(const char *s)
{
	const char	*copy;

	if (!s)
		return (0);
	copy = s;
	while (*s)
		s++;
	return ((size_t)s - (size_t)copy);
}

char	*ft_strjoin_free_change(t_buffer *u_gnl, char *s1, char *s2)
{
	char	*str;
	char	*temp;
	char	*temp_s1;
	char	*temp_s2;

	temp_s1 = (char *)s1;
	temp_s2 = (char *)s2;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
	{
		free(temp_s2);
		return (0);
	}
	temp = str;
	while (*s1)
		*temp++ = *s1++;
	free(temp_s1);
	while (*s2)
		*temp++ = *s2++;
	free(temp_s2);
	*temp = '\0';
	u_gnl->buffer = str;
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
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
