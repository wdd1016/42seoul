/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:51:02 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/23 00:21:30 by juyojeon         ###   ########.fr       */
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
	int		f_st;
	void	*next;
}	t_buffer;

# define TRUE 1
# define FALSE 0
# define NORMAL 0
# define EOFS -1
# define ALL 1
# define CURRENT 2
# define CUT 2
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

void			*ft_calloc(size_t count, size_t size);
int				ft_strchr_idx(const char *str, int ch);
size_t			ft_strlen(const char *s);
char			*ft_strjoin_free(char const *s1, char const *s2);
char			*get_next_line(int fd);
static t_buffer	*ft_make_gnl_struct(t_buffer **gnl, int fd);
static char		*ft_handle_buffer(t_buffer **gnl, t_buffer *u_gnl);
static char		*ft_process_string(t_buffer **gnl, t_buffer *u_gnl);
static char		*ft_gnl_free(t_buffer **gnl, t_buffer *u_gnl, int num, \
char *fre);

int	main(void)
{
	int		idx;
	int		fd;
	char	*str;

	idx = 1;
	fd = open("read_error.txt", O_RDWR);
	while (1)
	{
		str = get_next_line(fd);
		printf("%d: <%s>\n", idx, str);
		idx++;
		str = get_next_line(99);
		printf("%d: <%s>\n", idx, str);
		idx++;
		str = get_next_line(fd);
		printf("%d: <%s>\n", idx, str);
		idx++;
		str = get_next_line(99);
		printf("%d: <%s>\n", idx, str);
		idx++;
		str = get_next_line(fd);
		printf("%d: <%s>\n", idx, str);
		idx++;
		str = get_next_line(99);
		printf("%d: <%s>\n", idx, str);
		idx++;
		str = get_next_line(fd);
		printf("%d: <%s>\n", idx, str);
		idx++;
		str = get_next_line(99);
		printf("%d: <%s>\n", idx, str);
		idx++;
		str = get_next_line(fd);
		printf("%d: <%s>\n", idx, str);
		idx++;
		str = get_next_line(99);
		printf("%d: <%s>\n", idx, str);
		idx++;
		if (!str)
		{
			free(str);
			break ;
		}
		free(str);
	}
	close(fd);
	return (0);
}
