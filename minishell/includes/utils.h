/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:07:32 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/25 22:38:50 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		ft_isspace(char c);
int		ft_isalnum(int c);

void	free_tokens(t_data *data);
void	system_error(char *msg);

void	signal_handler(int sig);
void	signal_handler_parent(int sig);
void	signal_handler_heredoc(int sig);
void	signal_handler_quit(int sig);

void	signal_default(void);
void	signal_child(void);
void	signal_parent(void);

int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*generate_random_heredoc_filepath(int length);

char	**ft_split(char const *s, char c);

void	*malloc_s(size_t size);
char	*ft_strdup_s(const char *s1);

#endif