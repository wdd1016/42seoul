/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:11:21 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/27 00:44:19 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
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

ssize_t	ft_strchrindex(char *s, int c);
size_t	ft_strlen(char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_gnlfree_all(t_fdlist *firlist, char *str_rtn);
void	*ft_gnlfree_use(t_fdlist *firlist, t_fdlist *uselist, char *str_rtn);
char	*get_next_line(int fd);
char	*ft_handle_buffer(t_fdlist *firlist, t_fdlist *uselist, \
t_buffer *usebuffer);
char	*ft_remain_buffer(t_fdlist *uselist, t_buffer *usebuffer, \
size_t i, size_t j);
char	*ft_make_buffer(t_fdlist *firlist, t_fdlist *uselist, \
t_buffer *usebuffer, ssize_t len);

#endif