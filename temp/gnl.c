/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:51:02 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/23 21:45:23 by juyojeon         ###   ########.fr       */
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

int		ft_strchr_idx(const char *str, int ch, int size);
size_t	ft_strlen(const char *s);
char	*ft_strjoin_free_change(t_buffer *u_gnl, char *s1, char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_loop_buffer(t_buffer **gnl, t_buffer *u_gnl, \
ssize_t len, char *str);
char	*ft_gnl_free(t_buffer **gnl, t_buffer *u_gnl, int num, \
char *str_for_free);
char	*get_next_line(int fd);
static t_buffer	*ft_make_gnl_struct(t_buffer *gnl, int fd);
static char		*ft_handle_buffer(t_buffer **gnl, t_buffer *u_gnl, \
ssize_t len, char *str_temp);
static char		*ft_cutting_string(t_buffer **gnl, t_buffer *u_gnl, int len);

int	main(void)
{
	int		idx;
	int		fd;
	int		fd2;
	int		fd3;
	int		fd4;
	char	*str;

	idx = 1;
	fd = open("read_error.txt", O_RDWR);
	fd2 = open("1-brouette", O_RDWR);
	fd3 = open("error.txt", O_RDWR);
	while (1)
	{
		str = get_next_line(fd);
		printf("%d: <%s>\n", idx, str);
		idx++;
		str = get_next_line(fd2);
		printf("%d: <%s>\n", idx, str);
		idx++;
		str = get_next_line(fd);
		printf("%d: <%s>\n", idx, str);
		idx++;
		str = get_next_line(fd3);
		printf("%d: <%s>\n", idx, str);
		idx++;
		fd4 = open("giant_line_nl.txt", O_RDWR);
		str = get_next_line(fd4);
		printf("%d: <%s>\n", idx, str);
		idx++;
		str = get_next_line(1007);
		printf("%d: <%s>\n", idx, str);
		idx++;
		str = get_next_line(fd);
		printf("%d: <%s>\n", idx, str);
		idx++;
		str = get_next_line(fd2);
		printf("%d: <%s>\n", idx, str);
		idx++;
	}
	close(fd);
	close(fd2);
	close(fd3);
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
		gnl = ft_make_gnl_struct(gnl, fd);
		if (gnl == 0)
			return (0);
		return (ft_handle_buffer(&gnl, gnl, BUFFER_SIZE, 0));
	}
	u_gnl = gnl;
	while (u_gnl && u_gnl->fd_num != fd)
		u_gnl = u_gnl->next;
	if (!u_gnl)
	{
		u_gnl = ft_make_gnl_struct(gnl, fd);
		if (u_gnl == 0)
			return (ft_gnl_free(&gnl, u_gnl, ALL, 0));
	}
	return (ft_handle_buffer(&gnl, u_gnl, BUFFER_SIZE, 0));
}

static t_buffer	*ft_make_gnl_struct(t_buffer *gnl, int fd)
{
	t_buffer		*new_gnl;
	t_buffer		*temp;
	unsigned int	temp_idx;
	char			*temp_zero;

	new_gnl = (t_buffer *)malloc(sizeof(t_buffer));
	if (!new_gnl)
		return (0);
	temp_idx = 0;
	temp_zero = (char *)new_gnl;
	while (temp_idx < sizeof(t_buffer))
		temp_zero[temp_idx++] = 0;
	new_gnl->fd_num = fd;
	if (gnl != 0)
	{
		temp = gnl;
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
	u_gnl->last_idx = ft_strchr_idx(u_gnl->buffer, '\n', 0);
	while (u_gnl->last_idx == ERROR && len == BUFFER_SIZE)
	{
		str_temp = ft_loop_buffer(gnl, u_gnl, BUFFER_SIZE, 0);
		if (!str_temp)
			return (0);
		if (u_gnl->buffer == 0)
			u_gnl->buffer = str_temp;
		else
			if (ft_strjoin_free_change(u_gnl, u_gnl->buffer, str_temp) == 0)
				return (ft_gnl_free(gnl, u_gnl, ALL, 0));
		u_gnl->last_idx = ft_strchr_idx(u_gnl->buffer, '\n', 0);
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
		free(u_gnl->buffer);
		u_gnl->buffer = 0;
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

char	*ft_gnl_free(t_buffer **gnl, t_buffer *u_gnl, int num, \
char *str_for_free)
{
	t_buffer	*temp_b;

	free(str_for_free);
	if (num == CURRENT)
	{
		temp_b = *gnl;
		while (temp_b && temp_b->next != u_gnl)
			temp_b = temp_b->next;
		if (temp_b)
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

int	ft_strchr_idx(const char *str, int ch, int size)
{
	char	temp;
	int		end_idx;

	temp = (char)ch;
	end_idx = 0;
	if (!str)
		return (-1);
	if (!size)
	{
		while (str[end_idx])
		{
			if (str[end_idx] == temp)
				return (end_idx);
			end_idx++;
		}
		return (-1);
	}
	while (size-- > 0)
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

char	*ft_loop_buffer(t_buffer **gnl, t_buffer *u_gnl, \
ssize_t len, char *str)
{
	int		size;
	char	*temp;

	size = BUFFER_SIZE;
	if (BUFFER_SIZE < 100)
		size = 100;
	str = (char *)malloc(size + 1);
	if (!str)
		return (ft_gnl_free(gnl, u_gnl, ALL, 0));
	size = size / BUFFER_SIZE;
	temp = str;
	while (size-- > 0)
	{
		len = read(u_gnl->fd_num, temp, BUFFER_SIZE);
		temp += len;
		if (len < BUFFER_SIZE || ft_strchr_idx(temp - len, '\n', len) >= 0)
			break ;
	}
	*temp = '\0';
	if (len == ERROR)
		return (ft_gnl_free(gnl, u_gnl, CURRENT, str));
	else if (len == 0)
		free (str);
	else
		return (str);
	return (u_gnl->buffer);
}
