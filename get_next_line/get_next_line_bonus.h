/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:11:21 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/23 17:35:57 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

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

int		ft_strchr_idx(const char *str, int ch);
size_t	ft_strlen(const char *s);
char	*ft_strjoin_free_change(t_buffer *u_gnl, char *s1, char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*get_next_line(int fd);

#endif