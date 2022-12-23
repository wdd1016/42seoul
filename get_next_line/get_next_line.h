/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:11:21 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/24 06:00:30 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_buffer
{
	char			*buffer;
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
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

ssize_t	ft_strchrindex(char *s, int c);
size_t	ft_strlen(char *s);
char	*get_next_line(int fd);

#endif