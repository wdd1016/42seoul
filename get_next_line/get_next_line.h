/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:11:21 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/16 08:14:56 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_linkedlist
{
	char	*buffer;
	void	*next;
}	t_list;

typedef struct	s_buffer
{
	t_list *bufferlist;
	int		fd_num;
	int		index;
	void	*next;
}	t_buffer;

# define TRUE 1
# define FALSE 0
# define T_LIST 0
# define T_BUFFER 1
# define ALL_FD 1
# define CURRENT_FD 2
# define ONNY_BUFFER 3
# define BUFFER_SIZE 5

void	*ft_memset(void *b, int c, size_t len);
void	ft_lstadd_back(void *lst, void *new, int type);
int		ft_strchr_idx(const char *str, int ch, int startidx);
void	ft_buflstclear(t_buffer **gnl, t_buffer *use_gnl, int num);
void	ft_copy_buffer(t_buffer *use_gnl, char *dest, int lastindex);
char	*get_next_line(int fd);

#endif