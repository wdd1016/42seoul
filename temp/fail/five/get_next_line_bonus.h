/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:11:21 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/24 17:16:44 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
#  define BUFFER_SIZE 1
# endif

void	ft_process_len(t_list *uselist, char *newbuffer, ssize_t len);
size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_gnl_strjoin(t_list *uselist, char *s2, ssize_t len);
char	*get_next_line(int fd);

#endif