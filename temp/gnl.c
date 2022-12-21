/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:51:02 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/21 23:59:29 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_linkedlist
{
	char	*buffer;
	void	*next;
}	t_list;

typedef struct s_buffer
{
	t_list	*bufferlist;
	int		fd_num;
	int		file_state;
	int		index;
	void	*next;
}	t_buffer;

#define TRUE 1
#define FALSE 0
#define T_LIST 0
#define T_BUFFER 1
#define NORMAL_STATE 1
#define EOF_STATE 2
#define ALL_FD 1
#define CURRENT_FD 2
#define ONNY_BUFFER 3
#define BUFFER_SIZE 1000

static t_buffer	*ft_make_gnl_struct(t_buffer *gnl, int fd);
static char		*ft_handle_buffer(t_buffer *gnl, t_buffer *use_gnl, \
char *n_buffer, int *num_list);
static char		*ft_new_buffer(t_buffer *gnl, t_buffer *use_gnl, int *num_list);
static char		*ft_gnl_free_return(t_buffer **gnl, t_buffer *use_gnl, \
int num, char *returnstring);
void			*ft_memset(void *b, int c, size_t len);
void			ft_lstadd_back(void *lst, void *new, int type);
int				ft_strchr_idx(const char *str, int ch, int startidx);
void			ft_buflstclear(t_buffer **gnl, t_buffer *use_gnl, int num);
void			ft_copy_buffer(t_buffer *use_gnl, char *dest, int lastindex, \
int index);
char			*get_next_line(int fd);

int	main(void)
{
	int		idx;
	int		fd;
	char	*str;

	idx = 1;
	fd = open("test", O_RDWR);
	while (1)
	{
		str = get_next_line(fd);
		printf("%d: <%s>\n", idx, str);
		idx++;
		if (!str)
		{
			free(str);
			break ;
		}
	}
	close(fd);
	return (0);
}

char	*get_next_line(int fd)
{
	static t_buffer	*gnl = 0;
	t_buffer		*use_gnl;
	int				num_list;

	num_list = 0;
	if (!gnl)
	{
		gnl = ft_make_gnl_struct(gnl, fd);
		if (!gnl)
			return (0);
		return (ft_new_buffer(gnl, gnl, &num_list));
	}
	use_gnl = gnl;
	while (use_gnl && use_gnl->fd_num != fd)
		use_gnl = use_gnl->next;
	if (!(use_gnl))
	{
		use_gnl = ft_make_gnl_struct(gnl, fd);
		if (use_gnl == 0)
			return (ft_gnl_free_return(&gnl, use_gnl, ALL_FD, 0));
		return (ft_new_buffer(gnl, use_gnl, &num_list));
	}
	num_list = 1;
	return (ft_handle_buffer(gnl, use_gnl, use_gnl->bufferlist->buffer, \
	&num_list));
}

static t_buffer	*ft_make_gnl_struct(t_buffer *gnl, int fd)
{
	t_buffer	*new_gnl;

	new_gnl = (t_buffer *)malloc(sizeof(t_buffer));
	if (!new_gnl)
		return (0);
	ft_memset(new_gnl, 0, sizeof(t_buffer));
	new_gnl->fd_num = fd;
	if (gnl == 0)
		return (new_gnl);
	else
	{
		ft_lstadd_back(gnl, new_gnl, T_BUFFER);
		return (new_gnl);
	}
}

static char	*ft_handle_buffer(t_buffer *gnl, t_buffer *use_gnl, char *n_buffer, \
int *num_list)
{
	char	*str_line;
	int		lastindex;
	int		temp;

	if ((*num_list) == 1)
		lastindex = ft_strchr_idx(n_buffer, '\n', use_gnl->index);
	else
		lastindex = ft_strchr_idx(n_buffer, '\n', 0);
	if (use_gnl->file_state == EOF_STATE && lastindex == -1)
		while (n_buffer[lastindex + 1])
			lastindex++;
	if (lastindex != -1)
	{
		temp = BUFFER_SIZE * ((*num_list) - 1) - use_gnl->index + lastindex + 1;
		str_line = (char *)malloc(temp + 1);
		if (!str_line)
			return (ft_gnl_free_return(&gnl, use_gnl, ALL_FD, 0));
		ft_copy_buffer(use_gnl, str_line, lastindex, 0);
		if (n_buffer[lastindex + 1] == '\0')
			return (ft_gnl_free_return(&gnl, use_gnl, CURRENT_FD, str_line));
		else
			return (ft_gnl_free_return(&gnl, use_gnl, ONNY_BUFFER, str_line));
	}
	else
		return (ft_new_buffer(gnl, use_gnl, num_list));
}

static char	*ft_new_buffer(t_buffer *gnl, t_buffer *use_gnl, int *num_list)
{
	t_list	*new_buflist;
	int		state;

	new_buflist = (t_list *)malloc(sizeof(t_list));
	if (!new_buflist)
		return (ft_gnl_free_return(&gnl, use_gnl, ALL_FD, 0));
	ft_memset(new_buflist, 0, sizeof(t_list));
	if (use_gnl->bufferlist == 0)
		use_gnl->bufferlist = new_buflist;
	else
		ft_lstadd_back(use_gnl->bufferlist, new_buflist, T_LIST);
	new_buflist->buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!(new_buflist->buffer))
		return (ft_gnl_free_return(&gnl, use_gnl, ALL_FD, 0));
	new_buflist->buffer[BUFFER_SIZE] = '\0';
	state = read(use_gnl->fd_num, new_buflist->buffer, BUFFER_SIZE);
	if (state < 0)
		return (ft_gnl_free_return(&gnl, use_gnl, ALL_FD, 0));
	if (state < BUFFER_SIZE)
		use_gnl->file_state = EOF_STATE;
	if (state > 0)
		(*num_list)++;
	return (ft_handle_buffer(gnl, use_gnl, new_buflist->buffer, num_list));
}

static char	*ft_gnl_free_return(t_buffer **gnl, t_buffer *use_gnl, int num, \
char *returnstring)
{
	t_buffer	*temp_b;

	if (num == ALL_FD)
	{
		while (*gnl)
		{
			temp_b = *gnl;
			*gnl = (*gnl)->next;
			ft_buflstclear(gnl, temp_b, ALL_FD);
			free(temp_b);
		}
	}
	else if (num == CURRENT_FD)
	{
		temp_b = *gnl;
		while (temp_b->next != 0 && temp_b->next != use_gnl)
			temp_b = temp_b->next;
		temp_b->next = use_gnl->next;
		ft_buflstclear(gnl, use_gnl, CURRENT_FD);
		free(use_gnl);
	}
	else
		ft_buflstclear(gnl, use_gnl, ONNY_BUFFER);
	return (returnstring);
}

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
