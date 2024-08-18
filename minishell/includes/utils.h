#ifndef UTILS_H
# define UTILS_H

# include "stdlib.h"

void	signal_child(void);
void	signal_handler(int sig);
void	signal_handler_parent(int sig);
void	signal_handler_heredoc(int sig);
void	signal_handler_quit(int sig);

int	    ft_strcmp(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);

char	**ft_split(char const *s, char c);

void	*malloc_s(size_t size);
char	*ft_strdup_s(const char *s1);

#endif